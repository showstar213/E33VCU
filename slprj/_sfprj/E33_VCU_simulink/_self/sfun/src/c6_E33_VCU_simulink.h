#ifndef __c6_E33_VCU_simulink_h__
#define __c6_E33_VCU_simulink_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc6_E33_VCU_simulinkInstanceStruct
#define typedef_SFc6_E33_VCU_simulinkInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  uint8_T c6_tp_LEDStat;
  uint8_T c6_tp_Blink;
  uint8_T c6_tp_BlinkONslow;
  uint8_T c6_tp_BlinkOFFslow;
  uint8_T c6_tp_Init;
  uint8_T c6_tp_Test;
  uint8_T c6_tp_FastBlink;
  uint8_T c6_tp_BlinkONfast;
  uint8_T c6_tp_BlinkOFFfast;
  uint8_T c6_tp_ON;
  uint8_T c6_tp_OFF;
  boolean_T c6_isStable;
  uint8_T c6_is_active_c6_E33_VCU_simulink;
  uint8_T c6_is_c6_E33_VCU_simulink;
  uint8_T c6_is_LEDStat;
  uint8_T c6_is_Blink;
  uint8_T c6_is_FastBlink;
  uint8_T c6_temporalCounter_i1;
  uint32_T c6_presentTicks;
  uint32_T c6_elapsedTicks;
  uint32_T c6_previousTicks;
  uint8_T c6_doSetSimStateSideEffects;
  const mxArray *c6_setSimStateSideEffectsInfo;
} SFc6_E33_VCU_simulinkInstanceStruct;

#endif                                 /*typedef_SFc6_E33_VCU_simulinkInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_E33_VCU_simulink_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c6_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
extern void c6_E33_VCU_simulink_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
