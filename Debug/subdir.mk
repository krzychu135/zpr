################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../moc_mainwindow.cpp \
../moc_qcustomplot.cpp \
../qcustomplot.cpp \
../Analyzer.cpp \
../AssemblyInfo.cpp \
../BMPFileViewer.cpp \
../ChartViewer.cpp \
../FileViewer.cpp \
../Graph.cpp \
../mainwindow.cpp \
../Parser.cpp \
../ParserFactory.cpp \
../Program.cpp \
../Sequence.cpp \
../Spectrum.cpp \
../TextFileViewer.cpp \
../Viewer.cpp \
../ZPR.cpp \
../stdafx.cpp 



OBJS += \
./moc_mainwindow.o \
./moc_qcustomplot.o \
./qcustomplot.o \
./Analyzer.o \
./AssemblyInfo.o \
./BMPFileViewer.o \
./ChartViewer.o \
./FileViewer.o \
./Graph.o \
./mainwindow.o \
./Parser.o \
./ParserFactory.o \
./Program.o \
./Sequence.o \
./Spectrum.o \
./TextFileViewer.o \
./Viewer.o \
./ZPR.o \
./stdafx.o 



CPP_DEPS += \
./moc_mainwindow.d \
./moc_qcustomplot.d \
./qcustomplot.d \
./Analyzer.d \
./AssemblyInfo.d \
./BMPFileViewer.d \
./ChartViewer.d \
./FileViewer.d \
./Graph.d \
./mainwindow.d \
./Parser.d \
./ParserFactory.d \
./Program.d \
./Sequence.d \
./Spectrum.d \
./TextFileViewer.d \
./Viewer.d \
./ZPR.d \
./stdafx.d 




# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -pthread $(INCPATH) -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


