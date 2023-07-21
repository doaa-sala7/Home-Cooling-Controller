/*
 * PollerTimer.h
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */

#ifndef INC_POLLERTIMER_H_
#define INC_POLLERTIMER_H_

void StartTimer(void);
void StopTimer(void);
void EnableInterrupt(void);
void DisableInterrupt(void);
void CallPollingFunction(void);

#endif /* INC_POLLERTIMER_H_ */
