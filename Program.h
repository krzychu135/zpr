/*
 * Program.h
 *
 *  Created on: 31-12-2012
 *      Author: krzysiek
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_


#include <sstream>
#include <fstream>
#include <QApplication>
#include <boost/thread/thread.hpp>
#include <boost/ref.hpp>

#include "stdafx.h"

#include "Graph.h"
#include "Analyzer.h"
#include "ParserFactory.h"
#include "mainwindow.h"



/**
 * Main class providing basic functionality and launching others functions.
 */
class Program {
	void create_main_window();
    void transform_file(char * file);
	void transform_sequence();
public:
	Program(int argc, char *argv[]);
	virtual ~Program();
	int start();

private:
	QApplication * prog_;
    MainWindow * window_;
};

#endif /* PROGRAM_H_ */
