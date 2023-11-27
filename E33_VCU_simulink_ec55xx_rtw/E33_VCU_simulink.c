/*
 * Code generated for Simulink model E33_VCU_simulink.
 *
 * FILE    : E33_VCU_simulink.c
 *
 * VERSION : 1.70
 *
 * DATE    : Sun Nov 26 16:56:11 2023
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "E33_VCU_simulink.h"
#include "E33_VCU_simulink_private.h"

/* #include "myinclude.h" */

/* Named constants for Chart: '<S6>/Chart' */
#define E33_VCU_simu_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define E33_VCU_simuli_IN_WaitForEngine ((uint8_T)6U)
#define E33_VCU_simulink_IN_Guard      ((uint8_T)1U)
#define E33_VCU_simulink_IN_Init       ((uint8_T)2U)
#define E33_VCU_simulink_IN_OFF        ((uint8_T)1U)
#define E33_VCU_simulink_IN_ON         ((uint8_T)2U)
#define E33_VCU_simulink_IN_Ready      ((uint8_T)3U)
#define E33_VCU_simulink_IN_Standby    ((uint8_T)4U)
#define E33_VCU_simulink_IN_Trans      ((uint8_T)5U)

/* Named constants for Chart: '<S169>/LED' */
#define E33_VCU_simulink_IN_Blink      ((uint8_T)1U)
#define E33_VCU_simulink_IN_BlinkOff   ((uint8_T)1U)
#define E33_VCU_simulink_IN_BlinkOn    ((uint8_T)2U)
#define E33_VCU_simulink_IN_LEDStat    ((uint8_T)1U)
#define E33_VCU_simulink_IN_LightTest  ((uint8_T)3U)
#define E33_VCU_simulink_IN_OFF_m      ((uint8_T)4U)
#define E33_VCU_simulink_IN_ON_n       ((uint8_T)5U)

/* Named constants for Chart: '<S168>/BMS_ALM' */
#define E33_VCU_simulink_IN_AlevelAlm  ((uint8_T)1U)
#define E33_VCU_simulink_IN_BlevelAlm  ((uint8_T)2U)
#define E33_VCU_simulink_IN_BlvBlinkON ((uint8_T)1U)
#define E33_VCU_simulink_IN_BlvBlinkOff ((uint8_T)2U)
#define E33_VCU_simulink_IN_Init_n     ((uint8_T)3U)
#define E33_VCU_simulink_IN_Test       ((uint8_T)5U)

/* Named constants for Chart: '<S168>/IMD_ALM' */
#define E33_VCU_simulink_IN_OFF_e      ((uint8_T)3U)
#define E33_VCU_simulink_IN_Test_l     ((uint8_T)4U)

/* Named constants for Chart: '<S168>/Ready_SW' */
#define E33_VCU_simulin_IN_BlinkOFFfast ((uint8_T)1U)
#define E33_VCU_simulin_IN_BlinkOFFslow ((uint8_T)1U)
#define E33_VCU_simulink_IN_BlinkONfast ((uint8_T)2U)
#define E33_VCU_simulink_IN_BlinkONslow ((uint8_T)2U)
#define E33_VCU_simulink_IN_FastBlink  ((uint8_T)2U)
#define E33_VCU_simulink_IN_Test_k     ((uint8_T)6U)

/* Named constants for Chart: '<S170>/Accu_FAN' */
#define E33_VCU_simul_IN_Ready_to_close ((uint8_T)3U)
#define E33_VCU_simulink_IN_Init_e     ((uint8_T)1U)
#define E33_VCU_simulink_IN_PumpTest   ((uint8_T)2U)
#define E33_VCU_simulink_IN_Run        ((uint8_T)4U)
#define E33_VCU_simulink_IN_Stand      ((uint8_T)5U)

/* Named constants for Chart: '<S170>/Accu_FAN1' */
#define E33_VCU_simulink_IN_Run_i      ((uint8_T)3U)

/* Named constants for Chart: '<S170>/Pump' */
#define E33_VCU_simulink_IN_OFF_d      ((uint8_T)2U)
#define E33_VCU_simulink_IN_ON_b       ((uint8_T)3U)
#define E33_VCU_simulink_IN_PumpTest_o ((uint8_T)4U)
#define E33_VCU_simulink_IN_Pump_MR    ((uint8_T)1U)

/* Named constants for Chart: '<S166>/DCDC_Ctrl' */
#define E33_VCU_simulink_IN_DCDC_MR    ((uint8_T)1U)

uint16 TLE6232DIA[12]= { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

float ecflashdataold[1024];
float ecflashdatanew[1024];

/* Exported block parameters */
real_T Beep_Time = 2.0;                /* Variable: Beep_Time
                                        * Referenced by: '<S6>/Constant'
                                        */
real_T Brk_luminance = 50.0;           /* Variable: Brk_luminance
                                        * Referenced by: '<S169>/Constant1'
                                        */
real_T FactoryTestEnable = 0.0;        /* Variable: FactoryTestEnable
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
real_T HardBrk_luminance = 150.0;      /* Variable: HardBrk_luminance
                                        * Referenced by: '<S169>/Constant2'
                                        */
real32_T Accu_FAN_threshold[2] = { 28.0F, 35.0F } ;/* Variable: Accu_FAN_threshold
                                                    * Referenced by: '<S170>/1-D Lookup Table1'
                                                    */

real32_T Pump_threshold = 30.0F;       /* Variable: Pump_threshold
                                        * Referenced by: '<S197>/Constant'
                                        */
uint32_T Accu_FAN_Test = 0U;           /* Variable: Accu_FAN_Test
                                        * Referenced by: '<S170>/Constant12'
                                        */
uint32_T Radiator_FAN_Test = 0U;       /* Variable: Radiator_FAN_Test
                                        * Referenced by: '<S170>/Constant14'
                                        */
uint32_T Tail_Light_Test = 0U;         /* Variable: Tail_Light_Test
                                        * Referenced by: '<S169>/Constant5'
                                        */
uint32_T APPS_threshold = 3276800U;    /* Variable: APPS_threshold
                                        * Referenced by: '<S10>/Constant'
                                        */
uint16_T APPS1_Voltage[2] = { 430U, 1279U } ;/* Variable: APPS1_Voltage
                                              * Referenced by: '<S24>/1-D Lookup Table'
                                              */

uint16_T APPS2_Voltage[2] = { 872U, 2568U } ;/* Variable: APPS2_Voltage
                                              * Referenced by: '<S24>/1-D Lookup Table1'
                                              */

uint16_T BP_F_Voltage[2] = { 510U, 2800U } ;/* Variable: BP_F_Voltage
                                             * Referenced by: '<S26>/1-D Lookup Table1'
                                             */

uint16_T BP_F_threshold = 10U;         /* Variable: BP_F_threshold
                                        * Referenced by: '<S11>/Constant'
                                        */
uint16_T BP_R_Voltage[2] = { 520U, 1200U } ;/* Variable: BP_R_Voltage
                                             * Referenced by: '<S26>/1-D Lookup Table'
                                             */

uint16_T MaxRPMchangePerSec = 20000U;  /* Variable: MaxRPMchangePerSec
                                        * Referenced by: '<S7>/MaxCmdStep1'
                                        */
uint16_T MaxTorqChangePerSec = 25000U; /* Variable: MaxTorqChangePerSec
                                        * Referenced by: '<S7>/MaxCmdStep2'
                                        */
uint16_T SCS_Error_5V = 4500U;         /* Variable: SCS_Error_5V
                                        * Referenced by:
                                        *   '<S37>/Constant'
                                        *   '<S39>/Constant'
                                        *   '<S100>/Constant'
                                        *   '<S102>/Constant'
                                        */
uint16_T SCS_Error_GND = 200U;         /* Variable: SCS_Error_GND
                                        * Referenced by:
                                        *   '<S38>/Constant'
                                        *   '<S40>/Constant'
                                        *   '<S101>/Constant'
                                        *   '<S103>/Constant'
                                        */
uint16_T linear_FL_Map[2] = { 0U, 24000U } ;/* Variable: linear_FL_Map
                                             * Referenced by: '<S30>/1-D Lookup Table4'
                                             */

uint16_T linear_FR_Map[2] = { 0U, 24000U } ;/* Variable: linear_FR_Map
                                             * Referenced by: '<S30>/1-D Lookup Table2'
                                             */

uint16_T linear_Map[2] = { 0U, 1000U } ;/* Variable: linear_Map
                                         * Referenced by:
                                         *   '<S30>/1-D Lookup Table1'
                                         *   '<S30>/1-D Lookup Table2'
                                         *   '<S30>/1-D Lookup Table3'
                                         *   '<S30>/1-D Lookup Table4'
                                         */

uint16_T linear_RL_Map[2] = { 0U, 24000U } ;/* Variable: linear_RL_Map
                                             * Referenced by: '<S30>/1-D Lookup Table3'
                                             */

uint16_T linear_RR_Map[2] = { 0U, 24000U } ;/* Variable: linear_RR_Map
                                             * Referenced by: '<S30>/1-D Lookup Table1'
                                             */

boolean_T BMSLedTest = 0;              /* Variable: BMSLedTest
                                        * Referenced by: '<S168>/Constant9'
                                        */
boolean_T BeeperTest = 0;              /* Variable: BeeperTest
                                        * Referenced by: '<S168>/Constant7'
                                        */
boolean_T DCDC_Relay_Test = 0;         /* Variable: DCDC_Relay_Test
                                        * Referenced by: '<S166>/Constant5'
                                        */
boolean_T IMDLedTest = 0;              /* Variable: IMDLedTest
                                        * Referenced by: '<S168>/Constant11'
                                        */
boolean_T Pump_Test = 0;               /* Variable: Pump_Test
                                        * Referenced by: '<S170>/Constant9'
                                        */
boolean_T R2D_Light_Test = 0;          /* Variable: R2D_Light_Test
                                        * Referenced by: '<S168>/Constant5'
                                        */

/* Exported data definition */

/* Definition for custom storage class: Default */
boolean_T APPS1_Disconnect;
uint16_T APPS1_PWR;
uint16_T APPS1_Pos;
uint16_T APPS1_Vol_In;
boolean_T APPS2_Disconnect;
uint16_T APPS2_PWR;
uint16_T APPS2_Pos;
uint16_T APPS2_Vol_In;
uint16_T APPSUn_dif;
boolean_T APPS_OK;
uint32_T APPS_Pos;
uint8_T APPS_Unreliable;
boolean_T A_level_Warn;
uint16_T Angle_Vol;
uint8_T BMSALMCnt;
uint8_T BMSInfoCnt;
uint8_T BMSMAXTCnt;
uint8_T BMSMXVCnt;
real32_T BMS_AlmLv;
real32_T BMS_Current;
boolean_T BMS_Online;
real32_T BMS_SoC;
real32_T BMS_Voltage;
boolean_T BP_F_Disconnect;
boolean_T BP_F_OK;
uint16_T BP_F_Pos;
uint16_T BP_F_Vol_In;
uint16_T BP_Lim_T;
uint16_T BP_PWR;
boolean_T BP_R_Disconnect;
uint16_T BP_R_Pos;
uint16_T BP_R_Vol_In;
boolean_T B_level_Warn;
boolean_T BadApp1Alm;
boolean_T BadApp2Alm;
boolean_T BadMcuAlm;
boolean_T Bad_APPAlm;
boolean_T BeeperStat;
boolean_T BmsLedStat;
boolean_T DCDC_MR;
boolean_T DCDC_ON;
uint16_T Dri_T_request;
uint16_T I_BAT;
uint16_T I_UBR;
boolean_T ImdLedStat;
uint8_T Infomation_OK;
uint16_T Linear_FL;
uint16_T Linear_FR;
uint16_T Linear_RL;
uint16_T Linear_RR;
boolean_T MCU_Cut;
real32_T MCU_HvVolt;
boolean_T MCU_Online;
boolean_T MCU_Ready;
real32_T MCU_SpdCmd;
real32_T MCU_TorqCmd;
real32_T MaxTemp;
real32_T Maxchange_Lim_T;
uint32_T McuInfoOfflineCnt;
uint32_T McuStatelineCnt;
uint16_T PWR_5V;
real32_T Pwr_Lim;
boolean_T R2D_Light;
boolean_T R2D_SW;
boolean_T ReadyLEDstat;
uint8_T State_OK;
uint8_T VCUMCUCANOKK;
boolean_T VehReady;
boolean_T VehStandby;
int32_T Wheel_Angle;

/* Block signals (auto storage) */
B_E33_VCU_simulink_T E33_VCU_simulink_B;

/* Block states (auto storage) */
DW_E33_VCU_simulink_T E33_VCU_simulink_DW;

/* Real-time model */
RT_MODEL_E33_VCU_simulink_T E33_VCU_simulink_M_;
RT_MODEL_E33_VCU_simulink_T *const E33_VCU_simulink_M = &E33_VCU_simulink_M_;

/* Forward declaration for local functions */
static real_T E33_VCU_simulink_GetDutyCyc(real_T elapsed_sec, real_T period);
static void E33_VCU_simulink_LEDStat(void);
static real_T E33_VCU_simulink_GetDutyCyc_n(real_T elapsed_sec, real_T period);
static void rate_monotonic_scheduler(void);

/* TLE6240 control function */
void ec_tle6232_diag(void)
{
  int i;
  uint16 RD_DIAG[1] = { 0x8000 };      //Read DIAG Register

  uint16 RD_DIAG_RX1[1] = { 0x0000 };  //Read DIAG Register--returned value, chip1

  uint16 RD_DIAG_RX2[1] = { 0x0000 };  //Read DIAG Register--returned value, chip2

  ec_spi_masterwriteread(0, 1, 1, RD_DIAG, RD_DIAG_RX1);
  i= 10;
  while (i--) {
    ;
  }

  for (i=0; i<6; i++) {
    TLE6232DIA[i] = ((RD_DIAG_RX1[0] & (0x0003<<(i*2))))>>(i*2);
  }

  ec_spi_masterwriteread(0, 2, 1, RD_DIAG, RD_DIAG_RX2);
  i= 10;
  while (i--) {
    ;
  }

  for (i=0; i<6; i++) {
    TLE6232DIA[i+6] = ((RD_DIAG_RX2[0] & (0x0003<<(i*2))))>>(i*2);
  }
}

void ISR_Rti_CH23(void)
{
  EMIOS.CH[23].CSR.B.FLAG = 0x1;       /* Clear interrupt flag */
  ECUCoderModelBaseCounter++;
  rate_monotonic_scheduler();
}

void ec_flash_operation(void)
{
  uint16 i = 0;
  uint16 counter = 0;
  uint8 returnCode1= 0;
  boolean_T kl15s = 1;
  AfterRunFlags[1] = 1;
  ec_gpio_write(118,1);
  kl15s = ec_gpio_read(119);
  if (0 == kl15s && AfterRunFlags[0] == 0) {
    i= 1000;
    while (i--) {
      ;
    }

    kl15s = ec_gpio_read(119);
    if (0 == kl15s && AfterRunFlags[0] == 0) {
      for (i=0; i<1024; i++) {
        if (ecflashdataold[i] != ecflashdatanew[i]) {
          counter++;
        }
      }

      if (counter > 0) {
        DisableInterrupts();
        returnCode1 = pFlashErase( &ssdConfig, FALSE, 0x00000000, 0x00000000,
          0x00000400, NULL_CALLBACK );
        if (returnCode1 != H7F_OK ) {
          while (1) {
            ;
          }
        }

        pFlashProgram( &ssdConfig, 0x1c0000, 4096, (uint32)ecflashdatanew,
                      NULL_CALLBACK );
        i= 1000;
        while (i--) {
          ;
        }
      }

      AfterRunFlags[1] = 0;
      ec_gpio_write(118,0);
      i= 60000;
      while (i--) {
        ;
      }
    }
  }
}

void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T outBitsLo;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Lo;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  in0Hi = in0 >> 16U;
  in0Lo = in0 & 65535U;
  in1Hi = in1 >> 16U;
  in1Lo = in1 & 65535U;
  productHiLo = in0Hi * in1Lo;
  productLoHi = in0Lo * in1Hi;
  in0Lo *= in1Lo;
  in1Lo = 0U;
  outBitsLo = (productLoHi << 16U) + in0Lo;
  if (outBitsLo < in0Lo) {
    in1Lo = 1U;
  }

  in0Lo = outBitsLo;
  outBitsLo += productHiLo << 16U;
  if (outBitsLo < in0Lo) {
    in1Lo++;
  }

  *ptrOutBitsHi = (((productLoHi >> 16U) + (productHiLo >> 16U)) + in0Hi * in1Hi)
    + in1Lo;
  *ptrOutBitsLo = outBitsLo;
}

uint32_T mul_u32_u32_u32_sr31(uint32_T a, uint32_T b)
{
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_u32(a, b, &u32_chi, &u32_clo);
  u32_clo = u32_chi << 1U | u32_clo >> 31U;
  return u32_clo;
}

uint32_T div_nzp_repeat_u32(uint32_T numerator, uint32_T denominator, uint32_T
  nRepeatSub)
{
  uint32_T quotient;
  uint32_T iRepeatSub;
  boolean_T numeratorExtraBit;
  quotient = numerator / denominator;
  numerator %= denominator;
  for (iRepeatSub = 0U; iRepeatSub < nRepeatSub; iRepeatSub++) {
    numeratorExtraBit = (numerator >= 2147483648U);
    numerator <<= 1U;
    quotient <<= 1U;
    if (numeratorExtraBit || (numerator >= denominator)) {
      quotient++;
      numerator -= denominator;
    }
  }

  return quotient;
}

uint32_T div_nzp_u32_near(uint32_T numerator, uint32_T denominator)
{
  uint32_T tempAbsQuotient;
  tempAbsQuotient = numerator / denominator;
  numerator %= denominator;
  if ((numerator > 2147483647U) || ((numerator << 1U) >= denominator)) {
    tempAbsQuotient++;
  }

  return tempAbsQuotient;
}

uint16_T look1_iu16lu32n16_binlcse(uint16_T u0, const uint16_T bp0[], const
  uint16_T table[], uint32_T maxIndex)
{
  uint16_T y;
  uint32_T frac;
  uint32_T iRght;
  uint32_T iLeft;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    frac = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[frac]) {
        iRght = frac;
      } else {
        iLeft = frac;
      }

      frac = (iRght + iLeft) >> 1U;
    }

    frac = ((uint32_T)(uint16_T)((uint32_T)u0 - bp0[iLeft]) << 16) / (uint16_T)
      ((uint32_T)bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 65536U;
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (table[iLeft + 1U] >= table[iLeft]) {
    y = (uint16_T)((uint32_T)(uint16_T)((uint16_T)((uint32_T)table[iLeft + 1U] -
      table[iLeft]) * frac >> 16) + table[iLeft]);
  } else {
    y = (uint16_T)((uint32_T)table[iLeft] - (uint16_T)((uint16_T)((uint32_T)
      table[iLeft] - table[iLeft + 1U]) * frac >> 16));
  }

  return y;
}

int32_T look1_iu16bs32lu32n31t_VYilYNox(uint16_T u0, const int32_T bp0[], const
  int32_T table[], uint32_T maxIndex)
{
  int32_T y;
  uint32_T frac;
  int32_T uCast;
  uint32_T iRght;
  uint32_T iLeft;

  /* Lookup 1-D
     Canonical function name: look1_iu16bs32lu32n31ts32Du32_binlcse
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  uCast = u0;
  if (u0 < bp0[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (uCast < bp0[maxIndex]) {
    /* Binary Search */
    frac = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (uCast < bp0[frac]) {
        iRght = frac;
      } else {
        iLeft = frac;
      }

      frac = (iRght + iLeft) >> 1U;
    }

    frac = div_nzp_repeat_u32((uint32_T)u0 - bp0[iLeft], (uint32_T)bp0[iLeft +
      1U] - bp0[iLeft], 31U);
  } else {
    iLeft = maxIndex - 1U;
    frac = 2147483648U;
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (table[iLeft + 1U] >= table[iLeft]) {
    y = (int32_T)mul_u32_u32_u32_sr31(frac, (uint32_T)table[iLeft + 1U] -
      table[iLeft]) + table[iLeft];
  } else {
    y = table[iLeft] - (int32_T)mul_u32_u32_u32_sr31(frac, (uint32_T)table[iLeft]
      - table[iLeft + 1U]);
  }

  return y;
}

uint16_T look1_iu16lu32n16_binlcne(uint16_T u0, const uint16_T bp0[], const
  uint16_T table[], uint32_T maxIndex)
{
  uint16_T y;
  uint32_T frac;
  uint32_T iRght;
  uint32_T iLeft;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'nearest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'nearest'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    frac = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[frac]) {
        iRght = frac;
      } else {
        iLeft = frac;
      }

      frac = (iRght + iLeft) >> 1U;
    }

    frac = div_nzp_u32_near((uint32_T)(uint16_T)((uint32_T)u0 - bp0[iLeft]) <<
      16, (uint16_T)((uint32_T)bp0[iLeft + 1U] - bp0[iLeft]));
  } else {
    iLeft = maxIndex - 1U;
    frac = 65536U;
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'nearest'
     Overflow mode: 'wrapping'
   */
  if (table[iLeft + 1U] >= table[iLeft]) {
    frac *= (uint16_T)((uint32_T)table[iLeft + 1U] - table[iLeft]);
    y = (uint16_T)((uint32_T)(uint16_T)(((frac & 32768U) != 0U) + (frac >> 16))
                   + table[iLeft]);
  } else {
    frac *= (uint16_T)((uint32_T)table[iLeft] - table[iLeft + 1U]);
    y = (uint16_T)((uint32_T)table[iLeft] - (uint16_T)(((frac & 32768U) != 0U) +
                    (frac >> 16)));
  }

  return y;
}

real32_T look1_ifbdtdIf_binlc(real32_T u0, const real_T bp0[], const real_T
  table[], uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 < bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < (real32_T)bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0;
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  return (real32_T)((table[iLeft + 1U] - table[iLeft]) * frac) + (real32_T)
    table[iLeft];
}

uint16_T look2_ifyu16td_binlc(real32_T u0, real32_T u1, const real32_T bp0[],
  const real32_T bp1[], const real_T table[], const uint32_T maxIndex[],
  uint32_T stride)
{
  real_T frac;
  uint32_T bpIndices[2];
  real_T fractions[2];
  real_T yL_1d;
  uint32_T iRght;
  uint32_T bpIdx;
  uint32_T iLeft;

  /* Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = 1.0;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = 1.0;
  }

  /* Interpolation 2-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_1d = (table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] + table[bpIdx];
  bpIdx += stride;
  return (uint16_T)((((table[bpIdx + 1U] - table[bpIdx]) * fractions[0U] +
                      table[bpIdx]) - yL_1d) * frac + yL_1d);
}

real32_T look1_iflf_binlc(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0F;
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

real32_T sMultiWord2Single(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real32_T y;
  int32_T i;
  int32_T exp_0;
  uint32_T u1i;
  uint32_T cb;
  y = 0.0F;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= (real32_T)ldexp((real32_T)cb, exp_0);
      cb = cb < u1i ? 1U : 0U;
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += (real32_T)ldexp((real32_T)u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;
  boolean_T isNegative1;
  boolean_T isNegative2;
  uint32_T cb1;
  uint32_T cb2;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative2 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = u1i < cb1 ? 1U : 0U;
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    cb2 = 1U;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = u1i < cb2 ? 1U : 0U;
      }

      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk += cb;
      cb = yk < cb ? 1U : 0U;
      u1i *= a0;
      yk += u1i;
      cb += yk < u1i ? 1U : 0U;
      u1i = w10 << 16U;
      yk += u1i;
      cb += yk < u1i ? 1U : 0U;
      u1i = w01 << 16U;
      yk += u1i;
      cb += yk < u1i ? 1U : 0U;
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = yk < cb ? 1U : 0U;
    }
  }
}

real32_T uMultiWordSingle(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real32_T y;
  int32_T i;
  int32_T exp_1;
  y = 0.0F;
  exp_1 = e1;
  for (i = 0; i < n1; i++) {
    y += (real32_T)ldexp((real32_T)u1[i], exp_1);
    exp_1 += 32;
  }

  return y;
}

void uMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk += cb;
      cb = yk < cb ? 1U : 0U;
      u1i *= a0;
      yk += u1i;
      cb += yk < u1i ? 1U : 0U;
      u1i = w10 << 16U;
      yk += u1i;
      cb += yk < u1i ? 1U : 0U;
      u1i = w01 << 16U;
      yk += u1i;
      cb += yk < u1i ? 1U : 0U;
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

uint32_T MultiWord2uLong(const uint32_T u[])
{
  return u[0];
}

void uMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T nb;
  int32_T i;
  uint32_T yi;
  uint32_T u1i;
  int32_T nc;
  uint32_T nr;
  uint32_T nl;
  int32_T i1;
  nb = (int32_T)(n2 >> 5);
  i = 0;
  if (nb < n1) {
    nc = n + nb;
    if (nc > n1) {
      nc = n1;
    }

    nr = n2 - ((uint32_T)nb << 5);
    if (nr > 0U) {
      nl = 32U - nr;
      u1i = u1[nb];
      for (i1 = nb + 1; i1 < nc; i1++) {
        yi = u1i >> nr;
        u1i = u1[i1];
        y[i] = u1i << nl | yi;
        i++;
      }

      yi = u1i >> nr;
      if (nc < n1) {
        yi |= u1[nc] << nl;
      }

      y[i] = yi;
      i++;
    } else {
      for (i1 = nb; i1 < nc; i1++) {
        y[i] = u1[i1];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = 0U;
    i++;
  }
}

void ISR_FlexCAN_2_MB1(void)
{
  /* Call the system: <S144>/Function-Call Subsystem */
  {
    /* Output and update for function-call system: '<S144>/Function-Call Subsystem' */

    /* S-Function (ec55xx_canreceiveslb): '<S149>/CANReceive1' */

    /* Receive CAN message */
    {
      uint8 CAN2BUF1RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

      uint8 can2buf1looprx= 0;
      E33_VCU_simulink_B.CANReceive1_o3= 278;
      E33_VCU_simulink_B.CANReceive1_o5= 8;
      E33_VCU_simulink_B.CANReceive1_o2= ec_can_receive(2,1, CAN2BUF1RX);
      E33_VCU_simulink_B.CANReceive1_o4[0]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      E33_VCU_simulink_B.CANReceive1_o4[1]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      E33_VCU_simulink_B.CANReceive1_o4[2]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      E33_VCU_simulink_B.CANReceive1_o4[3]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      E33_VCU_simulink_B.CANReceive1_o4[4]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      E33_VCU_simulink_B.CANReceive1_o4[5]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      E33_VCU_simulink_B.CANReceive1_o4[6]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
      E33_VCU_simulink_B.CANReceive1_o4[7]= CAN2BUF1RX[can2buf1looprx];
      can2buf1looprx++;
    }

    /* Call the system: <S149>/Function-Call Subsystem */

    /* Output and update for function-call system: '<S149>/Function-Call Subsystem' */

    /* If: '<S150>/If' incorporates:
     *  Constant: '<S151>/Constant'
     *  Constant: '<S152>/Constant'
     *  Constant: '<S153>/Constant'
     *  Constant: '<S155>/Constant'
     *  RelationalOperator: '<S151>/Compare'
     *  RelationalOperator: '<S152>/Compare'
     *  RelationalOperator: '<S153>/Compare'
     *  Sum: '<S150>/Add'
     */
    if (((int32_T)((uint32_T)(E33_VCU_simulink_B.CANReceive1_o4[0] == 83) +
                   (E33_VCU_simulink_B.CANReceive1_o4[5] == 84)) == 2) > 0) {
      /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem' incorporates:
       *  ActionPort: '<S154>/Action Port'
       */

      /* S-Function (ec55xx_bootloaderslb): '<S154>/BootLoader' */
      {
        uint16 i= 0;
        uint8 CAN2BUF9TX[]= { 11, 12, 12, 13 };

        uint8 returnCode1= 0;
        uint8 bootflag[]= { 1, 0, 0, 0, 0, 0, 0, 0 };

        DisableInterrupts();
        returnCode1 = pFlashErase( &ssdConfig, FALSE, 0x00000000, 0x00000000,
          0x00000800, NULL_CALLBACK );
        if (returnCode1 != H7F_OK ) {
          while (1) {
            ;
          }
        }

        pFlashProgram( &ssdConfig, 0x1ffff0, 8,(uint32)bootflag, NULL_CALLBACK );
        i= 1000;
        while (i--) {
          ;
        }

        ec_can_transmit(2, 9, 0, 593, 4, CAN2BUF9TX);
        i= 10000;
        while (i--) {
          ;
        }
      }

      /* S-Function (ec55xx_cpuresetslb): '<S154>/CPUReset' */

      /* Perform a microcontroller reset */
      ec_cpu_reset();

      /* End of Outputs for SubSystem: '<S150>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S155>/Action Port'
       */

      /* S-Function (ec55xx_cantransmitslb): '<S155>/CANTransmit' */

      /*Transmit CAN message*/
      {
        uint8 CAN2BUF9TX[1];
        uint8 can2buf9looptx= 0;
        CAN2BUF9TX[can2buf9looptx]= ((uint8_T)1U);
        can2buf9looptx++;
        E33_VCU_simulink_B.CANTransmit_h= ec_can_transmit(2, 9, 0, 593U, 1,
          CAN2BUF9TX);
      }

      /* End of Outputs for SubSystem: '<S150>/If Action Subsystem1' */
    }

    /* End of If: '<S150>/If' */
  }

  FLEXCAN(2).IFRL.B.BUF01I = 1;        /* Clear CAN interrupt flag by writing it to 1 */
}

