// ZPR.cpp : main project file.

#include "includes.h"
#include "Program.h"
#include "Exceptions.h"

int main (int argc, char** argv)
{
	try
	{
		Program prog(argc,argv);
		return prog.start();
	}
	catch (namedException &e)
	{
		std::cout << e.message << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout<<"Błąd krytyczny!! Program musi zostać zakończony"<<std::endl;
	}
 return 0;
}
