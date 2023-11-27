/*
 * Code generated for Simulink model E33_VCU_simulink.
 *
 * FILE    : E33_VCU_simulink.h
 *
 * VERSION : 1.70
 *
 * DATE    : Sun Nov 26 16:56:11 2023
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_E33_VCU_simulink_h_
#define RTW_HEADER_E33_VCU_simulink_h_
#include <math.h>
#include "etpu_util.h"
#include "etpu_ic.h"
#include "etpu_pwm.h"
#include "etpu_gpio.h"
#include "etpu_ppa.h"
#include "MPC5554.h"
#include "Std_Types.h"
#include "interrupts.h"
#include "siu.h"
#include "VIN.h"
#include "flash_app.h"
#ifndef E33_VCU_simulink_COMMON_INCLUDES_
# define E33_VCU_simulink_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* E33_VCU_simulink_COMMON_INCLUDES_ */

#include "E33_VCU_simulink_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#define EC_FLASH_ENABLE

/* Macros for accessing real-time model data structure */
#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define EnableInterrupts()             asm(" wrteei 1")
#define DisableInterrupts()            asm(" wrteei 0")

/* Block signals (auto storage) */
typedef struct {
  real_T Pump_ON;                      /* '<S170>/Pump' */
  real32_T MaxTemp_i;                  /* '<Root>/Rate Transition' */
  real32_T LEAK_OC;                    /* '<Root>/Rate Transition' */
  real32_T BMS_Stat;                   /* '<Root>/Rate Transition' */
  real32_T BMS_AlmLv_h;                /* '<Root>/Rate Transition' */
  real32_T BMS_Stat_g;                 /* '<S5>/Rate Transition1' */
  real32_T MCU_SpdCmd_i;               /* '<S5>/Rate Transition3' */
  real32_T MCU_TorqCmd_j;              /* '<S5>/Rate Transition3' */
  real32_T LEAK_OC_p;                  /* '<S5>/Rate Transition2' */
  real32_T BMS_AlmLv_c;                /* '<S5>/Rate Transition2' */
  real32_T MCU_McuTemp;                /* '<S5>/Rate Transition5' */
  real32_T MCU_MotorTemp;              /* '<S5>/Rate Transition5' */
  real32_T MCU_IsReady;                /* '<S5>/Rate Transition5' */
  real32_T MaxTemp_f;                  /* '<S5>/Rate Transition5' */
  real32_T BMS_Stat_k;                 /* '<S5>/Rate Transition5' */
  real32_T MCU_HvCurr_sat;             /* '<S132>/MCU_HvCurr_sat' */
  real32_T MCU_McuTemp_sat;            /* '<S132>/MCU_McuTemp_sat' */
  real32_T MCU_MotorTemp_sat;          /* '<S132>/MCU_MotorTemp_sat' */
  real32_T MCU_IsReady_sat;            /* '<S111>/MCU_IsReady_sat' */
  real32_T MCU_SPD_RPT_sat;            /* '<S111>/MCU_SPD_RPT_sat' */
  real32_T BatState_sat;               /* '<S84>/BatState_sat' */
  real32_T BMS_ALM_LEAK_OC_sat;        /* '<S53>/BMS_ALM_LEAK_OC_sat' */
  real32_T BMS_AlmLv_g;                /* '<S1>/Signal Conversion' */
  real32_T BMS_Stat_p;                 /* '<S1>/Signal Conversion' */
  real32_T LEAK_OC_p0;                 /* '<S1>/Signal Conversion' */
  real32_T MCU_TorqCmd_h;              /* '<S1>/Signal Conversion' */
  real32_T MCU_SpdCmd_o;               /* '<S1>/Signal Conversion' */
  real32_T MaxTemp_g;                  /* '<S1>/Signal Conversion' */
  real32_T MCU_IsReady_b;              /* '<S1>/Signal Conversion' */
  real32_T MCU_MotorTemp_e;            /* '<S1>/Signal Conversion' */
  real32_T MCU_McuTemp_f;              /* '<S1>/Signal Conversion' */
  int32_T Wheel_Angle_a;               /* '<S5>/Rate Transition6' */
  int32_T Wheel_Angle_e;               /* '<S1>/Signal Conversion' */
  uint32_T FanOnTime;                  /* '<S170>/Data Type Conversion8' */
  uint32_T FanOnTime_c;                /* '<S170>/Data Type Conversion15' */
  uint32_T TailLightOnTime;            /* '<S169>/Data Type Conversion1' */
  uint32_T CANReceive_o3;              /* '<S163>/CANReceive' */
  uint32_T CANReceive1_o3;             /* '<S149>/CANReceive1' */
  uint32_T CANReceive_o3_i;            /* '<S28>/CANReceive' */
  uint32_T CANReceive1_o3_f;           /* '<S28>/CANReceive1' */
  uint32_T BMS_ALM_Receive_o3;         /* '<S25>/BMS_ALM_Receive' */
  uint32_T BMS_MXV_Receive_o3;         /* '<S25>/BMS_MXV_Receive' */
  uint32_T BMS_INFO_Receive_o3;        /* '<S25>/BMS_INFO_Receive' */
  uint32_T BMS_MAXT_Receive_o3;        /* '<S25>/BMS_MAXT_Receive' */
  uint16_T BP_F_Pos_l;                 /* '<S5>/Rate Transition4' */
  uint16_T Linear_FL_d;                /* '<S5>/Rate Transition6' */
  uint16_T Linear_RL_a;                /* '<S5>/Rate Transition6' */
  uint16_T Linear_FR_p;                /* '<S5>/Rate Transition6' */
  uint16_T Linear_RR_k;                /* '<S5>/Rate Transition6' */
  uint16_T FanDutyCycl;                /* '<S170>/Accu_FAN1' */
  uint16_T FanDutyCycl_o;              /* '<S170>/Accu_FAN' */
  uint16_T LEDDutyCyc;                 /* '<S169>/LED' */
  uint16_T AnalogInput;                /* '<S30>/AnalogInput' */
  uint16_T AnalogInput1;               /* '<S30>/AnalogInput1' */
  uint16_T AnalogInput2;               /* '<S30>/AnalogInput2' */
  uint16_T AnalogInput3;               /* '<S30>/AnalogInput3' */
  uint16_T BP_F_Pos_m;                 /* '<S1>/Signal Conversion' */
  uint16_T Linear_RR_b;                /* '<S1>/Signal Conversion' */
  uint16_T Linear_FR_l;                /* '<S1>/Signal Conversion' */
  uint16_T Linear_RL_b;                /* '<S1>/Signal Conversion' */
  uint16_T Linear_FL_a;                /* '<S1>/Signal Conversion' */
  uint8_T APPS_Unreliable_g;           /* '<S5>/Rate Transition2' */
  uint8_T or1;                         /* '<S203>/or1' */
  uint8_T or2;                         /* '<S203>/or2' */
  uint8_T or3;                         /* '<S203>/or3' */
  uint8_T or4;                         /* '<S203>/or4' */
  uint8_T or5;                         /* '<S203>/or5' */
  uint8_T or6;                         /* '<S203>/or6' */
  uint8_T or7;                         /* '<S203>/or7' */
  uint8_T or8;                         /* '<S203>/or8' */
  uint8_T CANTransmit;                 /* '<S171>/CANTransmit' */
  uint8_T or1_m;                       /* '<S175>/or1' */
  uint8_T or2_k;                       /* '<S175>/or2' */
  uint8_T or3_e;                       /* '<S175>/or3' */
  uint8_T or4_h;                       /* '<S175>/or4' */
  uint8_T or5_j;                       /* '<S175>/or5' */
  uint8_T or6_i;                       /* '<S175>/or6' */
  uint8_T or7_g;                       /* '<S175>/or7' */
  uint8_T or8_n;                       /* '<S175>/or8' */
  uint8_T CANReceive_o2;               /* '<S163>/CANReceive' */
  uint8_T CANReceive_o4[8];            /* '<S163>/CANReceive' */
  uint8_T CANReceive_o5;               /* '<S163>/CANReceive' */
  uint8_T CANReceive1_o2;              /* '<S149>/CANReceive1' */
  uint8_T CANReceive1_o4[8];           /* '<S149>/CANReceive1' */
  uint8_T CANReceive1_o5;              /* '<S149>/CANReceive1' */
  uint8_T CANTransmit_h;               /* '<S155>/CANTransmit' */
  uint8_T CANReceive_o4_l[8];          /* '<S28>/CANReceive' */
  uint8_T CANReceive_o5_h;             /* '<S28>/CANReceive' */
  uint8_T CANReceive1_o4_c[8];         /* '<S28>/CANReceive1' */
  uint8_T CANReceive1_o5_a;            /* '<S28>/CANReceive1' */
  uint8_T BMS_ALM_Receive_o2;          /* '<S25>/BMS_ALM_Receive' */
  uint8_T BMS_ALM_Receive_o4[8];       /* '<S25>/BMS_ALM_Receive' */
  uint8_T BMS_ALM_Receive_o5;          /* '<S25>/BMS_ALM_Receive' */
  uint8_T BMS_MXV_Receive_o2;          /* '<S25>/BMS_MXV_Receive' */
  uint8_T BMS_MXV_Receive_o4[8];       /* '<S25>/BMS_MXV_Receive' */
  uint8_T BMS_MXV_Receive_o5;          /* '<S25>/BMS_MXV_Receive' */
  uint8_T BMS_INFO_Receive_o2;         /* '<S25>/BMS_INFO_Receive' */
  uint8_T BMS_INFO_Receive_o4[8];      /* '<S25>/BMS_INFO_Receive' */
  uint8_T BMS_INFO_Receive_o5;         /* '<S25>/BMS_INFO_Receive' */
  uint8_T BMS_MAXT_Receive_o2;         /* '<S25>/BMS_MAXT_Receive' */
  uint8_T BMS_MAXT_Receive_o4[8];      /* '<S25>/BMS_MAXT_Receive' */
  uint8_T BMS_MAXT_Receive_o5;         /* '<S25>/BMS_MAXT_Receive' */
  uint8_T APPS_Unreliable_o;           /* '<S1>/Signal Conversion' */
  boolean_T BMS_Online_m;              /* '<Root>/Rate Transition' */
  boolean_T BMS_Online_o;              /* '<S5>/Rate Transition1' */
  boolean_T MCU_Online_g;              /* '<S5>/Rate Transition3' */
  boolean_T MCU_Cut_o;                 /* '<S5>/Rate Transition3' */
  boolean_T BMS_Online_n;              /* '<S5>/Rate Transition2' */
  boolean_T VehReady_e;                /* '<S5>/Rate Transition2' */
  boolean_T VehStandby_n;              /* '<S5>/Rate Transition2' */
  boolean_T BeeperOut;                 /* '<S5>/Rate Transition2' */
  boolean_T BMS_Online_f;              /* '<S5>/Rate Transition5' */
  boolean_T DCDC_ON_l;                 /* '<S166>/DCDC_Ctrl' */
  boolean_T Switch3;                   /* '<S170>/Switch3' */
  boolean_T DataTypeConversion1;       /* '<S168>/Data Type Conversion1' */
  boolean_T LED;                       /* '<S168>/IMD_ALM' */
  boolean_T LED_g;                     /* '<S168>/BMS_ALM' */
  boolean_T Compare;                   /* '<S107>/Compare' */
  boolean_T Compare_m;                 /* '<S108>/Compare' */
  boolean_T R2D_In;                    /* '<S27>/R2D_In' */
  boolean_T Compare_n;                 /* '<S49>/Compare' */
  boolean_T Compare_d;                 /* '<S50>/Compare' */
  boolean_T Compare_i;                 /* '<S51>/Compare' */
  boolean_T Compare_f;                 /* '<S52>/Compare' */
  boolean_T BMS_Online_c;              /* '<S1>/Signal Conversion' */
  boolean_T MCU_Cut_k;                 /* '<S1>/Signal Conversion' */
  boolean_T BeeperOut_g;               /* '<S1>/Signal Conversion' */
  boolean_T MCU_Online_n;              /* '<S1>/Signal Conversion' */
  boolean_T VehStandby_e;              /* '<S1>/Signal Conversion' */
  boolean_T VehReady_f;                /* '<S1>/Signal Conversion' */
  boolean_T BeeperStOut;               /* '<S6>/Chart' */
} B_E33_VCU_simulink_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint16_T TappedDelay_X[6];           /* '<S140>/Tapped Delay' */
  uint16_T TappedDelay_X_o[6];         /* '<S138>/Tapped Delay' */
  uint16_T TappedDelay_X_c[6];         /* '<S139>/Tapped Delay' */
  uint16_T TappedDelay_X_k[6];         /* '<S141>/Tapped Delay' */
  uint16_T TappedDelay_X_a[6];         /* '<S31>/Tapped Delay' */
  uint16_T TappedDelay_X_h[6];         /* '<S32>/Tapped Delay' */
  real32_T DelayInput2_DSTATE;         /* '<S12>/Delay Input2' */
  real32_T RateTransition_53_Buffer0;  /* '<Root>/Rate Transition' */
  real32_T RateTransition_25_Buffer0;  /* '<Root>/Rate Transition' */
  real32_T RateTransition_18_Buffer0;  /* '<Root>/Rate Transition' */
  real32_T RateTransition_17_Buffer0;  /* '<Root>/Rate Transition' */
  real32_T MCU_IsMcuNOTActive_st_DWORK1;/* '<S180>/MCU_IsMcuNOTActive_st' */
  uint32_T FunctionCallSubsystem_ELAPS_T;/* '<Root>/Function-Call Subsystem' */
  uint32_T FunctionCallSubsystem_PREV_T;/* '<Root>/Function-Call Subsystem' */
  uint32_T presentTicks;               /* '<S166>/DCDC_Ctrl' */
  uint32_T elapsedTicks;               /* '<S166>/DCDC_Ctrl' */
  uint32_T previousTicks;              /* '<S166>/DCDC_Ctrl' */
  uint32_T presentTicks_c;             /* '<S170>/Pump' */
  uint32_T elapsedTicks_d;             /* '<S170>/Pump' */
  uint32_T previousTicks_k;            /* '<S170>/Pump' */
  uint32_T temporalCounter_i1;         /* '<S170>/Accu_FAN1' */
  uint32_T presentTicks_j;             /* '<S170>/Accu_FAN1' */
  uint32_T elapsedTicks_e;             /* '<S170>/Accu_FAN1' */
  uint32_T previousTicks_l;            /* '<S170>/Accu_FAN1' */
  uint32_T temporalCounter_i1_b;       /* '<S170>/Accu_FAN' */
  uint32_T presentTicks_h;             /* '<S170>/Accu_FAN' */
  uint32_T elapsedTicks_dj;            /* '<S170>/Accu_FAN' */
  uint32_T previousTicks_g;            /* '<S170>/Accu_FAN' */
  uint32_T presentTicks_o;             /* '<S168>/Ready_SW' */
  uint32_T elapsedTicks_n;             /* '<S168>/Ready_SW' */
  uint32_T previousTicks_b;            /* '<S168>/Ready_SW' */
  uint32_T presentTicks_oa;            /* '<S168>/IMD_ALM' */
  uint32_T elapsedTicks_ea;            /* '<S168>/IMD_ALM' */
  uint32_T previousTicks_la;           /* '<S168>/IMD_ALM' */
  uint32_T presentTicks_e;             /* '<S168>/BMS_ALM' */
  uint32_T elapsedTicks_m;             /* '<S168>/BMS_ALM' */
  uint32_T previousTicks_n;            /* '<S168>/BMS_ALM' */
  uint32_T temporalCounter_i1_h;       /* '<S169>/LED' */
  uint32_T presentTicks_i;             /* '<S169>/LED' */
  uint32_T elapsedTicks_g;             /* '<S169>/LED' */
  uint32_T previousTicks_nj;           /* '<S169>/LED' */
  uint32_T Counter1_Count;             /* '<S28>/Counter1' */
  uint32_T Counter2_Count;             /* '<S28>/Counter2' */
  uint32_T temporalCounter_i1_hh;      /* '<S6>/Chart' */
  uint32_T presentTicks_b;             /* '<S6>/Chart' */
  uint32_T elapsedTicks_h;             /* '<S6>/Chart' */
  uint32_T previousTicks_ge;           /* '<S6>/Chart' */
  struct {
    uint_T is_VehStat:3;               /* '<S6>/Chart' */
    uint_T is_BeeperStat:2;            /* '<S6>/Chart' */
    uint_T is_active_c3_E33_VCU_simulink:1;/* '<S6>/Chart' */
    uint_T is_active_VehStat:1;        /* '<S6>/Chart' */
    uint_T is_active_Output:1;         /* '<S6>/Chart' */
    uint_T is_active_BeeperStat:1;     /* '<S6>/Chart' */
  } bitsForTID3;

  struct {
    uint_T is_LEDStat_p:3;             /* '<S169>/LED' */
    uint_T is_Blink_b:2;               /* '<S169>/LED' */
    uint_T is_active_c4_E33_VCU_simulink:1;/* '<S169>/LED' */
    uint_T is_c4_E33_VCU_simulink:1;   /* '<S169>/LED' */
  } bitsForTID4;

  struct {
    uint_T is_Pump_MR:3;               /* '<S170>/Pump' */
    uint_T is_LEDStat:3;               /* '<S170>/Accu_FAN' */
    uint_T is_LEDStat_m:3;             /* '<S168>/Ready_SW' */
    uint_T is_LEDStat_l:3;             /* '<S168>/IMD_ALM' */
    uint_T is_LEDStat_li:3;            /* '<S168>/BMS_ALM' */
    uint_T is_DCDC_MR:2;               /* '<S166>/DCDC_Ctrl' */
    uint_T is_LEDStat_mt:2;            /* '<S170>/Accu_FAN1' */
    uint_T is_Blink:2;                 /* '<S168>/Ready_SW' */
    uint_T is_FastBlink:2;             /* '<S168>/Ready_SW' */
    uint_T is_BlevelAlm:2;             /* '<S168>/BMS_ALM' */
    uint_T is_active_c13_E33_VCU_simulink:1;/* '<S166>/DCDC_Ctrl' */
    uint_T is_c13_E33_VCU_simulink:1;  /* '<S166>/DCDC_Ctrl' */
    uint_T is_active_c5_E33_VCU_simulink:1;/* '<S170>/Pump' */
    uint_T is_c5_E33_VCU_simulink:1;   /* '<S170>/Pump' */
    uint_T is_active_c1_E33_VCU_simulink:1;/* '<S170>/Accu_FAN1' */
    uint_T is_c1_E33_VCU_simulink:1;   /* '<S170>/Accu_FAN1' */
    uint_T is_active_c14_E33_VCU_simulink:1;/* '<S170>/Accu_FAN' */
    uint_T is_c14_E33_VCU_simulink:1;  /* '<S170>/Accu_FAN' */
    uint_T is_active_c6_E33_VCU_simulink:1;/* '<S168>/Ready_SW' */
    uint_T is_c6_E33_VCU_simulink:1;   /* '<S168>/Ready_SW' */
    uint_T is_active_c11_E33_VCU_simulink:1;/* '<S168>/IMD_ALM' */
    uint_T is_c11_E33_VCU_simulink:1;  /* '<S168>/IMD_ALM' */
    uint_T is_active_c8_E33_VCU_simulink:1;/* '<S168>/BMS_ALM' */
    uint_T is_c8_E33_VCU_simulink:1;   /* '<S168>/BMS_ALM' */
  } bitsForTID5;

  uint8_T UnitDelay1_DSTATE;           /* '<S28>/Unit Delay1' */
  uint8_T UnitDelay2_DSTATE;           /* '<S28>/Unit Delay2' */
  uint8_T UnitDelay_DSTATE;            /* '<S25>/Unit Delay' */
  uint8_T UnitDelay1_DSTATE_l;         /* '<S25>/Unit Delay1' */
  uint8_T UnitDelay2_DSTATE_c;         /* '<S25>/Unit Delay2' */
  uint8_T UnitDelay3_DSTATE;           /* '<S25>/Unit Delay3' */
  boolean_T UnitDelay_1_DSTATE;        /* '<S1>/Unit Delay' */
  boolean_T UnitDelay_8_DSTATE;        /* '<S1>/Unit Delay' */
  uint8_T temporalCounter_i1_i;        /* '<S166>/DCDC_Ctrl' */
  uint8_T temporalCounter_i1_bk;       /* '<S170>/Pump' */
  uint8_T temporalCounter_i1_be;       /* '<S168>/Ready_SW' */
  uint8_T temporalCounter_i1_p;        /* '<S168>/IMD_ALM' */
  uint8_T temporalCounter_i1_pw;       /* '<S168>/BMS_ALM' */
  uint8_T Counter_Count;               /* '<S25>/Counter' */
  uint8_T Counter1_Count_n;            /* '<S25>/Counter1' */
  uint8_T Counter2_Count_c;            /* '<S25>/Counter2' */
  uint8_T Counter3_Count;              /* '<S25>/Counter3' */
  boolean_T RateTransition_15_Buffer0; /* '<Root>/Rate Transition' */
  boolean_T FunctionCallSubsystem_RESET_ELA;/* '<Root>/Function-Call Subsystem' */
} DW_E33_VCU_simulink_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: [1000,500,0]
   * Referenced by: '<S7>/PwrLimDerateCur'
   */
  real_T PwrLimDerateCur_table[3];

  /* Expression: [0.95,0.98,0.99]
   * Referenced by: '<S7>/PwrLimDerateCur'
   */
  real_T PwrLimDerateCur_bp01D[3];

  /* Expression: Torq_percentage_Map
   * Referenced by: '<S7>/BasicTorqueCal'
   */
  real_T BasicTorqueCal_tabl[110];

  /* Computed Parameter: BasicTorqueCal_bp01Da
   * Referenced by: '<S7>/BasicTorqueCal'
   */
  real32_T BasicTorqueCal_bp01Da[2];

  /* Computed Parameter: BasicTorqueCal_bp02D
   * Referenced by: '<S7>/BasicTorqueCal'
   */
  real32_T BasicTorqueCal_bp02D[55];

  /* Computed Parameter: DLookupTable1_tableDa
   * Referenced by: '<S170>/1-D Lookup Table1'
   */
  real32_T DLookupTable1_tableDa[2];

  /* Computed Parameter: DLookupTable5_tableDa
   * Referenced by: '<S30>/1-D Lookup Table5'
   */
  int32_T DLookupTable5_tableDa[7];

  /* Computed Parameter: DLookupTable5_bp01Dat
   * Referenced by: '<S30>/1-D Lookup Table5'
   */
  int32_T DLookupTable5_bp01Dat[7];

  /* Computed Parameter: BasicTorqueCal_maxInd
   * Referenced by: '<S7>/BasicTorqueCal'
   */
  uint32_T BasicTorqueCal_maxInd[2];

  /* Computed Parameter: PwrLimDerateCur1_tabl
   * Referenced by: '<S7>/PwrLimDerateCur1'
   */
  uint16_T PwrLimDerateCur1_tabl[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S7>/PwrLimDerateCur1'
   *   '<S24>/1-D Lookup Table'
   *   '<S24>/1-D Lookup Table1'
   *   '<S26>/1-D Lookup Table'
   *   '<S26>/1-D Lookup Table1'
   */
  uint16_T pooled32[2];
} ConstP_E33_VCU_simulink_T;

