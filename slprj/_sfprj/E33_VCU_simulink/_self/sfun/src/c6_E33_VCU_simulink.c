/* Include files */

#include <stddef.h>
#include "blas.h"
#include "E33_VCU_simulink_sfun.h"
#include "c6_E33_VCU_simulink.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "E33_VCU_simulink_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c6_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c6_IN_LEDStat                  ((uint8_T)1U)
#define c6_IN_Blink                    ((uint8_T)1U)
#define c6_IN_FastBlink                ((uint8_T)2U)
#define c6_IN_Init                     ((uint8_T)3U)
#define c6_IN_OFF                      ((uint8_T)4U)
#define c6_IN_ON                       ((uint8_T)5U)
#define c6_IN_Test                     ((uint8_T)6U)
#define c6_IN_BlinkOFFslow             ((uint8_T)1U)
#define c6_IN_BlinkONslow              ((uint8_T)2U)
#define c6_IN_BlinkOFFfast             ((uint8_T)1U)
#define c6_IN_BlinkONfast              ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c6_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_o_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c6_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c6_E33_VCU_simulink(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void initialize_params_c6_E33_VCU_simulink
  (SFc6_E33_VCU_simulinkInstanceStruct *chartInstance);
static void enable_c6_E33_VCU_simulink(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void disable_c6_E33_VCU_simulink(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void c6_update_debugger_state_c6_E33_VCU_simulink
  (SFc6_E33_VCU_simulinkInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_E33_VCU_simulink
  (SFc6_E33_VCU_simulinkInstanceStruct *chartInstance);
static void set_sim_state_c6_E33_VCU_simulink
  (SFc6_E33_VCU_simulinkInstanceStruct *chartInstance, const mxArray *c6_st);
static void c6_set_sim_state_side_effects_c6_E33_VCU_simulink
  (SFc6_E33_VCU_simulinkInstanceStruct *chartInstance);
static void finalize_c6_E33_VCU_simulink(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void sf_gateway_c6_E33_VCU_simulink(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void initSimStructsc6_E33_VCU_simulink
  (SFc6_E33_VCU_simulinkInstanceStruct *chartInstance);
static void c6_LEDStat(SFc6_E33_VCU_simulinkInstanceStruct *chartInstance);
static void c6_Blink(SFc6_E33_VCU_simulinkInstanceStruct *chartInstance);
static void c6_exit_internal_Blink(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void c6_Test(SFc6_E33_VCU_simulinkInstanceStruct *chartInstance);
static void c6_FastBlink(SFc6_E33_VCU_simulinkInstanceStruct *chartInstance);
static void c6_exit_internal_FastBlink(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static real_T c6_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static boolean_T c6_b_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_sf_internal_predicateOutput, const char_T
  *c6_identifier);
static boolean_T c6_c_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_d_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static uint8_T c6_e_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_b_tp_LEDStat, const char_T *c6_identifier);
static uint8_T c6_f_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint32_T c6_g_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_b_previousTicks, const char_T *c6_identifier);
static uint32_T c6_h_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static const mxArray *c6_i_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct *
  chartInstance, const mxArray *c6_b_setSimStateSideEffectsInfo, const char_T
  *c6_identifier);
static const mxArray *c6_j_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct *
  chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_updateDataWrittenToVector(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, uint32_T c6_vectorIndex);
static void c6_errorIfDataNotWrittenToFcn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, uint32_T c6_vectorIndex, uint32_T c6_dataNumber);
static void init_dsm_address_info(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_E33_VCU_simulink(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_doSetSimStateSideEffects = 0U;
  chartInstance->c6_setSimStateSideEffectsInfo = NULL;
  chartInstance->c6_is_LEDStat = c6_IN_NO_ACTIVE_CHILD;
  chartInstance->c6_tp_LEDStat = 0U;
  chartInstance->c6_is_Blink = c6_IN_NO_ACTIVE_CHILD;
  chartInstance->c6_tp_Blink = 0U;
  chartInstance->c6_tp_BlinkOFFslow = 0U;
  chartInstance->c6_temporalCounter_i1 = 0U;
  chartInstance->c6_tp_BlinkONslow = 0U;
  chartInstance->c6_temporalCounter_i1 = 0U;
  chartInstance->c6_is_FastBlink = c6_IN_NO_ACTIVE_CHILD;
  chartInstance->c6_tp_FastBlink = 0U;
  chartInstance->c6_tp_BlinkOFFfast = 0U;
  chartInstance->c6_temporalCounter_i1 = 0U;
  chartInstance->c6_tp_BlinkONfast = 0U;
  chartInstance->c6_temporalCounter_i1 = 0U;
  chartInstance->c6_tp_Init = 0U;
  chartInstance->c6_temporalCounter_i1 = 0U;
  chartInstance->c6_tp_OFF = 0U;
  chartInstance->c6_tp_ON = 0U;
  chartInstance->c6_tp_Test = 0U;
  chartInstance->c6_temporalCounter_i1 = 0U;
  chartInstance->c6_is_active_c6_E33_VCU_simulink = 0U;
  chartInstance->c6_is_c6_E33_VCU_simulink = c6_IN_NO_ACTIVE_CHILD;
  chartInstance->c6_presentTicks = 0U;
  chartInstance->c6_elapsedTicks = 0U;
  chartInstance->c6_previousTicks = 0U;
}

static void initialize_params_c6_E33_VCU_simulink
  (SFc6_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c6_E33_VCU_simulink(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.05
    + 0.5);
  chartInstance->c6_previousTicks = chartInstance->c6_presentTicks;
}

static void disable_c6_E33_VCU_simulink(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.05
    + 0.5);
  chartInstance->c6_elapsedTicks = chartInstance->c6_presentTicks -
    chartInstance->c6_previousTicks;
  chartInstance->c6_previousTicks = chartInstance->c6_presentTicks;
  if ((uint32_T)chartInstance->c6_temporalCounter_i1 +
      chartInstance->c6_elapsedTicks <= 63U) {
    chartInstance->c6_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c6_temporalCounter_i1 + chartInstance->c6_elapsedTicks);
  } else {
    chartInstance->c6_temporalCounter_i1 = 63U;
  }
}

static void c6_update_debugger_state_c6_E33_VCU_simulink
  (SFc6_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  uint32_T c6_prevAniVal;
  c6_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c6_is_active_c6_E33_VCU_simulink == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_c6_E33_VCU_simulink == c6_IN_LEDStat) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_LEDStat == c6_IN_Blink) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_Blink == c6_IN_BlinkONslow) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_Blink == c6_IN_BlinkOFFslow) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_LEDStat == c6_IN_Init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_LEDStat == c6_IN_Test) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_LEDStat == c6_IN_FastBlink) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_FastBlink == c6_IN_BlinkONfast) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_FastBlink == c6_IN_BlinkOFFfast) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_LEDStat == c6_IN_ON) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_LEDStat == c6_IN_OFF) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c6_sfEvent);
  }

  _SFD_SET_ANIMATION(c6_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c6_E33_VCU_simulink
  (SFc6_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  boolean_T c6_hoistedGlobal;
  boolean_T c6_u;
  const mxArray *c6_b_y = NULL;
  uint8_T c6_b_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  uint8_T c6_c_hoistedGlobal;
  uint8_T c6_c_u;
  const mxArray *c6_d_y = NULL;
  uint8_T c6_d_hoistedGlobal;
  uint8_T c6_d_u;
  const mxArray *c6_e_y = NULL;
  uint8_T c6_e_hoistedGlobal;
  uint8_T c6_e_u;
  const mxArray *c6_f_y = NULL;
  uint8_T c6_f_hoistedGlobal;
  uint8_T c6_f_u;
  const mxArray *c6_g_y = NULL;
  uint8_T c6_g_hoistedGlobal;
  uint8_T c6_g_u;
  const mxArray *c6_h_y = NULL;
  uint32_T c6_h_hoistedGlobal;
  uint32_T c6_h_u;
  const mxArray *c6_i_y = NULL;
  boolean_T *c6_R2D_Light;
  c6_R2D_Light = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(8, 1), false);
  c6_hoistedGlobal = *c6_R2D_Light;
  c6_u = c6_hoistedGlobal;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_hoistedGlobal = chartInstance->c6_is_active_c6_E33_VCU_simulink;
  c6_b_u = c6_b_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_c_hoistedGlobal = chartInstance->c6_is_c6_E33_VCU_simulink;
  c6_c_u = c6_c_hoistedGlobal;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  c6_d_hoistedGlobal = chartInstance->c6_is_Blink;
  c6_d_u = c6_d_hoistedGlobal;
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 3, c6_e_y);
  c6_e_hoistedGlobal = chartInstance->c6_is_LEDStat;
  c6_e_u = c6_e_hoistedGlobal;
  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", &c6_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 4, c6_f_y);
  c6_f_hoistedGlobal = chartInstance->c6_is_FastBlink;
  c6_f_u = c6_f_hoistedGlobal;
  c6_g_y = NULL;
  sf_mex_assign(&c6_g_y, sf_mex_create("y", &c6_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 5, c6_g_y);
  c6_g_hoistedGlobal = chartInstance->c6_temporalCounter_i1;
  c6_g_u = c6_g_hoistedGlobal;
  c6_h_y = NULL;
  sf_mex_assign(&c6_h_y, sf_mex_create("y", &c6_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 6, c6_h_y);
  c6_h_hoistedGlobal = chartInstance->c6_previousTicks;
  c6_h_u = c6_h_hoistedGlobal;
  c6_i_y = NULL;
  sf_mex_assign(&c6_i_y, sf_mex_create("y", &c6_h_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 7, c6_i_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_E33_VCU_simulink
  (SFc6_E33_VCU_simulinkInstanceStruct *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  boolean_T *c6_R2D_Light;
  c6_R2D_Light = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_u = sf_mex_dup(c6_st);
  *c6_R2D_Light = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c6_u, 0)), "R2D_Light");
  chartInstance->c6_is_active_c6_E33_VCU_simulink = c6_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
     "is_active_c6_E33_VCU_simulink");
  chartInstance->c6_is_c6_E33_VCU_simulink = c6_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 2)), "is_c6_E33_VCU_simulink");
  chartInstance->c6_is_Blink = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 3)), "is_Blink");
  chartInstance->c6_is_LEDStat = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 4)), "is_LEDStat");
  chartInstance->c6_is_FastBlink = c6_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 5)), "is_FastBlink");
  chartInstance->c6_temporalCounter_i1 = c6_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 6)), "temporalCounter_i1");
  chartInstance->c6_previousTicks = c6_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 7)), "previousTicks");
  sf_mex_assign(&chartInstance->c6_setSimStateSideEffectsInfo,
                c6_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c6_u, 8)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c6_u);
  chartInstance->c6_doSetSimStateSideEffects = 1U;
  c6_update_debugger_state_c6_E33_VCU_simulink(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void c6_set_sim_state_side_effects_c6_E33_VCU_simulink
  (SFc6_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  if (chartInstance->c6_doSetSimStateSideEffects != 0) {
    if (chartInstance->c6_is_c6_E33_VCU_simulink == c6_IN_LEDStat) {
      chartInstance->c6_tp_LEDStat = 1U;
    } else {
      chartInstance->c6_tp_LEDStat = 0U;
    }

    if (chartInstance->c6_is_LEDStat == c6_IN_Blink) {
      chartInstance->c6_tp_Blink = 1U;
    } else {
      chartInstance->c6_tp_Blink = 0U;
    }

    if (chartInstance->c6_is_Blink == c6_IN_BlinkOFFslow) {
      chartInstance->c6_tp_BlinkOFFslow = 1U;
      if (sf_mex_sub(chartInstance->c6_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c6_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c6_tp_BlinkOFFslow = 0U;
    }

    if (chartInstance->c6_is_Blink == c6_IN_BlinkONslow) {
      chartInstance->c6_tp_BlinkONslow = 1U;
      if (sf_mex_sub(chartInstance->c6_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c6_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c6_tp_BlinkONslow = 0U;
    }

    if (chartInstance->c6_is_LEDStat == c6_IN_FastBlink) {
      chartInstance->c6_tp_FastBlink = 1U;
    } else {
      chartInstance->c6_tp_FastBlink = 0U;
    }

    if (chartInstance->c6_is_FastBlink == c6_IN_BlinkOFFfast) {
      chartInstance->c6_tp_BlinkOFFfast = 1U;
      if (sf_mex_sub(chartInstance->c6_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 7) == 0.0) {
        chartInstance->c6_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c6_tp_BlinkOFFfast = 0U;
    }

    if (chartInstance->c6_is_FastBlink == c6_IN_BlinkONfast) {
      chartInstance->c6_tp_BlinkONfast = 1U;
      if (sf_mex_sub(chartInstance->c6_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c6_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c6_tp_BlinkONfast = 0U;
    }

    if (chartInstance->c6_is_LEDStat == c6_IN_Init) {
      chartInstance->c6_tp_Init = 1U;
      if (sf_mex_sub(chartInstance->c6_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 9) == 0.0) {
        chartInstance->c6_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c6_tp_Init = 0U;
    }

    if (chartInstance->c6_is_LEDStat == c6_IN_OFF) {
      chartInstance->c6_tp_OFF = 1U;
    } else {
      chartInstance->c6_tp_OFF = 0U;
    }

    if (chartInstance->c6_is_LEDStat == c6_IN_ON) {
      chartInstance->c6_tp_ON = 1U;
    } else {
      chartInstance->c6_tp_ON = 0U;
    }

    if (chartInstance->c6_is_LEDStat == c6_IN_Test) {
      chartInstance->c6_tp_Test = 1U;
      if (sf_mex_sub(chartInstance->c6_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 12) == 0.0) {
        chartInstance->c6_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c6_tp_Test = 0U;
    }

    chartInstance->c6_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c6_E33_VCU_simulink(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c6_setSimStateSideEffectsInfo);
}

static void sf_gateway_c6_E33_VCU_simulink(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  boolean_T *c6_R2D_Light;
  boolean_T *c6_APPS_Unreliable;
  boolean_T *c6_VehStandby;
  boolean_T *c6_VehReady;
  c6_VehReady = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_VehStandby = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_APPS_Unreliable = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c6_R2D_Light = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_set_sim_state_side_effects_c6_E33_VCU_simulink(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_presentTicks = (uint32_T)muDoubleScalarFloor(_sfTime_ / 0.05
    + 0.5);
  chartInstance->c6_elapsedTicks = chartInstance->c6_presentTicks -
    chartInstance->c6_previousTicks;
  chartInstance->c6_previousTicks = chartInstance->c6_presentTicks;
  if ((uint32_T)chartInstance->c6_temporalCounter_i1 +
      chartInstance->c6_elapsedTicks <= 63U) {
    chartInstance->c6_temporalCounter_i1 = (uint8_T)((uint32_T)
      chartInstance->c6_temporalCounter_i1 + chartInstance->c6_elapsedTicks);
  } else {
    chartInstance->c6_temporalCounter_i1 = 63U;
  }

  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*c6_APPS_Unreliable, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*c6_VehStandby, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*c6_VehReady, 3U);
  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
  if (chartInstance->c6_is_active_c6_E33_VCU_simulink == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
    chartInstance->c6_is_active_c6_E33_VCU_simulink = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
    chartInstance->c6_is_c6_E33_VCU_simulink = c6_IN_LEDStat;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
    chartInstance->c6_tp_LEDStat = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
    chartInstance->c6_is_LEDStat = c6_IN_Init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c6_sfEvent);
    chartInstance->c6_temporalCounter_i1 = 0U;
    chartInstance->c6_tp_Init = 1U;
  } else {
    c6_LEDStat(chartInstance);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_E33_VCU_simulinkMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc6_E33_VCU_simulink
  (SFc6_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_LEDStat(SFc6_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  uint32_T c6_debug_family_var_map[3];
  real_T c6_nargin = 0.0;
  real_T c6_nargout = 1.0;
  boolean_T c6_out;
  uint32_T c6_b_debug_family_var_map[2];
  real_T c6_b_nargin = 0.0;
  real_T c6_b_nargout = 0.0;
  real_T c6_c_nargin = 0.0;
  real_T c6_c_nargout = 0.0;
  real_T c6_d_nargin = 0.0;
  real_T c6_d_nargout = 1.0;
  boolean_T c6_b_out;
  real_T c6_e_nargin = 0.0;
  real_T c6_e_nargout = 0.0;
  real_T c6_f_nargin = 0.0;
  real_T c6_f_nargout = 1.0;
  boolean_T c6_c_out;
  real_T c6_g_nargin = 0.0;
  real_T c6_g_nargout = 0.0;
  real_T c6_h_nargin = 0.0;
  real_T c6_h_nargout = 1.0;
  boolean_T c6_d_out;
  real_T c6_i_nargin = 0.0;
  real_T c6_i_nargout = 0.0;
  real_T c6_j_nargin = 0.0;
  real_T c6_j_nargout = 0.0;
  real_T c6_k_nargin = 0.0;
  real_T c6_k_nargout = 1.0;
  boolean_T c6_e_out;
  real_T c6_l_nargin = 0.0;
  real_T c6_l_nargout = 0.0;
  real_T c6_m_nargin = 0.0;
  real_T c6_m_nargout = 1.0;
  boolean_T c6_f_out;
  real_T c6_n_nargin = 0.0;
  real_T c6_n_nargout = 0.0;
  real_T c6_o_nargin = 0.0;
  real_T c6_o_nargout = 1.0;
  boolean_T c6_g_out;
  real_T c6_p_nargin = 0.0;
  real_T c6_p_nargout = 0.0;
  real_T c6_q_nargin = 0.0;
  real_T c6_q_nargout = 0.0;
  boolean_T *c6_R2D_Light;
  boolean_T *c6_VehStandby;
  boolean_T *c6_APPS_Unreliable;
  boolean_T *c6_VehReady;
  c6_VehReady = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_VehStandby = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_APPS_Unreliable = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c6_R2D_Light = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c6_sfEvent);
  switch (chartInstance->c6_is_LEDStat) {
   case c6_IN_Blink:
    CV_STATE_EVAL(0, 0, 1);
    c6_Blink(chartInstance);
    break;

   case c6_IN_FastBlink:
    CV_STATE_EVAL(0, 0, 2);
    c6_FastBlink(chartInstance);
    break;

   case c6_IN_Init:
    CV_STATE_EVAL(0, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_m_debug_family_names,
      c6_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_out, 2U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    c6_out = CV_EML_IF(10, 0, 0, chartInstance->c6_temporalCounter_i1 >= 20);
    _SFD_SYMBOL_SCOPE_POP();
    if (c6_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c6_sfEvent);
      chartInstance->c6_tp_Init = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c6_sfEvent);
      chartInstance->c6_is_LEDStat = c6_IN_Test;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c6_sfEvent);
      chartInstance->c6_temporalCounter_i1 = 0U;
      chartInstance->c6_tp_Test = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_d_debug_family_names,
        c6_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      *c6_R2D_Light = true;
      c6_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_c_debug_family_names,
        c6_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      *c6_R2D_Light = false;
      c6_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c6_sfEvent);
    break;

   case c6_IN_OFF:
    CV_STATE_EVAL(0, 0, 4);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                 chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_p_debug_family_names,
      c6_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_out, 2U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    c6_b_out = CV_EML_IF(13, 0, 0, *c6_VehStandby);
    _SFD_SYMBOL_SCOPE_POP();
    if (c6_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c6_sfEvent);
      chartInstance->c6_tp_OFF = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c6_sfEvent);
      chartInstance->c6_is_LEDStat = c6_IN_Blink;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      chartInstance->c6_tp_Blink = 1U;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
      chartInstance->c6_is_Blink = c6_IN_BlinkONslow;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
      chartInstance->c6_temporalCounter_i1 = 0U;
      chartInstance->c6_tp_BlinkONslow = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_debug_family_names,
        c6_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      *c6_R2D_Light = true;
      c6_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_r_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      c6_c_out = CV_EML_IF(22, 0, 0, *c6_APPS_Unreliable);
      _SFD_SYMBOL_SCOPE_POP();
      if (c6_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_OFF = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_LEDStat = c6_IN_FastBlink;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_FastBlink = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_FastBlink = c6_IN_BlinkONfast;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
        chartInstance->c6_temporalCounter_i1 = 0U;
        chartInstance->c6_tp_BlinkONfast = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_e_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_g_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_g_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        *c6_R2D_Light = true;
        c6_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c6_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                     chartInstance->c6_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_t_debug_family_names,
          c6_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_h_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_h_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_out, 2U, c6_b_sf_marshallOut,
          c6_b_sf_marshallIn);
        c6_d_out = CV_EML_IF(4, 0, 0, *c6_VehReady);
        _SFD_SYMBOL_SCOPE_POP();
        if (c6_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_OFF = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c6_sfEvent);
          chartInstance->c6_is_LEDStat = c6_IN_ON;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_ON = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_g_debug_family_names,
            c6_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_i_nargin, 0U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_i_nargout, 1U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          *c6_R2D_Light = true;
          c6_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c6_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_OFF = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c6_sfEvent);
          chartInstance->c6_is_LEDStat = c6_IN_OFF;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_OFF = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_h_debug_family_names,
            c6_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_j_nargin, 0U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_j_nargout, 1U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          *c6_R2D_Light = false;
          c6_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c6_sfEvent);
    break;

   case c6_IN_ON:
    CV_STATE_EVAL(0, 0, 5);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                 chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_p_debug_family_names,
      c6_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_k_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_k_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_out, 2U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    c6_e_out = CV_EML_IF(13, 0, 0, *c6_VehStandby);
    _SFD_SYMBOL_SCOPE_POP();
    if (c6_e_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c6_sfEvent);
      chartInstance->c6_tp_ON = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
      chartInstance->c6_is_LEDStat = c6_IN_Blink;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      chartInstance->c6_tp_Blink = 1U;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
      chartInstance->c6_is_Blink = c6_IN_BlinkONslow;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
      chartInstance->c6_temporalCounter_i1 = 0U;
      chartInstance->c6_tp_BlinkONslow = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_debug_family_names,
        c6_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_l_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_l_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      *c6_R2D_Light = true;
      c6_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_r_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_m_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_m_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      c6_f_out = CV_EML_IF(22, 0, 0, *c6_APPS_Unreliable);
      _SFD_SYMBOL_SCOPE_POP();
      if (c6_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_ON = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_LEDStat = c6_IN_FastBlink;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_FastBlink = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_FastBlink = c6_IN_BlinkONfast;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
        chartInstance->c6_temporalCounter_i1 = 0U;
        chartInstance->c6_tp_BlinkONfast = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_e_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_n_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_n_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        *c6_R2D_Light = true;
        c6_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c6_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                     chartInstance->c6_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_t_debug_family_names,
          c6_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_o_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_o_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_g_out, 2U, c6_b_sf_marshallOut,
          c6_b_sf_marshallIn);
        c6_g_out = CV_EML_IF(4, 0, 0, *c6_VehReady);
        _SFD_SYMBOL_SCOPE_POP();
        if (c6_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_ON = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
          chartInstance->c6_is_LEDStat = c6_IN_ON;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_ON = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_g_debug_family_names,
            c6_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_p_nargin, 0U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_p_nargout, 1U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          *c6_R2D_Light = true;
          c6_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c6_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_ON = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
          chartInstance->c6_is_LEDStat = c6_IN_OFF;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_OFF = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_h_debug_family_names,
            c6_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_q_nargin, 0U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_q_nargout, 1U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          *c6_R2D_Light = false;
          c6_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c6_sfEvent);
    break;

   case c6_IN_Test:
    CV_STATE_EVAL(0, 0, 6);
    c6_Test(chartInstance);
    break;

   default:
    CV_STATE_EVAL(0, 0, 0);
    chartInstance->c6_is_LEDStat = c6_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c6_sfEvent);
}

static void c6_Blink(SFc6_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  uint32_T c6_debug_family_var_map[3];
  real_T c6_nargin = 0.0;
  real_T c6_nargout = 1.0;
  boolean_T c6_out;
  real_T c6_b_nargin = 0.0;
  real_T c6_b_nargout = 1.0;
  boolean_T c6_b_out;
  uint32_T c6_b_debug_family_var_map[2];
  real_T c6_c_nargin = 0.0;
  real_T c6_c_nargout = 0.0;
  real_T c6_d_nargin = 0.0;
  real_T c6_d_nargout = 1.0;
  boolean_T c6_c_out;
  real_T c6_e_nargin = 0.0;
  real_T c6_e_nargout = 0.0;
  real_T c6_f_nargin = 0.0;
  real_T c6_f_nargout = 1.0;
  boolean_T c6_d_out;
  real_T c6_g_nargin = 0.0;
  real_T c6_g_nargout = 0.0;
  real_T c6_h_nargin = 0.0;
  real_T c6_h_nargout = 0.0;
  real_T c6_i_nargin = 0.0;
  real_T c6_i_nargout = 1.0;
  boolean_T c6_e_out;
  real_T c6_j_nargin = 0.0;
  real_T c6_j_nargout = 0.0;
  real_T c6_k_nargin = 0.0;
  real_T c6_k_nargout = 1.0;
  boolean_T c6_f_out;
  real_T c6_l_nargin = 0.0;
  real_T c6_l_nargout = 0.0;
  boolean_T *c6_APPS_Unreliable;
  boolean_T *c6_VehStandby;
  boolean_T *c6_VehReady;
  boolean_T *c6_R2D_Light;
  boolean_T guard1 = false;
  c6_VehReady = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_VehStandby = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_APPS_Unreliable = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c6_R2D_Light = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_q_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_out, 2U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  guard1 = false;
  if (CV_EML_COND(18, 0, 0, *c6_APPS_Unreliable)) {
    guard1 = true;
  } else if (!CV_EML_COND(18, 0, 1, *c6_VehStandby)) {
    guard1 = true;
  } else {
    CV_EML_MCDC(18, 0, 0, false);
    CV_EML_IF(18, 0, 0, false);
    c6_out = false;
  }

  if (guard1 == true) {
    CV_EML_MCDC(18, 0, 0, true);
    CV_EML_IF(18, 0, 0, true);
    c6_out = true;
  }

  _SFD_SYMBOL_SCOPE_POP();
  if (c6_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                 chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_p_debug_family_names,
      c6_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_out, 2U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    c6_b_out = CV_EML_IF(13, 0, 0, *c6_VehStandby);
    _SFD_SYMBOL_SCOPE_POP();
    if (c6_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c6_sfEvent);
      c6_exit_internal_Blink(chartInstance);
      chartInstance->c6_tp_Blink = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      chartInstance->c6_is_LEDStat = c6_IN_Blink;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      chartInstance->c6_tp_Blink = 1U;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
      chartInstance->c6_is_Blink = c6_IN_BlinkONslow;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
      chartInstance->c6_temporalCounter_i1 = 0U;
      chartInstance->c6_tp_BlinkONslow = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_debug_family_names,
        c6_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      *c6_R2D_Light = true;
      c6_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_r_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      c6_c_out = CV_EML_IF(22, 0, 0, *c6_APPS_Unreliable);
      _SFD_SYMBOL_SCOPE_POP();
      if (c6_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c6_sfEvent);
        c6_exit_internal_Blink(chartInstance);
        chartInstance->c6_tp_Blink = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_LEDStat = c6_IN_FastBlink;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_FastBlink = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_FastBlink = c6_IN_BlinkONfast;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
        chartInstance->c6_temporalCounter_i1 = 0U;
        chartInstance->c6_tp_BlinkONfast = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_e_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        *c6_R2D_Light = true;
        c6_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c6_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                     chartInstance->c6_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_t_debug_family_names,
          c6_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_out, 2U, c6_b_sf_marshallOut,
          c6_b_sf_marshallIn);
        c6_d_out = CV_EML_IF(4, 0, 0, *c6_VehReady);
        _SFD_SYMBOL_SCOPE_POP();
        if (c6_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
          c6_exit_internal_Blink(chartInstance);
          chartInstance->c6_tp_Blink = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
          chartInstance->c6_is_LEDStat = c6_IN_ON;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_ON = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_g_debug_family_names,
            c6_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_g_nargin, 0U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_g_nargout, 1U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          *c6_R2D_Light = true;
          c6_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c6_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c6_sfEvent);
          c6_exit_internal_Blink(chartInstance);
          chartInstance->c6_tp_Blink = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
          chartInstance->c6_is_LEDStat = c6_IN_OFF;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_OFF = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_h_debug_family_names,
            c6_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_h_nargin, 0U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_h_nargout, 1U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          *c6_R2D_Light = false;
          c6_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c6_sfEvent);
    switch (chartInstance->c6_is_Blink) {
     case c6_IN_BlinkOFFslow:
      CV_STATE_EVAL(1, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_j_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_i_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_i_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      c6_e_out = CV_EML_IF(1, 0, 0, chartInstance->c6_temporalCounter_i1 >= 20);
      _SFD_SYMBOL_SCOPE_POP();
      if (c6_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_BlinkOFFslow = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_Blink = c6_IN_BlinkONslow;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
        chartInstance->c6_temporalCounter_i1 = 0U;
        chartInstance->c6_tp_BlinkONslow = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_j_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_j_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        *c6_R2D_Light = true;
        c6_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c6_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c6_sfEvent);
      break;

     case c6_IN_BlinkONslow:
      CV_STATE_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_i_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_k_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_k_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      c6_f_out = CV_EML_IF(2, 0, 0, chartInstance->c6_temporalCounter_i1 >= 20);
      _SFD_SYMBOL_SCOPE_POP();
      if (c6_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_BlinkONslow = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_Blink = c6_IN_BlinkOFFslow;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
        chartInstance->c6_temporalCounter_i1 = 0U;
        chartInstance->c6_tp_BlinkOFFslow = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_b_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_l_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_l_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        *c6_R2D_Light = false;
        c6_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c6_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c6_sfEvent);
      break;

     default:
      CV_STATE_EVAL(1, 0, 0);
      chartInstance->c6_is_Blink = c6_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c6_sfEvent);
}

static void c6_exit_internal_Blink(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c6_is_Blink) {
   case c6_IN_BlinkOFFslow:
    CV_STATE_EVAL(1, 1, 1);
    chartInstance->c6_tp_BlinkOFFslow = 0U;
    chartInstance->c6_is_Blink = c6_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
    break;

   case c6_IN_BlinkONslow:
    CV_STATE_EVAL(1, 1, 2);
    chartInstance->c6_tp_BlinkONslow = 0U;
    chartInstance->c6_is_Blink = c6_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 1, 0);
    chartInstance->c6_is_Blink = c6_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
    break;
  }
}

static void c6_Test(SFc6_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  uint32_T c6_debug_family_var_map[3];
  real_T c6_nargin = 0.0;
  real_T c6_nargout = 1.0;
  boolean_T c6_out;
  uint32_T c6_b_debug_family_var_map[2];
  real_T c6_b_nargin = 0.0;
  real_T c6_b_nargout = 0.0;
  boolean_T c6_hoistedGlobal;
  boolean_T c6_u;
  const mxArray *c6_y = NULL;
  real_T c6_c_nargin = 0.0;
  real_T c6_c_nargout = 1.0;
  boolean_T c6_b_out;
  real_T c6_d_nargin = 0.0;
  real_T c6_d_nargout = 0.0;
  real_T c6_e_nargin = 0.0;
  real_T c6_e_nargout = 1.0;
  boolean_T c6_c_out;
  real_T c6_f_nargin = 0.0;
  real_T c6_f_nargout = 0.0;
  real_T c6_g_nargin = 0.0;
  real_T c6_g_nargout = 1.0;
  boolean_T c6_d_out;
  real_T c6_h_nargin = 0.0;
  real_T c6_h_nargout = 0.0;
  real_T c6_i_nargin = 0.0;
  real_T c6_i_nargout = 0.0;
  boolean_T *c6_R2D_Light;
  boolean_T *c6_VehStandby;
  boolean_T *c6_APPS_Unreliable;
  boolean_T *c6_VehReady;
  c6_VehReady = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_VehStandby = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_APPS_Unreliable = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c6_R2D_Light = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_n_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_out, 2U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  c6_out = CV_EML_IF(8, 0, 0, chartInstance->c6_temporalCounter_i1 >= 60);
  _SFD_SYMBOL_SCOPE_POP();
  if (c6_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_o_debug_family_names,
      c6_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    *c6_R2D_Light = false;
    c6_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
    c6_errorIfDataNotWrittenToFcn(chartInstance, 0U, 0U);
    sf_mex_printf("%s =\\n", "R2D_Light");
    c6_hoistedGlobal = *c6_R2D_Light;
    c6_u = c6_hoistedGlobal;
    c6_y = NULL;
    sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 11, 0U, 0U, 0U, 0), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c6_y);
    _SFD_SYMBOL_SCOPE_POP();
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                 chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_p_debug_family_names,
      c6_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_out, 2U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    c6_b_out = CV_EML_IF(13, 0, 0, *c6_VehStandby);
    _SFD_SYMBOL_SCOPE_POP();
    if (c6_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c6_sfEvent);
      chartInstance->c6_tp_Test = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c6_sfEvent);
      chartInstance->c6_is_LEDStat = c6_IN_Blink;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      chartInstance->c6_tp_Blink = 1U;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
      chartInstance->c6_is_Blink = c6_IN_BlinkONslow;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
      chartInstance->c6_temporalCounter_i1 = 0U;
      chartInstance->c6_tp_BlinkONslow = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_debug_family_names,
        c6_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      *c6_R2D_Light = true;
      c6_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_r_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      c6_c_out = CV_EML_IF(22, 0, 0, *c6_APPS_Unreliable);
      _SFD_SYMBOL_SCOPE_POP();
      if (c6_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_Test = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_LEDStat = c6_IN_FastBlink;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_FastBlink = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_FastBlink = c6_IN_BlinkONfast;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
        chartInstance->c6_temporalCounter_i1 = 0U;
        chartInstance->c6_tp_BlinkONfast = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_e_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        *c6_R2D_Light = true;
        c6_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c6_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                     chartInstance->c6_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_t_debug_family_names,
          c6_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_g_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_g_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_out, 2U, c6_b_sf_marshallOut,
          c6_b_sf_marshallIn);
        c6_d_out = CV_EML_IF(4, 0, 0, *c6_VehReady);
        _SFD_SYMBOL_SCOPE_POP();
        if (c6_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_Test = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c6_sfEvent);
          chartInstance->c6_is_LEDStat = c6_IN_ON;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_ON = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_g_debug_family_names,
            c6_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_h_nargin, 0U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_h_nargout, 1U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          *c6_R2D_Light = true;
          c6_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c6_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_Test = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c6_sfEvent);
          chartInstance->c6_is_LEDStat = c6_IN_OFF;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_OFF = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_h_debug_family_names,
            c6_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_i_nargin, 0U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_i_nargout, 1U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          *c6_R2D_Light = false;
          c6_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c6_sfEvent);
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c6_sfEvent);
}

