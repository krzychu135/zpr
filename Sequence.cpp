#include "stdafx.h"

#include "Sequence.h"
#include <sstream>

Sequence::Sequence()
{
	spectrum = NULL;
}

TSamples Sequence::numericalSamples() const
{
	return samples;
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
