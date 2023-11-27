#ifndef __c8_E33_VCU_simulink_h__
#define __c8_E33_VCU_simulink_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc8_E33_VCU_simulinkInstanceStruct
#define typedef_SFc8_E33_VCU_simulinkInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c8_sfEvent;
  uint8_T c8_tp_LEDStat;
  uint8_T c8_tp_AlevelAlm;
  uint8_T c8_tp_Init;
  uint8_T c8_tp_BlevelAlm;
  uint8_T c8_tp_BlvBlinkOff;
  uint8_T c8_tp_BlvBlinkON;
  uint8_T c8_tp_Test;
  uint8_T c8_tp_OFF;
  boolean_T c8_isStable;
  uint8_T c8_is_active_c8_E33_VCU_simulink;
  uint8_T c8_is_c8_E33_VCU_simulink;
  uint8_T c8_is_LEDStat;
  uint8_T c8_is_BlevelAlm;
  uint8_T c8_temporalCounter_i1;
  uint32_T c8_presentTicks;
  uint32_T c8_elapsedTicks;
  uint32_T c8_previousTicks;
  uint8_T c8_doSetSimStateSideEffects;
  const mxArray *c8_setSimStateSideEffectsInfo;
} SFc8_E33_VCU_simulinkInstanceStruct;

#endif                                 /*typedef_SFc8_E33_VCU_simulinkInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c8_E33_VCU_simulink_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c8_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
extern void c8_E33_VCU_simulink_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
