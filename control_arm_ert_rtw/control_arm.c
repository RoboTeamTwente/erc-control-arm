/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_arm.c
 *
 * Code generated for Simulink model 'control_arm'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Mar 23 11:35:01 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "control_arm.h"
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
void control_arm_step(void)
{
  real_T P2planar[16];
  real_T P4planar[16];
  real_T TPbasetoP3[16];
  real_T b_a[16];
  real_T theta6_0[16];
  real_T rtb_angles[5];
  real_T TPbasetoP3_0;
  real_T TPbasetoP3_1;
  real_T XE;
  real_T rtb_Gain15;
  real_T rtb_Gain16;
  real_T rtb_Sum10;
  real_T rtb_Sum11;
  real_T rtb_Sum6;
  real_T rtb_out;
  real_T theta6;
  real_T theta6_tmp_0;
  int16_T TPbasetoP3_tmp_1;
  int16_T TPbasetoP3_tmp_2;
  int16_T i;
  int16_T i_0;
  int16_T rtb_Sum10_tmp;
  int16_T theta6_tmp;
  int8_T P2planar_tmp[16];
  int8_T TPbasetoP3_tmp[4];
  int8_T TPbasetoP3_tmp_0[4];
  int8_T TPbasetoP3_tmp_3;
  static const int8_T b[4] = { 0, 0, 1, 0 };

  static const int8_T c[4] = { 0, 0, 0, 1 };

  static const int8_T c_a[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  static const real_T a[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.149, 1.0 };

  static const real_T b_a_0[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.065, 1.0 };

  static const real_T b_b[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.35, 0.0, 0.0, 1.0 };

  static const real_T c_b[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.12, 0.0, 0.0, 1.0 };

  static const real_T d_b[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.3, 0.0, 0.0, 1.0 };

  static const int8_T b_b_0[16] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0,
    1 };

  static const real_T d[5] = { 0.0, 1.5707963267948966, 0.0, 0.0,
    3.1415926535897931 };

  static const real_T d_b_0[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, -0.12, 0.0, 0.0, 1.0 };

  /* Gain: '<S1>/Gain15' incorporates:
   *  Inport: '<Root>/baseActualPosition'
   */
  rtb_Gain15 = -0.015873015873015872 * rtU.actualposition_b;

  /* Sum: '<S1>/Sum11' incorporates:
   *  Constant: '<S1>/Pi2'
   *  Gain: '<S1>/Gain17'
   *  Inport: '<Root>/stepperRightActualPosition'
   */
  rtb_Sum11 = 0.00625 * rtU.stepperRightActualPosition - 1.5707963267948966;

  /* Gain: '<S1>/Gain16' incorporates:
   *  Inport: '<Root>/gripperPitchActualPosition'
   */
  rtb_Gain16 = 0.047619047619047616 * rtU.actualposition_f;

  /* Sum: '<S1>/Sum10' incorporates:
   *  Constant: '<S1>/Pi2'
   *  Gain: '<S1>/Gain18'
   *  Inport: '<Root>/stepperLeftActualPosition'
   */
  rtb_Sum10 = 0.00625 * rtU.stepperLeftActualPosition - 1.5707963267948966;

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  XE = sin(rtb_Sum10);
  theta6 = cos(rtb_Sum10);
  theta6_0[0] = theta6;
  theta6_0[4] = -XE;
  theta6_0[8] = 0.0;
  theta6_0[12] = 0.0;
  theta6_0[1] = XE;
  theta6_0[5] = theta6;
  theta6_0[9] = 0.0;
  theta6_0[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    /* MATLAB Function: '<S1>/inverse kinematics' */
    TPbasetoP3_tmp_1 = b[i_0];
    TPbasetoP3_tmp[i_0] = (int8_T)TPbasetoP3_tmp_1;

    /* MATLAB Function: '<S1>/inverse kinematics' */
    TPbasetoP3_tmp_2 = c[i_0];
    TPbasetoP3_tmp_0[i_0] = (int8_T)TPbasetoP3_tmp_2;
    theta6_tmp = i_0 << 2;
    theta6_0[theta6_tmp + 2] = TPbasetoP3_tmp_1;
    theta6_0[theta6_tmp + 3] = TPbasetoP3_tmp_2;
    rtb_out = 0.0;
    rtb_Sum6 = 0.0;
    TPbasetoP3_0 = 0.0;
    TPbasetoP3_1 = 0.0;
    for (i = 0; i < 4; i++) {
      theta6_tmp_0 = theta6_0[theta6_tmp + i];
      TPbasetoP3_tmp_1 = i << 2;
      rtb_out += a[TPbasetoP3_tmp_1] * theta6_tmp_0;
      rtb_Sum6 += a[TPbasetoP3_tmp_1 + 1] * theta6_tmp_0;
      TPbasetoP3_0 += a[TPbasetoP3_tmp_1 + 2] * theta6_tmp_0;
      TPbasetoP3_1 += a[TPbasetoP3_tmp_1 + 3] * theta6_tmp_0;
    }

    TPbasetoP3[theta6_tmp + 3] = TPbasetoP3_1;
    TPbasetoP3[theta6_tmp + 2] = TPbasetoP3_0;
    TPbasetoP3[theta6_tmp + 1] = rtb_Sum6;
    TPbasetoP3[theta6_tmp] = rtb_out;
  }

  XE = sin(rtb_Sum11);
  rtb_Sum11 = cos(rtb_Sum11);
  for (i_0 = 0; i_0 < 16; i_0++) {
    /* MATLAB Function: '<S1>/inverse kinematics' */
    P2planar_tmp[i_0] = c_a[i_0];
  }

  P2planar[0] = rtb_Sum11;
  P2planar[4] = -XE;
  P2planar[8] = 0.0;
  P2planar[12] = 0.0;
  P2planar[1] = XE;
  P2planar[5] = rtb_Sum11;
  P2planar[9] = 0.0;
  P2planar[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    TPbasetoP3_tmp_1 = i_0 << 2;
    P2planar[TPbasetoP3_tmp_1 + 2] = TPbasetoP3_tmp[i_0];
    P2planar[TPbasetoP3_tmp_1 + 3] = TPbasetoP3_tmp_0[i_0];
    theta6 = 0.0;
    XE = 0.0;
    rtb_Sum11 = 0.0;
    rtb_out = 0.0;
    for (i = 0; i < 4; i++) {
      theta6_tmp_0 = P2planar[TPbasetoP3_tmp_1 + i];
      theta6_tmp = i << 2;
      theta6 += b_a_0[theta6_tmp] * theta6_tmp_0;
      XE += b_a_0[theta6_tmp + 1] * theta6_tmp_0;
      rtb_Sum11 += b_a_0[theta6_tmp + 2] * theta6_tmp_0;
      rtb_out += b_a_0[theta6_tmp + 3] * theta6_tmp_0;
    }

    b_a[TPbasetoP3_tmp_1 + 3] = rtb_out;
    b_a[TPbasetoP3_tmp_1 + 2] = rtb_Sum11;
    b_a[TPbasetoP3_tmp_1 + 1] = XE;
    b_a[TPbasetoP3_tmp_1] = theta6;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Sum11 = 0.0;
    rtb_out = 0.0;
    rtb_Sum6 = 0.0;
    TPbasetoP3_0 = 0.0;
    for (i = 0; i < 4; i++) {
      theta6_tmp = (i_0 << 2) + i;
      theta6_tmp_0 = b_a[theta6_tmp];
      TPbasetoP3_tmp_1 = i << 2;
      rtb_Sum11 += (real_T)P2planar_tmp[TPbasetoP3_tmp_1] * theta6_tmp_0;
      rtb_out += (real_T)P2planar_tmp[TPbasetoP3_tmp_1 + 1] * theta6_tmp_0;
      rtb_Sum6 += (real_T)P2planar_tmp[TPbasetoP3_tmp_1 + 2] * theta6_tmp_0;
      TPbasetoP3_0 += (real_T)P2planar_tmp[TPbasetoP3_tmp_1 + 3] * theta6_tmp_0;
      P2planar[theta6_tmp] = 0.0;
    }

    TPbasetoP3_tmp_1 = i_0 << 2;
    theta6_0[TPbasetoP3_tmp_1 + 3] = TPbasetoP3_0;
    theta6_0[TPbasetoP3_tmp_1 + 2] = rtb_Sum6;
    theta6_0[TPbasetoP3_tmp_1 + 1] = rtb_out;
    theta6_0[TPbasetoP3_tmp_1] = rtb_Sum11;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    TPbasetoP3_tmp_2 = i_0 << 2;
    theta6 = P2planar[TPbasetoP3_tmp_2];
    XE = P2planar[TPbasetoP3_tmp_2 + 1];
    rtb_Sum11 = P2planar[TPbasetoP3_tmp_2 + 2];
    rtb_out = P2planar[TPbasetoP3_tmp_2 + 3];
    for (i = 0; i < 4; i++) {
      theta6_tmp = TPbasetoP3_tmp_2 + i;
      theta6_tmp_0 = b_b[theta6_tmp];
      TPbasetoP3_tmp_1 = i << 2;
      theta6 += theta6_0[TPbasetoP3_tmp_1] * theta6_tmp_0;
      XE += theta6_0[TPbasetoP3_tmp_1 + 1] * theta6_tmp_0;
      rtb_Sum11 += theta6_0[TPbasetoP3_tmp_1 + 2] * theta6_tmp_0;
      rtb_out += theta6_0[TPbasetoP3_tmp_1 + 3] * theta6_tmp_0;
      b_a[theta6_tmp] = 0.0;
    }

    P2planar[TPbasetoP3_tmp_2 + 3] = rtb_out;
    P2planar[TPbasetoP3_tmp_2 + 2] = rtb_Sum11;
    P2planar[TPbasetoP3_tmp_2 + 1] = XE;
    P2planar[TPbasetoP3_tmp_2] = theta6;
    rtb_Sum11 = b_a[TPbasetoP3_tmp_2];
    rtb_out = b_a[TPbasetoP3_tmp_2 + 1];
    rtb_Sum6 = b_a[TPbasetoP3_tmp_2 + 2];
    TPbasetoP3_0 = b_a[TPbasetoP3_tmp_2 + 3];
    for (i = 0; i < 4; i++) {
      theta6_tmp = TPbasetoP3_tmp_2 + i;
      theta6_tmp_0 = TPbasetoP3[theta6_tmp];
      TPbasetoP3_tmp_1 = i << 2;
      rtb_Sum11 += (real_T)P2planar_tmp[TPbasetoP3_tmp_1] * theta6_tmp_0;
      rtb_out += (real_T)P2planar_tmp[TPbasetoP3_tmp_1 + 1] * theta6_tmp_0;
      rtb_Sum6 += (real_T)P2planar_tmp[TPbasetoP3_tmp_1 + 2] * theta6_tmp_0;
      TPbasetoP3_0 += (real_T)P2planar_tmp[TPbasetoP3_tmp_1 + 3] * theta6_tmp_0;
      P4planar[theta6_tmp] = 0.0;
    }

    b_a[TPbasetoP3_tmp_2 + 3] = TPbasetoP3_0;
    b_a[TPbasetoP3_tmp_2 + 2] = rtb_Sum6;
    b_a[TPbasetoP3_tmp_2 + 1] = rtb_out;
    b_a[TPbasetoP3_tmp_2] = rtb_Sum11;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    theta6_tmp = i_0 << 2;
    theta6 = P4planar[theta6_tmp];
    XE = P4planar[theta6_tmp + 1];
    rtb_Sum11 = P4planar[theta6_tmp + 2];
    rtb_out = P4planar[theta6_tmp + 3];
    for (i = 0; i < 4; i++) {
      theta6_tmp_0 = c_b[theta6_tmp + i];
      TPbasetoP3_tmp_1 = i << 2;
      theta6 += b_a[TPbasetoP3_tmp_1] * theta6_tmp_0;
      XE += b_a[TPbasetoP3_tmp_1 + 1] * theta6_tmp_0;
      rtb_Sum11 += b_a[TPbasetoP3_tmp_1 + 2] * theta6_tmp_0;
      rtb_out += b_a[TPbasetoP3_tmp_1 + 3] * theta6_tmp_0;
    }

    P4planar[theta6_tmp + 3] = rtb_out;
    P4planar[theta6_tmp + 2] = rtb_Sum11;
    P4planar[theta6_tmp + 1] = XE;
    P4planar[theta6_tmp] = theta6;
  }

  XE = P4planar[12] - P2planar[12];
  rtb_Sum11 = P4planar[14] - P2planar[14];
  theta6_tmp_0 = XE * XE;
  rtb_out = rtb_Sum11 * rtb_Sum11;
  theta6 = (theta6_tmp_0 - 0.0256) + rtb_out;
  theta6 = atan(sqrt(((0.16 - theta6_tmp_0) - rtb_out) * theta6) / theta6) *
    -2.0;
  rtb_Sum10 = atan((sqrt((((((((theta6_tmp_0 * 0.15680000000000002 -
    0.0038886400000000022) + rtb_out * 0.15680000000000002) -
    0.00020735999999999997) + theta6_tmp_0 * 0.0288) + rtb_out * 0.0288) -
    rt_powd_snf(XE, 4.0)) - theta6_tmp_0 * 2.0 * rtb_out) - rt_powd_snf
    (rtb_Sum11, 4.0)) + 0.56 * rtb_Sum11) / ((((0.56 * XE + 0.078400000000000011)
    - 0.0144) + theta6_tmp_0) + rtb_out)) * 2.0 + (3.1415926535897931 -
    rtb_Sum10);
  XE = sin(rtb_Gain15);
  rtb_Sum11 = cos(rtb_Gain15);
  rtb_Gain15 = sin(rtb_Sum10);
  rtb_Sum10 = cos(rtb_Sum10);
  rtb_out = sin(theta6);
  theta6 = cos(theta6);
  rtb_Sum6 = sin(rtb_Gain16);
  rtb_Gain16 = cos(rtb_Gain16);
  P2planar[0] = rtb_Sum11;
  P2planar[4] = -XE;
  P2planar[8] = 0.0;
  P2planar[12] = 0.0;
  P2planar[1] = XE;
  P2planar[5] = rtb_Sum11;
  P2planar[9] = 0.0;
  P2planar[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    TPbasetoP3_tmp_1 = i_0 << 2;
    P2planar[TPbasetoP3_tmp_1 + 2] = TPbasetoP3_tmp[i_0];
    P2planar[TPbasetoP3_tmp_1 + 3] = TPbasetoP3_tmp_0[i_0];
    b_a[TPbasetoP3_tmp_1] = 0.0;
    b_a[TPbasetoP3_tmp_1 + 1] = 0.0;
    b_a[TPbasetoP3_tmp_1 + 2] = 0.0;
    b_a[TPbasetoP3_tmp_1 + 3] = 0.0;
  }

  theta6_0[0] = rtb_Sum10;
  theta6_0[4] = -rtb_Gain15;
  theta6_0[8] = 0.0;
  theta6_0[12] = 0.12;
  theta6_0[1] = rtb_Gain15;
  theta6_0[5] = rtb_Sum10;
  theta6_0[9] = 0.0;
  theta6_0[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    TPbasetoP3_tmp_2 = i_0 << 2;
    theta6_0[TPbasetoP3_tmp_2 + 2] = TPbasetoP3_tmp[i_0];
    theta6_0[TPbasetoP3_tmp_2 + 3] = TPbasetoP3_tmp_0[i_0];
    rtb_Sum11 = b_a[TPbasetoP3_tmp_2];
    rtb_Sum10 = b_a[TPbasetoP3_tmp_2 + 1];
    rtb_Gain15 = b_a[TPbasetoP3_tmp_2 + 2];
    XE = b_a[TPbasetoP3_tmp_2 + 3];
    for (i = 0; i < 4; i++) {
      theta6_tmp = TPbasetoP3_tmp_2 + i;
      theta6_tmp_0 = TPbasetoP3[theta6_tmp];
      TPbasetoP3_tmp_1 = i << 2;
      rtb_Sum11 += P2planar[TPbasetoP3_tmp_1] * theta6_tmp_0;
      rtb_Sum10 += P2planar[TPbasetoP3_tmp_1 + 1] * theta6_tmp_0;
      rtb_Gain15 += P2planar[TPbasetoP3_tmp_1 + 2] * theta6_tmp_0;
      XE += P2planar[TPbasetoP3_tmp_1 + 3] * theta6_tmp_0;
      P4planar[theta6_tmp] = 0.0;
    }

    b_a[TPbasetoP3_tmp_2 + 3] = XE;
    b_a[TPbasetoP3_tmp_2 + 2] = rtb_Gain15;
    b_a[TPbasetoP3_tmp_2 + 1] = rtb_Sum10;
    b_a[TPbasetoP3_tmp_2] = rtb_Sum11;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    TPbasetoP3_tmp_1 = i_0 << 2;
    rtb_Sum11 = P4planar[TPbasetoP3_tmp_1];
    rtb_Sum10 = P4planar[TPbasetoP3_tmp_1 + 1];
    rtb_Gain15 = P4planar[TPbasetoP3_tmp_1 + 2];
    XE = P4planar[TPbasetoP3_tmp_1 + 3];
    for (i = 0; i < 4; i++) {
      theta6_tmp_0 = theta6_0[TPbasetoP3_tmp_1 + i];
      theta6_tmp = i << 2;
      rtb_Sum11 += b_a[theta6_tmp] * theta6_tmp_0;
      rtb_Sum10 += b_a[theta6_tmp + 1] * theta6_tmp_0;
      rtb_Gain15 += b_a[theta6_tmp + 2] * theta6_tmp_0;
      XE += b_a[theta6_tmp + 3] * theta6_tmp_0;
    }

    P4planar[TPbasetoP3_tmp_1 + 3] = XE;
    P4planar[TPbasetoP3_tmp_1 + 2] = rtb_Gain15;
    P4planar[TPbasetoP3_tmp_1 + 1] = rtb_Sum10;
    P4planar[TPbasetoP3_tmp_1] = rtb_Sum11;
  }

  theta6_0[0] = theta6;
  theta6_0[4] = -rtb_out;
  theta6_0[8] = 0.0;
  theta6_0[12] = 0.28;
  theta6_0[1] = rtb_out;
  theta6_0[5] = theta6;
  theta6_0[9] = 0.0;
  theta6_0[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    theta6_tmp = i_0 << 2;
    theta6_0[theta6_tmp + 2] = TPbasetoP3_tmp[i_0];
    theta6_0[theta6_tmp + 3] = TPbasetoP3_tmp_0[i_0];
    rtb_Sum11 = 0.0;
    rtb_Sum10 = 0.0;
    rtb_Gain15 = 0.0;
    XE = 0.0;
    for (i = 0; i < 4; i++) {
      theta6_tmp_0 = theta6_0[theta6_tmp + i];
      TPbasetoP3_tmp_1 = i << 2;
      rtb_Sum11 += P4planar[TPbasetoP3_tmp_1] * theta6_tmp_0;
      rtb_Sum10 += P4planar[TPbasetoP3_tmp_1 + 1] * theta6_tmp_0;
      rtb_Gain15 += P4planar[TPbasetoP3_tmp_1 + 2] * theta6_tmp_0;
      XE += P4planar[TPbasetoP3_tmp_1 + 3] * theta6_tmp_0;
    }

    P2planar[theta6_tmp + 3] = XE;
    P2planar[theta6_tmp + 2] = rtb_Gain15;
    P2planar[theta6_tmp + 1] = rtb_Sum10;
    P2planar[theta6_tmp] = rtb_Sum11;
  }

  TPbasetoP3[0] = rtb_Gain16;
  TPbasetoP3[4] = -rtb_Sum6;
  TPbasetoP3[8] = 0.0;
  TPbasetoP3[12] = 0.62;
  TPbasetoP3[1] = rtb_Sum6;
  TPbasetoP3[5] = rtb_Gain16;
  TPbasetoP3[9] = 0.0;
  TPbasetoP3[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    theta6_tmp = i_0 << 2;
    TPbasetoP3[theta6_tmp + 2] = TPbasetoP3_tmp[i_0];
    TPbasetoP3[theta6_tmp + 3] = TPbasetoP3_tmp_0[i_0];
    rtb_Sum11 = 0.0;
    rtb_Sum10 = 0.0;
    rtb_Gain15 = 0.0;
    XE = 0.0;
    for (i = 0; i < 4; i++) {
      theta6_tmp_0 = TPbasetoP3[theta6_tmp + i];
      TPbasetoP3_tmp_1 = i << 2;
      rtb_Sum11 += P2planar[TPbasetoP3_tmp_1] * theta6_tmp_0;
      rtb_Sum10 += P2planar[TPbasetoP3_tmp_1 + 1] * theta6_tmp_0;
      rtb_Gain15 += P2planar[TPbasetoP3_tmp_1 + 2] * theta6_tmp_0;
      XE += P2planar[TPbasetoP3_tmp_1 + 3] * theta6_tmp_0;
    }

    b_a[theta6_tmp + 3] = XE;
    b_a[theta6_tmp + 2] = rtb_Gain15;
    b_a[theta6_tmp + 1] = rtb_Sum10;
    b_a[theta6_tmp] = rtb_Sum11;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    theta6 = 0.0;
    XE = 0.0;
    rtb_Sum11 = 0.0;
    rtb_out = 0.0;
    for (i = 0; i < 4; i++) {
      theta6_tmp_0 = d_b[(i_0 << 2) + i];
      TPbasetoP3_tmp_2 = i << 2;
      theta6 += b_a[TPbasetoP3_tmp_2] * theta6_tmp_0;
      XE += b_a[TPbasetoP3_tmp_2 + 1] * theta6_tmp_0;
      rtb_Sum11 += b_a[TPbasetoP3_tmp_2 + 2] * theta6_tmp_0;
      rtb_out += b_a[TPbasetoP3_tmp_2 + 3] * theta6_tmp_0;
    }

    TPbasetoP3_tmp_2 = i_0 << 2;
    P2planar[TPbasetoP3_tmp_2 + 3] = rtb_out;
    P2planar[TPbasetoP3_tmp_2 + 2] = rtb_Sum11;
    P2planar[TPbasetoP3_tmp_2 + 1] = XE;
    P2planar[TPbasetoP3_tmp_2] = theta6;
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/x'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  rtb_Gain16 = P2planar[12] - rtU.x;

  /* DotProduct: '<S3>/Dot Product' */
  theta6_tmp_0 = rtb_Gain16 * rtb_Gain16;

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/y'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  rtb_Gain16 = P2planar[13] - rtU.y;

  /* DotProduct: '<S3>/Dot Product' */
  theta6_tmp_0 += rtb_Gain16 * rtb_Gain16;

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/z'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  rtb_Gain16 = P2planar[14] - rtU.z;

  /* Outport: '<Root>/pointReached' incorporates:
   *  Constant: '<S2>/Constant'
   *  DotProduct: '<S3>/Dot Product'
   *  RelationalOperator: '<S2>/Compare'
   *  Sqrt: '<S3>/sqrt'
   */
  rtY.pointReached = (sqrt(rtb_Gain16 * rtb_Gain16 + theta6_tmp_0) <= 0.00015);

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
  if (rtU.x < 0.0) {
    rtb_Gain16 = atan(rtU.y / rtU.x) + 3.1415926535897931;
  } else {
    rtb_Gain16 = atan(rtU.y / rtU.x);
  }

  XE = rtb_Gain16 - 3.1415926535897931;
  if (rtb_Gain16 > 3.1415926535897931) {
    rtb_Gain16 -= 6.2831853071795862;
  }

  rtb_Gain16 = -rtb_Gain16;
  rtb_Sum11 = sin(XE);
  rtb_Sum10 = cos(XE);
  theta6_0[0] = rtb_Sum10;
  theta6_0[4] = -rtb_Sum11;
  theta6_0[8] = 0.0;
  theta6_0[12] = rtU.x;
  theta6_0[1] = rtb_Sum11;
  theta6_0[5] = rtb_Sum10;
  theta6_0[9] = 0.0;
  theta6_0[13] = rtU.y;
  theta6_0[2] = 0.0;
  theta6_0[6] = 0.0;
  theta6_0[10] = 1.0;
  theta6_0[14] = rtU.z;
  P2planar[0] = cos(rtU.gripperAng);
  P2planar[4] = -sin(rtU.gripperAng);
  P2planar[8] = 0.0;
  P2planar[12] = 0.0;
  P2planar[1] = sin(rtU.gripperAng);
  P2planar[5] = cos(rtU.gripperAng);
  P2planar[9] = 0.0;
  P2planar[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    TPbasetoP3_tmp_3 = TPbasetoP3_tmp_0[i_0];
    TPbasetoP3_tmp_2 = i_0 << 2;
    theta6_0[TPbasetoP3_tmp_2 + 3] = TPbasetoP3_tmp_3;
    P2planar[TPbasetoP3_tmp_2 + 2] = TPbasetoP3_tmp[i_0];
    P2planar[TPbasetoP3_tmp_2 + 3] = TPbasetoP3_tmp_3;
    b_a[TPbasetoP3_tmp_2] = 0.0;
    b_a[TPbasetoP3_tmp_2 + 1] = 0.0;
    b_a[TPbasetoP3_tmp_2 + 2] = 0.0;
    b_a[TPbasetoP3_tmp_2 + 3] = 0.0;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    TPbasetoP3_tmp_2 = i_0 << 2;
    rtb_Sum10 = b_a[TPbasetoP3_tmp_2];
    theta6_tmp_0 = b_a[TPbasetoP3_tmp_2 + 1];
    rtb_Gain15 = b_a[TPbasetoP3_tmp_2 + 2];
    theta6 = b_a[TPbasetoP3_tmp_2 + 3];
    for (i = 0; i < 4; i++) {
      theta6_tmp = TPbasetoP3_tmp_2 + i;
      TPbasetoP3_tmp_1 = b_b_0[theta6_tmp];
      rtb_Sum10_tmp = i << 2;
      rtb_Sum10 += theta6_0[rtb_Sum10_tmp] * (real_T)TPbasetoP3_tmp_1;
      theta6_tmp_0 += theta6_0[rtb_Sum10_tmp + 1] * (real_T)TPbasetoP3_tmp_1;
      rtb_Gain15 += theta6_0[rtb_Sum10_tmp + 2] * (real_T)TPbasetoP3_tmp_1;
      theta6 += theta6_0[rtb_Sum10_tmp + 3] * (real_T)TPbasetoP3_tmp_1;
      P4planar[theta6_tmp] = 0.0;
    }

    b_a[TPbasetoP3_tmp_2 + 3] = theta6;
    b_a[TPbasetoP3_tmp_2 + 2] = rtb_Gain15;
    b_a[TPbasetoP3_tmp_2 + 1] = theta6_tmp_0;
    b_a[TPbasetoP3_tmp_2] = rtb_Sum10;
    theta6_tmp_0 = P4planar[TPbasetoP3_tmp_2];
    rtb_Sum10 = P4planar[TPbasetoP3_tmp_2 + 1];
    rtb_Gain15 = P4planar[TPbasetoP3_tmp_2 + 2];
    theta6 = P4planar[TPbasetoP3_tmp_2 + 3];
    for (i = 0; i < 4; i++) {
      theta6_tmp = TPbasetoP3_tmp_2 + i;
      XE = d_b[theta6_tmp];
      TPbasetoP3_tmp_1 = i << 2;
      theta6_tmp_0 += P2planar[TPbasetoP3_tmp_1] * XE;
      rtb_Sum10 += P2planar[TPbasetoP3_tmp_1 + 1] * XE;
      rtb_Gain15 += P2planar[TPbasetoP3_tmp_1 + 2] * XE;
      theta6 += P2planar[TPbasetoP3_tmp_1 + 3] * XE;
      TPbasetoP3[theta6_tmp] = 0.0;
    }

    P4planar[TPbasetoP3_tmp_2 + 3] = theta6;
    P4planar[TPbasetoP3_tmp_2 + 2] = rtb_Gain15;
    P4planar[TPbasetoP3_tmp_2 + 1] = rtb_Sum10;
    P4planar[TPbasetoP3_tmp_2] = theta6_tmp_0;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    TPbasetoP3_tmp_1 = i_0 << 2;
    rtb_out = TPbasetoP3[TPbasetoP3_tmp_1];
    rtb_Sum6 = TPbasetoP3[TPbasetoP3_tmp_1 + 1];
    TPbasetoP3_0 = TPbasetoP3[TPbasetoP3_tmp_1 + 2];
    TPbasetoP3_1 = TPbasetoP3[TPbasetoP3_tmp_1 + 3];
    for (i = 0; i < 4; i++) {
      theta6_tmp_0 = P4planar[TPbasetoP3_tmp_1 + i];
      TPbasetoP3_tmp_2 = i << 2;
      rtb_out += b_a[TPbasetoP3_tmp_2] * theta6_tmp_0;
      rtb_Sum6 += b_a[TPbasetoP3_tmp_2 + 1] * theta6_tmp_0;
      TPbasetoP3_0 += b_a[TPbasetoP3_tmp_2 + 2] * theta6_tmp_0;
      TPbasetoP3_1 += b_a[TPbasetoP3_tmp_2 + 3] * theta6_tmp_0;
    }

    TPbasetoP3[TPbasetoP3_tmp_1 + 3] = TPbasetoP3_1;
    TPbasetoP3[TPbasetoP3_tmp_1 + 2] = TPbasetoP3_0;
    TPbasetoP3[TPbasetoP3_tmp_1 + 1] = rtb_Sum6;
    TPbasetoP3[TPbasetoP3_tmp_1] = rtb_out;
  }

  rtb_Sum11 = sqrt(TPbasetoP3[12] * TPbasetoP3[12] + TPbasetoP3[13] *
                   TPbasetoP3[13]);
  theta6_tmp_0 = rtb_Sum11 * rtb_Sum11;
  rtb_Sum10 = (TPbasetoP3[14] - 0.065) * (TPbasetoP3[14] - 0.065);
  rtb_Gain15 = (((((((theta6_tmp_0 * 0.24499999999999997 + 0.04624375) +
                     rtb_Sum10 * 0.24499999999999997) - 0.0625) + theta6_tmp_0 *
                   0.5) + rtb_Sum10 * 0.5) - rt_powd_snf(rtb_Sum11, 4.0)) -
                theta6_tmp_0 * 2.0 * rtb_Sum10) - rt_powd_snf(TPbasetoP3[14] -
    0.065, 4.0);
  if (rtb_Gain15 < 0.0) {
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_angles[i_0] = d[i_0];
    }

    /* Outport: '<Root>/error' */
    rtY.error = 1.0;
  } else {
    XE = atan(((TPbasetoP3[14] - 0.065) * 0.7 + sqrt(rtb_Gain15)) / ((((0.7 *
      rtb_Sum11 + 0.12249999999999998) - 0.25) + theta6_tmp_0) + rtb_Sum10)) *
      2.0;
    rtb_Gain15 = (theta6_tmp_0 - 0.02250000000000002) + rtb_Sum10;
    rtb_Gain15 = atan(sqrt(((0.72249999999999992 - theta6_tmp_0) - rtb_Sum10) *
      rtb_Gain15) / rtb_Gain15) * -2.0;
    theta6 = (-rtU.gripperAng - XE) - rtb_Gain15;
    rtb_Sum11 = sin(XE);
    rtb_Sum10 = cos(XE);
    rtb_out = sin(rtb_Gain15);
    rtb_Sum6 = cos(rtb_Gain15);
    theta6_0[0] = rtb_Sum10;
    theta6_0[4] = -rtb_Sum11;
    theta6_0[8] = 0.0;
    theta6_0[12] = 0.0;
    theta6_0[1] = rtb_Sum11;
    theta6_0[5] = rtb_Sum10;
    theta6_0[9] = 0.0;
    theta6_0[13] = 0.0;
    for (i_0 = 0; i_0 < 4; i_0++) {
      TPbasetoP3_tmp_2 = i_0 << 2;
      theta6_0[TPbasetoP3_tmp_2 + 2] = TPbasetoP3_tmp[i_0];
      theta6_0[TPbasetoP3_tmp_2 + 3] = TPbasetoP3_tmp_0[i_0];
      rtb_Sum10 = 0.0;
      rtb_Gain15 = 0.0;
      rtb_Sum11 = 0.0;
      TPbasetoP3_0 = 0.0;
      for (i = 0; i < 4; i++) {
        theta6_tmp_0 = theta6_0[TPbasetoP3_tmp_2 + i];
        theta6_tmp = i << 2;
        rtb_Sum10 += b_a_0[theta6_tmp] * theta6_tmp_0;
        rtb_Gain15 += b_a_0[theta6_tmp + 1] * theta6_tmp_0;
        rtb_Sum11 += b_a_0[theta6_tmp + 2] * theta6_tmp_0;
        TPbasetoP3_0 += b_a_0[theta6_tmp + 3] * theta6_tmp_0;
      }

      TPbasetoP3[TPbasetoP3_tmp_2 + 3] = TPbasetoP3_0;
      TPbasetoP3[TPbasetoP3_tmp_2 + 2] = rtb_Sum11;
      TPbasetoP3[TPbasetoP3_tmp_2 + 1] = rtb_Gain15;
      TPbasetoP3[TPbasetoP3_tmp_2] = rtb_Sum10;
    }

    P2planar[0] = rtb_Sum6;
    P2planar[4] = -rtb_out;
    P2planar[8] = 0.0;
    P2planar[12] = 0.35;
    P2planar[1] = rtb_out;
    P2planar[5] = rtb_Sum6;
    P2planar[9] = 0.0;
    P2planar[13] = 0.0;
    for (i_0 = 0; i_0 < 4; i_0++) {
      TPbasetoP3_tmp_2 = i_0 << 2;
      P2planar[TPbasetoP3_tmp_2 + 2] = TPbasetoP3_tmp[i_0];
      P2planar[TPbasetoP3_tmp_2 + 3] = TPbasetoP3_tmp_0[i_0];
      rtb_Sum11 = 0.0;
      rtb_out = 0.0;
      rtb_Sum6 = 0.0;
      TPbasetoP3_0 = 0.0;
      for (i = 0; i < 4; i++) {
        theta6_tmp = TPbasetoP3_tmp_2 + i;
        theta6_tmp_0 = TPbasetoP3[theta6_tmp];
        TPbasetoP3_tmp_1 = i << 2;
        rtb_Sum11 += (real_T)P2planar_tmp[TPbasetoP3_tmp_1] * theta6_tmp_0;
        rtb_out += (real_T)P2planar_tmp[TPbasetoP3_tmp_1 + 1] * theta6_tmp_0;
        rtb_Sum6 += (real_T)P2planar_tmp[TPbasetoP3_tmp_1 + 2] * theta6_tmp_0;
        TPbasetoP3_0 += (real_T)P2planar_tmp[TPbasetoP3_tmp_1 + 3] *
          theta6_tmp_0;
        b_a[theta6_tmp] = 0.0;
      }

      theta6_0[TPbasetoP3_tmp_2 + 3] = TPbasetoP3_0;
      theta6_0[TPbasetoP3_tmp_2 + 2] = rtb_Sum6;
      theta6_0[TPbasetoP3_tmp_2 + 1] = rtb_out;
      theta6_0[TPbasetoP3_tmp_2] = rtb_Sum11;
    }

    for (i_0 = 0; i_0 < 4; i_0++) {
      TPbasetoP3_tmp_1 = i_0 << 2;
      rtb_Sum11 = b_a[TPbasetoP3_tmp_1];
      rtb_out = b_a[TPbasetoP3_tmp_1 + 1];
      rtb_Sum6 = b_a[TPbasetoP3_tmp_1 + 2];
      TPbasetoP3_0 = b_a[TPbasetoP3_tmp_1 + 3];
      for (i = 0; i < 4; i++) {
        theta6_tmp_0 = P2planar[TPbasetoP3_tmp_1 + i];
        theta6_tmp = i << 2;
        rtb_Sum11 += theta6_0[theta6_tmp] * theta6_tmp_0;
        rtb_out += theta6_0[theta6_tmp + 1] * theta6_tmp_0;
        rtb_Sum6 += theta6_0[theta6_tmp + 2] * theta6_tmp_0;
        TPbasetoP3_0 += theta6_0[theta6_tmp + 3] * theta6_tmp_0;
      }

      b_a[TPbasetoP3_tmp_1 + 3] = TPbasetoP3_0;
      b_a[TPbasetoP3_tmp_1 + 2] = rtb_Sum6;
      b_a[TPbasetoP3_tmp_1 + 1] = rtb_out;
      b_a[TPbasetoP3_tmp_1] = rtb_Sum11;
    }

    for (i_0 = 0; i_0 < 4; i_0++) {
      rtb_out = 0.0;
      rtb_Sum6 = 0.0;
      TPbasetoP3_0 = 0.0;
      TPbasetoP3_1 = 0.0;
      for (i = 0; i < 4; i++) {
        theta6_tmp_0 = d_b_0[(i_0 << 2) + i];
        TPbasetoP3_tmp_1 = i << 2;
        rtb_out += b_a[TPbasetoP3_tmp_1] * theta6_tmp_0;
        rtb_Sum6 += b_a[TPbasetoP3_tmp_1 + 1] * theta6_tmp_0;
        TPbasetoP3_0 += b_a[TPbasetoP3_tmp_1 + 2] * theta6_tmp_0;
        TPbasetoP3_1 += b_a[TPbasetoP3_tmp_1 + 3] * theta6_tmp_0;
      }

      TPbasetoP3_tmp_1 = i_0 << 2;
      TPbasetoP3[TPbasetoP3_tmp_1 + 3] = TPbasetoP3_1;
      TPbasetoP3[TPbasetoP3_tmp_1 + 2] = TPbasetoP3_0;
      TPbasetoP3[TPbasetoP3_tmp_1 + 1] = rtb_Sum6;
      TPbasetoP3[TPbasetoP3_tmp_1] = rtb_out;
    }

    theta6_tmp_0 = TPbasetoP3[12] * TPbasetoP3[12];
    rtb_Sum10 = (TPbasetoP3[14] - 0.149) * (TPbasetoP3[14] - 0.149);
    rtb_Sum11 = atan((sqrt((((((((theta6_tmp_0 * 0.0288 + 0.00205056) +
      rtb_Sum10 * 0.0288) - 0.0061465600000000023) + theta6_tmp_0 *
      0.15680000000000002) + rtb_Sum10 * 0.15680000000000002) - rt_powd_snf
      (TPbasetoP3[12], 4.0)) - theta6_tmp_0 * 2.0 * rtb_Sum10) - rt_powd_snf
      (TPbasetoP3[14] - 0.149, 4.0)) + (TPbasetoP3[14] - 0.149) * 0.24) /
                     ((((0.24 * TPbasetoP3[12] + 0.0144) - 0.078400000000000011)
                       + theta6_tmp_0) + rtb_Sum10)) * 2.0;
    if ((fabs(rtb_Gain16) > 3.1415926535897931) || ((XE < 0.0) || (XE >
          2.3561944901923448) || (theta6 < -2.3561944901923448) || (theta6 >
          0.78539816339744828) || (rtb_Sum11 < 1.5707963267948966) || (rtb_Sum11
          > 4.71238898038469))) {
      for (i_0 = 0; i_0 < 5; i_0++) {
        rtb_angles[i_0] = d[i_0];
      }

      /* Outport: '<Root>/error' */
      rtY.error = 2.0;
    } else {
      rtb_angles[0] = rtb_Gain16;
      rtb_angles[1] = XE;
      rtb_angles[3] = theta6;
      rtb_angles[4] = rtb_Sum11;

      /* Outport: '<Root>/error' */
      rtY.error = 0.0;
    }
  }

  /* Outport: '<Root>/StepsLeftBase' incorporates:
   *  Constant: '<S1>/Constant6'
   *  Constant: '<S1>/Pi'
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Gain13'
   *  Product: '<S1>/Divide'
   *  Sum: '<S1>/Sum7'
   */
  rtY.StepsLeftBase = (rtb_angles[4] + 1.5707963267948966) * 160.0 *
    57.295779513082323 / 1.8;

  /* Outport: '<Root>/StepsRightBase' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Pi1'
   *  Gain: '<S1>/Gain4'
   *  Gain: '<S1>/Gain8'
   *  Product: '<S1>/Divide1'
   *  Sum: '<S1>/Sum9'
   */
  rtY.StepsRightBase = (rtb_angles[1] + 1.5707963267948966) * 160.0 *
    57.295779513082323 / 1.8;

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Gain: '<S1>/Gain10'
   *  Gain: '<S1>/Gain12'
   *  Inport: '<Root>/deltaTime'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  MATLABFunction(rtDW.UnitDelay2_DSTATE, 21.0 * rtb_angles[3], 4.2 *
                 rtU.deltaTime, &rtb_Gain16);

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Gain: '<S1>/Gain11'
   *  Gain: '<S1>/Gain6'
   *  Inport: '<Root>/deltaTime'
   *  UnitDelay: '<S1>/Unit Delay5'
   */
  MATLABFunction(rtDW.UnitDelay5_DSTATE, 63.0 * rtb_angles[0], 20.0 *
                 rtU.deltaTime, &rtb_Sum11);

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain5'
   *  Gain: '<S1>/Gain9'
   *  Inport: '<Root>/deltaTime'
   *  Inport: '<Root>/gripperRotationDesiredPosition'
   *  UnitDelay: '<S1>/Unit Delay7'
   */
  MATLABFunction(rtDW.UnitDelay7_DSTATE, 21.0 * (0.017453292519943295 *
    rtU.gripperRotationDesiredPosition), 21.0 * rtU.deltaTime, &theta6);

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Gain3'
   *  Gain: '<S1>/Gain7'
   *  Inport: '<Root>/deltaTime'
   *  Inport: '<Root>/jawDesiredPosition'
   *  UnitDelay: '<S1>/Unit Delay9'
   */
  MATLABFunction(rtDW.UnitDelay9_DSTATE, 21.0 * (0.017453292519943295 *
    rtU.jawDesiredPosition), 2.1 * rtU.deltaTime, &rtb_out);

  /* Sum: '<S1>/Sum6' incorporates:
   *  Inport: '<Root>/jawActualPosition'
   *  UnitDelay: '<S1>/Unit Delay9'
   */
  rtb_Sum6 = rtDW.UnitDelay9_DSTATE - rtU.actualposition;

  /* Update for UnitDelay: '<S1>/Unit Delay8' incorporates:
   *  DiscreteIntegrator: '<S204>/Integrator'
   *  Gain: '<S209>/Proportional Gain'
   *  Sum: '<S213>/Sum'
   */
  rtDW.UnitDelay8_DSTATE = 2.0 * rtb_Sum6 + rtDW.Integrator_DSTATE_c;

  /* Gain: '<S157>/Proportional Gain' incorporates:
   *  Gain: '<S149>/Integral Gain'
   *  Inport: '<Root>/gripperRotationActualPosition'
   *  Sum: '<S1>/Sum5'
   *  UnitDelay: '<S1>/Unit Delay7'
   */
  theta6_tmp_0 = (rtDW.UnitDelay7_DSTATE - rtU.actualposition_o) * 0.2;

  /* Update for UnitDelay: '<S1>/Unit Delay6' incorporates:
   *  DiscreteIntegrator: '<S152>/Integrator'
   *  Gain: '<S157>/Proportional Gain'
   *  Sum: '<S161>/Sum'
   */
  rtDW.UnitDelay6_DSTATE = theta6_tmp_0 + rtDW.Integrator_DSTATE_j;

  /* Gain: '<S105>/Proportional Gain' incorporates:
   *  Gain: '<S97>/Integral Gain'
   *  Inport: '<Root>/gripperPitchActualPosition'
   *  Sum: '<S1>/Sum4'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  rtb_Sum10 = (rtDW.UnitDelay2_DSTATE - rtU.actualposition_f) * 0.1;

  /* Update for UnitDelay: '<S1>/Unit Delay4' incorporates:
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Gain: '<S105>/Proportional Gain'
   *  Sum: '<S109>/Sum'
   */
  rtDW.UnitDelay4_DSTATE = rtb_Sum10 + rtDW.Integrator_DSTATE;

  /* Gain: '<S53>/Proportional Gain' incorporates:
   *  Gain: '<S45>/Integral Gain'
   *  Inport: '<Root>/baseActualPosition'
   *  Sum: '<S1>/Sum2'
   *  UnitDelay: '<S1>/Unit Delay5'
   */
  rtb_Gain15 = (rtDW.UnitDelay5_DSTATE - rtU.actualposition_b) * 0.2;

  /* Update for UnitDelay: '<S1>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S48>/Integrator'
   *  Gain: '<S53>/Proportional Gain'
   *  Sum: '<S57>/Sum'
   */
  rtDW.UnitDelay1_DSTATE = rtb_Gain15 + rtDW.Integrator_DSTATE_g;

  /* Update for UnitDelay: '<S1>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE = rtb_Gain16;

  /* Update for DiscreteIntegrator: '<S100>/Integrator' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S113>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE += rtb_Sum10 * rtU.deltaTime;

  /* Update for UnitDelay: '<S1>/Unit Delay5' */
  rtDW.UnitDelay5_DSTATE = rtb_Sum11;

  /* Update for DiscreteIntegrator: '<S48>/Integrator' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S61>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE_g += rtb_Gain15 * rtU.deltaTime;

  /* Update for UnitDelay: '<S1>/Unit Delay7' */
  rtDW.UnitDelay7_DSTATE = theta6;

  /* Update for DiscreteIntegrator: '<S152>/Integrator' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S165>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE_j += theta6_tmp_0 * rtU.deltaTime;

  /* Update for UnitDelay: '<S1>/Unit Delay9' */
  rtDW.UnitDelay9_DSTATE = rtb_out;

  /* Update for DiscreteIntegrator: '<S204>/Integrator' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S217>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE_c += rtb_Sum6 * rtU.deltaTime;
}

/* Model initialize function */
void control_arm_initialize(void)
{
  /* ConstCode for Outport: '<Root>/FreqLeftBase' incorporates:
   *  Constant: '<S1>/frequency'
   */
  rtY.FreqLeftBase = 50.0;

  /* ConstCode for Outport: '<Root>/FreqRightBase' incorporates:
   *  Constant: '<S1>/frequency1'
   */
  rtY.FreqRightBase = 50.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
