/*
 * BMPFileViewer.h
 *
 *  Created on: 25-11-2012
 *      Author: krzysiek
 */
#include "includes.h"

#ifndef BMPFILEVIEWER_H_
#define BMPFILEVIEWER_H_

#include "FileViewer.h"
#include "ChartViewer.h"

class BMPFileViewer: public FileViewer, ChartViewer{
public:
	BMPFileViewer();
	virtual ~BMPFileViewer();
    void Show(Spectrum *s);
    bool Save(std::string name);
};

#endif /* BMPFILEVIEWER_H_ */
