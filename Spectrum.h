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
};

#endif //SPECTRUM_H_