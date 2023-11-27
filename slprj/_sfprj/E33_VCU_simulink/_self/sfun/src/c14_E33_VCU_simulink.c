/* Include files */

#include <stddef.h>
#include "blas.h"
#include "E33_VCU_simulink_sfun.h"
#include "c14_E33_VCU_simulink.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "E33_VCU_simulink_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c14_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c14_IN_LEDStat                 ((uint8_T)1U)
#define c14_IN_Init                    ((uint8_T)1U)
#define c14_IN_PumpTest                ((uint8_T)2U)
#define c14_IN_Ready_to_close          ((uint8_T)3U)
#define c14_IN_Run                     ((uint8_T)4U)
#define c14_IN_Stand                   ((uint8_T)5U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c14_debug_family_names[2] = { "nargin", "nargout" };

static const char * c14_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c14_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c14_d_debug_family_names[5] = { "nargin", "nargout",
  "elapsed_sec", "period", "DutyCyc" };

static const char * c14_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c14_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c14_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c14_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c14_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c14_j_debug_family_names[2] = { "nargin", "nargout" };

static const char * c14_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c14_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c14_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c14_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c14_dataWrittenToVector[2];

/* Function Declarations */
static void initialize_c14_E33_VCU_simulink(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void initialize_params_c14_E33_VCU_simulink
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance);
static void enable_c14_E33_VCU_simulink(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void disable_c14_E33_VCU_simulink(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void c14_update_debugger_state_c14_E33_VCU_simulink
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c14_E33_VCU_simulink
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance);
static void set_sim_state_c14_E33_VCU_simulink
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance, const mxArray *c14_st);
static void c14_set_sim_state_side_effects_c14_E33_VCU_simulink
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance);
static void finalize_c14_E33_VCU_simulink(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void sf_gateway_c14_E33_VCU_simulink(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void c14_chartstep_c14_E33_VCU_simulink
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance);
static void initSimStructsc14_E33_VCU_simulink
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber);
static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static real_T c14_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static boolean_T c14_b_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static void c14_info_helper(const mxArray **c14_info);
static const mxArray *c14_emlrt_marshallOut(const char * c14_u);
static const mxArray *c14_b_emlrt_marshallOut(const uint32_T c14_u);
static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static int32_T c14_c_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static uint8_T c14_d_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_b_tp_LEDStat, const char_T *c14_identifier);
static uint8_T c14_e_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData);
static uint16_T c14_f_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_FanDutyCycl, const char_T *c14_identifier);
static uint16_T c14_g_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static void c14_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData);
static uint32_T c14_h_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_b_temporalCounter_i1, const char_T
  *c14_identifier);
static uint32_T c14_i_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId);
static const mxArray *c14_j_emlrt_marshallIn
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance, const mxArray
   *c14_b_setSimStateSideEffectsInfo, const char_T *c14_identifier);
static const mxArray *c14_k_emlrt_marshallIn
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance, const mxArray *c14_u,
   const emlrtMsgIdentifier *c14_parentId);
static void c14_updateDataWrittenToVector(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, uint32_T c14_vectorIndex);
static void c14_errorIfDataNotWrittenToFcn(SFc14_E33_VCU_simulinkInstanceStruct *
  chartInstance, uint32_T c14_vectorIndex, uint32_T c14_dataNumber);
static void init_dsm_address_info(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c14_E33_VCU_simulink(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  chartInstance->c14_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c14_doSetSimStateSideEffects = 0U;
  chartInstance->c14_setSimStateSideEffectsInfo = NULL;
  chartInstance->c14_is_LEDStat = c14_IN_NO_ACTIVE_CHILD;
  chartInstance->c14_tp_LEDStat = 0U;
  chartInstance->c14_tp_Init = 0U;
  chartInstance->c14_temporalCounter_i1 = 0U;
  chartInstance->c14_tp_PumpTest = 0U;
  chartInstance->c14_temporalCounter_i1 = 0U;
  chartInstance->c14_tp_Ready_to_close = 0U;
  chartInstance->c14_temporalCounter_i1 = 0U;
  chartInstance->c14_tp_Run = 0U;
  chartInstance->c14_tp_Stand = 0U;
  chartInstance->c14_temporalCounter_i1 = 0U;
  chartInstance->c14_is_active_c14_E33_VCU_simulink = 0U;
  chartInstance->c14_is_c14_E33_VCU_simulink = c14_IN_NO_ACTIVE_CHILD;
  chartInstance->c14_presentTicks = 0U;
  chartInstance->c14_elapsedTicks = 0U;
  chartInstance->c14_previousTicks = 0U;
}

static void initialize_params_c14_E33_VCU_simulink
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c14_E33_VCU_simulink(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c14_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ /
    0.05 + 0.5);
  chartInstance->c14_previousTicks = chartInstance->c14_presentTicks;
}

