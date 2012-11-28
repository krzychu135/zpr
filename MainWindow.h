/*
 * MainWindow.h
 *
 *  Created on: 25-11-2012
 *      Author: krzysiek
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

// headers for painting the main window from QT
#include <Qt/qapplication.h>
#include <Qt/qmainwindow.h>
#include <Qt/qpushbutton.h>
#include <Qt/qlabel.h>
#include <Qt/qtextcodec.h>

class MainWindow {
	void create_main_window(int argc, char *argv[]);
public:
	MainWindow(int argc, char *argv[]);
	virtual ~MainWindow();
};

#endif /* MAINWINDOW_H_ */
