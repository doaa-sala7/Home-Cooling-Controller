/*
 * SPI.c
 *
 *  Created on: Dec 10, 2022
 *      Author: Doaa
 */
#include "stm32f4xx.h"
#include "SPI.h"


void SPI1_INIT(void)
{
	/*Enable clock access to GPIOA*/
	RCC->AHB1ENR |=(1U<<0);

	/*Set Alternate function mode*/
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |= (1U<<11);

	GPIOA->MODER &=~(1U<<12);
	GPIOA->MODER |= (1U<<13);

	GPIOA->MODER &=~(1U<<14);
	GPIOA->MODER |= (1U<<15);

	/*AF05 TO THE THREE PINS*/
//	GPIOA->AFR[0] &= ~0xAAA00000;
	GPIOA->AFR[0] |= 0x55500000;

	/**********************************/
	/*Enable clock access to SPI1*/
	RCC->APB2ENR |=(1U<<12);

	/*SET BAUD RATE TO FPCLK/8*/
	SPI1->CR1 |=(1U<<4);

	/*FULL DUPLEX*/
	//SPI1->CR1 &=~(1U<<10);

	/*Set to CPOL, CPHA*/
	SPI1->CR1 &=~(1U<<1);
	SPI1->CR1 |=(1U<<0);

	/*Set data frame format*/
	SPI1->CR1 &=~(1U<<11);

	/*SET MSB FIRST*/
	SPI1->CR1 &=~(1U<<7);

	/*Set Software slave management*/
	SPI1->CR1 |=(1U<<8);
	SPI1->CR1 |=(1U<<9);

	/*Set to master*/
	SPI1->CR1 |=(1U<<2);

	/*SPI enable*/
	SPI1->CR1 |=(1U<<6);

}

unsigned char transmit_recieve(unsigned char TxData)
{
	if(SPI1->SR &(1<<1))
	{
		SPI1->DR =TxData;
		while(SPI1->SR & (1U<<7));
		return SPI1->DR;

	}
	return -1;
}

void SPI1_Write(unsigned char data)
{
	/*Write data to data register*/
	SPI1->DR = data;
	while(!(SPI1->SR & (1U<<1))){}
}

unsigned char SPI1_Read(void)
{
	while(!(SPI1->SR & (1U<<0))){}
	return SPI1->DR;
}

void SPI1_CS_ENABLE(void)
{
	GPIOA->ODR &=~(1U<<9);
}

void SPI1_CS_DISABLE(void)
{
	GPIOA->ODR |=(1U<<9);
}
