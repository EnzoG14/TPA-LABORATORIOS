import time
import board
import digitalio
import os
import pwmio

import wifi
import ssl
import socketpool
import adafruit_requests
import asyncio

def wifi_connection(ssid , password):
    
    print("Conectando a Wi-Fi...")
    try:
        wifi.radio.connect(ssid, password)
        print(f"Conectado a {ssid}")
        print(f"IP asignada: {wifi.radio.ipv4_address}")
    except Exception as e:
        print(f"Error al conectar: {e}")


class Personas(object):

    def __init__(self, cantidad, aforo, tiempo_prom_espera):
        self.cantidad = cantidad
        self.tiempo_espera = 0
        self.aforo = aforo
        # tiempo de espera promedio por persona en segundos
        self.tiempo_prom_espera = 50



async def request_post(requests, url ,personas):
    try:
        response = await requests.post(url, json={"cant_personas": personas.cantidad, "tiempo_espera":personas.tiempo_espera})
        print(f"Código de estado: {response.status_code}")
        print(f"Respuesta del servidor: {response.text}")
    except Exception as e:
        print(f"Error en la petición POST: {e}")


async def manejar_movimiento(pin, buzzer, personas, requests, url):
    sensor = digitalio.DigitalInOut(pin)
    sensor.direction = digitalio.Direction.INPUT

    while True:
        if not sensor.value:
            personas.cantidad += 1
            personas.tiempo_espera += personas.tiempo_prom_espera
            print(f"Gente! - Sensor: {sensor.value}, cantidad personar: {personas.cantidad}, tiempo de espera: {personas.tiempo_espera}")
            print("--------------")
            await manejar_buzzer(buzzer, personas)
            await request_post(requests, url, personas)

        await asyncio.sleep(0.2)


async def monitor_tiempo_espera(pin, buzzer, requests, url, personas):

    led = pwmio.PWMOut(pin, frequency=1000)

    while True:
        print(f"Cantidad de personas:{personas.cantidad}, tiempo de espera:{personas.tiempo_espera}")
        if personas.tiempo_espera > 0:
            personas.tiempo_espera -= 1
        else:
            personas.tiempo_espera = 0
        if (personas.cantidad-1) * personas.tiempo_prom_espera >= personas.tiempo_espera:
            personas.cantidad-=1
            await manejar_buzzer(buzzer, personas)
            await request_post(requests, url, personas)
        led.duty_cycle = int(65535 * personas.tiempo_espera / (personas.aforo * personas.tiempo_prom_espera))

        await asyncio.sleep(1)


async def manejar_buzzer(buzzer, personas):
    ocupacion = (personas.cantidad / personas.aforo) * 100
    # Sonidos según el porcentaje de ocupación
    if ocupacion >= 100:

        for _ in range(10):
            buzzer.value = True
            await asyncio.sleep(0.1)
            buzzer.value = False
            await asyncio.sleep(0.1)
    elif ocupacion >= 75:

        for _ in range(7):
            buzzer.value = True
            await asyncio.sleep(0.2)
            buzzer.value = False
            await asyncio.sleep(0.2)
    elif ocupacion >= 50:

        for _ in range(5):
            buzzer.value = True
            await asyncio.sleep(0.3)
            buzzer.value = False
            await asyncio.sleep(0.3)
    elif ocupacion >= 25:

        for _ in range(3):
            buzzer.value = True
            await asyncio.sleep(0.4)
            buzzer.value = False
            await asyncio.sleep(0.4)
    await asyncio.sleep(3)


async def main():
    wifi_connection(os.getenv("CIRCUITPY_WIFI_SSID"),os.getenv("CIRCUITPY_WIFI_PASSWORD"))
    personas = Personas(0, 10, 50)

    pool = socketpool.SocketPool(wifi.radio)
    requests = adafruit_requests.Session(pool, ssl.create_default_context())
    url = "http://192.168.0.131:8000/sensor"
    
    buzzer = digitalio.DigitalInOut(board.GP18)
    buzzer.direction = digitalio.Direction.OUTPUT
    buzzer.value = False
    
    sensor_task = asyncio.create_task(manejar_movimiento(board.GP15, buzzer, personas, requests, url))
    waiting_task = asyncio.create_task(monitor_tiempo_espera(board.GP0, buzzer, requests, url, personas))

    await asyncio.gather(sensor_task, waiting_task)

asyncio.run(main())
