/* Include files */

#include <stddef.h>
#include "blas.h"
#include "E33_VCU_simulink_sfun.h"
#include "c13_E33_VCU_simulink.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "E33_VCU_simulink_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c13_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c13_IN_DCDC_MR                 ((uint8_T)1U)
#define c13_IN_OFF                     ((uint8_T)1U)
#define c13_IN_ON                      ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c13_debug_family_names[2] = { "nargin", "nargout" };

static const char * c13_b_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c13_c_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c13_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c13_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c13_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c13_E33_VCU_simulink(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void initialize_params_c13_E33_VCU_simulink
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance);
static void enable_c13_E33_VCU_simulink(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void disable_c13_E33_VCU_simulink(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void c13_update_debugger_state_c13_E33_VCU_simulink
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c13_E33_VCU_simulink
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance);
static void set_sim_state_c13_E33_VCU_simulink
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance, const mxArray *c13_st);
static void c13_set_sim_state_side_effects_c13_E33_VCU_simulink
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance);
static void finalize_c13_E33_VCU_simulink(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void sf_gateway_c13_E33_VCU_simulink(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void initSimStructsc13_E33_VCU_simulink
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static boolean_T c13_b_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_sf_internal_predicateOutput, const char_T
  *c13_identifier);
static boolean_T c13_c_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_d_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static uint8_T c13_e_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_b_tp_DCDC_MR, const char_T *c13_identifier);
static uint8_T c13_f_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static uint32_T c13_g_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_b_previousTicks, const char_T
  *c13_identifier);
static uint32_T c13_h_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId);
static const mxArray *c13_i_emlrt_marshallIn
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance, const mxArray
   *c13_b_setSimStateSideEffectsInfo, const char_T *c13_identifier);
static const mxArray *c13_j_emlrt_marshallIn
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance, const mxArray *c13_u,
   const emlrtMsgIdentifier *c13_parentId);
static void c13_updateDataWrittenToVector(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, uint32_T c13_vectorIndex);
static void c13_errorIfDataNotWrittenToFcn(SFc13_E33_VCU_simulinkInstanceStruct *
  chartInstance, uint32_T c13_vectorIndex, uint32_T c13_dataNumber);
static void init_dsm_address_info(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c13_E33_VCU_simulink(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c13_doSetSimStateSideEffects = 0U;
  chartInstance->c13_setSimStateSideEffectsInfo = NULL;
  chartInstance->c13_is_DCDC_MR = c13_IN_NO_ACTIVE_CHILD;
  chartInstance->c13_tp_DCDC_MR = 0U;
  chartInstance->c13_tp_OFF = 0U;
  chartInstance->c13_temporalCounter_i1 = 0U;
  chartInstance->c13_tp_ON = 0U;
  chartInstance->c13_temporalCounter_i1 = 0U;
  chartInstance->c13_is_active_c13_E33_VCU_simulink = 0U;
  chartInstance->c13_is_c13_E33_VCU_simulink = c13_IN_NO_ACTIVE_CHILD;
  chartInstance->c13_presentTicks = 0U;
  chartInstance->c13_elapsedTicks = 0U;
  chartInstance->c13_previousTicks = 0U;
}

static void initialize_params_c13_E33_VCU_simulink
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c13_E33_VCU_simulink(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c13_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ /
    0.05 + 0.5);
  chartInstance->c13_previousTicks = chartInstance->c13_presentTicks;
}

static void disable_c13_E33_VCU_simulink(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c13_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ /
    0.05 + 0.5);
  chartInstance->c13_elapsedTicks = chartInstance->c13_presentTicks -
    chartInstance->c13_previousTicks;
  chartInstance->c13_previousTicks = chartInstance->c13_presentTicks;
  if ((uint32_T)chartInstance->c13_temporalCounter_i1 +
      chartInstance->c13_elapsedTicks <= 63U) {
    chartInstance->c13_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c13_temporalCounter_i1 + chartInstance->c13_elapsedTicks);
  } else {
    chartInstance->c13_temporalCounter_i1 = 63U;
  }
}

