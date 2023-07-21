/*
 * device.c
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */
#include "device.h"
#include "gpio.h"
#include "SPI.h"
#include "stm32f4xx.h"
float data;
unsigned char spiData=0;
float temperature=0;

void TC72_init (void)
{
	TC72_register_write(0x80,0x00);
}

void TC72_register_write(unsigned char RegAdd, unsigned char Data)
{
	transmit_recieve( RegAdd |(1<<7));
	transmit_recieve(Data);

}

void TC72_register_read(unsigned char RegAdd, unsigned char *Dataptr)
{
	transmit_recieve( RegAdd &(~ (1<<7)));
	*Dataptr = transmit_recieve(0x00);
}

float Get_Data(void)
{
	temperature=0;
	GPIO_Write(GPIOB,0,1);

	TC72_register_read(0x02,&spiData);
	GPIO_Write(GPIOB,0,0);
	temperature = (signed char)spiData;

	return temperature;
}
