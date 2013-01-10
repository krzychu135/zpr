
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
	///Sequence of numbers to analyze
	Spectrum * spectrum;
	///Empty or already calculated fft related to this sequence
public:
	Sequence();
	Spectrum * getSpectrum() const;
	void setSpectrum (const Spectrum * s);
	TSamples numericalSamples() const;
	void setSamples (TSamples & s);
};

#endif //SEQUECNE_H_
