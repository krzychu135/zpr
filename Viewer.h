/*
 * Viewer.h
 *
 *  Created on: 21-11-2012
 *      Author: Krzysztof Grzyb
 */
#include "stdafx.h"

#ifndef VIEWER_H_
#define VIEWER_H_

#include "Sequence.h"

class Viewer {
private:
    Sequence * sequence_;
public:
	virtual ~Viewer();
	Viewer();
    Viewer(Sequence* s){ sequence_ = s; }

	virtual void Show()=0;
};

#endif /* VIEWER_H_ */
