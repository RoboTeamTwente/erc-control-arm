/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_arm.c
 *
 * Code generated for Simulink model 'control_arm'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Mar 30 12:08:07 2026
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
extern real_T rt_roundd_snf(real_T u);
static void MATLABFunction(real_T rtu_current, real_T rtu_startPosition, real_T
  rtu_desired, real_T rtu_timePerMovement, real_T rtu_deltaTime, real_T *rty_out);
static void MATLABFunction1(real_T rtu_startPosition, real_T rtu_desired, real_T
  rtu_timePerMovement, real_T *rty_out);
static void MATLABFunction2(real_T rtu_current, real_T rtu_desired, real_T
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
 *    '<S1>/MATLAB Function5'
 */
static void MATLABFunction(real_T rtu_current, real_T rtu_startPosition, real_T
  rtu_desired, real_T rtu_timePerMovement, real_T rtu_deltaTime, real_T *rty_out)
{
  real_T current;
  real_T velocity;
  current = rtu_current;
  velocity = fabs(rtu_desired - rtu_startPosition) / rtu_timePerMovement;
  if (rtu_current < rtu_desired) {
    current = velocity * rtu_deltaTime + rtu_current;
  }

  if (current > rtu_desired) {
    current -= velocity * rtu_deltaTime;
  }

  *rty_out = current;
}

/*
 * Output and update for atomic system:
 *    '<S1>/MATLAB Function1'
 *    '<S1>/MATLAB Function6'
 */
static void MATLABFunction1(real_T rtu_startPosition, real_T rtu_desired, real_T
  rtu_timePerMovement, real_T *rty_out)
{
  *rty_out = fabs(rtu_desired - rtu_startPosition) / rtu_timePerMovement;
}

/*
 * Output and update for atomic system:
 *    '<S1>/MATLAB Function2'
 *    '<S1>/MATLAB Function3'
 */
static void MATLABFunction2(real_T rtu_current, real_T rtu_desired, real_T
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
void control_arm_step(void)
{
  real_T P2planar[16];
  real_T P4planar[16];
  real_T TPbasetoP3[16];
  real_T b_a[16];
  real_T theta5_0[16];
  real_T rtb_angles[5];
  real_T TPbasetoP3_0;
  real_T XE;
  real_T YE;
  real_T a;
  real_T rtb_Gain15;
  real_T rtb_Gain16;
  real_T rtb_Sum10;
  real_T rtb_Sum11;
  real_T theta2;
  real_T theta5;
  int16_T TPbasetoP3_tmp_1;
  int16_T TPbasetoP3_tmp_2;
  int16_T i;
  int16_T i_0;
  int16_T theta5_tmp;
  int16_T theta5_tmp_0;
  int8_T P2planar_tmp[16];
  int8_T TPbasetoP3_tmp[4];
  int8_T TPbasetoP3_tmp_0[4];
  int8_T TPbasetoP3_tmp_3;
  static const int8_T b[4] = { 0, 0, 1, 0 };

  static const int8_T c[4] = { 0, 0, 0, 1 };

  static const int8_T c_a[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  static const real_T a_0[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
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
  rtb_Gain15 = -0.015873015873015872 * rtU.actualposition_e;

  /* Sum: '<S1>/Sum11' incorporates:
   *  Constant: '<S1>/Pi2'
   *  Gain: '<S1>/Gain14'
   *  Gain: '<S1>/Gain17'
   *  Gain: '<S1>/Gain4'
   *  Inport: '<Root>/stepperRightActualPosition'
   */
  rtb_Sum11 = 1.8 * rtU.actualposition_o * 0.017453292519943295 * 0.00625 -
    1.5707963267948966;

  /* Gain: '<S1>/Gain16' incorporates:
   *  Inport: '<Root>/gripperPitchActualPosition'
   */
  rtb_Gain16 = 0.047619047619047616 * rtU.actualposition_p;

  /* Sum: '<S1>/Sum10' incorporates:
   *  Constant: '<S1>/Pi2'
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Gain18'
   *  Gain: '<S1>/Gain19'
   *  Inport: '<Root>/stepperLeftActualPosition'
   */
  rtb_Sum10 = 1.8 * rtU.actualposition_f * 0.017453292519943295 * 0.00625 -
    1.5707963267948966;

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  theta2 = sin(rtb_Sum10);
  theta5 = cos(rtb_Sum10);
  theta5_0[0] = theta5;
  theta5_0[4] = -theta2;
  theta5_0[8] = 0.0;
  theta5_0[12] = 0.0;
  theta5_0[1] = theta2;
  theta5_0[5] = theta5;
  theta5_0[9] = 0.0;
  theta5_0[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    /* MATLAB Function: '<S1>/inverse kinematics' */
    TPbasetoP3_tmp_1 = b[i_0];
    TPbasetoP3_tmp[i_0] = (int8_T)TPbasetoP3_tmp_1;

    /* MATLAB Function: '<S1>/inverse kinematics' */
    TPbasetoP3_tmp_2 = c[i_0];
    TPbasetoP3_tmp_0[i_0] = (int8_T)TPbasetoP3_tmp_2;
    theta5_tmp = i_0 << 2;
    theta5_0[theta5_tmp + 2] = TPbasetoP3_tmp_1;
    theta5_0[theta5_tmp + 3] = TPbasetoP3_tmp_2;
    XE = 0.0;
    YE = 0.0;
    theta5 = 0.0;
    TPbasetoP3_0 = 0.0;
    for (i = 0; i < 4; i++) {
      theta2 = theta5_0[theta5_tmp + i];
      TPbasetoP3_tmp_1 = i << 2;
      XE += a_0[TPbasetoP3_tmp_1] * theta2;
      YE += a_0[TPbasetoP3_tmp_1 + 1] * theta2;
      theta5 += a_0[TPbasetoP3_tmp_1 + 2] * theta2;
      TPbasetoP3_0 += a_0[TPbasetoP3_tmp_1 + 3] * theta2;
    }

    TPbasetoP3[theta5_tmp + 3] = TPbasetoP3_0;
    TPbasetoP3[theta5_tmp + 2] = theta5;
    TPbasetoP3[theta5_tmp + 1] = YE;
    TPbasetoP3[theta5_tmp] = XE;
  }

  theta2 = sin(rtb_Sum11);
  rtb_Sum11 = cos(rtb_Sum11);
  for (i_0 = 0; i_0 < 16; i_0++) {
    /* MATLAB Function: '<S1>/inverse kinematics' */
    P2planar_tmp[i_0] = c_a[i_0];
  }

  theta5_0[0] = rtb_Sum11;
  theta5_0[4] = -theta2;
  theta5_0[8] = 0.0;
  theta5_0[12] = 0.0;
  theta5_0[1] = theta2;
  theta5_0[5] = rtb_Sum11;
  theta5_0[9] = 0.0;
  theta5_0[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    theta5_tmp = i_0 << 2;
    theta5_0[theta5_tmp + 2] = TPbasetoP3_tmp[i_0];
    theta5_0[theta5_tmp + 3] = TPbasetoP3_tmp_0[i_0];
    rtb_Sum11 = 0.0;
    XE = 0.0;
    YE = 0.0;
    theta5 = 0.0;
    for (i = 0; i < 4; i++) {
      theta2 = theta5_0[theta5_tmp + i];
      TPbasetoP3_tmp_1 = i << 2;
      rtb_Sum11 += b_a_0[TPbasetoP3_tmp_1] * theta2;
      XE += b_a_0[TPbasetoP3_tmp_1 + 1] * theta2;
      YE += b_a_0[TPbasetoP3_tmp_1 + 2] * theta2;
      theta5 += b_a_0[TPbasetoP3_tmp_1 + 3] * theta2;
    }

    b_a[theta5_tmp + 3] = theta5;
    b_a[theta5_tmp + 2] = YE;
    b_a[theta5_tmp + 1] = XE;
    b_a[theta5_tmp] = rtb_Sum11;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    XE = 0.0;
    YE = 0.0;
    theta5 = 0.0;
    TPbasetoP3_0 = 0.0;
    for (i = 0; i < 4; i++) {
      TPbasetoP3_tmp_1 = (i_0 << 2) + i;
      theta2 = b_a[TPbasetoP3_tmp_1];
      theta5_tmp = i << 2;
      XE += (real_T)P2planar_tmp[theta5_tmp] * theta2;
      YE += (real_T)P2planar_tmp[theta5_tmp + 1] * theta2;
      theta5 += (real_T)P2planar_tmp[theta5_tmp + 2] * theta2;
      TPbasetoP3_0 += (real_T)P2planar_tmp[theta5_tmp + 3] * theta2;
      P2planar[TPbasetoP3_tmp_1] = 0.0;
    }

    theta5_tmp = i_0 << 2;
    theta5_0[theta5_tmp + 3] = TPbasetoP3_0;
    theta5_0[theta5_tmp + 2] = theta5;
    theta5_0[theta5_tmp + 1] = YE;
    theta5_0[theta5_tmp] = XE;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    TPbasetoP3_tmp_2 = i_0 << 2;
    rtb_Sum11 = P2planar[TPbasetoP3_tmp_2];
    XE = P2planar[TPbasetoP3_tmp_2 + 1];
    YE = P2planar[TPbasetoP3_tmp_2 + 2];
    theta5 = P2planar[TPbasetoP3_tmp_2 + 3];
    for (i = 0; i < 4; i++) {
      TPbasetoP3_tmp_1 = TPbasetoP3_tmp_2 + i;
      theta2 = b_b[TPbasetoP3_tmp_1];
      theta5_tmp = i << 2;
      rtb_Sum11 += theta5_0[theta5_tmp] * theta2;
      XE += theta5_0[theta5_tmp + 1] * theta2;
      YE += theta5_0[theta5_tmp + 2] * theta2;
      theta5 += theta5_0[theta5_tmp + 3] * theta2;
      b_a[TPbasetoP3_tmp_1] = 0.0;
    }

    P2planar[TPbasetoP3_tmp_2 + 3] = theta5;
    P2planar[TPbasetoP3_tmp_2 + 2] = YE;
    P2planar[TPbasetoP3_tmp_2 + 1] = XE;
    P2planar[TPbasetoP3_tmp_2] = rtb_Sum11;
    XE = b_a[TPbasetoP3_tmp_2];
    YE = b_a[TPbasetoP3_tmp_2 + 1];
    theta5 = b_a[TPbasetoP3_tmp_2 + 2];
    TPbasetoP3_0 = b_a[TPbasetoP3_tmp_2 + 3];
    for (i = 0; i < 4; i++) {
      TPbasetoP3_tmp_1 = TPbasetoP3_tmp_2 + i;
      theta2 = TPbasetoP3[TPbasetoP3_tmp_1];
      theta5_tmp = i << 2;
      XE += (real_T)P2planar_tmp[theta5_tmp] * theta2;
      YE += (real_T)P2planar_tmp[theta5_tmp + 1] * theta2;
      theta5 += (real_T)P2planar_tmp[theta5_tmp + 2] * theta2;
      TPbasetoP3_0 += (real_T)P2planar_tmp[theta5_tmp + 3] * theta2;
      P4planar[TPbasetoP3_tmp_1] = 0.0;
    }

    b_a[TPbasetoP3_tmp_2 + 3] = TPbasetoP3_0;
    b_a[TPbasetoP3_tmp_2 + 2] = theta5;
    b_a[TPbasetoP3_tmp_2 + 1] = YE;
    b_a[TPbasetoP3_tmp_2] = XE;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    TPbasetoP3_tmp_1 = i_0 << 2;
    rtb_Sum11 = P4planar[TPbasetoP3_tmp_1];
    XE = P4planar[TPbasetoP3_tmp_1 + 1];
    YE = P4planar[TPbasetoP3_tmp_1 + 2];
    theta5 = P4planar[TPbasetoP3_tmp_1 + 3];
    for (i = 0; i < 4; i++) {
      theta2 = c_b[TPbasetoP3_tmp_1 + i];
      theta5_tmp = i << 2;
      rtb_Sum11 += b_a[theta5_tmp] * theta2;
      XE += b_a[theta5_tmp + 1] * theta2;
      YE += b_a[theta5_tmp + 2] * theta2;
      theta5 += b_a[theta5_tmp + 3] * theta2;
    }

    P4planar[TPbasetoP3_tmp_1 + 3] = theta5;
    P4planar[TPbasetoP3_tmp_1 + 2] = YE;
    P4planar[TPbasetoP3_tmp_1 + 1] = XE;
    P4planar[TPbasetoP3_tmp_1] = rtb_Sum11;
  }

  XE = P4planar[12] - P2planar[12];
  YE = P4planar[14] - P2planar[14];
  theta2 = XE * XE;
  TPbasetoP3_0 = YE * YE;
  rtb_Sum11 = (((((((theta2 * 0.15680000000000002 - 0.0038886400000000022) +
                    TPbasetoP3_0 * 0.15680000000000002) - 0.00020735999999999997)
                  + theta2 * 0.0288) + TPbasetoP3_0 * 0.0288) - rt_powd_snf(XE,
    4.0)) - theta2 * 2.0 * TPbasetoP3_0) - rt_powd_snf(YE, 4.0);
  if (rtb_Sum11 > 0.0) {
    theta5 = atan((0.56 * YE + sqrt(rtb_Sum11)) / ((((0.56 * XE +
      0.078400000000000011) - 0.0144) + theta2) + TPbasetoP3_0)) * 2.0;
    rtb_Sum11 = (theta2 - 0.0256) + TPbasetoP3_0;
    XE = atan(sqrt(((0.16 - theta2) - TPbasetoP3_0) * rtb_Sum11) / rtb_Sum11) *
      -2.0;
  } else {
    theta5 = 0.0;
    XE = 0.0;
  }

  theta5 += 3.1415926535897931 - rtb_Sum10;
  theta2 = sin(rtb_Gain15);
  rtb_Sum11 = cos(rtb_Gain15);
  rtb_Gain15 = sin(theta5);
  rtb_Sum10 = cos(theta5);
  theta5 = sin(XE);
  XE = cos(XE);
  YE = sin(rtb_Gain16);
  rtb_Gain16 = cos(rtb_Gain16);
  theta5_0[0] = rtb_Sum11;
  theta5_0[4] = -theta2;
  theta5_0[8] = 0.0;
  theta5_0[12] = 0.0;
  theta5_0[1] = theta2;
  theta5_0[5] = rtb_Sum11;
  theta5_0[9] = 0.0;
  theta5_0[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    theta5_tmp = i_0 << 2;
    theta5_0[theta5_tmp + 2] = TPbasetoP3_tmp[i_0];
    theta5_0[theta5_tmp + 3] = TPbasetoP3_tmp_0[i_0];
    b_a[theta5_tmp] = 0.0;
    b_a[theta5_tmp + 1] = 0.0;
    b_a[theta5_tmp + 2] = 0.0;
    b_a[theta5_tmp + 3] = 0.0;
  }

  P4planar[0] = rtb_Sum10;
  P4planar[4] = -rtb_Gain15;
  P4planar[8] = 0.0;
  P4planar[12] = 0.12;
  P4planar[1] = rtb_Gain15;
  P4planar[5] = rtb_Sum10;
  P4planar[9] = 0.0;
  P4planar[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    TPbasetoP3_tmp_2 = i_0 << 2;
    P4planar[TPbasetoP3_tmp_2 + 2] = TPbasetoP3_tmp[i_0];
    P4planar[TPbasetoP3_tmp_2 + 3] = TPbasetoP3_tmp_0[i_0];
    rtb_Sum11 = b_a[TPbasetoP3_tmp_2];
    rtb_Gain15 = b_a[TPbasetoP3_tmp_2 + 1];
    rtb_Sum10 = b_a[TPbasetoP3_tmp_2 + 2];
    TPbasetoP3_0 = b_a[TPbasetoP3_tmp_2 + 3];
    for (i = 0; i < 4; i++) {
      TPbasetoP3_tmp_1 = TPbasetoP3_tmp_2 + i;
      theta2 = TPbasetoP3[TPbasetoP3_tmp_1];
      theta5_tmp = i << 2;
      rtb_Sum11 += theta5_0[theta5_tmp] * theta2;
      rtb_Gain15 += theta5_0[theta5_tmp + 1] * theta2;
      rtb_Sum10 += theta5_0[theta5_tmp + 2] * theta2;
      TPbasetoP3_0 += theta5_0[theta5_tmp + 3] * theta2;
      P2planar[TPbasetoP3_tmp_1] = 0.0;
    }

    b_a[TPbasetoP3_tmp_2 + 3] = TPbasetoP3_0;
    b_a[TPbasetoP3_tmp_2 + 2] = rtb_Sum10;
    b_a[TPbasetoP3_tmp_2 + 1] = rtb_Gain15;
    b_a[TPbasetoP3_tmp_2] = rtb_Sum11;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    theta5_tmp = i_0 << 2;
    rtb_Sum11 = P2planar[theta5_tmp];
    rtb_Gain15 = P2planar[theta5_tmp + 1];
    rtb_Sum10 = P2planar[theta5_tmp + 2];
    TPbasetoP3_0 = P2planar[theta5_tmp + 3];
    for (i = 0; i < 4; i++) {
      theta2 = P4planar[theta5_tmp + i];
      TPbasetoP3_tmp_1 = i << 2;
      rtb_Sum11 += b_a[TPbasetoP3_tmp_1] * theta2;
      rtb_Gain15 += b_a[TPbasetoP3_tmp_1 + 1] * theta2;
      rtb_Sum10 += b_a[TPbasetoP3_tmp_1 + 2] * theta2;
      TPbasetoP3_0 += b_a[TPbasetoP3_tmp_1 + 3] * theta2;
    }

    P2planar[theta5_tmp + 3] = TPbasetoP3_0;
    P2planar[theta5_tmp + 2] = rtb_Sum10;
    P2planar[theta5_tmp + 1] = rtb_Gain15;
    P2planar[theta5_tmp] = rtb_Sum11;
  }

  TPbasetoP3[0] = XE;
  TPbasetoP3[4] = -theta5;
  TPbasetoP3[8] = 0.0;
  TPbasetoP3[12] = 0.28;
  TPbasetoP3[1] = theta5;
  TPbasetoP3[5] = XE;
  TPbasetoP3[9] = 0.0;
  TPbasetoP3[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    TPbasetoP3_tmp_1 = i_0 << 2;
    TPbasetoP3[TPbasetoP3_tmp_1 + 2] = TPbasetoP3_tmp[i_0];
    TPbasetoP3[TPbasetoP3_tmp_1 + 3] = TPbasetoP3_tmp_0[i_0];
    rtb_Sum11 = 0.0;
    rtb_Gain15 = 0.0;
    rtb_Sum10 = 0.0;
    TPbasetoP3_0 = 0.0;
    for (i = 0; i < 4; i++) {
      theta2 = TPbasetoP3[TPbasetoP3_tmp_1 + i];
      theta5_tmp = i << 2;
      rtb_Sum11 += P2planar[theta5_tmp] * theta2;
      rtb_Gain15 += P2planar[theta5_tmp + 1] * theta2;
      rtb_Sum10 += P2planar[theta5_tmp + 2] * theta2;
      TPbasetoP3_0 += P2planar[theta5_tmp + 3] * theta2;
    }

    theta5_0[TPbasetoP3_tmp_1 + 3] = TPbasetoP3_0;
    theta5_0[TPbasetoP3_tmp_1 + 2] = rtb_Sum10;
    theta5_0[TPbasetoP3_tmp_1 + 1] = rtb_Gain15;
    theta5_0[TPbasetoP3_tmp_1] = rtb_Sum11;
  }

  TPbasetoP3[0] = rtb_Gain16;
  TPbasetoP3[4] = -YE;
  TPbasetoP3[8] = 0.0;
  TPbasetoP3[12] = 0.62;
  TPbasetoP3[1] = YE;
  TPbasetoP3[5] = rtb_Gain16;
  TPbasetoP3[9] = 0.0;
  TPbasetoP3[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    TPbasetoP3_tmp_1 = i_0 << 2;
    TPbasetoP3[TPbasetoP3_tmp_1 + 2] = TPbasetoP3_tmp[i_0];
    TPbasetoP3[TPbasetoP3_tmp_1 + 3] = TPbasetoP3_tmp_0[i_0];
    rtb_Sum11 = 0.0;
    rtb_Gain15 = 0.0;
    rtb_Sum10 = 0.0;
    TPbasetoP3_0 = 0.0;
    for (i = 0; i < 4; i++) {
      theta2 = TPbasetoP3[TPbasetoP3_tmp_1 + i];
      theta5_tmp = i << 2;
      rtb_Sum11 += theta5_0[theta5_tmp] * theta2;
      rtb_Gain15 += theta5_0[theta5_tmp + 1] * theta2;
      rtb_Sum10 += theta5_0[theta5_tmp + 2] * theta2;
      TPbasetoP3_0 += theta5_0[theta5_tmp + 3] * theta2;
    }

    b_a[TPbasetoP3_tmp_1 + 3] = TPbasetoP3_0;
    b_a[TPbasetoP3_tmp_1 + 2] = rtb_Sum10;
    b_a[TPbasetoP3_tmp_1 + 1] = rtb_Gain15;
    b_a[TPbasetoP3_tmp_1] = rtb_Sum11;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Sum11 = 0.0;
    XE = 0.0;
    YE = 0.0;
    theta5 = 0.0;
    for (i = 0; i < 4; i++) {
      theta2 = d_b[(i_0 << 2) + i];
      TPbasetoP3_tmp_2 = i << 2;
      rtb_Sum11 += b_a[TPbasetoP3_tmp_2] * theta2;
      XE += b_a[TPbasetoP3_tmp_2 + 1] * theta2;
      YE += b_a[TPbasetoP3_tmp_2 + 2] * theta2;
      theta5 += b_a[TPbasetoP3_tmp_2 + 3] * theta2;
    }

    TPbasetoP3_tmp_2 = i_0 << 2;
    P2planar[TPbasetoP3_tmp_2 + 3] = theta5;
    P2planar[TPbasetoP3_tmp_2 + 2] = YE;
    P2planar[TPbasetoP3_tmp_2 + 1] = XE;
    P2planar[TPbasetoP3_tmp_2] = rtb_Sum11;
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/x'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  rtb_Gain16 = P2planar[12] - rtU.x;

  /* DotProduct: '<S3>/Dot Product' */
  theta2 = rtb_Gain16 * rtb_Gain16;

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/y'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  rtb_Gain16 = P2planar[13] - rtU.y;

  /* DotProduct: '<S3>/Dot Product' */
  theta2 += rtb_Gain16 * rtb_Gain16;

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
  rtY.pointReached = (sqrt(rtb_Gain16 * rtb_Gain16 + theta2) <= 0.002);

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

  rtb_Gain15 = rtb_Gain16 - 3.1415926535897931;
  if (rtb_Gain16 > 3.1415926535897931) {
    rtb_Gain16 -= 6.2831853071795862;
  }

  rtb_Gain16 = -rtb_Gain16;
  rtb_Sum10 = sin(rtb_Gain15);
  theta5 = cos(rtb_Gain15);
  theta5_0[0] = theta5;
  theta5_0[4] = -rtb_Sum10;
  theta5_0[8] = 0.0;
  theta5_0[12] = rtU.x;
  theta5_0[1] = rtb_Sum10;
  theta5_0[5] = theta5;
  theta5_0[9] = 0.0;
  theta5_0[13] = rtU.y;
  theta5_0[2] = 0.0;
  theta5_0[6] = 0.0;
  theta5_0[10] = 1.0;
  theta5_0[14] = rtU.z;
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
    theta5_tmp = i_0 << 2;
    theta5_0[theta5_tmp + 3] = TPbasetoP3_tmp_3;
    P2planar[theta5_tmp + 2] = TPbasetoP3_tmp[i_0];
    P2planar[theta5_tmp + 3] = TPbasetoP3_tmp_3;
    b_a[theta5_tmp] = 0.0;
    b_a[theta5_tmp + 1] = 0.0;
    b_a[theta5_tmp + 2] = 0.0;
    b_a[theta5_tmp + 3] = 0.0;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    theta5_tmp = i_0 << 2;
    theta5 = b_a[theta5_tmp];
    theta2 = b_a[theta5_tmp + 1];
    rtb_Gain15 = b_a[theta5_tmp + 2];
    rtb_Sum10 = b_a[theta5_tmp + 3];
    for (i = 0; i < 4; i++) {
      TPbasetoP3_tmp_1 = theta5_tmp + i;
      TPbasetoP3_tmp_2 = b_b_0[TPbasetoP3_tmp_1];
      theta5_tmp_0 = i << 2;
      theta5 += theta5_0[theta5_tmp_0] * (real_T)TPbasetoP3_tmp_2;
      theta2 += theta5_0[theta5_tmp_0 + 1] * (real_T)TPbasetoP3_tmp_2;
      rtb_Gain15 += theta5_0[theta5_tmp_0 + 2] * (real_T)TPbasetoP3_tmp_2;
      rtb_Sum10 += theta5_0[theta5_tmp_0 + 3] * (real_T)TPbasetoP3_tmp_2;
      P4planar[TPbasetoP3_tmp_1] = 0.0;
    }

    b_a[theta5_tmp + 3] = rtb_Sum10;
    b_a[theta5_tmp + 2] = rtb_Gain15;
    b_a[theta5_tmp + 1] = theta2;
    b_a[theta5_tmp] = theta5;
    theta2 = P4planar[theta5_tmp];
    TPbasetoP3_0 = P4planar[theta5_tmp + 1];
    rtb_Sum11 = P4planar[theta5_tmp + 2];
    rtb_Gain15 = P4planar[theta5_tmp + 3];
    for (i = 0; i < 4; i++) {
      TPbasetoP3_tmp_1 = theta5_tmp + i;
      rtb_Sum10 = d_b[TPbasetoP3_tmp_1];
      TPbasetoP3_tmp_2 = i << 2;
      theta2 += P2planar[TPbasetoP3_tmp_2] * rtb_Sum10;
      TPbasetoP3_0 += P2planar[TPbasetoP3_tmp_2 + 1] * rtb_Sum10;
      rtb_Sum11 += P2planar[TPbasetoP3_tmp_2 + 2] * rtb_Sum10;
      rtb_Gain15 += P2planar[TPbasetoP3_tmp_2 + 3] * rtb_Sum10;
      TPbasetoP3[TPbasetoP3_tmp_1] = 0.0;
    }

    P4planar[theta5_tmp + 3] = rtb_Gain15;
    P4planar[theta5_tmp + 2] = rtb_Sum11;
    P4planar[theta5_tmp + 1] = TPbasetoP3_0;
    P4planar[theta5_tmp] = theta2;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    TPbasetoP3_tmp_1 = i_0 << 2;
    XE = TPbasetoP3[TPbasetoP3_tmp_1];
    YE = TPbasetoP3[TPbasetoP3_tmp_1 + 1];
    theta5 = TPbasetoP3[TPbasetoP3_tmp_1 + 2];
    TPbasetoP3_0 = TPbasetoP3[TPbasetoP3_tmp_1 + 3];
    for (i = 0; i < 4; i++) {
      theta2 = P4planar[TPbasetoP3_tmp_1 + i];
      TPbasetoP3_tmp_2 = i << 2;
      XE += b_a[TPbasetoP3_tmp_2] * theta2;
      YE += b_a[TPbasetoP3_tmp_2 + 1] * theta2;
      theta5 += b_a[TPbasetoP3_tmp_2 + 2] * theta2;
      TPbasetoP3_0 += b_a[TPbasetoP3_tmp_2 + 3] * theta2;
    }

    TPbasetoP3[TPbasetoP3_tmp_1 + 3] = TPbasetoP3_0;
    TPbasetoP3[TPbasetoP3_tmp_1 + 2] = theta5;
    TPbasetoP3[TPbasetoP3_tmp_1 + 1] = YE;
    TPbasetoP3[TPbasetoP3_tmp_1] = XE;
  }

  rtb_Sum10 = sqrt(TPbasetoP3[12] * TPbasetoP3[12] + TPbasetoP3[13] *
                   TPbasetoP3[13]);
  theta2 = rtb_Sum10 * rtb_Sum10;
  TPbasetoP3_0 = (TPbasetoP3[14] - 0.065) * (TPbasetoP3[14] - 0.065);
  rtb_Sum11 = (((((((theta2 * 0.24499999999999997 + 0.04624375) + TPbasetoP3_0 *
                    0.24499999999999997) - 0.0625) + theta2 * 0.5) +
                 TPbasetoP3_0 * 0.5) - rt_powd_snf(rtb_Sum10, 4.0)) - theta2 *
               2.0 * TPbasetoP3_0) - rt_powd_snf(TPbasetoP3[14] - 0.065, 4.0);
  if (rtb_Sum11 < 0.0) {
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_angles[i_0] = d[i_0];
    }

    /* Outport: '<Root>/error' */
    rtY.error = 1.0;
  } else {
    rtb_Gain15 = atan(((TPbasetoP3[14] - 0.065) * 0.7 + sqrt(rtb_Sum11)) /
                      ((((0.7 * rtb_Sum10 + 0.12249999999999998) - 0.25) +
                        theta2) + TPbasetoP3_0)) * 2.0;
    rtb_Sum10 = (theta2 - 0.02250000000000002) + TPbasetoP3_0;
    theta2 = atan(sqrt(((0.72249999999999992 - theta2) - TPbasetoP3_0) *
                       rtb_Sum10) / rtb_Sum10) * -2.0;
    rtb_Sum11 = (-rtU.gripperAng - rtb_Gain15) - theta2;
    rtb_Sum10 = sin(rtb_Gain15);
    theta5 = cos(rtb_Gain15);
    XE = sin(theta2);
    YE = cos(theta2);
    theta5_0[0] = theta5;
    theta5_0[4] = -rtb_Sum10;
    theta5_0[8] = 0.0;
    theta5_0[12] = 0.0;
    theta5_0[1] = rtb_Sum10;
    theta5_0[5] = theta5;
    theta5_0[9] = 0.0;
    theta5_0[13] = 0.0;
    for (i_0 = 0; i_0 < 4; i_0++) {
      theta5_tmp = i_0 << 2;
      theta5_0[theta5_tmp + 2] = TPbasetoP3_tmp[i_0];
      theta5_0[theta5_tmp + 3] = TPbasetoP3_tmp_0[i_0];
      rtb_Sum10 = 0.0;
      theta5 = 0.0;
      TPbasetoP3_0 = 0.0;
      a = 0.0;
      for (i = 0; i < 4; i++) {
        theta2 = theta5_0[theta5_tmp + i];
        TPbasetoP3_tmp_1 = i << 2;
        rtb_Sum10 += b_a_0[TPbasetoP3_tmp_1] * theta2;
        theta5 += b_a_0[TPbasetoP3_tmp_1 + 1] * theta2;
        TPbasetoP3_0 += b_a_0[TPbasetoP3_tmp_1 + 2] * theta2;
        a += b_a_0[TPbasetoP3_tmp_1 + 3] * theta2;
      }

      TPbasetoP3[theta5_tmp + 3] = a;
      TPbasetoP3[theta5_tmp + 2] = TPbasetoP3_0;
      TPbasetoP3[theta5_tmp + 1] = theta5;
      TPbasetoP3[theta5_tmp] = rtb_Sum10;
    }

    P2planar[0] = YE;
    P2planar[4] = -XE;
    P2planar[8] = 0.0;
    P2planar[12] = 0.35;
    P2planar[1] = XE;
    P2planar[5] = YE;
    P2planar[9] = 0.0;
    P2planar[13] = 0.0;
    for (i_0 = 0; i_0 < 4; i_0++) {
      TPbasetoP3_tmp_2 = i_0 << 2;
      P2planar[TPbasetoP3_tmp_2 + 2] = TPbasetoP3_tmp[i_0];
      P2planar[TPbasetoP3_tmp_2 + 3] = TPbasetoP3_tmp_0[i_0];
      XE = 0.0;
      YE = 0.0;
      theta5 = 0.0;
      TPbasetoP3_0 = 0.0;
      for (i = 0; i < 4; i++) {
        TPbasetoP3_tmp_1 = TPbasetoP3_tmp_2 + i;
        theta2 = TPbasetoP3[TPbasetoP3_tmp_1];
        theta5_tmp = i << 2;
        XE += (real_T)P2planar_tmp[theta5_tmp] * theta2;
        YE += (real_T)P2planar_tmp[theta5_tmp + 1] * theta2;
        theta5 += (real_T)P2planar_tmp[theta5_tmp + 2] * theta2;
        TPbasetoP3_0 += (real_T)P2planar_tmp[theta5_tmp + 3] * theta2;
        b_a[TPbasetoP3_tmp_1] = 0.0;
      }

      theta5_0[TPbasetoP3_tmp_2 + 3] = TPbasetoP3_0;
      theta5_0[TPbasetoP3_tmp_2 + 2] = theta5;
      theta5_0[TPbasetoP3_tmp_2 + 1] = YE;
      theta5_0[TPbasetoP3_tmp_2] = XE;
    }

    for (i_0 = 0; i_0 < 4; i_0++) {
      theta5_tmp = i_0 << 2;
      XE = b_a[theta5_tmp];
      YE = b_a[theta5_tmp + 1];
      theta5 = b_a[theta5_tmp + 2];
      TPbasetoP3_0 = b_a[theta5_tmp + 3];
      for (i = 0; i < 4; i++) {
        theta2 = P2planar[theta5_tmp + i];
        TPbasetoP3_tmp_1 = i << 2;
        XE += theta5_0[TPbasetoP3_tmp_1] * theta2;
        YE += theta5_0[TPbasetoP3_tmp_1 + 1] * theta2;
        theta5 += theta5_0[TPbasetoP3_tmp_1 + 2] * theta2;
        TPbasetoP3_0 += theta5_0[TPbasetoP3_tmp_1 + 3] * theta2;
      }

      b_a[theta5_tmp + 3] = TPbasetoP3_0;
      b_a[theta5_tmp + 2] = theta5;
      b_a[theta5_tmp + 1] = YE;
      b_a[theta5_tmp] = XE;
    }

    for (i_0 = 0; i_0 < 4; i_0++) {
      XE = 0.0;
      YE = 0.0;
      theta5 = 0.0;
      TPbasetoP3_0 = 0.0;
      for (i = 0; i < 4; i++) {
        theta2 = d_b_0[(i_0 << 2) + i];
        TPbasetoP3_tmp_1 = i << 2;
        XE += b_a[TPbasetoP3_tmp_1] * theta2;
        YE += b_a[TPbasetoP3_tmp_1 + 1] * theta2;
        theta5 += b_a[TPbasetoP3_tmp_1 + 2] * theta2;
        TPbasetoP3_0 += b_a[TPbasetoP3_tmp_1 + 3] * theta2;
      }

      TPbasetoP3_tmp_1 = i_0 << 2;
      TPbasetoP3[TPbasetoP3_tmp_1 + 3] = TPbasetoP3_0;
      TPbasetoP3[TPbasetoP3_tmp_1 + 2] = theta5;
      TPbasetoP3[TPbasetoP3_tmp_1 + 1] = YE;
      TPbasetoP3[TPbasetoP3_tmp_1] = XE;
    }

    theta2 = TPbasetoP3[12] * TPbasetoP3[12];
    rtb_Sum10 = (TPbasetoP3[14] - 0.149) * (TPbasetoP3[14] - 0.149);
    rtb_Sum10 = atan((sqrt((((((((theta2 * 0.0288 + 0.00205056) + rtb_Sum10 *
      0.0288) - 0.0061465600000000023) + theta2 * 0.15680000000000002) +
      rtb_Sum10 * 0.15680000000000002) - rt_powd_snf(TPbasetoP3[12], 4.0)) -
      theta2 * 2.0 * rtb_Sum10) - rt_powd_snf(TPbasetoP3[14] - 0.149, 4.0)) +
                      (TPbasetoP3[14] - 0.149) * 0.24) / ((((0.24 * TPbasetoP3
      [12] + 0.0144) - 0.078400000000000011) + theta2) + rtb_Sum10)) * 2.0;
    if ((fabs(rtb_Gain16) > 3.1415926535897931) || ((rtb_Gain15 < 0.0) ||
         (rtb_Gain15 > 2.3561944901923448) || (rtb_Sum11 < -2.3561944901923448) ||
         (rtb_Sum11 > 0.78539816339744828) || (rtb_Sum10 < 1.5707963267948966) ||
         (rtb_Sum10 > 4.71238898038469))) {
      for (i_0 = 0; i_0 < 5; i_0++) {
        rtb_angles[i_0] = d[i_0];
      }

      /* Outport: '<Root>/error' */
      rtY.error = 2.0;
    } else {
      rtb_angles[0] = rtb_Gain16;
      rtb_angles[1] = rtb_Gain15;
      rtb_angles[3] = rtb_Sum11;
      rtb_angles[4] = rtb_Sum10;

      /* Outport: '<Root>/error' */
      rtY.error = 0.0;
    }
  }

  /* Rounding: '<S1>/Round' incorporates:
   *  Constant: '<S1>/Constant5'
   *  Constant: '<S1>/Pi'
   *  Gain: '<S1>/Gain10'
   *  Gain: '<S1>/Gain13'
   *  Product: '<S1>/Divide1'
   *  Sum: '<S1>/Sum7'
   */
  rtb_Gain16 = rt_roundd_snf((rtb_angles[4] + 1.5707963267948966) * 160.0 *
    57.295779513082323 / 1.8);

  /* Outport: '<Root>/stepperLeftSteps' */
  rtY.stepperLeftSteps = rtb_Gain16;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Constant: '<S1>/Time per movement'
   *  Inport: '<Root>/stepperLeftOldPosition'
   */
  MATLABFunction1(rtU.stepperLeftOldPosition, rtb_Gain16, 10.0, &rtb_Sum11);

  /* Outport: '<Root>/stepperLeftFrequency' incorporates:
   *  Constant: '<S1>/One'
   *  Product: '<S1>/Divide'
   */
  rtY.stepperLeftFrequency = 1.0 / rtb_Sum11;

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<S1>/Time per movement'
   *  Gain: '<S1>/Gain12'
   *  Inport: '<Root>/deltaTime'
   *  Inport: '<Root>/gripperPitchOldPosition'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  MATLABFunction(rtDW.UnitDelay2_DSTATE, rtU.gripperPitchOldPosition, 21.0 *
                 rtb_angles[3], 10.0, rtU.deltaTime, &rtb_Gain16);

  /* Sum: '<S1>/Sum4' incorporates:
   *  Inport: '<Root>/gripperPitchActualPosition'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  rtb_Gain15 = rtDW.UnitDelay2_DSTATE - rtU.actualposition_p;

  /* MATLAB Function: '<S1>/MATLAB Function5' incorporates:
   *  Constant: '<S1>/Time per movement'
   *  Gain: '<S1>/Gain6'
   *  Inport: '<Root>/baseOldPosition'
   *  Inport: '<Root>/deltaTime'
   *  UnitDelay: '<S1>/Unit Delay5'
   */
  MATLABFunction(rtDW.UnitDelay5_DSTATE, rtU.baseOldPosition, 63.0 * rtb_angles
                 [0], 10.0, rtU.deltaTime, &rtb_Sum10);

  /* Sum: '<S1>/Sum2' incorporates:
   *  Inport: '<Root>/baseActualPosition'
   *  UnitDelay: '<S1>/Unit Delay5'
   */
  theta5 = rtDW.UnitDelay5_DSTATE - rtU.actualposition_e;

  /* Update for UnitDelay: '<S1>/Unit Delay1' incorporates:
   *  DiscreteIntegrator: '<S50>/Integrator'
   *  Sum: '<S59>/Sum'
   */
  rtDW.UnitDelay1_DSTATE = theta5 + rtDW.Integrator_DSTATE_o;

  /* Product: '<S63>/Uintegral*Ts Prod Out' incorporates:
   *  Inport: '<Root>/deltaTime'
   */
  theta2 = theta5 * rtU.deltaTime;

  /* Rounding: '<S1>/Round1' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Pi1'
   *  Gain: '<S1>/Gain11'
   *  Gain: '<S1>/Gain8'
   *  Product: '<S1>/Divide2'
   *  Sum: '<S1>/Sum9'
   */
  rtb_Sum11 = rt_roundd_snf((rtb_angles[1] + 1.5707963267948966) * 160.0 *
    57.295779513082323 / 1.8);

  /* MATLAB Function: '<S1>/MATLAB Function6' incorporates:
   *  Constant: '<S1>/Time per movement'
   *  Inport: '<Root>/stepperRightOldPosition'
   */
  MATLABFunction1(rtU.stepperRightOldPosition, rtb_Sum11, 10.0, &theta5);

  /* Outport: '<Root>/stepperRightFrequency' incorporates:
   *  Constant: '<S1>/One1'
   *  Product: '<S1>/Divide3'
   */
  rtY.stepperRightFrequency = 1.0 / theta5;

  /* Outport: '<Root>/stepperRightSteps' */
  rtY.stepperRightSteps = rtb_Sum11;

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain5'
   *  Gain: '<S1>/Gain9'
   *  Inport: '<Root>/deltaTime'
   *  Inport: '<Root>/gripperRotationDesiredPosition'
   *  UnitDelay: '<S1>/Unit Delay7'
   */
  MATLABFunction2(rtDW.UnitDelay7_DSTATE, 21.0 * (0.017453292519943295 *
    rtU.gripperRotationDesiredPosition), 21.0 * rtU.deltaTime, &rtb_Sum11);

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Gain3'
   *  Gain: '<S1>/Gain7'
   *  Inport: '<Root>/deltaTime'
   *  Inport: '<Root>/jawDesiredPosition'
   *  UnitDelay: '<S1>/Unit Delay9'
   */
  MATLABFunction2(rtDW.UnitDelay9_DSTATE, 21.0 * (0.017453292519943295 *
    rtU.jawDesiredPosition), 2.1 * rtU.deltaTime, &XE);

  /* Sum: '<S1>/Sum6' incorporates:
   *  Inport: '<Root>/jawActualPosition'
   *  UnitDelay: '<S1>/Unit Delay9'
   */
  YE = rtDW.UnitDelay9_DSTATE - rtU.actualposition;

  /* Update for UnitDelay: '<S1>/Unit Delay8' incorporates:
   *  DiscreteIntegrator: '<S206>/Integrator'
   *  Gain: '<S211>/Proportional Gain'
   *  Sum: '<S215>/Sum'
   */
  rtDW.UnitDelay8_DSTATE = 2.0 * YE + rtDW.Integrator_DSTATE_h;

  /* Gain: '<S159>/Proportional Gain' incorporates:
   *  Gain: '<S151>/Integral Gain'
   *  Inport: '<Root>/gripperRotationActualPosition'
   *  Sum: '<S1>/Sum5'
   *  UnitDelay: '<S1>/Unit Delay7'
   */
  theta5 = (rtDW.UnitDelay7_DSTATE - rtU.actualposition_l) * 0.2;

  /* Update for UnitDelay: '<S1>/Unit Delay6' incorporates:
   *  DiscreteIntegrator: '<S154>/Integrator'
   *  Gain: '<S159>/Proportional Gain'
   *  Sum: '<S163>/Sum'
   */
  rtDW.UnitDelay6_DSTATE = theta5 + rtDW.Integrator_DSTATE_e;

  /* Update for UnitDelay: '<S1>/Unit Delay4' incorporates:
   *  DiscreteIntegrator: '<S102>/Integrator'
   *  Gain: '<S107>/Proportional Gain'
   *  Sum: '<S111>/Sum'
   */
  rtDW.UnitDelay4_DSTATE = 0.5 * rtb_Gain15 + rtDW.Integrator_DSTATE;

  /* Update for UnitDelay: '<S1>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE = rtb_Gain16;

  /* Update for DiscreteIntegrator: '<S102>/Integrator' incorporates:
   *  Gain: '<S99>/Integral Gain'
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S115>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE += 0.1 * rtb_Gain15 * rtU.deltaTime;

  /* Update for UnitDelay: '<S1>/Unit Delay5' */
  rtDW.UnitDelay5_DSTATE = rtb_Sum10;

  /* Update for DiscreteIntegrator: '<S50>/Integrator' */
  rtDW.Integrator_DSTATE_o += theta2;

  /* Update for UnitDelay: '<S1>/Unit Delay7' */
  rtDW.UnitDelay7_DSTATE = rtb_Sum11;

  /* Update for DiscreteIntegrator: '<S154>/Integrator' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S167>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE_e += theta5 * rtU.deltaTime;

  /* Update for UnitDelay: '<S1>/Unit Delay9' */
  rtDW.UnitDelay9_DSTATE = XE;

  /* Update for DiscreteIntegrator: '<S206>/Integrator' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S219>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE_h += YE * rtU.deltaTime;
}

/* Model initialize function */
void control_arm_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
