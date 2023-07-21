#include "stm32f4xx.h"
#include "PollerTimer.h"
#include "poller.h"
#include "gpio.h"
#include "device.h"
#include "SPI.h"
#include "PID.h"
#include "TIM.h"
int main(void)
{

	GPIO_Init (GPIOA,0,1,0);

/*select slave*/
	GPIO_Init (GPIOB,0,1,0);
	Timer_PWM_Configeration();


	SPI1_INIT();
	GPIO_Write(GPIOB,0,1);
	TC72_init();
	GPIO_Write(GPIOB,0,0);



	StartTimer();
	EnableInterrupt();
	SetPollingTime(500);
	StartPolling();

	while(1)
	{
		//Time_update_timer(50);
//		int i;
//			float temperature=0.0f;
			//GPIO_Write(GPIOB,0,1);
			/*read low temerature regester (fraction)*/
			/*TC72_register_read(0x01,&spiData);
			GPIO_Write(GPIOB,0,0);
			if(spiData & (1 << 7))
			{
				temperature += 0.5f;
			}
			if(spiData & (1 << 6))
			{
				temperature +=0.25f;
			}

			/*read high temerature regester*/
			/*GPIO_Write(GPIOB,0,1);

			TC72_register_read(0x02,&spiData);
			GPIO_Write(GPIOB,0,0);
			temperature = (signed char)spiData;

			if(temperature > 25.0f)
			{
				GPIO_Write(GPIOA,0,1);
			}
			else
			{
				GPIO_Write(GPIOA,0,0);

			}*/


	}

}

void TIM2_IRQHandler(void)
{
	TIM2->SR &=~(1<<0);
	CallPollingFunction();
}