static void c13_update_debugger_state_c13_E33_VCU_simulink
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  uint32_T c13_prevAniVal;
  c13_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c13_is_active_c13_E33_VCU_simulink == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 7U, chartInstance->c13_sfEvent);
  }

  if (chartInstance->c13_is_c13_E33_VCU_simulink == c13_IN_DCDC_MR) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c13_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c13_sfEvent);
  }

  if (chartInstance->c13_is_DCDC_MR == c13_IN_OFF) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
  }

  if (chartInstance->c13_is_DCDC_MR == c13_IN_ON) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c13_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c13_sfEvent);
  }

  _SFD_SET_ANIMATION(c13_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c13_E33_VCU_simulink
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  boolean_T c13_hoistedGlobal;
  boolean_T c13_u;
  const mxArray *c13_b_y = NULL;
  uint8_T c13_b_hoistedGlobal;
  uint8_T c13_b_u;
  const mxArray *c13_c_y = NULL;
  uint8_T c13_c_hoistedGlobal;
  uint8_T c13_c_u;
  const mxArray *c13_d_y = NULL;
  uint8_T c13_d_hoistedGlobal;
  uint8_T c13_d_u;
  const mxArray *c13_e_y = NULL;
  uint8_T c13_e_hoistedGlobal;
  uint8_T c13_e_u;
  const mxArray *c13_f_y = NULL;
  uint32_T c13_f_hoistedGlobal;
  uint32_T c13_f_u;
  const mxArray *c13_g_y = NULL;
  boolean_T *c13_DCDC_ON;
  c13_DCDC_ON = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellmatrix(6, 1), false);
  c13_hoistedGlobal = *c13_DCDC_ON;
  c13_u = c13_hoistedGlobal;
  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", &c13_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_b_hoistedGlobal = chartInstance->c13_is_active_c13_E33_VCU_simulink;
  c13_b_u = c13_b_hoistedGlobal;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 1, c13_c_y);
  c13_c_hoistedGlobal = chartInstance->c13_is_c13_E33_VCU_simulink;
  c13_c_u = c13_c_hoistedGlobal;
  c13_d_y = NULL;
  sf_mex_assign(&c13_d_y, sf_mex_create("y", &c13_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 2, c13_d_y);
  c13_d_hoistedGlobal = chartInstance->c13_is_DCDC_MR;
  c13_d_u = c13_d_hoistedGlobal;
  c13_e_y = NULL;
  sf_mex_assign(&c13_e_y, sf_mex_create("y", &c13_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 3, c13_e_y);
  c13_e_hoistedGlobal = chartInstance->c13_temporalCounter_i1;
  c13_e_u = c13_e_hoistedGlobal;
  c13_f_y = NULL;
  sf_mex_assign(&c13_f_y, sf_mex_create("y", &c13_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 4, c13_f_y);
  c13_f_hoistedGlobal = chartInstance->c13_previousTicks;
  c13_f_u = c13_f_hoistedGlobal;
  c13_g_y = NULL;
  sf_mex_assign(&c13_g_y, sf_mex_create("y", &c13_f_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c13_y, 5, c13_g_y);
  sf_mex_assign(&c13_st, c13_y, false);
  return c13_st;
}

static void set_sim_state_c13_E33_VCU_simulink
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance, const mxArray *c13_st)
{
  const mxArray *c13_u;
  boolean_T *c13_DCDC_ON;
  c13_DCDC_ON = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_u = sf_mex_dup(c13_st);
  *c13_DCDC_ON = c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c13_u, 0)), "DCDC_ON");
  chartInstance->c13_is_active_c13_E33_VCU_simulink = c13_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 1)),
     "is_active_c13_E33_VCU_simulink");
  chartInstance->c13_is_c13_E33_VCU_simulink = c13_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 2)),
     "is_c13_E33_VCU_simulink");
  chartInstance->c13_is_DCDC_MR = c13_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c13_u, 3)), "is_DCDC_MR");
  chartInstance->c13_temporalCounter_i1 = c13_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c13_u, 4)), "temporalCounter_i1");
  chartInstance->c13_previousTicks = c13_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c13_u, 5)), "previousTicks");
  sf_mex_assign(&chartInstance->c13_setSimStateSideEffectsInfo,
                c13_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c13_u, 6)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c13_u);
  chartInstance->c13_doSetSimStateSideEffects = 1U;
  c13_update_debugger_state_c13_E33_VCU_simulink(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void c13_set_sim_state_side_effects_c13_E33_VCU_simulink
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  if (chartInstance->c13_doSetSimStateSideEffects != 0) {
    if (chartInstance->c13_is_c13_E33_VCU_simulink == c13_IN_DCDC_MR) {
      chartInstance->c13_tp_DCDC_MR = 1U;
    } else {
      chartInstance->c13_tp_DCDC_MR = 0U;
    }

    if (chartInstance->c13_is_DCDC_MR == c13_IN_OFF) {
      chartInstance->c13_tp_OFF = 1U;
      if (sf_mex_sub(chartInstance->c13_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c13_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c13_tp_OFF = 0U;
    }

    if (chartInstance->c13_is_DCDC_MR == c13_IN_ON) {
      chartInstance->c13_tp_ON = 1U;
      if (sf_mex_sub(chartInstance->c13_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c13_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c13_tp_ON = 0U;
    }

    chartInstance->c13_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c13_E33_VCU_simulink(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c13_setSimStateSideEffectsInfo);
}

static void sf_gateway_c13_E33_VCU_simulink(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  uint32_T c13_debug_family_var_map[2];
  real_T c13_nargin = 0.0;
  real_T c13_nargout = 0.0;
  boolean_T c13_hoistedGlobal;
  boolean_T c13_u;
  const mxArray *c13_y = NULL;
  uint32_T c13_b_debug_family_var_map[3];
  real_T c13_b_nargin = 0.0;
  real_T c13_b_nargout = 1.0;
  boolean_T c13_out;
  real_T c13_c_nargin = 0.0;
  real_T c13_c_nargout = 1.0;
  boolean_T c13_b_out;
  boolean_T *c13_HV_ON;
  boolean_T *c13_DCDC_ON;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c13_DCDC_ON = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c13_HV_ON = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c13_set_sim_state_side_effects_c13_E33_VCU_simulink(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c13_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ /
    0.05 + 0.5);
  chartInstance->c13_elapsedTicks = chartInstance->c13_presentTicks -
    chartInstance->c13_previousTicks;
  chartInstance->c13_previousTicks = chartInstance->c13_presentTicks;
  if ((uint32_T)chartInstance->c13_temporalCounter_i1 +
      chartInstance->c13_elapsedTicks <= 63U) {
    chartInstance->c13_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c13_temporalCounter_i1 + chartInstance->c13_elapsedTicks);
  } else {
    chartInstance->c13_temporalCounter_i1 = 63U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c13_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c13_HV_ON, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c13_DCDC_ON, 1U);
  chartInstance->c13_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c13_sfEvent);
  if (chartInstance->c13_is_active_c13_E33_VCU_simulink == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 7U, chartInstance->c13_sfEvent);
    chartInstance->c13_is_active_c13_E33_VCU_simulink = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c13_sfEvent);
    chartInstance->c13_is_c13_E33_VCU_simulink = c13_IN_DCDC_MR;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c13_sfEvent);
    chartInstance->c13_tp_DCDC_MR = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c13_sfEvent);
    chartInstance->c13_is_DCDC_MR = c13_IN_OFF;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
    chartInstance->c13_temporalCounter_i1 = 0U;
    chartInstance->c13_tp_OFF = 1U;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c13_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c13_debug_family_names,
      c13_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargin, 0U, c13_sf_marshallOut,
      c13_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_nargout, 1U, c13_sf_marshallOut,
      c13_sf_marshallIn);
    *c13_DCDC_ON = (chartInstance->c13_is_DCDC_MR == c13_IN_ON);
    c13_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK((real_T)*c13_DCDC_ON, 1U);
    c13_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
    sf_mex_printf("%s =\\n", "DCDC_ON");
    c13_hoistedGlobal = *c13_DCDC_ON;
    c13_u = c13_hoistedGlobal;
    c13_y = NULL;
    sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 11, 0U, 0U, 0U, 0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c13_y);
    _SFD_SYMBOL_SCOPE_POP();
    switch (chartInstance->c13_is_DCDC_MR) {
     case c13_IN_OFF:
      CV_STATE_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c13_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c13_b_debug_family_names,
        c13_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_b_nargin, 0U, c13_sf_marshallOut,
        c13_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_b_nargout, 1U,
        c13_sf_marshallOut, c13_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_out, 2U, c13_b_sf_marshallOut,
        c13_b_sf_marshallIn);
      guard2 = false;
      if (CV_EML_COND(1, 0, 0, chartInstance->c13_temporalCounter_i1 >= 40)) {
        if (CV_EML_COND(1, 0, 1, *c13_HV_ON)) {
          CV_EML_MCDC(1, 0, 0, true);
          CV_EML_IF(1, 0, 0, true);
          c13_out = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }

      if (guard2 == true) {
        CV_EML_MCDC(1, 0, 0, false);
        CV_EML_IF(1, 0, 0, false);
        c13_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c13_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
        chartInstance->c13_tp_OFF = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
        chartInstance->c13_is_DCDC_MR = c13_IN_ON;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c13_sfEvent);
        chartInstance->c13_temporalCounter_i1 = 0U;
        chartInstance->c13_tp_ON = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c13_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c13_sfEvent);
      break;

     case c13_IN_ON:
      CV_STATE_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c13_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c13_c_debug_family_names,
        c13_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_c_nargin, 0U, c13_sf_marshallOut,
        c13_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_c_nargout, 1U,
        c13_sf_marshallOut, c13_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c13_b_out, 2U, c13_b_sf_marshallOut,
        c13_b_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(2, 0, 0, chartInstance->c13_temporalCounter_i1 >= 40)) {
        if (!CV_EML_COND(2, 0, 1, *c13_HV_ON)) {
          CV_EML_MCDC(2, 0, 0, true);
          CV_EML_IF(2, 0, 0, true);
          c13_b_out = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(2, 0, 0, false);
        CV_EML_IF(2, 0, 0, false);
        c13_b_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c13_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c13_sfEvent);
        chartInstance->c13_tp_ON = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c13_sfEvent);
        chartInstance->c13_is_DCDC_MR = c13_IN_OFF;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
        chartInstance->c13_temporalCounter_i1 = 0U;
        chartInstance->c13_tp_OFF = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c13_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c13_sfEvent);
      break;

     default:
      CV_STATE_EVAL(0, 0, 0);
      chartInstance->c13_is_DCDC_MR = c13_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c13_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c13_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c13_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_E33_VCU_simulinkMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc13_E33_VCU_simulink
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber, uint32_T c13_instanceNumber)
{
  (void)c13_machineNumber;
  (void)c13_chartNumber;
  (void)c13_instanceNumber;
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc13_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static real_T c13_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d0, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_nargout;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc13_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c13_nargout = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_nargout),
    &c13_thisId);
  sf_mex_destroy(&c13_nargout);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  boolean_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc13_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(boolean_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static boolean_T c13_b_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_sf_internal_predicateOutput, const char_T
  *c13_identifier)
{
  boolean_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_sf_internal_predicateOutput), &c13_thisId);
  sf_mex_destroy(&c13_sf_internal_predicateOutput);
  return c13_y;
}