/* Real-time Model Data Structure */
struct tag_RTM_E33_VCU_simulink_T {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick3;
    uint32_T clockTick4;
    uint32_T clockTick5;
    struct {
      uint16_T TID[8];
    } TaskCounters;

    struct {
      boolean_T TID3_4;
      boolean_T TID3_5;
      boolean_T TID3_6;
    } RateInteraction;
  } Timing;
};

/* Block signals (auto storage) */
extern B_E33_VCU_simulink_T E33_VCU_simulink_B;

/* Block states (auto storage) */
extern DW_E33_VCU_simulink_T E33_VCU_simulink_DW;

/* Constant parameters (auto storage) */
extern const ConstP_E33_VCU_simulink_T E33_VCU_simulink_ConstP;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T Beep_Time;               /* Variable: Beep_Time
                                        * Referenced by: '<S6>/Constant'
                                        */
extern real_T Brk_luminance;           /* Variable: Brk_luminance
                                        * Referenced by: '<S169>/Constant1'
                                        */
extern real_T FactoryTestEnable;       /* Variable: FactoryTestEnable
                                        * Referenced by:
                                        *   '<S166>/Constant4'
                                        *   '<S168>/Constant10'
                                        *   '<S168>/Constant4'
                                        *   '<S168>/Constant6'
                                        *   '<S168>/Constant8'
                                        *   '<S169>/Constant8'
                                        *   '<S170>/Constant11'
                                        *   '<S170>/Constant13'
                                        *   '<S170>/Constant8'
                                        */
