#include "includes.h"

class Spectrum;
class Sequence;

class Analyzer : public boost::noncopyable
///Spectrum analyzer, performs FFT on given Sequences
{
///Implemented as Singleton
public:
	static Analyzer & get();

	//FFT
	///old function, probably buggy
	Spectrum analyze (const Sequence & s) const;
	///perform FFT analysis of give sequence and return spectrum as result
    Spectrum analyze2(const Sequence &s)const;
	///perform FFT analysis AND set resulting spectrum for given sequence
	void createSpectrum (Sequence & s) const;
private:

	Analyzer(){};
	~Analyzer(){};
};