static void disable_c14_E33_VCU_simulink(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c14_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ /
    0.05 + 0.5);
  chartInstance->c14_elapsedTicks = chartInstance->c14_presentTicks -
    chartInstance->c14_previousTicks;
  chartInstance->c14_previousTicks = chartInstance->c14_presentTicks;
  chartInstance->c14_temporalCounter_i1 += chartInstance->c14_elapsedTicks;
}

static void c14_update_debugger_state_c14_E33_VCU_simulink
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  uint32_T c14_prevAniVal;
  c14_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c14_is_active_c14_E33_VCU_simulink == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 8U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_c14_E33_VCU_simulink == c14_IN_LEDStat) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_LEDStat == c14_IN_Run) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_LEDStat == c14_IN_Init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_LEDStat == c14_IN_Ready_to_close) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_LEDStat == c14_IN_PumpTest) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c14_sfEvent);
  }

  if (chartInstance->c14_is_LEDStat == c14_IN_Stand) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c14_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c14_sfEvent);
  }

  _SFD_SET_ANIMATION(c14_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c14_E33_VCU_simulink
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  const mxArray *c14_st;
  const mxArray *c14_y = NULL;
  uint16_T c14_hoistedGlobal;
  uint16_T c14_u;
  const mxArray *c14_b_y = NULL;
  uint8_T c14_b_hoistedGlobal;
  uint8_T c14_b_u;
  const mxArray *c14_c_y = NULL;
  uint8_T c14_c_hoistedGlobal;
  uint8_T c14_c_u;
  const mxArray *c14_d_y = NULL;
  uint8_T c14_d_hoistedGlobal;
  uint8_T c14_d_u;
  const mxArray *c14_e_y = NULL;
  uint32_T c14_e_hoistedGlobal;
  uint32_T c14_e_u;
  const mxArray *c14_f_y = NULL;
  uint32_T c14_f_hoistedGlobal;
  uint32_T c14_f_u;
  const mxArray *c14_g_y = NULL;
  uint16_T *c14_FanDutyCycl;
  c14_FanDutyCycl = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c14_st = NULL;
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellmatrix(6, 1), false);
  c14_hoistedGlobal = *c14_FanDutyCycl;
  c14_u = c14_hoistedGlobal;
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 0, c14_b_y);
  c14_b_hoistedGlobal = chartInstance->c14_is_active_c14_E33_VCU_simulink;
  c14_b_u = c14_b_hoistedGlobal;
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 1, c14_c_y);
  c14_c_hoistedGlobal = chartInstance->c14_is_c14_E33_VCU_simulink;
  c14_c_u = c14_c_hoistedGlobal;
  c14_d_y = NULL;
  sf_mex_assign(&c14_d_y, sf_mex_create("y", &c14_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 2, c14_d_y);
  c14_d_hoistedGlobal = chartInstance->c14_is_LEDStat;
  c14_d_u = c14_d_hoistedGlobal;
  c14_e_y = NULL;
  sf_mex_assign(&c14_e_y, sf_mex_create("y", &c14_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 3, c14_e_y);
  c14_e_hoistedGlobal = chartInstance->c14_temporalCounter_i1;
  c14_e_u = c14_e_hoistedGlobal;
  c14_f_y = NULL;
  sf_mex_assign(&c14_f_y, sf_mex_create("y", &c14_e_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 4, c14_f_y);
  c14_f_hoistedGlobal = chartInstance->c14_previousTicks;
  c14_f_u = c14_f_hoistedGlobal;
  c14_g_y = NULL;
  sf_mex_assign(&c14_g_y, sf_mex_create("y", &c14_f_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c14_y, 5, c14_g_y);
  sf_mex_assign(&c14_st, c14_y, false);
  return c14_st;
}

static void set_sim_state_c14_E33_VCU_simulink
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance, const mxArray *c14_st)
{
  const mxArray *c14_u;
  uint16_T *c14_FanDutyCycl;
  c14_FanDutyCycl = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c14_u = sf_mex_dup(c14_st);
  *c14_FanDutyCycl = c14_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c14_u, 0)), "FanDutyCycl");
  chartInstance->c14_is_active_c14_E33_VCU_simulink = c14_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 1)),
     "is_active_c14_E33_VCU_simulink");
  chartInstance->c14_is_c14_E33_VCU_simulink = c14_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 2)),
     "is_c14_E33_VCU_simulink");
  chartInstance->c14_is_LEDStat = c14_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c14_u, 3)), "is_LEDStat");
  chartInstance->c14_temporalCounter_i1 = c14_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c14_u, 4)), "temporalCounter_i1");
  chartInstance->c14_previousTicks = c14_h_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c14_u, 5)), "previousTicks");
  sf_mex_assign(&chartInstance->c14_setSimStateSideEffectsInfo,
                c14_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c14_u, 6)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c14_u);
  chartInstance->c14_doSetSimStateSideEffects = 1U;
  c14_update_debugger_state_c14_E33_VCU_simulink(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void c14_set_sim_state_side_effects_c14_E33_VCU_simulink
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  if (chartInstance->c14_doSetSimStateSideEffects != 0) {
    if (chartInstance->c14_is_c14_E33_VCU_simulink == c14_IN_LEDStat) {
      chartInstance->c14_tp_LEDStat = 1U;
    } else {
      chartInstance->c14_tp_LEDStat = 0U;
    }

    if (chartInstance->c14_is_LEDStat == c14_IN_Init) {
      chartInstance->c14_tp_Init = 1U;
      if (sf_mex_sub(chartInstance->c14_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 3) == 0.0) {
        chartInstance->c14_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c14_tp_Init = 0U;
    }

    if (chartInstance->c14_is_LEDStat == c14_IN_PumpTest) {
      chartInstance->c14_tp_PumpTest = 1U;
      if (sf_mex_sub(chartInstance->c14_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c14_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c14_tp_PumpTest = 0U;
    }

    if (chartInstance->c14_is_LEDStat == c14_IN_Ready_to_close) {
      chartInstance->c14_tp_Ready_to_close = 1U;
      if (sf_mex_sub(chartInstance->c14_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c14_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c14_tp_Ready_to_close = 0U;
    }

    if (chartInstance->c14_is_LEDStat == c14_IN_Run) {
      chartInstance->c14_tp_Run = 1U;
    } else {
      chartInstance->c14_tp_Run = 0U;
    }

    if (chartInstance->c14_is_LEDStat == c14_IN_Stand) {
      chartInstance->c14_tp_Stand = 1U;
      if (sf_mex_sub(chartInstance->c14_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c14_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c14_tp_Stand = 0U;
    }

    chartInstance->c14_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c14_E33_VCU_simulink(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c14_setSimStateSideEffectsInfo);
}

static void sf_gateway_c14_E33_VCU_simulink(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  uint16_T *c14_FanPwr;
  uint16_T *c14_FanDutyCycl;
  boolean_T *c14_IsPrechg;
  boolean_T *c14_IsRun;
  c14_IsRun = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c14_IsPrechg = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c14_FanDutyCycl = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c14_FanPwr = (uint16_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c14_set_sim_state_side_effects_c14_E33_VCU_simulink(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c14_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ /
    0.05 + 0.5);
  chartInstance->c14_elapsedTicks = chartInstance->c14_presentTicks -
    chartInstance->c14_previousTicks;
  chartInstance->c14_previousTicks = chartInstance->c14_presentTicks;
  chartInstance->c14_temporalCounter_i1 += chartInstance->c14_elapsedTicks;
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c14_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_FanPwr, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_FanDutyCycl, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_IsPrechg, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c14_IsRun, 3U);
  chartInstance->c14_sfEvent = CALL_EVENT;
  c14_chartstep_c14_E33_VCU_simulink(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_E33_VCU_simulinkMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c14_chartstep_c14_E33_VCU_simulink
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  uint32_T c14_debug_family_var_map[3];
  real_T c14_nargin = 0.0;
  real_T c14_nargout = 1.0;
  boolean_T c14_out;
  uint32_T c14_b_debug_family_var_map[2];
  real_T c14_b_nargin = 0.0;
  real_T c14_b_nargout = 0.0;
  uint16_T c14_hoistedGlobal;
  uint16_T c14_u;
  const mxArray *c14_y = NULL;
  real_T c14_c_nargin = 0.0;
  real_T c14_c_nargout = 1.0;
  boolean_T c14_b_out;
  real_T c14_d_nargin = 0.0;
  real_T c14_d_nargout = 0.0;
  uint16_T c14_b_hoistedGlobal;
  uint16_T c14_b_u;
  const mxArray *c14_b_y = NULL;
  real_T c14_e_nargin = 0.0;
  real_T c14_e_nargout = 1.0;
  boolean_T c14_c_out;
  real_T c14_f_nargin = 0.0;
  real_T c14_f_nargout = 0.0;
  uint16_T c14_c_hoistedGlobal;
  uint16_T c14_c_u;
  const mxArray *c14_c_y = NULL;
  real_T c14_g_nargin = 0.0;
  real_T c14_g_nargout = 1.0;
  boolean_T c14_d_out;
  real_T c14_h_nargin = 0.0;
  real_T c14_h_nargout = 0.0;
  uint16_T *c14_FanDutyCycl;
  boolean_T *c14_IsPrechg;
  uint16_T *c14_FanPwr;
  boolean_T *c14_IsRun;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c14_IsRun = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c14_IsPrechg = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c14_FanDutyCycl = (uint16_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c14_FanPwr = (uint16_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c14_sfEvent);
  if (chartInstance->c14_is_active_c14_E33_VCU_simulink == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 8U, chartInstance->c14_sfEvent);
    chartInstance->c14_is_active_c14_E33_VCU_simulink = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c14_sfEvent);
    chartInstance->c14_is_c14_E33_VCU_simulink = c14_IN_LEDStat;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c14_sfEvent);
    chartInstance->c14_tp_LEDStat = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c14_sfEvent);
    chartInstance->c14_is_LEDStat = c14_IN_Init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c14_sfEvent);
    chartInstance->c14_temporalCounter_i1 = 0U;
    chartInstance->c14_tp_Init = 1U;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c14_sfEvent);
    switch (chartInstance->c14_is_LEDStat) {
     case c14_IN_Init:
      CV_STATE_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c14_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c14_h_debug_family_names,
        c14_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargin, 0U, c14_sf_marshallOut,
        c14_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_nargout, 1U, c14_sf_marshallOut,
        c14_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_out, 2U, c14_b_sf_marshallOut,
        c14_b_sf_marshallIn);
      c14_out = CV_EML_IF(2, 0, 0, chartInstance->c14_temporalCounter_i1 >= 20U);
      _SFD_SYMBOL_SCOPE_POP();
      if (c14_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c14_sfEvent);
        chartInstance->c14_tp_Init = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c14_sfEvent);
        chartInstance->c14_is_LEDStat = c14_IN_PumpTest;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c14_sfEvent);
        chartInstance->c14_temporalCounter_i1 = 0U;
        chartInstance->c14_tp_PumpTest = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c14_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c14_sfEvent);
      break;

     case c14_IN_PumpTest:
      CV_STATE_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c14_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c14_j_debug_family_names,
        c14_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_b_nargin, 0U, c14_sf_marshallOut,
        c14_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_b_nargout, 1U,
        c14_sf_marshallOut, c14_sf_marshallIn);
      *c14_FanDutyCycl = 0U;
      c14_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK((real_T)*c14_FanDutyCycl, 1U);
      c14_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
      sf_mex_printf("%s =\\n", "FanDutyCycl");
      c14_hoistedGlobal = *c14_FanDutyCycl;
      c14_u = c14_hoistedGlobal;
      c14_y = NULL;
      sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 5, 0U, 0U, 0U, 0), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c14_y);
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c14_tp_PumpTest = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c14_sfEvent);
      chartInstance->c14_is_LEDStat = c14_IN_Stand;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c14_sfEvent);
      chartInstance->c14_temporalCounter_i1 = 0U;
      chartInstance->c14_tp_Stand = 1U;
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c14_sfEvent);
      break;

     case c14_IN_Ready_to_close:
      CV_STATE_EVAL(0, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   chartInstance->c14_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c14_i_debug_family_names,
        c14_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_c_nargin, 0U, c14_sf_marshallOut,
        c14_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_c_nargout, 1U,
        c14_sf_marshallOut, c14_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_b_out, 2U, c14_b_sf_marshallOut,
        c14_b_sf_marshallIn);
      guard2 = false;
      if (CV_EML_COND(5, 0, 0, chartInstance->c14_temporalCounter_i1 >= 600U)) {
        guard2 = true;
      } else if (CV_EML_COND(5, 0, 1, *c14_IsPrechg)) {
        guard2 = true;
      } else {
        CV_EML_MCDC(5, 0, 0, false);
        CV_EML_IF(5, 0, 0, false);
        c14_b_out = false;
      }

      if (guard2 == true) {
        CV_EML_MCDC(5, 0, 0, true);
        CV_EML_IF(5, 0, 0, true);
        c14_b_out = true;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c14_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c14_sfEvent);
        chartInstance->c14_tp_Ready_to_close = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c14_sfEvent);
        chartInstance->c14_is_LEDStat = c14_IN_Stand;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c14_sfEvent);
        chartInstance->c14_temporalCounter_i1 = 0U;
        chartInstance->c14_tp_Stand = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c14_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c14_b_debug_family_names,
          c14_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_d_nargin, 0U,
          c14_sf_marshallOut, c14_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_d_nargout, 1U,
          c14_sf_marshallOut, c14_sf_marshallIn);
        *c14_FanDutyCycl = *c14_FanPwr;
        c14_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK((real_T)*c14_FanDutyCycl, 1U);
        c14_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
        sf_mex_printf("%s =\\n", "FanDutyCycl");
        c14_b_hoistedGlobal = *c14_FanDutyCycl;
        c14_b_u = c14_b_hoistedGlobal;
        c14_b_y = NULL;
        sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_b_u, 5, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c14_b_y);
        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c14_sfEvent);
      break;

     case c14_IN_Run:
      CV_STATE_EVAL(0, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c14_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c14_g_debug_family_names,
        c14_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_e_nargin, 0U, c14_sf_marshallOut,
        c14_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_e_nargout, 1U,
        c14_sf_marshallOut, c14_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_c_out, 2U, c14_b_sf_marshallOut,
        c14_b_sf_marshallIn);
      c14_c_out = CV_EML_IF(4, 0, 0, CV_EML_MCDC(4, 0, 0, !CV_EML_COND(4, 0, 0, *
        c14_IsRun)));
      _SFD_SYMBOL_SCOPE_POP();
      if (c14_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c14_sfEvent);
        chartInstance->c14_tp_Run = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c14_sfEvent);
        chartInstance->c14_is_LEDStat = c14_IN_Ready_to_close;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c14_sfEvent);
        chartInstance->c14_temporalCounter_i1 = 0U;
        chartInstance->c14_tp_Ready_to_close = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                     chartInstance->c14_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c14_debug_family_names,
          c14_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_f_nargin, 0U,
          c14_sf_marshallOut, c14_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_f_nargout, 1U,
          c14_sf_marshallOut, c14_sf_marshallIn);
        *c14_FanDutyCycl = *c14_FanPwr;
        c14_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK((real_T)*c14_FanDutyCycl, 1U);
        c14_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U);
        sf_mex_printf("%s =\\n", "FanDutyCycl");
        c14_c_hoistedGlobal = *c14_FanDutyCycl;
        c14_c_u = c14_c_hoistedGlobal;
        c14_c_y = NULL;
        sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_c_u, 5, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14,
                          c14_c_y);
        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c14_sfEvent);
      break;

     case c14_IN_Stand:
      CV_STATE_EVAL(0, 0, 5);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c14_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c14_f_debug_family_names,
        c14_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_g_nargin, 0U, c14_sf_marshallOut,
        c14_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_g_nargout, 1U,
        c14_sf_marshallOut, c14_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_d_out, 2U, c14_b_sf_marshallOut,
        c14_b_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(3, 0, 0, *c14_IsRun)) {
        guard1 = true;
      } else if (CV_EML_COND(3, 0, 1, chartInstance->c14_temporalCounter_i1 >=
                             60U)) {
        guard1 = true;
      } else {
        CV_EML_MCDC(3, 0, 0, false);
        CV_EML_IF(3, 0, 0, false);
        c14_d_out = false;
      }

      if (guard1 == true) {
        CV_EML_MCDC(3, 0, 0, true);
        CV_EML_IF(3, 0, 0, true);
        c14_d_out = true;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c14_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c14_sfEvent);
        chartInstance->c14_tp_Stand = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c14_sfEvent);
        chartInstance->c14_is_LEDStat = c14_IN_Run;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c14_sfEvent);
        chartInstance->c14_tp_Run = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     chartInstance->c14_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c14_e_debug_family_names,
          c14_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_h_nargin, 0U,
          c14_sf_marshallOut, c14_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c14_h_nargout, 1U,
          c14_sf_marshallOut, c14_sf_marshallIn);
        *c14_FanDutyCycl = 0U;
        c14_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK((real_T)*c14_FanDutyCycl, 1U);
        _SFD_SYMBOL_SCOPE_POP();
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c14_sfEvent);
      break;

     default:
      CV_STATE_EVAL(0, 0, 0);
      chartInstance->c14_is_LEDStat = c14_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c14_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c14_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c14_sfEvent);
}

