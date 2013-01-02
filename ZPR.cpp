// ZPR.cpp : main project file.
#include "Program.h"


int main (int argc, char** argv)
{
	try
	{
		Program prog(argc,argv);
		return prog.start();
	}
	catch (std::exception &e)
	{
		std::cout<<"Błąd krytyczny!! Program musi zostać zakończony"<<std::endl;
	}
 return 0;
}
