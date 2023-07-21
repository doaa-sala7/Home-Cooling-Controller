################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/src/PID.c \
../Drivers/src/PollDataClient.c \
../Drivers/src/PollerTimer.c \
../Drivers/src/SPI.c \
../Drivers/src/TIM.c \
../Drivers/src/device.c \
../Drivers/src/gpio.c \
../Drivers/src/poller.c 

OBJS += \
./Drivers/src/PID.o \
./Drivers/src/PollDataClient.o \
./Drivers/src/PollerTimer.o \
./Drivers/src/SPI.o \
./Drivers/src/TIM.o \
./Drivers/src/device.o \
./Drivers/src/gpio.o \
./Drivers/src/poller.o 

C_DEPS += \
./Drivers/src/PID.d \
./Drivers/src/PollDataClient.d \
./Drivers/src/PollerTimer.d \
./Drivers/src/SPI.d \
./Drivers/src/TIM.d \
./Drivers/src/device.d \
./Drivers/src/gpio.d \
./Drivers/src/poller.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/src/%.o: ../Drivers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -I"C:/Users/MS/workspace/43_polling/inc" -I"C:/Users/MS/workspace/43_polling/CMSIS/device" -I"C:/Users/MS/workspace/43_polling/CMSIS/core" -I"C:/Users/MS/workspace/43_polling/Drivers/inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


