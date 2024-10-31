void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__QX0_0,data__->OUT1,retain)
  __INIT_LOCATED_VALUE(data__->OUT1,0)
  __INIT_LOCATED(BOOL,__IX0_0,data__->SENSOR,retain)
  __INIT_LOCATED_VALUE(data__->SENSOR,0)
  __INIT_VAR(data__->INPUTT,0,retain)
  __INIT_VAR(data__->INPUTT0,0,retain)
  __INIT_VAR(data__->TIEMPO,0,retain)
  TP_init__(&data__->TP1,retain);
  CTUD_init__(&data__->CTUD0,retain);
  TP_init__(&data__->TP3,retain);
  TOF_init__(&data__->TOF2,retain);
  CTU_init__(&data__->CTU1,retain);
  TP_init__(&data__->TP4,retain);
  TOF_init__(&data__->TOF3,retain);
  CTU_init__(&data__->CTU2,retain);
  TP_init__(&data__->TP5,retain);
  TOF_init__(&data__->TOF4,retain);
  CTU_init__(&data__->CTU3,retain);
  TP_init__(&data__->TP6,retain);
  TOF_init__(&data__->TOF5,retain);
  CTU_init__(&data__->CTU4,retain);
  TON_init__(&data__->TON0,retain);
  TP_init__(&data__->TP0,retain);
  TP_init__(&data__->TP2,retain);
  TP_init__(&data__->TP7,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  __INIT_VAR(data__->_TMP_MOD90_OUT,0,retain)
  __INIT_VAR(data__->_TMP_INT_TO_BOOL91_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT94_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND93_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT92_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT25_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND24_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR81_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG2,retain);
  __INIT_VAR(data__->_TMP_NOT68_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG3,retain);
  __INIT_VAR(data__->_TMP_OR27_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT71_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND66_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND65_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LE37_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE12_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND19_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT58_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG4,retain);
  __INIT_VAR(data__->_TMP_OR26_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT61_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND56_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND55_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR75_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LE17_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE34_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND16_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT48_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG5,retain);
  __INIT_VAR(data__->_TMP_OR1_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT51_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND46_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND45_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_LE36_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_GE10_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND14_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT35_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG6,retain);
  __INIT_VAR(data__->_TMP_OR76_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT40_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND23_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND43_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR22_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_OR44_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TP1.,IN,,__GET_LOCATED(data__->SENSOR,));
  __SET_VAR(data__->TP1.,PT,,__time_to_timespec(1, 200, 0, 0, 0, 0));
  TP_body__(&data__->TP1);
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->TP1.Q,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->,_TMP_MOD90_OUT,,MOD__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->CTUD0.CV,),
    (INT)2));
  __SET_VAR(data__->,_TMP_INT_TO_BOOL91_OUT,,INT_TO_BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->_TMP_MOD90_OUT,)));
  __SET_VAR(data__->TP2.,IN,,__GET_VAR(data__->_TMP_INT_TO_BOOL91_OUT,));
  __SET_VAR(data__->TP2.,PT,,__time_to_timespec(1, 100, 0, 0, 0, 0));
  TP_body__(&data__->TP2);
  __SET_VAR(data__->,_TMP_NOT94_OUT,,!(__GET_VAR(data__->TP2.Q,)));
  __SET_VAR(data__->,_TMP_AND93_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_INT_TO_BOOL91_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_NOT94_OUT,)));
  __SET_VAR(data__->,_TMP_NOT92_OUT,,!(__GET_VAR(data__->_TMP_INT_TO_BOOL91_OUT,)));
  __SET_VAR(data__->TP7.,IN,,__GET_VAR(data__->_TMP_NOT92_OUT,));
  __SET_VAR(data__->TP7.,PT,,__time_to_timespec(1, 100, 0, 0, 0, 0));
  TP_body__(&data__->TP7);
  __SET_VAR(data__->,_TMP_NOT25_OUT,,!(__GET_VAR(data__->TP7.Q,)));
  __SET_VAR(data__->,_TMP_AND24_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_NOT92_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_NOT25_OUT,)));
  __SET_VAR(data__->,_TMP_OR81_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND93_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_AND24_OUT,)));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->_TMP_OR81_OUT,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 10000, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->TP0.,IN,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TP0.,PT,,__time_to_timespec(1, 100, 0, 0, 0, 0));
  TP_body__(&data__->TP0);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->TP0.Q,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->CTUD0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTUD0.,CD,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTUD0.,PV,,10);
  CTUD_body__(&data__->CTUD0);
  __SET_VAR(data__->TOF5.,IN,,__GET_VAR(data__->TP6.Q,));
  __SET_VAR(data__->TOF5.,PT,,__time_to_timespec(1, 100, 0, 0, 0, 0));
  TOF_body__(&data__->TOF5);
  __SET_VAR(data__->,_TMP_NOT68_OUT,,!(__GET_VAR(data__->TOF5.Q,)));
  __SET_VAR(data__->TP6.,IN,,__GET_VAR(data__->_TMP_NOT68_OUT,));
  TP_body__(&data__->TP6);
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_VAR(data__->TP6.Q,));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->,_TMP_OR27_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->TP1.Q,),
    (BOOL)__GET_VAR(data__->TP0.Q,)));
  __SET_VAR(data__->CTU4.,CU,,__GET_VAR(data__->R_TRIG3.Q,));
  __SET_VAR(data__->CTU4.,R,,__GET_VAR(data__->_TMP_OR27_OUT,));
  __SET_VAR(data__->CTU4.,PV,,10);
  CTU_body__(&data__->CTU4);
  __SET_VAR(data__->,_TMP_NOT71_OUT,,!(__GET_VAR(data__->CTU4.Q,)));
  __SET_VAR(data__->,_TMP_AND66_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->TP6.Q,),
    (BOOL)__GET_VAR(data__->_TMP_NOT71_OUT,)));
  __SET_VAR(data__->,_TMP_AND65_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->CTUD0.QU,),
    (BOOL)__GET_VAR(data__->_TMP_AND66_OUT,)));
  __SET_VAR(data__->,_TMP_LE37_OUT,,LE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CTUD0.CV,),
    (INT)9));
  __SET_VAR(data__->,_TMP_GE12_OUT,,GE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CTUD0.CV,),
    (INT)8));
  __SET_VAR(data__->,_TMP_AND19_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_LE37_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_GE12_OUT,)));
  __SET_VAR(data__->TOF4.,IN,,__GET_VAR(data__->TP5.Q,));
  __SET_VAR(data__->TOF4.,PT,,__time_to_timespec(1, 300, 0, 0, 0, 0));
  TOF_body__(&data__->TOF4);
  __SET_VAR(data__->,_TMP_NOT58_OUT,,!(__GET_VAR(data__->TOF4.Q,)));
  __SET_VAR(data__->TP5.,IN,,__GET_VAR(data__->_TMP_NOT58_OUT,));
  TP_body__(&data__->TP5);
  __SET_VAR(data__->R_TRIG4.,CLK,,__GET_VAR(data__->TP5.Q,));
  R_TRIG_body__(&data__->R_TRIG4);
  __SET_VAR(data__->,_TMP_OR26_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->TP0.Q,),
    (BOOL)__GET_VAR(data__->TP1.Q,)));
  __SET_VAR(data__->CTU3.,CU,,__GET_VAR(data__->R_TRIG4.Q,));
  __SET_VAR(data__->CTU3.,R,,__GET_VAR(data__->_TMP_OR26_OUT,));
  __SET_VAR(data__->CTU3.,PV,,8);
  CTU_body__(&data__->CTU3);
  __SET_VAR(data__->,_TMP_NOT61_OUT,,!(__GET_VAR(data__->CTU3.Q,)));
  __SET_VAR(data__->,_TMP_AND56_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->TP5.Q,),
    (BOOL)__GET_VAR(data__->_TMP_NOT61_OUT,)));
  __SET_VAR(data__->,_TMP_AND55_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND19_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_AND56_OUT,)));
  __SET_VAR(data__->,_TMP_OR75_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND65_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_AND55_OUT,)));
  __SET_VAR(data__->,_TMP_LE17_OUT,,LE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CTUD0.CV,),
    (INT)7));
  __SET_VAR(data__->,_TMP_GE34_OUT,,GE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CTUD0.CV,),
    (INT)5));
  __SET_VAR(data__->,_TMP_AND16_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_LE17_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_GE34_OUT,)));
  __SET_VAR(data__->TOF3.,IN,,__GET_VAR(data__->TP4.Q,));
  __SET_VAR(data__->TOF3.,PT,,__time_to_timespec(1, 600, 0, 0, 0, 0));
  TOF_body__(&data__->TOF3);
  __SET_VAR(data__->,_TMP_NOT48_OUT,,!(__GET_VAR(data__->TOF3.Q,)));
  __SET_VAR(data__->TP4.,IN,,__GET_VAR(data__->_TMP_NOT48_OUT,));
  TP_body__(&data__->TP4);
  __SET_VAR(data__->R_TRIG5.,CLK,,__GET_VAR(data__->TP4.Q,));
  R_TRIG_body__(&data__->R_TRIG5);
  __SET_VAR(data__->,_TMP_OR1_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->TP1.Q,),
    (BOOL)__GET_VAR(data__->TP0.Q,)));
  __SET_VAR(data__->CTU2.,CU,,__GET_VAR(data__->R_TRIG5.Q,));
  __SET_VAR(data__->CTU2.,R,,__GET_VAR(data__->_TMP_OR1_OUT,));
  __SET_VAR(data__->CTU2.,PV,,6);
  CTU_body__(&data__->CTU2);
  __SET_VAR(data__->,_TMP_NOT51_OUT,,!(__GET_VAR(data__->CTU2.Q,)));
  __SET_VAR(data__->,_TMP_AND46_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->TP4.Q,),
    (BOOL)__GET_VAR(data__->_TMP_NOT51_OUT,)));
  __SET_VAR(data__->,_TMP_AND45_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND16_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_AND46_OUT,)));
  __SET_VAR(data__->,_TMP_LE36_OUT,,LE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CTUD0.CV,),
    (INT)4));
  __SET_VAR(data__->,_TMP_GE10_OUT,,GE__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CTUD0.CV,),
    (INT)3));
  __SET_VAR(data__->,_TMP_AND14_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_LE36_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_GE10_OUT,)));
  __SET_VAR(data__->TOF2.,IN,,__GET_VAR(data__->TP3.Q,));
  __SET_VAR(data__->TOF2.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TOF_body__(&data__->TOF2);
  __SET_VAR(data__->,_TMP_NOT35_OUT,,!(__GET_VAR(data__->TOF2.Q,)));
  __SET_VAR(data__->TP3.,IN,,__GET_VAR(data__->_TMP_NOT35_OUT,));
  TP_body__(&data__->TP3);
  __SET_VAR(data__->R_TRIG6.,CLK,,__GET_VAR(data__->TP3.Q,));
  R_TRIG_body__(&data__->R_TRIG6);
  __SET_VAR(data__->,_TMP_OR76_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->TP1.Q,),
    (BOOL)__GET_VAR(data__->TP0.Q,)));
  __SET_VAR(data__->CTU1.,CU,,__GET_VAR(data__->R_TRIG6.Q,));
  __SET_VAR(data__->CTU1.,R,,__GET_VAR(data__->_TMP_OR76_OUT,));
  __SET_VAR(data__->CTU1.,PV,,4);
  CTU_body__(&data__->CTU1);
  __SET_VAR(data__->,_TMP_NOT40_OUT,,!(__GET_VAR(data__->CTU1.Q,)));
  __SET_VAR(data__->,_TMP_AND23_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->TP3.Q,),
    (BOOL)__GET_VAR(data__->_TMP_NOT40_OUT,)));
  __SET_VAR(data__->,_TMP_AND43_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND14_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_AND23_OUT,)));
  __SET_VAR(data__->,_TMP_OR22_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND45_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_AND43_OUT,)));
  __SET_VAR(data__->,_TMP_OR44_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_OR75_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_OR22_OUT,)));
  __SET_LOCATED(data__->,OUT1,,__GET_VAR(data__->_TMP_OR44_OUT,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





