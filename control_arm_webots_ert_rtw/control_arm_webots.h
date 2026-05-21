/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_arm_webots.h
 *
 * Code generated for Simulink model 'control_arm_webots'.
 *
 * Model version                  : 1.42
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu May 21 10:27:59 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef control_arm_webots_h_
#define control_arm_webots_h_
#ifndef control_arm_webots_COMMON_INCLUDES_
#define control_arm_webots_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* control_arm_webots_COMMON_INCLUDES_ */

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
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S1>/Unit Delay1' */
  real_T UnitDelay3_DSTATE;            /* '<S1>/Unit Delay3' */
  real_T UnitDelay2_DSTATE;            /* '<S1>/Unit Delay2' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T x;                            /* '<Root>/x' */
  real_T y;                            /* '<Root>/y' */
  real_T z;                            /* '<Root>/z' */
  real_T gripperAng;                   /* '<Root>/gripperAng' */
  real_T jawDesiredPosition;           /* '<Root>/jawDesiredPosition' */
  real_T gripperRotationDesiredPosition;
                                   /* '<Root>/gripperRotationDesiredPosition' */
  real_T jawActualPosition;            /* '<Root>/jawActualPosition' */
  real_T gripperRotationActualPosition;
                                    /* '<Root>/gripperRotationActualPosition' */
  real_T gripperPitchActualPosition;   /* '<Root>/gripperPitchActualPosition' */
  real_T baseActualPosition;           /* '<Root>/baseActualPosition' */
  real_T stepperLeftActualPosition;    /* '<Root>/stepperLeftActualPosition' */
  real_T stepperRightActualPosition;   /* '<Root>/stepperRightActualPosition' */
  real_T deltaTime;                    /* '<Root>/deltaTime' */
  real_T baseOldPosition;              /* '<Root>/baseOldPosition' */
  real_T stepperLeftOldPosition;       /* '<Root>/stepperLeftOldPosition' */
  real_T stepperRightOldPosition;      /* '<Root>/stepperRightOldPosition' */
  real_T gripperPitchOldPosition;      /* '<Root>/gripperPitchOldPosition' */
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
extern void control_arm_webots_initialize(void);
extern void control_arm_webots_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/distance actual and  desired position' : Unused code path elimination
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
 * hilite_system('codegen_arm_webots/control_arm_webots')    - opens subsystem codegen_arm_webots/control_arm_webots
 * hilite_system('codegen_arm_webots/control_arm_webots/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'codegen_arm_webots'
 * '<S1>'   : 'codegen_arm_webots/control_arm_webots'
 * '<S2>'   : 'codegen_arm_webots/control_arm_webots/Compare To Constant3'
 * '<S3>'   : 'codegen_arm_webots/control_arm_webots/Distance'
 * '<S4>'   : 'codegen_arm_webots/control_arm_webots/MATLAB Function1'
 * '<S5>'   : 'codegen_arm_webots/control_arm_webots/MATLAB Function2'
 * '<S6>'   : 'codegen_arm_webots/control_arm_webots/MATLAB Function3'
 * '<S7>'   : 'codegen_arm_webots/control_arm_webots/MATLAB Function4'
 * '<S8>'   : 'codegen_arm_webots/control_arm_webots/MATLAB Function5'
 * '<S9>'   : 'codegen_arm_webots/control_arm_webots/inverse kinematics'
 */
#endif                                 /* control_arm_webots_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
