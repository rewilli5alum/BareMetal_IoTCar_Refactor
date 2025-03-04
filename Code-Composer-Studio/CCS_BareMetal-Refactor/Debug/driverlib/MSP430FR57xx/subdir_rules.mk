################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
driverlib/MSP430FR57xx/%.obj: ../driverlib/MSP430FR57xx/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"/Applications/ti/ccs2002/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --use_hw_mpy=F5 --include_path="/Applications/ti/ccs2002/ccs/ccs_base/msp430/include" --include_path="/Users/devrew/Documents/PROJ_CCS/CCS_Git/BareMetal_IoTCar_Refactor/Code-Composer-Studio/CCS_BareMetal-Refactor" --include_path="/Users/devrew/Documents/PROJ_CCS/CCS_Git/BareMetal_IoTCar_Refactor/Code-Composer-Studio/CCS_BareMetal-Refactor/driverlib/MSP430FR57xx" --include_path="/Applications/ti/ccs2002/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="none" --define=__MSP430FR5739__ --define=_MPU_ENABLE --define=DEPRECATED -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="driverlib/MSP430FR57xx/$(basename $(<F)).d_raw" --obj_directory="driverlib/MSP430FR57xx" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


