/*
 * PollingDataClient.h
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */

#ifndef INC_POLLINGDATACLIENT_H_
#define INC_POLLINGDATACLIENT_H_

#define KP  0.1f
#define KI  0.01f
#define KD  0.0f
#define T_sample   0.5f
#define MIN   0.0f
#define MAX   73.0f
void Handle_data(double data);
double PId_equation(double set ,double measure);

#endif /* INC_POLLINGDATACLIENT_H_ */
