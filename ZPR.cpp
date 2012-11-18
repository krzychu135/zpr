// ZPR.cpp : main project file.

#include "stdafx.h"

#include "Graph.h"
#include "Analyzer.h"
#include "ParserFactory.h"

#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/stream_buffer.hpp>
#include <boost/iostreams/device/file.hpp>

using namespace System;
namespace io = boost::iostreams;

int main (int argc, char** argv)
{
	try
	{
		ParserFactory::get().initParsers();

		for (int i = 0; i < argc; ++i)
		{
			io::stream_buffer<io::file_source> s (argv[i]);
		}

		int bar;
		ParserFactory::get().tryToParse(bar);
	}
	catch (std::exception &e)
	{}
    return 0;
}
