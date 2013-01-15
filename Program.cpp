#include "includes.h"

/*
 * Program.cpp
 *
 *  Created on: 31-12-2012
 *      Author: Krzysztof Grzyb, Tomasz Zieli�ski
 */

#include "Program.h"
#include "Exceptions.h"
/**
 * @brief main program method everything goes there
 * @param argc  number of files to perform
 * @param argv  files to perform
 */
Program::Program(int argc, char *argv[]) {

    //processing data
    ParserFactory::get().initParsers();
    for (int i = 1; i < argc; ++i)
    {
		try
		{
			transform_file(argv[i]);
		}
		catch (parserException & e)
		{
			std::cout << e.message << std::endl;
		}
    }
    //transform_file("../data/ATFullExOrIn.dat");
    //transform_file("../data/spliceATrainKIS.dat");
    transform_sequence();
    std::cout<<"Sequences transformed"<<std::endl;
    //inicial gui application
	prog_ = new QApplication(argc, argv);


    //creating main mindow
    window_ = new MainWindow();

    window_->setGeometry(100, 100, 500, 400);
    window_->setWindowTitle("Spectrum 1.0");
    window_->show();


    /*std::vector<double> samp;
    for(int i=0;i<128;i++)
    {
        samp += sin((double)i);
    }
    sine superposition test
    for(int i=0;i<128;i++)
    {
        samp += sin((double)i) + cos((double)2*i);
    }

	//saw wave test
    for (int waveform = 0; waveform < 5; ++waveform)
	{
		for (int i = -100; i < 101; ++i)
		{
			samp += (double) i * 0.01;
		}
    }
    Sequence s;
    s.setSamples(samp);
    Analyzer::get().createSpectrum(s);
    window_->addSequence(s);*/

    window_->addSequences();
}
/**
 * @brief releases resources
 */
Program::~Program() {
    if(prog_!=NULL)
        delete prog_;
    if(window_!=NULL)
        delete window_;
}
/**
 * @brief starts qt gui loop
 * @return result of gui processing
 */
int Program::start(){

    return prog_->exec();

}
/**
 * @brief parse file and getting sequences from added file for futher notice
 * @param file  file name to parse
 */
void Program::transform_file(char * file)
{
	std::string fileName (file);
	std::fstream s;
	std::string text;
	try
	{
		s.open (file);

		char buffer[4096];
		while (s.read (buffer, sizeof(buffer)))
			text.append (buffer, sizeof(buffer));
		text.append(buffer, s.gcount());

		s.close();
	}
	catch (std::exception & e)
	{
		throw fileException ("Nie uda�o si� otworzy� pliku " + fileName);
	}

	if (ParserFactory::get().tryToParse (text))
	{
		std::cout << "File " << file << " parsed\n";
	}
	else
	{
		std::cout << "File " << file << " not parsed\n";
        throw parserException ("Parsowanie pliku " + fileName + "  nie powiod�o si�");
	}

}
/**
 * @brief makes fft for sequences parsed before
 */
void Program::transform_sequence()
{



    //BOOST_FOREACH (auto vec, ParserFactory::get().allSequences)
    BOOST_FOREACH (boost::shared_ptr<std::vector <Sequence>> vec, ParserFactory::get().allSequences)
    {
        BOOST_FOREACH (Sequence & seq, *vec) //reference
        {
            Analyzer::get().createSpectrum (seq);
        }
    }
    std::cout << "Spectrum analysis complete\n";

}
