################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/EFM8BB1/peripheral_driver/src/pca_0.c \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/EFM8BB1/peripheral_driver/src/uart_0.c 

OBJS += \
./lib/efm8bb1/peripheralDrivers/src/pca_0.OBJ \
./lib/efm8bb1/peripheralDrivers/src/uart_0.OBJ 


# Each subdirectory must supply rules for building sources it contributes
lib/efm8bb1/peripheralDrivers/src/pca_0.OBJ: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/EFM8BB1/peripheral_driver/src/pca_0.c lib/efm8bb1/peripheralDrivers/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	wine "/Applications/Simplicity Studio.app/Contents/Eclipse/developer/toolchains/keil_8051/9.60/BIN/C51" "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

lib/efm8bb1/peripheralDrivers/src/pca_0.OBJ: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/EFM8BB1/peripheral_driver/inc/pca_0.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/toolchains/keil_8051/9.60/INC/ASSERT.H /Users/paul_leveque/Documents/10_Projets/EFM8BB1_PCA_Lib_8bitCenterPWM/inc/config/efm8_config.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/toolchains/keil_8051/9.60/INC/STDIO.H /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/toolchains/keil_8051/9.60/INC/STDLIB.H /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h

lib/efm8bb1/peripheralDrivers/src/uart_0.OBJ: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/EFM8BB1/peripheral_driver/src/uart_0.c lib/efm8bb1/peripheralDrivers/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	wine "/Applications/Simplicity Studio.app/Contents/Eclipse/developer/toolchains/keil_8051/9.60/BIN/C51" "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

lib/efm8bb1/peripheralDrivers/src/uart_0.OBJ: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/EFM8BB1/peripheral_driver/inc/uart_0.h /Users/paul_leveque/Documents/10_Projets/EFM8BB1_PCA_Lib_8bitCenterPWM/inc/config/efm8_config.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h


