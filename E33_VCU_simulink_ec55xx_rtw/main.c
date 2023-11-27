/*
 * Code generated for Simulink model E33_VCU_simulink.
 *
 * FILE    : main.c
 *
 * VERSION : 1.70
 *
 * DATE    : Sun Nov 26 16:56:11 2023
 *
 * Copyright 2011-2012 ECUCoder. All Rights Reserved.
 */

#include "E33_VCU_simulink.h"
#include "etpu.h"

uint8_T ECUCoderModelBaseCounter = 0;
uint8_T AfterRunFlags[2] = { 0, 0 };

static boolean_T ECUCoderOverrunFlags[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

uint32_t *fs_free_param;
void rt_OneStep(void)
{
  boolean_T ECUCodereventFlags[8];     /* Model has 8 rates */
  int_T i;

  /* Check base rate for overrun */
  if (ECUCoderOverrunFlags[0]++) {
    ((void) 0);
    return;
  }

  E33_VCU_simulink_SetEventsForThisBaseStep(ECUCodereventFlags);

  /* Set model inputs associated with base rate here */
  ECUCoderOverrunFlags[0]--;

  /* Check subrates for overrun */
  for (i = 1; i < 8; i++) {
    if (ECUCodereventFlags[i]) {
      if (ECUCoderOverrunFlags[i]++) {
        ((void) 0);
        return;
      }

      E33_VCU_simulink_step(i);

      /* Get model outputs here */
      ECUCoderOverrunFlags[i]--;
    }
  }
}

main()
{
  ec_cpu_init();

  /* Interrupt management */
  ec_interrupts_init();
  EXCEP_InitExceptionHandlers();
  INTC_InitINTCInterrupts();
  ec_interrupts_allintreg();

  /* Initialize Pad */
  ec_pad_init(&Pad_ConfigurationPB);
  ec_adc_init();

  /* Initialize eTPU */
  fs_etpu_init(my_etpu_config,
               (uint32_t *)etpu_code,
               sizeof(etpu_code),
               (uint32_t *)etpu_globals,
               sizeof(etpu_globals));

  /* Initialize CAN */
#if CANAENABLE

  ec_cana_init(&(CANINIT[0]));

#endif

#if CANBENABLE

  ec_canb_init(&(CANINIT[1]));

#endif

#if CANCENABLE

  ec_canc_init(&(CANINIT[2]));

#endif

  /* Initialize SPI */
#if SPIAENABLE

  ec_spia_init();

#endif

#if SPIBENABLE

  ec_spib_init();

#endif

#if SPICENABLE

  ec_spic_init();

#endif

#if SPIDENABLE

  ec_spid_init();

#endif

  /* Initialize SCI */
#if SCIAENABLE

  ec_scia_init();

#endif

#if SCIBENABLE

  ec_scib_init();

#endif

  /* Initialize model */
  E33_VCU_simulink_initialize();

  /* Initialize Flash */
  CCP_FlashInit();

  /* Enable all timebases */
  fs_timer_start();
  EnableInterrupts();
  while (((void*) 0) == 0) {
    if (ECUCoderModelBaseCounter >0 ) {
      ECUCoderModelBaseCounter = 0;
      rt_OneStep();
    }
  }

  return 0;
}

/* File trailer for ECUCoder generated file main.c.
 *
 * [EOF]
 */
