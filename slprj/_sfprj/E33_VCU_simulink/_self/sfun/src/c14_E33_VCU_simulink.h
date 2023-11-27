#ifndef __c14_E33_VCU_simulink_h__
#define __c14_E33_VCU_simulink_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc14_E33_VCU_simulinkInstanceStruct
#define typedef_SFc14_E33_VCU_simulinkInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c14_sfEvent;
  uint8_T c14_tp_LEDStat;
  uint8_T c14_tp_Run;
  uint8_T c14_tp_Init;
  uint8_T c14_tp_Ready_to_close;
  uint8_T c14_tp_PumpTest;
  uint8_T c14_tp_Stand;
  boolean_T c14_isStable;
  uint8_T c14_is_active_c14_E33_VCU_simulink;
  uint8_T c14_is_c14_E33_VCU_simulink;
  uint8_T c14_is_LEDStat;
  uint32_T c14_temporalCounter_i1;
  uint32_T c14_presentTicks;
  uint32_T c14_elapsedTicks;
  uint32_T c14_previousTicks;
  uint8_T c14_doSetSimStateSideEffects;
  const mxArray *c14_setSimStateSideEffectsInfo;
} SFc14_E33_VCU_simulinkInstanceStruct;

#endif                                 /*typedef_SFc14_E33_VCU_simulinkInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c14_E33_VCU_simulink_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c14_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
extern void c14_E33_VCU_simulink_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
