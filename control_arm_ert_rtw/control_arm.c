/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_arm.c
 *
 * Code generated for Simulink model 'control_arm'.
 *
 * Model version                  : 1.37
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon May 25 16:16:53 2026
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
  if (fabs(rtu_current - rtu_desired) < 0.01) {
    *rty_out = rtu_desired;
  } else {
    real_T velocity;
    velocity = fabs(rtu_desired - rtu_startPosition) / rtu_timePerMovement;
    if (rtu_current < rtu_desired) {
      *rty_out = velocity * rtu_deltaTime + rtu_current;
    } else if (rtu_current > rtu_desired) {
      *rty_out = rtu_current - velocity * rtu_deltaTime;
    } else {
      *rty_out = rtu_current;
    }
  }
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
  real_T P6i[16];
  real_T b_a[16];
  real_T rtb_Gain15_0[16];
  real_T rtb_angles[5];
  real_T XE;
  real_T XEi;
  real_T YE;
  real_T angToBase;
  real_T rtb_Gain15;
  real_T rtb_Gain15_1;
  real_T rtb_Sum11;
  real_T rtb_Sum6;
  real_T theta0;
  real_T theta2;
  real_T theta5;
  int16_T P6i_tmp_1;
  int16_T P6i_tmp_2;
  int16_T i;
  int16_T i_0;
  int16_T rtb_Gain15_tmp;
  int16_T rtb_Gain15_tmp_0;
  int8_T P2planar_tmp[16];
  int8_T P6i_tmp[4];
  int8_T P6i_tmp_0[4];
  static const int8_T b[4] = { 0, 0, 0, 1 };

  static const int8_T c[4] = { 0, 0, 1, 0 };

  static const int8_T b_b[16] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0,
    1 };

  static const real_T d[5] = { 0.0, 1.5707963267948966, 0.0, -1.5707963267948966,
    3.1415926535897931 };

  static const real_T c_b[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.335, 0.0, 0.0, 1.0 };

  static const real_T a[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.065, 1.0 };

  static const int8_T c_a[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  static const real_T d_b[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, -0.12, 0.0, 0.0, 1.0 };

  static const real_T a_0[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.149, 1.0 };

  static const real_T b_b_0[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.35, 0.0, 0.0, 1.0 };

  static const real_T c_b_0[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.12, 0.0, 0.0, 1.0 };

  static const real_T d_b_0[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.3, 0.0, 0.0, 1.0 };

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
  rtb_Gain15 = cos(angToBase);
  P2planar[0] = rtb_Gain15;
  P2planar[4] = -XEi;
  P2planar[8] = 0.0;
  P2planar[12] = rtU.x;
  P2planar[1] = XEi;
  P2planar[5] = rtb_Gain15;
  P2planar[9] = 0.0;
  P2planar[13] = rtU.y;
  P2planar[2] = 0.0;
  P2planar[6] = 0.0;
  P2planar[10] = 1.0;
  P2planar[14] = rtU.z;
  b_a[0] = cos(rtU.gripperAng);
  b_a[4] = -sin(rtU.gripperAng);
  b_a[8] = 0.0;
  b_a[12] = 0.0;
  b_a[1] = sin(rtU.gripperAng);
  b_a[5] = cos(rtU.gripperAng);
  b_a[9] = 0.0;
  b_a[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    /* MATLAB Function: '<S1>/MATLAB Function4' */
    P6i_tmp_1 = b[i_0];
    P6i_tmp[i_0] = (int8_T)P6i_tmp_1;

    /* MATLAB Function: '<S1>/MATLAB Function4' */
    P6i_tmp_2 = c[i_0];
    P6i_tmp_0[i_0] = (int8_T)P6i_tmp_2;
    rtb_Gain15_tmp = i_0 << 2;
    P2planar[rtb_Gain15_tmp + 3] = P6i_tmp_1;
    b_a[rtb_Gain15_tmp + 2] = P6i_tmp_2;
    b_a[rtb_Gain15_tmp + 3] = P6i_tmp_1;
    rtb_Gain15_0[rtb_Gain15_tmp] = 0.0;
    rtb_Gain15_0[rtb_Gain15_tmp + 1] = 0.0;
    rtb_Gain15_0[rtb_Gain15_tmp + 2] = 0.0;
    rtb_Gain15_0[rtb_Gain15_tmp + 3] = 0.0;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Gain15_tmp = i_0 << 2;
    rtb_Gain15 = rtb_Gain15_0[rtb_Gain15_tmp];
    rtb_Gain15_1 = rtb_Gain15_0[rtb_Gain15_tmp + 1];
    angToBase = rtb_Gain15_0[rtb_Gain15_tmp + 2];
    XEi = rtb_Gain15_0[rtb_Gain15_tmp + 3];
    for (i = 0; i < 4; i++) {
      P6i_tmp_1 = rtb_Gain15_tmp + i;
      P6i_tmp_2 = b_b[P6i_tmp_1];
      rtb_Gain15_tmp_0 = i << 2;
      rtb_Gain15 += P2planar[rtb_Gain15_tmp_0] * (real_T)P6i_tmp_2;
      rtb_Gain15_1 += P2planar[rtb_Gain15_tmp_0 + 1] * (real_T)P6i_tmp_2;
      angToBase += P2planar[rtb_Gain15_tmp_0 + 2] * (real_T)P6i_tmp_2;
      XEi += P2planar[rtb_Gain15_tmp_0 + 3] * (real_T)P6i_tmp_2;
      P4planar[P6i_tmp_1] = 0.0;
    }

    rtb_Gain15_0[rtb_Gain15_tmp + 3] = XEi;
    rtb_Gain15_0[rtb_Gain15_tmp + 2] = angToBase;
    rtb_Gain15_0[rtb_Gain15_tmp + 1] = rtb_Gain15_1;
    rtb_Gain15_0[rtb_Gain15_tmp] = rtb_Gain15;
    rtb_Gain15_1 = P4planar[rtb_Gain15_tmp];
    rtb_Sum11 = P4planar[rtb_Gain15_tmp + 1];
    rtb_Sum6 = P4planar[rtb_Gain15_tmp + 2];
    angToBase = P4planar[rtb_Gain15_tmp + 3];
    for (i = 0; i < 4; i++) {
      P6i_tmp_1 = rtb_Gain15_tmp + i;
      XEi = c_b[P6i_tmp_1];
      P6i_tmp_2 = i << 2;
      rtb_Gain15_1 += b_a[P6i_tmp_2] * XEi;
      rtb_Sum11 += b_a[P6i_tmp_2 + 1] * XEi;
      rtb_Sum6 += b_a[P6i_tmp_2 + 2] * XEi;
      angToBase += b_a[P6i_tmp_2 + 3] * XEi;
      P6i[P6i_tmp_1] = 0.0;
    }

    P4planar[rtb_Gain15_tmp + 3] = angToBase;
    P4planar[rtb_Gain15_tmp + 2] = rtb_Sum6;
    P4planar[rtb_Gain15_tmp + 1] = rtb_Sum11;
    P4planar[rtb_Gain15_tmp] = rtb_Gain15_1;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    P6i_tmp_1 = i_0 << 2;
    rtb_Sum6 = P6i[P6i_tmp_1];
    theta5 = P6i[P6i_tmp_1 + 1];
    XE = P6i[P6i_tmp_1 + 2];
    YE = P6i[P6i_tmp_1 + 3];
    for (i = 0; i < 4; i++) {
      rtb_Gain15_1 = P4planar[P6i_tmp_1 + i];
      P6i_tmp_2 = i << 2;
      rtb_Sum6 += rtb_Gain15_0[P6i_tmp_2] * rtb_Gain15_1;
      theta5 += rtb_Gain15_0[P6i_tmp_2 + 1] * rtb_Gain15_1;
      XE += rtb_Gain15_0[P6i_tmp_2 + 2] * rtb_Gain15_1;
      YE += rtb_Gain15_0[P6i_tmp_2 + 3] * rtb_Gain15_1;
    }

    P6i[P6i_tmp_1 + 3] = YE;
    P6i[P6i_tmp_1 + 2] = XE;
    P6i[P6i_tmp_1 + 1] = theta5;
    P6i[P6i_tmp_1] = rtb_Sum6;
  }

  XEi = sqrt(P6i[12] * P6i[12] + P6i[13] * P6i[13]);
  rtb_Gain15_1 = XEi * XEi;
  rtb_Sum11 = (P6i[14] - 0.065) * (P6i[14] - 0.065);
  rtb_Sum6 = (((((((rtb_Gain15_1 * 0.24499999999999997 + 0.04624375) + rtb_Sum11
                   * 0.24499999999999997) - 0.0625) + rtb_Gain15_1 * 0.5) +
                rtb_Sum11 * 0.5) - rt_powd_snf(XEi, 4.0)) - rtb_Gain15_1 * 2.0 *
              rtb_Sum11) - rt_powd_snf(P6i[14] - 0.065, 4.0);
  if (rtb_Sum6 < 0.0) {
    for (i_0 = 0; i_0 < 5; i_0++) {
      rtb_angles[i_0] = d[i_0];
    }

    /* Outport: '<Root>/error' */
    rtY.error = 1.0;
  } else {
    angToBase = atan(((P6i[14] - 0.065) * 0.7 + sqrt(rtb_Sum6)) / ((((0.7 * XEi
      + 0.12249999999999998) - 0.25) + rtb_Gain15_1) + rtb_Sum11)) * 2.0;
    XEi = (rtb_Gain15_1 - 0.02250000000000002) + rtb_Sum11;
    theta2 = atan(sqrt(((0.72249999999999992 - rtb_Gain15_1) - rtb_Sum11) * XEi)
                  / XEi) * -2.0;
    XEi = sin(angToBase);
    rtb_Gain15 = cos(angToBase);
    rtb_Sum6 = sin(theta2);
    rtb_Sum11 = cos(theta2);
    P2planar[0] = rtb_Gain15;
    P2planar[4] = -XEi;
    P2planar[8] = 0.0;
    P2planar[12] = 0.0;
    P2planar[1] = XEi;
    P2planar[5] = rtb_Gain15;
    P2planar[9] = 0.0;
    P2planar[13] = 0.0;
    for (i_0 = 0; i_0 < 4; i_0++) {
      rtb_Gain15_tmp = i_0 << 2;
      P2planar[rtb_Gain15_tmp + 2] = P6i_tmp_0[i_0];
      P2planar[rtb_Gain15_tmp + 3] = P6i_tmp[i_0];
      XEi = 0.0;
      rtb_Gain15 = 0.0;
      theta5 = 0.0;
      XE = 0.0;
      for (i = 0; i < 4; i++) {
        rtb_Gain15_1 = P2planar[rtb_Gain15_tmp + i];
        P6i_tmp_1 = i << 2;
        XEi += a[P6i_tmp_1] * rtb_Gain15_1;
        rtb_Gain15 += a[P6i_tmp_1 + 1] * rtb_Gain15_1;
        theta5 += a[P6i_tmp_1 + 2] * rtb_Gain15_1;
        XE += a[P6i_tmp_1 + 3] * rtb_Gain15_1;
      }

      P6i[rtb_Gain15_tmp + 3] = XE;
      P6i[rtb_Gain15_tmp + 2] = theta5;
      P6i[rtb_Gain15_tmp + 1] = rtb_Gain15;
      P6i[rtb_Gain15_tmp] = XEi;
    }

    P2planar[0] = rtb_Sum11;
    P2planar[4] = -rtb_Sum6;
    P2planar[8] = 0.0;
    P2planar[12] = 0.35;
    P2planar[1] = rtb_Sum6;
    P2planar[5] = rtb_Sum11;
    P2planar[9] = 0.0;
    P2planar[13] = 0.0;
    for (i_0 = 0; i_0 < 4; i_0++) {
      rtb_Gain15_tmp = i_0 << 2;
      P2planar[rtb_Gain15_tmp + 2] = P6i_tmp_0[i_0];
      P2planar[rtb_Gain15_tmp + 3] = P6i_tmp[i_0];
      rtb_Sum11 = 0.0;
      rtb_Sum6 = 0.0;
      theta5 = 0.0;
      XE = 0.0;
      for (i = 0; i < 4; i++) {
        P6i_tmp_1 = rtb_Gain15_tmp + i;
        rtb_Gain15_1 = P6i[P6i_tmp_1];
        P6i_tmp_2 = i << 2;
        rtb_Sum11 += (real_T)c_a[P6i_tmp_2] * rtb_Gain15_1;
        rtb_Sum6 += (real_T)c_a[P6i_tmp_2 + 1] * rtb_Gain15_1;
        theta5 += (real_T)c_a[P6i_tmp_2 + 2] * rtb_Gain15_1;
        XE += (real_T)c_a[P6i_tmp_2 + 3] * rtb_Gain15_1;
        rtb_Gain15_0[P6i_tmp_1] = 0.0;
      }

      b_a[rtb_Gain15_tmp + 3] = XE;
      b_a[rtb_Gain15_tmp + 2] = theta5;
      b_a[rtb_Gain15_tmp + 1] = rtb_Sum6;
      b_a[rtb_Gain15_tmp] = rtb_Sum11;
    }

    for (i_0 = 0; i_0 < 4; i_0++) {
      P6i_tmp_2 = i_0 << 2;
      rtb_Sum11 = rtb_Gain15_0[P6i_tmp_2];
      rtb_Sum6 = rtb_Gain15_0[P6i_tmp_2 + 1];
      theta5 = rtb_Gain15_0[P6i_tmp_2 + 2];
      XE = rtb_Gain15_0[P6i_tmp_2 + 3];
      for (i = 0; i < 4; i++) {
        rtb_Gain15_1 = P2planar[P6i_tmp_2 + i];
        P6i_tmp_1 = i << 2;
        rtb_Sum11 += b_a[P6i_tmp_1] * rtb_Gain15_1;
        rtb_Sum6 += b_a[P6i_tmp_1 + 1] * rtb_Gain15_1;
        theta5 += b_a[P6i_tmp_1 + 2] * rtb_Gain15_1;
        XE += b_a[P6i_tmp_1 + 3] * rtb_Gain15_1;
      }

      rtb_Gain15_0[P6i_tmp_2 + 3] = XE;
      rtb_Gain15_0[P6i_tmp_2 + 2] = theta5;
      rtb_Gain15_0[P6i_tmp_2 + 1] = rtb_Sum6;
      rtb_Gain15_0[P6i_tmp_2] = rtb_Sum11;
    }

    for (i_0 = 0; i_0 < 4; i_0++) {
      rtb_Sum6 = 0.0;
      theta5 = 0.0;
      XE = 0.0;
      YE = 0.0;
      for (i = 0; i < 4; i++) {
        rtb_Gain15_1 = d_b[(i_0 << 2) + i];
        P6i_tmp_1 = i << 2;
        rtb_Sum6 += rtb_Gain15_0[P6i_tmp_1] * rtb_Gain15_1;
        theta5 += rtb_Gain15_0[P6i_tmp_1 + 1] * rtb_Gain15_1;
        XE += rtb_Gain15_0[P6i_tmp_1 + 2] * rtb_Gain15_1;
        YE += rtb_Gain15_0[P6i_tmp_1 + 3] * rtb_Gain15_1;
      }

      P6i_tmp_1 = i_0 << 2;
      P6i[P6i_tmp_1 + 3] = YE;
      P6i[P6i_tmp_1 + 2] = XE;
      P6i[P6i_tmp_1 + 1] = theta5;
      P6i[P6i_tmp_1] = rtb_Sum6;
    }

    rtb_angles[0] = theta0;
    rtb_angles[1] = angToBase;
    rtb_angles[3] = (-rtU.gripperAng - angToBase) - theta2;
    theta0 = P6i[12] * P6i[12];
    rtb_Gain15_1 = (P6i[14] - 0.149) * (P6i[14] - 0.149);
    rtb_angles[4] = atan((sqrt((((((((theta0 * 0.0288 + 0.00205056) +
      rtb_Gain15_1 * 0.0288) - 0.0061465600000000023) + theta0 *
      0.15680000000000002) + rtb_Gain15_1 * 0.15680000000000002) - rt_powd_snf
      (P6i[12], 4.0)) - theta0 * 2.0 * rtb_Gain15_1) - rt_powd_snf(P6i[14] -
      0.149, 4.0)) + (P6i[14] - 0.149) * 0.24) / ((((0.24 * P6i[12] + 0.0144) -
      0.078400000000000011) + theta0) + rtb_Gain15_1)) * 2.0 +
      6.2831853071795862;

    /* Outport: '<Root>/error' */
    rtY.error = 0.0;
  }

  /* End of MATLAB Function: '<S1>/inverse kinematics' */

  /* Rounding: '<S1>/Round' incorporates:
   *  Constant: '<S1>/Pi'
   *  Gain: '<S1>/Gain10'
   *  Gain: '<S1>/Gain13'
   *  Gain: '<S1>/Gain20'
   *  Sum: '<S1>/Sum7'
   */
  theta0 = rt_roundd_snf((rtb_angles[4] + 1.5707963267948966) * 160.0 *
    57.295779513082323 * 0.55555555555555558);

  /* Outport: '<Root>/stepperLeftSteps' */
  rtY.stepperLeftSteps = theta0;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Inport: '<Root>/stepperLeftOldPosition'
   *  Inport: '<Root>/timePerMovement'
   *  Outport: '<Root>/stepperLeftFrequency'
   */
  MATLABFunction1(rtU.stepperLeftOldPosition, theta0, rtU.timePerMovement,
                  &rtY.stepperLeftFrequency);

  /* Rounding: '<S1>/Round1' incorporates:
   *  Constant: '<S1>/Pi1'
   *  Gain: '<S1>/Gain11'
   *  Gain: '<S1>/Gain21'
   *  Gain: '<S1>/Gain8'
   *  Sum: '<S1>/Sum9'
   */
  theta0 = rt_roundd_snf((rtb_angles[1] + 1.5707963267948966) * 160.0 *
    57.295779513082323 * 0.55555555555555558);

  /* Outport: '<Root>/stepperRightSteps' */
  rtY.stepperRightSteps = theta0;

  /* MATLAB Function: '<S1>/MATLAB Function6' incorporates:
   *  Inport: '<Root>/stepperRightOldPosition'
   *  Inport: '<Root>/timePerMovement'
   *  Outport: '<Root>/stepperRightFrequency'
   */
  MATLABFunction1(rtU.stepperRightOldPosition, theta0, rtU.timePerMovement,
                  &rtY.stepperRightFrequency);

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Gain: '<S1>/Gain12'
   *  Gain: '<S1>/Gain25'
   *  Inport: '<Root>/deltaTime'
   *  Inport: '<Root>/gripperPitchOldPosition'
   *  Inport: '<Root>/timePerMovement'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  MATLABFunction(rtDW.UnitDelay2_DSTATE, rtU.gripperPitchOldPosition, 0.1 *
                 (57.295779513082323 * rtb_angles[3]), rtU.timePerMovement,
                 rtU.deltaTime, &theta0);

  /* Outport: '<Root>/controlGripperPitch' incorporates:
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  rtY.controlGripperPitch = rtDW.UnitDelay2_DSTATE;

  /* MATLAB Function: '<S1>/MATLAB Function5' incorporates:
   *  Gain: '<S1>/Gain23'
   *  Gain: '<S1>/Gain24'
   *  Gain: '<S1>/Gain6'
   *  Inport: '<Root>/baseOldPosition'
   *  Inport: '<Root>/deltaTime'
   *  Inport: '<Root>/timePerMovement'
   *  UnitDelay: '<S1>/Unit Delay5'
   */
  MATLABFunction(rtDW.UnitDelay5_DSTATE, rtU.baseOldPosition, 0.1 *
                 (57.295779513082323 * (63.0 * rtb_angles[0])),
                 rtU.timePerMovement, rtU.deltaTime, &XEi);

  /* Outport: '<Root>/controlBase' incorporates:
   *  UnitDelay: '<S1>/Unit Delay5'
   */
  rtY.controlBase = rtDW.UnitDelay5_DSTATE;

  /* Gain: '<S1>/Gain15' incorporates:
   *  Inport: '<Root>/baseActualPosition'
   */
  rtb_Gain15 = -0.015873015873015872 * rtU.baseActualPosition;

  /* Sum: '<S1>/Sum11' incorporates:
   *  Constant: '<S1>/Pi2'
   *  Gain: '<S1>/Gain14'
   *  Gain: '<S1>/Gain17'
   *  Gain: '<S1>/Gain27'
   *  Gain: '<S1>/Gain4'
   *  Inport: '<Root>/stepperRightActualPosition'
   */
  rtb_Sum11 = 0.00625 * rtU.stepperRightActualPosition * 1.8 *
    0.017453292519943295 * 0.00625 - 1.5707963267948966;

  /* Gain: '<S1>/Gain16' incorporates:
   *  Gain: '<S1>/Gain22'
   *  Inport: '<Root>/gripperPitchActualPosition'
   */
  angToBase = 0.017453292519943295 * rtU.gripperPitchActualPosition *
    0.047619047619047616;

  /* Sum: '<S1>/Sum10' incorporates:
   *  Constant: '<S1>/Pi2'
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Gain18'
   *  Gain: '<S1>/Gain19'
   *  Gain: '<S1>/Gain26'
   *  Inport: '<Root>/stepperLeftActualPosition'
   */
  theta2 = 0.00625 * rtU.stepperLeftActualPosition * 1.8 * 0.017453292519943295 *
    0.00625 - 1.5707963267948966;

  /* MATLAB Function: '<S1>/MATLAB Function4' */
  rtb_Sum6 = sin(theta2);
  theta5 = cos(theta2);
  P2planar[0] = theta5;
  P2planar[4] = -rtb_Sum6;
  P2planar[8] = 0.0;
  P2planar[12] = 0.0;
  P2planar[1] = rtb_Sum6;
  P2planar[5] = theta5;
  P2planar[9] = 0.0;
  P2planar[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Gain15_tmp = i_0 << 2;
    P2planar[rtb_Gain15_tmp + 2] = P6i_tmp_0[i_0];
    P2planar[rtb_Gain15_tmp + 3] = P6i_tmp[i_0];
    rtb_Sum6 = 0.0;
    theta5 = 0.0;
    XE = 0.0;
    YE = 0.0;
    for (i = 0; i < 4; i++) {
      rtb_Gain15_1 = P2planar[rtb_Gain15_tmp + i];
      P6i_tmp_1 = i << 2;
      rtb_Sum6 += a_0[P6i_tmp_1] * rtb_Gain15_1;
      theta5 += a_0[P6i_tmp_1 + 1] * rtb_Gain15_1;
      XE += a_0[P6i_tmp_1 + 2] * rtb_Gain15_1;
      YE += a_0[P6i_tmp_1 + 3] * rtb_Gain15_1;
    }

    P6i[rtb_Gain15_tmp + 3] = YE;
    P6i[rtb_Gain15_tmp + 2] = XE;
    P6i[rtb_Gain15_tmp + 1] = theta5;
    P6i[rtb_Gain15_tmp] = rtb_Sum6;
  }

  rtb_Sum6 = sin(rtb_Sum11);
  rtb_Sum11 = cos(rtb_Sum11);
  for (i_0 = 0; i_0 < 16; i_0++) {
    P2planar_tmp[i_0] = c_a[i_0];
  }

  P2planar[0] = rtb_Sum11;
  P2planar[4] = -rtb_Sum6;
  P2planar[8] = 0.0;
  P2planar[12] = 0.0;
  P2planar[1] = rtb_Sum6;
  P2planar[5] = rtb_Sum11;
  P2planar[9] = 0.0;
  P2planar[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Gain15_tmp = i_0 << 2;
    P2planar[rtb_Gain15_tmp + 2] = P6i_tmp_0[i_0];
    P2planar[rtb_Gain15_tmp + 3] = P6i_tmp[i_0];
    rtb_Sum11 = 0.0;
    rtb_Sum6 = 0.0;
    theta5 = 0.0;
    XE = 0.0;
    for (i = 0; i < 4; i++) {
      rtb_Gain15_1 = P2planar[rtb_Gain15_tmp + i];
      P6i_tmp_2 = i << 2;
      rtb_Sum11 += a[P6i_tmp_2] * rtb_Gain15_1;
      rtb_Sum6 += a[P6i_tmp_2 + 1] * rtb_Gain15_1;
      theta5 += a[P6i_tmp_2 + 2] * rtb_Gain15_1;
      XE += a[P6i_tmp_2 + 3] * rtb_Gain15_1;
    }

    b_a[rtb_Gain15_tmp + 3] = XE;
    b_a[rtb_Gain15_tmp + 2] = theta5;
    b_a[rtb_Gain15_tmp + 1] = rtb_Sum6;
    b_a[rtb_Gain15_tmp] = rtb_Sum11;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Sum11 = 0.0;
    rtb_Sum6 = 0.0;
    theta5 = 0.0;
    XE = 0.0;
    for (i = 0; i < 4; i++) {
      P6i_tmp_1 = (i_0 << 2) + i;
      rtb_Gain15_1 = b_a[P6i_tmp_1];
      P6i_tmp_2 = i << 2;
      rtb_Sum11 += (real_T)P2planar_tmp[P6i_tmp_2] * rtb_Gain15_1;
      rtb_Sum6 += (real_T)P2planar_tmp[P6i_tmp_2 + 1] * rtb_Gain15_1;
      theta5 += (real_T)P2planar_tmp[P6i_tmp_2 + 2] * rtb_Gain15_1;
      XE += (real_T)P2planar_tmp[P6i_tmp_2 + 3] * rtb_Gain15_1;
      P2planar[P6i_tmp_1] = 0.0;
    }

    P6i_tmp_2 = i_0 << 2;
    rtb_Gain15_0[P6i_tmp_2 + 3] = XE;
    rtb_Gain15_0[P6i_tmp_2 + 2] = theta5;
    rtb_Gain15_0[P6i_tmp_2 + 1] = rtb_Sum6;
    rtb_Gain15_0[P6i_tmp_2] = rtb_Sum11;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Gain15_tmp = i_0 << 2;
    rtb_Sum11 = P2planar[rtb_Gain15_tmp];
    rtb_Sum6 = P2planar[rtb_Gain15_tmp + 1];
    theta5 = P2planar[rtb_Gain15_tmp + 2];
    XE = P2planar[rtb_Gain15_tmp + 3];
    for (i = 0; i < 4; i++) {
      P6i_tmp_1 = rtb_Gain15_tmp + i;
      rtb_Gain15_1 = b_b_0[P6i_tmp_1];
      P6i_tmp_2 = i << 2;
      rtb_Sum11 += rtb_Gain15_0[P6i_tmp_2] * rtb_Gain15_1;
      rtb_Sum6 += rtb_Gain15_0[P6i_tmp_2 + 1] * rtb_Gain15_1;
      theta5 += rtb_Gain15_0[P6i_tmp_2 + 2] * rtb_Gain15_1;
      XE += rtb_Gain15_0[P6i_tmp_2 + 3] * rtb_Gain15_1;
      b_a[P6i_tmp_1] = 0.0;
    }

    P2planar[rtb_Gain15_tmp + 3] = XE;
    P2planar[rtb_Gain15_tmp + 2] = theta5;
    P2planar[rtb_Gain15_tmp + 1] = rtb_Sum6;
    P2planar[rtb_Gain15_tmp] = rtb_Sum11;
    rtb_Sum11 = b_a[rtb_Gain15_tmp];
    rtb_Sum6 = b_a[rtb_Gain15_tmp + 1];
    theta5 = b_a[rtb_Gain15_tmp + 2];
    XE = b_a[rtb_Gain15_tmp + 3];
    for (i = 0; i < 4; i++) {
      P6i_tmp_1 = rtb_Gain15_tmp + i;
      rtb_Gain15_1 = P6i[P6i_tmp_1];
      P6i_tmp_2 = i << 2;
      rtb_Sum11 += (real_T)P2planar_tmp[P6i_tmp_2] * rtb_Gain15_1;
      rtb_Sum6 += (real_T)P2planar_tmp[P6i_tmp_2 + 1] * rtb_Gain15_1;
      theta5 += (real_T)P2planar_tmp[P6i_tmp_2 + 2] * rtb_Gain15_1;
      XE += (real_T)P2planar_tmp[P6i_tmp_2 + 3] * rtb_Gain15_1;
      P4planar[P6i_tmp_1] = 0.0;
    }

    b_a[rtb_Gain15_tmp + 3] = XE;
    b_a[rtb_Gain15_tmp + 2] = theta5;
    b_a[rtb_Gain15_tmp + 1] = rtb_Sum6;
    b_a[rtb_Gain15_tmp] = rtb_Sum11;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    P6i_tmp_1 = i_0 << 2;
    rtb_Sum11 = P4planar[P6i_tmp_1];
    rtb_Sum6 = P4planar[P6i_tmp_1 + 1];
    theta5 = P4planar[P6i_tmp_1 + 2];
    XE = P4planar[P6i_tmp_1 + 3];
    for (i = 0; i < 4; i++) {
      rtb_Gain15_1 = c_b_0[P6i_tmp_1 + i];
      rtb_Gain15_tmp = i << 2;
      rtb_Sum11 += b_a[rtb_Gain15_tmp] * rtb_Gain15_1;
      rtb_Sum6 += b_a[rtb_Gain15_tmp + 1] * rtb_Gain15_1;
      theta5 += b_a[rtb_Gain15_tmp + 2] * rtb_Gain15_1;
      XE += b_a[rtb_Gain15_tmp + 3] * rtb_Gain15_1;
    }

    P4planar[P6i_tmp_1 + 3] = XE;
    P4planar[P6i_tmp_1 + 2] = theta5;
    P4planar[P6i_tmp_1 + 1] = rtb_Sum6;
    P4planar[P6i_tmp_1] = rtb_Sum11;
  }

  XE = P4planar[12] - P2planar[12];
  YE = P4planar[14] - P2planar[14];
  rtb_Gain15_1 = XE * XE;
  rtb_Sum11 = YE * YE;
  rtb_Sum6 = (((((((rtb_Gain15_1 * 0.15680000000000002 - 0.0038886400000000022)
                   + rtb_Sum11 * 0.15680000000000002) - 0.00020735999999999997)
                 + rtb_Gain15_1 * 0.0288) + rtb_Sum11 * 0.0288) - rt_powd_snf(XE,
    4.0)) - rtb_Gain15_1 * 2.0 * rtb_Sum11) - rt_powd_snf(YE, 4.0);
  if (rtb_Sum6 > 0.0) {
    theta5 = atan((0.56 * YE + sqrt(rtb_Sum6)) / ((((0.56 * XE +
      0.078400000000000011) - 0.0144) + rtb_Gain15_1) + rtb_Sum11)) * 2.0;
    rtb_Sum6 = (rtb_Gain15_1 - 0.0256) + rtb_Sum11;
    XE = atan(sqrt(((0.16 - rtb_Gain15_1) - rtb_Sum11) * rtb_Sum6) / rtb_Sum6) *
      -2.0;
  } else {
    theta5 = 0.0;
    XE = 0.0;
  }

  theta5 += 3.1415926535897931 - theta2;
  rtb_Sum6 = sin(rtb_Gain15);
  rtb_Sum11 = cos(rtb_Gain15);
  rtb_Gain15 = sin(theta5);
  theta2 = cos(theta5);
  theta5 = sin(XE);
  XE = cos(XE);
  YE = sin(angToBase);
  angToBase = cos(angToBase);
  P2planar[0] = rtb_Sum11;
  P2planar[4] = -rtb_Sum6;
  P2planar[8] = 0.0;
  P2planar[12] = 0.0;
  P2planar[1] = rtb_Sum6;
  P2planar[5] = rtb_Sum11;
  P2planar[9] = 0.0;
  P2planar[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Gain15_tmp = i_0 << 2;
    P2planar[rtb_Gain15_tmp + 2] = P6i_tmp_0[i_0];
    P2planar[rtb_Gain15_tmp + 3] = P6i_tmp[i_0];
    b_a[rtb_Gain15_tmp] = 0.0;
    b_a[rtb_Gain15_tmp + 1] = 0.0;
    b_a[rtb_Gain15_tmp + 2] = 0.0;
    b_a[rtb_Gain15_tmp + 3] = 0.0;
  }

  P4planar[0] = theta2;
  P4planar[4] = -rtb_Gain15;
  P4planar[8] = 0.0;
  P4planar[12] = 0.12;
  P4planar[1] = rtb_Gain15;
  P4planar[5] = theta2;
  P4planar[9] = 0.0;
  P4planar[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    P6i_tmp_2 = i_0 << 2;
    P4planar[P6i_tmp_2 + 2] = P6i_tmp_0[i_0];
    P4planar[P6i_tmp_2 + 3] = P6i_tmp[i_0];
    rtb_Sum11 = b_a[P6i_tmp_2];
    theta2 = b_a[P6i_tmp_2 + 1];
    rtb_Gain15 = b_a[P6i_tmp_2 + 2];
    rtb_Sum6 = b_a[P6i_tmp_2 + 3];
    for (i = 0; i < 4; i++) {
      P6i_tmp_1 = P6i_tmp_2 + i;
      rtb_Gain15_1 = P6i[P6i_tmp_1];
      rtb_Gain15_tmp = i << 2;
      rtb_Sum11 += P2planar[rtb_Gain15_tmp] * rtb_Gain15_1;
      theta2 += P2planar[rtb_Gain15_tmp + 1] * rtb_Gain15_1;
      rtb_Gain15 += P2planar[rtb_Gain15_tmp + 2] * rtb_Gain15_1;
      rtb_Sum6 += P2planar[rtb_Gain15_tmp + 3] * rtb_Gain15_1;
      rtb_Gain15_0[P6i_tmp_1] = 0.0;
    }

    b_a[P6i_tmp_2 + 3] = rtb_Sum6;
    b_a[P6i_tmp_2 + 2] = rtb_Gain15;
    b_a[P6i_tmp_2 + 1] = theta2;
    b_a[P6i_tmp_2] = rtb_Sum11;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Gain15_tmp = i_0 << 2;
    rtb_Sum11 = rtb_Gain15_0[rtb_Gain15_tmp];
    theta2 = rtb_Gain15_0[rtb_Gain15_tmp + 1];
    rtb_Gain15 = rtb_Gain15_0[rtb_Gain15_tmp + 2];
    rtb_Sum6 = rtb_Gain15_0[rtb_Gain15_tmp + 3];
    for (i = 0; i < 4; i++) {
      rtb_Gain15_1 = P4planar[rtb_Gain15_tmp + i];
      P6i_tmp_1 = i << 2;
      rtb_Sum11 += b_a[P6i_tmp_1] * rtb_Gain15_1;
      theta2 += b_a[P6i_tmp_1 + 1] * rtb_Gain15_1;
      rtb_Gain15 += b_a[P6i_tmp_1 + 2] * rtb_Gain15_1;
      rtb_Sum6 += b_a[P6i_tmp_1 + 3] * rtb_Gain15_1;
    }

    rtb_Gain15_0[rtb_Gain15_tmp + 3] = rtb_Sum6;
    rtb_Gain15_0[rtb_Gain15_tmp + 2] = rtb_Gain15;
    rtb_Gain15_0[rtb_Gain15_tmp + 1] = theta2;
    rtb_Gain15_0[rtb_Gain15_tmp] = rtb_Sum11;
  }

  P6i[0] = XE;
  P6i[4] = -theta5;
  P6i[8] = 0.0;
  P6i[12] = 0.28;
  P6i[1] = theta5;
  P6i[5] = XE;
  P6i[9] = 0.0;
  P6i[13] = 0.0;
  for (i_0 = 0; i_0 < 4; i_0++) {
    P6i_tmp_1 = i_0 << 2;
    P6i[P6i_tmp_1 + 2] = P6i_tmp_0[i_0];
    P6i[P6i_tmp_1 + 3] = P6i_tmp[i_0];
    rtb_Sum11 = 0.0;
    theta2 = 0.0;
    rtb_Gain15 = 0.0;
    rtb_Sum6 = 0.0;
    for (i = 0; i < 4; i++) {
      rtb_Gain15_1 = P6i[P6i_tmp_1 + i];
      rtb_Gain15_tmp = i << 2;
      rtb_Sum11 += rtb_Gain15_0[rtb_Gain15_tmp] * rtb_Gain15_1;
      theta2 += rtb_Gain15_0[rtb_Gain15_tmp + 1] * rtb_Gain15_1;
      rtb_Gain15 += rtb_Gain15_0[rtb_Gain15_tmp + 2] * rtb_Gain15_1;
      rtb_Sum6 += rtb_Gain15_0[rtb_Gain15_tmp + 3] * rtb_Gain15_1;
    }

    P2planar[P6i_tmp_1 + 3] = rtb_Sum6;
    P2planar[P6i_tmp_1 + 2] = rtb_Gain15;
    P2planar[P6i_tmp_1 + 1] = theta2;
    P2planar[P6i_tmp_1] = rtb_Sum11;
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
    rtb_Gain15 = 0.0;
    rtb_Sum6 = 0.0;
    for (i = 0; i < 4; i++) {
      rtb_Gain15_1 = P6i[P6i_tmp_1 + i];
      rtb_Gain15_tmp = i << 2;
      rtb_Sum11 += P2planar[rtb_Gain15_tmp] * rtb_Gain15_1;
      theta2 += P2planar[rtb_Gain15_tmp + 1] * rtb_Gain15_1;
      rtb_Gain15 += P2planar[rtb_Gain15_tmp + 2] * rtb_Gain15_1;
      rtb_Sum6 += P2planar[rtb_Gain15_tmp + 3] * rtb_Gain15_1;
    }

    b_a[P6i_tmp_1 + 3] = rtb_Sum6;
    b_a[P6i_tmp_1 + 2] = rtb_Gain15;
    b_a[P6i_tmp_1 + 1] = theta2;
    b_a[P6i_tmp_1] = rtb_Sum11;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    rtb_Sum11 = 0.0;
    rtb_Sum6 = 0.0;
    theta5 = 0.0;
    XE = 0.0;
    for (i = 0; i < 4; i++) {
      rtb_Gain15_1 = d_b_0[(i_0 << 2) + i];
      rtb_Gain15_tmp = i << 2;
      rtb_Sum11 += b_a[rtb_Gain15_tmp] * rtb_Gain15_1;
      rtb_Sum6 += b_a[rtb_Gain15_tmp + 1] * rtb_Gain15_1;
      theta5 += b_a[rtb_Gain15_tmp + 2] * rtb_Gain15_1;
      XE += b_a[rtb_Gain15_tmp + 3] * rtb_Gain15_1;
    }

    rtb_Gain15_tmp = i_0 << 2;
    P2planar[rtb_Gain15_tmp + 3] = XE;
    P2planar[rtb_Gain15_tmp + 2] = theta5;
    P2planar[rtb_Gain15_tmp + 1] = rtb_Sum6;
    P2planar[rtb_Gain15_tmp] = rtb_Sum11;
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/x'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  rtb_Gain15_1 = P2planar[12] - rtU.x;

  /* DotProduct: '<S3>/Dot Product' */
  angToBase = rtb_Gain15_1 * rtb_Gain15_1;

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/y'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  rtb_Gain15_1 = P2planar[13] - rtU.y;

  /* DotProduct: '<S3>/Dot Product' */
  angToBase += rtb_Gain15_1 * rtb_Gain15_1;

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/z'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  rtb_Gain15_1 = P2planar[14] - rtU.z;

  /* Outport: '<Root>/pointReached' incorporates:
   *  Constant: '<S2>/Constant'
   *  DotProduct: '<S3>/Dot Product'
   *  RelationalOperator: '<S2>/Compare'
   *  Sqrt: '<S3>/sqrt'
   */
  rtY.pointReached = (sqrt(rtb_Gain15_1 * rtb_Gain15_1 + angToBase) <= 0.002);

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

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain5'
   *  Gain: '<S1>/Gain9'
   *  Inport: '<Root>/deltaTime'
   *  Inport: '<Root>/gripperRotationDesiredPosition'
   *  UnitDelay: '<S1>/Unit Delay7'
   */
  MATLABFunction2(rtDW.UnitDelay7_DSTATE, 21.0 * (0.017453292519943295 *
    rtU.gripperRotationDesiredPosition), 21.0 * rtU.deltaTime, &angToBase);

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Gain3'
   *  Gain: '<S1>/Gain7'
   *  Inport: '<Root>/deltaTime'
   *  Inport: '<Root>/jawDesiredPosition'
   *  UnitDelay: '<S1>/Unit Delay9'
   */
  MATLABFunction2(rtDW.UnitDelay9_DSTATE, 21.0 * (0.017453292519943295 *
    rtU.jawDesiredPosition), 2.1 * rtU.deltaTime, &theta2);

  /* Sum: '<S1>/Sum6' incorporates:
   *  Inport: '<Root>/jawActualPosition'
   *  UnitDelay: '<S1>/Unit Delay9'
   */
  rtb_Sum6 = rtDW.UnitDelay9_DSTATE - rtU.jawActualPosition;

  /* Update for UnitDelay: '<S1>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE = theta0;

  /* Update for UnitDelay: '<S1>/Unit Delay5' */
  rtDW.UnitDelay5_DSTATE = XEi;

  /* Update for UnitDelay: '<S1>/Unit Delay8' incorporates:
   *  DiscreteIntegrator: '<S100>/Integrator'
   *  Gain: '<S105>/Proportional Gain'
   *  Sum: '<S109>/Sum'
   */
  rtDW.UnitDelay8_DSTATE = 2.0 * rtb_Sum6 + rtDW.Integrator_DSTATE_h;

  /* Gain: '<S53>/Proportional Gain' incorporates:
   *  Gain: '<S45>/Integral Gain'
   *  Inport: '<Root>/gripperRotationActualPosition'
   *  Sum: '<S1>/Sum5'
   *  UnitDelay: '<S1>/Unit Delay7'
   */
  theta0 = (rtDW.UnitDelay7_DSTATE - rtU.gripperRotationActualPosition) * 0.2;

  /* Update for UnitDelay: '<S1>/Unit Delay6' incorporates:
   *  DiscreteIntegrator: '<S48>/Integrator'
   *  Gain: '<S53>/Proportional Gain'
   *  Sum: '<S57>/Sum'
   */
  rtDW.UnitDelay6_DSTATE = theta0 + rtDW.Integrator_DSTATE;

  /* Update for UnitDelay: '<S1>/Unit Delay7' */
  rtDW.UnitDelay7_DSTATE = angToBase;

  /* Update for DiscreteIntegrator: '<S48>/Integrator' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S61>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE += theta0 * rtU.deltaTime;

  /* Update for UnitDelay: '<S1>/Unit Delay9' */
  rtDW.UnitDelay9_DSTATE = theta2;

  /* Update for DiscreteIntegrator: '<S100>/Integrator' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S113>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE_h += rtb_Sum6 * rtU.deltaTime;
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
