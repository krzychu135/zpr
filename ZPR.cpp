// ZPR.cpp : main project file.

//include boost::foreach
//include gsl fft
//include qt?
#include "stdafx.h"

#include "Graph.h"
#include "Analyzer.h"

//GSL
#include <gsl_math.h>
#include <gsl\gsl_fft.h>
//QT
#include <Qt\qwidget.h>

using namespace System;

int main (array<System::String ^> ^args)
{
	std::vector<int> vec;
	BOOST_FOREACH (auto element, vec)
	{
		element = 666;
	}
	QWidget widget;

    Console::WriteLine (L"Hello World");
    return 0;
}
