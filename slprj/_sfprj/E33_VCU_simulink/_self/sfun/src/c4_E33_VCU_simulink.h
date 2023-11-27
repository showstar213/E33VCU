#ifndef __c4_E33_VCU_simulink_h__
#define __c4_E33_VCU_simulink_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc4_E33_VCU_simulinkInstanceStruct
#define typedef_SFc4_E33_VCU_simulinkInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  uint8_T c4_tp_LEDStat;
  uint8_T c4_tp_Init;
  uint8_T c4_tp_LightTest;
  uint8_T c4_tp_OFF;
  uint8_T c4_tp_Blink;
  uint8_T c4_tp_BlinkOn;
  uint8_T c4_tp_BlinkOff;
  uint8_T c4_tp_ON;
  boolean_T c4_isStable;
  uint8_T c4_is_active_c4_E33_VCU_simulink;
  uint8_T c4_is_c4_E33_VCU_simulink;
  uint8_T c4_is_LEDStat;
  uint8_T c4_is_Blink;
  uint32_T c4_temporalCounter_i1;
  uint32_T c4_presentTicks;
  uint32_T c4_elapsedTicks;
  uint32_T c4_previousTicks;
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
} SFc4_E33_VCU_simulinkInstanceStruct;

#endif                                 /*typedef_SFc4_E33_VCU_simulinkInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_E33_VCU_simulink_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c4_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
extern void c4_E33_VCU_simulink_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
