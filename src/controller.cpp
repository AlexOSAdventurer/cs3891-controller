//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.cpp
//
// Code generated for Simulink model 'controller'.
//
// Model version                  : 8.11
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Nov 15 03:15:22 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 10
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "controller.h"
#include "rtwtypes.h"
#include "controller_types.h"
#include "controller_private.h"

// Block signals (default storage)
B_controller_T controller_B;

// Continuous states
X_controller_T controller_X;

// Disabled State Vector
XDis_controller_T controller_XDis;

// Block states (default storage)
DW_controller_T controller_DW;

// Real-time model
RT_MODEL_controller_T controller_M_{ };

RT_MODEL_controller_T *const controller_M{ &controller_M_ };

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3]{
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3]{
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t { rtsiGetT(si) };

  time_T tnew { rtsiGetSolverStopTime(si) };

  time_T h { rtsiGetStepSize(si) };

  real_T *x { rtsiGetContStates(si) };

  ODE3_IntgData *id { static_cast<ODE3_IntgData *>(rtsiGetSolverData(si)) };

  real_T *y { id->y };

  real_T *f0 { id->f[0] };

  real_T *f1 { id->f[1] };

  real_T *f2 { id->f[2] };

  real_T hB[3];
  int_T i;
  int_T nXc { 1 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  controller_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  controller_step();
  controller_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  controller_step();
  controller_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void controller_step(void)
{
  // local block i/o variables
  real_T rtb_TSamp;
  SL_Bus_controller_std_msgs_Float64 b_varargout_2;
  SL_Bus_controller_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_Sum;
  real_T u0;
  boolean_T b_varargout_1;
  if (rtmIsMajorTimeStep(controller_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&controller_M->solverInfo,
                          ((controller_M->Timing.clockTick0+1)*
      controller_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(controller_M)) {
    controller_M->Timing.t[0] = rtsiGetT(&controller_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(controller_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
    // MATLABSystem: '<S5>/SourceBlock'
    b_varargout_1 = Sub_controller_58.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S7>/Enable'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S7>/In1'
      controller_B.In1 = b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe2'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S4>/SourceBlock'
    b_varargout_1 = Sub_controller_36.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S6>/Enable'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    if (b_varargout_1) {
      // SignalConversion generated from: '<S6>/In1'
      controller_B.In1_b = b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // ManualSwitch: '<Root>/Manual Switch1'
    if (controller_P.ManualSwitch1_CurrentSetting == 1) {
      rtb_Sum = 0.0;
    } else {
      rtb_Sum = controller_B.In1_b.Data;
    }

    // ManualSwitch: '<Root>/Manual Switch'
    if (controller_P.ManualSwitch_CurrentSetting == 1) {
      u0 = 0.0;
    } else {
      u0 = controller_B.In1.Data;
    }

    // Sum: '<Root>/Sum' incorporates:
    //   ManualSwitch: '<Root>/Manual Switch'
    //   ManualSwitch: '<Root>/Manual Switch1'

    rtb_Sum -= u0;

    // SampleTimeMath: '<S2>/TSamp' incorporates:
    //   Gain: '<Root>/Gain2'
    //
    //  About '<S2>/TSamp':
    //   y = u * K where K = 1 / ( w * Ts )

    rtb_TSamp = controller_P.Gain2_Gain * rtb_Sum * controller_P.TSamp_WtEt;

    // Sum: '<S2>/Diff' incorporates:
    //   UnitDelay: '<S2>/UD'
    //
    //  Block description for '<S2>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S2>/UD':
    //
    //   Store in Global RAM

    controller_B.Diff = rtb_TSamp - controller_DW.UD_DSTATE;

    // Gain: '<Root>/Gain1'
    controller_B.Gain1 = controller_P.Gain1_Gain * rtb_Sum;
  }

  // Sum: '<Root>/Sum1' incorporates:
  //   Integrator: '<Root>/Integrator'

  u0 = (controller_B.Diff + controller_X.Integrator_CSTATE) + controller_B.Gain1;

  // Saturate: '<Root>/Saturation'
  if (u0 > controller_P.Saturation_UpperSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = controller_P.Saturation_UpperSat;
  } else if (u0 < controller_P.Saturation_LowerSat) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = controller_P.Saturation_LowerSat;
  } else {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = u0;
  }

  // End of Saturate: '<Root>/Saturation'

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_controller_38.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'
  if (rtmIsMajorTimeStep(controller_M)) {
    // Gain: '<Root>/Gain'
    controller_B.Gain = controller_P.Gain_Gain * rtb_Sum;
  }

  if (rtmIsMajorTimeStep(controller_M)) {
    if (rtmIsMajorTimeStep(controller_M)) {
      // Update for UnitDelay: '<S2>/UD'
      //
      //  Block description for '<S2>/UD':
      //
      //   Store in Global RAM

      controller_DW.UD_DSTATE = rtb_TSamp;
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(controller_M)) {
    rt_ertODEUpdateContinuousStates(&controller_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++controller_M->Timing.clockTick0;
    controller_M->Timing.t[0] = rtsiGetSolverStopTime(&controller_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.05s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.05, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      controller_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void controller_derivatives(void)
{
  XDot_controller_T *_rtXdot;
  _rtXdot = ((XDot_controller_T *) controller_M->derivs);

  // Derivatives for Integrator: '<Root>/Integrator'
  _rtXdot->Integrator_CSTATE = controller_B.Gain;
}

// Model initialize function
void controller_initialize(void)
{
  // Registration code
  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&controller_M->solverInfo,
                          &controller_M->Timing.simTimeStep);
    rtsiSetTPtr(&controller_M->solverInfo, &rtmGetTPtr(controller_M));
    rtsiSetStepSizePtr(&controller_M->solverInfo,
                       &controller_M->Timing.stepSize0);
    rtsiSetdXPtr(&controller_M->solverInfo, &controller_M->derivs);
    rtsiSetContStatesPtr(&controller_M->solverInfo, (real_T **)
                         &controller_M->contStates);
    rtsiSetNumContStatesPtr(&controller_M->solverInfo,
      &controller_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&controller_M->solverInfo,
      &controller_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&controller_M->solverInfo,
      &controller_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&controller_M->solverInfo,
      &controller_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&controller_M->solverInfo, (boolean_T**)
      &controller_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&controller_M->solverInfo, (&rtmGetErrorStatus
      (controller_M)));
    rtsiSetRTModelPtr(&controller_M->solverInfo, controller_M);
  }

  rtsiSetSimTimeStep(&controller_M->solverInfo, MAJOR_TIME_STEP);
  controller_M->intgData.y = controller_M->odeY;
  controller_M->intgData.f[0] = controller_M->odeF[0];
  controller_M->intgData.f[1] = controller_M->odeF[1];
  controller_M->intgData.f[2] = controller_M->odeF[2];
  controller_M->contStates = ((X_controller_T *) &controller_X);
  controller_M->contStateDisabled = ((XDis_controller_T *) &controller_XDis);
  controller_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&controller_M->solverInfo, static_cast<void *>
                    (&controller_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&controller_M->solverInfo, false);
  rtsiSetSolverName(&controller_M->solverInfo,"ode3");
  rtmSetTPtr(controller_M, &controller_M->Timing.tArray[0]);
  controller_M->Timing.stepSize0 = 0.05;

  {
    static const char_T b_zeroDelimTopic_1[17]{ "/car/state/vel_x" };

    static const char_T b_zeroDelimTopic_2[11]{ "/pilot_vel" };

    static const char_T b_zeroDelimTopic_3[11]{ "/cmd_accel" };

    int32_T i;
    char_T b_zeroDelimTopic[17];
    char_T b_zeroDelimTopic_0[11];

    // InitializeConditions for UnitDelay: '<S2>/UD'
    //
    //  Block description for '<S2>/UD':
    //
    //   Store in Global RAM

    controller_DW.UD_DSTATE = controller_P.DiscreteDerivative_ICPrevScaled;

    // InitializeConditions for Integrator: '<Root>/Integrator'
    controller_X.Integrator_CSTATE = controller_P.Integrator_IC;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S7>/In1' incorporates:
    //   Outport: '<S7>/Out1'

    controller_B.In1 = controller_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    controller_DW.obj_f.matlabCodegenIsDeleted = false;
    controller_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_1[i];
    }

    Sub_controller_58.createSubscriber(&b_zeroDelimTopic[0], 1);
    controller_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S6>/In1' incorporates:
    //   Outport: '<S6>/Out1'

    controller_B.In1_b = controller_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    controller_DW.obj_g.matlabCodegenIsDeleted = false;
    controller_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_2[i];
    }

    Sub_controller_36.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    controller_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    controller_DW.obj.matlabCodegenIsDeleted = false;
    controller_DW.obj.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Pub_controller_38.createPublisher(&b_zeroDelimTopic_0[0], 1);
    controller_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void controller_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!controller_DW.obj_f.matlabCodegenIsDeleted) {
    controller_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!controller_DW.obj_g.matlabCodegenIsDeleted) {
    controller_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!controller_DW.obj.matlabCodegenIsDeleted) {
    controller_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
