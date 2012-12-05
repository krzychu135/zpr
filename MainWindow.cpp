/*
 * MainWindow.cpp
 *
 *  Created on: 25-11-2012
 *      Author: krzysiek
 */
#include "stdafx.h"

#include "MainWindow.h"
/**
 * Making main window of the application from where you can manage the application.
 */
MainWindow::MainWindow(int argc, char *argv[]) {
	create_main_window(argc,argv);

}

MainWindow::~MainWindow() {
	// TODO Auto-generated destructor stub
}

void MainWindow::create_main_window(int argc, char *argv[])
{
	 QApplication program(argc, argv);
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

	QMainWindow window;

	window.setGeometry(100, 100, 500, 400);
	window.setWindowTitle("Spectrum 1.0");

	QPushButton button("Close", &window);
	button.setGeometry(200, 350, 100, 40);

	QLabel label("Tekst etykiety :)", &window);
	label.setGeometry(200, 150, 400, 50);

	QObject::connect(&button, SIGNAL(clicked()), &program, SLOT(quit()));

	window.show();

    program.exec();
}
