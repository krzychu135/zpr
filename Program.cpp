#include "stdafx.h"

/*
 * Program.cpp
 *
 *  Created on: 31-12-2012
 *      Author: krzysiek
 */

#include "Program.h"
#include <math.h>

Program::Program(int argc, char *argv[]) {

    //processing data
    ParserFactory::get().initParsers();
    for (int i = 1; i < argc; ++i)
    {
        transform_file(argv[i]);
    }
    transform_file("../data/ATFullExOrIn.dat");
    //TODO: making transformation in diffrent thread
    transform_sequence();
    std::cout<<"Sequences transformed"<<std::endl;
    //inicial gui application
	prog_ = new QApplication(argc, argv);


    //creating main mindow
    window_ = new MainWindow();

    window_->setGeometry(100, 100, 500, 400);
    window_->setWindowTitle("Spectrum 1.0");
    window_->show();


    //after transformation adding all sequences to gui
    std::vector<double> samp;
    for(int i=0;i<60;i++)
    {
        samp += 0;
    }
    samp.at(3) = 1;
    Sequence s;
    s.setSamples(samp);
    Analyzer::get().createSpectrum(s);
    window_->addSequence(s);
    window_->addSequences();
    //boost::thread process(&transform_sequence);

}

Program::~Program() {
    if(prog_!=NULL)
        delete prog_;
    if(window_!=NULL)
        delete window_;
}

int Program::start(){

    return prog_->exec();
}

void Program::transform_file(char * file)
{
    std::fstream s;
    s.open (file);

    std::string text;
    char buffer[4096];
    while (s.read (buffer, sizeof(buffer)))
        text.append (buffer, sizeof(buffer));
    text.append(buffer, s.gcount());

    if (ParserFactory::get().tryToParse (text))
    {
        std::cout << "File " << file << " parsed\n";
    }
    else
        std::cout << "File " << file << " not parsed\n";

    s.close();

}
void Program::transform_sequence()
{



    //BOOST_FOREACH (auto vec, ParserFactory::get().allSequences)
    BOOST_FOREACH (boost::shared_ptr<std::vector <Sequence>> vec, ParserFactory::get().allSequences)
    {
        BOOST_FOREACH (Sequence & seq, *vec) //reference
        {
            std::cout<<"Sequence processing"<<std::endl;
            Analyzer::get().createSpectrum (seq);
            std::cout<<"zbadane"<<std::endl;
        }
    }
    std::cout << "Spectrum analysis complete\n";

}
