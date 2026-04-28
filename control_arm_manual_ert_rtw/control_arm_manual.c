/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_arm_manual.c
 *
 * Code generated for Simulink model 'control_arm_manual'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Apr 28 11:05:59 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "control_arm_manual.h"
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
extern real_T rt_roundd_snf(real_T u);
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

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void control_arm_manual_step(void)
{
  real_T P2planar[16];
  real_T P4planar[16];
  real_T P6i[16];
  real_T XE_0[16];
  real_T rtb_Sum11_0[16];
  real_T rtb_angles[5];
  real_T P6i_0;
  real_T XE;
  real_T XEi;
  real_T XEi_tmp;
  real_T YE;
  real_T angToBase;
  real_T rtb_Sum11;
  real_T theta0;
  real_T theta2;
  real_T theta3;
  real_T theta5;
  int16_T P6i_tmp_1;
  int16_T P6i_tmp_2;
  int16_T i;
  int16_T i_0;
  int16_T rtb_Sum11_tmp;
  int16_T rtb_Sum11_tmp_0;
  int8_T P2planar_tmp[16];
  int8_T P6i_tmp[4];
  int8_T P6i_tmp_0[4];
  static const int8_T b[4] = { 0, 0, 0, 1 };

  static const int8_T c[4] = { 0, 0, 1, 0 };

  static const int8_T b_b[16] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0,
    1 };

  static const real_T d[5] = { 0.0, 1.5707963267948966, 0.0, 0.0,
    3.1415926535897931 };

  static const real_T c_b[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.3, 0.0, 0.0, 1.0 };

  static const int8_T c_a[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  static const real_T a[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.065, 1.0 };

  static const real_T a_0[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.149, 1.0 };

  static const real_T d_b[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, -0.12, 0.0, 0.0, 1.0 };

  static const real_T b_b_0[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.35, 0.0, 0.0, 1.0 };

  static const real_T c_b_0[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.12, 0.0, 0.0, 1.0 };

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

  /* Product: '<S1>/Divide' incorporates:
   *  Constant: '<S1>/One'
   *  Gain: '<S1>/Gain2'
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S1>/Divide3'
   */
  theta0 = 1.0 / (5.0 * rtU.deltaTime);

  /* Outport: '<Root>/stepperLeftFrequency' incorporates:
   *  Product: '<S1>/Divide'
   */
  rtY.stepperLeftFrequency = theta0;

  /* Outport: '<Root>/stepperRightFrequency' */
  rtY.stepperRightFrequency = theta0;

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
  if (rtU.x < 0.0) {
    theta0 = atan(rtU.y / rtU.x) + 3.1415926535897931;
  } else {
    theta0 = atan(rtU.y / rtU.x);
  }

  angToBase = theta0 - 3.1415926535897931;
  if (theta0 > 3.1415926535897931) {
    theta0 -= 6.2831853071795862;
  }

  theta0 = -theta0;
  XEi = sin(angToBase);
  rtb_Sum11 = cos(angToBase);
  theta5 = sin(rtU.gripperAng);
  XE = cos(rtU.gripperAng);
  P2planar[0] = rtb_Sum11;
  P2planar[4] = -XEi;
  P2planar[8] = 0.0;
  P2planar[12] = rtU.x;
  P2planar[1] = XEi;
  P2planar[5] = rtb_Sum11;
  P2planar[9] = 0.0;
  P2planar[13] = rtU.y;
  P2planar[2] = 0.0;
  P2planar[6] = 0.0;
  P2planar[10] = 1.0;
  P2planar[14] = rtU.z;
  XE_0[0] = XE;
  XE_0[4] = -theta5;
  XE_0[8] = 0.0;
  XE_0[12] = 0.0;
  XE_0[1] = theta5;
  XE_0[5] = XE;
  XE_0[9] = 0.0;
  XE_0[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    /* MATLAB Function: '<S1>/MATLAB Function4' */
    P6i_tmp_1 = b[i_0];
    P6i_tmp[i_0] = (int8_T)P6i_tmp_1;

    /* MATLAB Function: '<S1>/MATLAB Function4' */
    P6i_tmp_2 = c[i_0];
    P6i_tmp_0[i_0] = (int8_T)P6i_tmp_2;
    rtb_Sum11_tmp = i_0 << 2;
    P2planar[rtb_Sum11_tmp + 3] = P6i_tmp_1;
    XE_0[rtb_Sum11_tmp + 2] = P6i_tmp_2;
    XE_0[rtb_Sum11_tmp + 3] = P6i_tmp_1;
    rtb_Sum11_0[rtb_Sum11_tmp] = 0.0;
    rtb_Sum11_0[rtb_Sum11_tmp + 1] = 0.0;
    rtb_Sum11_0[rtb_Sum11_tmp + 2] = 0.0;
    rtb_Sum11_0[rtb_Sum11_tmp + 3] = 0.0;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Sum11_tmp = i_0 << 2;
    rtb_Sum11 = rtb_Sum11_0[rtb_Sum11_tmp];
    theta2 = rtb_Sum11_0[rtb_Sum11_tmp + 1];
    XEi = rtb_Sum11_0[rtb_Sum11_tmp + 2];
    theta3 = rtb_Sum11_0[rtb_Sum11_tmp + 3];
    for (i = 0; i < 4; i++) {
      P6i_tmp_1 = rtb_Sum11_tmp + i;
      P6i_tmp_2 = b_b[P6i_tmp_1];
      rtb_Sum11_tmp_0 = i << 2;
      rtb_Sum11 += P2planar[rtb_Sum11_tmp_0] * (real_T)P6i_tmp_2;
      theta2 += P2planar[rtb_Sum11_tmp_0 + 1] * (real_T)P6i_tmp_2;
      XEi += P2planar[rtb_Sum11_tmp_0 + 2] * (real_T)P6i_tmp_2;
      theta3 += P2planar[rtb_Sum11_tmp_0 + 3] * (real_T)P6i_tmp_2;
      P4planar[P6i_tmp_1] = 0.0;
    }

    rtb_Sum11_0[rtb_Sum11_tmp + 3] = theta3;
    rtb_Sum11_0[rtb_Sum11_tmp + 2] = XEi;
    rtb_Sum11_0[rtb_Sum11_tmp + 1] = theta2;
    rtb_Sum11_0[rtb_Sum11_tmp] = rtb_Sum11;
    XE = P4planar[rtb_Sum11_tmp];
    angToBase = P4planar[rtb_Sum11_tmp + 1];
    theta2 = P4planar[rtb_Sum11_tmp + 2];
    XEi = P4planar[rtb_Sum11_tmp + 3];
    for (i = 0; i < 4; i++) {
      P6i_tmp_1 = rtb_Sum11_tmp + i;
      XEi_tmp = c_b[P6i_tmp_1];
      rtb_Sum11_tmp_0 = i << 2;
      XE += XE_0[rtb_Sum11_tmp_0] * XEi_tmp;
      angToBase += XE_0[rtb_Sum11_tmp_0 + 1] * XEi_tmp;
      theta2 += XE_0[rtb_Sum11_tmp_0 + 2] * XEi_tmp;
      XEi += XE_0[rtb_Sum11_tmp_0 + 3] * XEi_tmp;
      P6i[P6i_tmp_1] = 0.0;
    }

    P4planar[rtb_Sum11_tmp + 3] = XEi;
    P4planar[rtb_Sum11_tmp + 2] = theta2;
    P4planar[rtb_Sum11_tmp + 1] = angToBase;
    P4planar[rtb_Sum11_tmp] = XE;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    P6i_tmp_1 = i_0 << 2;
    XE = P6i[P6i_tmp_1];
    theta5 = P6i[P6i_tmp_1 + 1];
    YE = P6i[P6i_tmp_1 + 2];
    P6i_0 = P6i[P6i_tmp_1 + 3];
    for (i = 0; i < 4; i++) {
      XEi_tmp = P4planar[P6i_tmp_1 + i];
      P6i_tmp_2 = i << 2;
      XE += rtb_Sum11_0[P6i_tmp_2] * XEi_tmp;
      theta5 += rtb_Sum11_0[P6i_tmp_2 + 1] * XEi_tmp;
      YE += rtb_Sum11_0[P6i_tmp_2 + 2] * XEi_tmp;
      P6i_0 += rtb_Sum11_0[P6i_tmp_2 + 3] * XEi_tmp;
    }

    P6i[P6i_tmp_1 + 3] = P6i_0;
    P6i[P6i_tmp_1 + 2] = YE;
    P6i[P6i_tmp_1 + 1] = theta5;
    P6i[P6i_tmp_1] = XE;
  }

  XEi = sqrt(P6i[12] * P6i[12] + P6i[13] * P6i[13]);
  XEi_tmp = XEi * XEi;
  theta3 = (P6i[14] - 0.065) * (P6i[14] - 0.065);
  theta5 = (((((((XEi_tmp * 0.24499999999999997 + 0.04624375) + theta3 *
                 0.24499999999999997) - 0.0625) + XEi_tmp * 0.5) + theta3 * 0.5)
             - rt_powd_snf(XEi, 4.0)) - XEi_tmp * 2.0 * theta3) - rt_powd_snf
    (P6i[14] - 0.065, 4.0);
  if (theta5 < 0.0) {
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_angles[i_0] = d[i_0];
    }

    /* Outport: '<Root>/error' */
    rtY.error = 1.0;
  } else {
    angToBase = atan(((P6i[14] - 0.065) * 0.7 + sqrt(theta5)) / ((((0.7 * XEi +
      0.12249999999999998) - 0.25) + XEi_tmp) + theta3)) * 2.0;
    theta2 = (XEi_tmp - 0.02250000000000002) + theta3;
    theta2 = atan(sqrt(((0.72249999999999992 - XEi_tmp) - theta3) * theta2) /
                  theta2) * -2.0;
    theta3 = (-rtU.gripperAng - angToBase) - theta2;
    XEi = sin(angToBase);
    rtb_Sum11 = cos(angToBase);
    theta5 = sin(theta2);
    XE = cos(theta2);
    P2planar[0] = rtb_Sum11;
    P2planar[4] = -XEi;
    P2planar[8] = 0.0;
    P2planar[12] = 0.0;
    P2planar[1] = XEi;
    P2planar[5] = rtb_Sum11;
    P2planar[9] = 0.0;
    P2planar[13] = 0.0;
    for (i_0 = 0; i_0 < 4; i_0++) {
      rtb_Sum11_tmp = i_0 << 2;
      P2planar[rtb_Sum11_tmp + 2] = P6i_tmp_0[i_0];
      P2planar[rtb_Sum11_tmp + 3] = P6i_tmp[i_0];
      theta2 = 0.0;
      XEi = 0.0;
      rtb_Sum11 = 0.0;
      YE = 0.0;
      for (i = 0; i < 4; i++) {
        XEi_tmp = P2planar[rtb_Sum11_tmp + i];
        P6i_tmp_1 = i << 2;
        theta2 += a[P6i_tmp_1] * XEi_tmp;
        XEi += a[P6i_tmp_1 + 1] * XEi_tmp;
        rtb_Sum11 += a[P6i_tmp_1 + 2] * XEi_tmp;
        YE += a[P6i_tmp_1 + 3] * XEi_tmp;
      }

      P6i[rtb_Sum11_tmp + 3] = YE;
      P6i[rtb_Sum11_tmp + 2] = rtb_Sum11;
      P6i[rtb_Sum11_tmp + 1] = XEi;
      P6i[rtb_Sum11_tmp] = theta2;
    }

    XE_0[0] = XE;
    XE_0[4] = -theta5;
    XE_0[8] = 0.0;
    XE_0[12] = 0.35;
    XE_0[1] = theta5;
    XE_0[5] = XE;
    XE_0[9] = 0.0;
    XE_0[13] = 0.0;
    for (i_0 = 0; i_0 < 4; i_0++) {
      rtb_Sum11_tmp_0 = i_0 << 2;
      XE_0[rtb_Sum11_tmp_0 + 2] = P6i_tmp_0[i_0];
      XE_0[rtb_Sum11_tmp_0 + 3] = P6i_tmp[i_0];
      XE = 0.0;
      theta5 = 0.0;
      rtb_Sum11 = 0.0;
      YE = 0.0;
      for (i = 0; i < 4; i++) {
        P6i_tmp_1 = rtb_Sum11_tmp_0 + i;
        XEi_tmp = P6i[P6i_tmp_1];
        P6i_tmp_2 = i << 2;
        XE += (real_T)c_a[P6i_tmp_2] * XEi_tmp;
        theta5 += (real_T)c_a[P6i_tmp_2 + 1] * XEi_tmp;
        rtb_Sum11 += (real_T)c_a[P6i_tmp_2 + 2] * XEi_tmp;
        YE += (real_T)c_a[P6i_tmp_2 + 3] * XEi_tmp;
        P2planar[P6i_tmp_1] = 0.0;
      }

      rtb_Sum11_0[rtb_Sum11_tmp_0 + 3] = YE;
      rtb_Sum11_0[rtb_Sum11_tmp_0 + 2] = rtb_Sum11;
      rtb_Sum11_0[rtb_Sum11_tmp_0 + 1] = theta5;
      rtb_Sum11_0[rtb_Sum11_tmp_0] = XE;
    }

    for (i_0 = 0; i_0 < 4; i_0++) {
      P6i_tmp_2 = i_0 << 2;
      XE = P2planar[P6i_tmp_2];
      theta5 = P2planar[P6i_tmp_2 + 1];
      rtb_Sum11 = P2planar[P6i_tmp_2 + 2];
      YE = P2planar[P6i_tmp_2 + 3];
      for (i = 0; i < 4; i++) {
        XEi_tmp = XE_0[P6i_tmp_2 + i];
        rtb_Sum11_tmp = i << 2;
        XE += rtb_Sum11_0[rtb_Sum11_tmp] * XEi_tmp;
        theta5 += rtb_Sum11_0[rtb_Sum11_tmp + 1] * XEi_tmp;
        rtb_Sum11 += rtb_Sum11_0[rtb_Sum11_tmp + 2] * XEi_tmp;
        YE += rtb_Sum11_0[rtb_Sum11_tmp + 3] * XEi_tmp;
      }

      P2planar[P6i_tmp_2 + 3] = YE;
      P2planar[P6i_tmp_2 + 2] = rtb_Sum11;
      P2planar[P6i_tmp_2 + 1] = theta5;
      P2planar[P6i_tmp_2] = XE;
    }

    for (i_0 = 0; i_0 < 4; i_0++) {
      XE = 0.0;
      theta5 = 0.0;
      YE = 0.0;
      P6i_0 = 0.0;
      for (i = 0; i < 4; i++) {
        XEi_tmp = d_b[(i_0 << 2) + i];
        P6i_tmp_1 = i << 2;
        XE += P2planar[P6i_tmp_1] * XEi_tmp;
        theta5 += P2planar[P6i_tmp_1 + 1] * XEi_tmp;
        YE += P2planar[P6i_tmp_1 + 2] * XEi_tmp;
        P6i_0 += P2planar[P6i_tmp_1 + 3] * XEi_tmp;
      }

      P6i_tmp_1 = i_0 << 2;
      P6i[P6i_tmp_1 + 3] = P6i_0;
      P6i[P6i_tmp_1 + 2] = YE;
      P6i[P6i_tmp_1 + 1] = theta5;
      P6i[P6i_tmp_1] = XE;
    }

    XEi_tmp = P6i[12] * P6i[12];
    theta2 = (P6i[14] - 0.149) * (P6i[14] - 0.149);
    XEi = atan((sqrt((((((((XEi_tmp * 0.0288 + 0.00205056) + theta2 * 0.0288) -
                          0.0061465600000000023) + XEi_tmp * 0.15680000000000002)
                        + theta2 * 0.15680000000000002) - rt_powd_snf(P6i[12],
      4.0)) - XEi_tmp * 2.0 * theta2) - rt_powd_snf(P6i[14] - 0.149, 4.0)) +
                (P6i[14] - 0.149) * 0.24) / ((((0.24 * P6i[12] + 0.0144) -
      0.078400000000000011) + XEi_tmp) + theta2)) * 2.0;
    if ((fabs(theta0) > 3.1415926535897931) || ((angToBase < 0.0) || (angToBase >
          2.3561944901923448) || (theta3 < -2.3561944901923448) || (theta3 >
          0.78539816339744828) || (XEi < 1.5707963267948966) || (XEi >
          4.71238898038469))) {
      for (i_0 = 0; i_0 < 5; i_0++) {
        rtb_angles[i_0] = d[i_0];
      }

      /* Outport: '<Root>/error' */
      rtY.error = 2.0;
    } else {
      rtb_angles[0] = theta0;
      rtb_angles[1] = angToBase;
      rtb_angles[3] = theta3;
      rtb_angles[4] = XEi;

      /* Outport: '<Root>/error' */
      rtY.error = 0.0;
    }
  }

  /* End of MATLAB Function: '<S1>/inverse kinematics' */

  /* Gain: '<S1>/Gain6' */
  theta0 = 63.0 * rtb_angles[0];

  /* Gain: '<S1>/Gain15' */
  XEi = -0.015873015873015872 * theta0;

  /* Sum: '<S1>/Sum11' incorporates:
   *  Constant: '<S1>/Pi2'
   *  Gain: '<S1>/Gain17'
   *  Inport: '<Root>/stepperRightActualPosition'
   */
  rtb_Sum11 = 0.00625 * rtU.actualposition_e - 1.5707963267948966;

  /* Gain: '<S1>/Gain16' incorporates:
   *  Inport: '<Root>/gripperPitchActualPosition'
   */
  angToBase = 0.047619047619047616 * rtU.actualposition_i;

  /* Sum: '<S1>/Sum10' incorporates:
   *  Constant: '<S1>/Pi2'
   *  Gain: '<S1>/Gain18'
   *  Inport: '<Root>/stepperLeftActualPosition'
   */
  theta2 = 0.00625 * rtU.actualposition_g - 1.5707963267948966;

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  theta3 = sin(theta2);
  theta5 = cos(theta2);
  P2planar[0] = theta5;
  P2planar[4] = -theta3;
  P2planar[8] = 0.0;
  P2planar[12] = 0.0;
  P2planar[1] = theta3;
  P2planar[5] = theta5;
  P2planar[9] = 0.0;
  P2planar[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Sum11_tmp = i_0 << 2;
    P2planar[rtb_Sum11_tmp + 2] = P6i_tmp_0[i_0];
    P2planar[rtb_Sum11_tmp + 3] = P6i_tmp[i_0];
    XE = 0.0;
    theta5 = 0.0;
    YE = 0.0;
    P6i_0 = 0.0;
    for (i = 0; i < 4; i++) {
      XEi_tmp = P2planar[rtb_Sum11_tmp + i];
      P6i_tmp_1 = i << 2;
      XE += a_0[P6i_tmp_1] * XEi_tmp;
      theta5 += a_0[P6i_tmp_1 + 1] * XEi_tmp;
      YE += a_0[P6i_tmp_1 + 2] * XEi_tmp;
      P6i_0 += a_0[P6i_tmp_1 + 3] * XEi_tmp;
    }

    P6i[rtb_Sum11_tmp + 3] = P6i_0;
    P6i[rtb_Sum11_tmp + 2] = YE;
    P6i[rtb_Sum11_tmp + 1] = theta5;
    P6i[rtb_Sum11_tmp] = XE;
  }

  theta3 = sin(rtb_Sum11);
  rtb_Sum11 = cos(rtb_Sum11);
  for (i_0 = 0; i_0 < 16; i_0++) {
    P2planar_tmp[i_0] = c_a[i_0];
  }

  P2planar[0] = rtb_Sum11;
  P2planar[4] = -theta3;
  P2planar[8] = 0.0;
  P2planar[12] = 0.0;
  P2planar[1] = theta3;
  P2planar[5] = rtb_Sum11;
  P2planar[9] = 0.0;
  P2planar[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Sum11_tmp = i_0 << 2;
    P2planar[rtb_Sum11_tmp + 2] = P6i_tmp_0[i_0];
    P2planar[rtb_Sum11_tmp + 3] = P6i_tmp[i_0];
    XE = 0.0;
    theta5 = 0.0;
    rtb_Sum11 = 0.0;
    YE = 0.0;
    for (i = 0; i < 4; i++) {
      XEi_tmp = P2planar[rtb_Sum11_tmp + i];
      P6i_tmp_2 = i << 2;
      XE += a[P6i_tmp_2] * XEi_tmp;
      theta5 += a[P6i_tmp_2 + 1] * XEi_tmp;
      rtb_Sum11 += a[P6i_tmp_2 + 2] * XEi_tmp;
      YE += a[P6i_tmp_2 + 3] * XEi_tmp;
    }

    rtb_Sum11_0[rtb_Sum11_tmp + 3] = YE;
    rtb_Sum11_0[rtb_Sum11_tmp + 2] = rtb_Sum11;
    rtb_Sum11_0[rtb_Sum11_tmp + 1] = theta5;
    rtb_Sum11_0[rtb_Sum11_tmp] = XE;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    theta3 = 0.0;
    XE = 0.0;
    theta5 = 0.0;
    rtb_Sum11 = 0.0;
    for (i = 0; i < 4; i++) {
      P6i_tmp_1 = (i_0 << 2) + i;
      XEi_tmp = rtb_Sum11_0[P6i_tmp_1];
      P6i_tmp_2 = i << 2;
      theta3 += (real_T)P2planar_tmp[P6i_tmp_2] * XEi_tmp;
      XE += (real_T)P2planar_tmp[P6i_tmp_2 + 1] * XEi_tmp;
      theta5 += (real_T)P2planar_tmp[P6i_tmp_2 + 2] * XEi_tmp;
      rtb_Sum11 += (real_T)P2planar_tmp[P6i_tmp_2 + 3] * XEi_tmp;
      P2planar[P6i_tmp_1] = 0.0;
    }

    P6i_tmp_2 = i_0 << 2;
    XE_0[P6i_tmp_2 + 3] = rtb_Sum11;
    XE_0[P6i_tmp_2 + 2] = theta5;
    XE_0[P6i_tmp_2 + 1] = XE;
    XE_0[P6i_tmp_2] = theta3;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Sum11_tmp = i_0 << 2;
    theta3 = P2planar[rtb_Sum11_tmp];
    XE = P2planar[rtb_Sum11_tmp + 1];
    theta5 = P2planar[rtb_Sum11_tmp + 2];
    rtb_Sum11 = P2planar[rtb_Sum11_tmp + 3];
    for (i = 0; i < 4; i++) {
      P6i_tmp_1 = rtb_Sum11_tmp + i;
      XEi_tmp = b_b_0[P6i_tmp_1];
      P6i_tmp_2 = i << 2;
      theta3 += XE_0[P6i_tmp_2] * XEi_tmp;
      XE += XE_0[P6i_tmp_2 + 1] * XEi_tmp;
      theta5 += XE_0[P6i_tmp_2 + 2] * XEi_tmp;
      rtb_Sum11 += XE_0[P6i_tmp_2 + 3] * XEi_tmp;
      rtb_Sum11_0[P6i_tmp_1] = 0.0;
    }

    P2planar[rtb_Sum11_tmp + 3] = rtb_Sum11;
    P2planar[rtb_Sum11_tmp + 2] = theta5;
    P2planar[rtb_Sum11_tmp + 1] = XE;
    P2planar[rtb_Sum11_tmp] = theta3;
    theta3 = rtb_Sum11_0[rtb_Sum11_tmp];
    XE = rtb_Sum11_0[rtb_Sum11_tmp + 1];
    theta5 = rtb_Sum11_0[rtb_Sum11_tmp + 2];
    rtb_Sum11 = rtb_Sum11_0[rtb_Sum11_tmp + 3];
    for (i = 0; i < 4; i++) {
      P6i_tmp_1 = rtb_Sum11_tmp + i;
      XEi_tmp = P6i[P6i_tmp_1];
      P6i_tmp_2 = i << 2;
      theta3 += (real_T)P2planar_tmp[P6i_tmp_2] * XEi_tmp;
      XE += (real_T)P2planar_tmp[P6i_tmp_2 + 1] * XEi_tmp;
      theta5 += (real_T)P2planar_tmp[P6i_tmp_2 + 2] * XEi_tmp;
      rtb_Sum11 += (real_T)P2planar_tmp[P6i_tmp_2 + 3] * XEi_tmp;
      P4planar[P6i_tmp_1] = 0.0;
    }

    rtb_Sum11_0[rtb_Sum11_tmp + 3] = rtb_Sum11;
    rtb_Sum11_0[rtb_Sum11_tmp + 2] = theta5;
    rtb_Sum11_0[rtb_Sum11_tmp + 1] = XE;
    rtb_Sum11_0[rtb_Sum11_tmp] = theta3;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Sum11_tmp = i_0 << 2;
    theta3 = P4planar[rtb_Sum11_tmp];
    XE = P4planar[rtb_Sum11_tmp + 1];
    theta5 = P4planar[rtb_Sum11_tmp + 2];
    rtb_Sum11 = P4planar[rtb_Sum11_tmp + 3];
    for (i = 0; i < 4; i++) {
      XEi_tmp = c_b_0[rtb_Sum11_tmp + i];
      P6i_tmp_1 = i << 2;
      theta3 += rtb_Sum11_0[P6i_tmp_1] * XEi_tmp;
      XE += rtb_Sum11_0[P6i_tmp_1 + 1] * XEi_tmp;
      theta5 += rtb_Sum11_0[P6i_tmp_1 + 2] * XEi_tmp;
      rtb_Sum11 += rtb_Sum11_0[P6i_tmp_1 + 3] * XEi_tmp;
    }

    P4planar[rtb_Sum11_tmp + 3] = rtb_Sum11;
    P4planar[rtb_Sum11_tmp + 2] = theta5;
    P4planar[rtb_Sum11_tmp + 1] = XE;
    P4planar[rtb_Sum11_tmp] = theta3;
  }

  XE = P4planar[12] - P2planar[12];
  YE = P4planar[14] - P2planar[14];
  XEi_tmp = XE * XE;
  theta3 = YE * YE;
  theta5 = (((((((XEi_tmp * 0.15680000000000002 - 0.0038886400000000022) +
                 theta3 * 0.15680000000000002) - 0.00020735999999999997) +
               XEi_tmp * 0.0288) + theta3 * 0.0288) - rt_powd_snf(XE, 4.0)) -
            XEi_tmp * 2.0 * theta3) - rt_powd_snf(YE, 4.0);
  if (theta5 > 0.0) {
    theta5 = atan((0.56 * YE + sqrt(theta5)) / ((((0.56 * XE +
      0.078400000000000011) - 0.0144) + XEi_tmp) + theta3)) * 2.0;
    XE = (XEi_tmp - 0.0256) + theta3;
    XE = atan(sqrt(((0.16 - XEi_tmp) - theta3) * XE) / XE) * -2.0;
  } else {
    theta5 = 0.0;
    XE = 0.0;
  }

  theta5 += 3.1415926535897931 - theta2;
  theta3 = sin(XEi);
  rtb_Sum11 = cos(XEi);
  XEi = sin(theta5);
  theta2 = cos(theta5);
  theta5 = sin(XE);
  XE = cos(XE);
  YE = sin(angToBase);
  angToBase = cos(angToBase);
  P2planar[0] = rtb_Sum11;
  P2planar[4] = -theta3;
  P2planar[8] = 0.0;
  P2planar[12] = 0.0;
  P2planar[1] = theta3;
  P2planar[5] = rtb_Sum11;
  P2planar[9] = 0.0;
  P2planar[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Sum11_tmp = i_0 << 2;
    P2planar[rtb_Sum11_tmp + 2] = P6i_tmp_0[i_0];
    P2planar[rtb_Sum11_tmp + 3] = P6i_tmp[i_0];
    rtb_Sum11_0[rtb_Sum11_tmp] = 0.0;
    rtb_Sum11_0[rtb_Sum11_tmp + 1] = 0.0;
    rtb_Sum11_0[rtb_Sum11_tmp + 2] = 0.0;
    rtb_Sum11_0[rtb_Sum11_tmp + 3] = 0.0;
  }

  XE_0[0] = theta2;
  XE_0[4] = -XEi;
  XE_0[8] = 0.0;
  XE_0[12] = 0.12;
  XE_0[1] = XEi;
  XE_0[5] = theta2;
  XE_0[9] = 0.0;
  XE_0[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    P6i_tmp_2 = i_0 << 2;
    XE_0[P6i_tmp_2 + 2] = P6i_tmp_0[i_0];
    XE_0[P6i_tmp_2 + 3] = P6i_tmp[i_0];
    rtb_Sum11 = rtb_Sum11_0[P6i_tmp_2];
    theta2 = rtb_Sum11_0[P6i_tmp_2 + 1];
    XEi = rtb_Sum11_0[P6i_tmp_2 + 2];
    theta3 = rtb_Sum11_0[P6i_tmp_2 + 3];
    for (i = 0; i < 4; i++) {
      P6i_tmp_1 = P6i_tmp_2 + i;
      XEi_tmp = P6i[P6i_tmp_1];
      rtb_Sum11_tmp = i << 2;
      rtb_Sum11 += P2planar[rtb_Sum11_tmp] * XEi_tmp;
      theta2 += P2planar[rtb_Sum11_tmp + 1] * XEi_tmp;
      XEi += P2planar[rtb_Sum11_tmp + 2] * XEi_tmp;
      theta3 += P2planar[rtb_Sum11_tmp + 3] * XEi_tmp;
      P4planar[P6i_tmp_1] = 0.0;
    }

    rtb_Sum11_0[P6i_tmp_2 + 3] = theta3;
    rtb_Sum11_0[P6i_tmp_2 + 2] = XEi;
    rtb_Sum11_0[P6i_tmp_2 + 1] = theta2;
    rtb_Sum11_0[P6i_tmp_2] = rtb_Sum11;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Sum11_tmp = i_0 << 2;
    rtb_Sum11 = P4planar[rtb_Sum11_tmp];
    theta2 = P4planar[rtb_Sum11_tmp + 1];
    XEi = P4planar[rtb_Sum11_tmp + 2];
    theta3 = P4planar[rtb_Sum11_tmp + 3];
    for (i = 0; i < 4; i++) {
      XEi_tmp = XE_0[rtb_Sum11_tmp + i];
      rtb_Sum11_tmp_0 = i << 2;
      rtb_Sum11 += rtb_Sum11_0[rtb_Sum11_tmp_0] * XEi_tmp;
      theta2 += rtb_Sum11_0[rtb_Sum11_tmp_0 + 1] * XEi_tmp;
      XEi += rtb_Sum11_0[rtb_Sum11_tmp_0 + 2] * XEi_tmp;
      theta3 += rtb_Sum11_0[rtb_Sum11_tmp_0 + 3] * XEi_tmp;
    }

    P4planar[rtb_Sum11_tmp + 3] = theta3;
    P4planar[rtb_Sum11_tmp + 2] = XEi;
    P4planar[rtb_Sum11_tmp + 1] = theta2;
    P4planar[rtb_Sum11_tmp] = rtb_Sum11;
  }

  XE_0[0] = XE;
  XE_0[4] = -theta5;
  XE_0[8] = 0.0;
  XE_0[12] = 0.28;
  XE_0[1] = theta5;
  XE_0[5] = XE;
  XE_0[9] = 0.0;
  XE_0[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Sum11_tmp_0 = i_0 << 2;
    XE_0[rtb_Sum11_tmp_0 + 2] = P6i_tmp_0[i_0];
    XE_0[rtb_Sum11_tmp_0 + 3] = P6i_tmp[i_0];
    rtb_Sum11 = 0.0;
    theta2 = 0.0;
    XEi = 0.0;
    theta3 = 0.0;
    for (i = 0; i < 4; i++) {
      XEi_tmp = XE_0[rtb_Sum11_tmp_0 + i];
      rtb_Sum11_tmp = i << 2;
      rtb_Sum11 += P4planar[rtb_Sum11_tmp] * XEi_tmp;
      theta2 += P4planar[rtb_Sum11_tmp + 1] * XEi_tmp;
      XEi += P4planar[rtb_Sum11_tmp + 2] * XEi_tmp;
      theta3 += P4planar[rtb_Sum11_tmp + 3] * XEi_tmp;
    }

    P2planar[rtb_Sum11_tmp_0 + 3] = theta3;
    P2planar[rtb_Sum11_tmp_0 + 2] = XEi;
    P2planar[rtb_Sum11_tmp_0 + 1] = theta2;
    P2planar[rtb_Sum11_tmp_0] = rtb_Sum11;
  }

  P6i[0] = angToBase;
  P6i[4] = -YE;
  P6i[8] = 0.0;
  P6i[12] = 0.62;
  P6i[1] = YE;
  P6i[5] = angToBase;
  P6i[9] = 0.0;
  P6i[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    P6i_tmp_1 = i_0 << 2;
    P6i[P6i_tmp_1 + 2] = P6i_tmp_0[i_0];
    P6i[P6i_tmp_1 + 3] = P6i_tmp[i_0];
    rtb_Sum11 = 0.0;
    theta2 = 0.0;
    XEi = 0.0;
    theta3 = 0.0;
    for (i = 0; i < 4; i++) {
      XEi_tmp = P6i[P6i_tmp_1 + i];
      rtb_Sum11_tmp = i << 2;
      rtb_Sum11 += P2planar[rtb_Sum11_tmp] * XEi_tmp;
      theta2 += P2planar[rtb_Sum11_tmp + 1] * XEi_tmp;
      XEi += P2planar[rtb_Sum11_tmp + 2] * XEi_tmp;
      theta3 += P2planar[rtb_Sum11_tmp + 3] * XEi_tmp;
    }

    rtb_Sum11_0[P6i_tmp_1 + 3] = theta3;
    rtb_Sum11_0[P6i_tmp_1 + 2] = XEi;
    rtb_Sum11_0[P6i_tmp_1 + 1] = theta2;
    rtb_Sum11_0[P6i_tmp_1] = rtb_Sum11;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    theta3 = 0.0;
    XE = 0.0;
    theta5 = 0.0;
    rtb_Sum11 = 0.0;
    for (i = 0; i < 4; i++) {
      XEi_tmp = c_b[(i_0 << 2) + i];
      rtb_Sum11_tmp = i << 2;
      theta3 += rtb_Sum11_0[rtb_Sum11_tmp] * XEi_tmp;
      XE += rtb_Sum11_0[rtb_Sum11_tmp + 1] * XEi_tmp;
      theta5 += rtb_Sum11_0[rtb_Sum11_tmp + 2] * XEi_tmp;
      rtb_Sum11 += rtb_Sum11_0[rtb_Sum11_tmp + 3] * XEi_tmp;
    }

    rtb_Sum11_tmp = i_0 << 2;
    P2planar[rtb_Sum11_tmp + 3] = rtb_Sum11;
    P2planar[rtb_Sum11_tmp + 2] = theta5;
    P2planar[rtb_Sum11_tmp + 1] = XE;
    P2planar[rtb_Sum11_tmp] = theta3;
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/x'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  angToBase = P2planar[12] - rtU.x;

  /* DotProduct: '<S3>/Dot Product' */
  XEi_tmp = angToBase * angToBase;

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/y'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  angToBase = P2planar[13] - rtU.y;

  /* DotProduct: '<S3>/Dot Product' */
  XEi_tmp += angToBase * angToBase;

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/z'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  angToBase = P2planar[14] - rtU.z;

  /* Outport: '<Root>/pointReached' incorporates:
   *  Constant: '<S2>/Constant'
   *  DotProduct: '<S3>/Dot Product'
   *  RelationalOperator: '<S2>/Compare'
   *  Sqrt: '<S3>/sqrt'
   */
  rtY.pointReached = (sqrt(angToBase * angToBase + XEi_tmp) <= 0.002);

  /* Sum: '<S1>/Sum2' incorporates:
   *  Inport: '<Root>/baseActualPosition'
   */
  theta0 -= rtU.actualposition_a;

  /* Update for UnitDelay: '<S1>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S44>/Integrator'
   *  Sum: '<S53>/Sum'
   */
  rtDW.UnitDelay1_DSTATE = theta0 + rtDW.Integrator_DSTATE;

  /* Product: '<S57>/Uintegral*Ts Prod Out' incorporates:
   *  Inport: '<Root>/deltaTime'
   */
  angToBase = theta0 * rtU.deltaTime;

  /* Outport: '<Root>/stepperLeftSteps' incorporates:
   *  Constant: '<S1>/Constant5'
   *  Constant: '<S1>/Pi'
   *  Gain: '<S1>/Gain10'
   *  Gain: '<S1>/Gain13'
   *  Product: '<S1>/Divide1'
   *  Rounding: '<S1>/Round'
   *  Sum: '<S1>/Sum7'
   */
  rtY.stepperLeftSteps = rt_roundd_snf((rtb_angles[4] + 1.5707963267948966) *
    160.0 * 57.295779513082323 / 1.8);

  /* Outport: '<Root>/stepperRightSteps' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Pi1'
   *  Gain: '<S1>/Gain11'
   *  Gain: '<S1>/Gain8'
   *  Product: '<S1>/Divide2'
   *  Rounding: '<S1>/Round1'
   *  Sum: '<S1>/Sum9'
   */
  rtY.stepperRightSteps = rt_roundd_snf((rtb_angles[1] + 1.5707963267948966) *
    160.0 * 57.295779513082323 / 1.8);

  /* Sum: '<S1>/Sum4' incorporates:
   *  Gain: '<S1>/Gain12'
   *  Inport: '<Root>/gripperPitchActualPosition'
   */
  theta0 = 21.0 * rtb_angles[3] - rtU.actualposition_i;

  /* Sum: '<S1>/Sum6' incorporates:
   *  Gain: '<S1>/Gain3'
   *  Gain: '<S1>/Gain7'
   *  Inport: '<Root>/jawActualPosition'
   *  Inport: '<Root>/jawDesiredPosition'
   */
  theta2 = 0.017453292519943295 * rtU.jawDesiredPosition * 21.0 -
    rtU.actualposition;

  /* Update for UnitDelay: '<S1>/Unit Delay8' incorporates:
   *  DiscreteIntegrator: '<S200>/Integrator'
   *  Gain: '<S205>/Proportional Gain'
   *  Sum: '<S209>/Sum'
   */
  rtDW.UnitDelay8_DSTATE = 2.0 * theta2 + rtDW.Integrator_DSTATE_o;

  /* Gain: '<S153>/Proportional Gain' incorporates:
   *  Gain: '<S145>/Integral Gain'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain5'
   *  Inport: '<Root>/gripperRotationActualPosition'
   *  Inport: '<Root>/gripperRotationDesiredPosition'
   *  Sum: '<S1>/Sum5'
   */
  XEi_tmp = (0.017453292519943295 * rtU.gripperRotationDesiredPosition * 21.0 -
             rtU.actualposition_o) * 0.2;

  /* Update for UnitDelay: '<S1>/Unit Delay6' incorporates:
   *  DiscreteIntegrator: '<S148>/Integrator'
   *  Gain: '<S153>/Proportional Gain'
   *  Sum: '<S157>/Sum'
   */
  rtDW.UnitDelay6_DSTATE = XEi_tmp + rtDW.Integrator_DSTATE_p1;

  /* Update for UnitDelay: '<S1>/Unit Delay4' incorporates:
   *  DiscreteIntegrator: '<S96>/Integrator'
   *  Gain: '<S101>/Proportional Gain'
   *  Sum: '<S105>/Sum'
   */
  rtDW.UnitDelay4_DSTATE = 0.5 * theta0 + rtDW.Integrator_DSTATE_p;

  /* Update for DiscreteIntegrator: '<S44>/Integrator' */
  rtDW.Integrator_DSTATE += angToBase;

  /* Update for DiscreteIntegrator: '<S96>/Integrator' incorporates:
   *  Gain: '<S93>/Integral Gain'
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S109>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE_p += 0.1 * theta0 * rtU.deltaTime;

  /* Update for DiscreteIntegrator: '<S148>/Integrator' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S161>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE_p1 += XEi_tmp * rtU.deltaTime;

  /* Update for DiscreteIntegrator: '<S200>/Integrator' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S213>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE_o += theta2 * rtU.deltaTime;
}

/* Model initialize function */
void control_arm_manual_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
