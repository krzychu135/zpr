#include "includes.h"

#ifndef SPECTRUM_H_
#define SPECTRUM_H_

class Spectrum
///Spectrum created by FFT of data Sequence
{
	friend class Analyzer;
	friend class Sequence;

	std::vector<double> samples;
public:
	Spectrum();
	///getter
    std::vector<double> * getSamples();
	///setter
    void setSamples(const std::vector<double>);
};

#endif //SPECTRUM_H_
