/*
 * device.h
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */

#ifndef INC_DEVICE_H_
#define INC_DEVICE_H_
void TC72_init (void);
float Get_Data();
void TC72_register_write(unsigned char RegAdd, unsigned char Data);
void TC72_register_read(unsigned char RegAdd, unsigned char *Data);
#endif /* INC_DEVICE_H_ */
