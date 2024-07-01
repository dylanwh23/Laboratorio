################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ICollections/interfaces/ICollectible.cpp \
../src/ICollections/interfaces/ICollection.cpp \
../src/ICollections/interfaces/IDictionary.cpp \
../src/ICollections/interfaces/IIterator.cpp \
../src/ICollections/interfaces/IKey.cpp \
../src/ICollections/interfaces/OrderedKey.cpp 

CPP_DEPS += \
./src/ICollections/interfaces/ICollectible.d \
./src/ICollections/interfaces/ICollection.d \
./src/ICollections/interfaces/IDictionary.d \
./src/ICollections/interfaces/IIterator.d \
./src/ICollections/interfaces/IKey.d \
./src/ICollections/interfaces/OrderedKey.d 

OBJS += \
./src/ICollections/interfaces/ICollectible.o \
./src/ICollections/interfaces/ICollection.o \
./src/ICollections/interfaces/IDictionary.o \
./src/ICollections/interfaces/IIterator.o \
./src/ICollections/interfaces/IKey.o \
./src/ICollections/interfaces/OrderedKey.o 


# Each subdirectory must supply rules for building sources it contributes
src/ICollections/interfaces/%.o: ../src/ICollections/interfaces/%.cpp src/ICollections/interfaces/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-ICollections-2f-interfaces

clean-src-2f-ICollections-2f-interfaces:
	-$(RM) ./src/ICollections/interfaces/ICollectible.d ./src/ICollections/interfaces/ICollectible.o ./src/ICollections/interfaces/ICollection.d ./src/ICollections/interfaces/ICollection.o ./src/ICollections/interfaces/IDictionary.d ./src/ICollections/interfaces/IDictionary.o ./src/ICollections/interfaces/IIterator.d ./src/ICollections/interfaces/IIterator.o ./src/ICollections/interfaces/IKey.d ./src/ICollections/interfaces/IKey.o ./src/ICollections/interfaces/OrderedKey.d ./src/ICollections/interfaces/OrderedKey.o

.PHONY: clean-src-2f-ICollections-2f-interfaces