static boolean_T c13_c_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  boolean_T c13_y;
  boolean_T c13_b0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_b0, 1, 11, 0U, 0, 0U, 0);
  c13_y = c13_b0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_sf_internal_predicateOutput;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  boolean_T c13_y;
  SFc13_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc13_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c13_sf_internal_predicateOutput = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_sf_internal_predicateOutput), &c13_thisId);
  sf_mex_destroy(&c13_sf_internal_predicateOutput);
  *(boolean_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

const mxArray *sf_c13_E33_VCU_simulink_get_eml_resolved_functions_info(void)
{
  const mxArray *c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  sf_mex_assign(&c13_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c13_nameCaptureInfo;
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc13_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static int32_T c13_d_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
  int32_T c13_i0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i0, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc13_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c13_b_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_b_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  uint8_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc13_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(uint8_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, false);
  return c13_mxArrayOutData;
}

static uint8_T c13_e_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_b_tp_DCDC_MR, const char_T *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_tp_DCDC_MR),
    &c13_thisId);
  sf_mex_destroy(&c13_b_tp_DCDC_MR);
  return c13_y;
}

static uint8_T c13_f_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_tp_DCDC_MR;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  uint8_T c13_y;
  SFc13_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc13_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c13_b_tp_DCDC_MR = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_tp_DCDC_MR),
    &c13_thisId);
  sf_mex_destroy(&c13_b_tp_DCDC_MR);
  *(uint8_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static uint32_T c13_g_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_b_previousTicks, const char_T
  *c13_identifier)
{
  uint32_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_previousTicks),
    &c13_thisId);
  sf_mex_destroy(&c13_b_previousTicks);
  return c13_y;
}

