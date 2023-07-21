///*
// * PID.h
// *
// *  Created on: Dec 13, 2022
// *      Author: Administrator
// */
//
//#ifndef INC_PID_H_
//#define INC_PID_H_
//
//#define PID_KP  0.1f
//#define PID_KI  0.01f
//#define PID_KD  0.0f
//
//#define PID_TAU 0.2f
//
//#define PID_LIM_MIN -10.0f
//#define PID_LIM_MAX  10.0f
//
//#define PID_LIM_MIN_INT -5.0f
//#define PID_LIM_MAX_INT  5.0f
//
//#define SAMPLE_TIME_S 0.5f
//typedef struct {
//
//	/* Controller gains */
//	float Kp;
//	float Ki;
//	float Kd;
//
//	/* Derivative low-pass filter time constant */
//	float tau;
//
//	/* Output limits */
//	float limMin;
//	float limMax;
//
//	/* Integrator limits */
//	float limMinInt;
//	float limMaxInt;
//
//	/* Sample time (in seconds) */
//	float T;
//
//	/* Controller "memory" */
//	float integrator;
//	float prevError;			/* Required for integrator */
//	float differentiator;
//	float prevMeasurement;		/* Required for differentiator */
//
//	/* Controller output */
//	float out;
//
//} PIDController;
//
////void  PIDController_Init(PIDController *pid);
//float PIDController_Update(PIDController *pid, float setpoint, float measurement);
//
//#endif /* INC_PID_H_ */
