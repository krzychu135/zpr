/*
 * ChartViewer.cpp
 *
 *  Created on: 25-11-2012
 *      Author: krzysiek
 */
#include "stdafx.h"

#include "ChartViewer.h"

ChartViewer::ChartViewer() {
	// TODO Auto-generated constructor stub

}

ChartViewer::~ChartViewer() {
	// TODO Auto-generated destructor stub
}

void ChartViewer::Show()
{
    /*std::vector<double> * samples = s.getSpectrum()->getSamples();

    QVector<double> x(samples->size()), y(samples->size()); // initialize with entries 0..100
    for (int i=0; i<samples->size(); ++i)
    {
      x[i] = i; // x goes from -1 to 1
      y[i] = samples->at(i);  // let's plot a quadratic function
    }
    int min,max;
    min = max = samples->at(0);
    BOOST_FOREACH(auto x, *samples){
        if(x>max)
            max = x;
        if(x<min)
            min = x;
    }
    // create graph and assign data to it:
    ui->customPlot->clearGraphs();
    ui->customPlot->addGraph();

    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, samples->size());
    ui->customPlot->yAxis->setRange(min,max);
    ui->customPlot->replot();*/

}
