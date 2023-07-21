
#include "stm32f4xx.h"
#include "GPIO.h"
#include "TIM.h"

void Timer_PWM_Configeration(void){

	GPIO_Init(GPIOA, 8u, 2u, 0u);
	//GPIO_pull(GPIOA, 8u, 0u);

	/*enable timer1 clock*/
	//RCC-> APB2ENR |= (uint32_t) RCC_AHB1ENR_GPIOAEN;
	RCC-> APB2ENR |= ((uint32_t) 1u<<0);


	/* Select alternate function AF1 for PA8 AFR1 = 0001*/
	//GPIOA -> AFR[1] &= ~((uint32_t) 7<<1);
	GPIOA-> AFR[1] |= ((uint32_t) 1<<0);


	/* Enable Auto-reload preload */
	TIM1->CR1 |=  ((uint32_t) 1u <<7);

	/* Set counter direction as up-counter*/
	TIM1->CR1 &= (uint32_t) (~(uint32_t) (1u<<4));

	/* Select master mode Compare : TIM_CR2_MMS_2: 0x0040 : 0100 0000*/
	//TIM1->CR2 |= (uint8_t) (1u<<6);

	/* Set timer Prescaler, bus clock 90 MHz, FCK_PSC /(PSC[15:0]+1)=5
	 CK_CNT= 180000000 / (1799 + 1) > 100000 Hz-> time base 10 us */
	TIM1->PSC = ((uint32_t)16000)-1u;

	/* Set timer auto reload value to maximum*/
	TIM1->ARR =(uint32_t) 0xFFFF;


	/* Set Capture Compare 1 as output : TIM_CCMR1_CC1S 0x0003*/
	TIM1->CCMR1 &=(uint8_t) (~(uint8_t)(1u<<0)) | ((uint8_t)(1u<<1));

	/* Output Compare 1 preload enable :  TIM_CCMR1_OC1PE 0x0008 = 00001000*/
	TIM1->CCMR1 |= (uint32_t) (1u<<3);

	/*Select Output Compare 1 PWM mode 2
	TIMx CNT < TIMX_CCR1 > Output Inactive */
	TIM1->CCMR1 |= (uint32_t) (1u<<5);
	TIM1->CCMR1 |= (uint32_t) (1u<<6);
	/* Select Capture Compare 1 output polarity active high : TIM_CCER_CC1P 0x0002*/
	TIM1->CCER &= (uint32_t) (~(uint32_t)(1u<<1));

	/*Initialize all the registers*/
	TIM1->EGR |= (uint32_t) (1u<<0);

	/*Enable Capture Compare 1 output*/
	TIM1->CCER |= (uint32_t) (1u<<0);

	/*Enable timer main output*/
	TIM1-> BDTR |=  (uint32_t)(1u<<15);

	/*Enable TIM1*/
	TIM1->CR1 |= (uint32_t)(1u<<0); /*TIM_CR1_CEN*/
}


void Time_update_timer(uint16_t PWM_duty_cycle)
{
	/* Calculate auto reload value .. all period 500HZ -- 2ms*/
    uint16_t auto_reload = (uint16_t) (250);
	TIM1->ARR = (uint32_t) auto_reload;


	/* Calculate capture compare value */
	uint16_t capture_compare = (uint16_t) ((PWM_duty_cycle * auto_reload) / (uint16_t) 100);
	TIM1 -> CCR1 = (uint32_t) capture_compare;
}

