################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Lib/efm8_assert/assert.c 

OBJS += \
./lib/efm8_assert/assert.OBJ 


# Each subdirectory must supply rules for building sources it contributes
lib/efm8_assert/assert.OBJ: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Lib/efm8_assert/assert.c lib/efm8_assert/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	wine "/Applications/Simplicity Studio.app/Contents/Eclipse/developer/toolchains/keil_8051/9.60/BIN/C51" "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '


