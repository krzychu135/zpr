/*
 * Viewer.h
 *
 *  Created on: 21-11-2012
 *      Author: Krzysztof Grzyb
 */
#include "includes.h"

#ifndef VIEWER_H_
#define VIEWER_H_

#include "Sequence.h"
/**
 * @brief Basic class for all wanted to show spectrum
 */
class Viewer {
protected:
    boost::shared_ptr<Spectrum> spectrum;
public:
	virtual ~Viewer();
    Viewer();
    Viewer(const boost::shared_ptr<Spectrum> s):spectrum(s) {}
    virtual void addSpectrum(const boost::shared_ptr<Spectrum> s)=0;
    /**
     * @brief Shows contest of kept spectrum
     */
    virtual void show()const =0;
};

#endif /* VIEWER_H_ */