extern real_T HardBrk_luminance;       /* Variable: HardBrk_luminance
                                        * Referenced by: '<S169>/Constant2'
                                        */
extern real32_T Accu_FAN_threshold[2]; /* Variable: Accu_FAN_threshold
                                        * Referenced by: '<S170>/1-D Lookup Table1'
                                        */
extern real32_T Pump_threshold;        /* Variable: Pump_threshold
                                        * Referenced by: '<S197>/Constant'
                                        */
extern uint32_T Accu_FAN_Test;         /* Variable: Accu_FAN_Test
                                        * Referenced by: '<S170>/Constant12'
                                        */
extern uint32_T Radiator_FAN_Test;     /* Variable: Radiator_FAN_Test
                                        * Referenced by: '<S170>/Constant14'
                                        */
extern uint32_T Tail_Light_Test;       /* Variable: Tail_Light_Test
                                        * Referenced by: '<S169>/Constant5'
                                        */
extern uint32_T APPS_threshold;        /* Variable: APPS_threshold
                                        * Referenced by: '<S10>/Constant'
                                        */
extern uint16_T APPS1_Voltage[2];      /* Variable: APPS1_Voltage
                                        * Referenced by: '<S24>/1-D Lookup Table'
                                        */
extern uint16_T APPS2_Voltage[2];      /* Variable: APPS2_Voltage
                                        * Referenced by: '<S24>/1-D Lookup Table1'
                                        */
