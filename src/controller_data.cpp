//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller_data.cpp
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
#include "controller.h"

// Block parameters (default storage)
P_controller_T controller_P{
  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S7>/UD'

  0.0,

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S10>/Out1'

  {
    false                              // Data
  },

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S6>/Constant'

  {
    false                              // Data
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S1>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S8>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_gb
  //  Referenced by: '<S4>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S9>/Out1'

  {
    0.0                                // Data
  },

  // Computed Parameter: Constant_Value_j
  //  Referenced by: '<S5>/Constant'

  {
    0.0                                // Data
  },

  // Computed Parameter: Out1_Y0_l
  //  Referenced by: '<S2>/Out1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S2>/Gain2'

  0.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S7>/TSamp'

  20.0,

  // Expression: 0.8
  //  Referenced by: '<S2>/Gain1'

  0.8,

  // Expression: 0
  //  Referenced by: '<S2>/Integrator'

  0.0,

  // Expression: 1.5
  //  Referenced by: '<S2>/Saturation'

  1.5,

  // Expression: -3
  //  Referenced by: '<S2>/Saturation'

  -3.0,

  // Expression: 0
  //  Referenced by: '<S2>/Gain'

  0.0,

  // Computed Parameter: ManualSwitch_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch'

  0U,

  // Computed Parameter: ManualSwitch1_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch1'

  0U
};

//
// File trailer for generated code.
//
// [EOF]
//
