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

class Viewer {
private:
    Spectrum * spectrum_;
public:
	virtual ~Viewer();
	Viewer();
    Viewer(Spectrum* s){ spectrum_ = s; }

    virtual void Show(Spectrum *)=0;
};

#endif /* VIEWER_H_ */
