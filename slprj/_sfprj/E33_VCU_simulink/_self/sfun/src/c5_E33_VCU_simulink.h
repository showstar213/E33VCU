#ifndef __c5_E33_VCU_simulink_h__
#define __c5_E33_VCU_simulink_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_E33_VCU_simulinkInstanceStruct
#define typedef_SFc5_E33_VCU_simulinkInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  uint8_T c5_tp_Pump_MR;
  uint8_T c5_tp_Init;
  uint8_T c5_tp_OFF;
  uint8_T c5_tp_ON;
  uint8_T c5_tp_PumpTest;
  boolean_T c5_isStable;
  uint8_T c5_is_active_c5_E33_VCU_simulink;
  uint8_T c5_is_c5_E33_VCU_simulink;
  uint8_T c5_is_Pump_MR;
  uint8_T c5_temporalCounter_i1;
  uint32_T c5_presentTicks;
  uint32_T c5_elapsedTicks;
  uint32_T c5_previousTicks;
  uint8_T c5_doSetSimStateSideEffects;
  const mxArray *c5_setSimStateSideEffectsInfo;
} SFc5_E33_VCU_simulinkInstanceStruct;

#endif                                 /*typedef_SFc5_E33_VCU_simulinkInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_E33_VCU_simulink_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c5_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
extern void c5_E33_VCU_simulink_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