static uint32_T c13_h_emlrt_marshallIn(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint32_T c13_y;
  uint32_T c13_u1;
  (void)chartInstance;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u1, 1, 7, 0U, 0, 0U, 0);
  c13_y = c13_u1;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static const mxArray *c13_i_emlrt_marshallIn
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance, const mxArray
   *c13_b_setSimStateSideEffectsInfo, const char_T *c13_identifier)
{
  const mxArray *c13_y = NULL;
  emlrtMsgIdentifier c13_thisId;
  c13_y = NULL;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  sf_mex_assign(&c13_y, c13_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_setSimStateSideEffectsInfo), &c13_thisId), false);
  sf_mex_destroy(&c13_b_setSimStateSideEffectsInfo);
  return c13_y;
}

static const mxArray *c13_j_emlrt_marshallIn
  (SFc13_E33_VCU_simulinkInstanceStruct *chartInstance, const mxArray *c13_u,
   const emlrtMsgIdentifier *c13_parentId)
{
  const mxArray *c13_y = NULL;
  (void)chartInstance;
  (void)c13_parentId;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_duplicatearraysafe(&c13_u), false);
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_updateDataWrittenToVector(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance, uint32_T c13_vectorIndex)
{
  (void)chartInstance;
  c13_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c13_vectorIndex, 0, 0, 1, 0)] = true;
}