extern uint16_T BP_F_Voltage[2];       /* Variable: BP_F_Voltage
                                        * Referenced by: '<S26>/1-D Lookup Table1'
                                        */
extern uint16_T BP_F_threshold;        /* Variable: BP_F_threshold
                                        * Referenced by: '<S11>/Constant'
                                        */
extern uint16_T BP_R_Voltage[2];       /* Variable: BP_R_Voltage
                                        * Referenced by: '<S26>/1-D Lookup Table'
                                        */
extern uint16_T MaxRPMchangePerSec;    /* Variable: MaxRPMchangePerSec
                                        * Referenced by: '<S7>/MaxCmdStep1'
                                        */
extern uint16_T MaxTorqChangePerSec;   /* Variable: MaxTorqChangePerSec
                                        * Referenced by: '<S7>/MaxCmdStep2'
                                        */
extern uint16_T SCS_Error_5V;          /* Variable: SCS_Error_5V
                                        * Referenced by:
                                        *   '<S37>/Constant'
                                        *   '<S39>/Constant'
                                        *   '<S100>/Constant'
                                        *   '<S102>/Constant'
                                        */
extern uint16_T SCS_Error_GND;         /* Variable: SCS_Error_GND
                                        * Referenced by:
                                        *   '<S38>/Constant'
                                        *   '<S40>/Constant'
                                        *   '<S101>/Constant'
                                        *   '<S103>/Constant'
                                        */
