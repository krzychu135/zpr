#include "stdafx.h"

#include "Sequence.h"

TSamples Sequence::numericalSamples() const
{
	return TSamples();
}

void Sequence::setSamples(TSamples & s)
{
	samples = s; //TODO: copy
}

Spectrum * Sequence::getSpectrum() const
{
	return spectrum;
}
void Sequence::setSpectrum (const Spectrum * s)
{
	spectrum = const_cast<Spectrum *>(s);
}