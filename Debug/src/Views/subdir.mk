################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Views/AltaUsuario.cpp \
../src/Views/MenuPrincipal.cpp 

CPP_DEPS += \
./src/Views/AltaUsuario.d \
./src/Views/MenuPrincipal.d 

OBJS += \
./src/Views/AltaUsuario.o \
./src/Views/MenuPrincipal.o 


# Each subdirectory must supply rules for building sources it contributes
src/Views/%.o: ../src/Views/%.cpp src/Views/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-Views

clean-src-2f-Views:
	-$(RM) ./src/Views/AltaUsuario.d ./src/Views/AltaUsuario.o ./src/Views/MenuPrincipal.d ./src/Views/MenuPrincipal.o

.PHONY: clean-src-2f-Views