static void c6_FastBlink(SFc6_E33_VCU_simulinkInstanceStruct *chartInstance)
{
  uint32_T c6_debug_family_var_map[3];
  real_T c6_nargin = 0.0;
  real_T c6_nargout = 1.0;
  boolean_T c6_out;
  real_T c6_b_nargin = 0.0;
  real_T c6_b_nargout = 1.0;
  boolean_T c6_b_out;
  uint32_T c6_b_debug_family_var_map[2];
  real_T c6_c_nargin = 0.0;
  real_T c6_c_nargout = 0.0;
  real_T c6_d_nargin = 0.0;
  real_T c6_d_nargout = 1.0;
  boolean_T c6_c_out;
  real_T c6_e_nargin = 0.0;
  real_T c6_e_nargout = 0.0;
  real_T c6_f_nargin = 0.0;
  real_T c6_f_nargout = 1.0;
  boolean_T c6_d_out;
  real_T c6_g_nargin = 0.0;
  real_T c6_g_nargout = 0.0;
  real_T c6_h_nargin = 0.0;
  real_T c6_h_nargout = 0.0;
  real_T c6_i_nargin = 0.0;
  real_T c6_i_nargout = 1.0;
  boolean_T c6_e_out;
  real_T c6_j_nargin = 0.0;
  real_T c6_j_nargout = 0.0;
  real_T c6_k_nargin = 0.0;
  real_T c6_k_nargout = 1.0;
  boolean_T c6_f_out;
  real_T c6_l_nargin = 0.0;
  real_T c6_l_nargout = 0.0;
  boolean_T *c6_APPS_Unreliable;
  boolean_T *c6_VehStandby;
  boolean_T *c6_VehReady;
  boolean_T *c6_R2D_Light;
  c6_VehReady = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_VehStandby = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_APPS_Unreliable = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c6_R2D_Light = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_s_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_out, 2U, c6_b_sf_marshallOut,
    c6_b_sf_marshallIn);
  c6_out = CV_EML_IF(25, 0, 0, CV_EML_MCDC(25, 0, 0, !CV_EML_COND(25, 0, 0,
    *c6_APPS_Unreliable)));
  _SFD_SYMBOL_SCOPE_POP();
  if (c6_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c6_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                 chartInstance->c6_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_p_debug_family_names,
      c6_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_out, 2U, c6_b_sf_marshallOut,
      c6_b_sf_marshallIn);
    c6_b_out = CV_EML_IF(13, 0, 0, *c6_VehStandby);
    _SFD_SYMBOL_SCOPE_POP();
    if (c6_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c6_sfEvent);
      c6_exit_internal_FastBlink(chartInstance);
      chartInstance->c6_tp_FastBlink = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
      chartInstance->c6_is_LEDStat = c6_IN_Blink;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      chartInstance->c6_tp_Blink = 1U;
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
      chartInstance->c6_is_Blink = c6_IN_BlinkONslow;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
      chartInstance->c6_temporalCounter_i1 = 0U;
      chartInstance->c6_tp_BlinkONslow = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_debug_family_names,
        c6_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      *c6_R2D_Light = true;
      c6_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_r_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      c6_c_out = CV_EML_IF(22, 0, 0, *c6_APPS_Unreliable);
      _SFD_SYMBOL_SCOPE_POP();
      if (c6_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U, chartInstance->c6_sfEvent);
        c6_exit_internal_FastBlink(chartInstance);
        chartInstance->c6_tp_FastBlink = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_LEDStat = c6_IN_FastBlink;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_FastBlink = 1U;
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_FastBlink = c6_IN_BlinkONfast;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
        chartInstance->c6_temporalCounter_i1 = 0U;
        chartInstance->c6_tp_BlinkONfast = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_e_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        *c6_R2D_Light = true;
        c6_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U, chartInstance->c6_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                     chartInstance->c6_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_t_debug_family_names,
          c6_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_out, 2U, c6_b_sf_marshallOut,
          c6_b_sf_marshallIn);
        c6_d_out = CV_EML_IF(4, 0, 0, *c6_VehReady);
        _SFD_SYMBOL_SCOPE_POP();
        if (c6_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
          c6_exit_internal_FastBlink(chartInstance);
          chartInstance->c6_tp_FastBlink = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
          chartInstance->c6_is_LEDStat = c6_IN_ON;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_ON = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_g_debug_family_names,
            c6_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_g_nargin, 0U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_g_nargout, 1U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          *c6_R2D_Light = true;
          c6_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c6_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c6_sfEvent);
          c6_exit_internal_FastBlink(chartInstance);
          chartInstance->c6_tp_FastBlink = 0U;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
          chartInstance->c6_is_LEDStat = c6_IN_OFF;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c6_sfEvent);
          chartInstance->c6_tp_OFF = 1U;
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_h_debug_family_names,
            c6_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_h_nargin, 0U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_h_nargout, 1U,
            c6_sf_marshallOut, c6_sf_marshallIn);
          *c6_R2D_Light = false;
          c6_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }
    }
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
    switch (chartInstance->c6_is_FastBlink) {
     case c6_IN_BlinkOFFfast:
      CV_STATE_EVAL(4, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_l_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_i_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_i_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      c6_e_out = CV_EML_IF(19, 0, 0, chartInstance->c6_temporalCounter_i1 >= 4);
      _SFD_SYMBOL_SCOPE_POP();
      if (c6_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_BlinkOFFfast = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_FastBlink = c6_IN_BlinkONfast;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
        chartInstance->c6_temporalCounter_i1 = 0U;
        chartInstance->c6_tp_BlinkONfast = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_e_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_j_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_j_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        *c6_R2D_Light = true;
        c6_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                     chartInstance->c6_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
      break;

     case c6_IN_BlinkONfast:
      CV_STATE_EVAL(4, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 21U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_k_debug_family_names,
        c6_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_k_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_k_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      c6_f_out = CV_EML_IF(21, 0, 0, chartInstance->c6_temporalCounter_i1 >= 4);
      _SFD_SYMBOL_SCOPE_POP();
      if (c6_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_BlinkONfast = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_FastBlink = c6_IN_BlinkOFFfast;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
        chartInstance->c6_temporalCounter_i1 = 0U;
        chartInstance->c6_tp_BlinkOFFfast = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_f_debug_family_names,
          c6_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_l_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_l_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        *c6_R2D_Light = false;
        c6_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK((real_T)*c6_R2D_Light, 0U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     chartInstance->c6_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c6_sfEvent);
      break;

     default:
      CV_STATE_EVAL(4, 0, 0);
      chartInstance->c6_is_FastBlink = c6_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
      break;
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
}

static void c6_exit_internal_FastBlink(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c6_is_FastBlink) {
   case c6_IN_BlinkOFFfast:
    CV_STATE_EVAL(4, 1, 1);
    chartInstance->c6_tp_BlinkOFFfast = 0U;
    chartInstance->c6_is_FastBlink = c6_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
    break;

   case c6_IN_BlinkONfast:
    CV_STATE_EVAL(4, 1, 2);
    chartInstance->c6_tp_BlinkONfast = 0U;
    chartInstance->c6_is_FastBlink = c6_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c6_sfEvent);
    break;

   default:
    CV_STATE_EVAL(4, 1, 0);
    chartInstance->c6_is_FastBlink = c6_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
    break;
  }
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)c6_machineNumber;
  (void)c6_chartNumber;
  (void)c6_instanceNumber;
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc6_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static real_T c6_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc6_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  boolean_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc6_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(boolean_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static boolean_T c6_b_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_sf_internal_predicateOutput, const char_T
  *c6_identifier)
{
  boolean_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_sf_internal_predicateOutput), &c6_thisId);
  sf_mex_destroy(&c6_sf_internal_predicateOutput);
  return c6_y;
}

