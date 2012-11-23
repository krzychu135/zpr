// ZPR.cpp : main project file.

#include "stdafx.h"

#include "Graph.h"
#include "Analyzer.h"
#include "ParserFactory.h"
#include <sstream>
#include <fstream>

using namespace System;

int main (int argc, char** argv)
{
	try
	{
		ParserFactory::get().initParsers();

		for (int i = 1; i < argc; ++i)
		{
			std::fstream s;
			s.open (argv[i]);

			std::string text;
			char buffer[4096];
			while (s.read (buffer, sizeof(buffer)))
				text.append (buffer, sizeof(buffer));
			text.append(buffer, s.gcount());

			if (ParserFactory::get().tryToParse (text))
				std::cout << "File " << argv[i] << " parsed\n";
			else
				std::cout << "File " << argv[i] << " not parsed\n";

			s.close();
		}

	}
	catch (std::exception &e)
	{}
    return 0;
}
