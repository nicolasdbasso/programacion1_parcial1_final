################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Cliente.c \
../src/Informes.c \
../src/Recoleccion.c \
../src/Utils.c \
../src/main.c \
../src/ss.c 

OBJS += \
./src/Cliente.o \
./src/Informes.o \
./src/Recoleccion.o \
./src/Utils.o \
./src/main.o \
./src/ss.o 

C_DEPS += \
./src/Cliente.d \
./src/Informes.d \
./src/Recoleccion.d \
./src/Utils.d \
./src/main.d \
./src/ss.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


