################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/io/graphics.c \
../src/io/memory.c \
../src/io/stream.c 

OBJS += \
./src/io/graphics.o \
./src/io/memory.o \
./src/io/stream.o 

C_DEPS += \
./src/io/graphics.d \
./src/io/memory.d \
./src/io/stream.d 


# Each subdirectory must supply rules for building sources it contributes
src/io/%.o: ../src/io/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../zybo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


