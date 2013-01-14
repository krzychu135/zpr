
#ifndef SEQUENCE_H_
#define SEQUENCE_H_

#include "Spectrum.h"

class Spectrum;

typedef double TSample;
typedef std::vector<TSample> TSamples;

class Sequence
///data Sequence with optional Spectrum of that sequence
{
	TSamples samples;
	Spectrum * spectrum;
public:
	Sequence();
	///getter for spectrum
	Spectrum * getSpectrum() const;
	///setter for spectrum
	void setSpectrum (const Spectrum * s);
	///getter for samples
	TSamples numericalSamples() const;
	///setter for samples
	void setSamples (TSamples & s);
};

#endif //SEQUECNE_H_
