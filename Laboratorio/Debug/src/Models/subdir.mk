################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Models/Estudiante.cpp \
../src/Models/Idioma.cpp \
../src/Models/Profesor.cpp \
../src/Models/Usuario.cpp 

CPP_DEPS += \
./src/Models/Estudiante.d \
./src/Models/Idioma.d \
./src/Models/Profesor.d \
./src/Models/Usuario.d 

OBJS += \
./src/Models/Estudiante.o \
./src/Models/Idioma.o \
./src/Models/Profesor.o \
./src/Models/Usuario.o 


# Each subdirectory must supply rules for building sources it contributes
src/Models/%.o: ../src/Models/%.cpp src/Models/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-Models

clean-src-2f-Models:
	-$(RM) ./src/Models/Estudiante.d ./src/Models/Estudiante.o ./src/Models/Idioma.d ./src/Models/Idioma.o ./src/Models/Profesor.d ./src/Models/Profesor.o ./src/Models/Usuario.d ./src/Models/Usuario.o

.PHONY: clean-src-2f-Models

