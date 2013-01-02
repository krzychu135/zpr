#include "stdafx.h"

#include "Spectrum.h"
#include <boost/foreach.hpp>

Spectrum::Spectrum()
{
}
std::vector<double> * Spectrum::getSamples()
{
    return &samples;
}
void Spectrum::setSamples(const std::vector<double> samp)
{
    samples.clear();
    BOOST_FOREACH (double s, samp){
        samples.push_back(s);
    }
}