void ISR_FlexCAN_2_MB0(void)
{
  /* Call the system: <S148>/CCPReceive */
  {
    /* Output and update for function-call system: '<S148>/CCPReceive' */

    /* S-Function (ec55xx_canreceiveslb): '<S163>/CANReceive' */

    /* Receive CAN message */
    {
      uint8 CAN2BUF0RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

      uint8 can2buf0looprx= 0;
      E33_VCU_simulink_B.CANReceive_o3= 256;
      E33_VCU_simulink_B.CANReceive_o5= 8;
      E33_VCU_simulink_B.CANReceive_o2= ec_can_receive(2,0, CAN2BUF0RX);
      E33_VCU_simulink_B.CANReceive_o4[0]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      E33_VCU_simulink_B.CANReceive_o4[1]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      E33_VCU_simulink_B.CANReceive_o4[2]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      E33_VCU_simulink_B.CANReceive_o4[3]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      E33_VCU_simulink_B.CANReceive_o4[4]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      E33_VCU_simulink_B.CANReceive_o4[5]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      E33_VCU_simulink_B.CANReceive_o4[6]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
      E33_VCU_simulink_B.CANReceive_o4[7]= CAN2BUF0RX[can2buf0looprx];
      can2buf0looprx++;
    }

    /* Nothing to do for system: <S163>/Nothing */
  }

  FLEXCAN(2).IFRL.B.BUF00I = 1;        /* Clear CAN interrupt flag by writing it to 1 */
}

