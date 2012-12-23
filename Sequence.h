

#include "Spectrum.h"

class Spectrum;

typedef double TSample;
typedef std::vector<TSample> TSamples;

class Sequence
{
	///Empty or already calculated fft related to this sequence
	TSamples samples;
	Spectrum * spectrum; 
public:
	Sequence();
	Spectrum * getSpectrum() const;
	void setSpectrum (const Spectrum * s);
	TSamples numericalSamples() const;
	void setSamples (TSamples & s);
};