static boolean_T c6_c_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  boolean_T c6_y;
  boolean_T c6_b0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_b0, 1, 11, 0U, 0, 0U, 0);
  c6_y = c6_b0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_sf_internal_predicateOutput;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  boolean_T c6_y;
  SFc6_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc6_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c6_sf_internal_predicateOutput = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_sf_internal_predicateOutput), &c6_thisId);
  sf_mex_destroy(&c6_sf_internal_predicateOutput);
  *(boolean_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_E33_VCU_simulink_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c6_nameCaptureInfo;
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc6_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_d_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i0, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc6_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  uint8_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc6_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(uint8_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static uint8_T c6_e_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_b_tp_LEDStat, const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_tp_LEDStat),
    &c6_thisId);
  sf_mex_destroy(&c6_b_tp_LEDStat);
  return c6_y;
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_tp_LEDStat;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  uint8_T c6_y;
  SFc6_E33_VCU_simulinkInstanceStruct *chartInstance;
  chartInstance = (SFc6_E33_VCU_simulinkInstanceStruct *)chartInstanceVoid;
  c6_b_tp_LEDStat = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_tp_LEDStat),
    &c6_thisId);
  sf_mex_destroy(&c6_b_tp_LEDStat);
  *(uint8_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint32_T c6_g_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_b_previousTicks, const char_T *c6_identifier)
{
  uint32_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_previousTicks),
    &c6_thisId);
  sf_mex_destroy(&c6_b_previousTicks);
  return c6_y;
}

