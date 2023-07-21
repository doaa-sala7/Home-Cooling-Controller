/*
 * PollerTimer.c
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */
#include "PollerTimer.h"
#include "stm32f4xx.h"
#include "poller.h"


void StartTimer(void)
{
	/*Enable timer 2*/
	RCC->APB1ENR |=(1u<<0);

	TIM2->PSC = 1600-1;
	TIM2->ARR = 100;

	/*clear timer counter*/
	TIM2->CNT = 0;

	/*Enable  timer*/
	TIM2->CR1 |= (1u<<0);
}

void StopTimer(void)
{
	TIM2->CR1 &= ~(1u<<0);
}
void EnableInterrupt(void)
{
	/*Enable timer interrupt*/
	TIM2->DIER |= (1<<0);
	/*Enable timer interrupt NVIC*/
	NVIC_EnableIRQ(TIM2_IRQn);

}

void DisableInterrupt(void)
{
	/*Enable timer interrupt NVIC*/
	NVIC_DisableIRQ(TIM2_IRQn);
	/*Enable timer interrupt*/
	TIM2->DIER &= ~(1u<<0);
}

void CallPollingFunction(void)
{
	Poll();
}

