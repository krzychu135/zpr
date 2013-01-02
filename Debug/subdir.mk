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
	g++ -std=c++0x -pthread -DQT_WEBKIT -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED -D__GXX_EXPERIMENTAL_CXX0X__ -I/usr/share/qt4/mkspecs/linux-g++ -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I/home/krzysiek/Pobrane/gsl-1.15 -I/usr/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


