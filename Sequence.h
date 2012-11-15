

#include "Spectrum.h"

class Spectrum;

typedef std::vector<double> TSamples;

class Sequence
{
	///Empty or already calculated fft related to this sequence
	Spectrum * spectrum; 
public:
	TSamples numericalSamples() const;
};