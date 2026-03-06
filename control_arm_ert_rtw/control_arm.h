/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control_arm.h
 *
 * Code generated for Simulink model 'control_arm'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Fri Mar  6 13:11:00 2026
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
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  real_T UnitDelay3_DSTATE;            /* '<S1>/Unit Delay3' */
  real_T UnitDelay8_DSTATE;            /* '<S1>/Unit Delay8' */
  real_T UnitDelay6_DSTATE;            /* '<S1>/Unit Delay6' */
  real_T UnitDelay4_DSTATE;            /* '<S1>/Unit Delay4' */
  real_T UnitDelay1_DSTATE;            /* '<S1>/Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S1>/Unit Delay2' */
  real_T Integrator_DSTATE;            /* '<S102>/Integrator' */
  real_T UnitDelay5_DSTATE;            /* '<S1>/Unit Delay5' */
  real_T Integrator_DSTATE_g;          /* '<S50>/Integrator' */
  real_T UnitDelay7_DSTATE;            /* '<S1>/Unit Delay7' */
  real_T Integrator_DSTATE_j;          /* '<S154>/Integrator' */
  real_T UnitDelay9_DSTATE;            /* '<S1>/Unit Delay9' */
  real_T Integrator_DSTATE_c;          /* '<S206>/Integrator' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  int32_T clockTickCounter_d;          /* '<S1>/Pulse Generator1' */
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
  real_T actualposition_f;          /* '<Root>/gripperRotationActualPosition' */
  real_T actualposition_g;             /* '<Root>/gripperPitchActualPosition' */
  real_T actualposition_h;             /* '<Root>/baseActualPosition' */
  real_T actualposition_m;             /* '<Root>/stepperLeftActualPosition' */
  real_T actualposition_hs;            /* '<Root>/stepperRightActualPosition' */
  real_T deltaTime;                    /* '<Root>/deltaTime' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  boolean_T pointReached;              /* '<Root>/pointReached' */
  real_T error;                        /* '<Root>/error' */
  real_T controlJaw;                   /* '<Root>/controlJaw' */
  real_T controlWristRotation;         /* '<Root>/controlWristRotation' */
  real_T controlGripperPitch;          /* '<Root>/controlGripperPitch' */
  real_T controlBase;                  /* '<Root>/controlBase' */
  real_T stepperLeftENA;               /* '<Root>/stepperLeftENA' */
  real_T stepperLeftREV;               /* '<Root>/stepperLeftREV' */
  real_T stepperRightENA;              /* '<Root>/stepperRightENA' */
  real_T stepperRightREV;              /* '<Root>/stepperRightREV' */
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
 * Block '<S1>/base rotation' : Unused code path elimination
 * Block '<S1>/distance actual and  desired 3d position' : Unused code path elimination
 * Block '<S1>/gripper jaw' : Unused code path elimination
 * Block '<S1>/gripper pitch' : Unused code path elimination
 * Block '<S1>/gripper rotation' : Unused code path elimination
 * Block '<S1>/left base' : Unused code path elimination
 * Block '<S1>/right base' : Unused code path elimination
 * Block '<S203>/Integral Gain' : Eliminated nontunable gain of 1
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
 * '<S2>'   : 'codegen_arm/control_arm/Compare To Constant'
 * '<S3>'   : 'codegen_arm/control_arm/Compare To Constant1'
 * '<S4>'   : 'codegen_arm/control_arm/Compare To Constant3'
 * '<S5>'   : 'codegen_arm/control_arm/Distance'
 * '<S6>'   : 'codegen_arm/control_arm/MATLAB Function'
 * '<S7>'   : 'codegen_arm/control_arm/MATLAB Function1'
 * '<S8>'   : 'codegen_arm/control_arm/MATLAB Function2'
 * '<S9>'   : 'codegen_arm/control_arm/MATLAB Function3'
 * '<S10>'  : 'codegen_arm/control_arm/MATLAB Function4'
 * '<S11>'  : 'codegen_arm/control_arm/PID Controller1'
 * '<S12>'  : 'codegen_arm/control_arm/PID Controller2'
 * '<S13>'  : 'codegen_arm/control_arm/PID Controller3'
 * '<S14>'  : 'codegen_arm/control_arm/PID Controller4'
 * '<S15>'  : 'codegen_arm/control_arm/inverse kinematics'
 * '<S16>'  : 'codegen_arm/control_arm/PID Controller1/Anti-windup'
 * '<S17>'  : 'codegen_arm/control_arm/PID Controller1/D Gain'
 * '<S18>'  : 'codegen_arm/control_arm/PID Controller1/External Derivative'
 * '<S19>'  : 'codegen_arm/control_arm/PID Controller1/Filter'
 * '<S20>'  : 'codegen_arm/control_arm/PID Controller1/Filter ICs'
 * '<S21>'  : 'codegen_arm/control_arm/PID Controller1/I Gain'
 * '<S22>'  : 'codegen_arm/control_arm/PID Controller1/Ideal P Gain'
 * '<S23>'  : 'codegen_arm/control_arm/PID Controller1/Ideal P Gain Fdbk'
 * '<S24>'  : 'codegen_arm/control_arm/PID Controller1/Integrator'
 * '<S25>'  : 'codegen_arm/control_arm/PID Controller1/Integrator ICs'
 * '<S26>'  : 'codegen_arm/control_arm/PID Controller1/N Copy'
 * '<S27>'  : 'codegen_arm/control_arm/PID Controller1/N Gain'
 * '<S28>'  : 'codegen_arm/control_arm/PID Controller1/P Copy'
 * '<S29>'  : 'codegen_arm/control_arm/PID Controller1/Parallel P Gain'
 * '<S30>'  : 'codegen_arm/control_arm/PID Controller1/Reset Signal'
 * '<S31>'  : 'codegen_arm/control_arm/PID Controller1/Saturation'
 * '<S32>'  : 'codegen_arm/control_arm/PID Controller1/Saturation Fdbk'
 * '<S33>'  : 'codegen_arm/control_arm/PID Controller1/Sum'
 * '<S34>'  : 'codegen_arm/control_arm/PID Controller1/Sum Fdbk'
 * '<S35>'  : 'codegen_arm/control_arm/PID Controller1/Tracking Mode'
 * '<S36>'  : 'codegen_arm/control_arm/PID Controller1/Tracking Mode Sum'
 * '<S37>'  : 'codegen_arm/control_arm/PID Controller1/Tsamp - Integral'
 * '<S38>'  : 'codegen_arm/control_arm/PID Controller1/Tsamp - Ngain'
 * '<S39>'  : 'codegen_arm/control_arm/PID Controller1/postSat Signal'
 * '<S40>'  : 'codegen_arm/control_arm/PID Controller1/preInt Signal'
 * '<S41>'  : 'codegen_arm/control_arm/PID Controller1/preSat Signal'
 * '<S42>'  : 'codegen_arm/control_arm/PID Controller1/Anti-windup/Passthrough'
 * '<S43>'  : 'codegen_arm/control_arm/PID Controller1/D Gain/Disabled'
 * '<S44>'  : 'codegen_arm/control_arm/PID Controller1/External Derivative/Disabled'
 * '<S45>'  : 'codegen_arm/control_arm/PID Controller1/Filter/Disabled'
 * '<S46>'  : 'codegen_arm/control_arm/PID Controller1/Filter ICs/Disabled'
 * '<S47>'  : 'codegen_arm/control_arm/PID Controller1/I Gain/Internal Parameters'
 * '<S48>'  : 'codegen_arm/control_arm/PID Controller1/Ideal P Gain/Passthrough'
 * '<S49>'  : 'codegen_arm/control_arm/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S50>'  : 'codegen_arm/control_arm/PID Controller1/Integrator/Discrete'
 * '<S51>'  : 'codegen_arm/control_arm/PID Controller1/Integrator ICs/Internal IC'
 * '<S52>'  : 'codegen_arm/control_arm/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S53>'  : 'codegen_arm/control_arm/PID Controller1/N Gain/Disabled'
 * '<S54>'  : 'codegen_arm/control_arm/PID Controller1/P Copy/Disabled'
 * '<S55>'  : 'codegen_arm/control_arm/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S56>'  : 'codegen_arm/control_arm/PID Controller1/Reset Signal/Disabled'
 * '<S57>'  : 'codegen_arm/control_arm/PID Controller1/Saturation/Passthrough'
 * '<S58>'  : 'codegen_arm/control_arm/PID Controller1/Saturation Fdbk/Disabled'
 * '<S59>'  : 'codegen_arm/control_arm/PID Controller1/Sum/Sum_PI'
 * '<S60>'  : 'codegen_arm/control_arm/PID Controller1/Sum Fdbk/Disabled'
 * '<S61>'  : 'codegen_arm/control_arm/PID Controller1/Tracking Mode/Disabled'
 * '<S62>'  : 'codegen_arm/control_arm/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S63>'  : 'codegen_arm/control_arm/PID Controller1/Tsamp - Integral/External Ts'
 * '<S64>'  : 'codegen_arm/control_arm/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S65>'  : 'codegen_arm/control_arm/PID Controller1/postSat Signal/Forward_Path'
 * '<S66>'  : 'codegen_arm/control_arm/PID Controller1/preInt Signal/Internal PreInt'
 * '<S67>'  : 'codegen_arm/control_arm/PID Controller1/preSat Signal/Forward_Path'
 * '<S68>'  : 'codegen_arm/control_arm/PID Controller2/Anti-windup'
 * '<S69>'  : 'codegen_arm/control_arm/PID Controller2/D Gain'
 * '<S70>'  : 'codegen_arm/control_arm/PID Controller2/External Derivative'
 * '<S71>'  : 'codegen_arm/control_arm/PID Controller2/Filter'
 * '<S72>'  : 'codegen_arm/control_arm/PID Controller2/Filter ICs'
 * '<S73>'  : 'codegen_arm/control_arm/PID Controller2/I Gain'
 * '<S74>'  : 'codegen_arm/control_arm/PID Controller2/Ideal P Gain'
 * '<S75>'  : 'codegen_arm/control_arm/PID Controller2/Ideal P Gain Fdbk'
 * '<S76>'  : 'codegen_arm/control_arm/PID Controller2/Integrator'
 * '<S77>'  : 'codegen_arm/control_arm/PID Controller2/Integrator ICs'
 * '<S78>'  : 'codegen_arm/control_arm/PID Controller2/N Copy'
 * '<S79>'  : 'codegen_arm/control_arm/PID Controller2/N Gain'
 * '<S80>'  : 'codegen_arm/control_arm/PID Controller2/P Copy'
 * '<S81>'  : 'codegen_arm/control_arm/PID Controller2/Parallel P Gain'
 * '<S82>'  : 'codegen_arm/control_arm/PID Controller2/Reset Signal'
 * '<S83>'  : 'codegen_arm/control_arm/PID Controller2/Saturation'
 * '<S84>'  : 'codegen_arm/control_arm/PID Controller2/Saturation Fdbk'
 * '<S85>'  : 'codegen_arm/control_arm/PID Controller2/Sum'
 * '<S86>'  : 'codegen_arm/control_arm/PID Controller2/Sum Fdbk'
 * '<S87>'  : 'codegen_arm/control_arm/PID Controller2/Tracking Mode'
 * '<S88>'  : 'codegen_arm/control_arm/PID Controller2/Tracking Mode Sum'
 * '<S89>'  : 'codegen_arm/control_arm/PID Controller2/Tsamp - Integral'
 * '<S90>'  : 'codegen_arm/control_arm/PID Controller2/Tsamp - Ngain'
 * '<S91>'  : 'codegen_arm/control_arm/PID Controller2/postSat Signal'
 * '<S92>'  : 'codegen_arm/control_arm/PID Controller2/preInt Signal'
 * '<S93>'  : 'codegen_arm/control_arm/PID Controller2/preSat Signal'
 * '<S94>'  : 'codegen_arm/control_arm/PID Controller2/Anti-windup/Passthrough'
 * '<S95>'  : 'codegen_arm/control_arm/PID Controller2/D Gain/Disabled'
 * '<S96>'  : 'codegen_arm/control_arm/PID Controller2/External Derivative/Disabled'
 * '<S97>'  : 'codegen_arm/control_arm/PID Controller2/Filter/Disabled'
 * '<S98>'  : 'codegen_arm/control_arm/PID Controller2/Filter ICs/Disabled'
 * '<S99>'  : 'codegen_arm/control_arm/PID Controller2/I Gain/Internal Parameters'
 * '<S100>' : 'codegen_arm/control_arm/PID Controller2/Ideal P Gain/Passthrough'
 * '<S101>' : 'codegen_arm/control_arm/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S102>' : 'codegen_arm/control_arm/PID Controller2/Integrator/Discrete'
 * '<S103>' : 'codegen_arm/control_arm/PID Controller2/Integrator ICs/Internal IC'
 * '<S104>' : 'codegen_arm/control_arm/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S105>' : 'codegen_arm/control_arm/PID Controller2/N Gain/Disabled'
 * '<S106>' : 'codegen_arm/control_arm/PID Controller2/P Copy/Disabled'
 * '<S107>' : 'codegen_arm/control_arm/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S108>' : 'codegen_arm/control_arm/PID Controller2/Reset Signal/Disabled'
 * '<S109>' : 'codegen_arm/control_arm/PID Controller2/Saturation/Passthrough'
 * '<S110>' : 'codegen_arm/control_arm/PID Controller2/Saturation Fdbk/Disabled'
 * '<S111>' : 'codegen_arm/control_arm/PID Controller2/Sum/Sum_PI'
 * '<S112>' : 'codegen_arm/control_arm/PID Controller2/Sum Fdbk/Disabled'
 * '<S113>' : 'codegen_arm/control_arm/PID Controller2/Tracking Mode/Disabled'
 * '<S114>' : 'codegen_arm/control_arm/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S115>' : 'codegen_arm/control_arm/PID Controller2/Tsamp - Integral/External Ts'
 * '<S116>' : 'codegen_arm/control_arm/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S117>' : 'codegen_arm/control_arm/PID Controller2/postSat Signal/Forward_Path'
 * '<S118>' : 'codegen_arm/control_arm/PID Controller2/preInt Signal/Internal PreInt'
 * '<S119>' : 'codegen_arm/control_arm/PID Controller2/preSat Signal/Forward_Path'
 * '<S120>' : 'codegen_arm/control_arm/PID Controller3/Anti-windup'
 * '<S121>' : 'codegen_arm/control_arm/PID Controller3/D Gain'
 * '<S122>' : 'codegen_arm/control_arm/PID Controller3/External Derivative'
 * '<S123>' : 'codegen_arm/control_arm/PID Controller3/Filter'
 * '<S124>' : 'codegen_arm/control_arm/PID Controller3/Filter ICs'
 * '<S125>' : 'codegen_arm/control_arm/PID Controller3/I Gain'
 * '<S126>' : 'codegen_arm/control_arm/PID Controller3/Ideal P Gain'
 * '<S127>' : 'codegen_arm/control_arm/PID Controller3/Ideal P Gain Fdbk'
 * '<S128>' : 'codegen_arm/control_arm/PID Controller3/Integrator'
 * '<S129>' : 'codegen_arm/control_arm/PID Controller3/Integrator ICs'
 * '<S130>' : 'codegen_arm/control_arm/PID Controller3/N Copy'
 * '<S131>' : 'codegen_arm/control_arm/PID Controller3/N Gain'
 * '<S132>' : 'codegen_arm/control_arm/PID Controller3/P Copy'
 * '<S133>' : 'codegen_arm/control_arm/PID Controller3/Parallel P Gain'
 * '<S134>' : 'codegen_arm/control_arm/PID Controller3/Reset Signal'
 * '<S135>' : 'codegen_arm/control_arm/PID Controller3/Saturation'
 * '<S136>' : 'codegen_arm/control_arm/PID Controller3/Saturation Fdbk'
 * '<S137>' : 'codegen_arm/control_arm/PID Controller3/Sum'
 * '<S138>' : 'codegen_arm/control_arm/PID Controller3/Sum Fdbk'
 * '<S139>' : 'codegen_arm/control_arm/PID Controller3/Tracking Mode'
 * '<S140>' : 'codegen_arm/control_arm/PID Controller3/Tracking Mode Sum'
 * '<S141>' : 'codegen_arm/control_arm/PID Controller3/Tsamp - Integral'
 * '<S142>' : 'codegen_arm/control_arm/PID Controller3/Tsamp - Ngain'
 * '<S143>' : 'codegen_arm/control_arm/PID Controller3/postSat Signal'
 * '<S144>' : 'codegen_arm/control_arm/PID Controller3/preInt Signal'
 * '<S145>' : 'codegen_arm/control_arm/PID Controller3/preSat Signal'
 * '<S146>' : 'codegen_arm/control_arm/PID Controller3/Anti-windup/Passthrough'
 * '<S147>' : 'codegen_arm/control_arm/PID Controller3/D Gain/Disabled'
 * '<S148>' : 'codegen_arm/control_arm/PID Controller3/External Derivative/Disabled'
 * '<S149>' : 'codegen_arm/control_arm/PID Controller3/Filter/Disabled'
 * '<S150>' : 'codegen_arm/control_arm/PID Controller3/Filter ICs/Disabled'
 * '<S151>' : 'codegen_arm/control_arm/PID Controller3/I Gain/Internal Parameters'
 * '<S152>' : 'codegen_arm/control_arm/PID Controller3/Ideal P Gain/Passthrough'
 * '<S153>' : 'codegen_arm/control_arm/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S154>' : 'codegen_arm/control_arm/PID Controller3/Integrator/Discrete'
 * '<S155>' : 'codegen_arm/control_arm/PID Controller3/Integrator ICs/Internal IC'
 * '<S156>' : 'codegen_arm/control_arm/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S157>' : 'codegen_arm/control_arm/PID Controller3/N Gain/Disabled'
 * '<S158>' : 'codegen_arm/control_arm/PID Controller3/P Copy/Disabled'
 * '<S159>' : 'codegen_arm/control_arm/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S160>' : 'codegen_arm/control_arm/PID Controller3/Reset Signal/Disabled'
 * '<S161>' : 'codegen_arm/control_arm/PID Controller3/Saturation/Passthrough'
 * '<S162>' : 'codegen_arm/control_arm/PID Controller3/Saturation Fdbk/Disabled'
 * '<S163>' : 'codegen_arm/control_arm/PID Controller3/Sum/Sum_PI'
 * '<S164>' : 'codegen_arm/control_arm/PID Controller3/Sum Fdbk/Disabled'
 * '<S165>' : 'codegen_arm/control_arm/PID Controller3/Tracking Mode/Disabled'
 * '<S166>' : 'codegen_arm/control_arm/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S167>' : 'codegen_arm/control_arm/PID Controller3/Tsamp - Integral/External Ts'
 * '<S168>' : 'codegen_arm/control_arm/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S169>' : 'codegen_arm/control_arm/PID Controller3/postSat Signal/Forward_Path'
 * '<S170>' : 'codegen_arm/control_arm/PID Controller3/preInt Signal/Internal PreInt'
 * '<S171>' : 'codegen_arm/control_arm/PID Controller3/preSat Signal/Forward_Path'
 * '<S172>' : 'codegen_arm/control_arm/PID Controller4/Anti-windup'
 * '<S173>' : 'codegen_arm/control_arm/PID Controller4/D Gain'
 * '<S174>' : 'codegen_arm/control_arm/PID Controller4/External Derivative'
 * '<S175>' : 'codegen_arm/control_arm/PID Controller4/Filter'
 * '<S176>' : 'codegen_arm/control_arm/PID Controller4/Filter ICs'
 * '<S177>' : 'codegen_arm/control_arm/PID Controller4/I Gain'
 * '<S178>' : 'codegen_arm/control_arm/PID Controller4/Ideal P Gain'
 * '<S179>' : 'codegen_arm/control_arm/PID Controller4/Ideal P Gain Fdbk'
 * '<S180>' : 'codegen_arm/control_arm/PID Controller4/Integrator'
 * '<S181>' : 'codegen_arm/control_arm/PID Controller4/Integrator ICs'
 * '<S182>' : 'codegen_arm/control_arm/PID Controller4/N Copy'
 * '<S183>' : 'codegen_arm/control_arm/PID Controller4/N Gain'
 * '<S184>' : 'codegen_arm/control_arm/PID Controller4/P Copy'
 * '<S185>' : 'codegen_arm/control_arm/PID Controller4/Parallel P Gain'
 * '<S186>' : 'codegen_arm/control_arm/PID Controller4/Reset Signal'
 * '<S187>' : 'codegen_arm/control_arm/PID Controller4/Saturation'
 * '<S188>' : 'codegen_arm/control_arm/PID Controller4/Saturation Fdbk'
 * '<S189>' : 'codegen_arm/control_arm/PID Controller4/Sum'
 * '<S190>' : 'codegen_arm/control_arm/PID Controller4/Sum Fdbk'
 * '<S191>' : 'codegen_arm/control_arm/PID Controller4/Tracking Mode'
 * '<S192>' : 'codegen_arm/control_arm/PID Controller4/Tracking Mode Sum'
 * '<S193>' : 'codegen_arm/control_arm/PID Controller4/Tsamp - Integral'
 * '<S194>' : 'codegen_arm/control_arm/PID Controller4/Tsamp - Ngain'
 * '<S195>' : 'codegen_arm/control_arm/PID Controller4/postSat Signal'
 * '<S196>' : 'codegen_arm/control_arm/PID Controller4/preInt Signal'
 * '<S197>' : 'codegen_arm/control_arm/PID Controller4/preSat Signal'
 * '<S198>' : 'codegen_arm/control_arm/PID Controller4/Anti-windup/Passthrough'
 * '<S199>' : 'codegen_arm/control_arm/PID Controller4/D Gain/Disabled'
 * '<S200>' : 'codegen_arm/control_arm/PID Controller4/External Derivative/Disabled'
 * '<S201>' : 'codegen_arm/control_arm/PID Controller4/Filter/Disabled'
 * '<S202>' : 'codegen_arm/control_arm/PID Controller4/Filter ICs/Disabled'
 * '<S203>' : 'codegen_arm/control_arm/PID Controller4/I Gain/Internal Parameters'
 * '<S204>' : 'codegen_arm/control_arm/PID Controller4/Ideal P Gain/Passthrough'
 * '<S205>' : 'codegen_arm/control_arm/PID Controller4/Ideal P Gain Fdbk/Disabled'
 * '<S206>' : 'codegen_arm/control_arm/PID Controller4/Integrator/Discrete'
 * '<S207>' : 'codegen_arm/control_arm/PID Controller4/Integrator ICs/Internal IC'
 * '<S208>' : 'codegen_arm/control_arm/PID Controller4/N Copy/Disabled wSignal Specification'
 * '<S209>' : 'codegen_arm/control_arm/PID Controller4/N Gain/Disabled'
 * '<S210>' : 'codegen_arm/control_arm/PID Controller4/P Copy/Disabled'
 * '<S211>' : 'codegen_arm/control_arm/PID Controller4/Parallel P Gain/Internal Parameters'
 * '<S212>' : 'codegen_arm/control_arm/PID Controller4/Reset Signal/Disabled'
 * '<S213>' : 'codegen_arm/control_arm/PID Controller4/Saturation/Passthrough'
 * '<S214>' : 'codegen_arm/control_arm/PID Controller4/Saturation Fdbk/Disabled'
 * '<S215>' : 'codegen_arm/control_arm/PID Controller4/Sum/Sum_PI'
 * '<S216>' : 'codegen_arm/control_arm/PID Controller4/Sum Fdbk/Disabled'
 * '<S217>' : 'codegen_arm/control_arm/PID Controller4/Tracking Mode/Disabled'
 * '<S218>' : 'codegen_arm/control_arm/PID Controller4/Tracking Mode Sum/Passthrough'
 * '<S219>' : 'codegen_arm/control_arm/PID Controller4/Tsamp - Integral/External Ts'
 * '<S220>' : 'codegen_arm/control_arm/PID Controller4/Tsamp - Ngain/Passthrough'
 * '<S221>' : 'codegen_arm/control_arm/PID Controller4/postSat Signal/Forward_Path'
 * '<S222>' : 'codegen_arm/control_arm/PID Controller4/preInt Signal/Internal PreInt'
 * '<S223>' : 'codegen_arm/control_arm/PID Controller4/preSat Signal/Forward_Path'
 */
#endif                                 /* control_arm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
