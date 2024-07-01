################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/dto/DTOEstudiante.cpp \
../src/dto/DTOProfesor.cpp 

CPP_DEPS += \
./src/dto/DTOEstudiante.d \
./src/dto/DTOProfesor.d 

OBJS += \
./src/dto/DTOEstudiante.o \
./src/dto/DTOProfesor.o 


# Each subdirectory must supply rules for building sources it contributes
src/dto/%.o: ../src/dto/%.cpp src/dto/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-dto

clean-src-2f-dto:
	-$(RM) ./src/dto/DTOEstudiante.d ./src/dto/DTOEstudiante.o ./src/dto/DTOProfesor.d ./src/dto/DTOProfesor.o

.PHONY: clean-src-2f-dto

