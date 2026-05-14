/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_arm_manual_webots.h
 *
 * Code generated for Simulink model 'control_arm_manual_webots'.
 *
 * Model version                  : 1.36
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu May 14 16:11:21 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef control_arm_manual_webots_h_
#define control_arm_manual_webots_h_
#ifndef control_arm_manual_webots_COMMON_INCLUDES_
#define control_arm_manual_webots_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                          /* control_arm_manual_webots_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay8_DSTATE;            /* '<S1>/Unit Delay8' */
  real_T Integrator_DSTATE;            /* '<S41>/Integrator' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T x;                            /* '<Root>/x' */
  real_T y;                            /* '<Root>/y' */
  real_T z;                            /* '<Root>/z' */
  real_T gripperAng;                   /* '<Root>/gripperAng' */
  real_T desiredposition;              /* '<Root>/jawDesiredPosition' */
  real_T gripperRotationDesiredPosition;
                                   /* '<Root>/gripperRotationDesiredPosition' */
  real_T actualposition;               /* '<Root>/jawActualPosition' */
  real_T gripperRotationActualPosition;
                                    /* '<Root>/gripperRotationActualPosition' */
  real_T gripperPitchActualPosition;   /* '<Root>/gripperPitchActualPosition' */
  real_T baseActualPosition;           /* '<Root>/baseActualPosition' */
  real_T stepperLeftActualPosition;    /* '<Root>/stepperLeftActualPosition' */
  real_T stepperRightActualPosition;   /* '<Root>/stepperRightActualPosition' */
  real_T deltaTime;                    /* '<Root>/deltaTime' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T error;                        /* '<Root>/error' */
  real_T controlJaw;                   /* '<Root>/controlJaw' */
  real_T controlWristRotation;         /* '<Root>/controlWristRotation' */
  real_T controlGripperPitch;          /* '<Root>/controlGripperPitch' */
  real_T controlBase;                  /* '<Root>/controlBase' */
  real_T controlStepperLeft;           /* '<Root>/controlStepperLeft' */
  real_T controlStepperRight;          /* '<Root>/controlStepperRight' */
  boolean_T pointReached;              /* '<Root>/pointReached' */
  real_T actualX;                      /* '<Root>/actualX' */
  real_T actualY;                      /* '<Root>/actualY' */
  real_T actualZ;                      /* '<Root>/actualZ' */
  real_T testProbe;                    /* '<Root>/testProbe' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void control_arm_manual_webots_initialize(void);
extern void control_arm_manual_webots_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/distance actual and  desired position' : Unused code path elimination
 * Block '<S1>/gripper jaw' : Unused code path elimination
 * Block '<S38>/Integral Gain' : Eliminated nontunable gain of 1
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('codegen_arm_manual_webots/control_arm_manual_webots')    - opens subsystem codegen_arm_manual_webots/control_arm_manual_webots
 * hilite_system('codegen_arm_manual_webots/control_arm_manual_webots/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'codegen_arm_manual_webots'
 * '<S1>'   : 'codegen_arm_manual_webots/control_arm_manual_webots'
 * '<S2>'   : 'codegen_arm_manual_webots/control_arm_manual_webots/Compare To Constant3'
 * '<S3>'   : 'codegen_arm_manual_webots/control_arm_manual_webots/Distance'
 * '<S4>'   : 'codegen_arm_manual_webots/control_arm_manual_webots/MATLAB Function4'
 * '<S5>'   : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4'
 * '<S6>'   : 'codegen_arm_manual_webots/control_arm_manual_webots/inverse kinematics'
 * '<S7>'   : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Anti-windup'
 * '<S8>'   : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/D Gain'
 * '<S9>'   : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/External Derivative'
 * '<S10>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Filter'
 * '<S11>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Filter ICs'
 * '<S12>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/I Gain'
 * '<S13>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Ideal P Gain'
 * '<S14>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Ideal P Gain Fdbk'
 * '<S15>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Integrator'
 * '<S16>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Integrator ICs'
 * '<S17>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/N Copy'
 * '<S18>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/N Gain'
 * '<S19>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/P Copy'
 * '<S20>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Parallel P Gain'
 * '<S21>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Reset Signal'
 * '<S22>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Saturation'
 * '<S23>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Saturation Fdbk'
 * '<S24>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Sum'
 * '<S25>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Sum Fdbk'
 * '<S26>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Tracking Mode'
 * '<S27>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Tracking Mode Sum'
 * '<S28>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Tsamp - Integral'
 * '<S29>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Tsamp - Ngain'
 * '<S30>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/postSat Signal'
 * '<S31>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/preInt Signal'
 * '<S32>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/preSat Signal'
 * '<S33>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Anti-windup/Passthrough'
 * '<S34>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/D Gain/Disabled'
 * '<S35>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/External Derivative/Disabled'
 * '<S36>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Filter/Disabled'
 * '<S37>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Filter ICs/Disabled'
 * '<S38>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/I Gain/Internal Parameters'
 * '<S39>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Ideal P Gain/Passthrough'
 * '<S40>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Ideal P Gain Fdbk/Disabled'
 * '<S41>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Integrator/Discrete'
 * '<S42>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Integrator ICs/Internal IC'
 * '<S43>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/N Copy/Disabled wSignal Specification'
 * '<S44>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/N Gain/Disabled'
 * '<S45>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/P Copy/Disabled'
 * '<S46>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Parallel P Gain/Internal Parameters'
 * '<S47>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Reset Signal/Disabled'
 * '<S48>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Saturation/Passthrough'
 * '<S49>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Saturation Fdbk/Disabled'
 * '<S50>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Sum/Sum_PI'
 * '<S51>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Sum Fdbk/Disabled'
 * '<S52>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Tracking Mode/Disabled'
 * '<S53>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Tracking Mode Sum/Passthrough'
 * '<S54>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Tsamp - Integral/External Ts'
 * '<S55>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/Tsamp - Ngain/Passthrough'
 * '<S56>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/postSat Signal/Forward_Path'
 * '<S57>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/preInt Signal/Internal PreInt'
 * '<S58>'  : 'codegen_arm_manual_webots/control_arm_manual_webots/PID Controller4/preSat Signal/Forward_Path'
 */
#endif                                 /* control_arm_manual_webots_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
