// ZPR.cpp : main project file.

#include "stdafx.h"

#include "Graph.h"
#include "Analyzer.h"
#include "ParserFactory.h"

using namespace System;

int main (int argc, char** argv)
{
	try
	{
		ParserFactory::get().initParsers();

		for (int i = 0; i < argc; ++i)
		{
			io::stream_buffer<io::file_source> s (argv[i]);
			ParserFactory::get().tryToParse(s);
		}

	}
	catch (std::exception &e)
	{}
    return 0;
}
