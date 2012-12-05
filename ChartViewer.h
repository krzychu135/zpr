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


class ChartViewer: public Viewer {
	void create_window();
	void draw_chart();
	//MainWindow chart;
public:
	ChartViewer();
	virtual ~ChartViewer();
	virtual void Show();
};

#endif /* CHARTVIEWER_H_ */
