################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ICollections/collections/List.cpp \
../src/ICollections/collections/ListIterator.cpp \
../src/ICollections/collections/ListNode.cpp \
../src/ICollections/collections/OrderedDictionary.cpp \
../src/ICollections/collections/OrderedDictionaryEntry.cpp 

CPP_DEPS += \
./src/ICollections/collections/List.d \
./src/ICollections/collections/ListIterator.d \
./src/ICollections/collections/ListNode.d \
./src/ICollections/collections/OrderedDictionary.d \
./src/ICollections/collections/OrderedDictionaryEntry.d 

OBJS += \
./src/ICollections/collections/List.o \
./src/ICollections/collections/ListIterator.o \
./src/ICollections/collections/ListNode.o \
./src/ICollections/collections/OrderedDictionary.o \
./src/ICollections/collections/OrderedDictionaryEntry.o 


# Each subdirectory must supply rules for building sources it contributes
src/ICollections/collections/%.o: ../src/ICollections/collections/%.cpp src/ICollections/collections/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-ICollections-2f-collections

clean-src-2f-ICollections-2f-collections:
	-$(RM) ./src/ICollections/collections/List.d ./src/ICollections/collections/List.o ./src/ICollections/collections/ListIterator.d ./src/ICollections/collections/ListIterator.o ./src/ICollections/collections/ListNode.d ./src/ICollections/collections/ListNode.o ./src/ICollections/collections/OrderedDictionary.d ./src/ICollections/collections/OrderedDictionary.o ./src/ICollections/collections/OrderedDictionaryEntry.d ./src/ICollections/collections/OrderedDictionaryEntry.o

.PHONY: clean-src-2f-ICollections-2f-collections

