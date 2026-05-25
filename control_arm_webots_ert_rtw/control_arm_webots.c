/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_arm_webots.c
 *
 * Code generated for Simulink model 'control_arm_webots'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon May 25 10:08:36 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "control_arm_webots.h"
#include "rtwtypes.h"
#include <math.h>
#include <emmintrin.h>
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
static void MATLABFunction1(real_T rtu_current, real_T rtu_startPosition, real_T
  rtu_desired, real_T rtu_timePerMovement, real_T rtu_deltaTime, real_T *rty_out);
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
 *    '<S1>/MATLAB Function1'
 *    '<S1>/MATLAB Function2'
 *    '<S1>/MATLAB Function3'
 *    '<S1>/MATLAB Function5'
 */
static void MATLABFunction1(real_T rtu_current, real_T rtu_startPosition, real_T
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
void control_arm_webots_step(void)
{
  real_T P6i[16];
  real_T XEi;
  real_T angToBase;
  real_T theta0;
  real_T theta2;
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

  __m128d tmp_1;
  __m128d tmp_2;
  real_T b_a_0[16];
  real_T b_a_1[16];
  real_T rtb_angles[5];
  real_T tmp_0[2];
  real_T P6i_0;
  real_T P6i_1;
  real_T rtb_Sum10;
  real_T rtb_Sum11;
  real_T rtb_out_k;
  real_T tmp;
  int32_T P6i_tmp_1;
  int32_T P6i_tmp_2;
  int32_T i;
  int32_T i_0;
  int32_T rtb_out_b_tmp;
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
  XEi = sin(angToBase);
  rtb_out_k = cos(angToBase);
  P2planar[0] = rtb_out_k;
  P2planar[4] = -XEi;
  P2planar[8] = 0.0;
  P2planar[12] = rtU.x;
  P2planar[1] = XEi;
  P2planar[5] = rtb_out_k;
  P2planar[9] = 0.0;
  P2planar[13] = rtU.y;
  P2planar[2] = 0.0;
  P2planar[6] = 0.0;
  P2planar[10] = 1.0;
  P2planar[14] = rtU.z;
  b_a_0[0] = cos(rtU.gripperAng);
  b_a_0[4] = -sin(rtU.gripperAng);
  b_a_0[8] = 0.0;
  b_a_0[12] = 0.0;
  b_a_0[1] = sin(rtU.gripperAng);
  b_a_0[5] = cos(rtU.gripperAng);
  b_a_0[9] = 0.0;
  b_a_0[13] = 0.0;
  for (i = 0; i < 4; i++) {
    /* MATLAB Function: '<S1>/MATLAB Function4' */
    P6i_tmp_1 = b[i];
    P6i_tmp[i] = (int8_T)P6i_tmp_1;

    /* MATLAB Function: '<S1>/MATLAB Function4' */
    P6i_tmp_2 = c[i];
    P6i_tmp_0[i] = (int8_T)P6i_tmp_2;
    rtb_out_b_tmp = i << 2;
    P2planar[rtb_out_b_tmp + 3] = P6i_tmp_1;
    b_a_0[rtb_out_b_tmp + 2] = P6i_tmp_2;
    b_a_0[rtb_out_b_tmp + 3] = P6i_tmp_1;
    P4planar[rtb_out_b_tmp] = 0.0;
    P4planar[rtb_out_b_tmp + 1] = 0.0;
    P4planar[rtb_out_b_tmp + 2] = 0.0;
    P4planar[rtb_out_b_tmp + 3] = 0.0;
  }

  for (i = 0; i < 4; i++) {
    rtb_out_b_tmp = i << 2;
    rtb_out_k = P4planar[rtb_out_b_tmp];
    angToBase = P4planar[rtb_out_b_tmp + 1];
    XEi = P4planar[rtb_out_b_tmp + 2];
    theta2 = P4planar[rtb_out_b_tmp + 3];
    for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
      i_0 = P6i_tmp_2 << 2;
      P6i_tmp_1 = rtb_out_b_tmp + P6i_tmp_2;
      tmp_2 = _mm_set1_pd(b_b[P6i_tmp_1]);
      tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P2planar[i_0]), tmp_2),
                         _mm_set_pd(angToBase, rtb_out_k));
      _mm_storeu_pd(&tmp_0[0], tmp_1);
      rtb_out_k = tmp_0[0];
      angToBase = tmp_0[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P2planar[i_0 + 2]), tmp_2),
                         _mm_set_pd(theta2, XEi));
      _mm_storeu_pd(&tmp_0[0], tmp_2);
      XEi = tmp_0[0];
      theta2 = tmp_0[1];
      b_a_1[P6i_tmp_1] = 0.0;
    }

    P4planar[rtb_out_b_tmp + 3] = theta2;
    P4planar[rtb_out_b_tmp + 2] = XEi;
    P4planar[rtb_out_b_tmp + 1] = angToBase;
    P4planar[rtb_out_b_tmp] = rtb_out_k;
    P6i_0 = b_a_1[rtb_out_b_tmp];
    P6i_1 = b_a_1[rtb_out_b_tmp + 1];
    rtb_Sum10 = b_a_1[rtb_out_b_tmp + 2];
    tmp = b_a_1[rtb_out_b_tmp + 3];
    for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
      i_0 = P6i_tmp_2 << 2;
      P6i_tmp_1 = rtb_out_b_tmp + P6i_tmp_2;
      tmp_2 = _mm_set1_pd(c_b[P6i_tmp_1]);
      tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_0[i_0]), tmp_2),
                         _mm_set_pd(P6i_1, P6i_0));
      _mm_storeu_pd(&tmp_0[0], tmp_1);
      P6i_0 = tmp_0[0];
      P6i_1 = tmp_0[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_0[i_0 + 2]), tmp_2),
                         _mm_set_pd(tmp, rtb_Sum10));
      _mm_storeu_pd(&tmp_0[0], tmp_2);
      rtb_Sum10 = tmp_0[0];
      tmp = tmp_0[1];
      P6i[P6i_tmp_1] = 0.0;
    }

    b_a_1[rtb_out_b_tmp + 3] = tmp;
    b_a_1[rtb_out_b_tmp + 2] = rtb_Sum10;
    b_a_1[rtb_out_b_tmp + 1] = P6i_1;
    b_a_1[rtb_out_b_tmp] = P6i_0;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_1 = i << 2;
    rtb_Sum11 = P6i[P6i_tmp_1];
    P6i_0 = P6i[P6i_tmp_1 + 1];
    P6i_1 = P6i[P6i_tmp_1 + 2];
    XE = P6i[P6i_tmp_1 + 3];
    for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
      i_0 = P6i_tmp_2 << 2;
      tmp_2 = _mm_set1_pd(b_a_1[P6i_tmp_1 + P6i_tmp_2]);
      tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P4planar[i_0]), tmp_2),
                         _mm_set_pd(P6i_0, rtb_Sum11));
      _mm_storeu_pd(&tmp_0[0], tmp_1);
      rtb_Sum11 = tmp_0[0];
      P6i_0 = tmp_0[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P4planar[i_0 + 2]), tmp_2),
                         _mm_set_pd(XE, P6i_1));
      _mm_storeu_pd(&tmp_0[0], tmp_2);
      P6i_1 = tmp_0[0];
      XE = tmp_0[1];
    }

    P6i[P6i_tmp_1 + 3] = XE;
    P6i[P6i_tmp_1 + 2] = P6i_1;
    P6i[P6i_tmp_1 + 1] = P6i_0;
    P6i[P6i_tmp_1] = rtb_Sum11;
  }

  XEi = sqrt(P6i[12] * P6i[12] + P6i[13] * P6i[13]);
  P6i_0 = XEi * XEi;
  P6i_1 = (P6i[14] - 0.065) * (P6i[14] - 0.065);
  rtb_Sum10 = (((((((P6i_0 * 0.24499999999999997 + 0.04624375) + P6i_1 *
                    0.24499999999999997) - 0.0625) + P6i_0 * 0.5) + P6i_1 * 0.5)
                - rt_powd_snf(XEi, 4.0)) - P6i_0 * 2.0 * P6i_1) - rt_powd_snf
    (P6i[14] - 0.065, 4.0);
  if (rtb_Sum10 < 0.0) {
    for (i = 0; i < 5; i++) {
      rtb_angles[i] = d[i];
    }

    /* Outport: '<Root>/error' */
    rtY.error = 1.0;
  } else {
    tmp = (P6i_0 - 0.02250000000000002) + P6i_1;
    _mm_storeu_pd(&tmp_0[0], _mm_mul_pd(_mm_set_pd(atan(sqrt(tmp *
      ((0.72249999999999992 - P6i_0) - P6i_1)) / tmp), atan((sqrt(rtb_Sum10) +
      (P6i[14] - 0.065) * 0.7) / ((((0.7 * XEi + 0.12249999999999998) - 0.25) +
      P6i_0) + P6i_1))), _mm_set_pd(-2.0, 2.0)));
    angToBase = tmp_0[0];
    theta2 = tmp_0[1];
    XEi = sin(tmp_0[0]);
    rtb_out_k = cos(tmp_0[0]);
    rtb_Sum11 = sin(tmp_0[1]);
    P6i_0 = cos(tmp_0[1]);
    P2planar[0] = rtb_out_k;
    P2planar[4] = -XEi;
    P2planar[8] = 0.0;
    P2planar[12] = 0.0;
    P2planar[1] = XEi;
    P2planar[5] = rtb_out_k;
    P2planar[9] = 0.0;
    P2planar[13] = 0.0;
    for (i = 0; i < 4; i++) {
      rtb_out_b_tmp = i << 2;
      P2planar[rtb_out_b_tmp + 2] = P6i_tmp_0[i];
      P2planar[rtb_out_b_tmp + 3] = P6i_tmp[i];
      rtb_out_k = 0.0;
      XEi = 0.0;
      P6i_1 = 0.0;
      XE = 0.0;
      for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
        i_0 = P6i_tmp_2 << 2;
        tmp_2 = _mm_set1_pd(P2planar[rtb_out_b_tmp + P6i_tmp_2]);
        _mm_storeu_pd(&tmp_0[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&a[i_0]),
          tmp_2), _mm_set_pd(XEi, rtb_out_k)));
        rtb_out_k = tmp_0[0];
        XEi = tmp_0[1];
        _mm_storeu_pd(&tmp_0[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&a[i_0 + 2]),
          tmp_2), _mm_set_pd(XE, P6i_1)));
        P6i_1 = tmp_0[0];
        XE = tmp_0[1];
      }

      P6i[rtb_out_b_tmp + 3] = XE;
      P6i[rtb_out_b_tmp + 2] = P6i_1;
      P6i[rtb_out_b_tmp + 1] = XEi;
      P6i[rtb_out_b_tmp] = rtb_out_k;
    }

    P2planar[0] = P6i_0;
    P2planar[4] = -rtb_Sum11;
    P2planar[8] = 0.0;
    P2planar[12] = 0.35;
    P2planar[1] = rtb_Sum11;
    P2planar[5] = P6i_0;
    P2planar[9] = 0.0;
    P2planar[13] = 0.0;
    for (i = 0; i < 4; i++) {
      rtb_out_b_tmp = i << 2;
      P2planar[rtb_out_b_tmp + 2] = P6i_tmp_0[i];
      P2planar[rtb_out_b_tmp + 3] = P6i_tmp[i];
      rtb_Sum11 = 0.0;
      P6i_0 = 0.0;
      P6i_1 = 0.0;
      XE = 0.0;
      for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
        i_0 = P6i_tmp_2 << 2;
        P6i_tmp_1 = rtb_out_b_tmp + P6i_tmp_2;
        tmp_2 = _mm_set1_pd(P6i[P6i_tmp_1]);
        _mm_storeu_pd(&tmp_0[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(c_a[i_0 + 1],
          c_a[i_0]), tmp_2), _mm_set_pd(P6i_0, rtb_Sum11)));
        rtb_Sum11 = tmp_0[0];
        P6i_0 = tmp_0[1];
        _mm_storeu_pd(&tmp_0[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(c_a[i_0 + 3],
          c_a[i_0 + 2]), tmp_2), _mm_set_pd(XE, P6i_1)));
        P6i_1 = tmp_0[0];
        XE = tmp_0[1];
        b_a_1[P6i_tmp_1] = 0.0;
      }

      b_a_0[rtb_out_b_tmp + 3] = XE;
      b_a_0[rtb_out_b_tmp + 2] = P6i_1;
      b_a_0[rtb_out_b_tmp + 1] = P6i_0;
      b_a_0[rtb_out_b_tmp] = rtb_Sum11;
    }

    for (i = 0; i < 4; i++) {
      P6i_tmp_1 = i << 2;
      rtb_Sum11 = b_a_1[P6i_tmp_1];
      P6i_0 = b_a_1[P6i_tmp_1 + 1];
      P6i_1 = b_a_1[P6i_tmp_1 + 2];
      XE = b_a_1[P6i_tmp_1 + 3];
      for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
        i_0 = P6i_tmp_2 << 2;
        tmp_2 = _mm_set1_pd(P2planar[P6i_tmp_1 + P6i_tmp_2]);
        tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_0[i_0]), tmp_2),
                           _mm_set_pd(P6i_0, rtb_Sum11));
        _mm_storeu_pd(&tmp_0[0], tmp_1);
        rtb_Sum11 = tmp_0[0];
        P6i_0 = tmp_0[1];
        tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_0[i_0 + 2]), tmp_2),
                           _mm_set_pd(XE, P6i_1));
        _mm_storeu_pd(&tmp_0[0], tmp_2);
        P6i_1 = tmp_0[0];
        XE = tmp_0[1];
      }

      b_a_1[P6i_tmp_1 + 3] = XE;
      b_a_1[P6i_tmp_1 + 2] = P6i_1;
      b_a_1[P6i_tmp_1 + 1] = P6i_0;
      b_a_1[P6i_tmp_1] = rtb_Sum11;
    }

    for (i = 0; i < 4; i++) {
      rtb_Sum11 = 0.0;
      P6i_0 = 0.0;
      P6i_1 = 0.0;
      XE = 0.0;
      for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
        i_0 = P6i_tmp_2 << 2;
        tmp_2 = _mm_set1_pd(d_b[(i << 2) + P6i_tmp_2]);
        tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_1[i_0]), tmp_2),
                           _mm_set_pd(P6i_0, rtb_Sum11));
        _mm_storeu_pd(&tmp_0[0], tmp_1);
        rtb_Sum11 = tmp_0[0];
        P6i_0 = tmp_0[1];
        tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_1[i_0 + 2]), tmp_2),
                           _mm_set_pd(XE, P6i_1));
        _mm_storeu_pd(&tmp_0[0], tmp_2);
        P6i_1 = tmp_0[0];
        XE = tmp_0[1];
      }

      P6i_tmp_1 = i << 2;
      P6i[P6i_tmp_1 + 3] = XE;
      P6i[P6i_tmp_1 + 2] = P6i_1;
      P6i[P6i_tmp_1 + 1] = P6i_0;
      P6i[P6i_tmp_1] = rtb_Sum11;
    }

    rtb_angles[0] = theta0;
    rtb_angles[1] = angToBase;
    rtb_angles[3] = (-rtU.gripperAng - angToBase) - theta2;
    theta0 = P6i[12] * P6i[12];
    angToBase = (P6i[14] - 0.149) * (P6i[14] - 0.149);
    rtb_angles[4] = atan((sqrt((((((((theta0 * 0.0288 + 0.00205056) + angToBase *
      0.0288) - 0.0061465600000000023) + theta0 * 0.15680000000000002) +
      angToBase * 0.15680000000000002) - rt_powd_snf(P6i[12], 4.0)) - theta0 *
      2.0 * angToBase) - rt_powd_snf(P6i[14] - 0.149, 4.0)) + (P6i[14] - 0.149) *
                          0.24) / ((((0.24 * P6i[12] + 0.0144) -
      0.078400000000000011) + theta0) + angToBase)) * 2.0;

    /* Outport: '<Root>/error' */
    rtY.error = 0.0;
  }

  /* End of MATLAB Function: '<S1>/inverse kinematics' */

  /* MATLAB Function: '<S1>/MATLAB Function5' incorporates:
   *  Gain: '<S1>/Gain'
   *  Inport: '<Root>/deltaTime'
   *  Inport: '<Root>/gripperPitchOldPosition'
   *  Inport: '<Root>/timePerMovement'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  MATLABFunction1(rtDW.UnitDelay_DSTATE, rtU.gripperPitchOldPosition,
                  -rtb_angles[3], rtU.timePerMovement, rtU.deltaTime, &theta0);

  /* Outport: '<Root>/controlGripperPitch' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtY.controlGripperPitch = rtDW.UnitDelay_DSTATE;

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Pi'
   *  Constant: '<S1>/Pi3'
   *  Gain: '<S1>/Gain2'
   *  Sum: '<S1>/Sum1'
   *  Sum: '<S1>/Sum7'
   */
  if (rtb_angles[4] >= 0.0) {
    angToBase = 3.1415926535897931 - rtb_angles[4];
  } else {
    angToBase = -(rtb_angles[4] + 3.1415926535897931);
  }

  /* End of Switch: '<S1>/Switch' */

  /* MATLAB Function: '<S1>/MATLAB Function2' incorporates:
   *  Inport: '<Root>/deltaTime'
   *  Inport: '<Root>/stepperLeftOldPosition'
   *  Inport: '<Root>/timePerMovement'
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  MATLABFunction1(rtDW.UnitDelay2_DSTATE, rtU.stepperLeftOldPosition, angToBase,
                  rtU.timePerMovement, rtU.deltaTime, &XEi);

  /* Outport: '<Root>/controlStepperLeft' incorporates:
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  rtY.controlStepperLeft = rtDW.UnitDelay2_DSTATE;

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Gain: '<S1>/Gain3'
   *  Inport: '<Root>/baseOldPosition'
   *  Inport: '<Root>/deltaTime'
   *  Inport: '<Root>/timePerMovement'
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  MATLABFunction1(rtDW.UnitDelay1_DSTATE, rtU.baseOldPosition, -rtb_angles[0],
                  rtU.timePerMovement, rtU.deltaTime, &angToBase);

  /* Outport: '<Root>/controlBase' incorporates:
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  rtY.controlBase = rtDW.UnitDelay1_DSTATE;

  /* MATLAB Function: '<S1>/MATLAB Function3' incorporates:
   *  Constant: '<S1>/Pi1'
   *  Inport: '<Root>/deltaTime'
   *  Inport: '<Root>/stepperRightOldPosition'
   *  Inport: '<Root>/timePerMovement'
   *  Sum: '<S1>/Sum9'
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  MATLABFunction1(rtDW.UnitDelay3_DSTATE, rtU.stepperRightOldPosition,
                  1.5707963267948966 - rtb_angles[1], rtU.timePerMovement,
                  rtU.deltaTime, &rtb_out_k);

  /* Outport: '<Root>/controlStepperRight' incorporates:
   *  UnitDelay: '<S1>/Unit Delay3'
   */
  rtY.controlStepperRight = rtDW.UnitDelay3_DSTATE;

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
  P6i_0 = sin(3.1415926535897931 - rtU.stepperLeftActualPosition);
  XE = cos(3.1415926535897931 - rtU.stepperLeftActualPosition);
  b_a_1[0] = XE;
  b_a_1[4] = -P6i_0;
  b_a_1[8] = 0.0;
  b_a_1[12] = 0.0;
  b_a_1[1] = P6i_0;
  b_a_1[5] = XE;
  b_a_1[9] = 0.0;
  b_a_1[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_1 = i << 2;
    b_a_1[P6i_tmp_1 + 2] = P6i_tmp_0[i];
    b_a_1[P6i_tmp_1 + 3] = P6i_tmp[i];
    rtb_Sum11 = 0.0;
    P6i_0 = 0.0;
    P6i_1 = 0.0;
    XE = 0.0;
    for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
      i_0 = P6i_tmp_2 << 2;
      tmp_2 = _mm_set1_pd(b_a_1[P6i_tmp_1 + P6i_tmp_2]);
      _mm_storeu_pd(&tmp_0[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&a_0[i_0]),
        tmp_2), _mm_set_pd(P6i_0, rtb_Sum11)));
      rtb_Sum11 = tmp_0[0];
      P6i_0 = tmp_0[1];
      _mm_storeu_pd(&tmp_0[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&a_0[i_0 + 2]),
        tmp_2), _mm_set_pd(XE, P6i_1)));
      P6i_1 = tmp_0[0];
      XE = tmp_0[1];
    }

    P6i[P6i_tmp_1 + 3] = XE;
    P6i[P6i_tmp_1 + 2] = P6i_1;
    P6i[P6i_tmp_1 + 1] = P6i_0;
    P6i[P6i_tmp_1] = rtb_Sum11;
  }

  P6i_0 = sin(1.5707963267948966 - rtU.stepperRightActualPosition);
  rtb_Sum10 = cos(1.5707963267948966 - rtU.stepperRightActualPosition);
  for (i = 0; i < 16; i++) {
    P2planar_tmp[i] = c_a[i];
  }

  P2planar[0] = rtb_Sum10;
  P2planar[4] = -P6i_0;
  P2planar[8] = 0.0;
  P2planar[12] = 0.0;
  P2planar[1] = P6i_0;
  P2planar[5] = rtb_Sum10;
  P2planar[9] = 0.0;
  P2planar[13] = 0.0;
  for (i = 0; i < 4; i++) {
    rtb_out_b_tmp = i << 2;
    P2planar[rtb_out_b_tmp + 2] = P6i_tmp_0[i];
    P2planar[rtb_out_b_tmp + 3] = P6i_tmp[i];
    rtb_Sum11 = 0.0;
    P6i_0 = 0.0;
    P6i_1 = 0.0;
    XE = 0.0;
    for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
      i_0 = P6i_tmp_2 << 2;
      tmp_2 = _mm_set1_pd(P2planar[rtb_out_b_tmp + P6i_tmp_2]);
      _mm_storeu_pd(&tmp_0[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a[i_0]),
        tmp_2), _mm_set_pd(P6i_0, rtb_Sum11)));
      rtb_Sum11 = tmp_0[0];
      P6i_0 = tmp_0[1];
      _mm_storeu_pd(&tmp_0[0], _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a[i_0 + 2]),
        tmp_2), _mm_set_pd(XE, P6i_1)));
      P6i_1 = tmp_0[0];
      XE = tmp_0[1];
    }

    b_a_0[rtb_out_b_tmp + 3] = XE;
    b_a_0[rtb_out_b_tmp + 2] = P6i_1;
    b_a_0[rtb_out_b_tmp + 1] = P6i_0;
    b_a_0[rtb_out_b_tmp] = rtb_Sum11;
  }

  for (i = 0; i < 4; i++) {
    theta2 = 0.0;
    rtb_Sum11 = 0.0;
    P6i_0 = 0.0;
    P6i_1 = 0.0;
    for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
      i_0 = P6i_tmp_2 << 2;
      P6i_tmp_1 = (i << 2) + P6i_tmp_2;
      tmp_2 = _mm_set1_pd(b_a_0[P6i_tmp_1]);
      _mm_storeu_pd(&tmp_0[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(P2planar_tmp[i_0
        + 1], P2planar_tmp[i_0]), tmp_2), _mm_set_pd(rtb_Sum11, theta2)));
      theta2 = tmp_0[0];
      rtb_Sum11 = tmp_0[1];
      _mm_storeu_pd(&tmp_0[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(P2planar_tmp[i_0
        + 3], P2planar_tmp[i_0 + 2]), tmp_2), _mm_set_pd(P6i_1, P6i_0)));
      P6i_0 = tmp_0[0];
      P6i_1 = tmp_0[1];
      P2planar[P6i_tmp_1] = 0.0;
    }

    P6i_tmp_2 = i << 2;
    b_a_1[P6i_tmp_2 + 3] = P6i_1;
    b_a_1[P6i_tmp_2 + 2] = P6i_0;
    b_a_1[P6i_tmp_2 + 1] = rtb_Sum11;
    b_a_1[P6i_tmp_2] = theta2;
  }

  for (i = 0; i < 4; i++) {
    rtb_out_b_tmp = i << 2;
    theta2 = P2planar[rtb_out_b_tmp];
    rtb_Sum11 = P2planar[rtb_out_b_tmp + 1];
    P6i_0 = P2planar[rtb_out_b_tmp + 2];
    P6i_1 = P2planar[rtb_out_b_tmp + 3];
    for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
      i_0 = P6i_tmp_2 << 2;
      P6i_tmp_1 = rtb_out_b_tmp + P6i_tmp_2;
      tmp_2 = _mm_set1_pd(b_b_0[P6i_tmp_1]);
      tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_1[i_0]), tmp_2),
                         _mm_set_pd(rtb_Sum11, theta2));
      _mm_storeu_pd(&tmp_0[0], tmp_1);
      theta2 = tmp_0[0];
      rtb_Sum11 = tmp_0[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_1[i_0 + 2]), tmp_2),
                         _mm_set_pd(P6i_1, P6i_0));
      _mm_storeu_pd(&tmp_0[0], tmp_2);
      P6i_0 = tmp_0[0];
      P6i_1 = tmp_0[1];
      b_a_0[P6i_tmp_1] = 0.0;
    }

    P2planar[rtb_out_b_tmp + 3] = P6i_1;
    P2planar[rtb_out_b_tmp + 2] = P6i_0;
    P2planar[rtb_out_b_tmp + 1] = rtb_Sum11;
    P2planar[rtb_out_b_tmp] = theta2;
    theta2 = b_a_0[rtb_out_b_tmp];
    rtb_Sum11 = b_a_0[rtb_out_b_tmp + 1];
    P6i_0 = b_a_0[rtb_out_b_tmp + 2];
    P6i_1 = b_a_0[rtb_out_b_tmp + 3];
    for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
      i_0 = P6i_tmp_2 << 2;
      P6i_tmp_1 = rtb_out_b_tmp + P6i_tmp_2;
      tmp_2 = _mm_set1_pd(P6i[P6i_tmp_1]);
      _mm_storeu_pd(&tmp_0[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(P2planar_tmp[i_0
        + 1], P2planar_tmp[i_0]), tmp_2), _mm_set_pd(rtb_Sum11, theta2)));
      theta2 = tmp_0[0];
      rtb_Sum11 = tmp_0[1];
      _mm_storeu_pd(&tmp_0[0], _mm_add_pd(_mm_mul_pd(_mm_set_pd(P2planar_tmp[i_0
        + 3], P2planar_tmp[i_0 + 2]), tmp_2), _mm_set_pd(P6i_1, P6i_0)));
      P6i_0 = tmp_0[0];
      P6i_1 = tmp_0[1];
      P4planar[P6i_tmp_1] = 0.0;
    }

    b_a_0[rtb_out_b_tmp + 3] = P6i_1;
    b_a_0[rtb_out_b_tmp + 2] = P6i_0;
    b_a_0[rtb_out_b_tmp + 1] = rtb_Sum11;
    b_a_0[rtb_out_b_tmp] = theta2;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_1 = i << 2;
    theta2 = P4planar[P6i_tmp_1];
    rtb_Sum11 = P4planar[P6i_tmp_1 + 1];
    P6i_0 = P4planar[P6i_tmp_1 + 2];
    P6i_1 = P4planar[P6i_tmp_1 + 3];
    for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
      i_0 = P6i_tmp_2 << 2;
      tmp_2 = _mm_set1_pd(c_b_0[P6i_tmp_1 + P6i_tmp_2]);
      tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_0[i_0]), tmp_2),
                         _mm_set_pd(rtb_Sum11, theta2));
      _mm_storeu_pd(&tmp_0[0], tmp_1);
      theta2 = tmp_0[0];
      rtb_Sum11 = tmp_0[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_0[i_0 + 2]), tmp_2),
                         _mm_set_pd(P6i_1, P6i_0));
      _mm_storeu_pd(&tmp_0[0], tmp_2);
      P6i_0 = tmp_0[0];
      P6i_1 = tmp_0[1];
    }

    P4planar[P6i_tmp_1 + 3] = P6i_1;
    P4planar[P6i_tmp_1 + 2] = P6i_0;
    P4planar[P6i_tmp_1 + 1] = rtb_Sum11;
    P4planar[P6i_tmp_1] = theta2;
  }

  _mm_storeu_pd(&tmp_0[0], _mm_sub_pd(_mm_set_pd(P4planar[14], P4planar[12]),
    _mm_set_pd(P2planar[14], P2planar[12])));
  P6i_0 = tmp_0[0] * tmp_0[0];
  P6i_1 = tmp_0[1] * tmp_0[1];
  rtb_Sum10 = (((((((P6i_0 * 0.15680000000000002 - 0.0038886400000000022) +
                    P6i_1 * 0.15680000000000002) - 0.00020735999999999997) +
                  P6i_0 * 0.0288) + P6i_1 * 0.0288) - rt_powd_snf(tmp_0[0], 4.0))
               - P6i_0 * 2.0 * P6i_1) - rt_powd_snf(tmp_0[1], 4.0);
  if (rtb_Sum10 > 0.0) {
    rtb_Sum10 = atan((0.56 * tmp_0[1] + sqrt(rtb_Sum10)) / ((((0.56 * tmp_0[0] +
      0.078400000000000011) - 0.0144) + P6i_0) + P6i_1)) * 2.0;
    theta2 = (P6i_0 - 0.0256) + P6i_1;
    XE = atan(sqrt(((0.16 - P6i_0) - P6i_1) * theta2) / theta2) * -2.0;
  } else {
    rtb_Sum10 = 0.0;
    XE = 0.0;
  }

  rtb_Sum10 += 3.1415926535897931 - (3.1415926535897931 -
    rtU.stepperLeftActualPosition);
  P6i_0 = sin(rtb_Sum10);
  rtb_Sum10 = cos(rtb_Sum10);
  rtb_Sum11 = sin(XE);
  XE = cos(XE);
  YE = sin(-rtU.gripperPitchActualPosition);
  theta2 = cos(-rtU.gripperPitchActualPosition);
  b_a_0[0] = cos(rtU.baseActualPosition);
  b_a_0[4] = -sin(rtU.baseActualPosition);
  b_a_0[8] = 0.0;
  b_a_0[12] = 0.0;
  b_a_0[1] = sin(rtU.baseActualPosition);
  b_a_0[5] = cos(rtU.baseActualPosition);
  b_a_0[9] = 0.0;
  b_a_0[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_2 = i << 2;
    b_a_0[P6i_tmp_2 + 2] = P6i_tmp_0[i];
    b_a_0[P6i_tmp_2 + 3] = P6i_tmp[i];
    b_a_1[P6i_tmp_2] = 0.0;
    b_a_1[P6i_tmp_2 + 1] = 0.0;
    b_a_1[P6i_tmp_2 + 2] = 0.0;
    b_a_1[P6i_tmp_2 + 3] = 0.0;
  }

  P2planar[0] = rtb_Sum10;
  P2planar[4] = -P6i_0;
  P2planar[8] = 0.0;
  P2planar[12] = 0.12;
  P2planar[1] = P6i_0;
  P2planar[5] = rtb_Sum10;
  P2planar[9] = 0.0;
  P2planar[13] = 0.0;
  for (i = 0; i < 4; i++) {
    rtb_out_b_tmp = i << 2;
    P2planar[rtb_out_b_tmp + 2] = P6i_tmp_0[i];
    P2planar[rtb_out_b_tmp + 3] = P6i_tmp[i];
    P6i_0 = b_a_1[rtb_out_b_tmp];
    P6i_1 = b_a_1[rtb_out_b_tmp + 1];
    rtb_Sum10 = b_a_1[rtb_out_b_tmp + 2];
    tmp = b_a_1[rtb_out_b_tmp + 3];
    for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
      i_0 = P6i_tmp_2 << 2;
      P6i_tmp_1 = rtb_out_b_tmp + P6i_tmp_2;
      tmp_2 = _mm_set1_pd(P6i[P6i_tmp_1]);
      tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_0[i_0]), tmp_2),
                         _mm_set_pd(P6i_1, P6i_0));
      _mm_storeu_pd(&tmp_0[0], tmp_1);
      P6i_0 = tmp_0[0];
      P6i_1 = tmp_0[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_0[i_0 + 2]), tmp_2),
                         _mm_set_pd(tmp, rtb_Sum10));
      _mm_storeu_pd(&tmp_0[0], tmp_2);
      rtb_Sum10 = tmp_0[0];
      tmp = tmp_0[1];
      P4planar[P6i_tmp_1] = 0.0;
    }

    b_a_1[rtb_out_b_tmp + 3] = tmp;
    b_a_1[rtb_out_b_tmp + 2] = rtb_Sum10;
    b_a_1[rtb_out_b_tmp + 1] = P6i_1;
    b_a_1[rtb_out_b_tmp] = P6i_0;
  }

  for (i = 0; i < 4; i++) {
    P6i_tmp_2 = i << 2;
    P6i_0 = P4planar[P6i_tmp_2];
    P6i_1 = P4planar[P6i_tmp_2 + 1];
    rtb_Sum10 = P4planar[P6i_tmp_2 + 2];
    tmp = P4planar[P6i_tmp_2 + 3];
    for (i_0 = 0; i_0 < 4; i_0++) {
      P6i_tmp_1 = i_0 << 2;
      tmp_2 = _mm_set1_pd(P2planar[P6i_tmp_2 + i_0]);
      tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_1[P6i_tmp_1]), tmp_2),
                         _mm_set_pd(P6i_1, P6i_0));
      _mm_storeu_pd(&tmp_0[0], tmp_1);
      P6i_0 = tmp_0[0];
      P6i_1 = tmp_0[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_1[P6i_tmp_1 + 2]), tmp_2),
                         _mm_set_pd(tmp, rtb_Sum10));
      _mm_storeu_pd(&tmp_0[0], tmp_2);
      rtb_Sum10 = tmp_0[0];
      tmp = tmp_0[1];
    }

    P4planar[P6i_tmp_2 + 3] = tmp;
    P4planar[P6i_tmp_2 + 2] = rtb_Sum10;
    P4planar[P6i_tmp_2 + 1] = P6i_1;
    P4planar[P6i_tmp_2] = P6i_0;
  }

  b_a_1[0] = XE;
  b_a_1[4] = -rtb_Sum11;
  b_a_1[8] = 0.0;
  b_a_1[12] = 0.28;
  b_a_1[1] = rtb_Sum11;
  b_a_1[5] = XE;
  b_a_1[9] = 0.0;
  b_a_1[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_1 = i << 2;
    b_a_1[P6i_tmp_1 + 2] = P6i_tmp_0[i];
    b_a_1[P6i_tmp_1 + 3] = P6i_tmp[i];
    P6i_0 = 0.0;
    P6i_1 = 0.0;
    rtb_Sum10 = 0.0;
    tmp = 0.0;
    for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
      i_0 = P6i_tmp_2 << 2;
      tmp_2 = _mm_set1_pd(b_a_1[P6i_tmp_1 + P6i_tmp_2]);
      tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P4planar[i_0]), tmp_2),
                         _mm_set_pd(P6i_1, P6i_0));
      _mm_storeu_pd(&tmp_0[0], tmp_1);
      P6i_0 = tmp_0[0];
      P6i_1 = tmp_0[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&P4planar[i_0 + 2]), tmp_2),
                         _mm_set_pd(tmp, rtb_Sum10));
      _mm_storeu_pd(&tmp_0[0], tmp_2);
      rtb_Sum10 = tmp_0[0];
      tmp = tmp_0[1];
    }

    b_a_0[P6i_tmp_1 + 3] = tmp;
    b_a_0[P6i_tmp_1 + 2] = rtb_Sum10;
    b_a_0[P6i_tmp_1 + 1] = P6i_1;
    b_a_0[P6i_tmp_1] = P6i_0;
  }

  P6i[0] = theta2;
  P6i[4] = -YE;
  P6i[8] = 0.0;
  P6i[12] = 0.62;
  P6i[1] = YE;
  P6i[5] = theta2;
  P6i[9] = 0.0;
  P6i[13] = 0.0;
  for (i = 0; i < 4; i++) {
    P6i_tmp_1 = i << 2;
    P6i[P6i_tmp_1 + 2] = P6i_tmp_0[i];
    P6i[P6i_tmp_1 + 3] = P6i_tmp[i];
    P6i_0 = 0.0;
    P6i_1 = 0.0;
    rtb_Sum10 = 0.0;
    tmp = 0.0;
    for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
      i_0 = P6i_tmp_2 << 2;
      tmp_2 = _mm_set1_pd(P6i[P6i_tmp_1 + P6i_tmp_2]);
      tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_0[i_0]), tmp_2),
                         _mm_set_pd(P6i_1, P6i_0));
      _mm_storeu_pd(&tmp_0[0], tmp_1);
      P6i_0 = tmp_0[0];
      P6i_1 = tmp_0[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_0[i_0 + 2]), tmp_2),
                         _mm_set_pd(tmp, rtb_Sum10));
      _mm_storeu_pd(&tmp_0[0], tmp_2);
      rtb_Sum10 = tmp_0[0];
      tmp = tmp_0[1];
    }

    b_a_1[P6i_tmp_1 + 3] = tmp;
    b_a_1[P6i_tmp_1 + 2] = rtb_Sum10;
    b_a_1[P6i_tmp_1 + 1] = P6i_1;
    b_a_1[P6i_tmp_1] = P6i_0;
  }

  for (i = 0; i < 4; i++) {
    theta2 = 0.0;
    rtb_Sum11 = 0.0;
    P6i_0 = 0.0;
    P6i_1 = 0.0;
    for (P6i_tmp_2 = 0; P6i_tmp_2 < 4; P6i_tmp_2++) {
      i_0 = P6i_tmp_2 << 2;
      tmp_2 = _mm_set1_pd(c_b[(i << 2) + P6i_tmp_2]);
      tmp_1 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_1[i_0]), tmp_2),
                         _mm_set_pd(rtb_Sum11, theta2));
      _mm_storeu_pd(&tmp_0[0], tmp_1);
      theta2 = tmp_0[0];
      rtb_Sum11 = tmp_0[1];
      tmp_2 = _mm_add_pd(_mm_mul_pd(_mm_loadu_pd(&b_a_1[i_0 + 2]), tmp_2),
                         _mm_set_pd(P6i_1, P6i_0));
      _mm_storeu_pd(&tmp_0[0], tmp_2);
      P6i_0 = tmp_0[0];
      P6i_1 = tmp_0[1];
    }

    rtb_out_b_tmp = i << 2;
    P2planar[rtb_out_b_tmp + 3] = P6i_1;
    P2planar[rtb_out_b_tmp + 2] = P6i_0;
    P2planar[rtb_out_b_tmp + 1] = rtb_Sum11;
    P2planar[rtb_out_b_tmp] = theta2;
  }

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/x'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  theta2 = P2planar[12] - rtU.x;

  /* DotProduct: '<S3>/Dot Product' */
  rtb_Sum11 = theta2 * theta2;

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/y'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  theta2 = P2planar[13] - rtU.y;

  /* DotProduct: '<S3>/Dot Product' */
  rtb_Sum11 += theta2 * theta2;

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/z'
   *  MATLAB Function: '<S1>/MATLAB Function4'
   */
  theta2 = P2planar[14] - rtU.z;

  /* Outport: '<Root>/pointReached' incorporates:
   *  Constant: '<S2>/Constant'
   *  DotProduct: '<S3>/Dot Product'
   *  RelationalOperator: '<S2>/Compare'
   *  Sqrt: '<S3>/sqrt'
   */
  rtY.pointReached = (sqrt(theta2 * theta2 + rtb_Sum11) <= 0.002);

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
   *  Inport: '<Root>/jawDesiredPosition'
   */
  rtY.controlJaw = rtU.jawDesiredPosition;

  /* Outport: '<Root>/controlWristRotation' incorporates:
   *  Inport: '<Root>/gripperRotationDesiredPosition'
   */
  rtY.controlWristRotation = rtU.gripperRotationDesiredPosition;

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = theta0;

  /* Update for UnitDelay: '<S1>/Unit Delay2' */
  rtDW.UnitDelay2_DSTATE = XEi;

  /* Update for UnitDelay: '<S1>/Unit Delay1' */
  rtDW.UnitDelay1_DSTATE = angToBase;

  /* Update for UnitDelay: '<S1>/Unit Delay3' */
  rtDW.UnitDelay3_DSTATE = rtb_out_k;
}

/* Model initialize function */
void control_arm_webots_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
