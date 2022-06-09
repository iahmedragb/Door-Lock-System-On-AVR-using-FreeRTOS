################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/HC_05/HC_05_Prog.c 

OBJS += \
./HAL/HC_05/HC_05_Prog.o 

C_DEPS += \
./HAL/HC_05/HC_05_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/HC_05/%.o: ../HAL/HC_05/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


