#ifndef __c1_E33_VCU_simulink_h__
#define __c1_E33_VCU_simulink_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_E33_VCU_simulinkInstanceStruct
#define typedef_SFc1_E33_VCU_simulinkInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  uint8_T c1_tp_LEDStat;
  uint8_T c1_tp_Run;
  uint8_T c1_tp_Init;
  uint8_T c1_tp_PumpTest;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_E33_VCU_simulink;
  uint8_T c1_is_c1_E33_VCU_simulink;
  uint8_T c1_is_LEDStat;
  uint32_T c1_temporalCounter_i1;
  uint32_T c1_presentTicks;
  uint32_T c1_elapsedTicks;
  uint32_T c1_previousTicks;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_E33_VCU_simulinkInstanceStruct;

#endif                                 /*typedef_SFc1_E33_VCU_simulinkInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_E33_VCU_simulink_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c1_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
extern void c1_E33_VCU_simulink_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