static void initSimStructsc14_E33_VCU_simulink
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber, uint32_T c14_instanceNumber)
{
  (void)c14_machineNumber;
  (void)c14_chartNumber;
  (void)c14_instanceNumber;
}

static const mxArray *c14_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  real_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc14_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(real_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static real_T c14_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  real_T c14_y;
  real_T c14_d0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_d0, 1, 0, 0U, 0, 0U, 0);
  c14_y = c14_d0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_nargout;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  real_T c14_y;
  SFc14_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc14_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c14_nargout = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_nargout),
    &c14_thisId);
  sf_mex_destroy(&c14_nargout);
  *(real_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_b_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  boolean_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc14_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(boolean_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static boolean_T c14_b_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  boolean_T c14_y;
  boolean_T c14_b0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_b0, 1, 11, 0U, 0, 0U, 0);
  c14_y = c14_b0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_sf_internal_predicateOutput;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  boolean_T c14_y;
  SFc14_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc14_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c14_sf_internal_predicateOutput = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_sf_internal_predicateOutput), &c14_thisId);
  sf_mex_destroy(&c14_sf_internal_predicateOutput);
  *(boolean_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

const mxArray *sf_c14_E33_VCU_simulink_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo = NULL;
  c14_nameCaptureInfo = NULL;
  sf_mex_assign(&c14_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c14_info_helper(&c14_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c14_nameCaptureInfo);
  return c14_nameCaptureInfo;
}

static void c14_info_helper(const mxArray **c14_info)
{
  const mxArray *c14_rhs0 = NULL;
  const mxArray *c14_lhs0 = NULL;
  const mxArray *c14_rhs1 = NULL;
  const mxArray *c14_lhs1 = NULL;
  const mxArray *c14_rhs2 = NULL;
  const mxArray *c14_lhs2 = NULL;
  const mxArray *c14_rhs3 = NULL;
  const mxArray *c14_lhs3 = NULL;
  const mxArray *c14_rhs4 = NULL;
  const mxArray *c14_lhs4 = NULL;
  const mxArray *c14_rhs5 = NULL;
  const mxArray *c14_lhs5 = NULL;
  const mxArray *c14_rhs6 = NULL;
  const mxArray *c14_lhs6 = NULL;
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("rdivide"), "name", "name", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363688680U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c14_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1363689356U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c14_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1286797196U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c14_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_div"), "name", "name", 3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1375959088U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c14_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1389282720U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c14_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(""), "context", "context", 5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("sin"), "name", "name", 5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1343808786U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c14_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 6);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c14_info, c14_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(1286797136U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c14_info, c14_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c14_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c14_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c14_info, sf_mex_duplicatearraysafe(&c14_lhs6), "lhs", "lhs",
                  6);
  sf_mex_destroy(&c14_rhs0);
  sf_mex_destroy(&c14_lhs0);
  sf_mex_destroy(&c14_rhs1);
  sf_mex_destroy(&c14_lhs1);
  sf_mex_destroy(&c14_rhs2);
  sf_mex_destroy(&c14_lhs2);
  sf_mex_destroy(&c14_rhs3);
  sf_mex_destroy(&c14_lhs3);
  sf_mex_destroy(&c14_rhs4);
  sf_mex_destroy(&c14_lhs4);
  sf_mex_destroy(&c14_rhs5);
  sf_mex_destroy(&c14_lhs5);
  sf_mex_destroy(&c14_rhs6);
  sf_mex_destroy(&c14_lhs6);
}

