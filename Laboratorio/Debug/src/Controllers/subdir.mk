################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Controllers/Sistema.cpp \
../src/Controllers/UsuarioController.cpp 

CPP_DEPS += \
./src/Controllers/Sistema.d \
./src/Controllers/UsuarioController.d 

OBJS += \
./src/Controllers/Sistema.o \
./src/Controllers/UsuarioController.o 


# Each subdirectory must supply rules for building sources it contributes
src/Controllers/%.o: ../src/Controllers/%.cpp src/Controllers/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-Controllers

clean-src-2f-Controllers:
	-$(RM) ./src/Controllers/Sistema.d ./src/Controllers/Sistema.o ./src/Controllers/UsuarioController.d ./src/Controllers/UsuarioController.o

.PHONY: clean-src-2f-Controllers

