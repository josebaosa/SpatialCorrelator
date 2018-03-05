################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/io/lib/bmp.c \
../src/io/lib/image.c \
../src/io/lib/spatial_correlator.c \
../src/io/lib/state_machine.c 

OBJS += \
./src/io/lib/bmp.o \
./src/io/lib/image.o \
./src/io/lib/spatial_correlator.o \
./src/io/lib/state_machine.o 

C_DEPS += \
./src/io/lib/bmp.d \
./src/io/lib/image.d \
./src/io/lib/spatial_correlator.d \
./src/io/lib/state_machine.d 


# Each subdirectory must supply rules for building sources it contributes
src/io/lib/%.o: ../src/io/lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../zybo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


