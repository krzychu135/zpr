/*
 * ChartViewer.cpp
 *
 *  Created on: 25-11-2012
 *      Author: krzysiek
 */
#include "includes.h"

#include "ChartViewer.h"

ChartViewer::ChartViewer() {
	// TODO Auto-generated constructor stub

}

ChartViewer::~ChartViewer() {
	// TODO Auto-generated destructor stub
}

void ChartViewer::Show(Spectrum * s)
{
    std::vector<double> * samples = s->getSamples();

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

    customPlot = new QCustomPlot(NULL);
    customPlot->setObjectName(QString::fromUtf8("customPlot"));
    customPlot->setEnabled(true);
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
    customPlot->setSizePolicy(sizePolicy1);
    customPlot->setMinimumSize(QSize(201, 200));
    customPlot->setSizeIncrement(QSize(0, 0));

    customPlot->clearGraphs();
    customPlot->addGraph();

    customPlot->graph(0)->setData(x, y);

        // give the axes some labels:
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
        // set axes ranges, so we see all data:
    customPlot->xAxis->setRange(0, samples->size());
    customPlot->yAxis->setRange(min-(max-min)/10,max+(max-min)/10);
    customPlot->replot();
    customPlot->show();

}
