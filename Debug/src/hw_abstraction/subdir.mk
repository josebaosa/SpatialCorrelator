################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hw_abstraction/console_stream.c \
../src/hw_abstraction/file_stream.c \
../src/hw_abstraction/vga_graphics.c 

OBJS += \
./src/hw_abstraction/console_stream.o \
./src/hw_abstraction/file_stream.o \
./src/hw_abstraction/vga_graphics.o 

C_DEPS += \
./src/hw_abstraction/console_stream.d \
./src/hw_abstraction/file_stream.d \
./src/hw_abstraction/vga_graphics.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw_abstraction/%.o: ../src/hw_abstraction/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../zybo_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