static const mxArray *c14_emlrt_marshallOut(const char * c14_u)
{
  const mxArray *c14_y = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c14_u)), false);
  return c14_y;
}

static const mxArray *c14_b_emlrt_marshallOut(const uint32_T c14_u)
{
  const mxArray *c14_y = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 7, 0U, 0U, 0U, 0), false);
  return c14_y;
}

static const mxArray *c14_c_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  int32_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc14_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(int32_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static int32_T c14_c_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  int32_T c14_y;
  int32_T c14_i0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_i0, 1, 6, 0U, 0, 0U, 0);
  c14_y = c14_i0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_sfEvent;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  int32_T c14_y;
  SFc14_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc14_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c14_b_sfEvent = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_sfEvent),
    &c14_thisId);
  sf_mex_destroy(&c14_b_sfEvent);
  *(int32_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_d_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  uint8_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc14_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(uint8_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static uint8_T c14_d_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_b_tp_LEDStat, const char_T *c14_identifier)
{
  uint8_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_tp_LEDStat),
    &c14_thisId);
  sf_mex_destroy(&c14_b_tp_LEDStat);
  return c14_y;
}

static uint8_T c14_e_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint8_T c14_y;
  uint8_T c14_u0;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u0, 1, 3, 0U, 0, 0U, 0);
  c14_y = c14_u0;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_b_tp_LEDStat;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  uint8_T c14_y;
  SFc14_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc14_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c14_b_tp_LEDStat = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_b_tp_LEDStat),
    &c14_thisId);
  sf_mex_destroy(&c14_b_tp_LEDStat);
  *(uint8_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static const mxArray *c14_e_sf_marshallOut(void *chartInstanceVoid, void
  *c14_inData)
{
  const mxArray *c14_mxArrayOutData = NULL;
  uint16_T c14_u;
  const mxArray *c14_y = NULL;
  SFc14_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc14_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c14_mxArrayOutData = NULL;
  c14_u = *(uint16_T *)c14_inData;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", &c14_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c14_mxArrayOutData, c14_y, false);
  return c14_mxArrayOutData;
}

static uint16_T c14_f_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_FanDutyCycl, const char_T *c14_identifier)
{
  uint16_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_FanDutyCycl),
    &c14_thisId);
  sf_mex_destroy(&c14_FanDutyCycl);
  return c14_y;
}

