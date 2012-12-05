#include "stdafx.h"

#include "Analyzer.h"
#include "Spectrum.h"
#include "Sequence.h"

#include <gsl/gsl_math.h>
#include <gsl/gsl_fft.h>

Analyzer & Analyzer::get()
{
	static Analyzer anInstance;
	return anInstance;
}

Spectrum Analyzer::analyze (const Sequence & s) const
{
	return Spectrum();
}

void Analyzer::createSpectrum (Sequence & s) const
{
	s.setSpectrum (new Spectrum (analyze(s)));
}