static uint32_T c6_h_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint32_T c6_y;
  uint32_T c6_u1;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u1, 1, 7, 0U, 0, 0U, 0);
  c6_y = c6_u1;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static const mxArray *c6_i_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct *
  chartInstance, const mxArray *c6_b_setSimStateSideEffectsInfo, const char_T
  *c6_identifier)
{
  const mxArray *c6_y = NULL;
  emlrtMsgIdentifier c6_thisId;
  c6_y = NULL;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  sf_mex_assign(&c6_y, c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_setSimStateSideEffectsInfo), &c6_thisId), false);
  sf_mex_destroy(&c6_b_setSimStateSideEffectsInfo);
  return c6_y;
}

static const mxArray *c6_j_emlrt_marshallIn(SFc6_E33_VCU_simulinkInstanceStruct *
  chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  const mxArray *c6_y = NULL;
  (void)chartInstance;
  (void)c6_parentId;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_duplicatearraysafe(&c6_u), false);
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_updateDataWrittenToVector(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, uint32_T c6_vectorIndex)
{
  (void)chartInstance;
  c6_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c6_vectorIndex, 0, 0, 1, 0)] = true;
}

static void c6_errorIfDataNotWrittenToFcn(SFc6_E33_VCU_simulinkInstanceStruct
  *chartInstance, uint32_T c6_vectorIndex, uint32_T c6_dataNumber)
{
  (void)chartInstance;
  _SFD_DATA_READ_BEFORE_WRITE_CHECK(c6_dataNumber, c6_dataWrittenToVector
    [(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)c6_vectorIndex, 0, 0, 1,
    0)]);
}