extern uint16_T linear_FL_Map[2];      /* Variable: linear_FL_Map
                                        * Referenced by: '<S30>/1-D Lookup Table4'
                                        */
extern uint16_T linear_FR_Map[2];      /* Variable: linear_FR_Map
                                        * Referenced by: '<S30>/1-D Lookup Table2'
                                        */
extern uint16_T linear_Map[2];         /* Variable: linear_Map
                                        * Referenced by:
                                        *   '<S30>/1-D Lookup Table1'
                                        *   '<S30>/1-D Lookup Table2'
                                        *   '<S30>/1-D Lookup Table3'
                                        *   '<S30>/1-D Lookup Table4'
                                        */
extern uint16_T linear_RL_Map[2];      /* Variable: linear_RL_Map
                                        * Referenced by: '<S30>/1-D Lookup Table3'
                                        */
extern uint16_T linear_RR_Map[2];      /* Variable: linear_RR_Map
                                        * Referenced by: '<S30>/1-D Lookup Table1'
                                        */
extern boolean_T BMSLedTest;           /* Variable: BMSLedTest
                                        * Referenced by: '<S168>/Constant9'
                                        */
extern boolean_T BeeperTest;           /* Variable: BeeperTest
                                        * Referenced by: '<S168>/Constant7'
                                        */
extern boolean_T DCDC_Relay_Test;      /* Variable: DCDC_Relay_Test
                                        * Referenced by: '<S166>/Constant5'
                                        */
extern boolean_T IMDLedTest;           /* Variable: IMDLedTest
                                        * Referenced by: '<S168>/Constant11'
                                        */
extern boolean_T Pump_Test;            /* Variable: Pump_Test
                                        * Referenced by: '<S170>/Constant9'
                                        */
extern boolean_T R2D_Light_Test;       /* Variable: R2D_Light_Test
                                        * Referenced by: '<S168>/Constant5'
                                        */

/* External function called from main */
extern void E33_VCU_simulink_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void E33_VCU_simulink_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void E33_VCU_simulink_initialize(void);
extern void E33_VCU_simulink_step(int_T tid);
extern uint8_T ECUCoderModelBaseCounter;
extern uint8_T AfterRunFlags[2];

/* Exported data declaration */

/* Declaration for custom storage class: Default */
extern boolean_T APPS1_Disconnect;
extern uint16_T APPS1_PWR;
extern uint16_T APPS1_Pos;
extern uint16_T APPS1_Vol_In;
extern boolean_T APPS2_Disconnect;
extern uint16_T APPS2_PWR;
extern uint16_T APPS2_Pos;
extern uint16_T APPS2_Vol_In;
extern uint16_T APPSUn_dif;
extern boolean_T APPS_OK;
extern uint32_T APPS_Pos;
extern uint8_T APPS_Unreliable;
extern boolean_T A_level_Warn;
extern uint16_T Angle_Vol;
extern uint8_T BMSALMCnt;
extern uint8_T BMSInfoCnt;
extern uint8_T BMSMAXTCnt;
extern uint8_T BMSMXVCnt;
extern real32_T BMS_AlmLv;
extern real32_T BMS_Current;
extern boolean_T BMS_Online;
extern real32_T BMS_SoC;
extern real32_T BMS_Voltage;
extern boolean_T BP_F_Disconnect;
extern boolean_T BP_F_OK;
extern uint16_T BP_F_Pos;
extern uint16_T BP_F_Vol_In;
extern uint16_T BP_Lim_T;
extern uint16_T BP_PWR;
extern boolean_T BP_R_Disconnect;
extern uint16_T BP_R_Pos;
extern uint16_T BP_R_Vol_In;
extern boolean_T B_level_Warn;
extern boolean_T BadApp1Alm;
extern boolean_T BadApp2Alm;
extern boolean_T BadMcuAlm;
extern boolean_T Bad_APPAlm;
extern boolean_T BeeperStat;
extern boolean_T BmsLedStat;
extern boolean_T DCDC_MR;
extern boolean_T DCDC_ON;
extern uint16_T Dri_T_request;
extern uint16_T I_BAT;
extern uint16_T I_UBR;
extern boolean_T ImdLedStat;
extern uint8_T Infomation_OK;
extern uint16_T Linear_FL;
extern uint16_T Linear_FR;
extern uint16_T Linear_RL;
extern uint16_T Linear_RR;
extern boolean_T MCU_Cut;
extern real32_T MCU_HvVolt;
extern boolean_T MCU_Online;
extern boolean_T MCU_Ready;
extern real32_T MCU_SpdCmd;
extern real32_T MCU_TorqCmd;
extern real32_T MaxTemp;
extern real32_T Maxchange_Lim_T;
extern uint32_T McuInfoOfflineCnt;
extern uint32_T McuStatelineCnt;
extern uint16_T PWR_5V;
extern real32_T Pwr_Lim;
extern boolean_T R2D_Light;
extern boolean_T R2D_SW;
extern boolean_T ReadyLEDstat;
extern uint8_T State_OK;
extern uint8_T VCUMCUCANOKK;
extern boolean_T VehReady;
extern boolean_T VehStandby;
extern int32_T Wheel_Angle;

