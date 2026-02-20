/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control0.c
 *
 * Code generated for Simulink model 'control0'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Fri Feb 20 14:10:08 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "control0.h"
#include "rtwtypes.h"
#include <math.h>
#include "math.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
extern real_T rt_powd_snf(real_T u0, real_T u1);
static void MATLABFunction(real_T rtu_current, real_T rtu_desired, real_T
  rtu_velocity, real_T *rty_out);
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
real_T rtNaN = -(real_T)NAN;
real_T rtInf = (real_T)INFINITY;
real_T rtMinusInf = -(real_T)INFINITY;
real32_T rtNaNF = -(real32_T)NAN;
real32_T rtInfF = (real32_T)INFINITY;
real32_T rtMinusInfF = -(real32_T)INFINITY;

/* Return rtInf needed by the generated code. */
static real_T rtGetInf(void)
{
  return rtInf;
}

/* Get rtInfF needed by the generated code. */
static real32_T rtGetInfF(void)
{
  return rtInfF;
}

/* Return rtMinusInf needed by the generated code. */
static real_T rtGetMinusInf(void)
{
  return rtMinusInf;
}

/* Return rtMinusInfF needed by the generated code. */
static real32_T rtGetMinusInfF(void)
{
  return rtMinusInfF;
}

/* Return rtNaN needed by the generated code. */
static real_T rtGetNaN(void)
{
  return rtNaN;
}

/* Return rtNaNF needed by the generated code. */
static real32_T rtGetNaNF(void)
{
  return rtNaNF;
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)isinf(value);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)isinf(value);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  return (boolean_T)(isnan(value) != 0);
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  return (boolean_T)(isnan(value) != 0);
}

/*
 * Output and update for atomic system:
 *    '<S1>/MATLAB Function'
 *    '<S1>/MATLAB Function1'
 */
