################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/domain/fsm.c \
../src/domain/menu_manager.c 

OBJS += \
./src/domain/fsm.o \
./src/domain/menu_manager.o 

C_DEPS += \
./src/domain/fsm.d \
./src/domain/menu_manager.d 


# Each subdirectory must supply rules for building sources it contributes
src/domain/%.o: ../src/domain/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../zybo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


