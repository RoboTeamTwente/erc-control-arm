/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_arm_manual.h
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

#ifndef control_arm_manual_h_
#define control_arm_manual_h_
#ifndef control_arm_manual_COMMON_INCLUDES_
#define control_arm_manual_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* control_arm_manual_COMMON_INCLUDES_ */

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
  real_T UnitDelay4_DSTATE;            /* '<S1>/Unit Delay4' */
  real_T UnitDelay1_DSTATE;            /* '<S1>/Unit Delay1' */
  real_T Integrator_DSTATE;            /* '<S44>/Integrator' */
  real_T Integrator_DSTATE_p;          /* '<S96>/Integrator' */
  real_T Integrator_DSTATE_p1;         /* '<S148>/Integrator' */
  real_T Integrator_DSTATE_o;          /* '<S200>/Integrator' */
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
  real_T actualposition;               /* '<Root>/jawActualPosition' */
  real_T actualposition_o;          /* '<Root>/gripperRotationActualPosition' */
  real_T actualposition_i;             /* '<Root>/gripperPitchActualPosition' */
  real_T actualposition_a;             /* '<Root>/baseActualPosition' */
  real_T actualposition_g;             /* '<Root>/stepperLeftActualPosition' */
  real_T actualposition_e;             /* '<Root>/stepperRightActualPosition' */
  real_T deltaTime;                    /* '<Root>/deltaTime' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T error;                        /* '<Root>/error' */
  real_T controlJaw;                   /* '<Root>/controlJaw' */
  real_T controlWristRotation;         /* '<Root>/controlWristRotation' */
  real_T controlGripperPitch;          /* '<Root>/controlGripperPitch' */
  real_T controlBase;                  /* '<Root>/controlBase' */
  real_T stepperLeftSteps;             /* '<Root>/stepperLeftSteps' */
  real_T stepperLeftFrequency;         /* '<Root>/stepperLeftFrequency' */
  real_T stepperRightSteps;            /* '<Root>/stepperRightSteps' */
  real_T stepperRightFrequency;        /* '<Root>/stepperRightFrequency' */
  boolean_T pointReached;              /* '<Root>/pointReached' */
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
extern void control_arm_manual_initialize(void);
extern void control_arm_manual_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/actual position' : Unused code path elimination
 * Block '<S1>/base rotation' : Unused code path elimination
 * Block '<S1>/distance actual and  desired position' : Unused code path elimination
 * Block '<S1>/gripper jaw' : Unused code path elimination
 * Block '<S1>/gripper pitch' : Unused code path elimination
 * Block '<S1>/gripper rotation' : Unused code path elimination
 * Block '<S1>/left base' : Unused code path elimination
 * Block '<S1>/right base' : Unused code path elimination
 * Block '<S41>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S49>/Proportional Gain' : Eliminated nontunable gain of 1
 * Block '<S197>/Integral Gain' : Eliminated nontunable gain of 1
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
 * hilite_system('codegen_arm_manual/control_arm_manual')    - opens subsystem codegen_arm_manual/control_arm_manual
 * hilite_system('codegen_arm_manual/control_arm_manual/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'codegen_arm_manual'
 * '<S1>'   : 'codegen_arm_manual/control_arm_manual'
 * '<S2>'   : 'codegen_arm_manual/control_arm_manual/Compare To Constant3'
 * '<S3>'   : 'codegen_arm_manual/control_arm_manual/Distance'
 * '<S4>'   : 'codegen_arm_manual/control_arm_manual/MATLAB Function4'
 * '<S5>'   : 'codegen_arm_manual/control_arm_manual/PID Controller1'
 * '<S6>'   : 'codegen_arm_manual/control_arm_manual/PID Controller2'
 * '<S7>'   : 'codegen_arm_manual/control_arm_manual/PID Controller3'
 * '<S8>'   : 'codegen_arm_manual/control_arm_manual/PID Controller4'
 * '<S9>'   : 'codegen_arm_manual/control_arm_manual/inverse kinematics'
 * '<S10>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Anti-windup'
 * '<S11>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/D Gain'
 * '<S12>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/External Derivative'
 * '<S13>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Filter'
 * '<S14>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Filter ICs'
 * '<S15>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/I Gain'
 * '<S16>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Ideal P Gain'
 * '<S17>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Ideal P Gain Fdbk'
 * '<S18>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Integrator'
 * '<S19>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Integrator ICs'
 * '<S20>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/N Copy'
 * '<S21>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/N Gain'
 * '<S22>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/P Copy'
 * '<S23>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Parallel P Gain'
 * '<S24>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Reset Signal'
 * '<S25>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Saturation'
 * '<S26>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Saturation Fdbk'
 * '<S27>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Sum'
 * '<S28>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Sum Fdbk'
 * '<S29>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Tracking Mode'
 * '<S30>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Tracking Mode Sum'
 * '<S31>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Tsamp - Integral'
 * '<S32>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Tsamp - Ngain'
 * '<S33>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/postSat Signal'
 * '<S34>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/preInt Signal'
 * '<S35>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/preSat Signal'
 * '<S36>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Anti-windup/Passthrough'
 * '<S37>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/D Gain/Disabled'
 * '<S38>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/External Derivative/Disabled'
 * '<S39>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Filter/Disabled'
 * '<S40>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Filter ICs/Disabled'
 * '<S41>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/I Gain/Internal Parameters'
 * '<S42>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Ideal P Gain/Passthrough'
 * '<S43>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S44>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Integrator/Discrete'
 * '<S45>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Integrator ICs/Internal IC'
 * '<S46>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S47>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/N Gain/Disabled'
 * '<S48>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/P Copy/Disabled'
 * '<S49>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S50>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Reset Signal/Disabled'
 * '<S51>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Saturation/Passthrough'
 * '<S52>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Saturation Fdbk/Disabled'
 * '<S53>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Sum/Sum_PI'
 * '<S54>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Sum Fdbk/Disabled'
 * '<S55>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Tracking Mode/Disabled'
 * '<S56>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S57>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Tsamp - Integral/External Ts'
 * '<S58>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S59>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/postSat Signal/Forward_Path'
 * '<S60>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/preInt Signal/Internal PreInt'
 * '<S61>'  : 'codegen_arm_manual/control_arm_manual/PID Controller1/preSat Signal/Forward_Path'
 * '<S62>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Anti-windup'
 * '<S63>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/D Gain'
 * '<S64>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/External Derivative'
 * '<S65>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Filter'
 * '<S66>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Filter ICs'
 * '<S67>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/I Gain'
 * '<S68>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Ideal P Gain'
 * '<S69>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Ideal P Gain Fdbk'
 * '<S70>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Integrator'
 * '<S71>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Integrator ICs'
 * '<S72>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/N Copy'
 * '<S73>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/N Gain'
 * '<S74>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/P Copy'
 * '<S75>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Parallel P Gain'
 * '<S76>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Reset Signal'
 * '<S77>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Saturation'
 * '<S78>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Saturation Fdbk'
 * '<S79>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Sum'
 * '<S80>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Sum Fdbk'
 * '<S81>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Tracking Mode'
 * '<S82>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Tracking Mode Sum'
 * '<S83>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Tsamp - Integral'
 * '<S84>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Tsamp - Ngain'
 * '<S85>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/postSat Signal'
 * '<S86>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/preInt Signal'
 * '<S87>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/preSat Signal'
 * '<S88>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Anti-windup/Passthrough'
 * '<S89>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/D Gain/Disabled'
 * '<S90>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/External Derivative/Disabled'
 * '<S91>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Filter/Disabled'
 * '<S92>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Filter ICs/Disabled'
 * '<S93>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/I Gain/Internal Parameters'
 * '<S94>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Ideal P Gain/Passthrough'
 * '<S95>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S96>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Integrator/Discrete'
 * '<S97>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/Integrator ICs/Internal IC'
 * '<S98>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S99>'  : 'codegen_arm_manual/control_arm_manual/PID Controller2/N Gain/Disabled'
 * '<S100>' : 'codegen_arm_manual/control_arm_manual/PID Controller2/P Copy/Disabled'
 * '<S101>' : 'codegen_arm_manual/control_arm_manual/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S102>' : 'codegen_arm_manual/control_arm_manual/PID Controller2/Reset Signal/Disabled'
 * '<S103>' : 'codegen_arm_manual/control_arm_manual/PID Controller2/Saturation/Passthrough'
 * '<S104>' : 'codegen_arm_manual/control_arm_manual/PID Controller2/Saturation Fdbk/Disabled'
 * '<S105>' : 'codegen_arm_manual/control_arm_manual/PID Controller2/Sum/Sum_PI'
 * '<S106>' : 'codegen_arm_manual/control_arm_manual/PID Controller2/Sum Fdbk/Disabled'
 * '<S107>' : 'codegen_arm_manual/control_arm_manual/PID Controller2/Tracking Mode/Disabled'
 * '<S108>' : 'codegen_arm_manual/control_arm_manual/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S109>' : 'codegen_arm_manual/control_arm_manual/PID Controller2/Tsamp - Integral/External Ts'
 * '<S110>' : 'codegen_arm_manual/control_arm_manual/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S111>' : 'codegen_arm_manual/control_arm_manual/PID Controller2/postSat Signal/Forward_Path'
 * '<S112>' : 'codegen_arm_manual/control_arm_manual/PID Controller2/preInt Signal/Internal PreInt'
 * '<S113>' : 'codegen_arm_manual/control_arm_manual/PID Controller2/preSat Signal/Forward_Path'
 * '<S114>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Anti-windup'
 * '<S115>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/D Gain'
 * '<S116>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/External Derivative'
 * '<S117>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Filter'
 * '<S118>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Filter ICs'
 * '<S119>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/I Gain'
 * '<S120>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Ideal P Gain'
 * '<S121>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Ideal P Gain Fdbk'
 * '<S122>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Integrator'
 * '<S123>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Integrator ICs'
 * '<S124>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/N Copy'
 * '<S125>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/N Gain'
 * '<S126>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/P Copy'
 * '<S127>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Parallel P Gain'
 * '<S128>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Reset Signal'
 * '<S129>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Saturation'
 * '<S130>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Saturation Fdbk'
 * '<S131>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Sum'
 * '<S132>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Sum Fdbk'
 * '<S133>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Tracking Mode'
 * '<S134>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Tracking Mode Sum'
 * '<S135>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Tsamp - Integral'
 * '<S136>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Tsamp - Ngain'
 * '<S137>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/postSat Signal'
 * '<S138>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/preInt Signal'
 * '<S139>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/preSat Signal'
 * '<S140>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Anti-windup/Passthrough'
 * '<S141>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/D Gain/Disabled'
 * '<S142>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/External Derivative/Disabled'
 * '<S143>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Filter/Disabled'
 * '<S144>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Filter ICs/Disabled'
 * '<S145>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/I Gain/Internal Parameters'
 * '<S146>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Ideal P Gain/Passthrough'
 * '<S147>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S148>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Integrator/Discrete'
 * '<S149>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Integrator ICs/Internal IC'
 * '<S150>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S151>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/N Gain/Disabled'
 * '<S152>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/P Copy/Disabled'
 * '<S153>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S154>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Reset Signal/Disabled'
 * '<S155>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Saturation/Passthrough'
 * '<S156>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Saturation Fdbk/Disabled'
 * '<S157>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Sum/Sum_PI'
 * '<S158>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Sum Fdbk/Disabled'
 * '<S159>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Tracking Mode/Disabled'
 * '<S160>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S161>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Tsamp - Integral/External Ts'
 * '<S162>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S163>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/postSat Signal/Forward_Path'
 * '<S164>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/preInt Signal/Internal PreInt'
 * '<S165>' : 'codegen_arm_manual/control_arm_manual/PID Controller3/preSat Signal/Forward_Path'
 * '<S166>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Anti-windup'
 * '<S167>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/D Gain'
 * '<S168>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/External Derivative'
 * '<S169>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Filter'
 * '<S170>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Filter ICs'
 * '<S171>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/I Gain'
 * '<S172>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Ideal P Gain'
 * '<S173>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Ideal P Gain Fdbk'
 * '<S174>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Integrator'
 * '<S175>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Integrator ICs'
 * '<S176>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/N Copy'
 * '<S177>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/N Gain'
 * '<S178>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/P Copy'
 * '<S179>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Parallel P Gain'
 * '<S180>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Reset Signal'
 * '<S181>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Saturation'
 * '<S182>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Saturation Fdbk'
 * '<S183>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Sum'
 * '<S184>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Sum Fdbk'
 * '<S185>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Tracking Mode'
 * '<S186>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Tracking Mode Sum'
 * '<S187>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Tsamp - Integral'
 * '<S188>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Tsamp - Ngain'
 * '<S189>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/postSat Signal'
 * '<S190>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/preInt Signal'
 * '<S191>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/preSat Signal'
 * '<S192>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Anti-windup/Passthrough'
 * '<S193>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/D Gain/Disabled'
 * '<S194>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/External Derivative/Disabled'
 * '<S195>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Filter/Disabled'
 * '<S196>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Filter ICs/Disabled'
 * '<S197>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/I Gain/Internal Parameters'
 * '<S198>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Ideal P Gain/Passthrough'
 * '<S199>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Ideal P Gain Fdbk/Disabled'
 * '<S200>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Integrator/Discrete'
 * '<S201>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Integrator ICs/Internal IC'
 * '<S202>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/N Copy/Disabled wSignal Specification'
 * '<S203>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/N Gain/Disabled'
 * '<S204>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/P Copy/Disabled'
 * '<S205>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Parallel P Gain/Internal Parameters'
 * '<S206>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Reset Signal/Disabled'
 * '<S207>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Saturation/Passthrough'
 * '<S208>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Saturation Fdbk/Disabled'
 * '<S209>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Sum/Sum_PI'
 * '<S210>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Sum Fdbk/Disabled'
 * '<S211>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Tracking Mode/Disabled'
 * '<S212>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Tracking Mode Sum/Passthrough'
 * '<S213>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Tsamp - Integral/External Ts'
 * '<S214>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/Tsamp - Ngain/Passthrough'
 * '<S215>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/postSat Signal/Forward_Path'
 * '<S216>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/preInt Signal/Internal PreInt'
 * '<S217>' : 'codegen_arm_manual/control_arm_manual/PID Controller4/preSat Signal/Forward_Path'
 */
#endif                                 /* control_arm_manual_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
