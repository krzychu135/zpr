// ZPR.cpp : main project file.

#include "stdafx.h"

#include "Graph.h"
#include "Analyzer.h"
#include "ParserFactory.h"
#include <sstream>
#include <fstream>

#include <Qt/qapplication.h>
#include "MainWindow.h"
#include <boost/thread/thread.hpp>
#include <boost/ref.hpp>
class Wind
{
public:
	void operator()(){
		while(1){
			//boost::this_thread::sleep_for(boost::chrono::seconds(1));
			std::cout<<"Wypisz to"<<std::endl;
		}
	}
};

//using namespace System;

int main (int argc, char** argv)
{
try
{

	Wind w;
	boost::thread t(boost::ref(w));
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
if(t.joinable()){
	std::cout<<"T.joinable"<<std::endl;
	t.join();
}

}

}
catch (std::exception &e)
{}
    return 0;
}
