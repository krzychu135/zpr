#include "stdafx.h"

#ifndef SPECTRUM_H_
#define SPECTRUM_H_

class Spectrum
{
	friend class Analyzer;
	friend class Sequence;

	std::vector<double> samples;
public:
	Spectrum();
    std::vector<double> * getSamples();
    void setSamples(const std::vector<double>);
};

#endif //SPECTRUM_H_
