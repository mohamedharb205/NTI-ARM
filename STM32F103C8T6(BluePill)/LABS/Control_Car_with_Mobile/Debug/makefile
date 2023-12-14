################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Control_Car_with_Mobile
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Control_Car_with_Mobile.elf \

MAP_FILES += \
Control_Car_with_Mobile.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Control_Car_with_Mobile.list \

OBJCOPY_HEX += \
Control_Car_with_Mobile.hex \

OBJCOPY_BIN += \
Control_Car_with_Mobile.bin \


# All Target
all: main-build

# Main-build Target
main-build: Control_Car_with_Mobile.elf secondary-outputs

# Tool invocations
Control_Car_with_Mobile.elf Control_Car_with_Mobile.map: $(OBJS) $(USER_OBJS) E:\NTI\Workspaces\NTI-ARM\STM32F103C8T6(BluePill)\LABS\Control_Car_with_Mobile\STM32F103C8TX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "Control_Car_with_Mobile.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"E:\NTI\Workspaces\NTI-ARM\STM32F103C8T6(BluePill)\LABS\Control_Car_with_Mobile\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Control_Car_with_Mobile.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Control_Car_with_Mobile.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Control_Car_with_Mobile.list"
	@echo 'Finished building: $@'
	@echo ' '

Control_Car_with_Mobile.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "Control_Car_with_Mobile.hex"
	@echo 'Finished building: $@'
	@echo ' '

Control_Car_with_Mobile.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Control_Car_with_Mobile.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Control_Car_with_Mobile.bin Control_Car_with_Mobile.elf Control_Car_with_Mobile.hex Control_Car_with_Mobile.list Control_Car_with_Mobile.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
