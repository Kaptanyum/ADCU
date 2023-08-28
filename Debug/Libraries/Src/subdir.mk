################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Src/gpio.c \
../Libraries/Src/hcsr04.c \
../Libraries/Src/i2c.c \
../Libraries/Src/mpu6050.c \
../Libraries/Src/tim.c 

OBJS += \
./Libraries/Src/gpio.o \
./Libraries/Src/hcsr04.o \
./Libraries/Src/i2c.o \
./Libraries/Src/mpu6050.o \
./Libraries/Src/tim.o 

C_DEPS += \
./Libraries/Src/gpio.d \
./Libraries/Src/hcsr04.d \
./Libraries/Src/i2c.d \
./Libraries/Src/mpu6050.d \
./Libraries/Src/tim.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Src/%.o Libraries/Src/%.su Libraries/Src/%.cyclo: ../Libraries/Src/%.c Libraries/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"../Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"../Drivers/CMSIS/Include" -I"../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"../Drivers/STM32F4xx_HAL_Driver/Inc" -I../Libraries/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Libraries-2f-Src

clean-Libraries-2f-Src:
	-$(RM) ./Libraries/Src/gpio.cyclo ./Libraries/Src/gpio.d ./Libraries/Src/gpio.o ./Libraries/Src/gpio.su ./Libraries/Src/hcsr04.cyclo ./Libraries/Src/hcsr04.d ./Libraries/Src/hcsr04.o ./Libraries/Src/hcsr04.su ./Libraries/Src/i2c.cyclo ./Libraries/Src/i2c.d ./Libraries/Src/i2c.o ./Libraries/Src/i2c.su ./Libraries/Src/mpu6050.cyclo ./Libraries/Src/mpu6050.d ./Libraries/Src/mpu6050.o ./Libraries/Src/mpu6050.su ./Libraries/Src/tim.cyclo ./Libraries/Src/tim.d ./Libraries/Src/tim.o ./Libraries/Src/tim.su

.PHONY: clean-Libraries-2f-Src

