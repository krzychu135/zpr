#include "stdafx.h"

/*
 * Program.cpp
 *
 *  Created on: 31-12-2012
 *      Author: krzysiek
 */

#include "Program.h"

Program::Program(int argc, char *argv[]) {
    //inicial gui application
	prog_ = new QApplication(argc, argv);

    //creating main mindow
    window_ = new MainWindow();

    window_->setGeometry(100, 100, 500, 400);
    window_->setWindowTitle("Spectrum 1.0");
    window_->show();

    Sequence * n = new Sequence();
    std::vector<double> vec;
	vec += 2.0, 43.0, 34.2, 17.0, 2.0, 1.0, 21.0, 1.0, 1.0, 1.0;

    Spectrum * spe = new Spectrum();
    spe->setSamples(vec);
    n->setSpectrum(spe);
    window_->addSequence(n);
    ParserFactory::get().initParsers();
    for (int i = 1; i < argc; ++i)
    {
        transform_file(argv[i]);
    }
    //TODO: making transformation in diffrent thread
    transform_sequence();
    //boost::thread process(&transform_sequence);

    prog_->exec();



}

Program::~Program() {
    if(prog_!=NULL)
        delete prog_;
    if(window_!=NULL)
        delete window_;
}

int Program::start(){
	std::cout<<"This text is showing now"<<std::endl;
    return 0;
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
        BOOST_FOREACH (auto seq, *vec) //reference
        {
            Analyzer::get().createSpectrum (seq);
            window_->addSequence(&seq);

        }
    }
    std::cout << "Spectrum analysis complete\n";

}
