#include "stm32f4xx.h"
#include "gpio.h"

void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char defstate)
{
	/*Enable clock to GBIOx (no clock will be enabled in case GPIOx is not one of the ports)*/
	if (GPIOx==GPIOA)
		RCC->AHB1ENR |= (1u<<0);
	else if (GPIOx==GPIOB)
		RCC->AHB1ENR |= (1u<<1);
	else if (GPIOx==GPIOC)
		RCC->AHB1ENR |= (1u<<2);
	else if (GPIOx==GPIOD)
		RCC->AHB1ENR |= (1u<<3);
	else if (GPIOx==GPIOE)
		RCC->AHB1ENR |= (1u<<4);
	else if (GPIOx==GPIOH)
		RCC->AHB1ENR |= (1u<<7);

	/*set direction of pin*/
	switch(dir) {
		  case 0:
			  /*	00: Input (reset state)*/
				GPIOx->MODER &=~  ((uint32_t)1<<(2*pin));
				GPIOx->MODER &=~ ( (uint32_t)1<<(2*pin+1));
				GPIO_SetInput(GPIOx,pin,defstate);
			break;
		  case 1:
			  /*	01: General purpose output mode*/
			GPIOx->MODER |=  ((uint32_t)1<<(2*pin));
			GPIOx->MODER &=~ ((uint32_t)1<<(2*pin+1));
			GPIO_SetOutput(GPIOx,pin,defstate);
		    break;

		  case 2:
			  /*	10: Alternate function mode*/
				GPIOx->MODER &=~((uint32_t)1<<(2*pin));
				GPIOx->MODER |= ((uint32_t)1<<(2*pin+1));
				GPIO_pull(GPIOx,pin,defstate);
			break;

		  case 3:
			  /*	11: Analog mode*/
				GPIOx->MODER |= ((uint32_t) 1<<(2*pin));
				GPIOx->MODER |= ((uint32_t) 1<<(2*pin+1));
		    break;
		   default:
		     break;
		}
//	if(dir) /*output*/
//	{
//		GPIOx->MODER |= (1u<<(2*pin));
//		GPIOx->MODER &=~(1u<<(2*pin+1));
//		GPIO_SetOutput(GPIOx,pin,defstate);
//	}
//	else /*input*/
//	{
//		GPIOx->MODER &=~(1u<<(2*pin));
//		GPIOx->MODER &=~(1u<<(2*pin+1));
//		GPIO_SetInput(GPIOx,pin,defstate);
//
//	}

}

void GPIO_pull(GPIO_TypeDef * GPIOx, unsigned char pin, unsigned char state){
	switch(state) {
	  case 0:
		  /*	00:  No pull-up, pull-down*/
			GPIOx->PUPDR &=~((uint32_t) 1 <<(2*pin));
			GPIOx->PUPDR &=~((uint32_t) 1 <<(2*pin+1));
		break;
	  case 1:
		  /*	01: Pull-up*/
		GPIOx->PUPDR |= ((uint32_t) 1<<(2*pin));
		GPIOx->PUPDR &=~((uint32_t) 1<<(2*pin+1));
	    break;
	  case 2:
		  /*	10: Pull-down*/
			GPIOx->PUPDR &=~((uint32_t) 1<<(2*pin));
			GPIOx->PUPDR |= ((uint32_t) 1<<(2*pin+1));
	    break;
	  case 3:
		  /*	11: Reserved*/
			GPIOx->PUPDR |= ((uint32_t) 1<<(2*pin));
			GPIOx->PUPDR |= ((uint32_t) 1<<(2*pin+1));
	    break;
	    default:
	    break;
	}
}
/*PP_OD=0: Push-Pull
 *PP_OD=1: Open-Drain
 */
char GPIO_SetOutput(GPIO_TypeDef * GPIOx,char pin,char PP_OD)
{
	/*check pin is output*/
	if( (GPIOx->MODER & (1u<<(2*pin))) && ( !(GPIOx->MODER & (1u<<(2*pin+1))) ) )
	{
		/*check PU_OD carries a valid input*/
		if (PP_OD ==0 || PP_OD ==1)
		{
		/*write content of PU_OD on the pin's bit in OTYPER*/
		GPIOx->OTYPER = ( (GPIOx->OTYPER & ~((1u<<(pin))))  | (PP_OD<<pin) );
		}
		return 1; /*SUCCESS*/
	}

	else
	{
		return 0; /*FAILURE*/
	}
}


/* PU_PD=0: No Pull-UP or PULL-DOWN
 * PU_PD=1: Pull-UP
 * PU_PD=2: PULL-DOWN
 */
char GPIO_SetInput(GPIO_TypeDef * GPIOx,char pin,char PU_PD)
{
	/*check pin is input*/
	if(!( (GPIOx->MODER & (1u<<(2*pin))) || (GPIOx->MODER & (1u<<(2*pin+1))) ))
	{
		/*check PU_PD carries a valid input*/
		if (PU_PD ==0 || PU_PD ==1 || PU_PD ==2 )
		{
		/*write content of PU_PD on the pin's two bits in PUDPR*/
		GPIOx->PUPDR = (GPIOx->PUPDR & ~((1u<<(2*pin)) | (1u<<(2*pin+1)))) | (PU_PD<<2*pin);
		}
		return 1; /*SUCCESS*/
	}

	else
	{
		return 0; /*FAILURE*/
	}
}



char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state)
{
	if (GPIOx->MODER & (1u<<(2*pin)))
	{
		if(state)
			{
				GPIOx->ODR |=(1u<<pin);
			}
			else
			{
				GPIOx->ODR &=~(1u<<pin);
			}
		return 1;
	}
	else
	{
		return 0;
	}
}

// returns input pin state
char GPIO_Read(GPIO_TypeDef * GPIOx,char pin)
{   /*check pin is input*/
	if (!( (GPIOx->MODER & (1u<<(2*pin))) || (GPIOx->MODER & (1u<<(2*pin+1))) ))
	{
		if( (GPIOx->IDR) & (1<<pin) )
			return 1; /*return state High*/
		else
			return 0; /*return state Low*/
	}
	else
	{
		return -1; /*Pin is not input*/
	}
}

