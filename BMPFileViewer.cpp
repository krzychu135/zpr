/*
 * BMPFileViewer.cpp
 *
 *  Created on: 25-11-2012
 *      Author: krzysiek
 */
#include "includes.h"
#include "Exceptions.h"
#include "BMPFileViewer.h"
#include <QMessageBox>
BMPFileViewer::BMPFileViewer() {

}

BMPFileViewer::~BMPFileViewer() {
}
BMPFileViewer::BMPFileViewer(const ChartViewer & chart)
{
    this->customPlot = chart.customPlot;
    this->parent = chart.parent;
    this->spectrum = chart.spectrum;
}

void BMPFileViewer::show()const
{
    ChartViewer::show();
}

void BMPFileViewer::show(const boost::shared_ptr<Spectrum> s)
{
    addSpectrum(s);
    show();

}

BMPFileViewer::BMPFileViewer(const boost::shared_ptr<Spectrum> s, QWidget * par)
{
    this->parent = par;
    this->spectrum = s;
}
void BMPFileViewer::addSpectrum(const boost::shared_ptr<Spectrum> s)
{
    ChartViewer::addSpectrum(s);
}

void BMPFileViewer::save(const std::string name)const
{
    if(!customPlot->saveBmp(name.c_str())) throw fileException("File cannot be saved as: "+name);
}
