################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Relay/Relay_Config.c \
../HAL/Relay/Relay_Prog.c 

OBJS += \
./HAL/Relay/Relay_Config.o \
./HAL/Relay/Relay_Prog.o 

C_DEPS += \
./HAL/Relay/Relay_Config.d \
./HAL/Relay/Relay_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Relay/%.o: ../HAL/Relay/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


