// ZPR.cpp : main project file.

//include boost::foreach
//include gsl fft
//include qt?
#include "stdafx.h"

#include "Graph.h"
#include "Analyzer.h"
#include "ParserFactory.h"

//GSL
#include <gsl_math.h>
#include <gsl\gsl_fft.h>
//QT
#include <Qt\qwidget.h>

using namespace System;

int main (array<System::String ^> ^args)
{
	try
	{
		ParserFactory::get().initParsers();
		int bar;
		ParserFactory::get().tryToParse(bar);
	}
	catch (std::exception &e)
	{}
    return 0;
}
