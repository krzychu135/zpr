/*
 * ChartViewer.h
 *
 *  Created on: 25-11-2012
 *      Author: krzysiek
 */
#include "includes.h"

#ifndef CHARTVIEWER_H_
#define CHARTVIEWER_H_

#include "Viewer.h"
#include "qcustomplot.h"
class BMPFileViewer;

class ChartViewer: public Viewer {
protected:
    ///handler to  chart;
    QCustomPlot * customPlot;
    QWidget * parent;
    int width_max,height_max,height_min;
public:
    ChartViewer();
    /**
     * @brief ChartViewer
     * @param spectrum for which chart will be made
     * @param partent parent widget for this widget
     */
    ChartViewer(const boost::shared_ptr<Spectrum> spectrum,QWidget * partent = NULL);

    virtual QCustomPlot * getCustomPlot()const { return customPlot; }
    virtual void addSpectrum(const boost::shared_ptr<Spectrum> s);
	virtual ~ChartViewer();
    virtual void show()const;
    virtual void show(const boost::shared_ptr<Spectrum> s);

    friend class BMPFileViewer;
};

#endif /* CHARTVIEWER_H_ */
