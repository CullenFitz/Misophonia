################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DSP/Src/audio_processing.c 

OBJS += \
./DSP/Src/audio_processing.o 

C_DEPS += \
./DSP/Src/audio_processing.d 


# Each subdirectory must supply rules for building sources it contributes
DSP/Src/%.o DSP/Src/%.su DSP/Src/%.cyclo: ../DSP/Src/%.c DSP/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../USB_HOST/App -I../DSP/Inc -I../audio_samples -I../USB_HOST/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-DSP-2f-Src

clean-DSP-2f-Src:
	-$(RM) ./DSP/Src/audio_processing.cyclo ./DSP/Src/audio_processing.d ./DSP/Src/audio_processing.o ./DSP/Src/audio_processing.su

.PHONY: clean-DSP-2f-Src

