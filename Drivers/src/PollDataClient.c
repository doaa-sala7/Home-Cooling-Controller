/*
 * PollDataClient.c
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */
#include "stm32f4xx.h"
#include "PollingDataClient.h"
#include "PID.h"
#include "TIM.h"

//float preverror=0;
double sumerror=0;
double error=0;
double setpoint=30.0f;

double frac=0.0f;
//uint16_t duty=0.0f;

void Handle_data(double data)
{


	frac=PId_equation(setpoint ,data);

	if((frac*73) > 73)
	{
		frac=73;
		Time_update_timer(frac);
	}
	else if((frac*73)<0)
	{
		frac=0;
		Time_update_timer(frac);
	}
	else
	{
		Time_update_timer((frac*73));
	}

}
double PId_equation(double set ,double measure){
	if(measure!=0)
	{
		error = set - measure;
		sumerror +=error;
	}

	double out=(KP*error)+(KI*(sumerror));
	//preverror=error;
	return out;
}