void ISR_FlexCAN_2_MB8(void)
{
  /* Call the system: <S148>/CCPTransmit */
  {
    /* Output and update for function-call system: '<S148>/CCPTransmit' */

    /* S-Function (ec55xx_ccpslb2): '<S164>/CCPTXConfirmation' */
    ec_can_appltxconfirmation(FLEXCAN_C,8);
  }

  FLEXCAN(2).IFRL.B.BUF08I = 1;        /* Clear CAN interrupt flag by writing it to 1 */
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void E33_VCU_simulink_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(E33_VCU_simulink_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(E33_VCU_simulink_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(E33_VCU_simulink_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(E33_VCU_simulink_M, 4));
  eventFlags[5] = ((boolean_T)rtmStepTask(E33_VCU_simulink_M, 5));
  eventFlags[6] = ((boolean_T)rtmStepTask(E33_VCU_simulink_M, 6));
  eventFlags[7] = ((boolean_T)rtmStepTask(E33_VCU_simulink_M, 7));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 3 shares data with slower tid rates: 4, 5, 6 */
  if (E33_VCU_simulink_M->Timing.TaskCounters.TID[3] == 0) {
    E33_VCU_simulink_M->Timing.RateInteraction.TID3_4 =
      (E33_VCU_simulink_M->Timing.TaskCounters.TID[4] == 0);
    E33_VCU_simulink_M->Timing.RateInteraction.TID3_5 =
      (E33_VCU_simulink_M->Timing.TaskCounters.TID[5] == 0);
    E33_VCU_simulink_M->Timing.RateInteraction.TID3_6 =
      (E33_VCU_simulink_M->Timing.TaskCounters.TID[6] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (E33_VCU_simulink_M->Timing.TaskCounters.TID[1])++;
  if ((E33_VCU_simulink_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.001s, 0.0s] */
    E33_VCU_simulink_M->Timing.TaskCounters.TID[1] = 0;
  }

  (E33_VCU_simulink_M->Timing.TaskCounters.TID[2])++;
  if ((E33_VCU_simulink_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.005s, 0.0s] */
    E33_VCU_simulink_M->Timing.TaskCounters.TID[2] = 0;
  }

  (E33_VCU_simulink_M->Timing.TaskCounters.TID[3])++;
  if ((E33_VCU_simulink_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.01s, 0.0s] */
    E33_VCU_simulink_M->Timing.TaskCounters.TID[3] = 0;
  }

  (E33_VCU_simulink_M->Timing.TaskCounters.TID[4])++;
  if ((E33_VCU_simulink_M->Timing.TaskCounters.TID[4]) > 39) {/* Sample time: [0.02s, 0.0s] */
    E33_VCU_simulink_M->Timing.TaskCounters.TID[4] = 0;
  }

  (E33_VCU_simulink_M->Timing.TaskCounters.TID[5])++;
  if ((E33_VCU_simulink_M->Timing.TaskCounters.TID[5]) > 99) {/* Sample time: [0.05s, 0.0s] */
    E33_VCU_simulink_M->Timing.TaskCounters.TID[5] = 0;
  }

  (E33_VCU_simulink_M->Timing.TaskCounters.TID[6])++;
  if ((E33_VCU_simulink_M->Timing.TaskCounters.TID[6]) > 199) {/* Sample time: [0.1s, 0.0s] */
    E33_VCU_simulink_M->Timing.TaskCounters.TID[6] = 0;
  }

  (E33_VCU_simulink_M->Timing.TaskCounters.TID[7])++;
  if ((E33_VCU_simulink_M->Timing.TaskCounters.TID[7]) > 999) {/* Sample time: [0.5s, 0.0s] */
    E33_VCU_simulink_M->Timing.TaskCounters.TID[7] = 0;
  }
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for Chart: '<S169>/LED' */
static real_T E33_VCU_simulink_GetDutyCyc(real_T elapsed_sec, real_T period)
{
  real_T DutyCyc;

  /* MATLAB Function 'GetDutyCyc': '<S194>:9' */
  /* '<S194>:9:2' */
  DutyCyc = sin((elapsed_sec / period + 0.75) * 6.2831853071795862) * 25.0 +
    25.0;

  /* Note: sin in rad */
  return DutyCyc;
}

/* Function for Chart: '<S168>/Ready_SW' */
static void E33_VCU_simulink_LEDStat(void)
{
  /* During 'LEDStat': '<S191>:50' */
  switch (E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m) {
   case E33_VCU_simulink_IN_Blink:
    /* During 'Blink': '<S191>:37' */
    if (E33_VCU_simulink_B.DataTypeConversion1 ||
        (!E33_VCU_simulink_B.VehStandby_n)) {
      /* Transition: '<S191>:80' */
      /* Transition: '<S191>:60' */
      /* Transition: '<S191>:62' */
      /* Transition: '<S191>:71' */
      if (E33_VCU_simulink_B.VehStandby_n) {
        /* Transition: '<S191>:69' */
        /* Exit Internal 'Blink': '<S191>:37' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m = E33_VCU_simulink_IN_Blink;

        /* Entry Internal 'Blink': '<S191>:37' */
        /* Transition: '<S191>:39' */
        E33_VCU_simulink_DW.bitsForTID5.is_Blink =
          E33_VCU_simulink_IN_BlinkONslow;
        E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;

        /* Entry 'BlinkONslow': '<S191>:49' */
        R2D_Light = true;
      } else {
        /* Transition: '<S191>:55' */
        if (E33_VCU_simulink_B.DataTypeConversion1) {
          /* Transition: '<S191>:94' */
          /* Exit Internal 'Blink': '<S191>:37' */
          E33_VCU_simulink_DW.bitsForTID5.is_Blink =
            E33_VCU_simu_IN_NO_ACTIVE_CHILD;
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m =
            E33_VCU_simulink_IN_FastBlink;

          /* Entry Internal 'FastBlink': '<S191>:92' */
          /* Transition: '<S191>:90' */
          E33_VCU_simulink_DW.bitsForTID5.is_FastBlink =
            E33_VCU_simulink_IN_BlinkONfast;
          E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;

          /* Entry 'BlinkONfast': '<S191>:87' */
          R2D_Light = true;
        } else {
          /* Transition: '<S191>:95' */
          if (E33_VCU_simulink_B.VehReady_e) {
            /* Transition: '<S191>:56' */
            /* Exit Internal 'Blink': '<S191>:37' */
            E33_VCU_simulink_DW.bitsForTID5.is_Blink =
              E33_VCU_simu_IN_NO_ACTIVE_CHILD;
            E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m =
              E33_VCU_simulink_IN_ON_n;

            /* Entry 'ON': '<S191>:43' */
            R2D_Light = true;
          } else {
            /* Transition: '<S191>:64' */
            /* Transition: '<S191>:76' */
            /* Exit Internal 'Blink': '<S191>:37' */
            E33_VCU_simulink_DW.bitsForTID5.is_Blink =
              E33_VCU_simu_IN_NO_ACTIVE_CHILD;
            E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m =
              E33_VCU_simulink_IN_OFF_m;

            /* Entry 'OFF': '<S191>:44' */
            R2D_Light = false;
          }
        }
      }
    } else if (E33_VCU_simulink_DW.bitsForTID5.is_Blink ==
               E33_VCU_simulin_IN_BlinkOFFslow) {
      /* During 'BlinkOFFslow': '<S191>:38' */
      if (E33_VCU_simulink_DW.temporalCounter_i1_be >= 20U) {
        /* Transition: '<S191>:40' */
        E33_VCU_simulink_DW.bitsForTID5.is_Blink =
          E33_VCU_simulink_IN_BlinkONslow;
        E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;

        /* Entry 'BlinkONslow': '<S191>:49' */
        R2D_Light = true;
      }
    } else {
      /* During 'BlinkONslow': '<S191>:49' */
      if (E33_VCU_simulink_DW.temporalCounter_i1_be >= 20U) {
        /* Transition: '<S191>:53' */
        E33_VCU_simulink_DW.bitsForTID5.is_Blink =
          E33_VCU_simulin_IN_BlinkOFFslow;
        E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;

        /* Entry 'BlinkOFFslow': '<S191>:38' */
        R2D_Light = false;
      }
    }
    break;

   case E33_VCU_simulink_IN_FastBlink:
    /* During 'FastBlink': '<S191>:92' */
    if (!E33_VCU_simulink_B.DataTypeConversion1) {
      /* Transition: '<S191>:98' */
      /* Transition: '<S191>:97' */
      /* Transition: '<S191>:60' */
      /* Transition: '<S191>:62' */
      /* Transition: '<S191>:71' */
      if (E33_VCU_simulink_B.VehStandby_n) {
        /* Transition: '<S191>:69' */
        /* Exit Internal 'FastBlink': '<S191>:92' */
        E33_VCU_simulink_DW.bitsForTID5.is_FastBlink =
          E33_VCU_simu_IN_NO_ACTIVE_CHILD;
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m = E33_VCU_simulink_IN_Blink;

        /* Entry Internal 'Blink': '<S191>:37' */
        /* Transition: '<S191>:39' */
        E33_VCU_simulink_DW.bitsForTID5.is_Blink =
          E33_VCU_simulink_IN_BlinkONslow;
        E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;

        /* Entry 'BlinkONslow': '<S191>:49' */
        R2D_Light = true;
      } else {
        /* Transition: '<S191>:55' */
        if (E33_VCU_simulink_B.DataTypeConversion1) {
          /* Transition: '<S191>:94' */
          /* Exit Internal 'FastBlink': '<S191>:92' */
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m =
            E33_VCU_simulink_IN_FastBlink;

          /* Entry Internal 'FastBlink': '<S191>:92' */
          /* Transition: '<S191>:90' */
          E33_VCU_simulink_DW.bitsForTID5.is_FastBlink =
            E33_VCU_simulink_IN_BlinkONfast;
          E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;

          /* Entry 'BlinkONfast': '<S191>:87' */
          R2D_Light = true;
        } else {
          /* Transition: '<S191>:95' */
          if (E33_VCU_simulink_B.VehReady_e) {
            /* Transition: '<S191>:56' */
            /* Exit Internal 'FastBlink': '<S191>:92' */
            E33_VCU_simulink_DW.bitsForTID5.is_FastBlink =
              E33_VCU_simu_IN_NO_ACTIVE_CHILD;
            E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m =
              E33_VCU_simulink_IN_ON_n;

            /* Entry 'ON': '<S191>:43' */
            R2D_Light = true;
          } else {
            /* Transition: '<S191>:64' */
            /* Transition: '<S191>:76' */
            /* Exit Internal 'FastBlink': '<S191>:92' */
            E33_VCU_simulink_DW.bitsForTID5.is_FastBlink =
              E33_VCU_simu_IN_NO_ACTIVE_CHILD;
            E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m =
              E33_VCU_simulink_IN_OFF_m;

            /* Entry 'OFF': '<S191>:44' */
            R2D_Light = false;
          }
        }
      }
    } else if (E33_VCU_simulink_DW.bitsForTID5.is_FastBlink ==
               E33_VCU_simulin_IN_BlinkOFFfast) {
      /* During 'BlinkOFFfast': '<S191>:88' */
      if (E33_VCU_simulink_DW.temporalCounter_i1_be >= 4U) {
        /* Transition: '<S191>:89' */
        E33_VCU_simulink_DW.bitsForTID5.is_FastBlink =
          E33_VCU_simulink_IN_BlinkONfast;
        E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;

        /* Entry 'BlinkONfast': '<S191>:87' */
        R2D_Light = true;
      }
    } else {
      /* During 'BlinkONfast': '<S191>:87' */
      if (E33_VCU_simulink_DW.temporalCounter_i1_be >= 4U) {
        /* Transition: '<S191>:91' */
        E33_VCU_simulink_DW.bitsForTID5.is_FastBlink =
          E33_VCU_simulin_IN_BlinkOFFfast;
        E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;

        /* Entry 'BlinkOFFfast': '<S191>:88' */
        R2D_Light = false;
      }
    }
    break;

   case E33_VCU_simulink_IN_Init_n:
    /* During 'Init': '<S191>:41' */
    if (E33_VCU_simulink_DW.temporalCounter_i1_be >= 20U) {
      /* Transition: '<S191>:63' */
      E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m = E33_VCU_simulink_IN_Test_k;
      E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;

      /* Entry 'Test': '<S191>:42' */
      R2D_Light = true;
    } else {
      R2D_Light = false;
    }
    break;

   case E33_VCU_simulink_IN_OFF_m:
    /* During 'OFF': '<S191>:44' */
    /* Transition: '<S191>:77' */
    /* Transition: '<S191>:75' */
    /* Transition: '<S191>:68' */
    /* Transition: '<S191>:97' */
    /* Transition: '<S191>:60' */
    /* Transition: '<S191>:62' */
    /* Transition: '<S191>:71' */
    if (E33_VCU_simulink_B.VehStandby_n) {
      /* Transition: '<S191>:69' */
      E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m = E33_VCU_simulink_IN_Blink;

      /* Entry Internal 'Blink': '<S191>:37' */
      /* Transition: '<S191>:39' */
      E33_VCU_simulink_DW.bitsForTID5.is_Blink = E33_VCU_simulink_IN_BlinkONslow;
      E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;

      /* Entry 'BlinkONslow': '<S191>:49' */
      R2D_Light = true;
    } else {
      /* Transition: '<S191>:55' */
      if (E33_VCU_simulink_B.DataTypeConversion1) {
        /* Transition: '<S191>:94' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m =
          E33_VCU_simulink_IN_FastBlink;

        /* Entry Internal 'FastBlink': '<S191>:92' */
        /* Transition: '<S191>:90' */
        E33_VCU_simulink_DW.bitsForTID5.is_FastBlink =
          E33_VCU_simulink_IN_BlinkONfast;
        E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;

        /* Entry 'BlinkONfast': '<S191>:87' */
        R2D_Light = true;
      } else {
        /* Transition: '<S191>:95' */
        if (E33_VCU_simulink_B.VehReady_e) {
          /* Transition: '<S191>:56' */
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m =
            E33_VCU_simulink_IN_ON_n;

          /* Entry 'ON': '<S191>:43' */
          R2D_Light = true;
        } else {
          /* Transition: '<S191>:64' */
          /* Transition: '<S191>:76' */
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m =
            E33_VCU_simulink_IN_OFF_m;

          /* Entry 'OFF': '<S191>:44' */
          R2D_Light = false;
        }
      }
    }
    break;

   case E33_VCU_simulink_IN_ON_n:
    /* During 'ON': '<S191>:43' */
    /* Transition: '<S191>:57' */
    /* Transition: '<S191>:68' */
    /* Transition: '<S191>:97' */
    /* Transition: '<S191>:60' */
    /* Transition: '<S191>:62' */
    /* Transition: '<S191>:71' */
    if (E33_VCU_simulink_B.VehStandby_n) {
      /* Transition: '<S191>:69' */
      E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m = E33_VCU_simulink_IN_Blink;

      /* Entry Internal 'Blink': '<S191>:37' */
      /* Transition: '<S191>:39' */
      E33_VCU_simulink_DW.bitsForTID5.is_Blink = E33_VCU_simulink_IN_BlinkONslow;
      E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;

      /* Entry 'BlinkONslow': '<S191>:49' */
      R2D_Light = true;
    } else {
      /* Transition: '<S191>:55' */
      if (E33_VCU_simulink_B.DataTypeConversion1) {
        /* Transition: '<S191>:94' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m =
          E33_VCU_simulink_IN_FastBlink;

        /* Entry Internal 'FastBlink': '<S191>:92' */
        /* Transition: '<S191>:90' */
        E33_VCU_simulink_DW.bitsForTID5.is_FastBlink =
          E33_VCU_simulink_IN_BlinkONfast;
        E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;

        /* Entry 'BlinkONfast': '<S191>:87' */
        R2D_Light = true;
      } else {
        /* Transition: '<S191>:95' */
        if (E33_VCU_simulink_B.VehReady_e) {
          /* Transition: '<S191>:56' */
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m =
            E33_VCU_simulink_IN_ON_n;

          /* Entry 'ON': '<S191>:43' */
          R2D_Light = true;
        } else {
          /* Transition: '<S191>:64' */
          /* Transition: '<S191>:76' */
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m =
            E33_VCU_simulink_IN_OFF_m;

          /* Entry 'OFF': '<S191>:44' */
          R2D_Light = false;
        }
      }
    }
    break;

   default:
    /* During 'Test': '<S191>:42' */
    if (E33_VCU_simulink_DW.temporalCounter_i1_be >= 60U) {
      /* Transition: '<S191>:61' */
      R2D_Light = false;
      if (E33_VCU_simulink_B.VehStandby_n) {
        /* Transition: '<S191>:69' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m = E33_VCU_simulink_IN_Blink;

        /* Entry Internal 'Blink': '<S191>:37' */
        /* Transition: '<S191>:39' */
        E33_VCU_simulink_DW.bitsForTID5.is_Blink =
          E33_VCU_simulink_IN_BlinkONslow;
        E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;

        /* Entry 'BlinkONslow': '<S191>:49' */
        R2D_Light = true;
      } else {
        /* Transition: '<S191>:55' */
        if (E33_VCU_simulink_B.DataTypeConversion1) {
          /* Transition: '<S191>:94' */
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m =
            E33_VCU_simulink_IN_FastBlink;

          /* Entry Internal 'FastBlink': '<S191>:92' */
          /* Transition: '<S191>:90' */
          E33_VCU_simulink_DW.bitsForTID5.is_FastBlink =
            E33_VCU_simulink_IN_BlinkONfast;
          E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;

          /* Entry 'BlinkONfast': '<S191>:87' */
          R2D_Light = true;
        } else {
          /* Transition: '<S191>:95' */
          if (E33_VCU_simulink_B.VehReady_e) {
            /* Transition: '<S191>:56' */
            E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m =
              E33_VCU_simulink_IN_ON_n;

            /* Entry 'ON': '<S191>:43' */
            R2D_Light = true;
          } else {
            /* Transition: '<S191>:64' */
            /* Transition: '<S191>:76' */
            E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m =
              E33_VCU_simulink_IN_OFF_m;

            /* Entry 'OFF': '<S191>:44' */
            R2D_Light = false;
          }
        }
      }
    }
    break;
  }
}

/* Function for Chart: '<S170>/Accu_FAN1' */
static real_T E33_VCU_simulink_GetDutyCyc_n(real_T elapsed_sec, real_T period)
{
  real_T DutyCyc;

  /* MATLAB Function 'GetDutyCyc': '<S196>:9' */
  /* '<S196>:9:2' */
  DutyCyc = sin((elapsed_sec / period + 0.75) * 6.2831853071795862) * 25.0 +
    25.0;

  /* Note: sin in rad */
  return DutyCyc;
}

/* Model step function for TID0 */
void E33_VCU_simulink_step0(void)      /* Sample time: [0.0005s, 0.0s] */
{
  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void E33_VCU_simulink_step1(void)      /* Sample time: [0.001s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S148>/Function-Call Generator' incorporates:
   *  SubSystem: '<S148>/CCPBackground'
   */

  /* S-Function (ec55xx_ccpslb): '<S162>/CCPBackground' */
  ccpBackground();
}

/* Model step function for TID2 */
void E33_VCU_simulink_step2(void)      /* Sample time: [0.005s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S145>/5ms' incorporates:
   *  SubSystem: '<S145>/daq5ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S159>/CCPDAQ' */
  ccpDaq(0);
}

/* Model step function for TID3 */
void E33_VCU_simulink_step3(void)      /* Sample time: [0.01s, 0.0s] */
{
  uint16_T minV;
  uint8_T rtb_Compare_dq;
  uint8_T rtb_Compare_c;
  uint16_T rtb_SumofElements;
  uint16_T rtb_MinMax_j;
  real32_T rtb_Saturation2;
  real_T elapseTime;
  real32_T rtb_Switch2;
  real32_T rtb_UkYk1;
  int64m_T tmp;
  uint32_T tmp_0;
  uint32_T tmp_1;
  uint64m_T tmp_2;

  /* S-Function (fcncallgen): '<S23>/10ms4' incorporates:
   *  SubSystem: '<S23>/MCU_CAN_Receive'
   */

  /* S-Function (ec55xx_canreceiveslb): '<S28>/CANReceive' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF1RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf1looprx= 0;
    E33_VCU_simulink_B.CANReceive_o3_i= 218089199;
    E33_VCU_simulink_B.CANReceive_o5_h= 8;
    Infomation_OK= ec_can_receive(0,1, CAN0BUF1RX);
    E33_VCU_simulink_B.CANReceive_o4_l[0]= CAN0BUF1RX[can0buf1looprx];
    can0buf1looprx++;
    E33_VCU_simulink_B.CANReceive_o4_l[1]= CAN0BUF1RX[can0buf1looprx];
    can0buf1looprx++;
    E33_VCU_simulink_B.CANReceive_o4_l[2]= CAN0BUF1RX[can0buf1looprx];
    can0buf1looprx++;
    E33_VCU_simulink_B.CANReceive_o4_l[3]= CAN0BUF1RX[can0buf1looprx];
    can0buf1looprx++;
    E33_VCU_simulink_B.CANReceive_o4_l[4]= CAN0BUF1RX[can0buf1looprx];
    can0buf1looprx++;
    E33_VCU_simulink_B.CANReceive_o4_l[5]= CAN0BUF1RX[can0buf1looprx];
    can0buf1looprx++;
    E33_VCU_simulink_B.CANReceive_o4_l[6]= CAN0BUF1RX[can0buf1looprx];
    can0buf1looprx++;
    E33_VCU_simulink_B.CANReceive_o4_l[7]= CAN0BUF1RX[can0buf1looprx];
    can0buf1looprx++;
  }

  /* Call the system: <S28>/ReceiveMessages */

  /* Output and update for function-call system: '<S28>/ReceiveMessages' */
  {
    real32_T u0;

    /* Outputs for Enabled SubSystem: '<S109>/MCU_Stat' incorporates:
     *  EnablePort: '<S111>/Enable'
     */
    if (Infomation_OK > 0) {
      /* Saturate: '<S111>/MCU_IsReady_sat' incorporates:
       *  DataTypeConversion: '<S111>/MCU_IsReady_Convert'
       *  DataTypeConversion: '<S111>/MCU_IsReadycv'
       *  S-Function (sfix_bitop): '<S111>/MCU_IsReady_L'
       */
      E33_VCU_simulink_B.MCU_IsReady_sat = (real32_T)
        (E33_VCU_simulink_B.CANReceive_o4_l[5] & 1);

      /* Sum: '<S111>/MCU_SPD_RPT_Ad' incorporates:
       *  Constant: '<S111>/MCU_SPD_RPT_O'
       *  Constant: '<S111>/MCU_SPD_RPTinput2_C'
       *  Gain: '<S111>/MCU_SPD_RPT_F'
       *  Product: '<S111>/MCU_SPD_RPTinput2_P'
       *  Sum: '<S111>/MCU_SPD_RPTinput2_Ad'
       */
      u0 = (real32_T)((E33_VCU_simulink_B.CANReceive_o4_l[1] << 8) +
                      E33_VCU_simulink_B.CANReceive_o4_l[0]) * 0.5F + -10000.0F;

      /* Saturate: '<S111>/MCU_SPD_RPT_sat' */
      if (u0 > 10000.0F) {
        E33_VCU_simulink_B.MCU_SPD_RPT_sat = 10000.0F;
      } else {
        E33_VCU_simulink_B.MCU_SPD_RPT_sat = u0;
      }

      /* End of Saturate: '<S111>/MCU_SPD_RPT_sat' */
    }

    /* End of Outputs for SubSystem: '<S109>/MCU_Stat' */
  }

  /* S-Function (ec55xx_canreceiveslb): '<S28>/CANReceive1' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF2RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf2looprx= 0;
    E33_VCU_simulink_B.CANReceive1_o3_f= 218089455;
    E33_VCU_simulink_B.CANReceive1_o5_a= 8;
    State_OK= ec_can_receive(0,2, CAN0BUF2RX);
    E33_VCU_simulink_B.CANReceive1_o4_c[0]= CAN0BUF2RX[can0buf2looprx];
    can0buf2looprx++;
    E33_VCU_simulink_B.CANReceive1_o4_c[1]= CAN0BUF2RX[can0buf2looprx];
    can0buf2looprx++;
    E33_VCU_simulink_B.CANReceive1_o4_c[2]= CAN0BUF2RX[can0buf2looprx];
    can0buf2looprx++;
    E33_VCU_simulink_B.CANReceive1_o4_c[3]= CAN0BUF2RX[can0buf2looprx];
    can0buf2looprx++;
    E33_VCU_simulink_B.CANReceive1_o4_c[4]= CAN0BUF2RX[can0buf2looprx];
    can0buf2looprx++;
    E33_VCU_simulink_B.CANReceive1_o4_c[5]= CAN0BUF2RX[can0buf2looprx];
    can0buf2looprx++;
    E33_VCU_simulink_B.CANReceive1_o4_c[6]= CAN0BUF2RX[can0buf2looprx];
    can0buf2looprx++;
    E33_VCU_simulink_B.CANReceive1_o4_c[7]= CAN0BUF2RX[can0buf2looprx];
    can0buf2looprx++;
  }

  /* Call the system: <S28>/ReceiveMessages1 */

  /* Output and update for function-call system: '<S28>/ReceiveMessages1' */
  {
    real32_T u0;

    /* Outputs for Enabled SubSystem: '<S110>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S132>/Enable'
     */
    if (State_OK > 0) {
      /* Sum: '<S132>/MCU_HvCurr_Ad' incorporates:
       *  Constant: '<S132>/MCU_HvCurr_O'
       *  Constant: '<S132>/MCU_HvCurrinput6_C'
       *  Gain: '<S132>/MCU_HvCurr_F'
       *  Product: '<S132>/MCU_HvCurrinput6_P'
       *  Sum: '<S132>/MCU_HvCurrinput6_Ad'
       */
      u0 = (real32_T)((E33_VCU_simulink_B.CANReceive1_o4_c[5] << 8) +
                      E33_VCU_simulink_B.CANReceive1_o4_c[4]) * 0.1F + -1600.0F;

      /* Saturate: '<S132>/MCU_HvCurr_sat' */
      if (u0 > 1600.0F) {
        E33_VCU_simulink_B.MCU_HvCurr_sat = 1600.0F;
      } else {
        E33_VCU_simulink_B.MCU_HvCurr_sat = u0;
      }

      /* End of Saturate: '<S132>/MCU_HvCurr_sat' */

      /* Gain: '<S132>/MCU_HvVolt_F' incorporates:
       *  Constant: '<S132>/MCU_HvVoltinput4_C'
       *  Product: '<S132>/MCU_HvVoltinput4_P'
       *  Sum: '<S132>/MCU_HvVoltinput4_Ad'
       */
      u0 = (real32_T)((E33_VCU_simulink_B.CANReceive1_o4_c[3] << 8) +
                      E33_VCU_simulink_B.CANReceive1_o4_c[2]) * 0.1F;

      /* Saturate: '<S132>/MCU_HvVolt_sat' */
      if (u0 > 1000.0F) {
        MCU_HvVolt = 1000.0F;
      } else {
        MCU_HvVolt = u0;
      }

      /* End of Saturate: '<S132>/MCU_HvVolt_sat' */

      /* Saturate: '<S132>/MCU_McuTemp_sat' incorporates:
       *  Constant: '<S132>/MCU_McuTemp_O'
       *  DataTypeConversion: '<S132>/MCU_McuTemp_Convert'
       *  DataTypeConversion: '<S132>/MCU_McuTempcv'
       *  Sum: '<S132>/MCU_McuTemp_Ad'
       */
      E33_VCU_simulink_B.MCU_McuTemp_sat = (real32_T)
        E33_VCU_simulink_B.CANReceive1_o4_c[0] + -50.0F;

      /* Saturate: '<S132>/MCU_MotorTemp_sat' incorporates:
       *  Constant: '<S132>/MCU_MotorTemp_O'
       *  DataTypeConversion: '<S132>/MCU_MotorTemp_Convert'
       *  DataTypeConversion: '<S132>/MCU_MotorTempcv'
       *  Sum: '<S132>/MCU_MotorTemp_Ad'
       */
      E33_VCU_simulink_B.MCU_MotorTemp_sat = (real32_T)
        E33_VCU_simulink_B.CANReceive1_o4_c[1] + -50.0F;
    }

    /* End of Outputs for SubSystem: '<S110>/Enabled Subsystem' */
  }

  /* RelationalOperator: '<S107>/Compare' incorporates:
   *  Constant: '<S107>/Constant'
   */
  E33_VCU_simulink_B.Compare = (Infomation_OK != 0);

  /* S-Function (sdspcount2): '<S28>/Counter1' incorporates:
   *  UnitDelay: '<S28>/Unit Delay1'
   */
  if (E33_VCU_simulink_B.Compare) {
    E33_VCU_simulink_DW.Counter1_Count = 0U;
  }

  if (E33_VCU_simulink_DW.UnitDelay1_DSTATE != 0) {
    E33_VCU_simulink_DW.Counter1_Count++;
  }

  McuInfoOfflineCnt = E33_VCU_simulink_DW.Counter1_Count;

  /* End of S-Function (sdspcount2): '<S28>/Counter1' */

  /* RelationalOperator: '<S105>/Compare' incorporates:
   *  Constant: '<S105>/Constant'
   */
  rtb_Compare_dq = (uint8_T)(McuInfoOfflineCnt <= 10U);

  /* RelationalOperator: '<S108>/Compare' incorporates:
   *  Constant: '<S108>/Constant'
   */
  E33_VCU_simulink_B.Compare_m = (State_OK != 0);

  /* S-Function (sdspcount2): '<S28>/Counter2' incorporates:
   *  UnitDelay: '<S28>/Unit Delay2'
   */
  if (E33_VCU_simulink_B.Compare_m) {
    E33_VCU_simulink_DW.Counter2_Count = 0U;
  }

  if (E33_VCU_simulink_DW.UnitDelay2_DSTATE != 0) {
    E33_VCU_simulink_DW.Counter2_Count++;
  }

  McuStatelineCnt = E33_VCU_simulink_DW.Counter2_Count;

  /* End of S-Function (sdspcount2): '<S28>/Counter2' */

  /* RelationalOperator: '<S106>/Compare' incorporates:
   *  Constant: '<S106>/Constant'
   */
  rtb_Compare_c = (uint8_T)(McuStatelineCnt <= 10U);

  /* Logic: '<S28>/Logical Operator1' */
  MCU_Online = ((rtb_Compare_dq != 0) && (rtb_Compare_c != 0));

  /* Update for UnitDelay: '<S28>/Unit Delay1' */
  E33_VCU_simulink_DW.UnitDelay1_DSTATE = rtb_Compare_dq;

  /* Update for UnitDelay: '<S28>/Unit Delay2' */
  E33_VCU_simulink_DW.UnitDelay2_DSTATE = rtb_Compare_c;

  /* RateTransition: '<Root>/Rate Transition' */
  if (E33_VCU_simulink_M->Timing.RateInteraction.TID3_6) {
    E33_VCU_simulink_B.MaxTemp_i = E33_VCU_simulink_DW.RateTransition_53_Buffer0;

    /* RateTransition: '<Root>/Rate Transition' */
    E33_VCU_simulink_B.LEAK_OC = E33_VCU_simulink_DW.RateTransition_25_Buffer0;

    /* RateTransition: '<Root>/Rate Transition' */
    E33_VCU_simulink_B.BMS_Stat = E33_VCU_simulink_DW.RateTransition_18_Buffer0;

    /* RateTransition: '<Root>/Rate Transition' */
    E33_VCU_simulink_B.BMS_AlmLv_h =
      E33_VCU_simulink_DW.RateTransition_17_Buffer0;

    /* RateTransition: '<Root>/Rate Transition' */
    E33_VCU_simulink_B.BMS_Online_m =
      E33_VCU_simulink_DW.RateTransition_15_Buffer0;
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* S-Function (fcncallgen): '<S23>/10ms3' incorporates:
   *  SubSystem: '<S23>/Sensor'
   */
  /* MinMax: '<S140>/MinMax1' incorporates:
   *  S-Function (sfix_udelay): '<S140>/Tapped Delay'
   */
  if (E33_VCU_simulink_DW.TappedDelay_X[0] >= E33_VCU_simulink_DW.TappedDelay_X
      [1]) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X[0];
  } else {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X[1];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X[2])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X[2];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X[3])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X[3];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X[4])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X[4];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X[5])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X[5];
  }

  /* MinMax: '<S140>/MinMax' incorporates:
   *  S-Function (sfix_udelay): '<S140>/Tapped Delay'
   */
  if (E33_VCU_simulink_DW.TappedDelay_X[0] <= E33_VCU_simulink_DW.TappedDelay_X
      [1]) {
    minV = E33_VCU_simulink_DW.TappedDelay_X[0];
  } else {
    minV = E33_VCU_simulink_DW.TappedDelay_X[1];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X[2])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X[2];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X[3])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X[3];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X[4])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X[4];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X[5])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X[5];
  }

  /* Product: '<S140>/Divide' incorporates:
   *  MinMax: '<S140>/MinMax'
   *  MinMax: '<S140>/MinMax1'
   *  S-Function (sfix_udelay): '<S140>/Tapped Delay'
   *  Sum: '<S140>/Add'
   *  Sum: '<S140>/Sum of Elements'
   */
  rtb_MinMax_j = (uint16_T)((uint16_T)(((uint16_T)((((((uint32_T)
    E33_VCU_simulink_DW.TappedDelay_X[0] + E33_VCU_simulink_DW.TappedDelay_X[1])
    + E33_VCU_simulink_DW.TappedDelay_X[2]) + E33_VCU_simulink_DW.TappedDelay_X
    [3]) + E33_VCU_simulink_DW.TappedDelay_X[4]) +
    E33_VCU_simulink_DW.TappedDelay_X[5]) - rtb_MinMax_j) - minV) >> 2);

  /* Lookup_n-D: '<S30>/1-D Lookup Table1' */
  Linear_RR = look1_iu16lu32n16_binlcse(rtb_MinMax_j, linear_RR_Map, linear_Map,
    1U);

  /* S-Function (ec55xx_asislb): '<S30>/AnalogInput' */

  /* Read the ADC conversion result of the analog signal */
  E33_VCU_simulink_B.AnalogInput= ec_adc_readresult(17);

  /* MinMax: '<S138>/MinMax1' incorporates:
   *  S-Function (sfix_udelay): '<S138>/Tapped Delay'
   */
  if (E33_VCU_simulink_DW.TappedDelay_X_o[0] >=
      E33_VCU_simulink_DW.TappedDelay_X_o[1]) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_o[0];
  } else {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_o[1];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_o[2])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_o[2];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_o[3])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_o[3];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_o[4])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_o[4];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_o[5])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_o[5];
  }

  /* MinMax: '<S138>/MinMax' incorporates:
   *  S-Function (sfix_udelay): '<S138>/Tapped Delay'
   */
  if (E33_VCU_simulink_DW.TappedDelay_X_o[0] <=
      E33_VCU_simulink_DW.TappedDelay_X_o[1]) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_o[0];
  } else {
    minV = E33_VCU_simulink_DW.TappedDelay_X_o[1];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_o[2])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_o[2];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_o[3])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_o[3];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_o[4])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_o[4];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_o[5])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_o[5];
  }

  /* Product: '<S138>/Divide' incorporates:
   *  MinMax: '<S138>/MinMax'
   *  MinMax: '<S138>/MinMax1'
   *  S-Function (sfix_udelay): '<S138>/Tapped Delay'
   *  Sum: '<S138>/Add'
   *  Sum: '<S138>/Sum of Elements'
   */
  rtb_MinMax_j = (uint16_T)((uint16_T)(((uint16_T)((((((uint32_T)
    E33_VCU_simulink_DW.TappedDelay_X_o[0] +
    E33_VCU_simulink_DW.TappedDelay_X_o[1]) +
    E33_VCU_simulink_DW.TappedDelay_X_o[2]) +
    E33_VCU_simulink_DW.TappedDelay_X_o[3]) +
    E33_VCU_simulink_DW.TappedDelay_X_o[4]) +
    E33_VCU_simulink_DW.TappedDelay_X_o[5]) - rtb_MinMax_j) - minV) >> 2);

  /* Lookup_n-D: '<S30>/1-D Lookup Table2' */
  Linear_FR = look1_iu16lu32n16_binlcse(rtb_MinMax_j, linear_FR_Map, linear_Map,
    1U);

  /* S-Function (ec55xx_asislb): '<S30>/AnalogInput1' */

  /* Read the ADC conversion result of the analog signal */
  E33_VCU_simulink_B.AnalogInput1= ec_adc_readresult(27);

  /* MinMax: '<S139>/MinMax1' incorporates:
   *  S-Function (sfix_udelay): '<S139>/Tapped Delay'
   */
  if (E33_VCU_simulink_DW.TappedDelay_X_c[0] >=
      E33_VCU_simulink_DW.TappedDelay_X_c[1]) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_c[0];
  } else {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_c[1];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_c[2])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_c[2];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_c[3])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_c[3];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_c[4])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_c[4];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_c[5])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_c[5];
  }

  /* MinMax: '<S139>/MinMax' incorporates:
   *  S-Function (sfix_udelay): '<S139>/Tapped Delay'
   */
  if (E33_VCU_simulink_DW.TappedDelay_X_c[0] <=
      E33_VCU_simulink_DW.TappedDelay_X_c[1]) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_c[0];
  } else {
    minV = E33_VCU_simulink_DW.TappedDelay_X_c[1];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_c[2])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_c[2];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_c[3])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_c[3];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_c[4])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_c[4];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_c[5])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_c[5];
  }

  /* Product: '<S139>/Divide' incorporates:
   *  MinMax: '<S139>/MinMax'
   *  MinMax: '<S139>/MinMax1'
   *  S-Function (sfix_udelay): '<S139>/Tapped Delay'
   *  Sum: '<S139>/Add'
   *  Sum: '<S139>/Sum of Elements'
   */
  rtb_MinMax_j = (uint16_T)((uint16_T)(((uint16_T)((((((uint32_T)
    E33_VCU_simulink_DW.TappedDelay_X_c[0] +
    E33_VCU_simulink_DW.TappedDelay_X_c[1]) +
    E33_VCU_simulink_DW.TappedDelay_X_c[2]) +
    E33_VCU_simulink_DW.TappedDelay_X_c[3]) +
    E33_VCU_simulink_DW.TappedDelay_X_c[4]) +
    E33_VCU_simulink_DW.TappedDelay_X_c[5]) - rtb_MinMax_j) - minV) >> 2);

  /* Lookup_n-D: '<S30>/1-D Lookup Table3' */
  Linear_RL = look1_iu16lu32n16_binlcse(rtb_MinMax_j, linear_RL_Map, linear_Map,
    1U);

  /* S-Function (ec55xx_asislb): '<S30>/AnalogInput2' */

  /* Read the ADC conversion result of the analog signal */
  E33_VCU_simulink_B.AnalogInput2= ec_adc_readresult(5);

  /* MinMax: '<S141>/MinMax1' incorporates:
   *  S-Function (sfix_udelay): '<S141>/Tapped Delay'
   */
  if (E33_VCU_simulink_DW.TappedDelay_X_k[0] >=
      E33_VCU_simulink_DW.TappedDelay_X_k[1]) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_k[0];
  } else {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_k[1];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_k[2])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_k[2];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_k[3])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_k[3];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_k[4])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_k[4];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_k[5])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_k[5];
  }

  /* MinMax: '<S141>/MinMax' incorporates:
   *  S-Function (sfix_udelay): '<S141>/Tapped Delay'
   */
  if (E33_VCU_simulink_DW.TappedDelay_X_k[0] <=
      E33_VCU_simulink_DW.TappedDelay_X_k[1]) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_k[0];
  } else {
    minV = E33_VCU_simulink_DW.TappedDelay_X_k[1];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_k[2])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_k[2];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_k[3])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_k[3];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_k[4])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_k[4];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_k[5])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_k[5];
  }

  /* Product: '<S141>/Divide' incorporates:
   *  MinMax: '<S141>/MinMax'
   *  MinMax: '<S141>/MinMax1'
   *  S-Function (sfix_udelay): '<S141>/Tapped Delay'
   *  Sum: '<S141>/Add'
   *  Sum: '<S141>/Sum of Elements'
   */
  rtb_MinMax_j = (uint16_T)((uint16_T)(((uint16_T)((((((uint32_T)
    E33_VCU_simulink_DW.TappedDelay_X_k[0] +
    E33_VCU_simulink_DW.TappedDelay_X_k[1]) +
    E33_VCU_simulink_DW.TappedDelay_X_k[2]) +
    E33_VCU_simulink_DW.TappedDelay_X_k[3]) +
    E33_VCU_simulink_DW.TappedDelay_X_k[4]) +
    E33_VCU_simulink_DW.TappedDelay_X_k[5]) - rtb_MinMax_j) - minV) >> 2);

  /* Lookup_n-D: '<S30>/1-D Lookup Table4' */
  Linear_FL = look1_iu16lu32n16_binlcse(rtb_MinMax_j, linear_FL_Map, linear_Map,
    1U);

  /* S-Function (ec55xx_asislb): '<S30>/AnalogInput3' */

  /* Read the ADC conversion result of the analog signal */
  E33_VCU_simulink_B.AnalogInput3= ec_adc_readresult(4);

  /* S-Function (ec55xx_asislb): '<S30>/AnalogInput4' */

  /* Read the ADC conversion result of the analog signal */
  Angle_Vol= ec_adc_readresult(7);

  /* Lookup_n-D: '<S30>/1-D Lookup Table5' */
  Wheel_Angle = look1_iu16bs32lu32n31t_VYilYNox(Angle_Vol,
    E33_VCU_simulink_ConstP.DLookupTable5_bp01Dat,
    E33_VCU_simulink_ConstP.DLookupTable5_tableDa, 6U);

  /* Update for S-Function (sfix_udelay): '<S140>/Tapped Delay' */
  E33_VCU_simulink_DW.TappedDelay_X[0] = E33_VCU_simulink_DW.TappedDelay_X[1];
  E33_VCU_simulink_DW.TappedDelay_X[1] = E33_VCU_simulink_DW.TappedDelay_X[2];
  E33_VCU_simulink_DW.TappedDelay_X[2] = E33_VCU_simulink_DW.TappedDelay_X[3];
  E33_VCU_simulink_DW.TappedDelay_X[3] = E33_VCU_simulink_DW.TappedDelay_X[4];
  E33_VCU_simulink_DW.TappedDelay_X[4] = E33_VCU_simulink_DW.TappedDelay_X[5];
  E33_VCU_simulink_DW.TappedDelay_X[5] = E33_VCU_simulink_B.AnalogInput;

  /* Update for S-Function (sfix_udelay): '<S138>/Tapped Delay' */
  E33_VCU_simulink_DW.TappedDelay_X_o[0] = E33_VCU_simulink_DW.TappedDelay_X_o[1];
  E33_VCU_simulink_DW.TappedDelay_X_o[1] = E33_VCU_simulink_DW.TappedDelay_X_o[2];
  E33_VCU_simulink_DW.TappedDelay_X_o[2] = E33_VCU_simulink_DW.TappedDelay_X_o[3];
  E33_VCU_simulink_DW.TappedDelay_X_o[3] = E33_VCU_simulink_DW.TappedDelay_X_o[4];
  E33_VCU_simulink_DW.TappedDelay_X_o[4] = E33_VCU_simulink_DW.TappedDelay_X_o[5];
  E33_VCU_simulink_DW.TappedDelay_X_o[5] = E33_VCU_simulink_B.AnalogInput1;

  /* Update for S-Function (sfix_udelay): '<S139>/Tapped Delay' */
  E33_VCU_simulink_DW.TappedDelay_X_c[0] = E33_VCU_simulink_DW.TappedDelay_X_c[1];
  E33_VCU_simulink_DW.TappedDelay_X_c[1] = E33_VCU_simulink_DW.TappedDelay_X_c[2];
  E33_VCU_simulink_DW.TappedDelay_X_c[2] = E33_VCU_simulink_DW.TappedDelay_X_c[3];
  E33_VCU_simulink_DW.TappedDelay_X_c[3] = E33_VCU_simulink_DW.TappedDelay_X_c[4];
  E33_VCU_simulink_DW.TappedDelay_X_c[4] = E33_VCU_simulink_DW.TappedDelay_X_c[5];
  E33_VCU_simulink_DW.TappedDelay_X_c[5] = E33_VCU_simulink_B.AnalogInput2;

  /* Update for S-Function (sfix_udelay): '<S141>/Tapped Delay' */
  E33_VCU_simulink_DW.TappedDelay_X_k[0] = E33_VCU_simulink_DW.TappedDelay_X_k[1];
  E33_VCU_simulink_DW.TappedDelay_X_k[1] = E33_VCU_simulink_DW.TappedDelay_X_k[2];
  E33_VCU_simulink_DW.TappedDelay_X_k[2] = E33_VCU_simulink_DW.TappedDelay_X_k[3];
  E33_VCU_simulink_DW.TappedDelay_X_k[3] = E33_VCU_simulink_DW.TappedDelay_X_k[4];
  E33_VCU_simulink_DW.TappedDelay_X_k[4] = E33_VCU_simulink_DW.TappedDelay_X_k[5];
  E33_VCU_simulink_DW.TappedDelay_X_k[5] = E33_VCU_simulink_B.AnalogInput3;

  /* S-Function (fcncallgen): '<S23>/10ms2' incorporates:
   *  SubSystem: '<S23>/Keys'
   */

  /* S-Function (ec55xx_swislb): '<S27>/R2D_In' */

  /* Read the the value of the specified switch input */
  E33_VCU_simulink_B.R2D_In= ec_gpio_read(167);

  /* Logic: '<S27>/Logical Operator' */
  R2D_SW = !E33_VCU_simulink_B.R2D_In;

  /* S-Function (fcncallgen): '<S23>/10ms1' incorporates:
   *  SubSystem: '<S23>/Bpressure'
   */

  /* S-Function (ec55xx_asislb): '<S26>/BPressure_R' */

  /* Read the ADC conversion result of the analog signal */
  BP_R_Vol_In= ec_adc_readresult(14);

  /* Lookup_n-D: '<S26>/1-D Lookup Table' */
  BP_R_Pos = look1_iu16lu32n16_binlcse(BP_R_Vol_In, BP_R_Voltage,
    E33_VCU_simulink_ConstP.pooled32, 1U);

  /* S-Function (ec55xx_asislb): '<S26>/BPressure_F' */

  /* Read the ADC conversion result of the analog signal */
  BP_F_Vol_In= ec_adc_readresult(25);

  /* Lookup_n-D: '<S26>/1-D Lookup Table1' */
  BP_F_Pos = look1_iu16lu32n16_binlcse(BP_F_Vol_In, BP_F_Voltage,
    E33_VCU_simulink_ConstP.pooled32, 1U);

  /* Logic: '<S99>/Logical Operator' incorporates:
   *  Constant: '<S100>/Constant'
   *  Constant: '<S101>/Constant'
   *  RelationalOperator: '<S100>/Compare'
   *  RelationalOperator: '<S101>/Compare'
   */
  BP_F_Disconnect = ((BP_F_Vol_In >= SCS_Error_5V) || (BP_F_Vol_In <=
    SCS_Error_GND));

  /* Logic: '<S99>/Logical Operator1' incorporates:
   *  Constant: '<S102>/Constant'
   *  Constant: '<S103>/Constant'
   *  RelationalOperator: '<S102>/Compare'
   *  RelationalOperator: '<S103>/Compare'
   */
  BP_R_Disconnect = ((BP_R_Vol_In >= SCS_Error_5V) || (BP_R_Vol_In <=
    SCS_Error_GND));

  /* S-Function (fcncallgen): '<S23>/10ms' incorporates:
   *  SubSystem: '<S23>/APPS'
   */
  /* MinMax: '<S31>/MinMax1' incorporates:
   *  S-Function (sfix_udelay): '<S31>/Tapped Delay'
   */
  if (E33_VCU_simulink_DW.TappedDelay_X_a[0] >=
      E33_VCU_simulink_DW.TappedDelay_X_a[1]) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_a[0];
  } else {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_a[1];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_a[2])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_a[2];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_a[3])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_a[3];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_a[4])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_a[4];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_a[5])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_a[5];
  }

  /* MinMax: '<S31>/MinMax' incorporates:
   *  S-Function (sfix_udelay): '<S31>/Tapped Delay'
   */
  if (E33_VCU_simulink_DW.TappedDelay_X_a[0] <=
      E33_VCU_simulink_DW.TappedDelay_X_a[1]) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_a[0];
  } else {
    minV = E33_VCU_simulink_DW.TappedDelay_X_a[1];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_a[2])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_a[2];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_a[3])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_a[3];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_a[4])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_a[4];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_a[5])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_a[5];
  }

  /* Product: '<S31>/Divide' incorporates:
   *  MinMax: '<S31>/MinMax'
   *  MinMax: '<S31>/MinMax1'
   *  S-Function (sfix_udelay): '<S31>/Tapped Delay'
   *  Sum: '<S31>/Add'
   *  Sum: '<S31>/Sum of Elements'
   */
  rtb_SumofElements = (uint16_T)((uint16_T)(((uint16_T)((((((uint32_T)
    E33_VCU_simulink_DW.TappedDelay_X_a[0] +
    E33_VCU_simulink_DW.TappedDelay_X_a[1]) +
    E33_VCU_simulink_DW.TappedDelay_X_a[2]) +
    E33_VCU_simulink_DW.TappedDelay_X_a[3]) +
    E33_VCU_simulink_DW.TappedDelay_X_a[4]) +
    E33_VCU_simulink_DW.TappedDelay_X_a[5]) - rtb_MinMax_j) - minV) >> 2);

  /* Lookup_n-D: '<S24>/1-D Lookup Table' */
  APPS1_Pos = look1_iu16lu32n16_binlcne(rtb_SumofElements, APPS1_Voltage,
    E33_VCU_simulink_ConstP.pooled32, 1U);

  /* MinMax: '<S32>/MinMax1' incorporates:
   *  S-Function (sfix_udelay): '<S32>/Tapped Delay'
   */
  if (E33_VCU_simulink_DW.TappedDelay_X_h[0] >=
      E33_VCU_simulink_DW.TappedDelay_X_h[1]) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_h[0];
  } else {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_h[1];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_h[2])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_h[2];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_h[3])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_h[3];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_h[4])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_h[4];
  }

  if (!(rtb_MinMax_j >= E33_VCU_simulink_DW.TappedDelay_X_h[5])) {
    rtb_MinMax_j = E33_VCU_simulink_DW.TappedDelay_X_h[5];
  }

  /* MinMax: '<S32>/MinMax' incorporates:
   *  S-Function (sfix_udelay): '<S32>/Tapped Delay'
   */
  if (E33_VCU_simulink_DW.TappedDelay_X_h[0] <=
      E33_VCU_simulink_DW.TappedDelay_X_h[1]) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_h[0];
  } else {
    minV = E33_VCU_simulink_DW.TappedDelay_X_h[1];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_h[2])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_h[2];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_h[3])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_h[3];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_h[4])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_h[4];
  }

  if (!(minV <= E33_VCU_simulink_DW.TappedDelay_X_h[5])) {
    minV = E33_VCU_simulink_DW.TappedDelay_X_h[5];
  }

  /* Product: '<S32>/Divide' incorporates:
   *  MinMax: '<S32>/MinMax'
   *  MinMax: '<S32>/MinMax1'
   *  S-Function (sfix_udelay): '<S32>/Tapped Delay'
   *  Sum: '<S32>/Add'
   *  Sum: '<S32>/Sum of Elements'
   */
  rtb_MinMax_j = (uint16_T)((uint16_T)(((uint16_T)((((((uint32_T)
    E33_VCU_simulink_DW.TappedDelay_X_h[0] +
    E33_VCU_simulink_DW.TappedDelay_X_h[1]) +
    E33_VCU_simulink_DW.TappedDelay_X_h[2]) +
    E33_VCU_simulink_DW.TappedDelay_X_h[3]) +
    E33_VCU_simulink_DW.TappedDelay_X_h[4]) +
    E33_VCU_simulink_DW.TappedDelay_X_h[5]) - rtb_MinMax_j) - minV) >> 2);

  /* Lookup_n-D: '<S24>/1-D Lookup Table1' */
  APPS2_Pos = look1_iu16lu32n16_binlcne(rtb_MinMax_j, APPS2_Voltage,
    E33_VCU_simulink_ConstP.pooled32, 1U);

  /* S-Function (ec55xx_asislb): '<S24>/APPS1' */

  /* Read the ADC conversion result of the analog signal */
  APPS1_Vol_In= ec_adc_readresult(22);

  /* S-Function (ec55xx_asislb): '<S24>/APPS2' */

  /* Read the ADC conversion result of the analog signal */
  APPS2_Vol_In= ec_adc_readresult(3);

  /* Sum: '<S33>/Difference in pedal travel' incorporates:
   *  Constant: '<S33>/Constant'
   *  Sum: '<S33>/Sum'
   */
  APPSUn_dif = (uint16_T)((APPS1_Pos - APPS2_Pos) + 1000);

  /* RelationalOperator: '<S36>/Compare' incorporates:
   *  Constant: '<S36>/Constant'
   */
  APPS_Unreliable = (uint8_T)(APPSUn_dif >= 1100);

  /* Logic: '<S34>/Logical Operator' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S38>/Constant'
   *  RelationalOperator: '<S37>/Compare'
   *  RelationalOperator: '<S38>/Compare'
   */
  APPS1_Disconnect = ((rtb_SumofElements >= SCS_Error_5V) || (rtb_SumofElements <=
    SCS_Error_GND));

  /* Logic: '<S34>/Logical Operator1' incorporates:
   *  Constant: '<S39>/Constant'
   *  Constant: '<S40>/Constant'
   *  RelationalOperator: '<S39>/Compare'
   *  RelationalOperator: '<S40>/Compare'
   */
  APPS2_Disconnect = ((rtb_MinMax_j >= SCS_Error_5V) || (rtb_MinMax_j <=
    SCS_Error_GND));

  /* Gain: '<S35>/Gain' incorporates:
   *  Sum: '<S35>/Add'
   */
  APPS_Pos = (uint32_T)(uint16_T)((uint32_T)APPS1_Pos + (uint32_T)APPS2_Pos) <<
    15;

  /* Update for S-Function (sfix_udelay): '<S31>/Tapped Delay' */
  E33_VCU_simulink_DW.TappedDelay_X_a[0] = E33_VCU_simulink_DW.TappedDelay_X_a[1];
  E33_VCU_simulink_DW.TappedDelay_X_a[1] = E33_VCU_simulink_DW.TappedDelay_X_a[2];
  E33_VCU_simulink_DW.TappedDelay_X_a[2] = E33_VCU_simulink_DW.TappedDelay_X_a[3];
  E33_VCU_simulink_DW.TappedDelay_X_a[3] = E33_VCU_simulink_DW.TappedDelay_X_a[4];
  E33_VCU_simulink_DW.TappedDelay_X_a[4] = E33_VCU_simulink_DW.TappedDelay_X_a[5];
  E33_VCU_simulink_DW.TappedDelay_X_a[5] = APPS1_Vol_In;

  /* Update for S-Function (sfix_udelay): '<S32>/Tapped Delay' */
  E33_VCU_simulink_DW.TappedDelay_X_h[0] = E33_VCU_simulink_DW.TappedDelay_X_h[1];
  E33_VCU_simulink_DW.TappedDelay_X_h[1] = E33_VCU_simulink_DW.TappedDelay_X_h[2];
  E33_VCU_simulink_DW.TappedDelay_X_h[2] = E33_VCU_simulink_DW.TappedDelay_X_h[3];
  E33_VCU_simulink_DW.TappedDelay_X_h[3] = E33_VCU_simulink_DW.TappedDelay_X_h[4];
  E33_VCU_simulink_DW.TappedDelay_X_h[4] = E33_VCU_simulink_DW.TappedDelay_X_h[5];
  E33_VCU_simulink_DW.TappedDelay_X_h[5] = APPS2_Vol_In;

  /* S-Function (fcncallgen): '<Root>/10ms' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  if (E33_VCU_simulink_DW.FunctionCallSubsystem_RESET_ELA) {
    E33_VCU_simulink_DW.FunctionCallSubsystem_ELAPS_T = 0U;
  } else {
    E33_VCU_simulink_DW.FunctionCallSubsystem_ELAPS_T =
      E33_VCU_simulink_M->Timing.clockTick3 -
      E33_VCU_simulink_DW.FunctionCallSubsystem_PREV_T;
  }

  E33_VCU_simulink_DW.FunctionCallSubsystem_PREV_T =
    E33_VCU_simulink_M->Timing.clockTick3;
  E33_VCU_simulink_DW.FunctionCallSubsystem_RESET_ELA = false;

  /* DataTypeConversion: '<S6>/Data Type Conversion2' incorporates:
   *  Constant: '<S10>/Constant'
   *  RelationalOperator: '<S10>/Compare'
   */
  APPS_OK = (APPS_Pos <= APPS_threshold);

  /* DataTypeConversion: '<S6>/Data Type Conversion3' incorporates:
   *  Constant: '<S11>/Constant'
   *  RelationalOperator: '<S11>/Compare'
   */
  BP_F_OK = (BP_F_Pos >= BP_F_threshold);

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion1'
   */
  MCU_Ready = (MCU_Online && (E33_VCU_simulink_B.MCU_IsReady_sat != 0.0F));

  /* Chart: '<S6>/Chart' incorporates:
   *  Constant: '<S6>/Constant'
   */
  E33_VCU_simulink_DW.presentTicks_b = E33_VCU_simulink_M->Timing.clockTick3;
  E33_VCU_simulink_DW.elapsedTicks_h = E33_VCU_simulink_DW.presentTicks_b -
    E33_VCU_simulink_DW.previousTicks_ge;
  E33_VCU_simulink_DW.previousTicks_ge = E33_VCU_simulink_DW.presentTicks_b;
  E33_VCU_simulink_DW.temporalCounter_i1_hh +=
    E33_VCU_simulink_DW.elapsedTicks_h;

  /* Gateway: Function-Call
     Subsystem/R2D_State/Chart */
  /* During: Function-Call
     Subsystem/R2D_State/Chart */
  if (E33_VCU_simulink_DW.bitsForTID3.is_active_c3_E33_VCU_simulink == 0U) {
    /* Entry: Function-Call
       Subsystem/R2D_State/Chart */
    E33_VCU_simulink_DW.bitsForTID3.is_active_c3_E33_VCU_simulink = 1U;

    /* Entry Internal: Function-Call
       Subsystem/R2D_State/Chart */
    E33_VCU_simulink_DW.bitsForTID3.is_active_VehStat = 1U;

    /* Entry Internal 'VehStat': '<S9>:14' */
    /* Transition: '<S9>:17' */
    if (E33_VCU_simulink_DW.bitsForTID3.is_VehStat != E33_VCU_simulink_IN_Init)
    {
      E33_VCU_simulink_DW.bitsForTID3.is_VehStat = E33_VCU_simulink_IN_Init;
      E33_VCU_simulink_DW.temporalCounter_i1_hh = 0U;
    }

    E33_VCU_simulink_DW.bitsForTID3.is_active_BeeperStat = 1U;

    /* Entry Internal 'BeeperStat': '<S9>:73' */
    /* Transition: '<S9>:77' */
    E33_VCU_simulink_DW.bitsForTID3.is_BeeperStat = E33_VCU_simulink_IN_OFF;
    E33_VCU_simulink_DW.bitsForTID3.is_active_Output = 1U;
  } else {
    if (E33_VCU_simulink_DW.bitsForTID3.is_active_VehStat != 0U) {
      /* During 'VehStat': '<S9>:14' */
      switch (E33_VCU_simulink_DW.bitsForTID3.is_VehStat) {
       case E33_VCU_simulink_IN_Guard:
        /* During 'Guard': '<S9>:115' */
        if (E33_VCU_simulink_DW.temporalCounter_i1_hh >= 25U) {
          /* Transition: '<S9>:61' */
          if (E33_VCU_simulink_DW.bitsForTID3.is_active_BeeperStat != 0U) {
            /* During 'BeeperStat': '<S9>:73' */
            switch (E33_VCU_simulink_DW.bitsForTID3.is_BeeperStat) {
             case E33_VCU_simulink_IN_OFF:
              /* During 'OFF': '<S9>:74' */
              /* Transition: '<S9>:76' */
              E33_VCU_simulink_DW.bitsForTID3.is_BeeperStat =
                E33_VCU_simulink_IN_ON;
              break;

             case E33_VCU_simulink_IN_ON:
              /* During 'ON': '<S9>:75' */
              break;

             default:
              E33_VCU_simulink_DW.bitsForTID3.is_BeeperStat =
                E33_VCU_simu_IN_NO_ACTIVE_CHILD;
              break;
            }
          }

          E33_VCU_simulink_DW.bitsForTID3.is_VehStat = E33_VCU_simulink_IN_Trans;
          E33_VCU_simulink_DW.temporalCounter_i1_hh = 0U;
        } else if ((!R2D_SW) || (!BP_F_OK) || (!APPS_OK)) {
          /* Transition: '<S9>:116' */
          E33_VCU_simulink_DW.bitsForTID3.is_VehStat =
            E33_VCU_simulink_IN_Standby;
        } else {
          if (!MCU_Ready) {
            /* Transition: '<S9>:124' */
            E33_VCU_simulink_DW.bitsForTID3.is_VehStat =
              E33_VCU_simuli_IN_WaitForEngine;
          }
        }
        break;

       case E33_VCU_simulink_IN_Init:
        /* During 'Init': '<S9>:15' */
        if (E33_VCU_simulink_DW.temporalCounter_i1_hh >= 100U) {
          /* Transition: '<S9>:16' */
          E33_VCU_simulink_DW.bitsForTID3.is_VehStat =
            E33_VCU_simuli_IN_WaitForEngine;
        }
        break;

       case E33_VCU_simulink_IN_Ready:
        /* During 'Ready': '<S9>:53' */
        if (!MCU_Ready) {
          /* Transition: '<S9>:72' */
          E33_VCU_simulink_DW.bitsForTID3.is_VehStat =
            E33_VCU_simuli_IN_WaitForEngine;
        }
        break;

       case E33_VCU_simulink_IN_Standby:
        /* During 'Standby': '<S9>:119' */
        if (R2D_SW && BP_F_OK && APPS_OK) {
          /* Transition: '<S9>:9' */
          E33_VCU_simulink_DW.bitsForTID3.is_VehStat = E33_VCU_simulink_IN_Guard;
          E33_VCU_simulink_DW.temporalCounter_i1_hh = 0U;
        } else {
          if (!MCU_Ready) {
            /* Transition: '<S9>:122' */
            E33_VCU_simulink_DW.bitsForTID3.is_VehStat =
              E33_VCU_simuli_IN_WaitForEngine;
          }
        }
        break;

       case E33_VCU_simulink_IN_Trans:
        /* During 'Trans': '<S9>:117' */
        if (E33_VCU_simulink_DW.temporalCounter_i1_hh >= (uint32_T)ceil
            (Beep_Time / 0.01 - 1.0E-10)) {
          /* Transition: '<S9>:65' */
          if (E33_VCU_simulink_DW.bitsForTID3.is_active_BeeperStat != 0U) {
            /* During 'BeeperStat': '<S9>:73' */
            switch (E33_VCU_simulink_DW.bitsForTID3.is_BeeperStat) {
             case E33_VCU_simulink_IN_OFF:
              /* During 'OFF': '<S9>:74' */
              break;

             case E33_VCU_simulink_IN_ON:
              /* During 'ON': '<S9>:75' */
              /* Transition: '<S9>:78' */
              E33_VCU_simulink_DW.bitsForTID3.is_BeeperStat =
                E33_VCU_simulink_IN_OFF;
              break;

             default:
              E33_VCU_simulink_DW.bitsForTID3.is_BeeperStat =
                E33_VCU_simu_IN_NO_ACTIVE_CHILD;
              break;
            }
          }

          E33_VCU_simulink_DW.bitsForTID3.is_VehStat = E33_VCU_simulink_IN_Ready;
        }
        break;

       case E33_VCU_simuli_IN_WaitForEngine:
        /* During 'WaitForEngine': '<S9>:1' */
        if (MCU_Ready) {
          /* Transition: '<S9>:121' */
          E33_VCU_simulink_DW.bitsForTID3.is_VehStat =
            E33_VCU_simulink_IN_Standby;
        }
        break;

       default:
        E33_VCU_simulink_DW.bitsForTID3.is_VehStat =
          E33_VCU_simu_IN_NO_ACTIVE_CHILD;
        break;
      }
    }

    if (E33_VCU_simulink_DW.bitsForTID3.is_active_BeeperStat != 0U) {
      /* During 'BeeperStat': '<S9>:73' */
      switch (E33_VCU_simulink_DW.bitsForTID3.is_BeeperStat) {
       case E33_VCU_simulink_IN_OFF:
        /* During 'OFF': '<S9>:74' */
        break;

       case E33_VCU_simulink_IN_ON:
        /* During 'ON': '<S9>:75' */
        break;

       default:
        E33_VCU_simulink_DW.bitsForTID3.is_BeeperStat =
          E33_VCU_simu_IN_NO_ACTIVE_CHILD;
        break;
      }
    }

    if (E33_VCU_simulink_DW.bitsForTID3.is_active_Output != 0U) {
      /* During 'Output': '<S9>:52' */
      VehStandby = (E33_VCU_simulink_DW.bitsForTID3.is_VehStat ==
                    E33_VCU_simulink_IN_Standby);
      VehReady = (E33_VCU_simulink_DW.bitsForTID3.is_VehStat ==
                  E33_VCU_simulink_IN_Ready);
      E33_VCU_simulink_B.BeeperStOut =
        (E33_VCU_simulink_DW.bitsForTID3.is_BeeperStat == E33_VCU_simulink_IN_ON);
    }
  }

  /* End of Chart: '<S6>/Chart' */

  /* Logic: '<S7>/Logical Operator' incorporates:
   *  Logic: '<S7>/Logical Operator1'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  MCU_Cut = (E33_VCU_simulink_DW.UnitDelay_1_DSTATE ||
             (!E33_VCU_simulink_DW.UnitDelay_8_DSTATE));

  /* SampleTimeMath: '<S12>/sample time'
   *
   * About '<S12>/sample time':
   *  y = K where K = ( w * Ts )
   */
  elapseTime = (real_T)E33_VCU_simulink_DW.FunctionCallSubsystem_ELAPS_T * 0.01;

  /* Product: '<S12>/delta rise limit' incorporates:
   *  Constant: '<S7>/MaxCmdStep2'
   *  DataTypeConversion: '<S7>/Data Type Conversion4'
   *  SampleTimeMath: '<S12>/sample time'
   *
   * About '<S12>/sample time':
   *  y = K where K = ( w * Ts )
   */
  rtb_Switch2 = (real32_T)((real_T)MaxTorqChangePerSec * elapseTime);

  /* Lookup_n-D: '<S7>/PwrLimDerateCur' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion2'
   *  DotProduct: '<S7>/Dot Product'
   *  Gain: '<S7>/Gain1'
   */
  Pwr_Lim = look1_ifbdtdIf_binlc((real32_T)((real_T)(MCU_HvVolt *
    E33_VCU_simulink_B.MCU_HvCurr_sat) * 2.5E-5),
    E33_VCU_simulink_ConstP.PwrLimDerateCur_bp01D,
    E33_VCU_simulink_ConstP.PwrLimDerateCur_table, 2U);

  /* Lookup_n-D: '<S7>/PwrLimDerateCur1' */
  BP_Lim_T = look1_iu16lu32n16_binlcse(BP_F_Pos,
    E33_VCU_simulink_ConstP.pooled32,
    E33_VCU_simulink_ConstP.PwrLimDerateCur1_tabl, 1U);

  /* MinMax: '<S7>/MinMax' */
  if (Pwr_Lim <= (real32_T)BP_Lim_T) {
    rtb_Saturation2 = Pwr_Lim;
  } else {
    rtb_Saturation2 = (real32_T)BP_Lim_T;
  }

  /* Saturate: '<S7>/Saturation2' incorporates:
   *  MinMax: '<S7>/MinMax'
   */
  if (rtb_Saturation2 > 1000.0F) {
    rtb_Saturation2 = 1000.0F;
  } else {
    if (rtb_Saturation2 < 0.0F) {
      rtb_Saturation2 = 0.0F;
    }
  }

  /* End of Saturate: '<S7>/Saturation2' */

  /* Lookup_n-D: '<S7>/BasicTorqueCal' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion1'
   */
  Dri_T_request = look2_ifyu16td_binlc((real32_T)APPS_Pos * 1.52587891E-5F,
    E33_VCU_simulink_B.MCU_SPD_RPT_sat,
    E33_VCU_simulink_ConstP.BasicTorqueCal_bp01Da,
    E33_VCU_simulink_ConstP.BasicTorqueCal_bp02D,
    E33_VCU_simulink_ConstP.BasicTorqueCal_tabl,
    E33_VCU_simulink_ConstP.BasicTorqueCal_maxInd, 2U);

  /* Switch: '<S13>/Switch2' incorporates:
   *  RelationalOperator: '<S13>/LowerRelop1'
   *  Switch: '<S13>/Switch'
   */
  if ((real32_T)Dri_T_request > rtb_Saturation2) {
    rtb_MinMax_j = (uint16_T)rtb_Saturation2;
  } else {
    rtb_MinMax_j = Dri_T_request;
  }

  /* End of Switch: '<S13>/Switch2' */

  /* Sum: '<S12>/Difference Inputs1' incorporates:
   *  DataTypeConversion: '<S7>/Data Type Conversion3'
   *  UnitDelay: '<S12>/Delay Input2'
   */
  rtb_UkYk1 = (real32_T)rtb_MinMax_j - E33_VCU_simulink_DW.DelayInput2_DSTATE;

  /* Switch: '<S14>/Switch2' incorporates:
   *  RelationalOperator: '<S14>/LowerRelop1'
   */
  if (!(rtb_UkYk1 > rtb_Switch2)) {
    /* Gain: '<S7>/Gain' incorporates:
     *  Constant: '<S7>/MaxCmdStep2'
     *  DataTypeConversion: '<S7>/Data Type Conversion4'
     */
    tmp_0 = 2147483648U;
    tmp_1 = MaxTorqChangePerSec;
    sMultiWordMul(&tmp_0, 1, &tmp_1, 1, &tmp.chunks[0U], 2);

    /* Product: '<S12>/delta fall limit' incorporates:
     *  DataTypeConversion: '<S7>/Data Type Conversion7'
     *  SampleTimeMath: '<S12>/sample time'
     *
     * About '<S12>/sample time':
     *  y = K where K = ( w * Ts )
     */
    rtb_Saturation2 = (real32_T)(sMultiWord2Single(&tmp.chunks[0U], 2, 0) *
      4.65661287E-10F * elapseTime);

    /* Switch: '<S14>/Switch' incorporates:
     *  RelationalOperator: '<S14>/UpperRelop'
     */
    if (rtb_UkYk1 < rtb_Saturation2) {
      rtb_Switch2 = rtb_Saturation2;
    } else {
      rtb_Switch2 = rtb_UkYk1;
    }

    /* End of Switch: '<S14>/Switch' */
  }

  /* End of Switch: '<S14>/Switch2' */

  /* Sum: '<S12>/Difference Inputs2' incorporates:
   *  UnitDelay: '<S12>/Delay Input2'
   */
  Maxchange_Lim_T = rtb_Switch2 + E33_VCU_simulink_DW.DelayInput2_DSTATE;

  /* Switch: '<S7>/Switch2' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  if (MCU_Cut) {
    rtb_Switch2 = 0.0F;
  } else {
    rtb_Switch2 = Maxchange_Lim_T;
  }

  /* End of Switch: '<S7>/Switch2' */

  /* Saturate: '<S7>/Saturation' */
  if (rtb_Switch2 > 1000.0F) {
    MCU_TorqCmd = 1000.0F;
  } else if (rtb_Switch2 < 0.0F) {
    MCU_TorqCmd = 0.0F;
  } else {
    MCU_TorqCmd = rtb_Switch2;
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* SampleTimeMath: '<S7>/Weighted Sample Time' incorporates:
   *  Constant: '<S7>/MaxCmdStep1'
   *
   * About '<S7>/Weighted Sample Time':
   *  y = u * K where K = ( w * Ts )
   */
  tmp_0 = MaxRPMchangePerSec;
  uMultiWordMul(&tmp_0, 1, &E33_VCU_simulink_DW.FunctionCallSubsystem_ELAPS_T, 1,
                &tmp_2.chunks[0U], 2);

  /* Sum: '<S7>/Add4' */
  rtb_Switch2 = uMultiWordSingle(&tmp_2.chunks[0U], 2, 0) * 0.01F +
    E33_VCU_simulink_B.MCU_SPD_RPT_sat;

  /* Saturate: '<S7>/Saturation1' */
  if (rtb_Switch2 > 5400.0F) {
    MCU_SpdCmd = 5400.0F;
  } else if (rtb_Switch2 < -5400.0F) {
    MCU_SpdCmd = -5400.0F;
  } else {
    MCU_SpdCmd = rtb_Switch2;
  }

  /* End of Saturate: '<S7>/Saturation1' */

  /* RelationalOperator: '<S17>/Compare' incorporates:
   *  DataTypeConversion: '<S15>/Data Type Conversion'
   */
  Bad_APPAlm = (APPS_Unreliable != 0);

  /* RelationalOperator: '<S18>/Compare' */
  BadApp1Alm = APPS1_Disconnect;

  /* RelationalOperator: '<S19>/Compare' */
  BadApp2Alm = APPS2_Disconnect;

  /* RelationalOperator: '<S20>/Compare' incorporates:
   *  Constant: '<S20>/Constant'
   */
  BadMcuAlm = !MCU_Online;

  /* Logic: '<S15>/Logical Operator' */
  A_level_Warn = (BadMcuAlm || Bad_APPAlm || BadApp1Alm || BadApp2Alm);

  /* DataTypeConversion: '<S16>/Data Type Conversion1' */
  rtb_Switch2 = (real32_T)fabs(E33_VCU_simulink_B.BMS_AlmLv_h);
  if (rtb_Switch2 < 8.388608E+6F) {
    if (rtb_Switch2 >= 0.5F) {
      rtb_Switch2 = (real32_T)floor(E33_VCU_simulink_B.BMS_AlmLv_h + 0.5F);
    } else {
      rtb_Switch2 = E33_VCU_simulink_B.BMS_AlmLv_h * 0.0F;
    }
  } else {
    rtb_Switch2 = E33_VCU_simulink_B.BMS_AlmLv_h;
  }

  /* Logic: '<S16>/Logical Operator' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S22>/Constant'
   *  DataTypeConversion: '<S16>/Data Type Conversion1'
   *  RelationalOperator: '<S21>/Compare'
   *  RelationalOperator: '<S22>/Compare'
   */
  B_level_Warn = (((uint8_T)rtb_Switch2 != 0) ||
                  (!E33_VCU_simulink_B.BMS_Online_m));

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  E33_VCU_simulink_DW.UnitDelay_1_DSTATE = A_level_Warn;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  E33_VCU_simulink_DW.UnitDelay_8_DSTATE = VehReady;

  /* Update for UnitDelay: '<S12>/Delay Input2' */
  E33_VCU_simulink_DW.DelayInput2_DSTATE = Maxchange_Lim_T;

  /* RateTransition: '<S5>/Rate Transition1' incorporates:
   *  SignalConversion: '<S1>/Signal Conversion'
   */
  if (E33_VCU_simulink_M->Timing.RateInteraction.TID3_5) {
    /* S-Function (fcncallgen): '<Root>/10ms' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem'
     */
    E33_VCU_simulink_B.BMS_Stat_g = E33_VCU_simulink_B.BMS_Stat;

    /* RateTransition: '<S5>/Rate Transition1' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.BMS_Online_o = E33_VCU_simulink_B.BMS_Online_m;
  }

  /* End of RateTransition: '<S5>/Rate Transition1' */

  /* RateTransition: '<S5>/Rate Transition3' incorporates:
   *  SignalConversion: '<S1>/Signal Conversion'
   */
  if (E33_VCU_simulink_M->Timing.RateInteraction.TID3_4) {
    /* S-Function (fcncallgen): '<Root>/10ms' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem'
     */
    E33_VCU_simulink_B.MCU_Online_g = MCU_Online;

    /* RateTransition: '<S5>/Rate Transition3' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.MCU_SpdCmd_i = MCU_SpdCmd;

    /* RateTransition: '<S5>/Rate Transition3' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.MCU_TorqCmd_j = MCU_TorqCmd;

    /* RateTransition: '<S5>/Rate Transition3' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.MCU_Cut_o = MCU_Cut;
  }

  /* End of RateTransition: '<S5>/Rate Transition3' */

  /* RateTransition: '<S5>/Rate Transition2' incorporates:
   *  SignalConversion: '<S1>/Signal Conversion'
   */
  if (E33_VCU_simulink_M->Timing.RateInteraction.TID3_5) {
    /* S-Function (fcncallgen): '<Root>/10ms' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem'
     */
    E33_VCU_simulink_B.LEAK_OC_p = E33_VCU_simulink_B.LEAK_OC;

    /* RateTransition: '<S5>/Rate Transition2' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.BMS_AlmLv_c = E33_VCU_simulink_B.BMS_AlmLv_h;

    /* RateTransition: '<S5>/Rate Transition2' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.BMS_Online_n = E33_VCU_simulink_B.BMS_Online_m;

    /* RateTransition: '<S5>/Rate Transition2' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.APPS_Unreliable_g = APPS_Unreliable;

    /* RateTransition: '<S5>/Rate Transition2' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.VehReady_e = VehReady;

    /* RateTransition: '<S5>/Rate Transition2' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.VehStandby_n = VehStandby;

    /* RateTransition: '<S5>/Rate Transition2' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.BeeperOut = E33_VCU_simulink_B.BeeperStOut;
  }

  /* End of RateTransition: '<S5>/Rate Transition2' */

  /* RateTransition: '<S5>/Rate Transition4' incorporates:
   *  SignalConversion: '<S1>/Signal Conversion'
   */
  if (E33_VCU_simulink_M->Timing.RateInteraction.TID3_4) {
    /* S-Function (fcncallgen): '<Root>/10ms' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem'
     */
    E33_VCU_simulink_B.BP_F_Pos_l = BP_F_Pos;
  }

  /* End of RateTransition: '<S5>/Rate Transition4' */

  /* RateTransition: '<S5>/Rate Transition5' incorporates:
   *  SignalConversion: '<S1>/Signal Conversion'
   */
  if (E33_VCU_simulink_M->Timing.RateInteraction.TID3_5) {
    /* S-Function (fcncallgen): '<Root>/10ms' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem'
     */
    E33_VCU_simulink_B.MCU_McuTemp = E33_VCU_simulink_B.MCU_McuTemp_sat;

    /* RateTransition: '<S5>/Rate Transition5' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.MCU_MotorTemp = E33_VCU_simulink_B.MCU_MotorTemp_sat;

    /* RateTransition: '<S5>/Rate Transition5' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.MCU_IsReady = E33_VCU_simulink_B.MCU_IsReady_sat;

    /* RateTransition: '<S5>/Rate Transition5' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.MaxTemp_f = E33_VCU_simulink_B.MaxTemp_i;

    /* RateTransition: '<S5>/Rate Transition5' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.BMS_Stat_k = E33_VCU_simulink_B.BMS_Stat;

    /* RateTransition: '<S5>/Rate Transition5' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.BMS_Online_f = E33_VCU_simulink_B.BMS_Online_m;

    /* RateTransition: '<S5>/Rate Transition6' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.Wheel_Angle_a = Wheel_Angle;

    /* RateTransition: '<S5>/Rate Transition6' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.Linear_FL_d = Linear_FL;

    /* RateTransition: '<S5>/Rate Transition6' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.Linear_RL_a = Linear_RL;

    /* RateTransition: '<S5>/Rate Transition6' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.Linear_FR_p = Linear_FR;

    /* RateTransition: '<S5>/Rate Transition6' incorporates:
     *  SignalConversion: '<S1>/Signal Conversion'
     */
    E33_VCU_simulink_B.Linear_RR_k = Linear_RR;
  }

  /* End of RateTransition: '<S5>/Rate Transition5' */

  /* S-Function (fcncallgen): '<S145>/10ms' incorporates:
   *  SubSystem: '<S145>/daq10ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S157>/CCPDAQ' */
  ccpDaq(1);

  /* S-Function (fcncallgen): '<S147>/10ms' incorporates:
   *  SubSystem: '<S147>/10mstask'
   */

  /* S-Function (ec55xx_pdsdslb1): '<S161>/PDSD' */
  ec_tle6232_diag();

  /* Update absolute time */
  /* The "clockTick3" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick3" ensures timer will not overflow during the
   * application lifespan selected.
   */
  E33_VCU_simulink_M->Timing.clockTick3++;
}

/* Model step function for TID4 */
void E33_VCU_simulink_step4(void)      /* Sample time: [0.02s, 0.0s] */
{
  boolean_T rtb_Compare_c;
  boolean_T rtb_Compare_n;
  uint32_T tmp;
  real_T tmp_0;
  uint64m_T tmp_1;
  uint64m_T tmp_2;
  uint32_T tmp_3;
  real32_T u0;
  int32_T u0_0;

  /* S-Function (fcncallgen): '<S5>/20ms' incorporates:
   *  SubSystem: '<S5>/MCUctrl'
   */
  /* DataTypeConversion: '<S167>/Data Type Conversion11' */
  u0_0 = (int32_T)(real32_T)floor(E33_VCU_simulink_B.MCU_SpdCmd_i);

  /* Saturate: '<S185>/MCU_SPD_CMD_sat' */
  if (u0_0 > 10000) {
    u0_0 = 10000;
  } else {
    if (u0_0 < -10000) {
      u0_0 = -10000;
    }
  }

  /* Rounding: '<S185>/MCU_SPD_CMDRon' incorporates:
   *  Constant: '<S185>/MCU_SPD_CMD_F'
   *  Constant: '<S185>/MCU_SPD_CMD_O'
   *  Product: '<S185>/MCU_SPD_CMD_D'
   *  Saturate: '<S185>/MCU_SPD_CMD_sat'
   *  Sum: '<S185>/MCU_SPD_CMD_st'
   */
  u0 = rt_roundf_snf(((real32_T)u0_0 - -10000.0F) / 0.5F);

  /* S-Function (sfix_bitop): '<S175>/or1' incorporates:
   *  Constant: '<S185>/MCU_SPD_CMD_And_C'
   *  DataTypeConversion: '<S185>/BitCov'
   *  DataTypeConversion: '<S185>/MCU_SPD_CMD_Convert'
   *  S-Function (sfix_bitop): '<S185>/MCU_SPD_CMD_And'
   *  Saturate: '<S185>/MCU_SPD_CMD_1sat'
   */
  E33_VCU_simulink_B.or1_m = (uint8_T)((int32_T)u0 & 255U);

  /* S-Function (sfix_bitop): '<S175>/or2' incorporates:
   *  Constant: '<S185>/MCU_SPD_CMDoutput2_C'
   *  DataTypeConversion: '<S185>/MCU_SPD_CMDCOV'
   *  DataTypeConversion: '<S185>/MCU_SPD_CMD_Convert'
   *  Product: '<S185>/MCU_SPD_CMD_D1'
   *  Saturate: '<S185>/MCU_SPD_CMD_1sat'
   */
  E33_VCU_simulink_B.or2_k = (uint8_T)((real_T)(int32_T)u0 / 256.0);

  /* DataTypeConversion: '<S167>/Data Type Conversion10' */
  u0_0 = (int32_T)(real32_T)floor(E33_VCU_simulink_B.MCU_TorqCmd_j);

  /* Saturate: '<S186>/MCU_TORQ_CMD_sat' */
  if (u0_0 > 1000) {
    u0_0 = 1000;
  } else {
    if (u0_0 < 0) {
      u0_0 = 0;
    }
  }

  /* Rounding: '<S186>/MCU_TORQ_CMDRon' incorporates:
   *  Saturate: '<S186>/MCU_TORQ_CMD_sat'
   *  Sum: '<S186>/MCU_TORQ_CMD_st'
   */
  u0 = rt_roundf_snf((real32_T)u0_0);

  /* S-Function (sfix_bitop): '<S175>/or3' incorporates:
   *  Constant: '<S186>/MCU_TORQ_CMD_And_C'
   *  DataTypeConversion: '<S186>/BitCov'
   *  DataTypeConversion: '<S186>/MCU_TORQ_CMD_Convert'
   *  S-Function (sfix_bitop): '<S186>/MCU_TORQ_CMD_And'
   *  Saturate: '<S186>/MCU_TORQ_CMD_1sat'
   */
  E33_VCU_simulink_B.or3_e = (uint8_T)((int32_T)u0 & 255U);

  /* S-Function (sfix_bitop): '<S175>/or4' incorporates:
   *  Constant: '<S186>/MCU_TORQ_CMDoutput4_C'
   *  DataTypeConversion: '<S186>/MCU_TORQ_CMDCOV'
   *  DataTypeConversion: '<S186>/MCU_TORQ_CMD_Convert'
   *  Product: '<S186>/MCU_TORQ_CMD_D1'
   *  Saturate: '<S186>/MCU_TORQ_CMD_1sat'
   */
  E33_VCU_simulink_B.or4_h = (uint8_T)((real_T)(int32_T)u0 / 256.0);

  /* Switch: '<S167>/Switch2' incorporates:
   *  Constant: '<S167>/Constant10'
   *  Constant: '<S167>/Constant5'
   */
  if (E33_VCU_simulink_B.MCU_Cut_o) {
    u0_0 = 0;
  } else {
    u0_0 = 1;
  }

  /* End of Switch: '<S167>/Switch2' */

  /* S-Function (sfix_bitop): '<S175>/or5' incorporates:
   *  ArithShift: '<S183>/MCU_IsTorqMode_S'
   *  DataTypeConversion: '<S183>/MCU_IsTorqMode_Convert'
   *  DataTypeConversion: '<S183>/MCU_IsTorqMode_Convert1'
   *  Rounding: '<S183>/MCU_IsTorqModeRon'
   *  S-Function (sfix_bitop): '<S183>/MCU_IsTorqMode_L'
   *  Saturate: '<S183>/MCU_IsTorqMode_1sat'
   *  Saturate: '<S183>/MCU_IsTorqMode_sat'
   *  Sum: '<S183>/MCU_IsTorqMode_st'
   */
  E33_VCU_simulink_B.or5_j = (uint8_T)((uint32_T)(real32_T)ldexp(rt_roundf_snf
    ((real32_T)(uint16_T)u0_0), 1) & 2U);

  /* Switch: '<S167>/Switch1' incorporates:
   *  Constant: '<S167>/Constant7'
   *  Constant: '<S167>/Constant8'
   */
  if (E33_VCU_simulink_B.MCU_Cut_o) {
    u0_0 = 0;
  } else {
    u0_0 = 2;
  }

  /* End of Switch: '<S167>/Switch1' */

  /* S-Function (sfix_bitop): '<S175>/or6' incorporates:
   *  DataTypeConversion: '<S176>/MCU_GEAR_CMD_Convert'
   *  Rounding: '<S176>/MCU_GEAR_CMDRon'
   *  Saturate: '<S176>/MCU_GEAR_CMD_1sat'
   *  Saturate: '<S176>/MCU_GEAR_CMD_sat'
   *  Sum: '<S176>/MCU_GEAR_CMD_st'
   */
  E33_VCU_simulink_B.or6_i = (uint8_T)((int32_T)rt_roundf_snf((real32_T)
    (uint16_T)u0_0) | 8);

  /* S-Function (sfix_bitop): '<S175>/or7' */
  E33_VCU_simulink_B.or7_g = 0U;

  /* S-Function (sfix_bitop): '<S175>/or8' */
  E33_VCU_simulink_B.or8_n = 0U;

  /* Outputs for Enabled SubSystem: '<S167>/MCU_CMD_CAN_Tx' incorporates:
   *  EnablePort: '<S174>/Enable'
   */
  if (E33_VCU_simulink_B.MCU_Online_g) {
    /* S-Function (ec55xx_cantransmitslb): '<S174>/CANTransmit' */

    /*Transmit CAN message*/
    {
      uint8 CAN0BUF8TX[8];
      uint8 can0buf8looptx= 0;
      CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or1_m;
      can0buf8looptx++;
      CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or2_k;
      can0buf8looptx++;
      CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or3_e;
      can0buf8looptx++;
      CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or4_h;
      can0buf8looptx++;
      CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or5_j;
      can0buf8looptx++;
      CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or6_i;
      can0buf8looptx++;
      CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or7_g;
      can0buf8looptx++;
      CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or8_n;
      can0buf8looptx++;
      VCUMCUCANOKK= ec_can_transmit(0, 8, 1, 146927393U, 8, CAN0BUF8TX);
    }
  }

  /* End of Outputs for SubSystem: '<S167>/MCU_CMD_CAN_Tx' */

  /* S-Function (fcncallgen): '<S5>/20ms1' incorporates:
   *  SubSystem: '<S5>/TailLight'
   */
  /* RelationalOperator: '<S192>/Compare' incorporates:
   *  Constant: '<S192>/Constant'
   */
  rtb_Compare_c = (E33_VCU_simulink_B.BP_F_Pos_l >= 80);

  /* RelationalOperator: '<S193>/Compare' incorporates:
   *  Constant: '<S193>/Constant'
   */
  rtb_Compare_n = (E33_VCU_simulink_B.BP_F_Pos_l >= 950);

  /* Chart: '<S169>/LED' incorporates:
   *  Constant: '<S169>/Constant1'
   *  Constant: '<S169>/Constant2'
   */
  E33_VCU_simulink_DW.presentTicks_i = E33_VCU_simulink_M->Timing.clockTick4;
  E33_VCU_simulink_DW.elapsedTicks_g = E33_VCU_simulink_DW.presentTicks_i -
    E33_VCU_simulink_DW.previousTicks_nj;
  E33_VCU_simulink_DW.previousTicks_nj = E33_VCU_simulink_DW.presentTicks_i;
  E33_VCU_simulink_DW.temporalCounter_i1_h += E33_VCU_simulink_DW.elapsedTicks_g;

  /* Gateway: Subsystem1/TailLight/LED */
  /* During: Subsystem1/TailLight/LED */
  if (E33_VCU_simulink_DW.bitsForTID4.is_active_c4_E33_VCU_simulink == 0U) {
    /* Entry: Subsystem1/TailLight/LED */
    E33_VCU_simulink_DW.bitsForTID4.is_active_c4_E33_VCU_simulink = 1U;

    /* Entry Internal: Subsystem1/TailLight/LED */
    E33_VCU_simulink_DW.bitsForTID4.is_c4_E33_VCU_simulink =
      E33_VCU_simulink_IN_LEDStat;

    /* Entry Internal 'LEDStat': '<S194>:1' */
    /* Transition: '<S194>:14' */
    E33_VCU_simulink_DW.bitsForTID4.is_LEDStat_p = E33_VCU_simulink_IN_Init;
    E33_VCU_simulink_DW.temporalCounter_i1_h = 0U;
  } else {
    /* During 'LEDStat': '<S194>:1' */
    switch (E33_VCU_simulink_DW.bitsForTID4.is_LEDStat_p) {
     case E33_VCU_simulink_IN_Blink:
      /* During 'Blink': '<S194>:74' */
      if ((!rtb_Compare_n) && rtb_Compare_c) {
        /* Transition: '<S194>:77' */
        /* Exit Internal 'Blink': '<S194>:74' */
        E33_VCU_simulink_DW.bitsForTID4.is_Blink_b =
          E33_VCU_simu_IN_NO_ACTIVE_CHILD;
        E33_VCU_simulink_DW.bitsForTID4.is_LEDStat_p = E33_VCU_simulink_IN_ON_n;

        /* Entry 'ON': '<S194>:68' */
        tmp_0 = rt_roundd_snf(Brk_luminance);
        if (tmp_0 < 65536.0) {
          if (tmp_0 >= 0.0) {
            E33_VCU_simulink_B.LEDDutyCyc = (uint16_T)tmp_0;
          } else {
            E33_VCU_simulink_B.LEDDutyCyc = 0U;
          }
        } else {
          E33_VCU_simulink_B.LEDDutyCyc = MAX_uint16_T;
        }
      } else if (!rtb_Compare_c) {
        /* Transition: '<S194>:78' */
        /* Exit Internal 'Blink': '<S194>:74' */
        E33_VCU_simulink_DW.bitsForTID4.is_Blink_b =
          E33_VCU_simu_IN_NO_ACTIVE_CHILD;
        E33_VCU_simulink_DW.bitsForTID4.is_LEDStat_p = E33_VCU_simulink_IN_OFF_m;

        /* Entry 'OFF': '<S194>:66' */
        E33_VCU_simulink_B.LEDDutyCyc = 0U;
      } else if (E33_VCU_simulink_DW.bitsForTID4.is_Blink_b ==
                 E33_VCU_simulink_IN_BlinkOff) {
        /* During 'BlinkOff': '<S194>:81' */
        if (E33_VCU_simulink_DW.temporalCounter_i1_h >= 5U) {
          /* Transition: '<S194>:84' */
          E33_VCU_simulink_DW.bitsForTID4.is_Blink_b =
            E33_VCU_simulink_IN_BlinkOn;
          E33_VCU_simulink_DW.temporalCounter_i1_h = 0U;

          /* Entry 'BlinkOn': '<S194>:79' */
          tmp_0 = rt_roundd_snf(HardBrk_luminance);
          if (tmp_0 < 65536.0) {
            if (tmp_0 >= 0.0) {
              E33_VCU_simulink_B.LEDDutyCyc = (uint16_T)tmp_0;
            } else {
              E33_VCU_simulink_B.LEDDutyCyc = 0U;
            }
          } else {
            E33_VCU_simulink_B.LEDDutyCyc = MAX_uint16_T;
          }
        }
      } else {
        /* During 'BlinkOn': '<S194>:79' */
        if (E33_VCU_simulink_DW.temporalCounter_i1_h >= 5U) {
          /* Transition: '<S194>:83' */
          E33_VCU_simulink_DW.bitsForTID4.is_Blink_b =
            E33_VCU_simulink_IN_BlinkOff;
          E33_VCU_simulink_DW.temporalCounter_i1_h = 0U;

          /* Entry 'BlinkOff': '<S194>:81' */
          tmp_0 = rt_roundd_snf(Brk_luminance);
          if (tmp_0 < 65536.0) {
            if (tmp_0 >= 0.0) {
              E33_VCU_simulink_B.LEDDutyCyc = (uint16_T)tmp_0;
            } else {
              E33_VCU_simulink_B.LEDDutyCyc = 0U;
            }
          } else {
            E33_VCU_simulink_B.LEDDutyCyc = MAX_uint16_T;
          }
        }
      }
      break;

     case E33_VCU_simulink_IN_Init:
      /* During 'Init': '<S194>:71' */
      if (E33_VCU_simulink_DW.temporalCounter_i1_h >= 50U) {
        /* Transition: '<S194>:72' */
        E33_VCU_simulink_DW.bitsForTID4.is_LEDStat_p =
          E33_VCU_simulink_IN_LightTest;
        E33_VCU_simulink_DW.temporalCounter_i1_h = 0U;
      }
      break;

     case E33_VCU_simulink_IN_LightTest:
      /* During 'LightTest': '<S194>:13' */
      if (E33_VCU_simulink_DW.temporalCounter_i1_h >= 200U) {
        /* Transition: '<S194>:16' */
        E33_VCU_simulink_DW.bitsForTID4.is_LEDStat_p = E33_VCU_simulink_IN_OFF_m;

        /* Entry 'OFF': '<S194>:66' */
        E33_VCU_simulink_B.LEDDutyCyc = 0U;
      } else {
        tmp_0 = rt_roundd_snf(E33_VCU_simulink_GetDutyCyc((real_T)
          E33_VCU_simulink_DW.temporalCounter_i1_h * 0.02, 4.0));
        if (tmp_0 < 65536.0) {
          if (tmp_0 >= 0.0) {
            E33_VCU_simulink_B.LEDDutyCyc = (uint16_T)tmp_0;
          } else {
            E33_VCU_simulink_B.LEDDutyCyc = 0U;
          }
        } else {
          E33_VCU_simulink_B.LEDDutyCyc = MAX_uint16_T;
        }
      }
      break;

     case E33_VCU_simulink_IN_OFF_m:
      /* During 'OFF': '<S194>:66' */
      if (rtb_Compare_n) {
        /* Transition: '<S194>:75' */
        E33_VCU_simulink_DW.bitsForTID4.is_LEDStat_p = E33_VCU_simulink_IN_Blink;

        /* Entry Internal 'Blink': '<S194>:74' */
        /* Transition: '<S194>:82' */
        E33_VCU_simulink_DW.bitsForTID4.is_Blink_b = E33_VCU_simulink_IN_BlinkOn;
        E33_VCU_simulink_DW.temporalCounter_i1_h = 0U;

        /* Entry 'BlinkOn': '<S194>:79' */
        tmp_0 = rt_roundd_snf(HardBrk_luminance);
        if (tmp_0 < 65536.0) {
          if (tmp_0 >= 0.0) {
            E33_VCU_simulink_B.LEDDutyCyc = (uint16_T)tmp_0;
          } else {
            E33_VCU_simulink_B.LEDDutyCyc = 0U;
          }
        } else {
          E33_VCU_simulink_B.LEDDutyCyc = MAX_uint16_T;
        }
      } else {
        if (rtb_Compare_c) {
          /* Transition: '<S194>:69' */
          E33_VCU_simulink_DW.bitsForTID4.is_LEDStat_p =
            E33_VCU_simulink_IN_ON_n;

          /* Entry 'ON': '<S194>:68' */
          tmp_0 = rt_roundd_snf(Brk_luminance);
          if (tmp_0 < 65536.0) {
            if (tmp_0 >= 0.0) {
              E33_VCU_simulink_B.LEDDutyCyc = (uint16_T)tmp_0;
            } else {
              E33_VCU_simulink_B.LEDDutyCyc = 0U;
            }
          } else {
            E33_VCU_simulink_B.LEDDutyCyc = MAX_uint16_T;
          }
        }
      }
      break;

     default:
      /* During 'ON': '<S194>:68' */
      if (!rtb_Compare_c) {
        /* Transition: '<S194>:70' */
        E33_VCU_simulink_DW.bitsForTID4.is_LEDStat_p = E33_VCU_simulink_IN_OFF_m;

        /* Entry 'OFF': '<S194>:66' */
        E33_VCU_simulink_B.LEDDutyCyc = 0U;
      } else {
        if (rtb_Compare_n) {
          /* Transition: '<S194>:76' */
          E33_VCU_simulink_DW.bitsForTID4.is_LEDStat_p =
            E33_VCU_simulink_IN_Blink;

          /* Entry Internal 'Blink': '<S194>:74' */
          /* Transition: '<S194>:82' */
          E33_VCU_simulink_DW.bitsForTID4.is_Blink_b =
            E33_VCU_simulink_IN_BlinkOn;
          E33_VCU_simulink_DW.temporalCounter_i1_h = 0U;

          /* Entry 'BlinkOn': '<S194>:79' */
          tmp_0 = rt_roundd_snf(HardBrk_luminance);
          if (tmp_0 < 65536.0) {
            if (tmp_0 >= 0.0) {
              E33_VCU_simulink_B.LEDDutyCyc = (uint16_T)tmp_0;
            } else {
              E33_VCU_simulink_B.LEDDutyCyc = 0U;
            }
          } else {
            E33_VCU_simulink_B.LEDDutyCyc = MAX_uint16_T;
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S169>/LED' */

  /* Switch: '<S169>/Switch1' incorporates:
   *  Constant: '<S169>/Constant5'
   *  Constant: '<S169>/Constant8'
   */
  if (FactoryTestEnable != 0.0) {
    tmp = Tail_Light_Test;
  } else {
    tmp = E33_VCU_simulink_B.LEDDutyCyc;
  }

  /* End of Switch: '<S169>/Switch1' */

  /* Gain: '<S169>/Gain' */
  tmp_3 = 3355443200U;
  uMultiWordMul(&tmp_3, 1, &tmp, 1, &tmp_2.chunks[0U], 2);

  /* DataTypeConversion: '<S169>/Data Type Conversion1' */
  uMultiWordShr(&tmp_2.chunks[0U], 2, 26U, &tmp_1.chunks[0U], 2);
  E33_VCU_simulink_B.TailLightOnTime = MultiWord2uLong(&tmp_1.chunks[0U]);

  /* S-Function (ec55xx_pdpslb): '<S169>/TailLightctrl' */

  /* Power driver PWM output for channel 3 */
  ec_pwm_output(3,5000U,E33_VCU_simulink_B.TailLightOnTime);

  /* Update absolute time */
  /* The "clockTick4" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.02, which is the step size
   * of the task. Size of "clockTick4" ensures timer will not overflow during the
   * application lifespan selected.
   */
  E33_VCU_simulink_M->Timing.clockTick4++;
}

/* Model step function for TID5 */
void E33_VCU_simulink_step5(void)      /* Sample time: [0.05s, 0.0s] */
{
  boolean_T rtb_LogicalOperator1;
  real32_T rtb_DLookupTable1;
  uint16_T rtb_DataTypeConversion10_d;
  uint8_T rtb_DataTypeConversion16;
  uint32_T tmp;
  real_T tmp_0;
  uint64m_T tmp_1;
  uint64m_T tmp_2;
  uint32_T tmp_3;
  uint64m_T tmp_4;
  int32_T tmp_5;

  /* S-Function (fcncallgen): '<S5>/50ms2' incorporates:
   *  SubSystem: '<S5>/DCDC_Ctrl'
   */
  /* Logic: '<S166>/Logical Operator1' incorporates:
   *  Constant: '<S172>/Constant'
   *  RelationalOperator: '<S172>/Compare'
   */
  rtb_LogicalOperator1 = ((E33_VCU_simulink_B.BMS_Stat_g == 5.0F) &&
    E33_VCU_simulink_B.BMS_Online_o);

  /* Chart: '<S166>/DCDC_Ctrl' */
  E33_VCU_simulink_DW.presentTicks = E33_VCU_simulink_M->Timing.clockTick5;
  E33_VCU_simulink_DW.elapsedTicks = E33_VCU_simulink_DW.presentTicks -
    E33_VCU_simulink_DW.previousTicks;
  E33_VCU_simulink_DW.previousTicks = E33_VCU_simulink_DW.presentTicks;
  if (E33_VCU_simulink_DW.temporalCounter_i1_i +
      E33_VCU_simulink_DW.elapsedTicks <= 63U) {
    E33_VCU_simulink_DW.temporalCounter_i1_i = (uint8_T)
      (E33_VCU_simulink_DW.temporalCounter_i1_i +
       E33_VCU_simulink_DW.elapsedTicks);
  } else {
    E33_VCU_simulink_DW.temporalCounter_i1_i = 63U;
  }

  /* Gateway: Subsystem1/DCDC_Ctrl/DCDC_Ctrl */
  /* During: Subsystem1/DCDC_Ctrl/DCDC_Ctrl */
  if (E33_VCU_simulink_DW.bitsForTID5.is_active_c13_E33_VCU_simulink == 0U) {
    /* Entry: Subsystem1/DCDC_Ctrl/DCDC_Ctrl */
    E33_VCU_simulink_DW.bitsForTID5.is_active_c13_E33_VCU_simulink = 1U;

    /* Entry Internal: Subsystem1/DCDC_Ctrl/DCDC_Ctrl */
    E33_VCU_simulink_DW.bitsForTID5.is_c13_E33_VCU_simulink =
      E33_VCU_simulink_IN_DCDC_MR;

    /* Entry Internal 'DCDC_MR': '<S173>:1' */
    /* Transition: '<S173>:6' */
    E33_VCU_simulink_DW.bitsForTID5.is_DCDC_MR = E33_VCU_simulink_IN_OFF;
    E33_VCU_simulink_DW.temporalCounter_i1_i = 0U;
  } else {
    /* During 'DCDC_MR': '<S173>:1' */
    E33_VCU_simulink_B.DCDC_ON_l = (E33_VCU_simulink_DW.bitsForTID5.is_DCDC_MR ==
      E33_VCU_simulink_IN_ON);
    if (E33_VCU_simulink_DW.bitsForTID5.is_DCDC_MR == E33_VCU_simulink_IN_OFF) {
      /* During 'OFF': '<S173>:2' */
      if ((E33_VCU_simulink_DW.temporalCounter_i1_i >= 40U) &&
          rtb_LogicalOperator1) {
        /* Transition: '<S173>:8' */
        E33_VCU_simulink_DW.bitsForTID5.is_DCDC_MR = E33_VCU_simulink_IN_ON;
        E33_VCU_simulink_DW.temporalCounter_i1_i = 0U;
      }
    } else {
      /* During 'ON': '<S173>:3' */
      if ((E33_VCU_simulink_DW.temporalCounter_i1_i >= 40U) &&
          (!rtb_LogicalOperator1)) {
        /* Transition: '<S173>:9' */
        E33_VCU_simulink_DW.bitsForTID5.is_DCDC_MR = E33_VCU_simulink_IN_OFF;
        E33_VCU_simulink_DW.temporalCounter_i1_i = 0U;
      }
    }
  }

  /* End of Chart: '<S166>/DCDC_Ctrl' */

  /* DataTypeConversion: '<S166>/Data Type Conversion3' */
  DCDC_ON = E33_VCU_simulink_B.DCDC_ON_l;

  /* Switch: '<S166>/Switch1' incorporates:
   *  Constant: '<S166>/Constant4'
   *  Constant: '<S166>/Constant5'
   */
  if (FactoryTestEnable != 0.0) {
    DCDC_MR = DCDC_Relay_Test;
  } else {
    DCDC_MR = DCDC_ON;
  }

  /* End of Switch: '<S166>/Switch1' */

  /* S-Function (ec55xx_pdsslb): '<S166>/DCDC_MR_CTRL' */

  /* Set level DCDC_MR for the specified power driver switch */
  ec_gpio_write(184,DCDC_MR);

  /* S-Function (fcncallgen): '<S5>/50ms' incorporates:
   *  SubSystem: '<S5>/PanelCtrl'
   */
  /* Chart: '<S168>/BMS_ALM' */
  E33_VCU_simulink_DW.presentTicks_e = E33_VCU_simulink_M->Timing.clockTick5;
  E33_VCU_simulink_DW.elapsedTicks_m = E33_VCU_simulink_DW.presentTicks_e -
    E33_VCU_simulink_DW.previousTicks_n;
  E33_VCU_simulink_DW.previousTicks_n = E33_VCU_simulink_DW.presentTicks_e;
  if (E33_VCU_simulink_DW.temporalCounter_i1_pw +
      E33_VCU_simulink_DW.elapsedTicks_m <= 63U) {
    E33_VCU_simulink_DW.temporalCounter_i1_pw = (uint8_T)
      (E33_VCU_simulink_DW.temporalCounter_i1_pw +
       E33_VCU_simulink_DW.elapsedTicks_m);
  } else {
    E33_VCU_simulink_DW.temporalCounter_i1_pw = 63U;
  }

  /* Gateway: Subsystem1/PanelCtrl/BMS_ALM */
  /* During: Subsystem1/PanelCtrl/BMS_ALM */
  if (E33_VCU_simulink_DW.bitsForTID5.is_active_c8_E33_VCU_simulink == 0U) {
    /* Entry: Subsystem1/PanelCtrl/BMS_ALM */
    E33_VCU_simulink_DW.bitsForTID5.is_active_c8_E33_VCU_simulink = 1U;

    /* Entry Internal: Subsystem1/PanelCtrl/BMS_ALM */
    E33_VCU_simulink_DW.bitsForTID5.is_c8_E33_VCU_simulink =
      E33_VCU_simulink_IN_LEDStat;

    /* Entry Internal 'LEDStat': '<S187>:1' */
    /* Transition: '<S187>:14' */
    E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_li = E33_VCU_simulink_IN_Init_n;
    E33_VCU_simulink_DW.temporalCounter_i1_pw = 0U;

    /* Entry 'Init': '<S187>:65' */
    E33_VCU_simulink_B.LED_g = false;
  } else {
    /* During 'LEDStat': '<S187>:1' */
    switch (E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_li) {
     case E33_VCU_simulink_IN_AlevelAlm:
      /* During 'AlevelAlm': '<S187>:11' */
      if ((E33_VCU_simulink_B.BMS_AlmLv_c != 1.0F) &&
          E33_VCU_simulink_B.BMS_Online_n) {
        /* Transition: '<S187>:49' */
        /* Transition: '<S187>:54' */
        /* Transition: '<S187>:57' */
        /* Transition: '<S187>:58' */
        if ((E33_VCU_simulink_B.BMS_AlmLv_c == 1.0F) ||
            (!E33_VCU_simulink_B.BMS_Online_n)) {
          /* Transition: '<S187>:28' */
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_li =
            E33_VCU_simulink_IN_AlevelAlm;

          /* Entry 'AlevelAlm': '<S187>:11' */
          E33_VCU_simulink_B.LED_g = true;
        } else {
          /* Transition: '<S187>:35' */
          if (E33_VCU_simulink_B.BMS_AlmLv_c == 2.0F) {
            /* Transition: '<S187>:3' */
            E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_li =
              E33_VCU_simulink_IN_BlevelAlm;

            /* Entry Internal 'BlevelAlm': '<S187>:10' */
            /* Transition: '<S187>:64' */
            E33_VCU_simulink_DW.bitsForTID5.is_BlevelAlm =
              E33_VCU_simulink_IN_BlvBlinkON;
            E33_VCU_simulink_DW.temporalCounter_i1_pw = 0U;

            /* Entry 'BlvBlinkON': '<S187>:60' */
            E33_VCU_simulink_B.LED_g = true;
          } else {
            /* Transition: '<S187>:36' */
            /* Transition: '<S187>:31' */
            E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_li =
              E33_VCU_simulink_IN_OFF_m;

            /* Entry 'OFF': '<S187>:12' */
            E33_VCU_simulink_B.LED_g = false;
          }
        }
      }
      break;

     case E33_VCU_simulink_IN_BlevelAlm:
      /* During 'BlevelAlm': '<S187>:10' */
      if ((E33_VCU_simulink_B.BMS_AlmLv_c != 2.0F) ||
          (!E33_VCU_simulink_B.BMS_Online_n)) {
        /* Transition: '<S187>:40' */
        /* Transition: '<S187>:53' */
        /* Transition: '<S187>:54' */
        /* Transition: '<S187>:57' */
        /* Transition: '<S187>:58' */
        if ((E33_VCU_simulink_B.BMS_AlmLv_c == 1.0F) ||
            (!E33_VCU_simulink_B.BMS_Online_n)) {
          /* Transition: '<S187>:28' */
          /* Exit Internal 'BlevelAlm': '<S187>:10' */
          E33_VCU_simulink_DW.bitsForTID5.is_BlevelAlm =
            E33_VCU_simu_IN_NO_ACTIVE_CHILD;
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_li =
            E33_VCU_simulink_IN_AlevelAlm;

          /* Entry 'AlevelAlm': '<S187>:11' */
          E33_VCU_simulink_B.LED_g = true;
        } else {
          /* Transition: '<S187>:35' */
          if (E33_VCU_simulink_B.BMS_AlmLv_c == 2.0F) {
            /* Transition: '<S187>:3' */
            /* Exit Internal 'BlevelAlm': '<S187>:10' */
            E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_li =
              E33_VCU_simulink_IN_BlevelAlm;

            /* Entry Internal 'BlevelAlm': '<S187>:10' */
            /* Transition: '<S187>:64' */
            E33_VCU_simulink_DW.bitsForTID5.is_BlevelAlm =
              E33_VCU_simulink_IN_BlvBlinkON;
            E33_VCU_simulink_DW.temporalCounter_i1_pw = 0U;

            /* Entry 'BlvBlinkON': '<S187>:60' */
            E33_VCU_simulink_B.LED_g = true;
          } else {
            /* Transition: '<S187>:36' */
            /* Transition: '<S187>:31' */
            /* Exit Internal 'BlevelAlm': '<S187>:10' */
            E33_VCU_simulink_DW.bitsForTID5.is_BlevelAlm =
              E33_VCU_simu_IN_NO_ACTIVE_CHILD;
            E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_li =
              E33_VCU_simulink_IN_OFF_m;

            /* Entry 'OFF': '<S187>:12' */
            E33_VCU_simulink_B.LED_g = false;
          }
        }
      } else if (E33_VCU_simulink_DW.bitsForTID5.is_BlevelAlm ==
                 E33_VCU_simulink_IN_BlvBlinkON) {
        /* During 'BlvBlinkON': '<S187>:60' */
        if (E33_VCU_simulink_DW.temporalCounter_i1_pw >= 20U) {
          /* Transition: '<S187>:63' */
          E33_VCU_simulink_DW.bitsForTID5.is_BlevelAlm =
            E33_VCU_simulink_IN_BlvBlinkOff;
          E33_VCU_simulink_DW.temporalCounter_i1_pw = 0U;

          /* Entry 'BlvBlinkOff': '<S187>:59' */
          E33_VCU_simulink_B.LED_g = false;
        }
      } else {
        /* During 'BlvBlinkOff': '<S187>:59' */
        if (E33_VCU_simulink_DW.temporalCounter_i1_pw >= 20U) {
          /* Transition: '<S187>:61' */
          E33_VCU_simulink_DW.bitsForTID5.is_BlevelAlm =
            E33_VCU_simulink_IN_BlvBlinkON;
          E33_VCU_simulink_DW.temporalCounter_i1_pw = 0U;

          /* Entry 'BlvBlinkON': '<S187>:60' */
          E33_VCU_simulink_B.LED_g = true;
        }
      }
      break;

     case E33_VCU_simulink_IN_Init_n:
      /* During 'Init': '<S187>:65' */
      if (E33_VCU_simulink_DW.temporalCounter_i1_pw >= 20U) {
        /* Transition: '<S187>:66' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_li = E33_VCU_simulink_IN_Test;
        E33_VCU_simulink_DW.temporalCounter_i1_pw = 0U;

        /* Entry 'Test': '<S187>:13' */
        E33_VCU_simulink_B.LED_g = true;
      }
      break;

     case E33_VCU_simulink_IN_OFF_m:
      /* During 'OFF': '<S187>:12' */
      /* Transition: '<S187>:50' */
      /* Transition: '<S187>:51' */
      /* Transition: '<S187>:53' */
      /* Transition: '<S187>:54' */
      /* Transition: '<S187>:57' */
      /* Transition: '<S187>:58' */
      if ((E33_VCU_simulink_B.BMS_AlmLv_c == 1.0F) ||
          (!E33_VCU_simulink_B.BMS_Online_n)) {
        /* Transition: '<S187>:28' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_li =
          E33_VCU_simulink_IN_AlevelAlm;

        /* Entry 'AlevelAlm': '<S187>:11' */
        E33_VCU_simulink_B.LED_g = true;
      } else {
        /* Transition: '<S187>:35' */
        if (E33_VCU_simulink_B.BMS_AlmLv_c == 2.0F) {
          /* Transition: '<S187>:3' */
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_li =
            E33_VCU_simulink_IN_BlevelAlm;

          /* Entry Internal 'BlevelAlm': '<S187>:10' */
          /* Transition: '<S187>:64' */
          E33_VCU_simulink_DW.bitsForTID5.is_BlevelAlm =
            E33_VCU_simulink_IN_BlvBlinkON;
          E33_VCU_simulink_DW.temporalCounter_i1_pw = 0U;

          /* Entry 'BlvBlinkON': '<S187>:60' */
          E33_VCU_simulink_B.LED_g = true;
        } else {
          /* Transition: '<S187>:36' */
          /* Transition: '<S187>:31' */
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_li =
            E33_VCU_simulink_IN_OFF_m;

          /* Entry 'OFF': '<S187>:12' */
          E33_VCU_simulink_B.LED_g = false;
        }
      }
      break;

     default:
      /* During 'Test': '<S187>:13' */
      if (E33_VCU_simulink_DW.temporalCounter_i1_pw >= 60U) {
        /* Transition: '<S187>:16' */
        E33_VCU_simulink_B.LED_g = true;
        if ((E33_VCU_simulink_B.BMS_AlmLv_c == 1.0F) ||
            (!E33_VCU_simulink_B.BMS_Online_n)) {
          /* Transition: '<S187>:28' */
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_li =
            E33_VCU_simulink_IN_AlevelAlm;

          /* Entry 'AlevelAlm': '<S187>:11' */
          E33_VCU_simulink_B.LED_g = true;
        } else {
          /* Transition: '<S187>:35' */
          if (E33_VCU_simulink_B.BMS_AlmLv_c == 2.0F) {
            /* Transition: '<S187>:3' */
            E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_li =
              E33_VCU_simulink_IN_BlevelAlm;

            /* Entry Internal 'BlevelAlm': '<S187>:10' */
            /* Transition: '<S187>:64' */
            E33_VCU_simulink_DW.bitsForTID5.is_BlevelAlm =
              E33_VCU_simulink_IN_BlvBlinkON;
            E33_VCU_simulink_DW.temporalCounter_i1_pw = 0U;

            /* Entry 'BlvBlinkON': '<S187>:60' */
            E33_VCU_simulink_B.LED_g = true;
          } else {
            /* Transition: '<S187>:36' */
            /* Transition: '<S187>:31' */
            E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_li =
              E33_VCU_simulink_IN_OFF_m;

            /* Entry 'OFF': '<S187>:12' */
            E33_VCU_simulink_B.LED_g = false;
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S168>/BMS_ALM' */

  /* Switch: '<S168>/Switch3' incorporates:
   *  Constant: '<S168>/Constant8'
   *  Constant: '<S168>/Constant9'
   */
  if (FactoryTestEnable != 0.0) {
    BmsLedStat = BMSLedTest;
  } else {
    BmsLedStat = E33_VCU_simulink_B.LED_g;
  }

  /* End of Switch: '<S168>/Switch3' */

  /* S-Function (ec55xx_pdsslb): '<S168>/BMSLEDctrl_SW1' */

  /* Set level BmsLedStat for the specified power driver switch */
  ec_gpio_write(191,BmsLedStat);

  /* Switch: '<S168>/Switch2' incorporates:
   *  Constant: '<S168>/Constant6'
   *  Constant: '<S168>/Constant7'
   */
  if (FactoryTestEnable != 0.0) {
    BeeperStat = BeeperTest;
  } else {
    BeeperStat = E33_VCU_simulink_B.BeeperOut;
  }

  /* End of Switch: '<S168>/Switch2' */

  /* S-Function (ec55xx_pdsslb): '<S168>/BeeperCtrl' */

  /* Set level BeeperStat for the specified power driver switch */
  ec_gpio_write(183,BeeperStat);

  /* Chart: '<S168>/IMD_ALM' */
  E33_VCU_simulink_DW.presentTicks_oa = E33_VCU_simulink_M->Timing.clockTick5;
  E33_VCU_simulink_DW.elapsedTicks_ea = E33_VCU_simulink_DW.presentTicks_oa -
    E33_VCU_simulink_DW.previousTicks_la;
  E33_VCU_simulink_DW.previousTicks_la = E33_VCU_simulink_DW.presentTicks_oa;
  if (E33_VCU_simulink_DW.temporalCounter_i1_p +
      E33_VCU_simulink_DW.elapsedTicks_ea <= 63U) {
    E33_VCU_simulink_DW.temporalCounter_i1_p = (uint8_T)
      (E33_VCU_simulink_DW.temporalCounter_i1_p +
       E33_VCU_simulink_DW.elapsedTicks_ea);
  } else {
    E33_VCU_simulink_DW.temporalCounter_i1_p = 63U;
  }

  /* Gateway: Subsystem1/PanelCtrl/IMD_ALM */
  /* During: Subsystem1/PanelCtrl/IMD_ALM */
  if (E33_VCU_simulink_DW.bitsForTID5.is_active_c11_E33_VCU_simulink == 0U) {
    /* Entry: Subsystem1/PanelCtrl/IMD_ALM */
    E33_VCU_simulink_DW.bitsForTID5.is_active_c11_E33_VCU_simulink = 1U;

    /* Entry Internal: Subsystem1/PanelCtrl/IMD_ALM */
    E33_VCU_simulink_DW.bitsForTID5.is_c11_E33_VCU_simulink =
      E33_VCU_simulink_IN_LEDStat;

    /* Entry Internal 'LEDStat': '<S190>:1' */
    /* Transition: '<S190>:75' */
    E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_l = E33_VCU_simulink_IN_Init;
    E33_VCU_simulink_DW.temporalCounter_i1_p = 0U;

    /* Entry 'Init': '<S190>:72' */
    E33_VCU_simulink_B.LED = false;
  } else {
    /* During 'LEDStat': '<S190>:1' */
    switch (E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_l) {
     case E33_VCU_simulink_IN_AlevelAlm:
      /* During 'AlevelAlm': '<S190>:11' */
      if (E33_VCU_simulink_B.LEAK_OC_p != 0.0F) {
        /* Transition: '<S190>:49' */
        /* Transition: '<S190>:54' */
        /* Transition: '<S190>:57' */
        /* Transition: '<S190>:58' */
        if (!(E33_VCU_simulink_B.LEAK_OC_p != 0.0F)) {
          /* Transition: '<S190>:28' */
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_l =
            E33_VCU_simulink_IN_AlevelAlm;

          /* Entry 'AlevelAlm': '<S190>:11' */
          E33_VCU_simulink_B.LED = false;
        } else {
          /* Transition: '<S190>:35' */
          /* Transition: '<S190>:31' */
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_l =
            E33_VCU_simulink_IN_OFF_e;

          /* Entry 'OFF': '<S190>:12' */
          E33_VCU_simulink_B.LED = true;
        }
      }
      break;

     case E33_VCU_simulink_IN_Init:
      /* During 'Init': '<S190>:72' */
      if (E33_VCU_simulink_DW.temporalCounter_i1_p >= 20U) {
        /* Transition: '<S190>:74' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_l =
          E33_VCU_simulink_IN_Test_l;
        E33_VCU_simulink_DW.temporalCounter_i1_p = 0U;

        /* Entry 'Test': '<S190>:73' */
        E33_VCU_simulink_B.LED = true;
      }
      break;

     case E33_VCU_simulink_IN_OFF_e:
      /* During 'OFF': '<S190>:12' */
      /* Transition: '<S190>:50' */
      /* Transition: '<S190>:53' */
      /* Transition: '<S190>:54' */
      /* Transition: '<S190>:57' */
      /* Transition: '<S190>:58' */
      if (!(E33_VCU_simulink_B.LEAK_OC_p != 0.0F)) {
        /* Transition: '<S190>:28' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_l =
          E33_VCU_simulink_IN_AlevelAlm;

        /* Entry 'AlevelAlm': '<S190>:11' */
        E33_VCU_simulink_B.LED = false;
      } else {
        /* Transition: '<S190>:35' */
        /* Transition: '<S190>:31' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_l = E33_VCU_simulink_IN_OFF_e;

        /* Entry 'OFF': '<S190>:12' */
        E33_VCU_simulink_B.LED = true;
      }
      break;

     default:
      /* During 'Test': '<S190>:73' */
      if (E33_VCU_simulink_DW.temporalCounter_i1_p >= 60U) {
        /* Transition: '<S190>:16' */
        E33_VCU_simulink_B.LED = true;
        if (!(E33_VCU_simulink_B.LEAK_OC_p != 0.0F)) {
          /* Transition: '<S190>:28' */
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_l =
            E33_VCU_simulink_IN_AlevelAlm;

          /* Entry 'AlevelAlm': '<S190>:11' */
          E33_VCU_simulink_B.LED = false;
        } else {
          /* Transition: '<S190>:35' */
          /* Transition: '<S190>:31' */
          E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_l =
            E33_VCU_simulink_IN_OFF_e;

          /* Entry 'OFF': '<S190>:12' */
          E33_VCU_simulink_B.LED = true;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S168>/IMD_ALM' */

  /* Switch: '<S168>/Switch4' incorporates:
   *  Constant: '<S168>/Constant10'
   *  Constant: '<S168>/Constant11'
   */
  if (FactoryTestEnable != 0.0) {
    ImdLedStat = IMDLedTest;
  } else {
    ImdLedStat = E33_VCU_simulink_B.LED;
  }

  /* End of Switch: '<S168>/Switch4' */

  /* S-Function (ec55xx_pdsslb): '<S168>/IMDLEDctrl_SW' */

  /* Set level ImdLedStat for the specified power driver switch */
  ec_gpio_write(180,ImdLedStat);

  /* DataTypeConversion: '<S168>/Data Type Conversion1' */
  E33_VCU_simulink_B.DataTypeConversion1 = (E33_VCU_simulink_B.APPS_Unreliable_g
    != 0);

  /* Chart: '<S168>/Ready_SW' */
  E33_VCU_simulink_DW.presentTicks_o = E33_VCU_simulink_M->Timing.clockTick5;
  E33_VCU_simulink_DW.elapsedTicks_n = E33_VCU_simulink_DW.presentTicks_o -
    E33_VCU_simulink_DW.previousTicks_b;
  E33_VCU_simulink_DW.previousTicks_b = E33_VCU_simulink_DW.presentTicks_o;
  if (E33_VCU_simulink_DW.temporalCounter_i1_be +
      E33_VCU_simulink_DW.elapsedTicks_n <= 63U) {
    E33_VCU_simulink_DW.temporalCounter_i1_be = (uint8_T)
      (E33_VCU_simulink_DW.temporalCounter_i1_be +
       E33_VCU_simulink_DW.elapsedTicks_n);
  } else {
    E33_VCU_simulink_DW.temporalCounter_i1_be = 63U;
  }

  /* Gateway: Subsystem1/PanelCtrl/Ready_SW */
  /* During: Subsystem1/PanelCtrl/Ready_SW */
  if (E33_VCU_simulink_DW.bitsForTID5.is_active_c6_E33_VCU_simulink == 0U) {
    /* Entry: Subsystem1/PanelCtrl/Ready_SW */
    E33_VCU_simulink_DW.bitsForTID5.is_active_c6_E33_VCU_simulink = 1U;

    /* Entry Internal: Subsystem1/PanelCtrl/Ready_SW */
    E33_VCU_simulink_DW.bitsForTID5.is_c6_E33_VCU_simulink =
      E33_VCU_simulink_IN_LEDStat;

    /* Entry Internal 'LEDStat': '<S191>:50' */
    /* Transition: '<S191>:58' */
    E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_m = E33_VCU_simulink_IN_Init_n;
    E33_VCU_simulink_DW.temporalCounter_i1_be = 0U;
  } else {
    E33_VCU_simulink_LEDStat();
  }

  /* End of Chart: '<S168>/Ready_SW' */

  /* Switch: '<S168>/Switch1' incorporates:
   *  Constant: '<S168>/Constant4'
   *  Constant: '<S168>/Constant5'
   */
  if (FactoryTestEnable != 0.0) {
    ReadyLEDstat = R2D_Light_Test;
  } else {
    ReadyLEDstat = R2D_Light;
  }

  /* End of Switch: '<S168>/Switch1' */

  /* S-Function (ec55xx_pdsslb): '<S168>/ReadyLEDctrl_SW' */

  /* Set level ReadyLEDstat for the specified power driver switch */
  ec_gpio_write(179,ReadyLEDstat);

  /* S-Function (fcncallgen): '<S5>/50ms1' incorporates:
   *  SubSystem: '<S5>/TmanageCtrl'
   */
  /* Lookup_n-D: '<S170>/1-D Lookup Table1' */
  rtb_DLookupTable1 = look1_iflf_binlc(E33_VCU_simulink_B.MaxTemp_f,
    Accu_FAN_threshold, E33_VCU_simulink_ConstP.DLookupTable1_tableDa, 1U);

  /* DataTypeConversion: '<S170>/Data Type Conversion10' */
  rtb_DataTypeConversion10_d = (uint16_T)rtb_DLookupTable1;

  /* DataTypeConversion: '<S170>/Data Type Conversion9' */
  rtb_DataTypeConversion16 = (uint8_T)E33_VCU_simulink_B.BMS_Stat_k;

  /* Logic: '<S170>/Logical Operator4' incorporates:
   *  Constant: '<S200>/Constant'
   *  RelationalOperator: '<S200>/Compare'
   */
  rtb_LogicalOperator1 = ((rtb_DataTypeConversion16 == 5) &&
    E33_VCU_simulink_B.BMS_Online_f);

  /* Chart: '<S170>/Accu_FAN' incorporates:
   *  Constant: '<S199>/Constant'
   *  Logic: '<S170>/Logical Operator2'
   *  RelationalOperator: '<S199>/Compare'
   */
  E33_VCU_simulink_DW.presentTicks_h = E33_VCU_simulink_M->Timing.clockTick5;
  E33_VCU_simulink_DW.elapsedTicks_dj = E33_VCU_simulink_DW.presentTicks_h -
    E33_VCU_simulink_DW.previousTicks_g;
  E33_VCU_simulink_DW.previousTicks_g = E33_VCU_simulink_DW.presentTicks_h;
  E33_VCU_simulink_DW.temporalCounter_i1_b +=
    E33_VCU_simulink_DW.elapsedTicks_dj;

  /* Gateway: Subsystem1/TmanageCtrl/Accu_FAN */
  /* During: Subsystem1/TmanageCtrl/Accu_FAN */
  if (E33_VCU_simulink_DW.bitsForTID5.is_active_c14_E33_VCU_simulink == 0U) {
    /* Entry: Subsystem1/TmanageCtrl/Accu_FAN */
    E33_VCU_simulink_DW.bitsForTID5.is_active_c14_E33_VCU_simulink = 1U;

    /* Entry Internal: Subsystem1/TmanageCtrl/Accu_FAN */
    E33_VCU_simulink_DW.bitsForTID5.is_c14_E33_VCU_simulink =
      E33_VCU_simulink_IN_LEDStat;

    /* Entry Internal 'LEDStat': '<S195>:1' */
    /* Transition: '<S195>:14' */
    E33_VCU_simulink_DW.bitsForTID5.is_LEDStat = E33_VCU_simulink_IN_Init_e;
    E33_VCU_simulink_DW.temporalCounter_i1_b = 0U;
  } else {
    /* During 'LEDStat': '<S195>:1' */
    switch (E33_VCU_simulink_DW.bitsForTID5.is_LEDStat) {
     case E33_VCU_simulink_IN_Init_e:
      /* During 'Init': '<S195>:71' */
      if (E33_VCU_simulink_DW.temporalCounter_i1_b >= 20U) {
        /* Transition: '<S195>:72' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat =
          E33_VCU_simulink_IN_PumpTest;
        E33_VCU_simulink_DW.temporalCounter_i1_b = 0U;
      }
      break;

     case E33_VCU_simulink_IN_PumpTest:
      /* During 'PumpTest': '<S195>:13' */
      /* Transition: '<S195>:16' */
      E33_VCU_simulink_B.FanDutyCycl_o = 0U;
      E33_VCU_simulink_DW.bitsForTID5.is_LEDStat = E33_VCU_simulink_IN_Stand;
      E33_VCU_simulink_DW.temporalCounter_i1_b = 0U;
      break;

     case E33_VCU_simul_IN_Ready_to_close:
      /* During 'Ready_to_close': '<S195>:102' */
      if ((E33_VCU_simulink_DW.temporalCounter_i1_b >= 600U) ||
          ((rtb_DataTypeConversion16 == 4) && E33_VCU_simulink_B.BMS_Online_f))
      {
        /* Transition: '<S195>:104' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat = E33_VCU_simulink_IN_Stand;
        E33_VCU_simulink_DW.temporalCounter_i1_b = 0U;
      } else {
        E33_VCU_simulink_B.FanDutyCycl_o = rtb_DataTypeConversion10_d;
      }
      break;

     case E33_VCU_simulink_IN_Run:
      /* During 'Run': '<S195>:92' */
      if (!rtb_LogicalOperator1) {
        /* Transition: '<S195>:95' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat =
          E33_VCU_simul_IN_Ready_to_close;
        E33_VCU_simulink_DW.temporalCounter_i1_b = 0U;
      } else {
        E33_VCU_simulink_B.FanDutyCycl_o = rtb_DataTypeConversion10_d;
      }
      break;

     default:
      /* During 'Stand': '<S195>:66' */
      if (rtb_LogicalOperator1 || (E33_VCU_simulink_DW.temporalCounter_i1_b >=
           60U)) {
        /* Transition: '<S195>:93' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat = E33_VCU_simulink_IN_Run;
      } else {
        E33_VCU_simulink_B.FanDutyCycl_o = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S170>/Accu_FAN' */

  /* Switch: '<S170>/Switch4' incorporates:
   *  Constant: '<S170>/Constant11'
   *  Constant: '<S170>/Constant12'
   */
  if (FactoryTestEnable != 0.0) {
    tmp = Accu_FAN_Test;
  } else {
    tmp = E33_VCU_simulink_B.FanDutyCycl_o;
  }

  /* End of Switch: '<S170>/Switch4' */

  /* Gain: '<S170>/Gain3' */
  tmp_3 = 3355443200U;
  uMultiWordMul(&tmp_3, 1, &tmp, 1, &tmp_2.chunks[0U], 2);

  /* DataTypeConversion: '<S170>/Data Type Conversion8' */
  uMultiWordShr(&tmp_2.chunks[0U], 2, 26U, &tmp_1.chunks[0U], 2);
  E33_VCU_simulink_B.FanOnTime = MultiWord2uLong(&tmp_1.chunks[0U]);

  /* S-Function (ec55xx_pdpslb): '<S170>/AccuFanCtrl' */

  /* Power driver PWM output for channel 14 */
  ec_pwm_output(14,5000U,E33_VCU_simulink_B.FanOnTime);

  /* MinMax: '<S170>/MinMax' */
  if ((E33_VCU_simulink_B.MCU_MotorTemp >= E33_VCU_simulink_B.MCU_McuTemp) ||
      rtIsNaNF(E33_VCU_simulink_B.MCU_McuTemp)) {
    rtb_DLookupTable1 = E33_VCU_simulink_B.MCU_MotorTemp;
  } else {
    rtb_DLookupTable1 = E33_VCU_simulink_B.MCU_McuTemp;
  }

  /* RelationalOperator: '<S197>/Compare' incorporates:
   *  Constant: '<S197>/Constant'
   *  MinMax: '<S170>/MinMax'
   */
  rtb_LogicalOperator1 = (rtb_DLookupTable1 >= Pump_threshold);

  /* Chart: '<S170>/Pump' */
  E33_VCU_simulink_DW.presentTicks_c = E33_VCU_simulink_M->Timing.clockTick5;
  E33_VCU_simulink_DW.elapsedTicks_d = E33_VCU_simulink_DW.presentTicks_c -
    E33_VCU_simulink_DW.previousTicks_k;
  E33_VCU_simulink_DW.previousTicks_k = E33_VCU_simulink_DW.presentTicks_c;
  if (E33_VCU_simulink_DW.temporalCounter_i1_bk +
      E33_VCU_simulink_DW.elapsedTicks_d <= 255U) {
    E33_VCU_simulink_DW.temporalCounter_i1_bk = (uint8_T)
      (E33_VCU_simulink_DW.temporalCounter_i1_bk +
       E33_VCU_simulink_DW.elapsedTicks_d);
  } else {
    E33_VCU_simulink_DW.temporalCounter_i1_bk = MAX_uint8_T;
  }

  /* Gateway: Subsystem1/TmanageCtrl/Pump */
  /* During: Subsystem1/TmanageCtrl/Pump */
  if (E33_VCU_simulink_DW.bitsForTID5.is_active_c5_E33_VCU_simulink == 0U) {
    /* Entry: Subsystem1/TmanageCtrl/Pump */
    E33_VCU_simulink_DW.bitsForTID5.is_active_c5_E33_VCU_simulink = 1U;

    /* Entry Internal: Subsystem1/TmanageCtrl/Pump */
    E33_VCU_simulink_DW.bitsForTID5.is_c5_E33_VCU_simulink =
      E33_VCU_simulink_IN_Pump_MR;

    /* Entry Internal 'Pump_MR': '<S202>:1' */
    /* Transition: '<S202>:6' */
    E33_VCU_simulink_DW.bitsForTID5.is_Pump_MR = E33_VCU_simulink_IN_Init_e;
    E33_VCU_simulink_DW.temporalCounter_i1_bk = 0U;
  } else {
    /* During 'Pump_MR': '<S202>:1' */
    switch (E33_VCU_simulink_DW.bitsForTID5.is_Pump_MR) {
     case E33_VCU_simulink_IN_Init_e:
      /* During 'Init': '<S202>:19' */
      if (E33_VCU_simulink_DW.temporalCounter_i1_bk >= 20U) {
        /* Transition: '<S202>:20' */
        E33_VCU_simulink_DW.bitsForTID5.is_Pump_MR =
          E33_VCU_simulink_IN_PumpTest_o;
        E33_VCU_simulink_DW.temporalCounter_i1_bk = 0U;
      }
      break;

     case E33_VCU_simulink_IN_OFF_d:
      /* During 'OFF': '<S202>:2' */
      if (rtb_LogicalOperator1) {
        /* Transition: '<S202>:8' */
        E33_VCU_simulink_DW.bitsForTID5.is_Pump_MR = E33_VCU_simulink_IN_ON_b;
      } else {
        E33_VCU_simulink_B.Pump_ON = 0.0;
      }
      break;

     case E33_VCU_simulink_IN_ON_b:
      /* During 'ON': '<S202>:3' */
      if (!rtb_LogicalOperator1) {
        /* Transition: '<S202>:9' */
        E33_VCU_simulink_DW.bitsForTID5.is_Pump_MR = E33_VCU_simulink_IN_OFF_d;
      } else {
        E33_VCU_simulink_B.Pump_ON = 1.0;
      }
      break;

     default:
      /* During 'PumpTest': '<S202>:16' */
      if (E33_VCU_simulink_DW.temporalCounter_i1_bk >= 160U) {
        /* Transition: '<S202>:17' */
        E33_VCU_simulink_DW.bitsForTID5.is_Pump_MR = E33_VCU_simulink_IN_OFF_d;
      } else {
        E33_VCU_simulink_B.Pump_ON = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<S170>/Pump' */

  /* Switch: '<S170>/Switch3' incorporates:
   *  Constant: '<S170>/Constant8'
   *  Constant: '<S170>/Constant9'
   *  DataTypeConversion: '<S170>/Data Type Conversion5'
   */
  if (FactoryTestEnable != 0.0) {
    E33_VCU_simulink_B.Switch3 = Pump_Test;
  } else {
    E33_VCU_simulink_B.Switch3 = (E33_VCU_simulink_B.Pump_ON != 0.0);
  }

  /* End of Switch: '<S170>/Switch3' */

  /* S-Function (ec55xx_pdsslb): '<S170>/Pump_ctrl' */

  /* Set level E33_VCU_simulink_B.Switch3 for the specified power driver switch */
  ec_gpio_write(181,E33_VCU_simulink_B.Switch3);

  /* Chart: '<S170>/Accu_FAN1' incorporates:
   *  Constant: '<S198>/Constant'
   *  Constant: '<S201>/Constant'
   *  DataTypeConversion: '<S170>/Data Type Conversion16'
   *  Logic: '<S170>/Logical Operator7'
   *  RelationalOperator: '<S198>/Compare'
   *  RelationalOperator: '<S201>/Compare'
   *  Switch: '<S170>/Switch1'
   */
  E33_VCU_simulink_DW.presentTicks_j = E33_VCU_simulink_M->Timing.clockTick5;
  E33_VCU_simulink_DW.elapsedTicks_e = E33_VCU_simulink_DW.presentTicks_j -
    E33_VCU_simulink_DW.previousTicks_l;
  E33_VCU_simulink_DW.previousTicks_l = E33_VCU_simulink_DW.presentTicks_j;
  E33_VCU_simulink_DW.temporalCounter_i1 += E33_VCU_simulink_DW.elapsedTicks_e;

  /* Gateway: Subsystem1/TmanageCtrl/Accu_FAN1 */
  /* During: Subsystem1/TmanageCtrl/Accu_FAN1 */
  if (E33_VCU_simulink_DW.bitsForTID5.is_active_c1_E33_VCU_simulink == 0U) {
    /* Entry: Subsystem1/TmanageCtrl/Accu_FAN1 */
    E33_VCU_simulink_DW.bitsForTID5.is_active_c1_E33_VCU_simulink = 1U;

    /* Entry Internal: Subsystem1/TmanageCtrl/Accu_FAN1 */
    E33_VCU_simulink_DW.bitsForTID5.is_c1_E33_VCU_simulink =
      E33_VCU_simulink_IN_LEDStat;

    /* Entry Internal 'LEDStat': '<S196>:1' */
    /* Transition: '<S196>:14' */
    E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_mt = E33_VCU_simulink_IN_Init_e;
    E33_VCU_simulink_DW.temporalCounter_i1 = 0U;
  } else {
    /* During 'LEDStat': '<S196>:1' */
    switch (E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_mt) {
     case E33_VCU_simulink_IN_Init_e:
      /* During 'Init': '<S196>:71' */
      if (E33_VCU_simulink_DW.temporalCounter_i1 >= 20U) {
        /* Transition: '<S196>:72' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_mt =
          E33_VCU_simulink_IN_PumpTest;
        E33_VCU_simulink_DW.temporalCounter_i1 = 0U;
      }
      break;

     case E33_VCU_simulink_IN_PumpTest:
      /* During 'PumpTest': '<S196>:13' */
      if (E33_VCU_simulink_DW.temporalCounter_i1 >= 40U) {
        /* Transition: '<S196>:93' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_mt =
          E33_VCU_simulink_IN_Run_i;
      } else {
        tmp_0 = rt_roundd_snf(E33_VCU_simulink_GetDutyCyc_n((real_T)
          E33_VCU_simulink_DW.temporalCounter_i1 * 0.05, 8.0));
        if (tmp_0 < 65536.0) {
          if (tmp_0 >= 0.0) {
            E33_VCU_simulink_B.FanDutyCycl = (uint16_T)tmp_0;
          } else {
            E33_VCU_simulink_B.FanDutyCycl = 0U;
          }
        } else {
          E33_VCU_simulink_B.FanDutyCycl = MAX_uint16_T;
        }
      }
      break;

     default:
      /* During 'Run': '<S196>:92' */
      if (((uint8_T)E33_VCU_simulink_B.BMS_Stat_k == 4) &&
          E33_VCU_simulink_B.BMS_Online_f) {
        /* Transition: '<S196>:104' */
        E33_VCU_simulink_DW.bitsForTID5.is_LEDStat_mt =
          E33_VCU_simulink_IN_PumpTest;
        E33_VCU_simulink_DW.temporalCounter_i1 = 0U;
      } else if (E33_VCU_simulink_B.MCU_McuTemp >= 30.0F) {
        /* Switch: '<S170>/Switch1' incorporates:
         *  Constant: '<S170>/Constant1'
         *  DataTypeConversion: '<S170>/Data Type Conversion14'
         */
        E33_VCU_simulink_B.FanDutyCycl = 100U;
      } else {
        /* Switch: '<S170>/Switch1' incorporates:
         *  Constant: '<S170>/Constant2'
         *  DataTypeConversion: '<S170>/Data Type Conversion14'
         */
        E33_VCU_simulink_B.FanDutyCycl = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S170>/Accu_FAN1' */

  /* Switch: '<S170>/Switch5' incorporates:
   *  Constant: '<S170>/Constant13'
   *  Constant: '<S170>/Constant14'
   */
  if (FactoryTestEnable != 0.0) {
    tmp = Radiator_FAN_Test;
  } else {
    tmp = E33_VCU_simulink_B.FanDutyCycl;
  }

  /* End of Switch: '<S170>/Switch5' */

  /* Gain: '<S170>/Gain4' */
  uMultiWordMul(&tmp_3, 1, &tmp, 1, &tmp_4.chunks[0U], 2);

  /* DataTypeConversion: '<S170>/Data Type Conversion15' */
  uMultiWordShr(&tmp_4.chunks[0U], 2, 26U, &tmp_2.chunks[0U], 2);
  E33_VCU_simulink_B.FanOnTime_c = MultiWord2uLong(&tmp_2.chunks[0U]);

  /* S-Function (ec55xx_pdpslb): '<S170>/Radiator_FAN_Ctrl' */

  /* Power driver PWM output for channel 19 */
  ec_pwm_output(19,5000U,E33_VCU_simulink_B.FanOnTime_c);

  /* S-Function (fcncallgen): '<S5>/50ms3' incorporates:
   *  SubSystem: '<S5>/VCUCAN'
   */
  /* Saturate: '<S204>/Linear_FL_sat' */
  if (E33_VCU_simulink_B.Linear_FL_d <= 5000) {
    rtb_DataTypeConversion10_d = E33_VCU_simulink_B.Linear_FL_d;
  } else {
    rtb_DataTypeConversion10_d = 5000U;
  }

  /* Rounding: '<S204>/Linear_FLRon' incorporates:
   *  Saturate: '<S204>/Linear_FL_sat'
   *  Sum: '<S204>/Linear_FL_st'
   */
  rtb_DLookupTable1 = rt_roundf_snf((real32_T)rtb_DataTypeConversion10_d);

  /* Saturate: '<S204>/Linear_FL_1sat' */
  if (rtb_DLookupTable1 > 255.0F) {
    rtb_DLookupTable1 = 255.0F;
  }

  /* End of Saturate: '<S204>/Linear_FL_1sat' */

  /* S-Function (sfix_bitop): '<S203>/or1' incorporates:
   *  DataTypeConversion: '<S204>/Linear_FL_Convert'
   *  DataTypeConversion: '<S204>/Linear_FL_Convert1'
   */
  E33_VCU_simulink_B.or1 = (uint8_T)rtb_DLookupTable1;

  /* Saturate: '<S206>/Linear_RL_sat' */
  if (E33_VCU_simulink_B.Linear_RL_a <= 5000) {
    rtb_DataTypeConversion10_d = E33_VCU_simulink_B.Linear_RL_a;
  } else {
    rtb_DataTypeConversion10_d = 5000U;
  }

  /* Rounding: '<S206>/Linear_RLRon' incorporates:
   *  Saturate: '<S206>/Linear_RL_sat'
   *  Sum: '<S206>/Linear_RL_st'
   */
  rtb_DLookupTable1 = rt_roundf_snf((real32_T)rtb_DataTypeConversion10_d);

  /* Saturate: '<S206>/Linear_RL_1sat' */
  if (rtb_DLookupTable1 > 255.0F) {
    rtb_DLookupTable1 = 255.0F;
  }

  /* End of Saturate: '<S206>/Linear_RL_1sat' */

  /* S-Function (sfix_bitop): '<S203>/or2' incorporates:
   *  DataTypeConversion: '<S206>/Linear_RL_Convert'
   *  DataTypeConversion: '<S206>/Linear_RL_Convert1'
   */
  E33_VCU_simulink_B.or2 = (uint8_T)rtb_DLookupTable1;

  /* Saturate: '<S205>/Linear_FR_sat' */
  if (E33_VCU_simulink_B.Linear_FR_p <= 5000) {
    rtb_DataTypeConversion10_d = E33_VCU_simulink_B.Linear_FR_p;
  } else {
    rtb_DataTypeConversion10_d = 5000U;
  }

  /* Rounding: '<S205>/Linear_FRRon' incorporates:
   *  Saturate: '<S205>/Linear_FR_sat'
   *  Sum: '<S205>/Linear_FR_st'
   */
  rtb_DLookupTable1 = rt_roundf_snf((real32_T)rtb_DataTypeConversion10_d);

  /* Saturate: '<S205>/Linear_FR_1sat' */
  if (rtb_DLookupTable1 > 255.0F) {
    rtb_DLookupTable1 = 255.0F;
  }

  /* End of Saturate: '<S205>/Linear_FR_1sat' */

  /* S-Function (sfix_bitop): '<S203>/or3' incorporates:
   *  DataTypeConversion: '<S205>/Linear_FR_Convert'
   *  DataTypeConversion: '<S205>/Linear_FR_Convert1'
   */
  E33_VCU_simulink_B.or3 = (uint8_T)rtb_DLookupTable1;

  /* Saturate: '<S207>/Linear_RR_sat' */
  if (E33_VCU_simulink_B.Linear_RR_k <= 5000) {
    rtb_DataTypeConversion10_d = E33_VCU_simulink_B.Linear_RR_k;
  } else {
    rtb_DataTypeConversion10_d = 5000U;
  }

  /* Rounding: '<S207>/Linear_RRRon' incorporates:
   *  Saturate: '<S207>/Linear_RR_sat'
   *  Sum: '<S207>/Linear_RR_st'
   */
  rtb_DLookupTable1 = rt_roundf_snf((real32_T)rtb_DataTypeConversion10_d);

  /* Saturate: '<S207>/Linear_RR_1sat' */
  if (rtb_DLookupTable1 > 255.0F) {
    rtb_DLookupTable1 = 255.0F;
  }

  /* End of Saturate: '<S207>/Linear_RR_1sat' */

  /* S-Function (sfix_bitop): '<S203>/or4' incorporates:
   *  DataTypeConversion: '<S207>/Linear_RR_Convert'
   *  DataTypeConversion: '<S207>/Linear_RR_Convert1'
   */
  E33_VCU_simulink_B.or4 = (uint8_T)rtb_DLookupTable1;

  /* Saturate: '<S208>/Wheel_Angle_sat' */
  if (E33_VCU_simulink_B.Wheel_Angle_a > 5000) {
    tmp_5 = 5000;
  } else if (E33_VCU_simulink_B.Wheel_Angle_a < 0) {
    tmp_5 = 0;
  } else {
    tmp_5 = E33_VCU_simulink_B.Wheel_Angle_a;
  }

  /* Rounding: '<S208>/Wheel_AngleRon' incorporates:
   *  Saturate: '<S208>/Wheel_Angle_sat'
   *  Sum: '<S208>/Wheel_Angle_st'
   */
  rtb_DLookupTable1 = rt_roundf_snf((real32_T)tmp_5);

  /* Saturate: '<S208>/Wheel_Angle_1sat' */
  if (rtb_DLookupTable1 > 255.0F) {
    rtb_DLookupTable1 = 255.0F;
  }

  /* End of Saturate: '<S208>/Wheel_Angle_1sat' */

  /* S-Function (sfix_bitop): '<S203>/or5' incorporates:
   *  DataTypeConversion: '<S208>/Wheel_Angle_Convert'
   *  DataTypeConversion: '<S208>/Wheel_Angle_Convert1'
   */
  E33_VCU_simulink_B.or5 = (uint8_T)rtb_DLookupTable1;

  /* S-Function (sfix_bitop): '<S203>/or6' incorporates:
   *  Constant: '<S208>/Constant6'
   */
  E33_VCU_simulink_B.or6 = 0U;

  /* S-Function (sfix_bitop): '<S203>/or7' incorporates:
   *  Constant: '<S208>/Constant7'
   */
  E33_VCU_simulink_B.or7 = 0U;

  /* S-Function (sfix_bitop): '<S203>/or8' incorporates:
   *  Constant: '<S208>/Constant8'
   */
  E33_VCU_simulink_B.or8 = 0U;

  /* S-Function (ec55xx_cantransmitslb): '<S171>/CANTransmit' */

  /*Transmit CAN message*/
  {
    uint8 CAN0BUF8TX[8];
    uint8 can0buf8looptx= 0;
    CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or1;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or2;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or3;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or4;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or5;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or6;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or7;
    can0buf8looptx++;
    CAN0BUF8TX[can0buf8looptx]= E33_VCU_simulink_B.or8;
    can0buf8looptx++;
    E33_VCU_simulink_B.CANTransmit= ec_can_transmit(0, 8, 1, 385875968U, 8,
      CAN0BUF8TX);
  }

  /* S-Function (fcncallgen): '<S23>/50ms' incorporates:
   *  SubSystem: '<S23>/Self_inspection'
   */

  /* S-Function (ec55xx_pvmslb): '<S29>/APPS1_PWR' */

  /* Read the 5V power supply voltage */
  APPS1_PWR= ec_adc_readresult(16)*2;

  /* S-Function (ec55xx_pvmslb): '<S29>/APPS2_PWR' */

  /* Read the 5V power supply voltage */
  APPS2_PWR= ec_adc_readresult(8)*2;

  /* S-Function (ec55xx_pvmslb): '<S29>/BP_PWR' */

  /* Read the adjustable power supply voltage */
  BP_PWR= ec_adc_readresult(23)*67/20;

  /* S-Function (ec55xx_pvmslb): '<S29>/I_BAT' */

  /* Read the battary voltage */
  I_BAT= ec_adc_readresult(20)*57/10;

  /* S-Function (ec55xx_pvmslb): '<S29>/I_UBR' */

  /* Read the battary voltage */
  I_UBR= ec_adc_readresult(37)*57/10;

  /* S-Function (ec55xx_pvmslb): '<S29>/PWR_5V' */

  /* Read the adjustable power supply voltage */
  PWR_5V= ec_adc_readresult(23)*67/20;

  /* S-Function (fcncallgen): '<S145>/50ms' incorporates:
   *  SubSystem: '<S145>/daq50ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S158>/CCPDAQ' */
  ccpDaq(2);

  /* Update absolute time */
  /* The "clockTick5" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.05, which is the step size
   * of the task. Size of "clockTick5" ensures timer will not overflow during the
   * application lifespan selected.
   */
  E33_VCU_simulink_M->Timing.clockTick5++;
}

/* Model step function for TID6 */
void E33_VCU_simulink_step6(void)      /* Sample time: [0.1s, 0.0s] */
{
  uint8_T rtb_Compare_gh;
  uint8_T rtb_Compare_f;
  uint8_T rtb_Compare_du;
  uint8_T rtb_Compare_c;

  /* S-Function (fcncallgen): '<S23>/100ms' incorporates:
   *  SubSystem: '<S23>/BMS_CAN_Receive'
   */

  /* S-Function (ec55xx_canreceiveslb): '<S25>/BMS_ALM_Receive' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF5RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf5looprx= 0;
    E33_VCU_simulink_B.BMS_ALM_Receive_o3= 409288947;
    E33_VCU_simulink_B.BMS_ALM_Receive_o5= 8;
    E33_VCU_simulink_B.BMS_ALM_Receive_o2= ec_can_receive(0,5, CAN0BUF5RX);
    E33_VCU_simulink_B.BMS_ALM_Receive_o4[0]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
    E33_VCU_simulink_B.BMS_ALM_Receive_o4[1]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
    E33_VCU_simulink_B.BMS_ALM_Receive_o4[2]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
    E33_VCU_simulink_B.BMS_ALM_Receive_o4[3]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
    E33_VCU_simulink_B.BMS_ALM_Receive_o4[4]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
    E33_VCU_simulink_B.BMS_ALM_Receive_o4[5]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
    E33_VCU_simulink_B.BMS_ALM_Receive_o4[6]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
    E33_VCU_simulink_B.BMS_ALM_Receive_o4[7]= CAN0BUF5RX[can0buf5looprx];
    can0buf5looprx++;
  }

  /* Call the system: <S25>/BMS_ALM_Analyze */

  /* Output and update for function-call system: '<S25>/BMS_ALM_Analyze' */

  /* Outputs for Enabled SubSystem: '<S41>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S53>/Enable'
   */
  if (E33_VCU_simulink_B.BMS_ALM_Receive_o2 > 0) {
    /* Saturate: '<S53>/BMS_ALM_LEAK_OC_sat' incorporates:
     *  ArithShift: '<S53>/BMS_ALM_LEAK_OC_S'
     *  DataTypeConversion: '<S53>/BMS_ALM_LEAK_OC_Convert'
     *  DataTypeConversion: '<S53>/BMS_ALM_LEAK_OCcv'
     *  S-Function (sfix_bitop): '<S53>/BMS_ALM_LEAK_OC_L'
     */
    E33_VCU_simulink_B.BMS_ALM_LEAK_OC_sat = (real32_T)(int32_T)
      ((E33_VCU_simulink_B.BMS_ALM_Receive_o4[4] & 96U) >> 5);
  }

  /* End of Outputs for SubSystem: '<S41>/Enabled Subsystem' */

  /* S-Function (ec55xx_canreceiveslb): '<S25>/BMS_MXV_Receive' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF6RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf6looprx= 0;
    E33_VCU_simulink_B.BMS_MXV_Receive_o3= 409026803;
    E33_VCU_simulink_B.BMS_MXV_Receive_o5= 8;
    E33_VCU_simulink_B.BMS_MXV_Receive_o2= ec_can_receive(0,6, CAN0BUF6RX);
    E33_VCU_simulink_B.BMS_MXV_Receive_o4[0]= CAN0BUF6RX[can0buf6looprx];
    can0buf6looprx++;
    E33_VCU_simulink_B.BMS_MXV_Receive_o4[1]= CAN0BUF6RX[can0buf6looprx];
    can0buf6looprx++;
    E33_VCU_simulink_B.BMS_MXV_Receive_o4[2]= CAN0BUF6RX[can0buf6looprx];
    can0buf6looprx++;
    E33_VCU_simulink_B.BMS_MXV_Receive_o4[3]= CAN0BUF6RX[can0buf6looprx];
    can0buf6looprx++;
    E33_VCU_simulink_B.BMS_MXV_Receive_o4[4]= CAN0BUF6RX[can0buf6looprx];
    can0buf6looprx++;
    E33_VCU_simulink_B.BMS_MXV_Receive_o4[5]= CAN0BUF6RX[can0buf6looprx];
    can0buf6looprx++;
    E33_VCU_simulink_B.BMS_MXV_Receive_o4[6]= CAN0BUF6RX[can0buf6looprx];
    can0buf6looprx++;
    E33_VCU_simulink_B.BMS_MXV_Receive_o4[7]= CAN0BUF6RX[can0buf6looprx];
    can0buf6looprx++;
  }

  /* Nothing to do for system: <S25>/BMS_ALM_Analyze1 */

  /* S-Function (ec55xx_canreceiveslb): '<S25>/BMS_INFO_Receive' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF3RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf3looprx= 0;
    E33_VCU_simulink_B.BMS_INFO_Receive_o3= 408961267;
    E33_VCU_simulink_B.BMS_INFO_Receive_o5= 8;
    E33_VCU_simulink_B.BMS_INFO_Receive_o2= ec_can_receive(0,3, CAN0BUF3RX);
    E33_VCU_simulink_B.BMS_INFO_Receive_o4[0]= CAN0BUF3RX[can0buf3looprx];
    can0buf3looprx++;
    E33_VCU_simulink_B.BMS_INFO_Receive_o4[1]= CAN0BUF3RX[can0buf3looprx];
    can0buf3looprx++;
    E33_VCU_simulink_B.BMS_INFO_Receive_o4[2]= CAN0BUF3RX[can0buf3looprx];
    can0buf3looprx++;
    E33_VCU_simulink_B.BMS_INFO_Receive_o4[3]= CAN0BUF3RX[can0buf3looprx];
    can0buf3looprx++;
    E33_VCU_simulink_B.BMS_INFO_Receive_o4[4]= CAN0BUF3RX[can0buf3looprx];
    can0buf3looprx++;
    E33_VCU_simulink_B.BMS_INFO_Receive_o4[5]= CAN0BUF3RX[can0buf3looprx];
    can0buf3looprx++;
    E33_VCU_simulink_B.BMS_INFO_Receive_o4[6]= CAN0BUF3RX[can0buf3looprx];
    can0buf3looprx++;
    E33_VCU_simulink_B.BMS_INFO_Receive_o4[7]= CAN0BUF3RX[can0buf3looprx];
    can0buf3looprx++;
  }

  /* Call the system: <S25>/BMS_INFO_Analyze */

  /* Output and update for function-call system: '<S25>/BMS_INFO_Analyze' */
  {
    real32_T u0;

    /* Outputs for Enabled SubSystem: '<S43>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S84>/Enable'
     */
    if (E33_VCU_simulink_B.BMS_INFO_Receive_o2 > 0) {
      /* DataTypeConversion: '<S84>/BatAlmLvcv' incorporates:
       *  DataTypeConversion: '<S84>/BatAlmLv_Convert'
       *  S-Function (sfix_bitop): '<S84>/BatAlmLv_L'
       */
      u0 = (real32_T)(E33_VCU_simulink_B.BMS_INFO_Receive_o4[6] & 15);

      /* Saturate: '<S84>/BatAlmLv_sat' */
      if (u0 > 4.0F) {
        BMS_AlmLv = 4.0F;
      } else {
        BMS_AlmLv = u0;
      }

      /* End of Saturate: '<S84>/BatAlmLv_sat' */

      /* Sum: '<S84>/BatCurrent_Ad' incorporates:
       *  Constant: '<S84>/BatCurrent_O'
       *  Constant: '<S84>/BatCurrentinput3_C'
       *  Gain: '<S84>/BatCurrent_F'
       *  Product: '<S84>/BatCurrentinput3_P'
       *  Sum: '<S84>/BatCurrentinput3_Ad'
       */
      u0 = (real32_T)((E33_VCU_simulink_B.BMS_INFO_Receive_o4[2] << 8) +
                      E33_VCU_simulink_B.BMS_INFO_Receive_o4[3]) * 0.1F +
        -1000.0F;

      /* Saturate: '<S84>/BatCurrent_sat' */
      if (u0 > 1000.0F) {
        BMS_Current = 1000.0F;
      } else {
        BMS_Current = u0;
      }

      /* End of Saturate: '<S84>/BatCurrent_sat' */

      /* Saturate: '<S84>/BatSoc_sat' incorporates:
       *  DataTypeConversion: '<S84>/BatSoc_Convert'
       *  DataTypeConversion: '<S84>/BatSoccv'
       */
      if (E33_VCU_simulink_B.BMS_INFO_Receive_o4[4] > 100.0F) {
        BMS_SoC = 100.0F;
      } else {
        BMS_SoC = (real32_T)E33_VCU_simulink_B.BMS_INFO_Receive_o4[4];
      }

      /* End of Saturate: '<S84>/BatSoc_sat' */

      /* DataTypeConversion: '<S84>/BatStatecv' incorporates:
       *  ArithShift: '<S84>/BatState_S'
       *  DataTypeConversion: '<S84>/BatState_Convert'
       *  S-Function (sfix_bitop): '<S84>/BatState_L'
       */
      u0 = (real32_T)(int32_T)((E33_VCU_simulink_B.BMS_INFO_Receive_o4[6] & 240U)
        >> 4);

      /* Saturate: '<S84>/BatState_sat' */
      if (u0 > 7.0F) {
        E33_VCU_simulink_B.BatState_sat = 7.0F;
      } else {
        E33_VCU_simulink_B.BatState_sat = u0;
      }

      /* End of Saturate: '<S84>/BatState_sat' */

      /* Gain: '<S84>/BatVoltage_F' incorporates:
       *  Constant: '<S84>/BatVoltageinput1_C'
       *  Product: '<S84>/BatVoltageinput1_P'
       *  Sum: '<S84>/BatVoltageinput1_Ad'
       */
      u0 = (real32_T)((E33_VCU_simulink_B.BMS_INFO_Receive_o4[0] << 8) +
                      E33_VCU_simulink_B.BMS_INFO_Receive_o4[1]) * 0.1F;

      /* Saturate: '<S84>/BatVoltage_sat' */
      if (u0 > 900.0F) {
        BMS_Voltage = 900.0F;
      } else {
        BMS_Voltage = u0;
      }

      /* End of Saturate: '<S84>/BatVoltage_sat' */
    }

    /* End of Outputs for SubSystem: '<S43>/Enabled Subsystem' */
  }

  /* S-Function (ec55xx_canreceiveslb): '<S25>/BMS_MAXT_Receive' */

  /* Receive CAN message */
  {
    uint8 CAN0BUF4RX[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint8 can0buf4looprx= 0;
    E33_VCU_simulink_B.BMS_MAXT_Receive_o3= 409092339;
    E33_VCU_simulink_B.BMS_MAXT_Receive_o5= 8;
    E33_VCU_simulink_B.BMS_MAXT_Receive_o2= ec_can_receive(0,4, CAN0BUF4RX);
    E33_VCU_simulink_B.BMS_MAXT_Receive_o4[0]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    E33_VCU_simulink_B.BMS_MAXT_Receive_o4[1]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    E33_VCU_simulink_B.BMS_MAXT_Receive_o4[2]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    E33_VCU_simulink_B.BMS_MAXT_Receive_o4[3]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    E33_VCU_simulink_B.BMS_MAXT_Receive_o4[4]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    E33_VCU_simulink_B.BMS_MAXT_Receive_o4[5]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    E33_VCU_simulink_B.BMS_MAXT_Receive_o4[6]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
    E33_VCU_simulink_B.BMS_MAXT_Receive_o4[7]= CAN0BUF4RX[can0buf4looprx];
    can0buf4looprx++;
  }

  /* Call the system: <S25>/BMS_MAXT_Analyze */

  /* Output and update for function-call system: '<S25>/BMS_MAXT_Analyze' */

  /* Outputs for Enabled SubSystem: '<S44>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S92>/Enable'
   */
  if (E33_VCU_simulink_B.BMS_MAXT_Receive_o2 > 0) {
    /* Saturate: '<S92>/MaxTemp_sat' incorporates:
     *  Constant: '<S92>/MaxTemp_O'
     *  DataTypeConversion: '<S92>/MaxTemp_Convert'
     *  DataTypeConversion: '<S92>/MaxTempcv'
     *  Sum: '<S92>/MaxTemp_Ad'
     */
    if ((real32_T)E33_VCU_simulink_B.BMS_MAXT_Receive_o4[0] + -40.0F > 120.0F) {
      MaxTemp = 120.0F;
    } else {
      MaxTemp = (real32_T)E33_VCU_simulink_B.BMS_MAXT_Receive_o4[0] + -40.0F;
    }

    /* End of Saturate: '<S92>/MaxTemp_sat' */
  }

  /* End of Outputs for SubSystem: '<S44>/Enabled Subsystem' */

  /* RelationalOperator: '<S49>/Compare' incorporates:
   *  Constant: '<S49>/Constant'
   */
  E33_VCU_simulink_B.Compare_n = (E33_VCU_simulink_B.BMS_INFO_Receive_o2 != 0);

  /* S-Function (sdspcount2): '<S25>/Counter' incorporates:
   *  UnitDelay: '<S25>/Unit Delay'
   */
  if (E33_VCU_simulink_B.Compare_n) {
    E33_VCU_simulink_DW.Counter_Count = 0U;
  }

  if (E33_VCU_simulink_DW.UnitDelay_DSTATE != 0) {
    E33_VCU_simulink_DW.Counter_Count++;
  }

  BMSInfoCnt = E33_VCU_simulink_DW.Counter_Count;

  /* End of S-Function (sdspcount2): '<S25>/Counter' */

  /* RelationalOperator: '<S45>/Compare' incorporates:
   *  Constant: '<S45>/Constant'
   */
  rtb_Compare_gh = (uint8_T)(BMSInfoCnt <= 10);

  /* RelationalOperator: '<S50>/Compare' incorporates:
   *  Constant: '<S50>/Constant'
   */
  E33_VCU_simulink_B.Compare_d = (E33_VCU_simulink_B.BMS_ALM_Receive_o2 != 0);

  /* S-Function (sdspcount2): '<S25>/Counter1' incorporates:
   *  UnitDelay: '<S25>/Unit Delay1'
   */
  if (E33_VCU_simulink_B.Compare_d) {
    E33_VCU_simulink_DW.Counter1_Count_n = 0U;
  }

  if (E33_VCU_simulink_DW.UnitDelay1_DSTATE_l != 0) {
    E33_VCU_simulink_DW.Counter1_Count_n++;
  }

  BMSALMCnt = E33_VCU_simulink_DW.Counter1_Count_n;

  /* End of S-Function (sdspcount2): '<S25>/Counter1' */

  /* RelationalOperator: '<S46>/Compare' incorporates:
   *  Constant: '<S46>/Constant'
   */
  rtb_Compare_f = (uint8_T)(BMSALMCnt <= 100);

  /* RelationalOperator: '<S51>/Compare' incorporates:
   *  Constant: '<S51>/Constant'
   */
  E33_VCU_simulink_B.Compare_i = (E33_VCU_simulink_B.BMS_MAXT_Receive_o2 != 0);

  /* S-Function (sdspcount2): '<S25>/Counter2' incorporates:
   *  UnitDelay: '<S25>/Unit Delay2'
   */
  if (E33_VCU_simulink_B.Compare_i) {
    E33_VCU_simulink_DW.Counter2_Count_c = 0U;
  }

  if (E33_VCU_simulink_DW.UnitDelay2_DSTATE_c != 0) {
    E33_VCU_simulink_DW.Counter2_Count_c++;
  }

  BMSMAXTCnt = E33_VCU_simulink_DW.Counter2_Count_c;

  /* End of S-Function (sdspcount2): '<S25>/Counter2' */

  /* RelationalOperator: '<S47>/Compare' incorporates:
   *  Constant: '<S47>/Constant'
   */
  rtb_Compare_du = (uint8_T)(BMSMAXTCnt <= 10);

  /* RelationalOperator: '<S52>/Compare' incorporates:
   *  Constant: '<S52>/Constant'
   */
  E33_VCU_simulink_B.Compare_f = (E33_VCU_simulink_B.BMS_MXV_Receive_o2 != 0);

  /* S-Function (sdspcount2): '<S25>/Counter3' incorporates:
   *  UnitDelay: '<S25>/Unit Delay3'
   */
  if (E33_VCU_simulink_B.Compare_f) {
    E33_VCU_simulink_DW.Counter3_Count = 0U;
  }

  if (E33_VCU_simulink_DW.UnitDelay3_DSTATE != 0) {
    E33_VCU_simulink_DW.Counter3_Count++;
  }

  BMSMXVCnt = E33_VCU_simulink_DW.Counter3_Count;

  /* End of S-Function (sdspcount2): '<S25>/Counter3' */

  /* RelationalOperator: '<S48>/Compare' incorporates:
   *  Constant: '<S48>/Constant'
   */
  rtb_Compare_c = (uint8_T)(BMSMXVCnt <= 100);

  /* Logic: '<S25>/Logical Operator' */
  BMS_Online = ((rtb_Compare_gh != 0) && (rtb_Compare_du != 0) && (rtb_Compare_f
    != 0) && (rtb_Compare_c != 0));

  /* Update for UnitDelay: '<S25>/Unit Delay' */
  E33_VCU_simulink_DW.UnitDelay_DSTATE = rtb_Compare_gh;

  /* Update for UnitDelay: '<S25>/Unit Delay1' */
  E33_VCU_simulink_DW.UnitDelay1_DSTATE_l = rtb_Compare_f;

  /* Update for UnitDelay: '<S25>/Unit Delay2' */
  E33_VCU_simulink_DW.UnitDelay2_DSTATE_c = rtb_Compare_du;

  /* Update for UnitDelay: '<S25>/Unit Delay3' */
  E33_VCU_simulink_DW.UnitDelay3_DSTATE = rtb_Compare_c;

  /* S-Function (fcncallgen): '<S145>/100ms' incorporates:
   *  SubSystem: '<S145>/daq100ms'
   */

  /* S-Function (ec55xx_ccpslb1): '<S156>/CCPDAQ' */
  ccpDaq(3);

  /* S-Function (ec55xx_vinwrslb): '<S3>/VINWR' */
#if defined EC_VIN_ENABLE

  ec_VIN_WR();

#endif

  /* Update for RateTransition: '<Root>/Rate Transition' */
  E33_VCU_simulink_DW.RateTransition_53_Buffer0 = MaxTemp;

  /* Update for RateTransition: '<Root>/Rate Transition' */
  E33_VCU_simulink_DW.RateTransition_25_Buffer0 =
    E33_VCU_simulink_B.BMS_ALM_LEAK_OC_sat;

  /* Update for RateTransition: '<Root>/Rate Transition' */
  E33_VCU_simulink_DW.RateTransition_18_Buffer0 =
    E33_VCU_simulink_B.BatState_sat;

  /* Update for RateTransition: '<Root>/Rate Transition' */
  E33_VCU_simulink_DW.RateTransition_17_Buffer0 = BMS_AlmLv;

  /* Update for RateTransition: '<Root>/Rate Transition' */
  E33_VCU_simulink_DW.RateTransition_15_Buffer0 = BMS_Online;
}

/* Model step function for TID7 */
void E33_VCU_simulink_step7(void)      /* Sample time: [0.5s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S146>/500ms' incorporates:
   *  SubSystem: '<S146>/FlashOperation'
   */

  /* S-Function (ec55xx_flashoslb): '<S160>/FlashOperatin' */
#if defined EC_FLASH_ENABLE

  /* Operate the flash module on the MPC5554 */
  ec_flash_operation();

#endif

}

/* Model step wrapper function for compatibility with a static main program */
void E33_VCU_simulink_step(int_T tid)
{
  switch (tid) {
   case 0 :
    E33_VCU_simulink_step0();
    break;

   case 1 :
    E33_VCU_simulink_step1();
    break;

   case 2 :
    E33_VCU_simulink_step2();
    break;

   case 3 :
    E33_VCU_simulink_step3();
    break;

   case 4 :
    E33_VCU_simulink_step4();
    break;

   case 5 :
    E33_VCU_simulink_step5();
    break;

   case 6 :
    E33_VCU_simulink_step6();
    break;

   case 7 :
    E33_VCU_simulink_step7();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void E33_VCU_simulink_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (fcncallgen): '<S23>/10ms4' incorporates:
   *  Start for SubSystem: '<S23>/MCU_CAN_Receive'
   */
  /* Start for S-Function (ec55xx_canreceiveslb): '<S28>/CANReceive' */
  ec_buffer_init(0,1,1,218089199);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S28>/CANReceive1' */
  ec_buffer_init(0,2,1,218089455);

  /* Start for S-Function (fcncallgen): '<S5>/20ms' incorporates:
   *  Start for SubSystem: '<S5>/MCUctrl'
   */

  /* Start for Enabled SubSystem: '<S167>/MCU_CMD_CAN_Tx' */

  /* Start for S-Function (ec55xx_cantransmitslb): '<S174>/CANTransmit' */
  ec_buffer_init(0,8,1,146927393U);

  /* End of Start for SubSystem: '<S167>/MCU_CMD_CAN_Tx' */

  /* Start for S-Function (fcncallgen): '<S5>/20ms1' incorporates:
   *  Start for SubSystem: '<S5>/TailLight'
   */
  /* Start for S-Function (ec55xx_pdpslb): '<S169>/TailLightctrl' */

  /* Initialize PWM output for channel 3 */
  ec_pwm_init(3);

  /* Start for S-Function (fcncallgen): '<S5>/50ms1' incorporates:
   *  Start for SubSystem: '<S5>/TmanageCtrl'
   */
  /* Start for S-Function (ec55xx_pdpslb): '<S170>/AccuFanCtrl' */

  /* Initialize PWM output for channel 14 */
  ec_pwm_init(14);

  /* Start for S-Function (ec55xx_pdpslb): '<S170>/Radiator_FAN_Ctrl' */

  /* Initialize PWM output for channel 19 */
  ec_pwm_init(19);

  /* Start for S-Function (fcncallgen): '<S5>/50ms3' incorporates:
   *  Start for SubSystem: '<S5>/VCUCAN'
   */
  /* Start for S-Function (ec55xx_cantransmitslb): '<S171>/CANTransmit' */
  ec_buffer_init(0,8,1,385875968U);

  /* Start for S-Function (fcncallgen): '<S23>/100ms' incorporates:
   *  Start for SubSystem: '<S23>/BMS_CAN_Receive'
   */
  /* Start for S-Function (ec55xx_canreceiveslb): '<S25>/BMS_ALM_Receive' */
  ec_buffer_init(0,5,1,409288947);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S25>/BMS_MXV_Receive' */
  ec_buffer_init(0,6,1,409026803);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S25>/BMS_INFO_Receive' */
  ec_buffer_init(0,3,1,408961267);

  /* Start for S-Function (ec55xx_canreceiveslb): '<S25>/BMS_MAXT_Receive' */
  ec_buffer_init(0,4,1,409092339);

  /* Call the downstream function call subsystem <Root>/Subsystem */

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S144>/ReceiveandTransmitInterrupt' incorporates:
   *  Start for SubSystem: '<S144>/Function-Call Subsystem'
   */
  /* Start for function-call system: '<S144>/Function-Call Subsystem' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S149>/CANReceive1' incorporates:
   *  Start for SubSystem: '<S149>/Function-Call Subsystem'
   */
  /* Start for function-call system: '<S149>/Function-Call Subsystem' */

  /* Start for IfAction SubSystem: '<S150>/If Action Subsystem1' */

  /* Start for S-Function (ec55xx_cantransmitslb): '<S155>/CANTransmit' */
  ec_buffer_init(2,9,0,593U);

  /* End of Start for SubSystem: '<S150>/If Action Subsystem1' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S149>/CANReceive1' */
  ec_buffer_init(2,1,0,278);

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S144>/ReceiveandTransmitInterrupt' */
  ec_bufint_init(2,1);
  INTC_InstallINTCInterruptHandler( ISR_FlexCAN_2_MB1, SW_INT_VEC_CAN2_IFRL_BUF1,
    CAN2_INTC_PRIORITY );

  /* Start for S-Function (fcncallgen): '<S148>/Function-Call Generator' incorporates:
   *  Start for SubSystem: '<S148>/CCPBackground'
   */
  /* Start for S-Function (ec55xx_ccpslb): '<S162>/CCPBackground' */
  ccpInit();

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S148>/ReceiveandTransmitInterrupt' incorporates:
   *  Start for SubSystem: '<S148>/CCPReceive'
   */
  /* Start for function-call system: '<S148>/CCPReceive' */

  /* Start for S-Function (ec55xx_canreceiveslb): '<S163>/CANReceive' */
  ec_buffer_init(2,0,0,CCP_CRO_ID);

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S148>/ReceiveandTransmitInterrupt' */
  ec_bufint_init(2,0);
  INTC_InstallINTCInterruptHandler( ISR_FlexCAN_2_MB0, SW_INT_VEC_CAN2_IFRL_BUF0,
    CAN2_INTC_PRIORITY );

  /* Start for S-Function (ec55xx_caninterruptslb1): '<S148>/ReceiveandTransmitInterrupt1' */
  ec_bufint_init(2,8);
  INTC_InstallINTCInterruptHandler( ISR_FlexCAN_2_MB8, SW_INT_VEC_CAN2_IFRL_BUF8,
    CAN2_INTC_PRIORITY );

  /* Start for S-Function (ec55xx_adcbsb): '<S3>/ADC' */
  ec_adc_init();

  /* Start for S-Function (ec55xx_rtibsb): '<S3>/RTI' */
  ec_rti_init(500);

  /* Start for S-Function (ec55xx_flashbsb): '<Root>/FlashEnable' */
  Fls_Read(0x001c0000,ecflashdataold,4096);
  Fls_Read(0x001c0000,ecflashdatanew,4096);

  /* ConstCode for S-Function (ec55xx_initinterruptslb): '<Root>/Initialization' incorporates:
   *  ConstCode for SubSystem: '<Root>/Subsystem'
   */
  /* ConstCode for function-call system: '<Root>/Subsystem' */

  /* S-Function (ec55xx_arsslb): '<S4>/AfterRunSwitch' */

  /* Set level true for after run switch */
  AfterRunFlags[0] = true;
  if (AfterRunFlags[0] == 1) {
    ec_gpio_write(118,1);
  } else {
    if (AfterRunFlags[1] == 1) {
      AfterRunFlags[0] = 0;
    } else {
      AfterRunFlags[0] = 0;
      ec_gpio_write(118,0);
    }
  }

  /* S-Function (ec55xx_pdsslb): '<S4>/PowerDriverSwitch' */

  /* Set level true for the specified power driver switch */
  ec_gpio_write(205,true);

  /* Enable for S-Function (fcncallgen): '<Root>/10ms' incorporates:
   *  Enable for SubSystem: '<Root>/Function-Call Subsystem'
   */
  E33_VCU_simulink_DW.FunctionCallSubsystem_RESET_ELA = true;

  /* Enable for Chart: '<S6>/Chart' */
  E33_VCU_simulink_DW.presentTicks_b = E33_VCU_simulink_M->Timing.clockTick3;
  E33_VCU_simulink_DW.previousTicks_ge = E33_VCU_simulink_DW.presentTicks_b;

  /* Enable for S-Function (fcncallgen): '<S5>/50ms2' incorporates:
   *  Enable for SubSystem: '<S5>/DCDC_Ctrl'
   */
  /* Enable for Chart: '<S166>/DCDC_Ctrl' */
  E33_VCU_simulink_DW.presentTicks = E33_VCU_simulink_M->Timing.clockTick5;
  E33_VCU_simulink_DW.previousTicks = E33_VCU_simulink_DW.presentTicks;

  /* Enable for S-Function (fcncallgen): '<S5>/50ms' incorporates:
   *  Enable for SubSystem: '<S5>/PanelCtrl'
   */
  /* Enable for Chart: '<S168>/BMS_ALM' */
  E33_VCU_simulink_DW.presentTicks_e = E33_VCU_simulink_M->Timing.clockTick5;
  E33_VCU_simulink_DW.previousTicks_n = E33_VCU_simulink_DW.presentTicks_e;

  /* Enable for Chart: '<S168>/IMD_ALM' */
  E33_VCU_simulink_DW.presentTicks_oa = E33_VCU_simulink_M->Timing.clockTick5;
  E33_VCU_simulink_DW.previousTicks_la = E33_VCU_simulink_DW.presentTicks_oa;

  /* Enable for Chart: '<S168>/Ready_SW' */
  E33_VCU_simulink_DW.presentTicks_o = E33_VCU_simulink_M->Timing.clockTick5;
  E33_VCU_simulink_DW.previousTicks_b = E33_VCU_simulink_DW.presentTicks_o;

  /* Enable for S-Function (fcncallgen): '<S5>/20ms1' incorporates:
   *  Enable for SubSystem: '<S5>/TailLight'
   */
  /* Enable for Chart: '<S169>/LED' */
  E33_VCU_simulink_DW.presentTicks_i = E33_VCU_simulink_M->Timing.clockTick4;
  E33_VCU_simulink_DW.previousTicks_nj = E33_VCU_simulink_DW.presentTicks_i;

  /* Enable for S-Function (fcncallgen): '<S5>/50ms1' incorporates:
   *  Enable for SubSystem: '<S5>/TmanageCtrl'
   */
  /* Enable for Chart: '<S170>/Accu_FAN' */
  E33_VCU_simulink_DW.presentTicks_h = E33_VCU_simulink_M->Timing.clockTick5;
  E33_VCU_simulink_DW.previousTicks_g = E33_VCU_simulink_DW.presentTicks_h;

  /* Enable for Chart: '<S170>/Pump' */
  E33_VCU_simulink_DW.presentTicks_c = E33_VCU_simulink_M->Timing.clockTick5;
  E33_VCU_simulink_DW.previousTicks_k = E33_VCU_simulink_DW.presentTicks_c;

  /* Enable for Chart: '<S170>/Accu_FAN1' */
  E33_VCU_simulink_DW.presentTicks_j = E33_VCU_simulink_M->Timing.clockTick5;
  E33_VCU_simulink_DW.previousTicks_l = E33_VCU_simulink_DW.presentTicks_j;
}

/* File trailer for ECUCoder generated file E33_VCU_simulink.c.
 *
 * [EOF]
 */
