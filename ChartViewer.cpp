/*
 * ChartViewer.cpp
 *
 *  Created on: 25-11-2012
 *      Author: krzysiek
 */
#include "includes.h"
#include "Exceptions.h"
#include "ChartViewer.h"

ChartViewer::ChartViewer() {
    this->customPlot=NULL;
    this->height_max = this->height_min = this->width_max = 0;

}
ChartViewer::ChartViewer(const boost::shared_ptr<Spectrum> spect,QWidget * par):parent(par)
{
    ChartViewer();
    //this->customPlot=NULL;
    this->spectrum = spect;
}

ChartViewer::~ChartViewer() {
    if(customPlot==NULL)
        delete customPlot;
}


void ChartViewer::show(const boost::shared_ptr<Spectrum> s)
{
    addSpectrum(s);
    show();
}

void ChartViewer::addSpectrum(const boost::shared_ptr<Spectrum> s){
    if(s.get()==NULL) throw nullPointerException("Niezainicjalizowane spectrum");
    if(this->customPlot==NULL){
        customPlot = new QCustomPlot(NULL);
        customPlot->xAxis->setRange(0,0);
        customPlot->yAxis->setRange(0,0);
    }

    int n = s->getSamples()->size();
    QVector<double> x(n), y(n);
    for (int i=0; i<n; ++i)
    {
      x[i] = i;
      y[i] = s->getSamples()->at(i);
    }
    int min,max;
    min = max = s->getSamples()->at(0);
    BOOST_FOREACH(auto x, *s->getSamples()){
        if(x>max)
            max = x;
        if(x<min)
            min = x;
    }

    customPlot->addGraph();
    customPlot->graph(customPlot->graphCount()-1)->setData(x, y);
    customPlot->setObjectName(QString::fromUtf8("customPlot"));
    customPlot->setEnabled(true);
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy1.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
    customPlot->setSizePolicy(sizePolicy1);
    customPlot->setMinimumSize(QSize(300, 300));


    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    if(width_max<s->getSamples()->size())
        width_max = s->getSamples()->size();
    customPlot->xAxis->setRange(0, width_max);
    if(height_min>min)
       height_min = min;
    if(height_max<max)
        height_max = max;
    customPlot->yAxis->setRange(height_min,height_max);
}

void ChartViewer::show()const
{
    customPlot->replot();
    customPlot->show();
}

