/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control0.c
 *
 * Code generated for Simulink model 'control0'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Fri Feb 13 12:09:22 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "control0.h"
#include <math.h>
#include "rtwtypes.h"
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
  real_T P6i_tmp_1[16];
  real_T P6i_tmp_2[16];
  real_T theta2_0[16];
  real_T theta2_1[16];
  real_T rtb_angles[4];
  real_T P6i_0;
  real_T P6i_tmp;
  real_T XEi;
  real_T a;
  real_T alpha;
  real_T angToBase;
  real_T rtb_Gain8;
  real_T rtb_Integrator_e;
  real_T theta0;
  real_T theta2;
  int16_T P6i_tmp_3;
  int16_T P6i_tmp_tmp;
  int16_T P6i_tmp_tmp_0;
  int16_T i;
  int16_T rtb_angles_0;
  int16_T theta2_tmp;
  int8_T P6i_tmp_0[4];
  static const int8_T b[4] = { 0, 0, 0, 1 };

  static const int8_T c[4] = { 0, 0, 1, 0 };

  static const int8_T b_b[16] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0,
    1 };

  static const real_T c_b[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.3, 0.0, 0.0, 1.0 };

  static const real_T a_0[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.03325, 1.0 };

  static const real_T d_b[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, -0.12, 0.0, 0.0, 1.0 };

  static const int8_T b_a[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  rtb_Integrator_e = ((rtDW.clockTickCounter < 1L) && (rtDW.clockTickCounter >=
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
   *  Gain: '<S1>/Gain3'
   *  Product: '<S1>/Product'
   *  RelationalOperator: '<S2>/Compare'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtY.stepperLeftENA = (real_T)(fabs(rtDW.UnitDelay_DSTATE) > 0.0002) *
    rtb_Integrator_e * 5.0;

  /* Signum: '<S1>/Sign1' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  if (rtIsNaN(rtDW.UnitDelay_DSTATE)) {
    /* Gain: '<S1>/Gain1' */
    alpha = (rtNaN);
  } else if (rtDW.UnitDelay_DSTATE < 0.0) {
    /* Gain: '<S1>/Gain1' */
    alpha = 1.0;
  } else {
    /* Gain: '<S1>/Gain1' */
    alpha = -(real_T)(rtDW.UnitDelay_DSTATE > 0.0);
  }

  /* End of Signum: '<S1>/Sign1' */

  /* Saturate: '<S1>/Saturation1' */
  if (alpha < 0.0) {
    alpha = 0.0;
  }

  /* Outport: '<Root>/stepperLeftREV' incorporates:
   *  Gain: '<S1>/Gain2'
   *  Saturate: '<S1>/Saturation1'
   */
  rtY.stepperLeftREV = 5.0 * alpha;

  /* DiscretePulseGenerator: '<S1>/Pulse Generator1' */
  rtb_Integrator_e = ((rtDW.clockTickCounter_h < 1L) && (rtDW.clockTickCounter_h
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
   *  Gain: '<S1>/Gain6'
   *  Product: '<S1>/Product1'
   *  RelationalOperator: '<S3>/Compare'
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  rtY.stepperRightENA = (real_T)(fabs(rtDW.UnitDelay3_DSTATE) > 0.0002) *
    rtb_Integrator_e * 5.0;

  /* Signum: '<S1>/Sign2' incorporates:
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  if (rtIsNaN(rtDW.UnitDelay3_DSTATE)) {
    /* Gain: '<S1>/Gain4' */
    alpha = (rtNaN);
  } else if (rtDW.UnitDelay3_DSTATE < 0.0) {
    /* Gain: '<S1>/Gain4' */
    alpha = 1.0;
  } else {
    /* Gain: '<S1>/Gain4' */
    alpha = -(real_T)(rtDW.UnitDelay3_DSTATE > 0.0);
  }

  /* End of Signum: '<S1>/Sign2' */

  /* Saturate: '<S1>/Saturation2' */
  if (alpha < 0.0) {
    alpha = 0.0;
  }

  /* Outport: '<Root>/stepperRightREV' incorporates:
   *  Gain: '<S1>/Gain5'
   *  Saturate: '<S1>/Saturation2'
   */
  rtY.stepperRightREV = 5.0 * alpha;

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
    theta0 = atan(rtU.y / rtU.x) + 3.1415926535897931;
  } else {
    theta0 = atan(rtU.y / rtU.x);
  }

  angToBase = theta0 - 3.1415926535897931;
  if (theta0 > 3.1415926535897931) {
    theta0 -= 6.2831853071795862;
  }

  XEi = sin(angToBase);
  P6i_tmp = cos(angToBase);
  rtb_Gain8 = sin(alpha);
  theta2 = cos(alpha);
  P6i_tmp_1[0] = P6i_tmp;
  P6i_tmp_1[4] = -XEi;
  P6i_tmp_1[8] = 0.0;
  P6i_tmp_1[12] = rtU.x;
  P6i_tmp_1[1] = XEi;
  P6i_tmp_1[5] = P6i_tmp;
  P6i_tmp_1[9] = 0.0;
  P6i_tmp_1[13] = rtU.y;
  P6i_tmp_1[2] = 0.0;
  P6i_tmp_1[6] = 0.0;
  P6i_tmp_1[10] = 1.0;
  P6i_tmp_1[14] = rtU.z;
  theta2_0[0] = theta2;
  theta2_0[4] = -rtb_Gain8;
  theta2_0[8] = 0.0;
  theta2_0[12] = 0.0;
  theta2_0[1] = rtb_Gain8;
  theta2_0[5] = theta2;
  theta2_0[9] = 0.0;
  theta2_0[13] = 0.0;
  for (i = 0; i < 4; i++) {
    rtb_angles_0 = b[i];
    rtb_angles[i] = rtb_angles_0;
    P6i_tmp_3 = c[i];
    P6i_tmp_0[i] = (int8_T)P6i_tmp_3;
    P6i_tmp_tmp = i << 2;
    P6i_tmp_1[P6i_tmp_tmp + 3] = rtb_angles_0;
    theta2_0[P6i_tmp_tmp + 2] = P6i_tmp_3;
    theta2_0[P6i_tmp_tmp + 3] = rtb_angles_0;
    P6i_tmp_2[P6i_tmp_tmp] = 0.0;
    P6i_tmp_2[P6i_tmp_tmp + 1] = 0.0;
    P6i_tmp_2[P6i_tmp_tmp + 2] = 0.0;
    P6i_tmp_2[P6i_tmp_tmp + 3] = 0.0;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_tmp = i << 2;
    P6i_tmp = P6i_tmp_2[P6i_tmp_tmp];
    angToBase = P6i_tmp_2[P6i_tmp_tmp + 1];
    theta2 = P6i_tmp_2[P6i_tmp_tmp + 2];
    rtb_Gain8 = P6i_tmp_2[P6i_tmp_tmp + 3];
    for (rtb_angles_0 = 0; rtb_angles_0 < 4; rtb_angles_0++) {
      P6i_tmp_3 = P6i_tmp_tmp + rtb_angles_0;
      theta2_tmp = b_b[P6i_tmp_3];
      P6i_tmp_tmp_0 = rtb_angles_0 << 2;
      P6i_tmp += P6i_tmp_1[P6i_tmp_tmp_0] * (real_T)theta2_tmp;
      angToBase += P6i_tmp_1[P6i_tmp_tmp_0 + 1] * (real_T)theta2_tmp;
      theta2 += P6i_tmp_1[P6i_tmp_tmp_0 + 2] * (real_T)theta2_tmp;
      rtb_Gain8 += P6i_tmp_1[P6i_tmp_tmp_0 + 3] * (real_T)theta2_tmp;
      theta2_1[P6i_tmp_3] = 0.0;
    }

    P6i_tmp_2[P6i_tmp_tmp + 3] = rtb_Gain8;
    P6i_tmp_2[P6i_tmp_tmp + 2] = theta2;
    P6i_tmp_2[P6i_tmp_tmp + 1] = angToBase;
    P6i_tmp_2[P6i_tmp_tmp] = P6i_tmp;
    theta2 = theta2_1[P6i_tmp_tmp];
    angToBase = theta2_1[P6i_tmp_tmp + 1];
    rtb_Gain8 = theta2_1[P6i_tmp_tmp + 2];
    XEi = theta2_1[P6i_tmp_tmp + 3];
    for (rtb_angles_0 = 0; rtb_angles_0 < 4; rtb_angles_0++) {
      P6i_tmp_3 = P6i_tmp_tmp + rtb_angles_0;
      P6i_tmp = c_b[P6i_tmp_3];
      theta2_tmp = rtb_angles_0 << 2;
      theta2 += theta2_0[theta2_tmp] * P6i_tmp;
      angToBase += theta2_0[theta2_tmp + 1] * P6i_tmp;
      rtb_Gain8 += theta2_0[theta2_tmp + 2] * P6i_tmp;
      XEi += theta2_0[theta2_tmp + 3] * P6i_tmp;
      P6i[P6i_tmp_3] = 0.0;
    }

    theta2_1[P6i_tmp_tmp + 3] = XEi;
    theta2_1[P6i_tmp_tmp + 2] = rtb_Gain8;
    theta2_1[P6i_tmp_tmp + 1] = angToBase;
    theta2_1[P6i_tmp_tmp] = theta2;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_3 = i << 2;
    theta2 = P6i[P6i_tmp_3];
    rtb_Gain8 = P6i[P6i_tmp_3 + 1];
    XEi = P6i[P6i_tmp_3 + 2];
    P6i_0 = P6i[P6i_tmp_3 + 3];
    for (rtb_angles_0 = 0; rtb_angles_0 < 4; rtb_angles_0++) {
      P6i_tmp = theta2_1[P6i_tmp_3 + rtb_angles_0];
      P6i_tmp_tmp = rtb_angles_0 << 2;
      theta2 += P6i_tmp_2[P6i_tmp_tmp] * P6i_tmp;
      rtb_Gain8 += P6i_tmp_2[P6i_tmp_tmp + 1] * P6i_tmp;
      XEi += P6i_tmp_2[P6i_tmp_tmp + 2] * P6i_tmp;
      P6i_0 += P6i_tmp_2[P6i_tmp_tmp + 3] * P6i_tmp;
    }

    P6i[P6i_tmp_3 + 3] = P6i_0;
    P6i[P6i_tmp_3 + 2] = XEi;
    P6i[P6i_tmp_3 + 1] = rtb_Gain8;
    P6i[P6i_tmp_3] = theta2;
  }

  XEi = sqrt(P6i[12] * P6i[12] + P6i[13] * P6i[13]);
  P6i_tmp = XEi * XEi;
  theta2 = (P6i[14] - 0.03325) * (P6i[14] - 0.03325);
  angToBase = (((((((P6i_tmp * 0.24499999999999997 + 0.04624375) + theta2 *
                    0.24499999999999997) - 0.0625) + P6i_tmp * 0.5) + theta2 *
                 0.5) - rt_powd_snf(XEi, 4.0)) - P6i_tmp * 2.0 * theta2) -
    rt_powd_snf(P6i[14] - 0.03325, 4.0);
  if (angToBase < 0.0) {
    rtb_angles[0] = 0.0;
    rtb_angles[1] = 1.5707963267948966;
    rtb_angles[2] = 0.0;
    rtb_angles[3] = 3.1415926535897931;

    /* Outport: '<Root>/error' */
    rtY.error = 1.0;
  } else {
    angToBase = atan(((P6i[14] - 0.03325) * 0.7 + sqrt(angToBase)) / ((((0.7 *
      XEi + 0.12249999999999998) - 0.25) + P6i_tmp) + theta2)) * 2.0;
    rtb_Gain8 = (P6i_tmp - 0.02250000000000002) + theta2;
    theta2 = atan(sqrt(((0.72249999999999992 - P6i_tmp) - theta2) * rtb_Gain8) /
                  rtb_Gain8) * -2.0;
    alpha = (-alpha - angToBase) - theta2;
    XEi = sin(angToBase);
    P6i_tmp = cos(angToBase);
    rtb_Gain8 = sin(theta2);
    theta2 = cos(theta2);
    P6i_tmp_1[0] = P6i_tmp;
    P6i_tmp_1[4] = -XEi;
    P6i_tmp_1[8] = 0.0;
    P6i_tmp_1[12] = 0.0;
    P6i_tmp_1[1] = XEi;
    P6i_tmp_1[5] = P6i_tmp;
    P6i_tmp_1[9] = 0.0;
    P6i_tmp_1[13] = 0.0;
    for (i = 0; i < 4; i++) {
      P6i_tmp_tmp = i << 2;
      P6i_tmp_1[P6i_tmp_tmp + 2] = P6i_tmp_0[i];
      P6i_tmp_1[P6i_tmp_tmp + 3] = rtb_angles[i];
      XEi = 0.0;
      P6i_0 = 0.0;
      rtb_Integrator_e = 0.0;
      a = 0.0;
      for (rtb_angles_0 = 0; rtb_angles_0 < 4; rtb_angles_0++) {
        P6i_tmp = P6i_tmp_1[P6i_tmp_tmp + rtb_angles_0];
        P6i_tmp_3 = rtb_angles_0 << 2;
        XEi += a_0[P6i_tmp_3] * P6i_tmp;
        P6i_0 += a_0[P6i_tmp_3 + 1] * P6i_tmp;
        rtb_Integrator_e += a_0[P6i_tmp_3 + 2] * P6i_tmp;
        a += a_0[P6i_tmp_3 + 3] * P6i_tmp;
      }

      P6i[P6i_tmp_tmp + 3] = a;
      P6i[P6i_tmp_tmp + 2] = rtb_Integrator_e;
      P6i[P6i_tmp_tmp + 1] = P6i_0;
      P6i[P6i_tmp_tmp] = XEi;
    }

    theta2_0[0] = theta2;
    theta2_0[4] = -rtb_Gain8;
    theta2_0[8] = 0.0;
    theta2_0[12] = 0.35;
    theta2_0[1] = rtb_Gain8;
    theta2_0[5] = theta2;
    theta2_0[9] = 0.0;
    theta2_0[13] = 0.0;
    for (i = 0; i < 4; i++) {
      theta2_tmp = i << 2;
      theta2_0[theta2_tmp + 2] = P6i_tmp_0[i];
      theta2_0[theta2_tmp + 3] = rtb_angles[i];
      theta2 = 0.0;
      rtb_Gain8 = 0.0;
      XEi = 0.0;
      P6i_0 = 0.0;
      for (rtb_angles_0 = 0; rtb_angles_0 < 4; rtb_angles_0++) {
        P6i_tmp_3 = theta2_tmp + rtb_angles_0;
        P6i_tmp = P6i[P6i_tmp_3];
        P6i_tmp_tmp = rtb_angles_0 << 2;
        theta2 += (real_T)b_a[P6i_tmp_tmp] * P6i_tmp;
        rtb_Gain8 += (real_T)b_a[P6i_tmp_tmp + 1] * P6i_tmp;
        XEi += (real_T)b_a[P6i_tmp_tmp + 2] * P6i_tmp;
        P6i_0 += (real_T)b_a[P6i_tmp_tmp + 3] * P6i_tmp;
        P6i_tmp_1[P6i_tmp_3] = 0.0;
      }

      P6i_tmp_2[theta2_tmp + 3] = P6i_0;
      P6i_tmp_2[theta2_tmp + 2] = XEi;
      P6i_tmp_2[theta2_tmp + 1] = rtb_Gain8;
      P6i_tmp_2[theta2_tmp] = theta2;
    }

    for (i = 0; i < 4; i++) {
      P6i_tmp_tmp = i << 2;
      theta2 = P6i_tmp_1[P6i_tmp_tmp];
      rtb_Gain8 = P6i_tmp_1[P6i_tmp_tmp + 1];
      XEi = P6i_tmp_1[P6i_tmp_tmp + 2];
      P6i_0 = P6i_tmp_1[P6i_tmp_tmp + 3];
      for (rtb_angles_0 = 0; rtb_angles_0 < 4; rtb_angles_0++) {
        P6i_tmp = theta2_0[P6i_tmp_tmp + rtb_angles_0];
        P6i_tmp_3 = rtb_angles_0 << 2;
        theta2 += P6i_tmp_2[P6i_tmp_3] * P6i_tmp;
        rtb_Gain8 += P6i_tmp_2[P6i_tmp_3 + 1] * P6i_tmp;
        XEi += P6i_tmp_2[P6i_tmp_3 + 2] * P6i_tmp;
        P6i_0 += P6i_tmp_2[P6i_tmp_3 + 3] * P6i_tmp;
      }

      P6i_tmp_1[P6i_tmp_tmp + 3] = P6i_0;
      P6i_tmp_1[P6i_tmp_tmp + 2] = XEi;
      P6i_tmp_1[P6i_tmp_tmp + 1] = rtb_Gain8;
      P6i_tmp_1[P6i_tmp_tmp] = theta2;
    }

    for (i = 0; i < 4; i++) {
      theta2 = 0.0;
      rtb_Gain8 = 0.0;
      XEi = 0.0;
      P6i_0 = 0.0;
      for (rtb_angles_0 = 0; rtb_angles_0 < 4; rtb_angles_0++) {
        P6i_tmp = d_b[(i << 2) + rtb_angles_0];
        P6i_tmp_3 = rtb_angles_0 << 2;
        theta2 += P6i_tmp_1[P6i_tmp_3] * P6i_tmp;
        rtb_Gain8 += P6i_tmp_1[P6i_tmp_3 + 1] * P6i_tmp;
        XEi += P6i_tmp_1[P6i_tmp_3 + 2] * P6i_tmp;
        P6i_0 += P6i_tmp_1[P6i_tmp_3 + 3] * P6i_tmp;
      }

      P6i_tmp_3 = i << 2;
      P6i[P6i_tmp_3 + 3] = P6i_0;
      P6i[P6i_tmp_3 + 2] = XEi;
      P6i[P6i_tmp_3 + 1] = rtb_Gain8;
      P6i[P6i_tmp_3] = theta2;
    }

    P6i_tmp = P6i[12] * P6i[12];
    theta2 = (P6i[14] - 0.11725) * (P6i[14] - 0.11725);
    XEi = atan((sqrt((((((((P6i_tmp * 0.0288 + 0.00205056) + theta2 * 0.0288) -
                          0.0061465600000000023) + P6i_tmp * 0.15680000000000002)
                        + theta2 * 0.15680000000000002) - rt_powd_snf(P6i[12],
      4.0)) - P6i_tmp * 2.0 * theta2) - rt_powd_snf(P6i[14] - 0.11725, 4.0)) +
                (P6i[14] - 0.11725) * 0.24) / ((((0.24 * P6i[12] + 0.0144) -
      0.078400000000000011) + P6i_tmp) + theta2)) * 2.0;
    if ((fabs(theta0) > 3.1415926535897931) || ((angToBase < 0.0) || (angToBase >
          2.3561944901923448) || (alpha < -2.3561944901923448) || (alpha >
          0.78539816339744828) || (XEi < 1.5707963267948966) || (XEi >
          4.71238898038469))) {
      rtb_angles[0] = 0.0;
      rtb_angles[1] = 1.5707963267948966;
      rtb_angles[2] = 0.0;
      rtb_angles[3] = 3.1415926535897931;

      /* Outport: '<Root>/error' */
      rtY.error = 2.0;
    } else {
      rtb_angles[0] = theta0;
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
  theta0 = (rtb_angles[3] + 1.5707963267948966) - rtU.actualposition_c;

  /* Sum: '<S1>/Sum4' incorporates:
   *  Inport: '<Root>/gripperPitchActualPosition'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  alpha = rtDW.UnitDelay2_DSTATE - rtU.actualposition_d;

  /* Sum: '<S1>/Sum2' incorporates:
   *  Inport: '<Root>/baseActualPosition'
   *  UnitDelay: '<S1>/Unit Delay5'
   */
  angToBase = rtDW.UnitDelay5_DSTATE - rtU.actualposition_i;

  /* Sum: '<S1>/Sum3' incorporates:
   *  Constant: '<S1>/Pi1'
   *  Inport: '<Root>/stepperRightActualPosition'
   *  Sum: '<S1>/Sum7'
   */
  XEi = (rtb_angles[1] + 1.5707963267948966) - rtU.actualposition_h;

  /* Outport: '<Root>/pointReached' incorporates:
   *  Abs: '<S1>/Abs2'
   *  Abs: '<S1>/Abs3'
   *  Abs: '<S1>/Abs4'
   *  Abs: '<S1>/Abs5'
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   *  Sum: '<S1>/Sum8'
   */
  rtY.pointReached = (((fabs(alpha) + fabs(angToBase)) + fabs(theta0)) + fabs
                      (XEi) <= 0.001);

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Gain: '<S1>/Gain8'
   *  UnitDelay: '<S1>/Unit Delay5'
   */
  P6i_tmp = rtDW.UnitDelay5_DSTATE;
  if (rtDW.UnitDelay5_DSTATE < -rtb_angles[0]) {
    P6i_tmp = rtDW.UnitDelay5_DSTATE + 0.0001;
  }

  if (P6i_tmp > -rtb_angles[0]) {
    P6i_tmp -= 0.0001;
  }

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  rtb_Gain8 = rtDW.UnitDelay2_DSTATE;
  if (rtDW.UnitDelay2_DSTATE < rtb_angles[2]) {
    rtb_Gain8 = rtDW.UnitDelay2_DSTATE + 0.0002;
  }

  if (rtb_Gain8 > rtb_angles[2]) {
    rtb_Gain8 -= 0.0002;
  }

  /* Sum: '<S1>/Sum6' incorporates:
   *  Gain: '<S1>/Gain7'
   *  Inport: '<Root>/jawActualPosition'
   *  Inport: '<Root>/jawDesiredPosition'
   */
  theta2 = 0.017453292519943295 * rtU.jawDesiredPosition - rtU.actualposition;

  /* Gain: '<S1>/Gain' incorporates:
   *  Inport: '<Root>/gripperRotationDesiredPosition'
   */
  rtb_Integrator_e = 0.017453292519943295 * rtU.gripperRotationDesiredPosition;

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  UnitDelay: '<S1>/Unit Delay7'
   */
  P6i_0 = rtDW.UnitDelay7_DSTATE;
  if (rtDW.UnitDelay7_DSTATE < rtb_Integrator_e) {
    P6i_0 = rtDW.UnitDelay7_DSTATE + 0.001;
  }

  if (P6i_0 > rtb_Integrator_e) {
    P6i_0 -= 0.001;
  }

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = theta0;

  /* Update for UnitDelay: '<S1>/Unit Delay3' */
  rtDW.UnitDelay3_DSTATE = XEi;

  /* Update for UnitDelay: '<S1>/Unit Delay8' incorporates:
   *  DiscreteIntegrator: '<S203>/Integrator'
   *  Sum: '<S212>/Sum'
   */
  rtDW.UnitDelay8_DSTATE = theta2 + rtDW.Integrator_DSTATE_d;

  /* Gain: '<S156>/Proportional Gain' incorporates:
   *  Gain: '<S148>/Integral Gain'
   *  Inport: '<Root>/gripperRotationActualPosition'
   *  Sum: '<S1>/Sum5'
   *  UnitDelay: '<S1>/Unit Delay7'
   */
  theta0 = (rtDW.UnitDelay7_DSTATE - rtU.actualposition_a) * 3.0;

  /* Update for UnitDelay: '<S1>/Unit Delay6' incorporates:
   *  DiscreteIntegrator: '<S151>/Integrator'
   *  Gain: '<S156>/Proportional Gain'
   *  Sum: '<S160>/Sum'
   */
  rtDW.UnitDelay6_DSTATE = theta0 + rtDW.Integrator_DSTATE_c;

  /* Update for UnitDelay: '<S1>/Unit Delay4' incorporates:
   *  DiscreteIntegrator: '<S99>/Integrator'
   *  Sum: '<S108>/Sum'
   */
  rtDW.UnitDelay4_DSTATE = alpha + rtDW.Integrator_DSTATE_g;

  /* Gain: '<S52>/Proportional Gain' incorporates:
   *  Gain: '<S44>/Integral Gain'
   */
  angToBase *= 2.0;

  /* Update for UnitDelay: '<S1>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S47>/Integrator'
   *  Gain: '<S52>/Proportional Gain'
   *  Sum: '<S56>/Sum'
   */
  rtDW.UnitDelay1_DSTATE = angToBase + rtDW.Integrator_DSTATE;

  /* Update for UnitDelay: '<S1>/Unit Delay2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  rtDW.UnitDelay2_DSTATE = rtb_Gain8;

  /* Update for UnitDelay: '<S1>/Unit Delay5' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  rtDW.UnitDelay5_DSTATE = P6i_tmp;

  /* Update for DiscreteIntegrator: '<S47>/Integrator' */
  rtDW.Integrator_DSTATE += angToBase * 0.001;

  /* Update for DiscreteIntegrator: '<S99>/Integrator' */
  rtDW.Integrator_DSTATE_g += 0.001 * alpha;

  /* Update for DiscreteIntegrator: '<S203>/Integrator' */
  rtDW.Integrator_DSTATE_d += 0.001 * theta2;

  /* Update for UnitDelay: '<S1>/Unit Delay7' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function2'
   */
  rtDW.UnitDelay7_DSTATE = P6i_0;

  /* Update for DiscreteIntegrator: '<S151>/Integrator' */
  rtDW.Integrator_DSTATE_c += theta0 * 0.001;
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
