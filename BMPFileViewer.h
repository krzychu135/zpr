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
    BMPFileViewer(boost::shared_ptr<Spectrum> s, QWidget * par=0);
    BMPFileViewer(const ChartViewer & chart);
	virtual ~BMPFileViewer();
    void show()const;
    void show(const boost::shared_ptr<Spectrum> s);
    void save(const std::string name)const;
    void addSpectrum(const boost::shared_ptr<Spectrum> s);
};

#endif /* BMPFILEVIEWER_H_ */