/* Real-time Model object */
extern RT_MODEL_E33_VCU_simulink_T *const E33_VCU_simulink_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'E33_VCU_simulink'
 * '<S1>'   : 'E33_VCU_simulink/Function-Call Subsystem'
 * '<S2>'   : 'E33_VCU_simulink/Input'
 * '<S3>'   : 'E33_VCU_simulink/RapidECUSetting'
 * '<S4>'   : 'E33_VCU_simulink/Subsystem'
 * '<S5>'   : 'E33_VCU_simulink/Subsystem1'
 * '<S6>'   : 'E33_VCU_simulink/Function-Call Subsystem/R2D_State'
 * '<S7>'   : 'E33_VCU_simulink/Function-Call Subsystem/Veh_Dynamic'
 * '<S8>'   : 'E33_VCU_simulink/Function-Call Subsystem/Warn'
 * '<S9>'   : 'E33_VCU_simulink/Function-Call Subsystem/R2D_State/Chart'
 * '<S10>'  : 'E33_VCU_simulink/Function-Call Subsystem/R2D_State/Compare To Constant'
 * '<S11>'  : 'E33_VCU_simulink/Function-Call Subsystem/R2D_State/Compare To Constant1'
 * '<S12>'  : 'E33_VCU_simulink/Function-Call Subsystem/Veh_Dynamic/Rate Limiter Dynamic'
 * '<S13>'  : 'E33_VCU_simulink/Function-Call Subsystem/Veh_Dynamic/Saturation Dynamic'
 * '<S14>'  : 'E33_VCU_simulink/Function-Call Subsystem/Veh_Dynamic/Rate Limiter Dynamic/Saturation Dynamic'
 * '<S15>'  : 'E33_VCU_simulink/Function-Call Subsystem/Warn/A_level_Warn'
 * '<S16>'  : 'E33_VCU_simulink/Function-Call Subsystem/Warn/B_level_Warn'
 * '<S17>'  : 'E33_VCU_simulink/Function-Call Subsystem/Warn/A_level_Warn/Compare To Constant'
 * '<S18>'  : 'E33_VCU_simulink/Function-Call Subsystem/Warn/A_level_Warn/Compare To Constant1'
 * '<S19>'  : 'E33_VCU_simulink/Function-Call Subsystem/Warn/A_level_Warn/Compare To Constant2'
 * '<S20>'  : 'E33_VCU_simulink/Function-Call Subsystem/Warn/A_level_Warn/Compare To Constant5'
 * '<S21>'  : 'E33_VCU_simulink/Function-Call Subsystem/Warn/B_level_Warn/Compare To Constant1'
 * '<S22>'  : 'E33_VCU_simulink/Function-Call Subsystem/Warn/B_level_Warn/Compare To Constant2'
 * '<S23>'  : 'E33_VCU_simulink/Input/Input'
 * '<S24>'  : 'E33_VCU_simulink/Input/Input/APPS'
 * '<S25>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive'
 * '<S26>'  : 'E33_VCU_simulink/Input/Input/Bpressure'
 * '<S27>'  : 'E33_VCU_simulink/Input/Input/Keys'
 * '<S28>'  : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive'
 * '<S29>'  : 'E33_VCU_simulink/Input/Input/Self_inspection'
 * '<S30>'  : 'E33_VCU_simulink/Input/Input/Sensor'
 * '<S31>'  : 'E33_VCU_simulink/Input/Input/APPS/Filter1 '
 * '<S32>'  : 'E33_VCU_simulink/Input/Input/APPS/Filter2 '
 * '<S33>'  : 'E33_VCU_simulink/Input/Input/APPS/Reliability testing'
 * '<S34>'  : 'E33_VCU_simulink/Input/Input/APPS/SCS_Wire_breakage_detection'
 * '<S35>'  : 'E33_VCU_simulink/Input/Input/APPS/Subsystem'
 * '<S36>'  : 'E33_VCU_simulink/Input/Input/APPS/Reliability testing/Pedal stroke 10%'
 * '<S37>'  : 'E33_VCU_simulink/Input/Input/APPS/SCS_Wire_breakage_detection/Compare To Constant'
 * '<S38>'  : 'E33_VCU_simulink/Input/Input/APPS/SCS_Wire_breakage_detection/Compare To Constant1'
 * '<S39>'  : 'E33_VCU_simulink/Input/Input/APPS/SCS_Wire_breakage_detection/Compare To Constant2'
 * '<S40>'  : 'E33_VCU_simulink/Input/Input/APPS/SCS_Wire_breakage_detection/Compare To Constant3'
 * '<S41>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze'
 * '<S42>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze1'
 * '<S43>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_INFO_Analyze'
 * '<S44>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_MAXT_Analyze'
 * '<S45>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/Compare To Constant'
 * '<S46>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/Compare To Constant1'
 * '<S47>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/Compare To Constant2'
 * '<S48>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/Compare To Constant3'
 * '<S49>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/Compare To Zero'
 * '<S50>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/Compare To Zero1'
 * '<S51>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/Compare To Zero2'
 * '<S52>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/Compare To Zero3'
 * '<S53>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem'
 * '<S54>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_AUX_FAIL_Sub'
 * '<S55>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_BATT_OC_Sub'
 * '<S56>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_BATT_OV_Sub'
 * '<S57>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_BATT_UC_Sub'
 * '<S58>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_BATT_UV_Sub'
 * '<S59>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_BMU_FAIL_Sub'
 * '<S60>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_BSU_FAULT_Sub'
 * '<S61>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_BSU_OFFLINE_Sub'
 * '<S62>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_CELL_DT_Sub'
 * '<S63>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_CELL_DV_Sub'
 * '<S64>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_CELL_LBK_Sub'
 * '<S65>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_CELL_OT_Sub'
 * '<S66>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_CELL_OV_Sub'
 * '<S67>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_CELL_TBK_Sub'
 * '<S68>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_CELL_UT_Sub'
 * '<S69>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_CELL_UV_Sub'
 * '<S70>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_CHRG_OCS_Sub'
 * '<S71>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_CHRG_OCT_Sub'
 * '<S72>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_DSCH_OCS_Sub'
 * '<S73>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_DSCH_OCT_Sub'
 * '<S74>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_HALL_BREAK_Sub'
 * '<S75>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_HVREL_FAIL_Sub'
 * '<S76>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_LEAK_OC_Sub'
 * '<S77>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_PRECHG_FAIL_Sub'
 * '<S78>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze/Enabled Subsystem/BMS_ALM_VCU_OFFLINE_Sub'
 * '<S79>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze1/BMS_HCU_MAXV'
 * '<S80>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze1/BMS_HCU_MAXV/MaxCellVoltNo_Sub'
 * '<S81>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze1/BMS_HCU_MAXV/MaxCellVolt_Sub'
 * '<S82>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze1/BMS_HCU_MAXV/MinCellVoltNo_Sub'
 * '<S83>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_ALM_Analyze1/BMS_HCU_MAXV/MinCellVolt_Sub'
 * '<S84>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_INFO_Analyze/Enabled Subsystem'
 * '<S85>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_INFO_Analyze/Enabled Subsystem/BatAlmLv_Sub'
 * '<S86>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_INFO_Analyze/Enabled Subsystem/BatCurrent_Sub'
 * '<S87>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_INFO_Analyze/Enabled Subsystem/BatLife_Sub'
 * '<S88>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_INFO_Analyze/Enabled Subsystem/BatSoc_Sub'
 * '<S89>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_INFO_Analyze/Enabled Subsystem/BatSoh_Sub'
 * '<S90>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_INFO_Analyze/Enabled Subsystem/BatState_Sub'
 * '<S91>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_INFO_Analyze/Enabled Subsystem/BatVoltage_Sub'
 * '<S92>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_MAXT_Analyze/Enabled Subsystem'
 * '<S93>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_MAXT_Analyze/Enabled Subsystem/CoolingCtl_Sub'
 * '<S94>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_MAXT_Analyze/Enabled Subsystem/HeatingCtl_Sub'
 * '<S95>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_MAXT_Analyze/Enabled Subsystem/MaxTempNo_Sub'
 * '<S96>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_MAXT_Analyze/Enabled Subsystem/MaxTemp_Sub'
 * '<S97>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_MAXT_Analyze/Enabled Subsystem/MinTempNo_Sub'
 * '<S98>'  : 'E33_VCU_simulink/Input/Input/BMS_CAN_Receive/BMS_MAXT_Analyze/Enabled Subsystem/MinTemp_Sub'
 * '<S99>'  : 'E33_VCU_simulink/Input/Input/Bpressure/SCS_Wire_breakage_detection'
 * '<S100>' : 'E33_VCU_simulink/Input/Input/Bpressure/SCS_Wire_breakage_detection/Compare To Constant'
 * '<S101>' : 'E33_VCU_simulink/Input/Input/Bpressure/SCS_Wire_breakage_detection/Compare To Constant1'
 * '<S102>' : 'E33_VCU_simulink/Input/Input/Bpressure/SCS_Wire_breakage_detection/Compare To Constant2'
 * '<S103>' : 'E33_VCU_simulink/Input/Input/Bpressure/SCS_Wire_breakage_detection/Compare To Constant3'
 * '<S104>' : 'E33_VCU_simulink/Input/Input/Keys/BoolFilter6'
 * '<S105>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/Compare To Constant1'
 * '<S106>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/Compare To Constant2'
 * '<S107>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/Compare To Zero'
 * '<S108>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/Compare To Zero1'
 * '<S109>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages'
 * '<S110>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages1'
 * '<S111>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat'
 * '<S112>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_AlmLv_Sub'
 * '<S113>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsBrakeMode_Sub'
 * '<S114>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsFreeMode_Sub'
 * '<S115>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsHvOvervoltage_Sub'
 * '<S116>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsHvUndervoltage_Sub'
 * '<S117>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsLvError_Sub'
 * '<S118>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsMcuNOTActive_Sub'
 * '<S119>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsMcuOvertemp_Sub'
 * '<S120>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsMotorOvertemp_Sub'
 * '<S121>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsOverCurr_Sub'
 * '<S122>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsPreChg_Sub'
 * '<S123>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsReady_Sub'
 * '<S124>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsRevoloverError_Sub'
 * '<S125>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsSelfcheckPass_Sub'
 * '<S126>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsSpdMode_Sub'
 * '<S127>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsTorqMode_Sub'
 * '<S128>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsUnderPowerLim_Sub'
 * '<S129>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_IsZeroLocMode_Sub'
 * '<S130>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_SPD_RPT_Sub'
 * '<S131>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages/MCU_Stat/MCU_TORQ_RPT_Sub'
 * '<S132>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages1/Enabled Subsystem'
 * '<S133>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages1/Enabled Subsystem/MCU_HvAcCurrRms_Sub'
 * '<S134>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages1/Enabled Subsystem/MCU_HvCurr_Sub'
 * '<S135>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages1/Enabled Subsystem/MCU_HvVolt_Sub'
 * '<S136>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages1/Enabled Subsystem/MCU_McuTemp_Sub'
 * '<S137>' : 'E33_VCU_simulink/Input/Input/MCU_CAN_Receive/ReceiveMessages1/Enabled Subsystem/MCU_MotorTemp_Sub'
 * '<S138>' : 'E33_VCU_simulink/Input/Input/Sensor/Filter1'
 * '<S139>' : 'E33_VCU_simulink/Input/Input/Sensor/Filter2'
 * '<S140>' : 'E33_VCU_simulink/Input/Input/Sensor/Filter3'
 * '<S141>' : 'E33_VCU_simulink/Input/Input/Sensor/Filter4'
 * '<S142>' : 'E33_VCU_simulink/Input/Input/Sensor/For Each Subsystem'
 * '<S143>' : 'E33_VCU_simulink/Input/Input/Sensor/For Each Subsystem/Filter5'
 * '<S144>' : 'E33_VCU_simulink/RapidECUSetting/BL'
 * '<S145>' : 'E33_VCU_simulink/RapidECUSetting/DAQ'
 * '<S146>' : 'E33_VCU_simulink/RapidECUSetting/Flash'
 * '<S147>' : 'E33_VCU_simulink/RapidECUSetting/PD'
 * '<S148>' : 'E33_VCU_simulink/RapidECUSetting/Polling'
 * '<S149>' : 'E33_VCU_simulink/RapidECUSetting/BL/Function-Call Subsystem'
 * '<S150>' : 'E33_VCU_simulink/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem'
 * '<S151>' : 'E33_VCU_simulink/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem/Com0'
 * '<S152>' : 'E33_VCU_simulink/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem/Com1'
 * '<S153>' : 'E33_VCU_simulink/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem/Com2'
 * '<S154>' : 'E33_VCU_simulink/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem/If Action Subsystem'
 * '<S155>' : 'E33_VCU_simulink/RapidECUSetting/BL/Function-Call Subsystem/Function-Call Subsystem/If Action Subsystem1'
 * '<S156>' : 'E33_VCU_simulink/RapidECUSetting/DAQ/daq100ms'
 * '<S157>' : 'E33_VCU_simulink/RapidECUSetting/DAQ/daq10ms'
 * '<S158>' : 'E33_VCU_simulink/RapidECUSetting/DAQ/daq50ms'
 * '<S159>' : 'E33_VCU_simulink/RapidECUSetting/DAQ/daq5ms'
 * '<S160>' : 'E33_VCU_simulink/RapidECUSetting/Flash/FlashOperation'
 * '<S161>' : 'E33_VCU_simulink/RapidECUSetting/PD/10mstask'
 * '<S162>' : 'E33_VCU_simulink/RapidECUSetting/Polling/CCPBackground'
 * '<S163>' : 'E33_VCU_simulink/RapidECUSetting/Polling/CCPReceive'
 * '<S164>' : 'E33_VCU_simulink/RapidECUSetting/Polling/CCPTransmit'
 * '<S165>' : 'E33_VCU_simulink/RapidECUSetting/Polling/CCPReceive/Nothing'
 * '<S166>' : 'E33_VCU_simulink/Subsystem1/DCDC_Ctrl'
 * '<S167>' : 'E33_VCU_simulink/Subsystem1/MCUctrl'
 * '<S168>' : 'E33_VCU_simulink/Subsystem1/PanelCtrl'
 * '<S169>' : 'E33_VCU_simulink/Subsystem1/TailLight'
 * '<S170>' : 'E33_VCU_simulink/Subsystem1/TmanageCtrl'
 * '<S171>' : 'E33_VCU_simulink/Subsystem1/VCUCAN'
 * '<S172>' : 'E33_VCU_simulink/Subsystem1/DCDC_Ctrl/Compare To Constant1'
 * '<S173>' : 'E33_VCU_simulink/Subsystem1/DCDC_Ctrl/DCDC_Ctrl'
 * '<S174>' : 'E33_VCU_simulink/Subsystem1/MCUctrl/MCU_CMD_CAN_Tx'
 * '<S175>' : 'E33_VCU_simulink/Subsystem1/MCUctrl/VCU_MCU_CMD'
 * '<S176>' : 'E33_VCU_simulink/Subsystem1/MCUctrl/VCU_MCU_CMD/MCU_GEAR_CMD'
 * '<S177>' : 'E33_VCU_simulink/Subsystem1/MCUctrl/VCU_MCU_CMD/MCU_HV_Voltage'
 * '<S178>' : 'E33_VCU_simulink/Subsystem1/MCUctrl/VCU_MCU_CMD/MCU_IsBrakeMode'
 * '<S179>' : 'E33_VCU_simulink/Subsystem1/MCUctrl/VCU_MCU_CMD/MCU_IsFreeMode'
 * '<S180>' : 'E33_VCU_simulink/Subsystem1/MCUctrl/VCU_MCU_CMD/MCU_IsMcuNOTActive'
 * '<S181>' : 'E33_VCU_simulink/Subsystem1/MCUctrl/VCU_MCU_CMD/MCU_IsPosRelayAct'
 * '<S182>' : 'E33_VCU_simulink/Subsystem1/MCUctrl/VCU_MCU_CMD/MCU_IsSpdMode'
 * '<S183>' : 'E33_VCU_simulink/Subsystem1/MCUctrl/VCU_MCU_CMD/MCU_IsTorqMode'
 * '<S184>' : 'E33_VCU_simulink/Subsystem1/MCUctrl/VCU_MCU_CMD/MCU_IsZeroLocMode'
 * '<S185>' : 'E33_VCU_simulink/Subsystem1/MCUctrl/VCU_MCU_CMD/MCU_SPD_CMD'
 * '<S186>' : 'E33_VCU_simulink/Subsystem1/MCUctrl/VCU_MCU_CMD/MCU_TORQ_CMD'
 * '<S187>' : 'E33_VCU_simulink/Subsystem1/PanelCtrl/BMS_ALM'
 * '<S188>' : 'E33_VCU_simulink/Subsystem1/PanelCtrl/Compare To Constant'
 * '<S189>' : 'E33_VCU_simulink/Subsystem1/PanelCtrl/Compare To Constant1'
 * '<S190>' : 'E33_VCU_simulink/Subsystem1/PanelCtrl/IMD_ALM'
 * '<S191>' : 'E33_VCU_simulink/Subsystem1/PanelCtrl/Ready_SW'
 * '<S192>' : 'E33_VCU_simulink/Subsystem1/TailLight/Compare To Constant'
 * '<S193>' : 'E33_VCU_simulink/Subsystem1/TailLight/Compare To Constant1'
 * '<S194>' : 'E33_VCU_simulink/Subsystem1/TailLight/LED'
 * '<S195>' : 'E33_VCU_simulink/Subsystem1/TmanageCtrl/Accu_FAN'
 * '<S196>' : 'E33_VCU_simulink/Subsystem1/TmanageCtrl/Accu_FAN1'
 * '<S197>' : 'E33_VCU_simulink/Subsystem1/TmanageCtrl/Compare To Constant'
 * '<S198>' : 'E33_VCU_simulink/Subsystem1/TmanageCtrl/Compare To Constant1'
 * '<S199>' : 'E33_VCU_simulink/Subsystem1/TmanageCtrl/Compare To Constant2'
 * '<S200>' : 'E33_VCU_simulink/Subsystem1/TmanageCtrl/Compare To Constant4'
 * '<S201>' : 'E33_VCU_simulink/Subsystem1/TmanageCtrl/Compare To Constant7'
 * '<S202>' : 'E33_VCU_simulink/Subsystem1/TmanageCtrl/Pump'
 * '<S203>' : 'E33_VCU_simulink/Subsystem1/VCUCAN/VCU_Panel'
 * '<S204>' : 'E33_VCU_simulink/Subsystem1/VCUCAN/VCU_Panel/Linear_FL'
 * '<S205>' : 'E33_VCU_simulink/Subsystem1/VCUCAN/VCU_Panel/Linear_FR'
 * '<S206>' : 'E33_VCU_simulink/Subsystem1/VCUCAN/VCU_Panel/Linear_RL'
 * '<S207>' : 'E33_VCU_simulink/Subsystem1/VCUCAN/VCU_Panel/Linear_RR'
 * '<S208>' : 'E33_VCU_simulink/Subsystem1/VCUCAN/VCU_Panel/Wheel_Angle'
 */
#endif                                 /* RTW_HEADER_E33_VCU_simulink_h_ */

/* File trailer for ECUCoder generated file E33_VCU_simulink.h.
 *
 * [EOF]
 */