static uint16_T c14_g_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint16_T c14_y;
  uint16_T c14_u1;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u1, 1, 5, 0U, 0, 0U, 0);
  c14_y = c14_u1;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c14_mxArrayInData, const char_T *c14_varName, void *c14_outData)
{
  const mxArray *c14_FanDutyCycl;
  const char_T *c14_identifier;
  emlrtMsgIdentifier c14_thisId;
  uint16_T c14_y;
  SFc14_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc14_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c14_FanDutyCycl = sf_mex_dup(c14_mxArrayInData);
  c14_identifier = c14_varName;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c14_FanDutyCycl),
    &c14_thisId);
  sf_mex_destroy(&c14_FanDutyCycl);
  *(uint16_T *)c14_outData = c14_y;
  sf_mex_destroy(&c14_mxArrayInData);
}

static uint32_T c14_h_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_b_temporalCounter_i1, const char_T
  *c14_identifier)
{
  uint32_T c14_y;
  emlrtMsgIdentifier c14_thisId;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  c14_y = c14_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_temporalCounter_i1), &c14_thisId);
  sf_mex_destroy(&c14_b_temporalCounter_i1);
  return c14_y;
}

static uint32_T c14_i_emlrt_marshallIn(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c14_u, const emlrtMsgIdentifier *c14_parentId)
{
  uint32_T c14_y;
  uint32_T c14_u2;
  (void)chartInstance;
  sf_mex_import(c14_parentId, sf_mex_dup(c14_u), &c14_u2, 1, 7, 0U, 0, 0U, 0);
  c14_y = c14_u2;
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static const mxArray *c14_j_emlrt_marshallIn
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance, const mxArray
   *c14_b_setSimStateSideEffectsInfo, const char_T *c14_identifier)
{
  const mxArray *c14_y = NULL;
  emlrtMsgIdentifier c14_thisId;
  c14_y = NULL;
  c14_thisId.fIdentifier = c14_identifier;
  c14_thisId.fParent = NULL;
  sf_mex_assign(&c14_y, c14_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c14_b_setSimStateSideEffectsInfo), &c14_thisId), false);
  sf_mex_destroy(&c14_b_setSimStateSideEffectsInfo);
  return c14_y;
}

