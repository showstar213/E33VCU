/* Include files */

#include "E33_VCU_simulink_sfun.h"
#include "E33_VCU_simulink_sfun_debug_macros.h"
#include "c1_E33_VCU_simulink.h"
#include "c3_E33_VCU_simulink.h"
#include "c4_E33_VCU_simulink.h"
#include "c5_E33_VCU_simulink.h"
#include "c6_E33_VCU_simulink.h"
#include "c8_E33_VCU_simulink.h"
#include "c11_E33_VCU_simulink.h"
#include "c13_E33_VCU_simulink.h"
#include "c14_E33_VCU_simulink.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _E33_VCU_simulinkMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void E33_VCU_simulink_initializer(void)
{
}

void E33_VCU_simulink_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_E33_VCU_simulink_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_E33_VCU_simulink_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_E33_VCU_simulink_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_E33_VCU_simulink_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_E33_VCU_simulink_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_E33_VCU_simulink_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_E33_VCU_simulink_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_E33_VCU_simulink_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_E33_VCU_simulink_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_E33_VCU_simulink_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_E33_VCU_simulink_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4250069691U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1927565241U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4294365278U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(918722666U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2403318371U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4257468662U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(138733580U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(403048220U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
          sf_c1_E33_VCU_simulink_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
          sf_c3_E33_VCU_simulink_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
          sf_c4_E33_VCU_simulink_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
          sf_c5_E33_VCU_simulink_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
          sf_c6_E33_VCU_simulink_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
          sf_c8_E33_VCU_simulink_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
          sf_c11_E33_VCU_simulink_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
          sf_c13_E33_VCU_simulink_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_E33_VCU_simulink_get_check_sum(mxArray *plhs[]);
          sf_c14_E33_VCU_simulink_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2020127832U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2875675789U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(967944156U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3601629534U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2987983213U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3106191539U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3150519239U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1174348759U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_E33_VCU_simulink_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "Q8nKrGcQNY8uCId2foYDCD") == 0) {
          extern mxArray *sf_c1_E33_VCU_simulink_get_autoinheritance_info(void);
          plhs[0] = sf_c1_E33_VCU_simulink_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "NHwMtBSTG2AyntKxPuHukB") == 0) {
          extern mxArray *sf_c3_E33_VCU_simulink_get_autoinheritance_info(void);
          plhs[0] = sf_c3_E33_VCU_simulink_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "Dk0U9ygB4FQ1Akj0lXymUE") == 0) {
          extern mxArray *sf_c4_E33_VCU_simulink_get_autoinheritance_info(void);
          plhs[0] = sf_c4_E33_VCU_simulink_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "gdHJy0mX1hh9DccLd5OXBH") == 0) {
          extern mxArray *sf_c5_E33_VCU_simulink_get_autoinheritance_info(void);
          plhs[0] = sf_c5_E33_VCU_simulink_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "HrZWBL5pMcmjzuzRAfr52") == 0) {
          extern mxArray *sf_c6_E33_VCU_simulink_get_autoinheritance_info(void);
          plhs[0] = sf_c6_E33_VCU_simulink_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "0L39YPeMqiEsPnjEzeEceG") == 0) {
          extern mxArray *sf_c8_E33_VCU_simulink_get_autoinheritance_info(void);
          plhs[0] = sf_c8_E33_VCU_simulink_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "YkviDxtI91H8ljqyEWgmbF") == 0) {
          extern mxArray *sf_c11_E33_VCU_simulink_get_autoinheritance_info(void);
          plhs[0] = sf_c11_E33_VCU_simulink_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "bjeHjkYvM6F6bWG6YrOS5C") == 0) {
          extern mxArray *sf_c13_E33_VCU_simulink_get_autoinheritance_info(void);
          plhs[0] = sf_c13_E33_VCU_simulink_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 14:
      {
        if (strcmp(aiChksum, "WkhUAWJEAFEAVamPKJ2x6D") == 0) {
          extern mxArray *sf_c14_E33_VCU_simulink_get_autoinheritance_info(void);
          plhs[0] = sf_c14_E33_VCU_simulink_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_E33_VCU_simulink_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_E33_VCU_simulink_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_E33_VCU_simulink_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_E33_VCU_simulink_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_E33_VCU_simulink_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_E33_VCU_simulink_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_E33_VCU_simulink_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_E33_VCU_simulink_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_E33_VCU_simulink_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_E33_VCU_simulink_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_E33_VCU_simulink_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_E33_VCU_simulink_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_E33_VCU_simulink_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_E33_VCU_simulink_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_E33_VCU_simulink_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_E33_VCU_simulink_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_E33_VCU_simulink_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_E33_VCU_simulink_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_E33_VCU_simulink_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_E33_VCU_simulink_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "DRern0iVG8kv8kBLgbAMTH") == 0) {
          extern mxArray *sf_c1_E33_VCU_simulink_third_party_uses_info(void);
          plhs[0] = sf_c1_E33_VCU_simulink_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "F2YVg5wFOk3ekTv8vqO7PB") == 0) {
          extern mxArray *sf_c3_E33_VCU_simulink_third_party_uses_info(void);
          plhs[0] = sf_c3_E33_VCU_simulink_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "3ZMTl8J8bnv2BpT1fX7qhG") == 0) {
          extern mxArray *sf_c4_E33_VCU_simulink_third_party_uses_info(void);
          plhs[0] = sf_c4_E33_VCU_simulink_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "Swc5rNtULYzV5sXUeixSzB") == 0) {
          extern mxArray *sf_c5_E33_VCU_simulink_third_party_uses_info(void);
          plhs[0] = sf_c5_E33_VCU_simulink_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "cGT6IKSaKoCsqYOu6H8WmC") == 0) {
          extern mxArray *sf_c6_E33_VCU_simulink_third_party_uses_info(void);
          plhs[0] = sf_c6_E33_VCU_simulink_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "pLc0MeiLLvbQ03jYBoNVz") == 0) {
          extern mxArray *sf_c8_E33_VCU_simulink_third_party_uses_info(void);
          plhs[0] = sf_c8_E33_VCU_simulink_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "VwD3lKHS7JviNVkI2o4OfE") == 0) {
          extern mxArray *sf_c11_E33_VCU_simulink_third_party_uses_info(void);
          plhs[0] = sf_c11_E33_VCU_simulink_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "ZLsxr0kqaCgdGYfiEo801G") == 0) {
          extern mxArray *sf_c13_E33_VCU_simulink_third_party_uses_info(void);
          plhs[0] = sf_c13_E33_VCU_simulink_third_party_uses_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "V930h3l4wFdgDZrDUd5AQ") == 0) {
          extern mxArray *sf_c14_E33_VCU_simulink_third_party_uses_info(void);
          plhs[0] = sf_c14_E33_VCU_simulink_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_E33_VCU_simulink_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "DRern0iVG8kv8kBLgbAMTH") == 0) {
          extern mxArray *sf_c1_E33_VCU_simulink_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_E33_VCU_simulink_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "F2YVg5wFOk3ekTv8vqO7PB") == 0) {
          extern mxArray *sf_c3_E33_VCU_simulink_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_E33_VCU_simulink_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "3ZMTl8J8bnv2BpT1fX7qhG") == 0) {
          extern mxArray *sf_c4_E33_VCU_simulink_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_E33_VCU_simulink_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "Swc5rNtULYzV5sXUeixSzB") == 0) {
          extern mxArray *sf_c5_E33_VCU_simulink_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_E33_VCU_simulink_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "cGT6IKSaKoCsqYOu6H8WmC") == 0) {
          extern mxArray *sf_c6_E33_VCU_simulink_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_E33_VCU_simulink_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "pLc0MeiLLvbQ03jYBoNVz") == 0) {
          extern mxArray *sf_c8_E33_VCU_simulink_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_E33_VCU_simulink_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "VwD3lKHS7JviNVkI2o4OfE") == 0) {
          extern mxArray *sf_c11_E33_VCU_simulink_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_E33_VCU_simulink_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "ZLsxr0kqaCgdGYfiEo801G") == 0) {
          extern mxArray *sf_c13_E33_VCU_simulink_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_E33_VCU_simulink_updateBuildInfo_args_info();
          break;
        }
      }

     case 14:
      {
        if (strcmp(tpChksum, "V930h3l4wFdgDZrDUd5AQ") == 0) {
          extern mxArray *sf_c14_E33_VCU_simulink_updateBuildInfo_args_info(void);
          plhs[0] = sf_c14_E33_VCU_simulink_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void E33_VCU_simulink_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _E33_VCU_simulinkMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "E33_VCU_simulink","sfun",0,9,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _E33_VCU_simulinkMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _E33_VCU_simulinkMachineNumber_,0);
}

void E33_VCU_simulink_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_E33_VCU_simulink_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "E33_VCU_simulink", "E33_VCU_simulink");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_E33_VCU_simulink_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
