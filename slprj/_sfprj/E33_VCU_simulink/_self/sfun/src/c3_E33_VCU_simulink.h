#ifndef __c3_E33_VCU_simulink_h__
#define __c3_E33_VCU_simulink_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_E33_VCU_simulinkInstanceStruct
#define typedef_SFc3_E33_VCU_simulinkInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_VehStat;
  uint8_T c3_tp_Guard;
  uint8_T c3_tp_Standby;
  uint8_T c3_tp_WaitForEngine;
  uint8_T c3_tp_Trans;
  uint8_T c3_tp_Init;
  uint8_T c3_tp_Ready;
  uint8_T c3_tp_Output;
  uint8_T c3_tp_BeeperStat;
  uint8_T c3_tp_OFF;
  uint8_T c3_tp_ON;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_E33_VCU_simulink;
  uint8_T c3_is_VehStat;
  uint8_T c3_is_active_VehStat;
  uint8_T c3_is_active_Output;
  uint8_T c3_is_BeeperStat;
  uint8_T c3_is_active_BeeperStat;
  uint32_T c3_temporalCounter_i1;
  uint32_T c3_presentTicks;
  uint32_T c3_elapsedTicks;
  uint32_T c3_previousTicks;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
} SFc3_E33_VCU_simulinkInstanceStruct;

#endif                                 /*typedef_SFc3_E33_VCU_simulinkInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_E33_VCU_simulink_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
extern void c3_E33_VCU_simulink_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
