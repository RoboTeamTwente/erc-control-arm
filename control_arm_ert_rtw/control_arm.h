/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_arm.h
 *
 * Code generated for Simulink model 'control_arm'.
 *
 * Model version                  : 1.35
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon May 25 10:23:03 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef control_arm_h_
#define control_arm_h_
#ifndef control_arm_COMMON_INCLUDES_
#define control_arm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* control_arm_COMMON_INCLUDES_ */

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
  real_T UnitDelay6_DSTATE;            /* '<S1>/Unit Delay6' */
  real_T UnitDelay1_DSTATE;            /* '<S1>/Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S1>/Unit Delay2' */
  real_T UnitDelay5_DSTATE;            /* '<S1>/Unit Delay5' */
  real_T Integrator_DSTATE;            /* '<S49>/Integrator' */
  real_T UnitDelay7_DSTATE;            /* '<S1>/Unit Delay7' */
  real_T Integrator_DSTATE_e;          /* '<S101>/Integrator' */
  real_T UnitDelay9_DSTATE;            /* '<S1>/Unit Delay9' */
  real_T Integrator_DSTATE_h;          /* '<S153>/Integrator' */
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
  real_T gripperPitchOldPosition;      /* '<Root>/gripperPitchOldPosition' */
  real_T baseOldPosition;              /* '<Root>/baseOldPosition' */
  real_T stepperLeftOldPosition;       /* '<Root>/stepperLeftOldPosition' */
  real_T stepperRightOldPosition;      /* '<Root>/stepperRightOldPosition' */
  real_T timePerMovement;              /* '<Root>/timePerMovement' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T pointReached;              /* '<Root>/pointReached' */
  real_T error;                        /* '<Root>/error' */
  real_T controlJaw;                   /* '<Root>/controlJaw' */
  real_T controlWristRotation;         /* '<Root>/controlWristRotation' */
  real_T controlGripperPitch;          /* '<Root>/controlGripperPitch' */
  real_T controlBase;                  /* '<Root>/controlBase' */
  real_T stepperLeftSteps;             /* '<Root>/stepperLeftSteps' */
  real_T stepperLeftFrequency;         /* '<Root>/stepperLeftFrequency' */
  real_T stepperRightSteps;            /* '<Root>/stepperRightSteps' */
  real_T stepperRightFrequency;        /* '<Root>/stepperRightFrequency' */
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
extern void control_arm_initialize(void);
extern void control_arm_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/actual position' : Unused code path elimination
 * Block '<S1>/distance actual and  desired position' : Unused code path elimination
 * Block '<S46>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S54>/Proportional Gain' : Eliminated nontunable gain of 1
 * Block '<S150>/Integral Gain' : Eliminated nontunable gain of 1
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
 * hilite_system('codegen_arm/control_arm')    - opens subsystem codegen_arm/control_arm
 * hilite_system('codegen_arm/control_arm/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'codegen_arm'
 * '<S1>'   : 'codegen_arm/control_arm'
 * '<S2>'   : 'codegen_arm/control_arm/Compare To Constant3'
 * '<S3>'   : 'codegen_arm/control_arm/Distance'
 * '<S4>'   : 'codegen_arm/control_arm/MATLAB Function'
 * '<S5>'   : 'codegen_arm/control_arm/MATLAB Function1'
 * '<S6>'   : 'codegen_arm/control_arm/MATLAB Function2'
 * '<S7>'   : 'codegen_arm/control_arm/MATLAB Function3'
 * '<S8>'   : 'codegen_arm/control_arm/MATLAB Function4'
 * '<S9>'   : 'codegen_arm/control_arm/MATLAB Function5'
 * '<S10>'  : 'codegen_arm/control_arm/MATLAB Function6'
 * '<S11>'  : 'codegen_arm/control_arm/PID Controller1'
 * '<S12>'  : 'codegen_arm/control_arm/PID Controller3'
 * '<S13>'  : 'codegen_arm/control_arm/PID Controller4'
 * '<S14>'  : 'codegen_arm/control_arm/inverse kinematics'
 * '<S15>'  : 'codegen_arm/control_arm/PID Controller1/Anti-windup'
 * '<S16>'  : 'codegen_arm/control_arm/PID Controller1/D Gain'
 * '<S17>'  : 'codegen_arm/control_arm/PID Controller1/External Derivative'
 * '<S18>'  : 'codegen_arm/control_arm/PID Controller1/Filter'
 * '<S19>'  : 'codegen_arm/control_arm/PID Controller1/Filter ICs'
 * '<S20>'  : 'codegen_arm/control_arm/PID Controller1/I Gain'
 * '<S21>'  : 'codegen_arm/control_arm/PID Controller1/Ideal P Gain'
 * '<S22>'  : 'codegen_arm/control_arm/PID Controller1/Ideal P Gain Fdbk'
 * '<S23>'  : 'codegen_arm/control_arm/PID Controller1/Integrator'
 * '<S24>'  : 'codegen_arm/control_arm/PID Controller1/Integrator ICs'
 * '<S25>'  : 'codegen_arm/control_arm/PID Controller1/N Copy'
 * '<S26>'  : 'codegen_arm/control_arm/PID Controller1/N Gain'
 * '<S27>'  : 'codegen_arm/control_arm/PID Controller1/P Copy'
 * '<S28>'  : 'codegen_arm/control_arm/PID Controller1/Parallel P Gain'
 * '<S29>'  : 'codegen_arm/control_arm/PID Controller1/Reset Signal'
 * '<S30>'  : 'codegen_arm/control_arm/PID Controller1/Saturation'
 * '<S31>'  : 'codegen_arm/control_arm/PID Controller1/Saturation Fdbk'
 * '<S32>'  : 'codegen_arm/control_arm/PID Controller1/Sum'
 * '<S33>'  : 'codegen_arm/control_arm/PID Controller1/Sum Fdbk'
 * '<S34>'  : 'codegen_arm/control_arm/PID Controller1/Tracking Mode'
 * '<S35>'  : 'codegen_arm/control_arm/PID Controller1/Tracking Mode Sum'
 * '<S36>'  : 'codegen_arm/control_arm/PID Controller1/Tsamp - Integral'
 * '<S37>'  : 'codegen_arm/control_arm/PID Controller1/Tsamp - Ngain'
 * '<S38>'  : 'codegen_arm/control_arm/PID Controller1/postSat Signal'
 * '<S39>'  : 'codegen_arm/control_arm/PID Controller1/preInt Signal'
 * '<S40>'  : 'codegen_arm/control_arm/PID Controller1/preSat Signal'
 * '<S41>'  : 'codegen_arm/control_arm/PID Controller1/Anti-windup/Passthrough'
 * '<S42>'  : 'codegen_arm/control_arm/PID Controller1/D Gain/Disabled'
 * '<S43>'  : 'codegen_arm/control_arm/PID Controller1/External Derivative/Disabled'
 * '<S44>'  : 'codegen_arm/control_arm/PID Controller1/Filter/Disabled'
 * '<S45>'  : 'codegen_arm/control_arm/PID Controller1/Filter ICs/Disabled'
 * '<S46>'  : 'codegen_arm/control_arm/PID Controller1/I Gain/Internal Parameters'
 * '<S47>'  : 'codegen_arm/control_arm/PID Controller1/Ideal P Gain/Passthrough'
 * '<S48>'  : 'codegen_arm/control_arm/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S49>'  : 'codegen_arm/control_arm/PID Controller1/Integrator/Discrete'
 * '<S50>'  : 'codegen_arm/control_arm/PID Controller1/Integrator ICs/Internal IC'
 * '<S51>'  : 'codegen_arm/control_arm/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S52>'  : 'codegen_arm/control_arm/PID Controller1/N Gain/Disabled'
 * '<S53>'  : 'codegen_arm/control_arm/PID Controller1/P Copy/Disabled'
 * '<S54>'  : 'codegen_arm/control_arm/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S55>'  : 'codegen_arm/control_arm/PID Controller1/Reset Signal/Disabled'
 * '<S56>'  : 'codegen_arm/control_arm/PID Controller1/Saturation/Passthrough'
 * '<S57>'  : 'codegen_arm/control_arm/PID Controller1/Saturation Fdbk/Disabled'
 * '<S58>'  : 'codegen_arm/control_arm/PID Controller1/Sum/Sum_PI'
 * '<S59>'  : 'codegen_arm/control_arm/PID Controller1/Sum Fdbk/Disabled'
 * '<S60>'  : 'codegen_arm/control_arm/PID Controller1/Tracking Mode/Disabled'
 * '<S61>'  : 'codegen_arm/control_arm/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S62>'  : 'codegen_arm/control_arm/PID Controller1/Tsamp - Integral/External Ts'
 * '<S63>'  : 'codegen_arm/control_arm/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S64>'  : 'codegen_arm/control_arm/PID Controller1/postSat Signal/Forward_Path'
 * '<S65>'  : 'codegen_arm/control_arm/PID Controller1/preInt Signal/Internal PreInt'
 * '<S66>'  : 'codegen_arm/control_arm/PID Controller1/preSat Signal/Forward_Path'
 * '<S67>'  : 'codegen_arm/control_arm/PID Controller3/Anti-windup'
 * '<S68>'  : 'codegen_arm/control_arm/PID Controller3/D Gain'
 * '<S69>'  : 'codegen_arm/control_arm/PID Controller3/External Derivative'
 * '<S70>'  : 'codegen_arm/control_arm/PID Controller3/Filter'
 * '<S71>'  : 'codegen_arm/control_arm/PID Controller3/Filter ICs'
 * '<S72>'  : 'codegen_arm/control_arm/PID Controller3/I Gain'
 * '<S73>'  : 'codegen_arm/control_arm/PID Controller3/Ideal P Gain'
 * '<S74>'  : 'codegen_arm/control_arm/PID Controller3/Ideal P Gain Fdbk'
 * '<S75>'  : 'codegen_arm/control_arm/PID Controller3/Integrator'
 * '<S76>'  : 'codegen_arm/control_arm/PID Controller3/Integrator ICs'
 * '<S77>'  : 'codegen_arm/control_arm/PID Controller3/N Copy'
 * '<S78>'  : 'codegen_arm/control_arm/PID Controller3/N Gain'
 * '<S79>'  : 'codegen_arm/control_arm/PID Controller3/P Copy'
 * '<S80>'  : 'codegen_arm/control_arm/PID Controller3/Parallel P Gain'
 * '<S81>'  : 'codegen_arm/control_arm/PID Controller3/Reset Signal'
 * '<S82>'  : 'codegen_arm/control_arm/PID Controller3/Saturation'
 * '<S83>'  : 'codegen_arm/control_arm/PID Controller3/Saturation Fdbk'
 * '<S84>'  : 'codegen_arm/control_arm/PID Controller3/Sum'
 * '<S85>'  : 'codegen_arm/control_arm/PID Controller3/Sum Fdbk'
 * '<S86>'  : 'codegen_arm/control_arm/PID Controller3/Tracking Mode'
 * '<S87>'  : 'codegen_arm/control_arm/PID Controller3/Tracking Mode Sum'
 * '<S88>'  : 'codegen_arm/control_arm/PID Controller3/Tsamp - Integral'
 * '<S89>'  : 'codegen_arm/control_arm/PID Controller3/Tsamp - Ngain'
 * '<S90>'  : 'codegen_arm/control_arm/PID Controller3/postSat Signal'
 * '<S91>'  : 'codegen_arm/control_arm/PID Controller3/preInt Signal'
 * '<S92>'  : 'codegen_arm/control_arm/PID Controller3/preSat Signal'
 * '<S93>'  : 'codegen_arm/control_arm/PID Controller3/Anti-windup/Passthrough'
 * '<S94>'  : 'codegen_arm/control_arm/PID Controller3/D Gain/Disabled'
 * '<S95>'  : 'codegen_arm/control_arm/PID Controller3/External Derivative/Disabled'
 * '<S96>'  : 'codegen_arm/control_arm/PID Controller3/Filter/Disabled'
 * '<S97>'  : 'codegen_arm/control_arm/PID Controller3/Filter ICs/Disabled'
 * '<S98>'  : 'codegen_arm/control_arm/PID Controller3/I Gain/Internal Parameters'
 * '<S99>'  : 'codegen_arm/control_arm/PID Controller3/Ideal P Gain/Passthrough'
 * '<S100>' : 'codegen_arm/control_arm/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S101>' : 'codegen_arm/control_arm/PID Controller3/Integrator/Discrete'
 * '<S102>' : 'codegen_arm/control_arm/PID Controller3/Integrator ICs/Internal IC'
 * '<S103>' : 'codegen_arm/control_arm/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S104>' : 'codegen_arm/control_arm/PID Controller3/N Gain/Disabled'
 * '<S105>' : 'codegen_arm/control_arm/PID Controller3/P Copy/Disabled'
 * '<S106>' : 'codegen_arm/control_arm/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S107>' : 'codegen_arm/control_arm/PID Controller3/Reset Signal/Disabled'
 * '<S108>' : 'codegen_arm/control_arm/PID Controller3/Saturation/Passthrough'
 * '<S109>' : 'codegen_arm/control_arm/PID Controller3/Saturation Fdbk/Disabled'
 * '<S110>' : 'codegen_arm/control_arm/PID Controller3/Sum/Sum_PI'
 * '<S111>' : 'codegen_arm/control_arm/PID Controller3/Sum Fdbk/Disabled'
 * '<S112>' : 'codegen_arm/control_arm/PID Controller3/Tracking Mode/Disabled'
 * '<S113>' : 'codegen_arm/control_arm/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S114>' : 'codegen_arm/control_arm/PID Controller3/Tsamp - Integral/External Ts'
 * '<S115>' : 'codegen_arm/control_arm/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S116>' : 'codegen_arm/control_arm/PID Controller3/postSat Signal/Forward_Path'
 * '<S117>' : 'codegen_arm/control_arm/PID Controller3/preInt Signal/Internal PreInt'
 * '<S118>' : 'codegen_arm/control_arm/PID Controller3/preSat Signal/Forward_Path'
 * '<S119>' : 'codegen_arm/control_arm/PID Controller4/Anti-windup'
 * '<S120>' : 'codegen_arm/control_arm/PID Controller4/D Gain'
 * '<S121>' : 'codegen_arm/control_arm/PID Controller4/External Derivative'
 * '<S122>' : 'codegen_arm/control_arm/PID Controller4/Filter'
 * '<S123>' : 'codegen_arm/control_arm/PID Controller4/Filter ICs'
 * '<S124>' : 'codegen_arm/control_arm/PID Controller4/I Gain'
 * '<S125>' : 'codegen_arm/control_arm/PID Controller4/Ideal P Gain'
 * '<S126>' : 'codegen_arm/control_arm/PID Controller4/Ideal P Gain Fdbk'
 * '<S127>' : 'codegen_arm/control_arm/PID Controller4/Integrator'
 * '<S128>' : 'codegen_arm/control_arm/PID Controller4/Integrator ICs'
 * '<S129>' : 'codegen_arm/control_arm/PID Controller4/N Copy'
 * '<S130>' : 'codegen_arm/control_arm/PID Controller4/N Gain'
 * '<S131>' : 'codegen_arm/control_arm/PID Controller4/P Copy'
 * '<S132>' : 'codegen_arm/control_arm/PID Controller4/Parallel P Gain'
 * '<S133>' : 'codegen_arm/control_arm/PID Controller4/Reset Signal'
 * '<S134>' : 'codegen_arm/control_arm/PID Controller4/Saturation'
 * '<S135>' : 'codegen_arm/control_arm/PID Controller4/Saturation Fdbk'
 * '<S136>' : 'codegen_arm/control_arm/PID Controller4/Sum'
 * '<S137>' : 'codegen_arm/control_arm/PID Controller4/Sum Fdbk'
 * '<S138>' : 'codegen_arm/control_arm/PID Controller4/Tracking Mode'
 * '<S139>' : 'codegen_arm/control_arm/PID Controller4/Tracking Mode Sum'
 * '<S140>' : 'codegen_arm/control_arm/PID Controller4/Tsamp - Integral'
 * '<S141>' : 'codegen_arm/control_arm/PID Controller4/Tsamp - Ngain'
 * '<S142>' : 'codegen_arm/control_arm/PID Controller4/postSat Signal'
 * '<S143>' : 'codegen_arm/control_arm/PID Controller4/preInt Signal'
 * '<S144>' : 'codegen_arm/control_arm/PID Controller4/preSat Signal'
 * '<S145>' : 'codegen_arm/control_arm/PID Controller4/Anti-windup/Passthrough'
 * '<S146>' : 'codegen_arm/control_arm/PID Controller4/D Gain/Disabled'
 * '<S147>' : 'codegen_arm/control_arm/PID Controller4/External Derivative/Disabled'
 * '<S148>' : 'codegen_arm/control_arm/PID Controller4/Filter/Disabled'
 * '<S149>' : 'codegen_arm/control_arm/PID Controller4/Filter ICs/Disabled'
 * '<S150>' : 'codegen_arm/control_arm/PID Controller4/I Gain/Internal Parameters'
 * '<S151>' : 'codegen_arm/control_arm/PID Controller4/Ideal P Gain/Passthrough'
 * '<S152>' : 'codegen_arm/control_arm/PID Controller4/Ideal P Gain Fdbk/Disabled'
 * '<S153>' : 'codegen_arm/control_arm/PID Controller4/Integrator/Discrete'
 * '<S154>' : 'codegen_arm/control_arm/PID Controller4/Integrator ICs/Internal IC'
 * '<S155>' : 'codegen_arm/control_arm/PID Controller4/N Copy/Disabled wSignal Specification'
 * '<S156>' : 'codegen_arm/control_arm/PID Controller4/N Gain/Disabled'
 * '<S157>' : 'codegen_arm/control_arm/PID Controller4/P Copy/Disabled'
 * '<S158>' : 'codegen_arm/control_arm/PID Controller4/Parallel P Gain/Internal Parameters'
 * '<S159>' : 'codegen_arm/control_arm/PID Controller4/Reset Signal/Disabled'
 * '<S160>' : 'codegen_arm/control_arm/PID Controller4/Saturation/Passthrough'
 * '<S161>' : 'codegen_arm/control_arm/PID Controller4/Saturation Fdbk/Disabled'
 * '<S162>' : 'codegen_arm/control_arm/PID Controller4/Sum/Sum_PI'
 * '<S163>' : 'codegen_arm/control_arm/PID Controller4/Sum Fdbk/Disabled'
 * '<S164>' : 'codegen_arm/control_arm/PID Controller4/Tracking Mode/Disabled'
 * '<S165>' : 'codegen_arm/control_arm/PID Controller4/Tracking Mode Sum/Passthrough'
 * '<S166>' : 'codegen_arm/control_arm/PID Controller4/Tsamp - Integral/External Ts'
 * '<S167>' : 'codegen_arm/control_arm/PID Controller4/Tsamp - Ngain/Passthrough'
 * '<S168>' : 'codegen_arm/control_arm/PID Controller4/postSat Signal/Forward_Path'
 * '<S169>' : 'codegen_arm/control_arm/PID Controller4/preInt Signal/Internal PreInt'
 * '<S170>' : 'codegen_arm/control_arm/PID Controller4/preSat Signal/Forward_Path'
 */
#endif                                 /* control_arm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