static void MATLABFunction(real_T rtu_current, real_T rtu_desired, real_T
  rtu_velocity, real_T *rty_out)
{
  real_T current;
  current = rtu_current;
  if (rtu_current < rtu_desired) {
    current = rtu_current + rtu_velocity;
  }

  if (current > rtu_desired) {
    current -= rtu_velocity;
  }

  *rty_out = current;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void control0_step(void)
{
  real_T P6i[16];
  real_T rtb_IntegralGain_0[16];
  real_T rtb_IntegralGain_1[16];
  real_T theta2_0[16];
  real_T theta2_1[16];
  real_T rtb_angles[4];
  real_T P6i_0;
  real_T XEi;
  real_T a;
  real_T a_0;
  real_T alpha;
  real_T angToBase;
  real_T rtb_IntegralGain;
  real_T rtb_Integrator_n;
  real_T rtb_ProportionalGain;
  real_T theta2;
  int16_T P6i_tmp_0;
  int16_T i;
  int16_T rtb_IntegralGain_tmp;
  int16_T rtb_IntegralGain_tmp_0;
  int16_T rtb_angles_0;
  int16_T theta2_tmp;
  int8_T P6i_tmp[4];
  static const int8_T b[4] = { 0, 0, 0, 1 };

  static const int8_T c[4] = { 0, 0, 1, 0 };

  static const int8_T b_b[16] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0,
    1 };

  static const real_T c_b[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.3, 0.0, 0.0, 1.0 };

  static const real_T a_1[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.065, 1.0 };

  static const real_T d_b[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, -0.12, 0.0, 0.0, 1.0 };

  static const int8_T b_a[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  rtb_Integrator_n = ((rtDW.clockTickCounter < 1L) && (rtDW.clockTickCounter >=
    0L));
  if (rtDW.clockTickCounter >= 1L) {
    rtDW.clockTickCounter = 0L;
  } else {
    rtDW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator' */

  /* Outport: '<Root>/stepperLeftENA' incorporates:
   *  Abs: '<S1>/Abs'
   *  Constant: '<S2>/Constant'
   *  Product: '<S1>/Product'
   *  RelationalOperator: '<S2>/Compare'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtY.stepperLeftENA = (real_T)(fabs(rtDW.UnitDelay_DSTATE) > 0.0002) *
    rtb_Integrator_n;

  /* Signum: '<S1>/Sign1' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  if (rtIsNaN(rtDW.UnitDelay_DSTATE)) {
    rtb_Integrator_n = (rtNaN);
  } else if (rtDW.UnitDelay_DSTATE < 0.0) {
    rtb_Integrator_n = -1.0;
  } else {
    rtb_Integrator_n = (rtDW.UnitDelay_DSTATE > 0.0);
  }

  /* End of Signum: '<S1>/Sign1' */

  /* Saturate: '<S1>/Saturation1' incorporates:
   *  Gain: '<S1>/Gain1'
   */
  if (-rtb_Integrator_n < 0.0) {
    /* Outport: '<Root>/stepperLeftREV' */
    rtY.stepperLeftREV = 0.0;
  } else {
    /* Outport: '<Root>/stepperLeftREV' */
    rtY.stepperLeftREV = -rtb_Integrator_n;
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* DiscretePulseGenerator: '<S1>/Pulse Generator1' */
  rtb_Integrator_n = ((rtDW.clockTickCounter_h < 1L) && (rtDW.clockTickCounter_h
    >= 0L));
  if (rtDW.clockTickCounter_h >= 1L) {
    rtDW.clockTickCounter_h = 0L;
  } else {
    rtDW.clockTickCounter_h++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator1' */

  /* Outport: '<Root>/stepperRightENA' incorporates:
   *  Abs: '<S1>/Abs1'
   *  Constant: '<S3>/Constant'
   *  Product: '<S1>/Product1'
   *  RelationalOperator: '<S3>/Compare'
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  rtY.stepperRightENA = (real_T)(fabs(rtDW.UnitDelay3_DSTATE) > 0.0002) *
    rtb_Integrator_n;

  /* Signum: '<S1>/Sign2' incorporates:
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  if (rtIsNaN(rtDW.UnitDelay3_DSTATE)) {
    rtb_Integrator_n = (rtNaN);
  } else if (rtDW.UnitDelay3_DSTATE < 0.0) {
    rtb_Integrator_n = -1.0;
  } else {
    rtb_Integrator_n = (rtDW.UnitDelay3_DSTATE > 0.0);
  }

  /* End of Signum: '<S1>/Sign2' */

  /* Saturate: '<S1>/Saturation2' incorporates:
   *  Gain: '<S1>/Gain4'
   */
  if (-rtb_Integrator_n < 0.0) {
    /* Outport: '<Root>/stepperRightREV' */
    rtY.stepperRightREV = 0.0;
  } else {
    /* Outport: '<Root>/stepperRightREV' */
    rtY.stepperRightREV = -rtb_Integrator_n;
  }

  /* End of Saturate: '<S1>/Saturation2' */

  /* Saturate: '<S1>/Saturation5' incorporates:
   *  UnitDelay: '<S1>/Unit Delay8'
   */
  if (rtDW.UnitDelay8_DSTATE > 5.0) {
    /* Outport: '<Root>/controlJaw' */
    rtY.controlJaw = 5.0;
  } else if (rtDW.UnitDelay8_DSTATE < -5.0) {
    /* Outport: '<Root>/controlJaw' */
    rtY.controlJaw = -5.0;
  } else {
    /* Outport: '<Root>/controlJaw' */
    rtY.controlJaw = rtDW.UnitDelay8_DSTATE;
  }

  /* End of Saturate: '<S1>/Saturation5' */

  /* Saturate: '<S1>/Saturation4' incorporates:
   *  UnitDelay: '<S1>/Unit Delay6'
   */
  if (rtDW.UnitDelay6_DSTATE > 5.0) {
    /* Outport: '<Root>/controlWristRotation' */
    rtY.controlWristRotation = 5.0;
  } else if (rtDW.UnitDelay6_DSTATE < -5.0) {
    /* Outport: '<Root>/controlWristRotation' */
    rtY.controlWristRotation = -5.0;
  } else {
    /* Outport: '<Root>/controlWristRotation' */
    rtY.controlWristRotation = rtDW.UnitDelay6_DSTATE;
  }

  /* End of Saturate: '<S1>/Saturation4' */

  /* Saturate: '<S1>/Saturation3' incorporates:
   *  UnitDelay: '<S1>/Unit Delay4'
   */
  if (rtDW.UnitDelay4_DSTATE > 5.0) {
    /* Outport: '<Root>/controlGripperPitch' */
    rtY.controlGripperPitch = 5.0;
  } else if (rtDW.UnitDelay4_DSTATE < -5.0) {
    /* Outport: '<Root>/controlGripperPitch' */
    rtY.controlGripperPitch = -5.0;
  } else {
    /* Outport: '<Root>/controlGripperPitch' */
    rtY.controlGripperPitch = rtDW.UnitDelay4_DSTATE;
  }

  /* End of Saturate: '<S1>/Saturation3' */

  /* Saturate: '<S1>/Saturation' incorporates:
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  if (rtDW.UnitDelay1_DSTATE > 5.0) {
    /* Outport: '<Root>/controlBase' */
    rtY.controlBase = 5.0;
  } else if (rtDW.UnitDelay1_DSTATE < -5.0) {
    /* Outport: '<Root>/controlBase' */
    rtY.controlBase = -5.0;
  } else {
    /* Outport: '<Root>/controlBase' */
    rtY.controlBase = rtDW.UnitDelay1_DSTATE;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* MATLAB Function: '<S1>/inverse kinematics' incorporates:
   *  Inport: '<Root>/gripperAng'
   *  Inport: '<Root>/x'
   *  Inport: '<Root>/y'
   *  Inport: '<Root>/z'
   */
  alpha = rtU.gripperAng * 0.017453292519943295;
  if (rtU.x < 0.0) {
    rtb_Integrator_n = atan(rtU.y / rtU.x) + 3.1415926535897931;
  } else {
    rtb_Integrator_n = atan(rtU.y / rtU.x);
  }

  angToBase = rtb_Integrator_n - 3.1415926535897931;
  if (rtb_Integrator_n > 3.1415926535897931) {
    rtb_Integrator_n -= 6.2831853071795862;
  }

  XEi = sin(angToBase);
  rtb_IntegralGain = cos(angToBase);
  rtb_ProportionalGain = sin(alpha);
  theta2 = cos(alpha);
  rtb_IntegralGain_0[0] = rtb_IntegralGain;
  rtb_IntegralGain_0[4] = -XEi;
  rtb_IntegralGain_0[8] = 0.0;
  rtb_IntegralGain_0[12] = rtU.x;
  rtb_IntegralGain_0[1] = XEi;
  rtb_IntegralGain_0[5] = rtb_IntegralGain;
  rtb_IntegralGain_0[9] = 0.0;
  rtb_IntegralGain_0[13] = rtU.y;
  rtb_IntegralGain_0[2] = 0.0;
  rtb_IntegralGain_0[6] = 0.0;
  rtb_IntegralGain_0[10] = 1.0;
  rtb_IntegralGain_0[14] = rtU.z;
  theta2_0[0] = theta2;
  theta2_0[4] = -rtb_ProportionalGain;
  theta2_0[8] = 0.0;
  theta2_0[12] = 0.0;
  theta2_0[1] = rtb_ProportionalGain;
  theta2_0[5] = theta2;
  theta2_0[9] = 0.0;
  theta2_0[13] = 0.0;
  for (i = 0; i < 4; i++) {
    rtb_angles_0 = b[i];
    rtb_angles[i] = rtb_angles_0;
    P6i_tmp_0 = c[i];
    P6i_tmp[i] = (int8_T)P6i_tmp_0;
    rtb_IntegralGain_tmp = i << 2;
    rtb_IntegralGain_0[rtb_IntegralGain_tmp + 3] = rtb_angles_0;
    theta2_0[rtb_IntegralGain_tmp + 2] = P6i_tmp_0;
    theta2_0[rtb_IntegralGain_tmp + 3] = rtb_angles_0;
    rtb_IntegralGain_1[rtb_IntegralGain_tmp] = 0.0;
    rtb_IntegralGain_1[rtb_IntegralGain_tmp + 1] = 0.0;
    rtb_IntegralGain_1[rtb_IntegralGain_tmp + 2] = 0.0;
    rtb_IntegralGain_1[rtb_IntegralGain_tmp + 3] = 0.0;
  }

  for (i = 0; i < 4; i++) {
    rtb_IntegralGain_tmp = i << 2;
    rtb_IntegralGain = rtb_IntegralGain_1[rtb_IntegralGain_tmp];
    angToBase = rtb_IntegralGain_1[rtb_IntegralGain_tmp + 1];
    theta2 = rtb_IntegralGain_1[rtb_IntegralGain_tmp + 2];
    XEi = rtb_IntegralGain_1[rtb_IntegralGain_tmp + 3];
    for (rtb_angles_0 = 0; rtb_angles_0 < 4; rtb_angles_0++) {
      P6i_tmp_0 = rtb_IntegralGain_tmp + rtb_angles_0;
      theta2_tmp = b_b[P6i_tmp_0];
      rtb_IntegralGain_tmp_0 = rtb_angles_0 << 2;
      rtb_IntegralGain += rtb_IntegralGain_0[rtb_IntegralGain_tmp_0] * (real_T)
        theta2_tmp;
      angToBase += rtb_IntegralGain_0[rtb_IntegralGain_tmp_0 + 1] * (real_T)
        theta2_tmp;
      theta2 += rtb_IntegralGain_0[rtb_IntegralGain_tmp_0 + 2] * (real_T)
        theta2_tmp;
      XEi += rtb_IntegralGain_0[rtb_IntegralGain_tmp_0 + 3] * (real_T)theta2_tmp;
      theta2_1[P6i_tmp_0] = 0.0;
    }

    rtb_IntegralGain_1[rtb_IntegralGain_tmp + 3] = XEi;
    rtb_IntegralGain_1[rtb_IntegralGain_tmp + 2] = theta2;
    rtb_IntegralGain_1[rtb_IntegralGain_tmp + 1] = angToBase;
    rtb_IntegralGain_1[rtb_IntegralGain_tmp] = rtb_IntegralGain;
    theta2 = theta2_1[rtb_IntegralGain_tmp];
    angToBase = theta2_1[rtb_IntegralGain_tmp + 1];
    XEi = theta2_1[rtb_IntegralGain_tmp + 2];
    rtb_ProportionalGain = theta2_1[rtb_IntegralGain_tmp + 3];
    for (rtb_angles_0 = 0; rtb_angles_0 < 4; rtb_angles_0++) {
      P6i_tmp_0 = rtb_IntegralGain_tmp + rtb_angles_0;
      rtb_IntegralGain = c_b[P6i_tmp_0];
      theta2_tmp = rtb_angles_0 << 2;
      theta2 += theta2_0[theta2_tmp] * rtb_IntegralGain;
      angToBase += theta2_0[theta2_tmp + 1] * rtb_IntegralGain;
      XEi += theta2_0[theta2_tmp + 2] * rtb_IntegralGain;
      rtb_ProportionalGain += theta2_0[theta2_tmp + 3] * rtb_IntegralGain;
      P6i[P6i_tmp_0] = 0.0;
    }

    theta2_1[rtb_IntegralGain_tmp + 3] = rtb_ProportionalGain;
    theta2_1[rtb_IntegralGain_tmp + 2] = XEi;
    theta2_1[rtb_IntegralGain_tmp + 1] = angToBase;
    theta2_1[rtb_IntegralGain_tmp] = theta2;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_0 = i << 2;
    theta2 = P6i[P6i_tmp_0];
    XEi = P6i[P6i_tmp_0 + 1];
    rtb_ProportionalGain = P6i[P6i_tmp_0 + 2];
    P6i_0 = P6i[P6i_tmp_0 + 3];
    for (rtb_angles_0 = 0; rtb_angles_0 < 4; rtb_angles_0++) {
      rtb_IntegralGain = theta2_1[P6i_tmp_0 + rtb_angles_0];
      rtb_IntegralGain_tmp = rtb_angles_0 << 2;
      theta2 += rtb_IntegralGain_1[rtb_IntegralGain_tmp] * rtb_IntegralGain;
      XEi += rtb_IntegralGain_1[rtb_IntegralGain_tmp + 1] * rtb_IntegralGain;
      rtb_ProportionalGain += rtb_IntegralGain_1[rtb_IntegralGain_tmp + 2] *
        rtb_IntegralGain;
      P6i_0 += rtb_IntegralGain_1[rtb_IntegralGain_tmp + 3] * rtb_IntegralGain;
    }

    P6i[P6i_tmp_0 + 3] = P6i_0;
    P6i[P6i_tmp_0 + 2] = rtb_ProportionalGain;
    P6i[P6i_tmp_0 + 1] = XEi;
    P6i[P6i_tmp_0] = theta2;
  }

  XEi = sqrt(P6i[12] * P6i[12] + P6i[13] * P6i[13]);
  rtb_IntegralGain = XEi * XEi;
  theta2 = (P6i[14] - 0.065) * (P6i[14] - 0.065);
  angToBase = (((((((rtb_IntegralGain * 0.24499999999999997 + 0.04624375) +
                    theta2 * 0.24499999999999997) - 0.0625) + rtb_IntegralGain *
                  0.5) + theta2 * 0.5) - rt_powd_snf(XEi, 4.0)) -
               rtb_IntegralGain * 2.0 * theta2) - rt_powd_snf(P6i[14] - 0.065,
    4.0);
  if (angToBase < 0.0) {
    rtb_angles[0] = 0.0;
    rtb_angles[1] = 1.5707963267948966;
    rtb_angles[2] = 0.0;
    rtb_angles[3] = 3.1415926535897931;

    /* Outport: '<Root>/error' */
    rtY.error = 1.0;
  } else {
    angToBase = atan(((P6i[14] - 0.065) * 0.7 + sqrt(angToBase)) / ((((0.7 * XEi
      + 0.12249999999999998) - 0.25) + rtb_IntegralGain) + theta2)) * 2.0;
    XEi = (rtb_IntegralGain - 0.02250000000000002) + theta2;
    theta2 = atan(sqrt(((0.72249999999999992 - rtb_IntegralGain) - theta2) * XEi)
                  / XEi) * -2.0;
    alpha = (-alpha - angToBase) - theta2;
    XEi = sin(angToBase);
    rtb_IntegralGain = cos(angToBase);
    rtb_ProportionalGain = sin(theta2);
    theta2 = cos(theta2);
    rtb_IntegralGain_0[0] = rtb_IntegralGain;
    rtb_IntegralGain_0[4] = -XEi;
    rtb_IntegralGain_0[8] = 0.0;
    rtb_IntegralGain_0[12] = 0.0;
    rtb_IntegralGain_0[1] = XEi;
    rtb_IntegralGain_0[5] = rtb_IntegralGain;
    rtb_IntegralGain_0[9] = 0.0;
    rtb_IntegralGain_0[13] = 0.0;
    for (i = 0; i < 4; i++) {
      rtb_IntegralGain_tmp = i << 2;
      rtb_IntegralGain_0[rtb_IntegralGain_tmp + 2] = P6i_tmp[i];
      rtb_IntegralGain_0[rtb_IntegralGain_tmp + 3] = rtb_angles[i];
      XEi = 0.0;
      P6i_0 = 0.0;
      a = 0.0;
      a_0 = 0.0;
      for (rtb_angles_0 = 0; rtb_angles_0 < 4; rtb_angles_0++) {
        rtb_IntegralGain = rtb_IntegralGain_0[rtb_IntegralGain_tmp +
          rtb_angles_0];
        P6i_tmp_0 = rtb_angles_0 << 2;
        XEi += a_1[P6i_tmp_0] * rtb_IntegralGain;
        P6i_0 += a_1[P6i_tmp_0 + 1] * rtb_IntegralGain;
        a += a_1[P6i_tmp_0 + 2] * rtb_IntegralGain;
        a_0 += a_1[P6i_tmp_0 + 3] * rtb_IntegralGain;
      }

      P6i[rtb_IntegralGain_tmp + 3] = a_0;
      P6i[rtb_IntegralGain_tmp + 2] = a;
      P6i[rtb_IntegralGain_tmp + 1] = P6i_0;
      P6i[rtb_IntegralGain_tmp] = XEi;
    }

    theta2_0[0] = theta2;
    theta2_0[4] = -rtb_ProportionalGain;
    theta2_0[8] = 0.0;
    theta2_0[12] = 0.35;
    theta2_0[1] = rtb_ProportionalGain;
    theta2_0[5] = theta2;
    theta2_0[9] = 0.0;
    theta2_0[13] = 0.0;
    for (i = 0; i < 4; i++) {
      theta2_tmp = i << 2;
      theta2_0[theta2_tmp + 2] = P6i_tmp[i];
      theta2_0[theta2_tmp + 3] = rtb_angles[i];
      theta2 = 0.0;
      XEi = 0.0;
      rtb_ProportionalGain = 0.0;
      P6i_0 = 0.0;
      for (rtb_angles_0 = 0; rtb_angles_0 < 4; rtb_angles_0++) {
        P6i_tmp_0 = theta2_tmp + rtb_angles_0;
        rtb_IntegralGain = P6i[P6i_tmp_0];
        rtb_IntegralGain_tmp = rtb_angles_0 << 2;
        theta2 += (real_T)b_a[rtb_IntegralGain_tmp] * rtb_IntegralGain;
        XEi += (real_T)b_a[rtb_IntegralGain_tmp + 1] * rtb_IntegralGain;
        rtb_ProportionalGain += (real_T)b_a[rtb_IntegralGain_tmp + 2] *
          rtb_IntegralGain;
        P6i_0 += (real_T)b_a[rtb_IntegralGain_tmp + 3] * rtb_IntegralGain;
        rtb_IntegralGain_0[P6i_tmp_0] = 0.0;
      }

      rtb_IntegralGain_1[theta2_tmp + 3] = P6i_0;
      rtb_IntegralGain_1[theta2_tmp + 2] = rtb_ProportionalGain;
      rtb_IntegralGain_1[theta2_tmp + 1] = XEi;
      rtb_IntegralGain_1[theta2_tmp] = theta2;
    }

    for (i = 0; i < 4; i++) {
      rtb_IntegralGain_tmp = i << 2;
      theta2 = rtb_IntegralGain_0[rtb_IntegralGain_tmp];
      XEi = rtb_IntegralGain_0[rtb_IntegralGain_tmp + 1];
      rtb_ProportionalGain = rtb_IntegralGain_0[rtb_IntegralGain_tmp + 2];
      P6i_0 = rtb_IntegralGain_0[rtb_IntegralGain_tmp + 3];
      for (rtb_angles_0 = 0; rtb_angles_0 < 4; rtb_angles_0++) {
        rtb_IntegralGain = theta2_0[rtb_IntegralGain_tmp + rtb_angles_0];
        P6i_tmp_0 = rtb_angles_0 << 2;
        theta2 += rtb_IntegralGain_1[P6i_tmp_0] * rtb_IntegralGain;
        XEi += rtb_IntegralGain_1[P6i_tmp_0 + 1] * rtb_IntegralGain;
        rtb_ProportionalGain += rtb_IntegralGain_1[P6i_tmp_0 + 2] *
          rtb_IntegralGain;
        P6i_0 += rtb_IntegralGain_1[P6i_tmp_0 + 3] * rtb_IntegralGain;
      }

      rtb_IntegralGain_0[rtb_IntegralGain_tmp + 3] = P6i_0;
      rtb_IntegralGain_0[rtb_IntegralGain_tmp + 2] = rtb_ProportionalGain;
      rtb_IntegralGain_0[rtb_IntegralGain_tmp + 1] = XEi;
      rtb_IntegralGain_0[rtb_IntegralGain_tmp] = theta2;
    }

    for (i = 0; i < 4; i++) {
      theta2 = 0.0;
      XEi = 0.0;
      rtb_ProportionalGain = 0.0;
      P6i_0 = 0.0;
      for (rtb_angles_0 = 0; rtb_angles_0 < 4; rtb_angles_0++) {
        rtb_IntegralGain = d_b[(i << 2) + rtb_angles_0];
        P6i_tmp_0 = rtb_angles_0 << 2;
        theta2 += rtb_IntegralGain_0[P6i_tmp_0] * rtb_IntegralGain;
        XEi += rtb_IntegralGain_0[P6i_tmp_0 + 1] * rtb_IntegralGain;
        rtb_ProportionalGain += rtb_IntegralGain_0[P6i_tmp_0 + 2] *
          rtb_IntegralGain;
        P6i_0 += rtb_IntegralGain_0[P6i_tmp_0 + 3] * rtb_IntegralGain;
      }

      P6i_tmp_0 = i << 2;
      P6i[P6i_tmp_0 + 3] = P6i_0;
      P6i[P6i_tmp_0 + 2] = rtb_ProportionalGain;
      P6i[P6i_tmp_0 + 1] = XEi;
      P6i[P6i_tmp_0] = theta2;
    }

    rtb_IntegralGain = P6i[12] * P6i[12];
    theta2 = (P6i[14] - 0.149) * (P6i[14] - 0.149);
    XEi = atan((sqrt((((((((rtb_IntegralGain * 0.0288 + 0.00205056) + theta2 *
      0.0288) - 0.0061465600000000023) + rtb_IntegralGain * 0.15680000000000002)
                        + theta2 * 0.15680000000000002) - rt_powd_snf(P6i[12],
      4.0)) - rtb_IntegralGain * 2.0 * theta2) - rt_powd_snf(P6i[14] - 0.149,
      4.0)) + (P6i[14] - 0.149) * 0.24) / ((((0.24 * P6i[12] + 0.0144) -
      0.078400000000000011) + rtb_IntegralGain) + theta2)) * 2.0;
    if ((fabs(rtb_Integrator_n) > 3.1415926535897931) || ((angToBase < 0.0) ||
         (angToBase > 2.3561944901923448) || (alpha < -2.3561944901923448) ||
         (alpha > 0.78539816339744828) || (XEi < 1.5707963267948966) || (XEi >
          4.71238898038469))) {
      rtb_angles[0] = 0.0;
      rtb_angles[1] = 1.5707963267948966;
      rtb_angles[2] = 0.0;
      rtb_angles[3] = 3.1415926535897931;

      /* Outport: '<Root>/error' */
      rtY.error = 2.0;
    } else {
      rtb_angles[0] = rtb_Integrator_n;
      rtb_angles[1] = angToBase;
      rtb_angles[2] = alpha;
      rtb_angles[3] = XEi;

      /* Outport: '<Root>/error' */
      rtY.error = 0.0;
    }
  }

  /* End of MATLAB Function: '<S1>/inverse kinematics' */

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/Pi'
   *  Inport: '<Root>/stepperLeftActualPosition'
   *  Sum: '<S1>/Sum'
   */
  alpha = (rtb_angles[3] + 1.5707963267948966) - rtU.actualposition_c;

  /* Sum: '<S1>/Sum4' incorporates:
   *  Inport: '<Root>/gripperPitchActualPosition'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  rtb_Integrator_n = rtDW.UnitDelay2_DSTATE - rtU.actualposition_p;

  /* Sum: '<S1>/Sum2' incorporates:
   *  Inport: '<Root>/baseActualPosition'
   *  UnitDelay: '<S1>/Unit Delay5'
   */
  angToBase = rtDW.UnitDelay5_DSTATE - rtU.actualposition_pe;

  /* Sum: '<S1>/Sum3' incorporates:
   *  Constant: '<S1>/Pi1'
   *  Inport: '<Root>/stepperRightActualPosition'
   *  Sum: '<S1>/Sum7'
   */
  XEi = (rtb_angles[1] + 1.5707963267948966) - rtU.actualposition_ps;

  /* Outport: '<Root>/pointReached' incorporates:
   *  Abs: '<S1>/Abs2'
   *  Abs: '<S1>/Abs3'
   *  Abs: '<S1>/Abs4'
   *  Abs: '<S1>/Abs5'
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   *  Sum: '<S1>/Sum8'
   */
  rtY.pointReached = (((fabs(rtb_Integrator_n) + fabs(angToBase)) + fabs(alpha))
                      + fabs(XEi) <= 0.001);

  /* Gain: '<S45>/Integral Gain' */
  rtb_IntegralGain = 0.2 * angToBase;

  /* Update for UnitDelay: '<S1>/Unit Delay5' incorporates:
   *  Gain: '<S1>/Gain11'
   *  Gain: '<S1>/Gain6'
   *  Gain: '<S1>/Gain8'
   *  Inport: '<Root>/deltaTime'
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  MATLABFunction(rtDW.UnitDelay5_DSTATE, 63.0 * -rtb_angles[0], 20.0 *
                 rtU.deltaTime, &rtDW.UnitDelay5_DSTATE);

  /* Gain: '<S97>/Integral Gain' */
  theta2 = 0.1 * rtb_Integrator_n;

  /* Update for UnitDelay: '<S1>/Unit Delay2' incorporates:
   *  Gain: '<S1>/Gain10'
   *  Gain: '<S1>/Gain12'
   *  Inport: '<Root>/deltaTime'
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  MATLABFunction(rtDW.UnitDelay2_DSTATE, 21.0 * rtb_angles[2], 4.2 *
                 rtU.deltaTime, &rtDW.UnitDelay2_DSTATE);

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain5'
   *  Gain: '<S1>/Gain9'
   *  Inport: '<Root>/deltaTime'
   *  Inport: '<Root>/gripperRotationDesiredPosition'
   *  UnitDelay: '<S1>/Unit Delay7'
   */
  MATLABFunction(rtDW.UnitDelay7_DSTATE, 21.0 * (0.017453292519943295 *
    rtU.gripperRotationDesiredPosition), 21.0 * rtU.deltaTime, &angToBase);

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Gain3'
   *  Gain: '<S1>/Gain7'
   *  Inport: '<Root>/deltaTime'
   *  Inport: '<Root>/jawDesiredPosition'
   *  UnitDelay: '<S1>/Unit Delay9'
   */
  MATLABFunction(rtDW.UnitDelay9_DSTATE, 21.0 * (0.017453292519943295 *
    rtU.jawDesiredPosition), 2.1 * rtU.deltaTime, &rtb_Integrator_n);

  /* Sum: '<S1>/Sum6' incorporates:
   *  Inport: '<Root>/jawActualPosition'
   *  UnitDelay: '<S1>/Unit Delay9'
   */
  rtb_ProportionalGain = rtDW.UnitDelay9_DSTATE - rtU.actualposition;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = alpha;

  /* Update for UnitDelay: '<S1>/Unit Delay3' */
  rtDW.UnitDelay3_DSTATE = XEi;

  /* Update for UnitDelay: '<S1>/Unit Delay8' incorporates:
   *  DiscreteIntegrator: '<S204>/Integrator'
   *  Gain: '<S209>/Proportional Gain'
   *  Sum: '<S213>/Sum'
   */
  rtDW.UnitDelay8_DSTATE = 2.0 * rtb_ProportionalGain + rtDW.Integrator_DSTATE_d;

  /* Gain: '<S157>/Proportional Gain' incorporates:
   *  Gain: '<S149>/Integral Gain'
   *  Inport: '<Root>/gripperRotationActualPosition'
   *  Sum: '<S1>/Sum5'
   *  UnitDelay: '<S1>/Unit Delay7'
   */
  alpha = (rtDW.UnitDelay7_DSTATE - rtU.actualposition_g) * 0.2;

  /* Update for UnitDelay: '<S1>/Unit Delay6' incorporates:
   *  DiscreteIntegrator: '<S152>/Integrator'
   *  Gain: '<S157>/Proportional Gain'
   *  Sum: '<S161>/Sum'
   */
  rtDW.UnitDelay6_DSTATE = alpha + rtDW.Integrator_DSTATE_g;

  /* Update for UnitDelay: '<S1>/Unit Delay4' incorporates:
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Gain: '<S105>/Proportional Gain'
   *  Sum: '<S109>/Sum'
   */
  rtDW.UnitDelay4_DSTATE = theta2 + rtDW.Integrator_DSTATE_i;

  /* Update for UnitDelay: '<S1>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S48>/Integrator'
   *  Gain: '<S53>/Proportional Gain'
   *  Sum: '<S57>/Sum'
   */
  rtDW.UnitDelay1_DSTATE = rtb_IntegralGain + rtDW.Integrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S48>/Integrator' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S61>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE += rtb_IntegralGain * rtU.deltaTime;

  /* Update for DiscreteIntegrator: '<S100>/Integrator' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S113>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE_i += theta2 * rtU.deltaTime;

  /* Update for UnitDelay: '<S1>/Unit Delay7' */
  rtDW.UnitDelay7_DSTATE = angToBase;

  /* Update for DiscreteIntegrator: '<S152>/Integrator' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S165>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE_g += alpha * rtU.deltaTime;

  /* Update for UnitDelay: '<S1>/Unit Delay9' */
  rtDW.UnitDelay9_DSTATE = rtb_Integrator_n;

  /* Update for DiscreteIntegrator: '<S204>/Integrator' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S217>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE_d += rtb_ProportionalGain * rtU.deltaTime;
}

/* Model initialize function */
void control0_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
