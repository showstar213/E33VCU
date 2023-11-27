/*
 * Code generated for Simulink model E33_VCU_simulink.
 *
 * FILE    : pwm.h
 *
 * VERSION : 1.70
 *
 * DATE    : Sun Nov 26 16:56:11 2023
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#ifndef RTW_HEADER_pwm_h_
#define RTW_HEADER_pwm_h_
#include "MPC5554.h"
#include "Std_Types.h"

extern void ec_pwm_init(uint8 Chn);
extern void ec_pwm_output(uint8 Chn, uint32 Period, uint32 DutyCycle);

#endif                                 /* RTW_HEADER_pwm_h_ */

/* File trailer for ECUCoder generated file pwm.h.
 *
 * [EOF]
 */
