################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Models/Curso.cpp \
../src/Models/Ejercicio.cpp \
../src/Models/EjercicioCompletar.cpp \
../src/Models/EjercicioTraduccion.cpp \
../src/Models/Estudiante.cpp \
../src/Models/Idioma.cpp \
../src/Models/Incripcion.cpp \
../src/Models/Leccion.cpp \
../src/Models/Profesor.cpp \
../src/Models/Usuario.cpp 

CPP_DEPS += \
./src/Models/Curso.d \
./src/Models/Ejercicio.d \
./src/Models/EjercicioCompletar.d \
./src/Models/EjercicioTraduccion.d \
./src/Models/Estudiante.d \
./src/Models/Idioma.d \
./src/Models/Incripcion.d \
./src/Models/Leccion.d \
./src/Models/Profesor.d \
./src/Models/Usuario.d 

OBJS += \
./src/Models/Curso.o \
./src/Models/Ejercicio.o \
./src/Models/EjercicioCompletar.o \
./src/Models/EjercicioTraduccion.o \
./src/Models/Estudiante.o \
./src/Models/Idioma.o \
./src/Models/Incripcion.o \
./src/Models/Leccion.o \
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
	-$(RM) ./src/Models/Curso.d ./src/Models/Curso.o ./src/Models/Ejercicio.d ./src/Models/Ejercicio.o ./src/Models/EjercicioCompletar.d ./src/Models/EjercicioCompletar.o ./src/Models/EjercicioTraduccion.d ./src/Models/EjercicioTraduccion.o ./src/Models/Estudiante.d ./src/Models/Estudiante.o ./src/Models/Idioma.d ./src/Models/Idioma.o ./src/Models/Incripcion.d ./src/Models/Incripcion.o ./src/Models/Leccion.d ./src/Models/Leccion.o ./src/Models/Profesor.d ./src/Models/Profesor.o ./src/Models/Usuario.d ./src/Models/Usuario.o

.PHONY: clean-src-2f-Models

