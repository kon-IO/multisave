################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CustomListWidgetItem.cpp \
../src/MainWidget.cpp \
../src/NewEntryPopup.cpp \
../src/TestCpp.cpp 

CPP_DEPS += \
./src/CustomListWidgetItem.d \
./src/MainWidget.d \
./src/NewEntryPopup.d \
./src/TestCpp.d 

OBJS += \
./src/CustomListWidgetItem.o \
./src/MainWidget.o \
./src/NewEntryPopup.o \
./src/TestCpp.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/x86_64-linux-gnu/qt5 -O0 -g3 -Wall -Wextra -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/CustomListWidgetItem.d ./src/CustomListWidgetItem.o ./src/MainWidget.d ./src/MainWidget.o ./src/NewEntryPopup.d ./src/NewEntryPopup.o ./src/TestCpp.d ./src/TestCpp.o

.PHONY: clean-src

