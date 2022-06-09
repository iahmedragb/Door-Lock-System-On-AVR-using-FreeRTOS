################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Switch/Switch_Config.c \
../HAL/Switch/Switch_Prog.c 

OBJS += \
./HAL/Switch/Switch_Config.o \
./HAL/Switch/Switch_Prog.o 

C_DEPS += \
./HAL/Switch/Switch_Config.d \
./HAL/Switch/Switch_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Switch/%.o: ../HAL/Switch/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


