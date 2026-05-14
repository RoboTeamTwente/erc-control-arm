/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_arm_manual_webots.c
 *
 * Code generated for Simulink model 'control_arm_manual_webots'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu May 14 15:12:41 2026
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
  real_T theta3;
  static const real_T a[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.065, 1.0 };

  real_T P2planar[16];
  real_T P4planar[16];
  real_T theta6;
  static const real_T a_0[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.149, 1.0 };

  static const real_T b_a[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    -1.0, 0.0, 0.0, 0.0, 0.0, 0.065, 1.0 };

  __m128d tmp_0;
  __m128d tmp_2;
  real_T P6i_tmp_4[16];
  real_T P6i_tmp_5[16];
  real_T rtb_angles[5];
  real_T tmp[2];
  real_T P6i_tmp;
  real_T P6i_tmp_0;
  real_T a_1;
  int32_T P6i_tmp_6;
  int32_T P6i_tmp_7;
  int32_T P6i_tmp_tmp;
  int32_T i;
  int32_T tmp_1;
  int8_T P6i_tmp_3[16];
  int8_T P6i_tmp_1[4];
  int8_T P6i_tmp_2[4];
  static const int8_T b[4] = { 0, 0, 0, 1 };

  static const int8_T c[4] = { 0, 0, 1, 0 };

  static const int8_T b_b[16] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 0, 0,
    1 };

  static const int8_T b_a_0[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
    1 };

  static const real_T c_b[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.3, 0.0, 0.0, 1.0 };

  static const real_T d_b[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, -0.12, 0.0, 0.0, 1.0 };

  static const real_T d[5] = { 0.0, 1.5707963267948966, 0.0, 0.0,
    3.1415926535897931 };

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
  XEi = sin(angToBase);
  P6i_tmp = cos(angToBase);
  theta6 = sin(rtU.gripperAng);
  P6i_tmp_0 = cos(rtU.gripperAng);
  P6i_tmp_4[0] = P6i_tmp;
  P6i_tmp_4[4] = -XEi;
  P6i_tmp_4[8] = 0.0;
  P6i_tmp_4[12] = rtU.x;
  P6i_tmp_4[1] = XEi;
  P6i_tmp_4[5] = P6i_tmp;
  P6i_tmp_4[9] = 0.0;
  P6i_tmp_4[13] = rtU.y;
  P6i_tmp_4[2] = 0.0;
  P6i_tmp_4[6] = 0.0;
  P6i_tmp_4[10] = 1.0;
  P6i_tmp_4[14] = rtU.z;
  P6i_tmp_5[0] = P6i_tmp_0;
  P6i_tmp_5[4] = -theta6;
  P6i_tmp_5[8] = 0.0;
  P6i_tmp_5[12] = 0.0;
  P6i_tmp_5[1] = theta6;
  P6i_tmp_5[5] = P6i_tmp_0;
  P6i_tmp_5[9] = 0.0;
  P6i_tmp_5[13] = 0.0;
  for (i = 0; i < 4; i++) {
    /* MATLAB Function: '<S1>/MATLAB Function4' */
    P6i_tmp_6 = b[i];
    P6i_tmp_1[i] = (int8_T)P6i_tmp_6;

    /* MATLAB Function: '<S1>/MATLAB Function4' */
    P6i_tmp_7 = c[i];
    P6i_tmp_2[i] = (int8_T)P6i_tmp_7;
    P6i_tmp_tmp = i << 2;
    P6i_tmp_4[P6i_tmp_tmp + 3] = P6i_tmp_6;
    P6i_tmp_5[P6i_tmp_tmp + 2] = P6i_tmp_7;
    P6i_tmp_5[P6i_tmp_tmp + 3] = P6i_tmp_6;
    P2planar[P6i_tmp_tmp] = 0.0;
    P2planar[P6i_tmp_tmp + 1] = 0.0;
    P2planar[P6i_tmp_tmp + 2] = 0.0;
    P2planar[P6i_tmp_tmp + 3] = 0.0;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_tmp = i << 2;
    P6i_tmp = P2planar[P6i_tmp_tmp];
    P6i_tmp_0 = P2planar[P6i_tmp_tmp + 1];
    theta6 = P2planar[P6i_tmp_tmp + 2];
    XEi = P2planar[P6i_tmp_tmp + 3];
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      P6i_tmp_6 = P6i_tmp_tmp + P6i_tmp_7;
      tmp_2 = _mm_set1_pd(b_b[P6i_tmp_6]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_4[tmp_1]), tmp_2),
                         _mm_set_pd(P6i_tmp_0, P6i_tmp));
      _mm_storeu_pd(&tmp[0], tmp_0);
      P6i_tmp = tmp[0];
      P6i_tmp_0 = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_4[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(XEi, theta6));
      _mm_storeu_pd(&tmp[0], tmp_2);
      theta6 = tmp[0];
      XEi = tmp[1];
      P4planar[P6i_tmp_6] = 0.0;
    }

    P2planar[P6i_tmp_tmp + 3] = XEi;
    P2planar[P6i_tmp_tmp + 2] = theta6;
    P2planar[P6i_tmp_tmp + 1] = P6i_tmp_0;
    P2planar[P6i_tmp_tmp] = P6i_tmp;
    P6i_tmp = P4planar[P6i_tmp_tmp];
    P6i_tmp_0 = P4planar[P6i_tmp_tmp + 1];
    theta6 = P4planar[P6i_tmp_tmp + 2];
    XEi = P4planar[P6i_tmp_tmp + 3];
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      P6i_tmp_6 = P6i_tmp_tmp + P6i_tmp_7;
      tmp_2 = _mm_set1_pd(c_b[P6i_tmp_6]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_5[tmp_1]), tmp_2),
                         _mm_set_pd(P6i_tmp_0, P6i_tmp));
      _mm_storeu_pd(&tmp[0], tmp_0);
      P6i_tmp = tmp[0];
      P6i_tmp_0 = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_5[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(XEi, theta6));
      _mm_storeu_pd(&tmp[0], tmp_2);
      theta6 = tmp[0];
      XEi = tmp[1];
      P6i[P6i_tmp_6] = 0.0;
    }

    P4planar[P6i_tmp_tmp + 3] = XEi;
    P4planar[P6i_tmp_tmp + 2] = theta6;
    P4planar[P6i_tmp_tmp + 1] = P6i_tmp_0;
    P4planar[P6i_tmp_tmp] = P6i_tmp;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_6 = i << 2;
    P6i_tmp_0 = P6i[P6i_tmp_6];
    theta6 = P6i[P6i_tmp_6 + 1];
    P6i_tmp = P6i[P6i_tmp_6 + 2];
    XEi = P6i[P6i_tmp_6 + 3];
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      tmp_2 = _mm_set1_pd(P4planar[P6i_tmp_6 + P6i_tmp_7]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P2planar[tmp_1]), tmp_2),
                         _mm_set_pd(theta6, P6i_tmp_0));
      _mm_storeu_pd(&tmp[0], tmp_0);
      P6i_tmp_0 = tmp[0];
      theta6 = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P2planar[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(XEi, P6i_tmp));
      _mm_storeu_pd(&tmp[0], tmp_2);
      P6i_tmp = tmp[0];
      XEi = tmp[1];
    }

    P6i[P6i_tmp_6 + 3] = XEi;
    P6i[P6i_tmp_6 + 2] = P6i_tmp;
    P6i[P6i_tmp_6 + 1] = theta6;
    P6i[P6i_tmp_6] = P6i_tmp_0;
  }

  XEi = sqrt(P6i[12] * P6i[12] + P6i[13] * P6i[13]);
  angToBase = XEi * XEi;
  P6i_tmp_0 = (P6i[14] - 0.065) * (P6i[14] - 0.065);
  theta3 = (angToBase - 0.02250000000000002) + P6i_tmp_0;
  _mm_storeu_pd(&tmp[0], _mm_mul_pd(_mm_set_pd(atan(sqrt(theta3 *
    ((0.72249999999999992 - angToBase) - P6i_tmp_0)) / theta3), atan((sqrt
    ((((((((angToBase * 0.24499999999999997 + 0.04624375) + P6i_tmp_0 *
           0.24499999999999997) - 0.0625) + angToBase * 0.5) + P6i_tmp_0 * 0.5)
       - rt_powd_snf(XEi, 4.0)) - angToBase * 2.0 * P6i_tmp_0) - rt_powd_snf
     (P6i[14] - 0.065, 4.0)) + (P6i[14] - 0.065) * 0.7) / ((((0.7 * XEi +
    0.12249999999999998) - 0.25) + angToBase) + P6i_tmp_0))), _mm_set_pd(-2.0,
    2.0)));
  angToBase = tmp[0];
  theta3 = (-rtU.gripperAng - tmp[0]) - tmp[1];
  XEi = sin(tmp[0]);
  P6i_tmp = cos(tmp[0]);
  theta6 = sin(tmp[1]);
  P6i_tmp_0 = cos(tmp[1]);
  for (i = 0; i < 16; i++) {
    /* MATLAB Function: '<S1>/MATLAB Function4' */
    P6i_tmp_3[i] = b_a_0[i];
  }

  P6i_tmp_4[0] = P6i_tmp;
  P6i_tmp_4[4] = -XEi;
  P6i_tmp_4[8] = 0.0;
  P6i_tmp_4[12] = 0.0;
  P6i_tmp_4[1] = XEi;
  P6i_tmp_4[5] = P6i_tmp;
  P6i_tmp_4[9] = 0.0;
  P6i_tmp_4[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_tmp = i << 2;
    P6i_tmp_4[P6i_tmp_tmp + 2] = P6i_tmp_2[i];
    P6i_tmp_4[P6i_tmp_tmp + 3] = P6i_tmp_1[i];
    P6i_tmp = 0.0;
    XEi = 0.0;
    theta2 = 0.0;
    a_1 = 0.0;
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      tmp_2 = _mm_set1_pd(P6i_tmp_4[P6i_tmp_tmp + P6i_tmp_7]);
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&a[tmp_1]),
        tmp_2), _mm_set_pd(XEi, P6i_tmp)));
      P6i_tmp = tmp[0];
      XEi = tmp[1];
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&a[tmp_1 + 2]),
        tmp_2), _mm_set_pd(a_1, theta2)));
      theta2 = tmp[0];
      a_1 = tmp[1];
    }

    P6i[P6i_tmp_tmp + 3] = a_1;
    P6i[P6i_tmp_tmp + 2] = theta2;
    P6i[P6i_tmp_tmp + 1] = XEi;
    P6i[P6i_tmp_tmp] = P6i_tmp;
  }

  P6i_tmp_5[0] = P6i_tmp_0;
  P6i_tmp_5[4] = -theta6;
  P6i_tmp_5[8] = 0.0;
  P6i_tmp_5[12] = 0.35;
  P6i_tmp_5[1] = theta6;
  P6i_tmp_5[5] = P6i_tmp_0;
  P6i_tmp_5[9] = 0.0;
  P6i_tmp_5[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_tmp = i << 2;
    P6i_tmp_5[P6i_tmp_tmp + 2] = P6i_tmp_2[i];
    P6i_tmp_5[P6i_tmp_tmp + 3] = P6i_tmp_1[i];
    P6i_tmp = 0.0;
    P6i_tmp_0 = 0.0;
    theta6 = 0.0;
    XEi = 0.0;
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      P6i_tmp_6 = P6i_tmp_tmp + P6i_tmp_7;
      tmp_2 = _mm_set1_pd(P6i[P6i_tmp_6]);
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(P6i_tmp_3[tmp_1 +
        1], P6i_tmp_3[tmp_1]), tmp_2), _mm_set_pd(P6i_tmp_0, P6i_tmp)));
      P6i_tmp = tmp[0];
      P6i_tmp_0 = tmp[1];
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(P6i_tmp_3[tmp_1 +
        3], P6i_tmp_3[tmp_1 + 2]), tmp_2), _mm_set_pd(XEi, theta6)));
      theta6 = tmp[0];
      XEi = tmp[1];
      P2planar[P6i_tmp_6] = 0.0;
    }

    P6i_tmp_4[P6i_tmp_tmp + 3] = XEi;
    P6i_tmp_4[P6i_tmp_tmp + 2] = theta6;
    P6i_tmp_4[P6i_tmp_tmp + 1] = P6i_tmp_0;
    P6i_tmp_4[P6i_tmp_tmp] = P6i_tmp;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_tmp = i << 2;
    P6i_tmp = P2planar[P6i_tmp_tmp];
    P6i_tmp_0 = P2planar[P6i_tmp_tmp + 1];
    theta6 = P2planar[P6i_tmp_tmp + 2];
    XEi = P2planar[P6i_tmp_tmp + 3];
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      tmp_2 = _mm_set1_pd(P6i_tmp_5[P6i_tmp_tmp + P6i_tmp_7]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_4[tmp_1]), tmp_2),
                         _mm_set_pd(P6i_tmp_0, P6i_tmp));
      _mm_storeu_pd(&tmp[0], tmp_0);
      P6i_tmp = tmp[0];
      P6i_tmp_0 = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_4[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(XEi, theta6));
      _mm_storeu_pd(&tmp[0], tmp_2);
      theta6 = tmp[0];
      XEi = tmp[1];
    }

    P2planar[P6i_tmp_tmp + 3] = XEi;
    P2planar[P6i_tmp_tmp + 2] = theta6;
    P2planar[P6i_tmp_tmp + 1] = P6i_tmp_0;
    P2planar[P6i_tmp_tmp] = P6i_tmp;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_0 = 0.0;
    theta6 = 0.0;
    P6i_tmp = 0.0;
    XEi = 0.0;
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      tmp_2 = _mm_set1_pd(d_b[(i << 2) + P6i_tmp_7]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P2planar[tmp_1]), tmp_2),
                         _mm_set_pd(theta6, P6i_tmp_0));
      _mm_storeu_pd(&tmp[0], tmp_0);
      P6i_tmp_0 = tmp[0];
      theta6 = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P2planar[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(XEi, P6i_tmp));
      _mm_storeu_pd(&tmp[0], tmp_2);
      P6i_tmp = tmp[0];
      XEi = tmp[1];
    }

    P6i_tmp_6 = i << 2;
    P6i[P6i_tmp_6 + 3] = XEi;
    P6i[P6i_tmp_6 + 2] = P6i_tmp;
    P6i[P6i_tmp_6 + 1] = theta6;
    P6i[P6i_tmp_6] = P6i_tmp_0;
  }

  P6i_tmp_0 = P6i[12] * P6i[12];
  theta6 = (P6i[14] - 0.149) * (P6i[14] - 0.149);
  XEi = atan((sqrt((((((((P6i_tmp_0 * 0.0288 + 0.00205056) + theta6 * 0.0288) -
                        0.0061465600000000023) + P6i_tmp_0 * 0.15680000000000002)
                      + theta6 * 0.15680000000000002) - rt_powd_snf(P6i[12], 4.0))
                    - P6i_tmp_0 * 2.0 * theta6) - rt_powd_snf(P6i[14] - 0.149,
    4.0)) + (P6i[14] - 0.149) * 0.24) / ((((0.24 * P6i[12] + 0.0144) -
    0.078400000000000011) + P6i_tmp_0) + theta6)) * 2.0;
  if ((fabs(theta0) > 3.1415926535897931) || ((angToBase < 0.0) || (angToBase >
        2.3561944901923448) || (theta3 < -2.3561944901923448) || (theta3 >
        0.78539816339744828) || (XEi < 1.5707963267948966) || (XEi >
        4.71238898038469))) {
    for (i = 0; i < 5; i++) {
      rtb_angles[i] = d[i];
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
  XEi = sin(3.1415926535897931 - rtU.stepperLeftActualPosition);
  theta3 = cos(3.1415926535897931 - rtU.stepperLeftActualPosition);
  P4planar[0] = theta3;
  P4planar[4] = -XEi;
  P4planar[8] = 0.0;
  P4planar[12] = 0.0;
  P4planar[1] = XEi;
  P4planar[5] = theta3;
  P4planar[9] = 0.0;
  P4planar[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_tmp = i << 2;
    P4planar[P6i_tmp_tmp + 2] = P6i_tmp_2[i];
    P4planar[P6i_tmp_tmp + 3] = P6i_tmp_1[i];
    P6i_tmp_0 = 0.0;
    theta6 = 0.0;
    P6i_tmp = 0.0;
    XEi = 0.0;
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      tmp_2 = _mm_set1_pd(P4planar[P6i_tmp_tmp + P6i_tmp_7]);
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&a_0[tmp_1]),
        tmp_2), _mm_set_pd(theta6, P6i_tmp_0)));
      P6i_tmp_0 = tmp[0];
      theta6 = tmp[1];
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&a_0[tmp_1 + 2]),
        tmp_2), _mm_set_pd(XEi, P6i_tmp)));
      P6i_tmp = tmp[0];
      XEi = tmp[1];
    }

    P6i[P6i_tmp_tmp + 3] = XEi;
    P6i[P6i_tmp_tmp + 2] = P6i_tmp;
    P6i[P6i_tmp_tmp + 1] = theta6;
    P6i[P6i_tmp_tmp] = P6i_tmp_0;
  }

  XEi = sin(1.5707963267948966 - rtU.stepperRightActualPosition);
  theta2 = cos(1.5707963267948966 - rtU.stepperRightActualPosition);
  P6i_tmp_4[0] = theta2;
  P6i_tmp_4[4] = -XEi;
  P6i_tmp_4[8] = 0.0;
  P6i_tmp_4[12] = 0.0;
  P6i_tmp_4[1] = XEi;
  P6i_tmp_4[5] = theta2;
  P6i_tmp_4[9] = 0.0;
  P6i_tmp_4[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_tmp = i << 2;
    P6i_tmp_4[P6i_tmp_tmp + 2] = P6i_tmp_2[i];
    P6i_tmp_4[P6i_tmp_tmp + 3] = P6i_tmp_1[i];
    theta0 = 0.0;
    theta3 = 0.0;
    angToBase = 0.0;
    P6i_tmp_0 = 0.0;
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      tmp_2 = _mm_set1_pd(P6i_tmp_4[P6i_tmp_tmp + P6i_tmp_7]);
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a[tmp_1]),
        tmp_2), _mm_set_pd(theta3, theta0)));
      theta0 = tmp[0];
      theta3 = tmp[1];
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a[tmp_1 + 2]),
        tmp_2), _mm_set_pd(P6i_tmp_0, angToBase)));
      angToBase = tmp[0];
      P6i_tmp_0 = tmp[1];
    }

    P6i_tmp_5[P6i_tmp_tmp + 3] = P6i_tmp_0;
    P6i_tmp_5[P6i_tmp_tmp + 2] = angToBase;
    P6i_tmp_5[P6i_tmp_tmp + 1] = theta3;
    P6i_tmp_5[P6i_tmp_tmp] = theta0;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp = 0.0;
    P6i_tmp_0 = 0.0;
    theta6 = 0.0;
    XEi = 0.0;
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      P6i_tmp_6 = (i << 2) + P6i_tmp_7;
      tmp_2 = _mm_set1_pd(P6i_tmp_5[P6i_tmp_6]);
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(P6i_tmp_3[tmp_1 +
        1], P6i_tmp_3[tmp_1]), tmp_2), _mm_set_pd(P6i_tmp_0, P6i_tmp)));
      P6i_tmp = tmp[0];
      P6i_tmp_0 = tmp[1];
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(P6i_tmp_3[tmp_1 +
        3], P6i_tmp_3[tmp_1 + 2]), tmp_2), _mm_set_pd(XEi, theta6)));
      theta6 = tmp[0];
      XEi = tmp[1];
      P2planar[P6i_tmp_6] = 0.0;
    }

    P6i_tmp_tmp = i << 2;
    P6i_tmp_4[P6i_tmp_tmp + 3] = XEi;
    P6i_tmp_4[P6i_tmp_tmp + 2] = theta6;
    P6i_tmp_4[P6i_tmp_tmp + 1] = P6i_tmp_0;
    P6i_tmp_4[P6i_tmp_tmp] = P6i_tmp;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_tmp = i << 2;
    theta0 = P2planar[P6i_tmp_tmp];
    theta3 = P2planar[P6i_tmp_tmp + 1];
    angToBase = P2planar[P6i_tmp_tmp + 2];
    P6i_tmp_0 = P2planar[P6i_tmp_tmp + 3];
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      P6i_tmp_6 = P6i_tmp_tmp + P6i_tmp_7;
      tmp_2 = _mm_set1_pd(b_b_0[P6i_tmp_6]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_4[tmp_1]), tmp_2),
                         _mm_set_pd(theta3, theta0));
      _mm_storeu_pd(&tmp[0], tmp_0);
      theta0 = tmp[0];
      theta3 = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_4[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(P6i_tmp_0, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      P6i_tmp_0 = tmp[1];
      P6i_tmp_5[P6i_tmp_6] = 0.0;
    }

    P2planar[P6i_tmp_tmp + 3] = P6i_tmp_0;
    P2planar[P6i_tmp_tmp + 2] = angToBase;
    P2planar[P6i_tmp_tmp + 1] = theta3;
    P2planar[P6i_tmp_tmp] = theta0;
    P6i_tmp = P6i_tmp_5[P6i_tmp_tmp];
    P6i_tmp_0 = P6i_tmp_5[P6i_tmp_tmp + 1];
    theta6 = P6i_tmp_5[P6i_tmp_tmp + 2];
    XEi = P6i_tmp_5[P6i_tmp_tmp + 3];
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      P6i_tmp_6 = P6i_tmp_tmp + P6i_tmp_7;
      tmp_2 = _mm_set1_pd(P6i[P6i_tmp_6]);
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(P6i_tmp_3[tmp_1 +
        1], P6i_tmp_3[tmp_1]), tmp_2), _mm_set_pd(P6i_tmp_0, P6i_tmp)));
      P6i_tmp = tmp[0];
      P6i_tmp_0 = tmp[1];
      _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(P6i_tmp_3[tmp_1 +
        3], P6i_tmp_3[tmp_1 + 2]), tmp_2), _mm_set_pd(XEi, theta6)));
      theta6 = tmp[0];
      XEi = tmp[1];
      P4planar[P6i_tmp_6] = 0.0;
    }

    P6i_tmp_5[P6i_tmp_tmp + 3] = XEi;
    P6i_tmp_5[P6i_tmp_tmp + 2] = theta6;
    P6i_tmp_5[P6i_tmp_tmp + 1] = P6i_tmp_0;
    P6i_tmp_5[P6i_tmp_tmp] = P6i_tmp;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_tmp = i << 2;
    theta0 = P4planar[P6i_tmp_tmp];
    theta3 = P4planar[P6i_tmp_tmp + 1];
    angToBase = P4planar[P6i_tmp_tmp + 2];
    P6i_tmp_0 = P4planar[P6i_tmp_tmp + 3];
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      tmp_2 = _mm_set1_pd(c_b_0[P6i_tmp_tmp + P6i_tmp_7]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_5[tmp_1]), tmp_2),
                         _mm_set_pd(theta3, theta0));
      _mm_storeu_pd(&tmp[0], tmp_0);
      theta0 = tmp[0];
      theta3 = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_5[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(P6i_tmp_0, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      P6i_tmp_0 = tmp[1];
    }

    P4planar[P6i_tmp_tmp + 3] = P6i_tmp_0;
    P4planar[P6i_tmp_tmp + 2] = angToBase;
    P4planar[P6i_tmp_tmp + 1] = theta3;
    P4planar[P6i_tmp_tmp] = theta0;
  }

  _mm_storeu_pd(&tmp[0], _mm_sub_pd(_mm_set_pd(P4planar[14], P4planar[12]),
    _mm_set_pd(P2planar[14], P2planar[12])));
  angToBase = tmp[0] * tmp[0];
  P6i_tmp_0 = tmp[1] * tmp[1];
  theta3 = (((((((angToBase * 0.15680000000000002 - 0.0038886400000000022) +
                 P6i_tmp_0 * 0.15680000000000002) - 0.00020735999999999997) +
               angToBase * 0.0288) + P6i_tmp_0 * 0.0288) - rt_powd_snf(tmp[0],
              4.0)) - angToBase * 2.0 * P6i_tmp_0) - rt_powd_snf(tmp[1], 4.0);
  if (theta3 > 0.0) {
    theta3 = atan((0.56 * tmp[1] + sqrt(theta3)) / ((((0.56 * tmp[0] +
      0.078400000000000011) - 0.0144) + angToBase) + P6i_tmp_0)) * 2.0;
    theta0 = (angToBase - 0.0256) + P6i_tmp_0;
    theta6 = atan(sqrt(((0.16 - angToBase) - P6i_tmp_0) * theta0) / theta0) *
      -2.0;
  } else {
    theta3 = 0.0;
    theta6 = 0.0;
  }

  theta3 += 3.1415926535897931 - (3.1415926535897931 -
    rtU.stepperLeftActualPosition);
  XEi = sin(rtU.baseActualPosition);
  theta2 = cos(rtU.baseActualPosition);
  angToBase = sin(theta3);
  theta3 = cos(theta3);
  P6i_tmp = sin(theta6);
  theta6 = cos(theta6);
  P6i_tmp_0 = sin(-rtU.gripperPitchActualPosition);
  theta0 = cos(-rtU.gripperPitchActualPosition);
  P6i_tmp_4[0] = theta2;
  P6i_tmp_4[4] = -XEi;
  P6i_tmp_4[8] = 0.0;
  P6i_tmp_4[12] = 0.0;
  P6i_tmp_4[1] = XEi;
  P6i_tmp_4[5] = theta2;
  P6i_tmp_4[9] = 0.0;
  P6i_tmp_4[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_tmp = i << 2;
    P6i_tmp_4[P6i_tmp_tmp + 2] = P6i_tmp_2[i];
    P6i_tmp_4[P6i_tmp_tmp + 3] = P6i_tmp_1[i];
    P6i_tmp_5[P6i_tmp_tmp] = 0.0;
    P6i_tmp_5[P6i_tmp_tmp + 1] = 0.0;
    P6i_tmp_5[P6i_tmp_tmp + 2] = 0.0;
    P6i_tmp_5[P6i_tmp_tmp + 3] = 0.0;
  }

  P4planar[0] = theta3;
  P4planar[4] = -angToBase;
  P4planar[8] = 0.0;
  P4planar[12] = 0.12;
  P4planar[1] = angToBase;
  P4planar[5] = theta3;
  P4planar[9] = 0.0;
  P4planar[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_tmp = i << 2;
    P4planar[P6i_tmp_tmp + 2] = P6i_tmp_2[i];
    P4planar[P6i_tmp_tmp + 3] = P6i_tmp_1[i];
    theta2 = P6i_tmp_5[P6i_tmp_tmp];
    theta3 = P6i_tmp_5[P6i_tmp_tmp + 1];
    angToBase = P6i_tmp_5[P6i_tmp_tmp + 2];
    XEi = P6i_tmp_5[P6i_tmp_tmp + 3];
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      P6i_tmp_6 = P6i_tmp_tmp + P6i_tmp_7;
      tmp_2 = _mm_set1_pd(P6i[P6i_tmp_6]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_4[tmp_1]), tmp_2),
                         _mm_set_pd(theta3, theta2));
      _mm_storeu_pd(&tmp[0], tmp_0);
      theta2 = tmp[0];
      theta3 = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_4[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(XEi, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      XEi = tmp[1];
      P2planar[P6i_tmp_6] = 0.0;
    }

    P6i_tmp_5[P6i_tmp_tmp + 3] = XEi;
    P6i_tmp_5[P6i_tmp_tmp + 2] = angToBase;
    P6i_tmp_5[P6i_tmp_tmp + 1] = theta3;
    P6i_tmp_5[P6i_tmp_tmp] = theta2;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_tmp = i << 2;
    theta2 = P2planar[P6i_tmp_tmp];
    theta3 = P2planar[P6i_tmp_tmp + 1];
    angToBase = P2planar[P6i_tmp_tmp + 2];
    XEi = P2planar[P6i_tmp_tmp + 3];
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      tmp_2 = _mm_set1_pd(P4planar[P6i_tmp_tmp + P6i_tmp_7]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_5[tmp_1]), tmp_2),
                         _mm_set_pd(theta3, theta2));
      _mm_storeu_pd(&tmp[0], tmp_0);
      theta2 = tmp[0];
      theta3 = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_5[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(XEi, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      XEi = tmp[1];
    }

    P2planar[P6i_tmp_tmp + 3] = XEi;
    P2planar[P6i_tmp_tmp + 2] = angToBase;
    P2planar[P6i_tmp_tmp + 1] = theta3;
    P2planar[P6i_tmp_tmp] = theta2;
  }

  P6i[0] = theta6;
  P6i[4] = -P6i_tmp;
  P6i[8] = 0.0;
  P6i[12] = 0.28;
  P6i[1] = P6i_tmp;
  P6i[5] = theta6;
  P6i[9] = 0.0;
  P6i[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_tmp = i << 2;
    P6i[P6i_tmp_tmp + 2] = P6i_tmp_2[i];
    P6i[P6i_tmp_tmp + 3] = P6i_tmp_1[i];
    theta2 = 0.0;
    theta3 = 0.0;
    angToBase = 0.0;
    XEi = 0.0;
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      tmp_2 = _mm_set1_pd(P6i[P6i_tmp_tmp + P6i_tmp_7]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P2planar[tmp_1]), tmp_2),
                         _mm_set_pd(theta3, theta2));
      _mm_storeu_pd(&tmp[0], tmp_0);
      theta2 = tmp[0];
      theta3 = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P2planar[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(XEi, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      XEi = tmp[1];
    }

    P6i_tmp_4[P6i_tmp_tmp + 3] = XEi;
    P6i_tmp_4[P6i_tmp_tmp + 2] = angToBase;
    P6i_tmp_4[P6i_tmp_tmp + 1] = theta3;
    P6i_tmp_4[P6i_tmp_tmp] = theta2;
  }

  P6i[0] = theta0;
  P6i[4] = -P6i_tmp_0;
  P6i[8] = 0.0;
  P6i[12] = 0.62;
  P6i[1] = P6i_tmp_0;
  P6i[5] = theta0;
  P6i[9] = 0.0;
  P6i[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_tmp = i << 2;
    P6i[P6i_tmp_tmp + 2] = P6i_tmp_2[i];
    P6i[P6i_tmp_tmp + 3] = P6i_tmp_1[i];
    theta2 = 0.0;
    theta3 = 0.0;
    angToBase = 0.0;
    XEi = 0.0;
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      tmp_2 = _mm_set1_pd(P6i[P6i_tmp_tmp + P6i_tmp_7]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_4[tmp_1]), tmp_2),
                         _mm_set_pd(theta3, theta2));
      _mm_storeu_pd(&tmp[0], tmp_0);
      theta2 = tmp[0];
      theta3 = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_4[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(XEi, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      XEi = tmp[1];
    }

    P6i_tmp_5[P6i_tmp_tmp + 3] = XEi;
    P6i_tmp_5[P6i_tmp_tmp + 2] = angToBase;
    P6i_tmp_5[P6i_tmp_tmp + 1] = theta3;
    P6i_tmp_5[P6i_tmp_tmp] = theta2;
  }

  for (i = 0; i < 4; i++) {
    theta0 = 0.0;
    theta3 = 0.0;
    angToBase = 0.0;
    P6i_tmp_0 = 0.0;
    for (P6i_tmp_7 = 0; P6i_tmp_7 < 4; P6i_tmp_7++) {
      tmp_1 = P6i_tmp_7 << 2;
      tmp_2 = _mm_set1_pd(c_b[(i << 2) + P6i_tmp_7]);
      tmp_0 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_5[tmp_1]), tmp_2),
                         _mm_set_pd(theta3, theta0));
      _mm_storeu_pd(&tmp[0], tmp_0);
      theta0 = tmp[0];
      theta3 = tmp[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P6i_tmp_5[tmp_1 + 2]), tmp_2),
                         _mm_set_pd(P6i_tmp_0, angToBase));
      _mm_storeu_pd(&tmp[0], tmp_2);
      angToBase = tmp[0];
      P6i_tmp_0 = tmp[1];
    }

    P6i_tmp_tmp = i << 2;
    P2planar[P6i_tmp_tmp + 3] = P6i_tmp_0;
    P2planar[P6i_tmp_tmp + 2] = angToBase;
    P2planar[P6i_tmp_tmp + 1] = theta3;
    P2planar[P6i_tmp_tmp] = theta0;
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/x'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  theta0 = P2planar[12] - rtU.x;

  /* DotProduct: '<S3>/Dot Product' */
  theta3 = theta0 * theta0;

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/y'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  theta0 = P2planar[13] - rtU.y;

  /* DotProduct: '<S3>/Dot Product' */
  theta3 += theta0 * theta0;

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
  rtY.pointReached = (sqrt(theta0 * theta0 + theta3) <= 0.002);

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