static const mxArray *c14_k_emlrt_marshallIn
  (SFc14_E33_VCU_simulinkInstanceStruct *chartInstance, const mxArray *c14_u,
   const emlrtMsgIdentifier *c14_parentId)
{
  const mxArray *c14_y = NULL;
  (void)chartInstance;
  (void)c14_parentId;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_duplicatearraysafe(&c14_u), false);
  sf_mex_destroy(&c14_u);
  return c14_y;
}

static void c14_updateDataWrittenToVector(SFc14_E33_VCU_simulinkInstanceStruct
  *chartInstance, uint32_T c14_vectorIndex)
{
  (void)chartInstance;
  c14_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c14_vectorIndex, 0, 1, 1, 0)] = true;
}

static void c14_errorIfDataNotWrittenToFcn(SFc14_E33_VCU_simulinkInstanceStruct *
  chartInstance, uint32_T c14_vectorIndex, uint32_T c14_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c14_dataNumber, c14_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c14_vectorIndex, 0, 1, 1,
    0)]);
}

static void init_dsm_address_info(SFc14_E33_VCU_simulinkInstanceStruct
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

void sf_c14_E33_VCU_simulink_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(929512839U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2091057919U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2987111539U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3036171443U);
}

mxArray *sf_c14_E33_VCU_simulink_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("WkhUAWJEAFEAVamPKJ2x6D");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(5));
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