static void init_dsm_address_info(SFc6_E33_VCU_simulinkInstanceStruct
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

void sf_c6_E33_VCU_simulink_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1188455499U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2485339749U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(602030943U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1169201469U);
}

mxArray *sf_c6_E33_VCU_simulink_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("HrZWBL5pMcmjzuzRAfr52");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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

mxArray *sf_c6_E33_VCU_simulink_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_E33_VCU_simulink_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c6_E33_VCU_simulink(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[83],T\"R2D_Light\",},{M[8],M[0],T\"is_active_c6_E33_VCU_simulink\",},{M[9],M[0],T\"is_c6_E33_VCU_simulink\",},{M[9],M[37],T\"is_Blink\",},{M[9],M[50],T\"is_LEDStat\",},{M[9],M[92],T\"is_FastBlink\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"at\",M1x6[49 38 87 88 41 42],M[1]}}},{M[13],M[0],T\"previousTicks\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_E33_VCU_simulink_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_E33_VCU_simulinkInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc6_E33_VCU_simulinkInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _E33_VCU_simulinkMachineNumber_,
           6,
           11,
           26,
           0,
           4,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"R2D_Light");
          _SFD_SET_DATA_PROPS(1,1,1,0,"APPS_Unreliable");
          _SFD_SET_DATA_PROPS(2,1,1,0,"VehStandby");
          _SFD_SET_DATA_PROPS(3,1,1,0,"VehReady");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,6);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,4);
          _SFD_ST_SUBSTATE_INDEX(0,2,7);
          _SFD_ST_SUBSTATE_INDEX(0,3,8);
          _SFD_ST_SUBSTATE_INDEX(0,4,9);
          _SFD_ST_SUBSTATE_INDEX(0,5,10);
          _SFD_ST_SUBSTATE_COUNT(1,2);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,2);
          _SFD_ST_SUBSTATE_INDEX(4,0,5);
          _SFD_ST_SUBSTATE_INDEX(4,1,6);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,6,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(24,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(22,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(25,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(10,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(21,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(21,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(19,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,11,1,11);
        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(18,0,0,1,29,1,29);

        {
          static int condStart[] = { 1, 19 };

          static int condEnd[] = { 16, 29 };

          static int pfixExpr[] = { 0, 1, -1, -2 };

          _SFD_CV_INIT_EML_MCDC(18,0,0,1,29,2,0,&(condStart[0]),&(condEnd[0]),4,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(22,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(22,0,0,1,16,1,16);
        _SFD_CV_INIT_EML(25,0,0,1,0,0,0,0,0,1,1);
        _SFD_CV_INIT_EML_IF(25,0,0,1,17,1,17);

        {
          static int condStart[] = { 2 };

          static int condEnd[] = { 17 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(25,0,0,1,17,1,0,&(condStart[0]),&(condEnd[0]),2,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,9,1,9);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)c6_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          boolean_T *c6_R2D_Light;
          boolean_T *c6_APPS_Unreliable;
          boolean_T *c6_VehStandby;
          boolean_T *c6_VehReady;
          c6_VehReady = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c6_VehStandby = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c6_APPS_Unreliable = (boolean_T *)ssGetInputPortSignal
            (chartInstance->S, 0);
          c6_R2D_Light = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_R2D_Light);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_APPS_Unreliable);
          _SFD_SET_DATA_VALUE_PTR(2U, c6_VehStandby);
          _SFD_SET_DATA_VALUE_PTR(3U, c6_VehReady);
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
  return "cGT6IKSaKoCsqYOu6H8WmC";
}

static void sf_opaque_initialize_c6_E33_VCU_simulink(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_E33_VCU_simulink((SFc6_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
  initialize_c6_E33_VCU_simulink((SFc6_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_E33_VCU_simulink(void *chartInstanceVar)
{
  enable_c6_E33_VCU_simulink((SFc6_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c6_E33_VCU_simulink(void *chartInstanceVar)
{
  disable_c6_E33_VCU_simulink((SFc6_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c6_E33_VCU_simulink(void *chartInstanceVar)
{
  sf_gateway_c6_E33_VCU_simulink((SFc6_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_E33_VCU_simulink(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_E33_VCU_simulink
    ((SFc6_E33_VCU_simulinkInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_E33_VCU_simulink();/* state var info */
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

extern void sf_internal_set_sim_state_c6_E33_VCU_simulink(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c6_E33_VCU_simulink();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_E33_VCU_simulink((SFc6_E33_VCU_simulinkInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_E33_VCU_simulink(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_E33_VCU_simulink(S);
}

static void sf_opaque_set_sim_state_c6_E33_VCU_simulink(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c6_E33_VCU_simulink(S, st);
}

static void sf_opaque_terminate_c6_E33_VCU_simulink(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_E33_VCU_simulinkInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_E33_VCU_simulink_optimization_info();
    }

    finalize_c6_E33_VCU_simulink((SFc6_E33_VCU_simulinkInstanceStruct*)
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
  initSimStructsc6_E33_VCU_simulink((SFc6_E33_VCU_simulinkInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_E33_VCU_simulink(SimStruct *S)
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
    initialize_params_c6_E33_VCU_simulink((SFc6_E33_VCU_simulinkInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_E33_VCU_simulink(SimStruct *S)
{
  ssSetNeedAbsoluteTime(S,1);
  ssSetModelReferenceSampleTimeDisallowInheritance(S);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_E33_VCU_simulink_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(7423387U));
  ssSetChecksum1(S,(1239589530U));
  ssSetChecksum2(S,(1613718435U));
  ssSetChecksum3(S,(3348771903U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_E33_VCU_simulink(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c6_E33_VCU_simulink(SimStruct *S)
{
  SFc6_E33_VCU_simulinkInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc6_E33_VCU_simulinkInstanceStruct *)utMalloc(sizeof
    (SFc6_E33_VCU_simulinkInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_E33_VCU_simulinkInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_E33_VCU_simulink;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_E33_VCU_simulink;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_E33_VCU_simulink;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_E33_VCU_simulink;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_E33_VCU_simulink;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_E33_VCU_simulink;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_E33_VCU_simulink;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_E33_VCU_simulink;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_E33_VCU_simulink;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_E33_VCU_simulink;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_E33_VCU_simulink;
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

void c6_E33_VCU_simulink_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_E33_VCU_simulink(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_E33_VCU_simulink(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_E33_VCU_simulink(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_E33_VCU_simulink_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
