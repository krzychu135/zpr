#include "stdafx.h"

class Spectrum;
class Sequence;

class Analyzer : public boost::noncopyable
///Spectrum analyzer, performs FFT on given Sequences
{
///Implemented as Singleton
public:
	static Analyzer & get();

	//FFT
	Spectrum analyze (const Sequence & s) const;
	void createSpectrum (Sequence & s) const;
private:

	Analyzer(){};
	~Analyzer(){};
};