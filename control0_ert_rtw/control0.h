/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: control0.h
 *
 * Code generated for Simulink model 'control0'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Fri Feb 13 12:09:22 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef control0_h_
#define control0_h_
#ifndef control0_COMMON_INCLUDES_
#define control0_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* control0_COMMON_INCLUDES_ */

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
  real_T UnitDelay5_DSTATE;            /* '<S1>/Unit Delay5' */
  real_T Integrator_DSTATE;            /* '<S47>/Integrator' */
  real_T Integrator_DSTATE_g;          /* '<S99>/Integrator' */
  real_T Integrator_DSTATE_d;          /* '<S203>/Integrator' */
  real_T UnitDelay7_DSTATE;            /* '<S1>/Unit Delay7' */
  real_T Integrator_DSTATE_c;          /* '<S151>/Integrator' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  int32_T clockTickCounter_h;          /* '<S1>/Pulse Generator1' */
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
  real_T actualposition_a;          /* '<Root>/gripperRotationActualPosition' */
  real_T actualposition_d;             /* '<Root>/gripperPitchActualPosition' */
  real_T actualposition_i;             /* '<Root>/baseActualPosition' */
  real_T actualposition_c;             /* '<Root>/stepperLeftActualPosition' */
  real_T actualposition_h;             /* '<Root>/stepperRightActualPosition' */
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
extern void control0_initialize(void);
extern void control0_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S1>/base rotation' : Unused code path elimination
 * Block '<S1>/gripper jaw' : Unused code path elimination
 * Block '<S1>/gripper pitch' : Unused code path elimination
 * Block '<S1>/gripper rotation' : Unused code path elimination
 * Block '<S1>/left base' : Unused code path elimination
 * Block '<S1>/right base' : Unused code path elimination
 * Block '<S96>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S104>/Proportional Gain' : Eliminated nontunable gain of 1
 * Block '<S200>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S208>/Proportional Gain' : Eliminated nontunable gain of 1
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
 * hilite_system('codegen/control')    - opens subsystem codegen/control
 * hilite_system('codegen/control/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'codegen'
 * '<S1>'   : 'codegen/control'
 * '<S2>'   : 'codegen/control/Compare To Constant'
 * '<S3>'   : 'codegen/control/Compare To Constant1'
 * '<S4>'   : 'codegen/control/Compare To Constant2'
 * '<S5>'   : 'codegen/control/MATLAB Function'
 * '<S6>'   : 'codegen/control/MATLAB Function1'
 * '<S7>'   : 'codegen/control/MATLAB Function2'
 * '<S8>'   : 'codegen/control/PID Controller1'
 * '<S9>'   : 'codegen/control/PID Controller2'
 * '<S10>'  : 'codegen/control/PID Controller3'
 * '<S11>'  : 'codegen/control/PID Controller4'
 * '<S12>'  : 'codegen/control/inverse kinematics'
 * '<S13>'  : 'codegen/control/PID Controller1/Anti-windup'
 * '<S14>'  : 'codegen/control/PID Controller1/D Gain'
 * '<S15>'  : 'codegen/control/PID Controller1/External Derivative'
 * '<S16>'  : 'codegen/control/PID Controller1/Filter'
 * '<S17>'  : 'codegen/control/PID Controller1/Filter ICs'
 * '<S18>'  : 'codegen/control/PID Controller1/I Gain'
 * '<S19>'  : 'codegen/control/PID Controller1/Ideal P Gain'
 * '<S20>'  : 'codegen/control/PID Controller1/Ideal P Gain Fdbk'
 * '<S21>'  : 'codegen/control/PID Controller1/Integrator'
 * '<S22>'  : 'codegen/control/PID Controller1/Integrator ICs'
 * '<S23>'  : 'codegen/control/PID Controller1/N Copy'
 * '<S24>'  : 'codegen/control/PID Controller1/N Gain'
 * '<S25>'  : 'codegen/control/PID Controller1/P Copy'
 * '<S26>'  : 'codegen/control/PID Controller1/Parallel P Gain'
 * '<S27>'  : 'codegen/control/PID Controller1/Reset Signal'
 * '<S28>'  : 'codegen/control/PID Controller1/Saturation'
 * '<S29>'  : 'codegen/control/PID Controller1/Saturation Fdbk'
 * '<S30>'  : 'codegen/control/PID Controller1/Sum'
 * '<S31>'  : 'codegen/control/PID Controller1/Sum Fdbk'
 * '<S32>'  : 'codegen/control/PID Controller1/Tracking Mode'
 * '<S33>'  : 'codegen/control/PID Controller1/Tracking Mode Sum'
 * '<S34>'  : 'codegen/control/PID Controller1/Tsamp - Integral'
 * '<S35>'  : 'codegen/control/PID Controller1/Tsamp - Ngain'
 * '<S36>'  : 'codegen/control/PID Controller1/postSat Signal'
 * '<S37>'  : 'codegen/control/PID Controller1/preInt Signal'
 * '<S38>'  : 'codegen/control/PID Controller1/preSat Signal'
 * '<S39>'  : 'codegen/control/PID Controller1/Anti-windup/Passthrough'
 * '<S40>'  : 'codegen/control/PID Controller1/D Gain/Disabled'
 * '<S41>'  : 'codegen/control/PID Controller1/External Derivative/Disabled'
 * '<S42>'  : 'codegen/control/PID Controller1/Filter/Disabled'
 * '<S43>'  : 'codegen/control/PID Controller1/Filter ICs/Disabled'
 * '<S44>'  : 'codegen/control/PID Controller1/I Gain/Internal Parameters'
 * '<S45>'  : 'codegen/control/PID Controller1/Ideal P Gain/Passthrough'
 * '<S46>'  : 'codegen/control/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S47>'  : 'codegen/control/PID Controller1/Integrator/Discrete'
 * '<S48>'  : 'codegen/control/PID Controller1/Integrator ICs/Internal IC'
 * '<S49>'  : 'codegen/control/PID Controller1/N Copy/Disabled wSignal Specification'
 * '<S50>'  : 'codegen/control/PID Controller1/N Gain/Disabled'
 * '<S51>'  : 'codegen/control/PID Controller1/P Copy/Disabled'
 * '<S52>'  : 'codegen/control/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S53>'  : 'codegen/control/PID Controller1/Reset Signal/Disabled'
 * '<S54>'  : 'codegen/control/PID Controller1/Saturation/Passthrough'
 * '<S55>'  : 'codegen/control/PID Controller1/Saturation Fdbk/Disabled'
 * '<S56>'  : 'codegen/control/PID Controller1/Sum/Sum_PI'
 * '<S57>'  : 'codegen/control/PID Controller1/Sum Fdbk/Disabled'
 * '<S58>'  : 'codegen/control/PID Controller1/Tracking Mode/Disabled'
 * '<S59>'  : 'codegen/control/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S60>'  : 'codegen/control/PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S61>'  : 'codegen/control/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S62>'  : 'codegen/control/PID Controller1/postSat Signal/Forward_Path'
 * '<S63>'  : 'codegen/control/PID Controller1/preInt Signal/Internal PreInt'
 * '<S64>'  : 'codegen/control/PID Controller1/preSat Signal/Forward_Path'
 * '<S65>'  : 'codegen/control/PID Controller2/Anti-windup'
 * '<S66>'  : 'codegen/control/PID Controller2/D Gain'
 * '<S67>'  : 'codegen/control/PID Controller2/External Derivative'
 * '<S68>'  : 'codegen/control/PID Controller2/Filter'
 * '<S69>'  : 'codegen/control/PID Controller2/Filter ICs'
 * '<S70>'  : 'codegen/control/PID Controller2/I Gain'
 * '<S71>'  : 'codegen/control/PID Controller2/Ideal P Gain'
 * '<S72>'  : 'codegen/control/PID Controller2/Ideal P Gain Fdbk'
 * '<S73>'  : 'codegen/control/PID Controller2/Integrator'
 * '<S74>'  : 'codegen/control/PID Controller2/Integrator ICs'
 * '<S75>'  : 'codegen/control/PID Controller2/N Copy'
 * '<S76>'  : 'codegen/control/PID Controller2/N Gain'
 * '<S77>'  : 'codegen/control/PID Controller2/P Copy'
 * '<S78>'  : 'codegen/control/PID Controller2/Parallel P Gain'
 * '<S79>'  : 'codegen/control/PID Controller2/Reset Signal'
 * '<S80>'  : 'codegen/control/PID Controller2/Saturation'
 * '<S81>'  : 'codegen/control/PID Controller2/Saturation Fdbk'
 * '<S82>'  : 'codegen/control/PID Controller2/Sum'
 * '<S83>'  : 'codegen/control/PID Controller2/Sum Fdbk'
 * '<S84>'  : 'codegen/control/PID Controller2/Tracking Mode'
 * '<S85>'  : 'codegen/control/PID Controller2/Tracking Mode Sum'
 * '<S86>'  : 'codegen/control/PID Controller2/Tsamp - Integral'
 * '<S87>'  : 'codegen/control/PID Controller2/Tsamp - Ngain'
 * '<S88>'  : 'codegen/control/PID Controller2/postSat Signal'
 * '<S89>'  : 'codegen/control/PID Controller2/preInt Signal'
 * '<S90>'  : 'codegen/control/PID Controller2/preSat Signal'
 * '<S91>'  : 'codegen/control/PID Controller2/Anti-windup/Passthrough'
 * '<S92>'  : 'codegen/control/PID Controller2/D Gain/Disabled'
 * '<S93>'  : 'codegen/control/PID Controller2/External Derivative/Disabled'
 * '<S94>'  : 'codegen/control/PID Controller2/Filter/Disabled'
 * '<S95>'  : 'codegen/control/PID Controller2/Filter ICs/Disabled'
 * '<S96>'  : 'codegen/control/PID Controller2/I Gain/Internal Parameters'
 * '<S97>'  : 'codegen/control/PID Controller2/Ideal P Gain/Passthrough'
 * '<S98>'  : 'codegen/control/PID Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S99>'  : 'codegen/control/PID Controller2/Integrator/Discrete'
 * '<S100>' : 'codegen/control/PID Controller2/Integrator ICs/Internal IC'
 * '<S101>' : 'codegen/control/PID Controller2/N Copy/Disabled wSignal Specification'
 * '<S102>' : 'codegen/control/PID Controller2/N Gain/Disabled'
 * '<S103>' : 'codegen/control/PID Controller2/P Copy/Disabled'
 * '<S104>' : 'codegen/control/PID Controller2/Parallel P Gain/Internal Parameters'
 * '<S105>' : 'codegen/control/PID Controller2/Reset Signal/Disabled'
 * '<S106>' : 'codegen/control/PID Controller2/Saturation/Passthrough'
 * '<S107>' : 'codegen/control/PID Controller2/Saturation Fdbk/Disabled'
 * '<S108>' : 'codegen/control/PID Controller2/Sum/Sum_PI'
 * '<S109>' : 'codegen/control/PID Controller2/Sum Fdbk/Disabled'
 * '<S110>' : 'codegen/control/PID Controller2/Tracking Mode/Disabled'
 * '<S111>' : 'codegen/control/PID Controller2/Tracking Mode Sum/Passthrough'
 * '<S112>' : 'codegen/control/PID Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S113>' : 'codegen/control/PID Controller2/Tsamp - Ngain/Passthrough'
 * '<S114>' : 'codegen/control/PID Controller2/postSat Signal/Forward_Path'
 * '<S115>' : 'codegen/control/PID Controller2/preInt Signal/Internal PreInt'
 * '<S116>' : 'codegen/control/PID Controller2/preSat Signal/Forward_Path'
 * '<S117>' : 'codegen/control/PID Controller3/Anti-windup'
 * '<S118>' : 'codegen/control/PID Controller3/D Gain'
 * '<S119>' : 'codegen/control/PID Controller3/External Derivative'
 * '<S120>' : 'codegen/control/PID Controller3/Filter'
 * '<S121>' : 'codegen/control/PID Controller3/Filter ICs'
 * '<S122>' : 'codegen/control/PID Controller3/I Gain'
 * '<S123>' : 'codegen/control/PID Controller3/Ideal P Gain'
 * '<S124>' : 'codegen/control/PID Controller3/Ideal P Gain Fdbk'
 * '<S125>' : 'codegen/control/PID Controller3/Integrator'
 * '<S126>' : 'codegen/control/PID Controller3/Integrator ICs'
 * '<S127>' : 'codegen/control/PID Controller3/N Copy'
 * '<S128>' : 'codegen/control/PID Controller3/N Gain'
 * '<S129>' : 'codegen/control/PID Controller3/P Copy'
 * '<S130>' : 'codegen/control/PID Controller3/Parallel P Gain'
 * '<S131>' : 'codegen/control/PID Controller3/Reset Signal'
 * '<S132>' : 'codegen/control/PID Controller3/Saturation'
 * '<S133>' : 'codegen/control/PID Controller3/Saturation Fdbk'
 * '<S134>' : 'codegen/control/PID Controller3/Sum'
 * '<S135>' : 'codegen/control/PID Controller3/Sum Fdbk'
 * '<S136>' : 'codegen/control/PID Controller3/Tracking Mode'
 * '<S137>' : 'codegen/control/PID Controller3/Tracking Mode Sum'
 * '<S138>' : 'codegen/control/PID Controller3/Tsamp - Integral'
 * '<S139>' : 'codegen/control/PID Controller3/Tsamp - Ngain'
 * '<S140>' : 'codegen/control/PID Controller3/postSat Signal'
 * '<S141>' : 'codegen/control/PID Controller3/preInt Signal'
 * '<S142>' : 'codegen/control/PID Controller3/preSat Signal'
 * '<S143>' : 'codegen/control/PID Controller3/Anti-windup/Passthrough'
 * '<S144>' : 'codegen/control/PID Controller3/D Gain/Disabled'
 * '<S145>' : 'codegen/control/PID Controller3/External Derivative/Disabled'
 * '<S146>' : 'codegen/control/PID Controller3/Filter/Disabled'
 * '<S147>' : 'codegen/control/PID Controller3/Filter ICs/Disabled'
 * '<S148>' : 'codegen/control/PID Controller3/I Gain/Internal Parameters'
 * '<S149>' : 'codegen/control/PID Controller3/Ideal P Gain/Passthrough'
 * '<S150>' : 'codegen/control/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S151>' : 'codegen/control/PID Controller3/Integrator/Discrete'
 * '<S152>' : 'codegen/control/PID Controller3/Integrator ICs/Internal IC'
 * '<S153>' : 'codegen/control/PID Controller3/N Copy/Disabled wSignal Specification'
 * '<S154>' : 'codegen/control/PID Controller3/N Gain/Disabled'
 * '<S155>' : 'codegen/control/PID Controller3/P Copy/Disabled'
 * '<S156>' : 'codegen/control/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S157>' : 'codegen/control/PID Controller3/Reset Signal/Disabled'
 * '<S158>' : 'codegen/control/PID Controller3/Saturation/Passthrough'
 * '<S159>' : 'codegen/control/PID Controller3/Saturation Fdbk/Disabled'
 * '<S160>' : 'codegen/control/PID Controller3/Sum/Sum_PI'
 * '<S161>' : 'codegen/control/PID Controller3/Sum Fdbk/Disabled'
 * '<S162>' : 'codegen/control/PID Controller3/Tracking Mode/Disabled'
 * '<S163>' : 'codegen/control/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S164>' : 'codegen/control/PID Controller3/Tsamp - Integral/TsSignalSpecification'
 * '<S165>' : 'codegen/control/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S166>' : 'codegen/control/PID Controller3/postSat Signal/Forward_Path'
 * '<S167>' : 'codegen/control/PID Controller3/preInt Signal/Internal PreInt'
 * '<S168>' : 'codegen/control/PID Controller3/preSat Signal/Forward_Path'
 * '<S169>' : 'codegen/control/PID Controller4/Anti-windup'
 * '<S170>' : 'codegen/control/PID Controller4/D Gain'
 * '<S171>' : 'codegen/control/PID Controller4/External Derivative'
 * '<S172>' : 'codegen/control/PID Controller4/Filter'
 * '<S173>' : 'codegen/control/PID Controller4/Filter ICs'
 * '<S174>' : 'codegen/control/PID Controller4/I Gain'
 * '<S175>' : 'codegen/control/PID Controller4/Ideal P Gain'
 * '<S176>' : 'codegen/control/PID Controller4/Ideal P Gain Fdbk'
 * '<S177>' : 'codegen/control/PID Controller4/Integrator'
 * '<S178>' : 'codegen/control/PID Controller4/Integrator ICs'
 * '<S179>' : 'codegen/control/PID Controller4/N Copy'
 * '<S180>' : 'codegen/control/PID Controller4/N Gain'
 * '<S181>' : 'codegen/control/PID Controller4/P Copy'
 * '<S182>' : 'codegen/control/PID Controller4/Parallel P Gain'
 * '<S183>' : 'codegen/control/PID Controller4/Reset Signal'
 * '<S184>' : 'codegen/control/PID Controller4/Saturation'
 * '<S185>' : 'codegen/control/PID Controller4/Saturation Fdbk'
 * '<S186>' : 'codegen/control/PID Controller4/Sum'
 * '<S187>' : 'codegen/control/PID Controller4/Sum Fdbk'
 * '<S188>' : 'codegen/control/PID Controller4/Tracking Mode'
 * '<S189>' : 'codegen/control/PID Controller4/Tracking Mode Sum'
 * '<S190>' : 'codegen/control/PID Controller4/Tsamp - Integral'
 * '<S191>' : 'codegen/control/PID Controller4/Tsamp - Ngain'
 * '<S192>' : 'codegen/control/PID Controller4/postSat Signal'
 * '<S193>' : 'codegen/control/PID Controller4/preInt Signal'
 * '<S194>' : 'codegen/control/PID Controller4/preSat Signal'
 * '<S195>' : 'codegen/control/PID Controller4/Anti-windup/Passthrough'
 * '<S196>' : 'codegen/control/PID Controller4/D Gain/Disabled'
 * '<S197>' : 'codegen/control/PID Controller4/External Derivative/Disabled'
 * '<S198>' : 'codegen/control/PID Controller4/Filter/Disabled'
 * '<S199>' : 'codegen/control/PID Controller4/Filter ICs/Disabled'
 * '<S200>' : 'codegen/control/PID Controller4/I Gain/Internal Parameters'
 * '<S201>' : 'codegen/control/PID Controller4/Ideal P Gain/Passthrough'
 * '<S202>' : 'codegen/control/PID Controller4/Ideal P Gain Fdbk/Disabled'
 * '<S203>' : 'codegen/control/PID Controller4/Integrator/Discrete'
 * '<S204>' : 'codegen/control/PID Controller4/Integrator ICs/Internal IC'
 * '<S205>' : 'codegen/control/PID Controller4/N Copy/Disabled wSignal Specification'
 * '<S206>' : 'codegen/control/PID Controller4/N Gain/Disabled'
 * '<S207>' : 'codegen/control/PID Controller4/P Copy/Disabled'
 * '<S208>' : 'codegen/control/PID Controller4/Parallel P Gain/Internal Parameters'
 * '<S209>' : 'codegen/control/PID Controller4/Reset Signal/Disabled'
 * '<S210>' : 'codegen/control/PID Controller4/Saturation/Passthrough'
 * '<S211>' : 'codegen/control/PID Controller4/Saturation Fdbk/Disabled'
 * '<S212>' : 'codegen/control/PID Controller4/Sum/Sum_PI'
 * '<S213>' : 'codegen/control/PID Controller4/Sum Fdbk/Disabled'
 * '<S214>' : 'codegen/control/PID Controller4/Tracking Mode/Disabled'
 * '<S215>' : 'codegen/control/PID Controller4/Tracking Mode Sum/Passthrough'
 * '<S216>' : 'codegen/control/PID Controller4/Tsamp - Integral/TsSignalSpecification'
 * '<S217>' : 'codegen/control/PID Controller4/Tsamp - Ngain/Passthrough'
 * '<S218>' : 'codegen/control/PID Controller4/postSat Signal/Forward_Path'
 * '<S219>' : 'codegen/control/PID Controller4/preInt Signal/Internal PreInt'
 * '<S220>' : 'codegen/control/PID Controller4/preSat Signal/Forward_Path'
 */
#endif                                 /* control0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
