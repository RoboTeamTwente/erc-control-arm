/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_arm_manual_webots.c
 *
 * Code generated for Simulink model 'control_arm_manual_webots'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon May 11 12:51:03 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "control_arm_manual_webots.h"
#include <math.h>
#include <emmintrin.h>
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
void control_arm_manual_webots_step(void)
{
  real_T P6i[16];
  real_T XEi;
  real_T angToBase;
  real_T theta0;
  real_T theta2;
  real_T theta4;
  static const real_T a[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.065, 1.0 };

  real_T P2planar[16];
  real_T P4planar[16];
  real_T XE;
  real_T YE;
  static const real_T a_0[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.149, 1.0 };

  static const real_T b_a[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.065, 1.0 };

  __m128d tmp_0;
  __m128d tmp_2;
  real_T XE_0[16];
  real_T XE_1[16];
  real_T rtb_angles[5];
  real_T tmp[2];
  real_T P6i_tmp;
  real_T a_1;
  int32_T P6i_tmp_2;
  int32_T P6i_tmp_3;
  int32_T XE_tmp;
  int32_T i;
  int32_T tmp_1;
  int8_T P2planar_tmp[16];
  int8_T P6i_tmp_0[4];
  int8_T P6i_tmp_1[4];
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

  static const real_T d_b[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, -0.12, 0.0, 0.0, 1.0 };

  static const real_T b_b_0[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.35, 0.0, 0.0, 1.0 };

  static const real_T c_b_0[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.12, 0.0, 0.0, 1.0 };

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
  theta4 = sin(angToBase);
  XE = cos(angToBase);
  YE = sin(rtU.gripperAng);
  P6i_tmp = cos(rtU.gripperAng);
  XE_0[0] = XE;
  XE_0[4] = -theta4;
  XE_0[8] = 0.0;
  XE_0[12] = rtU.x;
  XE_0[1] = theta4;
  XE_0[5] = XE;
  XE_0[9] = 0.0;
  XE_0[13] = rtU.y;
  XE_0[2] = 0.0;
  XE_0[6] = 0.0;
  XE_0[10] = 1.0;
  XE_0[14] = rtU.z;
  P2planar[0] = P6i_tmp;
  P2planar[4] = -YE;
  P2planar[8] = 0.0;
  P2planar[12] = 0.0;
  P2planar[1] = YE;
  P2planar[5] = P6i_tmp;
  P2planar[9] = 0.0;
  P2planar[13] = 0.0;
  for (i = 0; i < 4; i++) {
    /* MATLAB Function: '<S1>/MATLAB Function4' */
    P6i_tmp_2 = b[i];
    P6i_tmp_0[i] = (int8_T)P6i_tmp_2;

    /* MATLAB Function: '<S1>/MATLAB Function4' */
    P6i_tmp_3 = c[i];
    P6i_tmp_1[i] = (int8_T)P6i_tmp_3;
    XE_tmp = i << 2;
    XE_0[XE_tmp + 3] = P6i_tmp_2;
    P2planar[XE_tmp + 2] = P6i_tmp_3;
    P2planar[XE_tmp + 3] = P6i_tmp_2;
    XE_1[XE_tmp] = 0.0;
    XE_1[XE_tmp + 1] = 0.0;
    XE_1[XE_tmp + 2] = 0.0;
    XE_1[XE_tmp + 3] = 0.0;
  }

  for (i = 0; i < 4; i++) {
    XE_tmp = i << 2;
    XE = XE_1[XE_tmp];
    XEi = XE_1[XE_tmp + 1];
    angToBase = XE_1[XE_tmp + 2];
    P6i_tmp = XE_1[XE_tmp + 3];
    for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
      tmp_1 = P6i_tmp_3 << 2;
      P6i_tmp_2 = XE_tmp + P6i_tmp_3;
      tmp_2 = _mm_set1_pd(b_b[P6i_tmp_2]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_0[tmp_1]), tmp_2),
                         _mm_set_pd(XEi, XE));
      _mm_storeu_pd(&tmp[0], tmp_0);
      XE = tmp[0];
      XEi = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_0[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(P6i_tmp, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      P6i_tmp = tmp[1];
      P4planar[P6i_tmp_2] = 0.0;
    }

    XE_1[XE_tmp + 3] = P6i_tmp;
    XE_1[XE_tmp + 2] = angToBase;
    XE_1[XE_tmp + 1] = XEi;
    XE_1[XE_tmp] = XE;
    P6i_tmp = P4planar[XE_tmp];
    XEi = P4planar[XE_tmp + 1];
    angToBase = P4planar[XE_tmp + 2];
    YE = P4planar[XE_tmp + 3];
    for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
      tmp_1 = P6i_tmp_3 << 2;
      P6i_tmp_2 = XE_tmp + P6i_tmp_3;
      tmp_2 = _mm_set1_pd(c_b[P6i_tmp_2]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P2planar[tmp_1]), tmp_2),
                         _mm_set_pd(XEi, P6i_tmp));
      _mm_storeu_pd(&tmp[0], tmp_0);
      P6i_tmp = tmp[0];
      XEi = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P2planar[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(YE, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      YE = tmp[1];
      P6i[P6i_tmp_2] = 0.0;
    }

    P4planar[XE_tmp + 3] = YE;
    P4planar[XE_tmp + 2] = angToBase;
    P4planar[XE_tmp + 1] = XEi;
    P4planar[XE_tmp] = P6i_tmp;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_2 = i << 2;
    P6i_tmp = P6i[P6i_tmp_2];
    YE = P6i[P6i_tmp_2 + 1];
    XE = P6i[P6i_tmp_2 + 2];
    theta2 = P6i[P6i_tmp_2 + 3];
    for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
      tmp_1 = P6i_tmp_3 << 2;
      tmp_2 = _mm_set1_pd(P4planar[P6i_tmp_2 + P6i_tmp_3]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_1[tmp_1]), tmp_2),
                         _mm_set_pd(YE, P6i_tmp));
      _mm_storeu_pd(&tmp[0], tmp_0);
      P6i_tmp = tmp[0];
      YE = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_1[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(theta2, XE));
      _mm_storeu_pd(&tmp[0], tmp_2);
      XE = tmp[0];
      theta2 = tmp[1];
    }

    P6i[P6i_tmp_2 + 3] = theta2;
    P6i[P6i_tmp_2 + 2] = XE;
    P6i[P6i_tmp_2 + 1] = YE;
    P6i[P6i_tmp_2] = P6i_tmp;
  }

  XEi = sqrt(P6i[12] * P6i[12] + P6i[13] * P6i[13]);
  P6i_tmp = XEi * XEi;
  YE = (P6i[14] - 0.065) * (P6i[14] - 0.065);
  angToBase = (((((((P6i_tmp * 0.24499999999999997 + 0.04624375) + YE *
                    0.24499999999999997) - 0.0625) + P6i_tmp * 0.5) + YE * 0.5)
                - rt_powd_snf(XEi, 4.0)) - P6i_tmp * 2.0 * YE) - rt_powd_snf
    (P6i[14] - 0.065, 4.0);
  if (angToBase < 0.0) {
    for (i = 0; i < 5; i++) {
      rtb_angles[i] = d[i];
    }

    /* Outport: '<Root>/error' */
    rtY.error = 1.0;
  } else {
    angToBase = atan(((P6i[14] - 0.065) * 0.7 + sqrt(angToBase)) / ((((0.7 * XEi
      + 0.12249999999999998) - 0.25) + P6i_tmp) + YE)) * 2.0;
    XEi = (P6i_tmp - 0.02250000000000002) + YE;
    theta2 = atan(sqrt(((0.72249999999999992 - P6i_tmp) - YE) * XEi) / XEi) *
      -2.0;
    XEi = (-rtU.gripperAng - angToBase) - theta2;
    theta4 = sin(angToBase);
    XE = cos(angToBase);
    YE = sin(theta2);
    P6i_tmp = cos(theta2);
    XE_0[0] = XE;
    XE_0[4] = -theta4;
    XE_0[8] = 0.0;
    XE_0[12] = 0.0;
    XE_0[1] = theta4;
    XE_0[5] = XE;
    XE_0[9] = 0.0;
    XE_0[13] = 0.0;
    for (i = 0; i < 4; i++) {
      XE_tmp = i << 2;
      XE_0[XE_tmp + 2] = P6i_tmp_1[i];
      XE_0[XE_tmp + 3] = P6i_tmp_0[i];
      XE = 0.0;
      theta2 = 0.0;
      theta4 = 0.0;
      a_1 = 0.0;
      for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
        tmp_1 = P6i_tmp_3 << 2;
        tmp_2 = _mm_set1_pd(XE_0[XE_tmp + P6i_tmp_3]);
        _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&a[tmp_1]),
          tmp_2), _mm_set_pd(theta2, XE)));
        XE = tmp[0];
        theta2 = tmp[1];
        _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&a[tmp_1 + 2]),
          tmp_2), _mm_set_pd(a_1, theta4)));
        theta4 = tmp[0];
        a_1 = tmp[1];
      }

      P6i[XE_tmp + 3] = a_1;
      P6i[XE_tmp + 2] = theta4;
      P6i[XE_tmp + 1] = theta2;
      P6i[XE_tmp] = XE;
    }

    P2planar[0] = P6i_tmp;
    P2planar[4] = -YE;
    P2planar[8] = 0.0;
    P2planar[12] = 0.35;
    P2planar[1] = YE;
    P2planar[5] = P6i_tmp;
    P2planar[9] = 0.0;
    P2planar[13] = 0.0;
    for (i = 0; i < 4; i++) {
      XE_tmp = i << 2;
      P2planar[XE_tmp + 2] = P6i_tmp_1[i];
      P2planar[XE_tmp + 3] = P6i_tmp_0[i];
      P6i_tmp = 0.0;
      YE = 0.0;
      XE = 0.0;
      theta2 = 0.0;
      for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
        tmp_1 = P6i_tmp_3 << 2;
        P6i_tmp_2 = XE_tmp + P6i_tmp_3;
        tmp_2 = _mm_set1_pd(P6i[P6i_tmp_2]);
        _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(c_a[tmp_1 + 1],
          c_a[tmp_1]), tmp_2), _mm_set_pd(YE, P6i_tmp)));
        P6i_tmp = tmp[0];
        YE = tmp[1];
        _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(c_a[tmp_1 + 3],
          c_a[tmp_1 + 2]), tmp_2), _mm_set_pd(theta2, XE)));
        XE = tmp[0];
        theta2 = tmp[1];
        XE_1[P6i_tmp_2] = 0.0;
      }

      XE_0[XE_tmp + 3] = theta2;
      XE_0[XE_tmp + 2] = XE;
      XE_0[XE_tmp + 1] = YE;
      XE_0[XE_tmp] = P6i_tmp;
    }

    for (i = 0; i < 4; i++) {
      P6i_tmp_2 = i << 2;
      P6i_tmp = XE_1[P6i_tmp_2];
      YE = XE_1[P6i_tmp_2 + 1];
      XE = XE_1[P6i_tmp_2 + 2];
      theta2 = XE_1[P6i_tmp_2 + 3];
      for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
        tmp_1 = P6i_tmp_3 << 2;
        tmp_2 = _mm_set1_pd(P2planar[P6i_tmp_2 + P6i_tmp_3]);
        tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_0[tmp_1]), tmp_2),
                           _mm_set_pd(YE, P6i_tmp));
        _mm_storeu_pd(&tmp[0], tmp_0);
        P6i_tmp = tmp[0];
        YE = tmp[1];
        tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_0[tmp_1 + 2]), tmp_2),
                           _mm_set_pd(theta2, XE));
        _mm_storeu_pd(&tmp[0], tmp_2);
        XE = tmp[0];
        theta2 = tmp[1];
      }

      XE_1[P6i_tmp_2 + 3] = theta2;
      XE_1[P6i_tmp_2 + 2] = XE;
      XE_1[P6i_tmp_2 + 1] = YE;
      XE_1[P6i_tmp_2] = P6i_tmp;
    }

    for (i = 0; i < 4; i++) {
      P6i_tmp = 0.0;
      YE = 0.0;
      XE = 0.0;
      theta2 = 0.0;
      for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
        tmp_1 = P6i_tmp_3 << 2;
        tmp_2 = _mm_set1_pd(d_b[(i << 2) + P6i_tmp_3]);
        tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_1[tmp_1]), tmp_2),
                           _mm_set_pd(YE, P6i_tmp));
        _mm_storeu_pd(&tmp[0], tmp_0);
        P6i_tmp = tmp[0];
        YE = tmp[1];
        tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_1[tmp_1 + 2]), tmp_2),
                           _mm_set_pd(theta2, XE));
        _mm_storeu_pd(&tmp[0], tmp_2);
        XE = tmp[0];
        theta2 = tmp[1];
      }

      P6i_tmp_2 = i << 2;
      P6i[P6i_tmp_2 + 3] = theta2;
      P6i[P6i_tmp_2 + 2] = XE;
      P6i[P6i_tmp_2 + 1] = YE;
      P6i[P6i_tmp_2] = P6i_tmp;
    }

    P6i_tmp = P6i[12] * P6i[12];
    YE = (P6i[14] - 0.149) * (P6i[14] - 0.149);
    theta4 = atan((sqrt((((((((P6i_tmp * 0.0288 + 0.00205056) + YE * 0.0288) -
      0.0061465600000000023) + P6i_tmp * 0.15680000000000002) + YE *
      0.15680000000000002) - rt_powd_snf(P6i[12], 4.0)) - P6i_tmp * 2.0 * YE) -
                        rt_powd_snf(P6i[14] - 0.149, 4.0)) + (P6i[14] - 0.149) *
                   0.24) / ((((0.24 * P6i[12] + 0.0144) - 0.078400000000000011)
      + P6i_tmp) + YE)) * 2.0;
    if ((fabs(theta0) > 3.1415926535897931) || ((angToBase < 0.0) || (angToBase >
          2.3561944901923448) || (XEi < -2.3561944901923448) || (XEi >
          0.78539816339744828) || (theta4 < 1.5707963267948966) || (theta4 >
          4.71238898038469))) {
      for (i = 0; i < 5; i++) {
        rtb_angles[i] = d[i];
      }

      /* Outport: '<Root>/error' */
      rtY.error = 2.0;
    } else {
      rtb_angles[0] = theta0;
      rtb_angles[1] = angToBase;
      rtb_angles[3] = XEi;
      rtb_angles[4] = theta4;

      /* Outport: '<Root>/error' */
      rtY.error = 0.0;
    }
  }

  /* End of MATLAB Function: '<S1>/inverse kinematics' */

  /* Outport: '<Root>/controlGripperPitch' incorporates:
   *  Gain: '<S1>/Gain'
   */
  rtY.controlGripperPitch = -rtb_angles[3];

  /* Outport: '<Root>/controlBase' incorporates:
   *  Gain: '<S1>/Gain3'
   */
  rtY.controlBase = -rtb_angles[0];

  /* Sum: '<S1>/Sum9' incorporates:
   *  Constant: '<S1>/Pi'
   *  Constant: '<S1>/Pi1'
   *  Sum: '<S1>/Sum7'
   */
  _mm_storeu_pd(&tmp[0], _mm_sub_pd(_mm_set_pd(1.5707963267948966,
    3.1415926535897931), _mm_set_pd(rtb_angles[1], rtb_angles[4])));

  /* Outport: '<Root>/controlStepperLeft' */
  rtY.controlStepperLeft = tmp[0];

  /* Outport: '<Root>/controlStepperRight' */
  rtY.controlStepperRight = tmp[1];

  /* MATLAB Function: '<S1>/MATLAB Function4' incorporates:
   *  Constant: '<S1>/Pi2'
   *  Constant: '<S1>/Pi4'
   *  Gain: '<S1>/Gain1'
   *  Inport: '<Root>/baseActualPosition'
   *  Inport: '<Root>/gripperPitchActualPosition'
   *  Inport: '<Root>/stepperLeftActualPosition'
   *  Inport: '<Root>/stepperRightActualPosition'
   *  Sum: '<S1>/Sum10'
   *  Sum: '<S1>/Sum11'
   */
  theta4 = sin(3.1415926535897931 - rtU.stepperLeftActualPosition);
  XEi = cos(3.1415926535897931 - rtU.stepperLeftActualPosition);
  P4planar[0] = XEi;
  P4planar[4] = -theta4;
  P4planar[8] = 0.0;
  P4planar[12] = 0.0;
  P4planar[1] = theta4;
  P4planar[5] = XEi;
  P4planar[9] = 0.0;
  P4planar[13] = 0.0;
  for (i = 0; i < 4; i++) {
    XE_tmp = i << 2;
    P4planar[XE_tmp + 2] = P6i_tmp_1[i];
    P4planar[XE_tmp + 3] = P6i_tmp_0[i];
    P6i_tmp = 0.0;
    YE = 0.0;
    XE = 0.0;
    theta2 = 0.0;
    for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
      tmp_1 = P6i_tmp_3 << 2;
      tmp_2 = _mm_set1_pd(P4planar[XE_tmp + P6i_tmp_3]);
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&a_0[tmp_1]),
        tmp_2), _mm_set_pd(YE, P6i_tmp)));
      P6i_tmp = tmp[0];
      YE = tmp[1];
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&a_0[tmp_1 + 2]),
        tmp_2), _mm_set_pd(theta2, XE)));
      XE = tmp[0];
      theta2 = tmp[1];
    }

    P6i[XE_tmp + 3] = theta2;
    P6i[XE_tmp + 2] = XE;
    P6i[XE_tmp + 1] = YE;
    P6i[XE_tmp] = P6i_tmp;
  }

  theta4 = sin(1.5707963267948966 - rtU.stepperRightActualPosition);
  theta2 = cos(1.5707963267948966 - rtU.stepperRightActualPosition);
  for (i = 0; i < 16; i++) {
    P2planar_tmp[i] = c_a[i];
  }

  P2planar[0] = theta2;
  P2planar[4] = -theta4;
  P2planar[8] = 0.0;
  P2planar[12] = 0.0;
  P2planar[1] = theta4;
  P2planar[5] = theta2;
  P2planar[9] = 0.0;
  P2planar[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_2 = i << 2;
    P2planar[P6i_tmp_2 + 2] = P6i_tmp_1[i];
    P2planar[P6i_tmp_2 + 3] = P6i_tmp_0[i];
    P6i_tmp = 0.0;
    YE = 0.0;
    XE = 0.0;
    theta2 = 0.0;
    for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
      tmp_1 = P6i_tmp_3 << 2;
      tmp_2 = _mm_set1_pd(P2planar[P6i_tmp_2 + P6i_tmp_3]);
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a[tmp_1]),
        tmp_2), _mm_set_pd(YE, P6i_tmp)));
      P6i_tmp = tmp[0];
      YE = tmp[1];
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a[tmp_1 + 2]),
        tmp_2), _mm_set_pd(theta2, XE)));
      XE = tmp[0];
      theta2 = tmp[1];
    }

    XE_0[P6i_tmp_2 + 3] = theta2;
    XE_0[P6i_tmp_2 + 2] = XE;
    XE_0[P6i_tmp_2 + 1] = YE;
    XE_0[P6i_tmp_2] = P6i_tmp;
  }

  for (i = 0; i < 4; i++) {
    theta0 = 0.0;
    XEi = 0.0;
    angToBase = 0.0;
    P6i_tmp = 0.0;
    for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
      tmp_1 = P6i_tmp_3 << 2;
      P6i_tmp_2 = (i << 2) + P6i_tmp_3;
      tmp_2 = _mm_set1_pd(XE_0[P6i_tmp_2]);
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(P2planar_tmp[tmp_1
        + 1], P2planar_tmp[tmp_1]), tmp_2), _mm_set_pd(XEi, theta0)));
      theta0 = tmp[0];
      XEi = tmp[1];
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(P2planar_tmp[tmp_1
        + 3], P2planar_tmp[tmp_1 + 2]), tmp_2), _mm_set_pd(P6i_tmp, angToBase)));
      angToBase = tmp[0];
      P6i_tmp = tmp[1];
      P2planar[P6i_tmp_2] = 0.0;
    }

    P6i_tmp_3 = i << 2;
    XE_1[P6i_tmp_3 + 3] = P6i_tmp;
    XE_1[P6i_tmp_3 + 2] = angToBase;
    XE_1[P6i_tmp_3 + 1] = XEi;
    XE_1[P6i_tmp_3] = theta0;
  }

  for (i = 0; i < 4; i++) {
    XE_tmp = i << 2;
    theta0 = P2planar[XE_tmp];
    XEi = P2planar[XE_tmp + 1];
    angToBase = P2planar[XE_tmp + 2];
    P6i_tmp = P2planar[XE_tmp + 3];
    for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
      tmp_1 = P6i_tmp_3 << 2;
      P6i_tmp_2 = XE_tmp + P6i_tmp_3;
      tmp_2 = _mm_set1_pd(b_b_0[P6i_tmp_2]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_1[tmp_1]), tmp_2),
                         _mm_set_pd(XEi, theta0));
      _mm_storeu_pd(&tmp[0], tmp_0);
      theta0 = tmp[0];
      XEi = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_1[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(P6i_tmp, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      P6i_tmp = tmp[1];
      XE_0[P6i_tmp_2] = 0.0;
    }

    P2planar[XE_tmp + 3] = P6i_tmp;
    P2planar[XE_tmp + 2] = angToBase;
    P2planar[XE_tmp + 1] = XEi;
    P2planar[XE_tmp] = theta0;
    theta0 = XE_0[XE_tmp];
    XEi = XE_0[XE_tmp + 1];
    angToBase = XE_0[XE_tmp + 2];
    P6i_tmp = XE_0[XE_tmp + 3];
    for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
      tmp_1 = P6i_tmp_3 << 2;
      P6i_tmp_2 = XE_tmp + P6i_tmp_3;
      tmp_2 = _mm_set1_pd(P6i[P6i_tmp_2]);
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(P2planar_tmp[tmp_1
        + 1], P2planar_tmp[tmp_1]), tmp_2), _mm_set_pd(XEi, theta0)));
      theta0 = tmp[0];
      XEi = tmp[1];
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(P2planar_tmp[tmp_1
        + 3], P2planar_tmp[tmp_1 + 2]), tmp_2), _mm_set_pd(P6i_tmp, angToBase)));
      angToBase = tmp[0];
      P6i_tmp = tmp[1];
      P4planar[P6i_tmp_2] = 0.0;
    }

    XE_0[XE_tmp + 3] = P6i_tmp;
    XE_0[XE_tmp + 2] = angToBase;
    XE_0[XE_tmp + 1] = XEi;
    XE_0[XE_tmp] = theta0;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_2 = i << 2;
    theta0 = P4planar[P6i_tmp_2];
    XEi = P4planar[P6i_tmp_2 + 1];
    angToBase = P4planar[P6i_tmp_2 + 2];
    P6i_tmp = P4planar[P6i_tmp_2 + 3];
    for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
      tmp_1 = P6i_tmp_3 << 2;
      tmp_2 = _mm_set1_pd(c_b_0[P6i_tmp_2 + P6i_tmp_3]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_0[tmp_1]), tmp_2),
                         _mm_set_pd(XEi, theta0));
      _mm_storeu_pd(&tmp[0], tmp_0);
      theta0 = tmp[0];
      XEi = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_0[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(P6i_tmp, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      P6i_tmp = tmp[1];
    }

    P4planar[P6i_tmp_2 + 3] = P6i_tmp;
    P4planar[P6i_tmp_2 + 2] = angToBase;
    P4planar[P6i_tmp_2 + 1] = XEi;
    P4planar[P6i_tmp_2] = theta0;
  }

  _mm_storeu_pd(&tmp[0], _mm_sub_pd(_mm_set_pd(P4planar[14], P4planar[12]),
    _mm_set_pd(P2planar[14], P2planar[12])));
  P6i_tmp = tmp[0] * tmp[0];
  YE = tmp[1] * tmp[1];
  angToBase = (((((((P6i_tmp * 0.15680000000000002 - 0.0038886400000000022) + YE
                    * 0.15680000000000002) - 0.00020735999999999997) + P6i_tmp *
                  0.0288) + YE * 0.0288) - rt_powd_snf(tmp[0], 4.0)) - P6i_tmp *
               2.0 * YE) - rt_powd_snf(tmp[1], 4.0);
  if (angToBase > 0.0) {
    XEi = atan((0.56 * tmp[1] + sqrt(angToBase)) / ((((0.56 * tmp[0] +
      0.078400000000000011) - 0.0144) + P6i_tmp) + YE)) * 2.0;
    theta0 = (P6i_tmp - 0.0256) + YE;
    YE = atan(sqrt(((0.16 - P6i_tmp) - YE) * theta0) / theta0) * -2.0;
  } else {
    XEi = 0.0;
    YE = 0.0;
  }

  XEi += 3.1415926535897931 - (3.1415926535897931 -
    rtU.stepperLeftActualPosition);
  theta4 = sin(rtU.baseActualPosition);
  theta2 = cos(rtU.baseActualPosition);
  angToBase = sin(XEi);
  XEi = cos(XEi);
  XE = sin(YE);
  YE = cos(YE);
  P6i_tmp = sin(-rtU.gripperPitchActualPosition);
  theta0 = cos(-rtU.gripperPitchActualPosition);
  P2planar[0] = theta2;
  P2planar[4] = -theta4;
  P2planar[8] = 0.0;
  P2planar[12] = 0.0;
  P2planar[1] = theta4;
  P2planar[5] = theta2;
  P2planar[9] = 0.0;
  P2planar[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_2 = i << 2;
    P2planar[P6i_tmp_2 + 2] = P6i_tmp_1[i];
    P2planar[P6i_tmp_2 + 3] = P6i_tmp_0[i];
    XE_0[P6i_tmp_2] = 0.0;
    XE_0[P6i_tmp_2 + 1] = 0.0;
    XE_0[P6i_tmp_2 + 2] = 0.0;
    XE_0[P6i_tmp_2 + 3] = 0.0;
  }

  P4planar[0] = XEi;
  P4planar[4] = -angToBase;
  P4planar[8] = 0.0;
  P4planar[12] = 0.12;
  P4planar[1] = angToBase;
  P4planar[5] = XEi;
  P4planar[9] = 0.0;
  P4planar[13] = 0.0;
  for (i = 0; i < 4; i++) {
    XE_tmp = i << 2;
    P4planar[XE_tmp + 2] = P6i_tmp_1[i];
    P4planar[XE_tmp + 3] = P6i_tmp_0[i];
    theta2 = XE_0[XE_tmp];
    XEi = XE_0[XE_tmp + 1];
    angToBase = XE_0[XE_tmp + 2];
    theta4 = XE_0[XE_tmp + 3];
    for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
      tmp_1 = P6i_tmp_3 << 2;
      P6i_tmp_2 = XE_tmp + P6i_tmp_3;
      tmp_2 = _mm_set1_pd(P6i[P6i_tmp_2]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P2planar[tmp_1]), tmp_2),
                         _mm_set_pd(XEi, theta2));
      _mm_storeu_pd(&tmp[0], tmp_0);
      theta2 = tmp[0];
      XEi = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P2planar[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(theta4, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      theta4 = tmp[1];
      XE_1[P6i_tmp_2] = 0.0;
    }

    XE_0[XE_tmp + 3] = theta4;
    XE_0[XE_tmp + 2] = angToBase;
    XE_0[XE_tmp + 1] = XEi;
    XE_0[XE_tmp] = theta2;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_2 = i << 2;
    theta2 = XE_1[P6i_tmp_2];
    XEi = XE_1[P6i_tmp_2 + 1];
    angToBase = XE_1[P6i_tmp_2 + 2];
    theta4 = XE_1[P6i_tmp_2 + 3];
    for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
      tmp_1 = P6i_tmp_3 << 2;
      tmp_2 = _mm_set1_pd(P4planar[P6i_tmp_2 + P6i_tmp_3]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_0[tmp_1]), tmp_2),
                         _mm_set_pd(XEi, theta2));
      _mm_storeu_pd(&tmp[0], tmp_0);
      theta2 = tmp[0];
      XEi = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_0[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(theta4, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      theta4 = tmp[1];
    }

    XE_1[P6i_tmp_2 + 3] = theta4;
    XE_1[P6i_tmp_2 + 2] = angToBase;
    XE_1[P6i_tmp_2 + 1] = XEi;
    XE_1[P6i_tmp_2] = theta2;
  }

  P6i[0] = YE;
  P6i[4] = -XE;
  P6i[8] = 0.0;
  P6i[12] = 0.28;
  P6i[1] = XE;
  P6i[5] = YE;
  P6i[9] = 0.0;
  P6i[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_2 = i << 2;
    P6i[P6i_tmp_2 + 2] = P6i_tmp_1[i];
    P6i[P6i_tmp_2 + 3] = P6i_tmp_0[i];
    theta2 = 0.0;
    XEi = 0.0;
    angToBase = 0.0;
    theta4 = 0.0;
    for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
      tmp_1 = P6i_tmp_3 << 2;
      tmp_2 = _mm_set1_pd(P6i[P6i_tmp_2 + P6i_tmp_3]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_1[tmp_1]), tmp_2),
                         _mm_set_pd(XEi, theta2));
      _mm_storeu_pd(&tmp[0], tmp_0);
      theta2 = tmp[0];
      XEi = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_1[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(theta4, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      theta4 = tmp[1];
    }

    P2planar[P6i_tmp_2 + 3] = theta4;
    P2planar[P6i_tmp_2 + 2] = angToBase;
    P2planar[P6i_tmp_2 + 1] = XEi;
    P2planar[P6i_tmp_2] = theta2;
  }

  P6i[0] = theta0;
  P6i[4] = -P6i_tmp;
  P6i[8] = 0.0;
  P6i[12] = 0.62;
  P6i[1] = P6i_tmp;
  P6i[5] = theta0;
  P6i[9] = 0.0;
  P6i[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_2 = i << 2;
    P6i[P6i_tmp_2 + 2] = P6i_tmp_1[i];
    P6i[P6i_tmp_2 + 3] = P6i_tmp_0[i];
    theta2 = 0.0;
    XEi = 0.0;
    angToBase = 0.0;
    theta4 = 0.0;
    for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
      tmp_1 = P6i_tmp_3 << 2;
      tmp_2 = _mm_set1_pd(P6i[P6i_tmp_2 + P6i_tmp_3]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P2planar[tmp_1]), tmp_2),
                         _mm_set_pd(XEi, theta2));
      _mm_storeu_pd(&tmp[0], tmp_0);
      theta2 = tmp[0];
      XEi = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P2planar[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(theta4, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      theta4 = tmp[1];
    }

    XE_0[P6i_tmp_2 + 3] = theta4;
    XE_0[P6i_tmp_2 + 2] = angToBase;
    XE_0[P6i_tmp_2 + 1] = XEi;
    XE_0[P6i_tmp_2] = theta2;
  }

  for (i = 0; i < 4; i++) {
    theta0 = 0.0;
    XEi = 0.0;
    angToBase = 0.0;
    P6i_tmp = 0.0;
    for (P6i_tmp_3 = 0; P6i_tmp_3 < 4; P6i_tmp_3++) {
      tmp_1 = P6i_tmp_3 << 2;
      tmp_2 = _mm_set1_pd(c_b[(i << 2) + P6i_tmp_3]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_0[tmp_1]), tmp_2),
                         _mm_set_pd(XEi, theta0));
      _mm_storeu_pd(&tmp[0], tmp_0);
      theta0 = tmp[0];
      XEi = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&XE_0[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(P6i_tmp, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      P6i_tmp = tmp[1];
    }

    XE_tmp = i << 2;
    P2planar[XE_tmp + 3] = P6i_tmp;
    P2planar[XE_tmp + 2] = angToBase;
    P2planar[XE_tmp + 1] = XEi;
    P2planar[XE_tmp] = theta0;
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/x'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  theta0 = P2planar[12] - rtU.x;

  /* DotProduct: '<S3>/Dot Product' */
  XEi = theta0 * theta0;

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/y'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  theta0 = P2planar[13] - rtU.y;

  /* DotProduct: '<S3>/Dot Product' */
  XEi += theta0 * theta0;

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/z'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  theta0 = P2planar[14] - rtU.z;

  /* Outport: '<Root>/pointReached' incorporates:
   *  Constant: '<S2>/Constant'
   *  DotProduct: '<S3>/Dot Product'
   *  RelationalOperator: '<S2>/Compare'
   *  Sqrt: '<S3>/sqrt'
   */
  rtY.pointReached = (sqrt(theta0 * theta0 + XEi) <= 0.002);

  /* Outport: '<Root>/actualX' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  rtY.actualX = P2planar[12];

  /* Outport: '<Root>/actualY' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  rtY.actualY = P2planar[13];

  /* Outport: '<Root>/actualZ' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  rtY.actualZ = P2planar[14];

  /* Outport: '<Root>/controlJaw' incorporates:
   *  UnitDelay: '<S1>/Unit Delay8'
   */
  rtY.controlJaw = rtDW.UnitDelay8_DSTATE;

  /* Sum: '<S1>/Sum6' incorporates:
   *  Inport: '<Root>/jawActualPosition'
   *  Inport: '<Root>/jawDesiredPosition'
   */
  theta0 = rtU.desiredposition - rtU.actualposition;

  /* Outport: '<Root>/controlWristRotation' incorporates:
   *  Inport: '<Root>/gripperRotationDesiredPosition'
   */
  rtY.controlWristRotation = rtU.gripperRotationDesiredPosition;

  /* Update for UnitDelay: '<S1>/Unit Delay8' incorporates:
   *  DiscreteIntegrator: '<S41>/Integrator'
   *  Gain: '<S46>/Proportional Gain'
   *  Sum: '<S50>/Sum'
   */
  rtDW.UnitDelay8_DSTATE = 2.0 * theta0 + rtDW.Integrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S41>/Integrator' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Product: '<S54>/Uintegral*Ts Prod Out'
   */
  rtDW.Integrator_DSTATE += theta0 * rtU.deltaTime;
}

/* Model initialize function */
void control_arm_manual_webots_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