static void c13_errorIfDataNotWrittenToFcn(SFc13_E33_VCU_simulinkInstanceStruct *
  chartInstance, uint32_T c13_vectorIndex, uint32_T c13_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c13_dataNumber, c13_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c13_vectorIndex, 0, 0, 1,
    0)]);
}

static void init_dsm_address_info(SFc13_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c13_E33_VCU_simulink_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1605995764U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(630294707U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3513775770U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3508328644U);
}

mxArray *sf_c13_E33_VCU_simulink_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("bjeHjkYvM6F6bWG6YrOS5C");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c13_E33_VCU_simulink_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c13_E33_VCU_simulink_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c13_E33_VCU_simulink(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[5],T\"DCDC_ON\",},{M[8],M[0],T\"is_active_c13_E33_VCU_simulink\",},{M[9],M[0],T\"is_c13_E33_VCU_simulink\",},{M[9],M[1],T\"is_DCDC_MR\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x2[2 3],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_E33_VCU_simulink_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_E33_VCU_simulinkInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc13_E33_VCU_simulinkInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _E33_VCU_simulinkMachineNumber_,
           13,
           3,
           3,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_E33_VCU_simulinkMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_E33_VCU_simulinkMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _E33_VCU_simulinkMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"HV_ON");
          _SFD_SET_DATA_PROPS(1,2,0,1,"DCDC_ON");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,2);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,20,1,20);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 13, 20 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,20,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(2,0,0,1,21,1,21);

        {
          static int condStart[] = { 1, 16 };

          static int condEnd[] = { 13, 21 };

          static int pfixExpr[] = { 0, 1, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(2,0,0,1,21,2,0,&(condStart[0]),&(condEnd[0]),4,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)
          c13_b_sf_marshallIn);

        {
          boolean_T *c13_HV_ON;
          boolean_T *c13_DCDC_ON;
          c13_DCDC_ON = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c13_HV_ON = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c13_HV_ON);
          _SFD_SET_DATA_VALUE_PTR(1U, c13_DCDC_ON);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _E33_VCU_simulinkMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "ZLsxr0kqaCgdGYfiEo801G";
}

