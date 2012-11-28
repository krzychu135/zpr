// ZPR.cpp : main project file.

//include boost::foreach
//include gsl fft
//include qt?
#include "stdafx.h"

#include "Graph.h"
#include "Analyzer.h"

//GSL
#include <gsl/gsl_math.h>
#include <gsl/gsl_fft.h>
//QT
#include <Qt/qwidget.h>
#include <Qt/qapplication.h>

#include <boost/foreach.hpp>
//#include <boost/thread.hpp>
//using namespace System;
constexpr int g(){
	return 5;
}
void gh(){
	while(true){
		std::cout<< "Hello" << std::endl;
	}
}
class typ
{
public:
	std::string ala;
	int a;
};
/*int main ()
{
	std::vector<int> vec;
	BOOST_FOREACH (auto element, vec)
	{
		element = 666;
	}
	QApplication g();
	QWidget widget;
	//boost::thread t(&g);
	//t.join();
	//boost::thread th(&gh);
		//th.join();
    //Console::WriteLine (L"Hello World");
	std::cout<< "Hello World"<<std::endl;
    return 0;
}*/
#include "MainWindow.h"
#include <boost/thread.hpp>
#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>


int main(int argc, char *argv[])
{

	boost::thread watek();
	watek.join();

	int mojatablica[] = {1,3,4,5,6};
	auto y = mojatablica;
	for(int &x :mojatablica){
		x = 0;
		auto alai = u8"To jest uó ląala w UTF8";
		std::cout<<alai<<" "<<*(y++)<<std::endl;
	}
	typ i{"tentyp",2};
	std::vector<int> vec;
//	BOOST_FOREACH (auto element, vec)
//	{
//		//element = 1;
//	}
	MainWindow prog(argc,argv);

    return 0;
}
