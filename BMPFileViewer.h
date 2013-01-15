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
/**
  * @brief Provides methods for saving chart in bmp file
  */
class BMPFileViewer: public FileViewer, ChartViewer{
public:
    BMPFileViewer();
    BMPFileViewer(boost::shared_ptr<Spectrum> s, QWidget * par=0);
    /**
      * @brief create BMPFileViewer from ChartViewer. Adds save ability for ChartViewer
    */
    BMPFileViewer(const ChartViewer & chart);
	virtual ~BMPFileViewer();
    void show()const;
    void show(const boost::shared_ptr<Spectrum> s);
    /**
      * @brief Saves chart in bmp file using name as filename. 
      
      * If file exist will be overrided.
    */
    void save(const std::string name)const;
    /**
      * @brief Adds new Spectrum for chart
    */
    void addSpectrum(const boost::shared_ptr<Spectrum> s);
};

#endif /* BMPFILEVIEWER_H_ */
