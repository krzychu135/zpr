#include "stdafx.h"

#include "Analyzer.h"
#include "Spectrum.h"
#include "Sequence.h"

#include <gsl/gsl_math.h>
#include <gsl/gsl_fft.h>
#include <gsl/gsl_fft_real.h>
#include <gsl/gsl_fft_halfcomplex.h.>

Analyzer & Analyzer::get()
{
	static Analyzer anInstance;
	return anInstance;
}

Spectrum Analyzer::analyze (const Sequence & s) const
{
	auto copy = s.numericalSamples(); // use vector as array
	size_t size = copy.size();

	double (*data)[] = (double(*)[]) malloc (sizeof(double) * size);
     
	gsl_fft_real_wavetable * real = gsl_fft_real_wavetable_alloc (size);
	gsl_fft_halfcomplex_wavetable * hc = gsl_fft_halfcomplex_wavetable_alloc (size);
	gsl_fft_real_workspace * work = gsl_fft_real_workspace_alloc (size);
     
	memcpy (data, &copy[0], size * sizeof(double));
	
	gsl_fft_real_transform (*data, 1, size, real, work);   
	gsl_fft_real_wavetable_free (real);
	gsl_fft_halfcomplex_inverse (*data, 1, size, hc, work);
	gsl_fft_halfcomplex_wavetable_free (hc);
	gsl_fft_real_workspace_free (work);

	Spectrum spec;
	spec.samples.resize (size);
	memcpy (&spec.samples[0], data, size * sizeof(double));

	free(data);

	return spec;
}

void Analyzer::createSpectrum (Sequence & s) const
{
	s.setSpectrum (new Spectrum (analyze(s)));
}
