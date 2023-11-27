/*
 * Code generated for Simulink model E33_VCU_simulink.
 *
 * FILE    : E33_VCU_simulink_data.c
 *
 * VERSION : 1.70
 *
 * DATE    : Sun Nov 26 16:56:11 2023
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "E33_VCU_simulink.h"
#include "E33_VCU_simulink_private.h"

/* Constant parameters (auto storage) */
const ConstP_E33_VCU_simulink_T E33_VCU_simulink_ConstP = {
  /* Expression: [1000,500,0]
   * Referenced by: '<S7>/PwrLimDerateCur'
   */
  { 1000.0, 500.0, 0.0 },

  /* Expression: [0.95,0.98,0.99]
   * Referenced by: '<S7>/PwrLimDerateCur'
   */
  { 0.95, 0.98, 0.99 },

  /* Expression: Torq_percentage_Map
   * Referenced by: '<S7>/BasicTorqueCal'
   */
  { 0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0,
    0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0,
    0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0,
    0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0, 0.0, 1000.0, 0.0, 964.52525252525254,
    0.0, 922.58937198067622, 0.0, 884.14814814814827, 0.0, 848.78222222222223,
    0.0, 816.13675213675219, 0.0, 785.90946502057625, 0.0, 757.84126984126976,
    0.0, 731.70881226053655, 0.0, 707.31851851851854, 0.0, 684.50179211469526,
    0.0, 663.11111111111109, 0.0, 643.016835016835, 0.0, 624.10457516339864, 0.0,
    606.27301587301588, 0.0, 589.4320987654321, 0.0, 573.50150150150148, 0.0,
    558.40935672514627, 0.0, 544.09116809116813, 0.0, 530.48888888888894, 0.0,
    517.55013550135493, 0.0, 505.22751322751327, 0.0, 493.4780361757106, 0.0,
    482.26262626262627, 0.0, 471.54567901234566, 0.0, 461.29468599033811, 0.0,
    451.47990543735222, 0.0, 442.07407407407413, 0.0, 433.05215419501133, 0.0,
    424.39111111111112, 0.0, 416.06971677559909, 0.0, 408.0683760683761, 0.0,
    400.36897274633122, 0.0, 0.0 },

  /* Computed Parameter: BasicTorqueCal_bp01Da
   * Referenced by: '<S7>/BasicTorqueCal'
   */
  { 0.0F, 1000.0F },

  /* Computed Parameter: BasicTorqueCal_bp02D
   * Referenced by: '<S7>/BasicTorqueCal'
   */
  { 0.0F, 100.0F, 200.0F, 300.0F, 400.0F, 500.0F, 600.0F, 700.0F, 800.0F, 900.0F,
    1000.0F, 1100.0F, 1200.0F, 1300.0F, 1400.0F, 1500.0F, 1600.0F, 1700.0F,
    1800.0F, 1900.0F, 2000.0F, 2100.0F, 2200.0F, 2300.0F, 2400.0F, 2500.0F,
    2600.0F, 2700.0F, 2800.0F, 2900.0F, 3000.0F, 3100.0F, 3200.0F, 3300.0F,
    3400.0F, 3500.0F, 3600.0F, 3700.0F, 3800.0F, 3900.0F, 4000.0F, 4100.0F,
    4200.0F, 4300.0F, 4400.0F, 4500.0F, 4600.0F, 4700.0F, 4800.0F, 4900.0F,
    5000.0F, 5100.0F, 5200.0F, 5300.0F, 5400.0F },

  /* Computed Parameter: DLookupTable1_tableDa
   * Referenced by: '<S170>/1-D Lookup Table1'
   */
  { 0.0F, 100.0F },

  /* Computed Parameter: DLookupTable5_tableDa
   * Referenced by: '<S30>/1-D Lookup Table5'
   */
  { -364, 0, 1000, 1000, -1000, -1000, -365 },

  /* Computed Parameter: DLookupTable5_bp01Dat
   * Referenced by: '<S30>/1-D Lookup Table5'
   */
  { 500, 900, 2007, 2205, 3405, 3705, 4490 },

  /* Computed Parameter: BasicTorqueCal_maxInd
   * Referenced by: '<S7>/BasicTorqueCal'
   */
  { 1U, 54U },

  /* Computed Parameter: PwrLimDerateCur1_tabl
   * Referenced by: '<S7>/PwrLimDerateCur1'
   */
  { 1000U, 0U },

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S7>/PwrLimDerateCur1'
   *   '<S24>/1-D Lookup Table'
   *   '<S24>/1-D Lookup Table1'
   *   '<S26>/1-D Lookup Table'
   *   '<S26>/1-D Lookup Table1'
   */
  { 0U, 1000U }
};

/* File trailer for ECUCoder generated file E33_VCU_simulink_data.c.
 *
 * [EOF]
 */
