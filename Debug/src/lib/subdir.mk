################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lib/bmp.c \
../src/lib/image.c \
../src/lib/spatial_correlator.c \
../src/lib/state_machine.c 

OBJS += \
./src/lib/bmp.o \
./src/lib/image.o \
./src/lib/spatial_correlator.o \
./src/lib/state_machine.o 

C_DEPS += \
./src/lib/bmp.d \
./src/lib/image.d \
./src/lib/spatial_correlator.d \
./src/lib/state_machine.d 


# Each subdirectory must supply rules for building sources it contributes
src/lib/%.o: ../src/lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../zybo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


