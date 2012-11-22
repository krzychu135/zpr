// ZPR.cpp : main project file.

#include "stdafx.h"

#include "Graph.h"
#include "Analyzer.h"
#include "ParserFactory.h"
#include <sstream>

using namespace System;

int main (int argc, char** argv)
{
	try
	{
		ParserFactory::get().initParsers();

		for (int i = 0; i < argc; ++i)
		{
			std::stringstream s (argv[i]);

			std::string text;
			char buffer[4096];
			while (s.read (buffer, sizeof(buffer)))
				text.append (buffer, sizeof(buffer));
			text.append(buffer, s.gcount());

			ParserFactory::get().tryToParse(text);
		}

	}
	catch (std::exception &e)
	{}
    return 0;
}
