/*
 * ChartViewer.h
 *
 *  Created on: 25-11-2012
 *      Author: krzysiek
 */
#include "stdafx.h"

#ifndef CHARTVIEWER_H_
#define CHARTVIEWER_H_

#include "Viewer.h"
#include "qcustomplot.h"

class ChartViewer: public Viewer {
    void create_window(){}
    void draw_chart(){}
	//MainWindow chart;
    QCustomPlot * customPlot;
public:
	ChartViewer();
    QCustomPlot * getCustomPlot()const { return customPlot; }
	virtual ~ChartViewer();
    virtual void Show(Spectrum * s);
};

#endif /* CHARTVIEWER_H_ */
