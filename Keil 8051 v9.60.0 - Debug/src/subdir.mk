################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
A51_UPPER_SRCS += \
/Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/SILABS_STARTUP.A51 

C_SRCS += \
../src/InitDevice.c \
../src/PCA_Lib_8bitCenterPWM.c 

OBJS += \
./src/InitDevice.OBJ \
./src/PCA_Lib_8bitCenterPWM.OBJ \
./src/SILABS_STARTUP.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/%.OBJ: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	wine "/Applications/Simplicity Studio.app/Contents/Eclipse/developer/toolchains/keil_8051/9.60/BIN/C51" "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/InitDevice.OBJ: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h /Users/paul_leveque/Documents/10_Projets/EFM8BB1_PCA_Lib_8bitCenterPWM/inc/InitDevice.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h

src/PCA_Lib_8bitCenterPWM.OBJ: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/kits/common/bsp/bsp.h /Users/paul_leveque/Documents/10_Projets/EFM8BB1_PCA_Lib_8bitCenterPWM/inc/InitDevice.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/EFM8BB1/peripheral_driver/inc/pca_0.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/kits/EFM8BB1_LCK/config/bsp_config.h /Users/paul_leveque/Documents/10_Projets/EFM8BB1_PCA_Lib_8bitCenterPWM/inc/config/efm8_config.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h

src/SILABS_STARTUP.OBJ: /Applications/Simplicity\ Studio.app/Contents/Eclipse/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/SILABS_STARTUP.A51 src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	wine "/Applications/Simplicity Studio.app/Contents/Eclipse/developer/toolchains/keil_8051/9.60/BIN/AX51" "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '


