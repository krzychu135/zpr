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
	auto copy = s.numericalSamples(); // use as array
	size_t size = copy.size();

	//gsl_fft_real_radix2_transform (&copy[0], 1, size); //transform
	//gsl_fft_halfcomplex_radix2_inverse (&copy[0], 1, size); //reorder
	double (*data)[] = (double(*)[]) malloc (sizeof(double) * size);
     
	gsl_fft_real_wavetable * real = gsl_fft_real_wavetable_alloc (size);
	gsl_fft_halfcomplex_wavetable * hc = gsl_fft_halfcomplex_wavetable_alloc (size);
	gsl_fft_real_workspace * work = gsl_fft_real_workspace_alloc (size);
     
	memcpy (data, &copy[0], size * sizeof(double)); //TODO: alloc
	
	gsl_fft_real_transform (*data, 1, size, real, work);   
	gsl_fft_real_wavetable_free (real);
	gsl_fft_halfcomplex_inverse (*data, 1, size, hc, work);
	gsl_fft_halfcomplex_wavetable_free (hc);
	gsl_fft_real_workspace_free (work);

	free(data);

	Spectrum spec;
	spec.samples = copy;

	return spec;
}

void Analyzer::createSpectrum (Sequence & s) const
{
	s.setSpectrum (new Spectrum (analyze(s)));
}
