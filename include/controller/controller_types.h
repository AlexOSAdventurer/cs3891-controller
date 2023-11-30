//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_types.h
//
// Code generated for Simulink model 'controller'.
//
// Model version                  : 8.14
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Nov 30 13:09:09 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 10
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_controller_types_h_
#define RTW_HEADER_controller_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_controller_std_msgs_Float64_
#define DEFINED_TYPEDEF_FOR_SL_Bus_controller_std_msgs_Float64_

// MsgType=std_msgs/Float64
struct SL_Bus_controller_std_msgs_Float64
{
  real_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_controller_std_msgs_Bool_
#define DEFINED_TYPEDEF_FOR_SL_Bus_controller_std_msgs_Bool_

// MsgType=std_msgs/Bool
struct SL_Bus_controller_std_msgs_Bool
{
  boolean_T Data;
};

#endif

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_P_T

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_S_T

// Parameters (default storage)
typedef struct P_controller_T_ P_controller_T;

// Forward declaration for rtModel
typedef struct tag_RTM_controller_T RT_MODEL_controller_T;

#endif                                 // RTW_HEADER_controller_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
