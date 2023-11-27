#ifndef __c13_E33_VCU_simulink_h__
#define __c13_E33_VCU_simulink_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc13_E33_VCU_simulinkInstanceStruct
#define typedef_SFc13_E33_VCU_simulinkInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  uint8_T c13_tp_DCDC_MR;
  uint8_T c13_tp_OFF;
  uint8_T c13_tp_ON;
  boolean_T c13_isStable;
  uint8_T c13_is_active_c13_E33_VCU_simulink;
  uint8_T c13_is_c13_E33_VCU_simulink;
  uint8_T c13_is_DCDC_MR;
  uint8_T c13_temporalCounter_i1;
  uint32_T c13_presentTicks;
  uint32_T c13_elapsedTicks;
  uint32_T c13_previousTicks;
  uint8_T c13_doSetSimStateSideEffects;
  const mxArray *c13_setSimStateSideEffectsInfo;
} SFc13_E33_VCU_simulinkInstanceStruct;

#endif                                 /*typedef_SFc13_E33_VCU_simulinkInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_E33_VCU_simulink_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c13_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
extern void c13_E33_VCU_simulink_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