static void sf_opaque_initialize_c13_E33_VCU_simulink(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc13_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c13_E33_VCU_simulink((SFc13_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
  initialize_c13_E33_VCU_simulink((SFc13_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c13_E33_VCU_simulink(void *chartInstanceVar)
{
  enable_c13_E33_VCU_simulink((SFc13_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c13_E33_VCU_simulink(void *chartInstanceVar)
{
  disable_c13_E33_VCU_simulink((SFc13_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c13_E33_VCU_simulink(void *chartInstanceVar)
{
  sf_gateway_c13_E33_VCU_simulink((SFc13_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c13_E33_VCU_simulink(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c13_E33_VCU_simulink
    ((SFc13_E33_VCU_simulinkInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_E33_VCU_simulink();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c13_E33_VCU_simulink(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c13_E33_VCU_simulink();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c13_E33_VCU_simulink((SFc13_E33_VCU_simulinkInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c13_E33_VCU_simulink(SimStruct* S)
{
  return sf_internal_get_sim_state_c13_E33_VCU_simulink(S);
}

static void sf_opaque_set_sim_state_c13_E33_VCU_simulink(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c13_E33_VCU_simulink(S, st);
}

static void sf_opaque_terminate_c13_E33_VCU_simulink(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_E33_VCU_simulinkInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_E33_VCU_simulink_optimization_info();
    }

    finalize_c13_E33_VCU_simulink((SFc13_E33_VCU_simulinkInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc13_E33_VCU_simulink((SFc13_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_E33_VCU_simulink(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c13_E33_VCU_simulink((SFc13_E33_VCU_simulinkInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c13_E33_VCU_simulink(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_E33_VCU_simulink_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,13,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,13,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,13);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1554567660U));
  ssSetChecksum1(S,(1364127980U));
  ssSetChecksum2(S,(346375889U));
  ssSetChecksum3(S,(3026518227U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c13_E33_VCU_simulink(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c13_E33_VCU_simulink(SimStruct *S)
{
  SFc13_E33_VCU_simulinkInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc13_E33_VCU_simulinkInstanceStruct *)utMalloc(sizeof
    (SFc13_E33_VCU_simulinkInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc13_E33_VCU_simulinkInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c13_E33_VCU_simulink;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c13_E33_VCU_simulink;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c13_E33_VCU_simulink;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c13_E33_VCU_simulink;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c13_E33_VCU_simulink;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c13_E33_VCU_simulink;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c13_E33_VCU_simulink;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_E33_VCU_simulink;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_E33_VCU_simulink;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_E33_VCU_simulink;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c13_E33_VCU_simulink;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c13_E33_VCU_simulink_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_E33_VCU_simulink(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_E33_VCU_simulink(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_E33_VCU_simulink(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_E33_VCU_simulink_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
