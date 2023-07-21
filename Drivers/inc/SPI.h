/*
 * SPI.h
 *
 *  Created on: Dec 10, 2022
 *      Author: Doaa
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

void SPI1_INIT(void);
void SPI1_Write(unsigned char data);
unsigned char SPI1_Read(void);
unsigned char transmit_recieve(unsigned char TxData);
void SPI1_CS_ENABLE(void);
void SPI1_CS_DISABLE(void);

#endif /* INC_SPI_H_ */
