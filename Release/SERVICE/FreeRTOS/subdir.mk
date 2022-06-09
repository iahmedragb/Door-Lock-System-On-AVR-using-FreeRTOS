################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SERVICE/FreeRTOS/croutine.c \
../SERVICE/FreeRTOS/heap_1.c \
../SERVICE/FreeRTOS/list.c \
../SERVICE/FreeRTOS/port.c \
../SERVICE/FreeRTOS/queue.c \
../SERVICE/FreeRTOS/tasks.c \
../SERVICE/FreeRTOS/timers.c 

OBJS += \
./SERVICE/FreeRTOS/croutine.o \
./SERVICE/FreeRTOS/heap_1.o \
./SERVICE/FreeRTOS/list.o \
./SERVICE/FreeRTOS/port.o \
./SERVICE/FreeRTOS/queue.o \
./SERVICE/FreeRTOS/tasks.o \
./SERVICE/FreeRTOS/timers.o 

C_DEPS += \
./SERVICE/FreeRTOS/croutine.d \
./SERVICE/FreeRTOS/heap_1.d \
./SERVICE/FreeRTOS/list.d \
./SERVICE/FreeRTOS/port.d \
./SERVICE/FreeRTOS/queue.d \
./SERVICE/FreeRTOS/tasks.d \
./SERVICE/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
SERVICE/FreeRTOS/%.o: ../SERVICE/FreeRTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


