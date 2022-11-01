################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CustomTreeWidget.cpp \
../src/CustomTreeWidgetItem.cpp \
../src/FileEntry.cpp \
../src/MainWidget.cpp \
../src/Multisave.cpp \
../src/NewEntryPopup.cpp 

CPP_DEPS += \
./src/CustomTreeWidget.d \
./src/CustomTreeWidgetItem.d \
./src/FileEntry.d \
./src/MainWidget.d \
./src/Multisave.d \
./src/NewEntryPopup.d 

OBJS += \
./src/CustomTreeWidget.o \
./src/CustomTreeWidgetItem.o \
./src/FileEntry.o \
./src/MainWidget.o \
./src/Multisave.o \
./src/NewEntryPopup.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/x86_64-linux-gnu/qt5 -O0 -g3 -Wall -Wextra -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/CustomTreeWidget.d ./src/CustomTreeWidget.o ./src/CustomTreeWidgetItem.d ./src/CustomTreeWidgetItem.o ./src/FileEntry.d ./src/FileEntry.o ./src/MainWidget.d ./src/MainWidget.o ./src/Multisave.d ./src/Multisave.o ./src/NewEntryPopup.d ./src/NewEntryPopup.o

.PHONY: clean-src

