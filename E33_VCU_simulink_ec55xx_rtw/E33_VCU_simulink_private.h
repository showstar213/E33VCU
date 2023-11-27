/*
 * Code generated for Simulink model E33_VCU_simulink.
 *
 * FILE    : E33_VCU_simulink_private.h
 *
 * VERSION : 1.70
 *
 * DATE    : Sun Nov 26 16:56:11 2023
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_E33_VCU_simulink_private_h_
#define RTW_HEADER_E33_VCU_simulink_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error "Code was generated for compiler with different sized uchar/char. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compiler's limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, which will disable the preprocessor word size checks."
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error "Code was generated for compiler with different sized ushort/short. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized uint/int. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error "Code was generated for compiler with different sized ulong/long. Consider adjusting Emulation Hardware word size settings on the Hardware Implementation pane to match your compiler word sizes as defined in the compilers limits.h header file. Alternatively, you can select 'None' for Emulation Hardware and select the 'Enable portable word sizes' option for ERT based targets, this will disable the preprocessor word size checks."
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

/* #define mydefine 100.0 */
extern real32_T rt_roundf_snf(real32_T u);
extern real_T rt_roundd_snf(real_T u);
extern void mul_wide_u32(uint32_T in0, uint32_T in1, uint32_T *ptrOutBitsHi,
  uint32_T *ptrOutBitsLo);
extern uint32_T mul_u32_u32_u32_sr31(uint32_T a, uint32_T b);
extern uint32_T div_nzp_repeat_u32(uint32_T numerator, uint32_T denominator,
  uint32_T nRepeatSub);
extern uint32_T div_nzp_u32_near(uint32_T numerator, uint32_T denominator);
extern uint16_T look1_iu16lu32n16_binlcse(uint16_T u0, const uint16_T bp0[],
  const uint16_T table[], uint32_T maxIndex);
extern int32_T look1_iu16bs32lu32n31t_VYilYNox(uint16_T u0, const int32_T bp0[],
  const int32_T table[], uint32_T maxIndex);
extern uint16_T look1_iu16lu32n16_binlcne(uint16_T u0, const uint16_T bp0[],
  const uint16_T table[], uint32_T maxIndex);
extern real32_T look1_ifbdtdIf_binlc(real32_T u0, const real_T bp0[], const
  real_T table[], uint32_T maxIndex);
extern uint16_T look2_ifyu16td_binlc(real32_T u0, real32_T u1, const real32_T
  bp0[], const real32_T bp1[], const real_T table[], const uint32_T maxIndex[],
  uint32_T stride);
extern real32_T look1_iflf_binlc(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);
extern real32_T sMultiWord2Single(const uint32_T u1[], int32_T n1, int32_T e1);
extern void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[],
  int32_T n2, uint32_T y[], int32_T n);
extern real32_T uMultiWordSingle(const uint32_T u1[], int32_T n1, int32_T e1);
extern void uMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[],
  int32_T n2, uint32_T y[], int32_T n);
extern uint32_T MultiWord2uLong(const uint32_T u[]);
extern void uMultiWordShr(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[], int32_T n);
extern void E33_VCU_simulink_step0(void);
extern void E33_VCU_simulink_step1(void);
extern void E33_VCU_simulink_step2(void);
extern void E33_VCU_simulink_step3(void);
extern void E33_VCU_simulink_step4(void);
extern void E33_VCU_simulink_step5(void);
extern void E33_VCU_simulink_step6(void);
extern void E33_VCU_simulink_step7(void);

#endif                                 /* RTW_HEADER_E33_VCU_simulink_private_h_ */

/* File trailer for ECUCoder generated file E33_VCU_simulink_private.h.
 *
 * [EOF]
 */
