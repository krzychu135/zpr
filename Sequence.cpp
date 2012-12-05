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