mxArray *sf_c14_E33_VCU_simulink_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c14_E33_VCU_simulink_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c14_E33_VCU_simulink(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[67],T\"FanDutyCycl\",},{M[8],M[0],T\"is_active_c14_E33_VCU_simulink\",},{M[9],M[0],T\"is_c14_E33_VCU_simulink\",},{M[9],M[1],T\"is_LEDStat\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x4[13 66 71 102],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_E33_VCU_simulink_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_E33_VCU_simulinkInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc14_E33_VCU_simulinkInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _E33_VCU_simulinkMachineNumber_,
           14,
           7,
           6,
           0,
           7,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"FanPwr");
          _SFD_SET_DATA_PROPS(1,2,0,1,"FanDutyCycl");
          _SFD_SET_DATA_PROPS(2,1,1,0,"IsPrechg");
          _SFD_SET_DATA_PROPS(3,1,1,0,"IsRun");
          _SFD_SET_DATA_PROPS(4,8,0,0,"");
          _SFD_SET_DATA_PROPS(5,9,0,0,"");
          _SFD_SET_DATA_PROPS(6,8,0,0,"");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(1,0,2);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,5);
          _SFD_ST_SUBSTATE_INDEX(0,0,2);
          _SFD_ST_SUBSTATE_INDEX(0,1,3);
          _SFD_ST_SUBSTATE_INDEX(0,2,4);
          _SFD_ST_SUBSTATE_INDEX(0,3,5);
          _SFD_ST_SUBSTATE_INDEX(0,4,6);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,5,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(1,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(1,0,"GetDutyCyc",0,-1,138);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,20,1,20);

        {
          static int condStart[] = { 1, 8 };

          static int condEnd[] = { 6, 20 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,20,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,1,1);
        _SFD_CV_INIT_EML_IF(4,0,0,1,7,1,7);

        {
          static int condStart[] = { 2 };

          static int condEnd[] = { 7 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,1,7,1,0,&(condStart[0]),&(condEnd[0]),2,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(5,0,0,1,24,1,24);

        {
          static int condStart[] = { 1, 16 };

          static int condEnd[] = { 14, 24 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(5,0,0,1,24,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(1,0,0,0,0,0,0,0,0,0,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT16,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_e_sf_marshallOut,(MexInFcnForType)
          c14_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c14_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4294967295;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)NULL,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(4,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(5,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(6,(void *)(NULL));

        {
          uint16_T *c14_FanPwr;
          uint16_T *c14_FanDutyCycl;
          boolean_T *c14_IsPrechg;
          boolean_T *c14_IsRun;
          c14_IsRun = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c14_IsPrechg = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c14_FanDutyCycl = (uint16_T *)ssGetOutputPortSignal(chartInstance->S,
            1);
          c14_FanPwr = (uint16_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c14_FanPwr);
          _SFD_SET_DATA_VALUE_PTR(1U, c14_FanDutyCycl);
          _SFD_SET_DATA_VALUE_PTR(2U, c14_IsPrechg);
          _SFD_SET_DATA_VALUE_PTR(3U, c14_IsRun);
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
  return "V930h3l4wFdgDZrDUd5AQ";
}

static void sf_opaque_initialize_c14_E33_VCU_simulink(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc14_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c14_E33_VCU_simulink((SFc14_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
  initialize_c14_E33_VCU_simulink((SFc14_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c14_E33_VCU_simulink(void *chartInstanceVar)
{
  enable_c14_E33_VCU_simulink((SFc14_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c14_E33_VCU_simulink(void *chartInstanceVar)
{
  disable_c14_E33_VCU_simulink((SFc14_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c14_E33_VCU_simulink(void *chartInstanceVar)
{
  sf_gateway_c14_E33_VCU_simulink((SFc14_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c14_E33_VCU_simulink(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c14_E33_VCU_simulink
    ((SFc14_E33_VCU_simulinkInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_E33_VCU_simulink();/* state var info */
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

extern void sf_internal_set_sim_state_c14_E33_VCU_simulink(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c14_E33_VCU_simulink();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c14_E33_VCU_simulink((SFc14_E33_VCU_simulinkInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c14_E33_VCU_simulink(SimStruct* S)
{
  return sf_internal_get_sim_state_c14_E33_VCU_simulink(S);
}

static void sf_opaque_set_sim_state_c14_E33_VCU_simulink(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c14_E33_VCU_simulink(S, st);
}

static void sf_opaque_terminate_c14_E33_VCU_simulink(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_E33_VCU_simulinkInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_E33_VCU_simulink_optimization_info();
    }

    finalize_c14_E33_VCU_simulink((SFc14_E33_VCU_simulinkInstanceStruct*)
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
  initSimStructsc14_E33_VCU_simulink((SFc14_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_E33_VCU_simulink(SimStruct *S)
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
    initialize_params_c14_E33_VCU_simulink((SFc14_E33_VCU_simulinkInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_E33_VCU_simulink(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_E33_VCU_simulink_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,14,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,14,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,14);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,14,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,14,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,14);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2501530111U));
  ssSetChecksum1(S,(2763732975U));
  ssSetChecksum2(S,(4029764936U));
  ssSetChecksum3(S,(4061047357U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c14_E33_VCU_simulink(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c14_E33_VCU_simulink(SimStruct *S)
{
  SFc14_E33_VCU_simulinkInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc14_E33_VCU_simulinkInstanceStruct *)utMalloc(sizeof
    (SFc14_E33_VCU_simulinkInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc14_E33_VCU_simulinkInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c14_E33_VCU_simulink;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c14_E33_VCU_simulink;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c14_E33_VCU_simulink;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c14_E33_VCU_simulink;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c14_E33_VCU_simulink;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c14_E33_VCU_simulink;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c14_E33_VCU_simulink;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c14_E33_VCU_simulink;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_E33_VCU_simulink;
  chartInstance->chartInfo.mdlStart = mdlStart_c14_E33_VCU_simulink;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c14_E33_VCU_simulink;
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

void c14_E33_VCU_simulink_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_E33_VCU_simulink(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_E33_VCU_simulink(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_E33_VCU_simulink(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_E33_VCU_simulink_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
