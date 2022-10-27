################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/MainWidget.cpp \
../src/TestCpp.cpp 

CPP_DEPS += \
./src/MainWidget.d \
./src/TestCpp.d 

OBJS += \
./src/MainWidget.o \
./src/TestCpp.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/x86_64-linux-gnu/qt5 -O3 -Wall -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/MainWidget.d ./src/MainWidget.o ./src/TestCpp.d ./src/TestCpp.o

.PHONY: clean-src

