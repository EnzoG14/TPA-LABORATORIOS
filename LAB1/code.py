import time
from machine import Pin, PWM
import uasyncio as asyncio
import micro_monitoring  # Reemplazar por circuit_monitoring si usas CircuitPython


class Personas(object):
    _instance = None  # Atributo de clase que almacena la única instancia

    def __new__(cls, *args, **kwargs):
        if cls._instance is None:
            # Si no existe instancia, la creamos
            cls._instance = super(Personas, cls).__new__(cls)
        return cls._instance

    def __init__(self, cantidad, aforo, tiempo_prom_espera):
        if not hasattr(self, '_initialized'):  # Evitar inicialización repetida
            self.cantidad = cantidad
            self.tiempo_espera = 0
            self.aforo = aforo
            self.tiempo_prom_espera = tiempo_prom_espera
            self.ultima_activacion = 0
            self._initialized = True  # Marca la instancia como inicializada

    def get_app_data(self):
        return {
            "tiempo_espera": self.tiempo_espera,
            "cantidad": self.cantidad
        }

    def __call__(self):
        # Al ser llamada, devuelve la misma instancia
        return self



def sensor_callback(pin, personas, buzzer):
    tiempo_actual = time.ticks_ms()
    tiempo_debouncing = 1500

    if time.ticks_diff(tiempo_actual, personas.ultima_activacion) > tiempo_debouncing:
        personas.ultima_activacion = tiempo_actual
        personas.cantidad += 1
        personas.tiempo_espera += personas.tiempo_prom_espera
        print(f"Gente! - Sensor activado, cantidad personas: {personas.cantidad}, tiempo de espera: {personas.tiempo_espera}")
        asyncio.create_task(manejar_buzzer(buzzer, personas))


async def monitor_tiempo_espera(pin, buzzer, personas):
    led = PWM(Pin(pin))
    led.freq(1000)

    while True:
        if personas.tiempo_espera > 0:
            personas.tiempo_espera -= 1
        else:
            personas.tiempo_espera = 0

        if (personas.cantidad - 1) * personas.tiempo_prom_espera >= personas.tiempo_espera:
            personas.cantidad -= 1
            print(f"¡Alguien se ha ido! Cantidad de personas: {personas.cantidad}, tiempo de espera: {personas.tiempo_espera}")
            await manejar_buzzer(buzzer, personas)

        duty_cycle = int(65535 * personas.tiempo_espera / (personas.aforo * personas.tiempo_prom_espera))
        led.duty_u16(duty_cycle)

        await asyncio.sleep(1)


async def manejar_buzzer(buzzer, personas):
    ocupacion = (personas.cantidad / personas.aforo) * 100
    beep_count = 0
    beep_delay = 0.5

    if ocupacion >= 100:
        beep_count, beep_delay = 10, 0.1
    elif ocupacion >= 75:
        beep_count, beep_delay = 7, 0.2
    elif ocupacion >= 50:
        beep_count, beep_delay = 5, 0.3
    elif ocupacion >= 25:
        beep_count, beep_delay = 3, 0.4

    for _ in range(beep_count):
        buzzer.value(1)
        await asyncio.sleep(beep_delay)
        buzzer.value(0)
        await asyncio.sleep(beep_delay)


async def operations():
    # Configuración del sensor de movimiento y buzzer
    personas = Personas(0, 10, 50)

    buzzer = Pin(18, Pin.OUT)
    buzzer.value(0)

    sensor_pin = Pin(15, Pin.IN)
    sensor_pin.irq(trigger=Pin.IRQ_FALLING, handler=lambda pin: sensor_callback(pin, personas, buzzer))

    # Monitoreo del tiempo de espera (LED PWM)
    await asyncio.create_task(monitor_tiempo_espera(0, buzzer, personas))


def get_app_data():
    # Función que devuelve un dict con la data para el maestro
    personas = Personas(0, 10, 50)  # Aquí deberías usar la instancia real de `personas`
    return personas.get_app_data()


async def main():
    # Funcionamiento del equipo y monitoreo con el maestro se ejecutan concurrentemente.
    await asyncio.gather(
        operations(),
        micro_monitoring.monitoring(get_app_data)  # Monitoreo del maestro
    )

asyncio.run(main())


