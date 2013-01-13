/*
 * BMPFileViewer.cpp
 *
 *  Created on: 25-11-2012
 *      Author: krzysiek
 */
#include "includes.h"

#include "BMPFileViewer.h"
#include <QMessageBox>
BMPFileViewer::BMPFileViewer() {
	// TODO Auto-generated constructor stub

}

BMPFileViewer::~BMPFileViewer() {
	// TODO Auto-generated destructor stub
}

void BMPFileViewer::Show(Spectrum *s)
{
    ChartViewer::Show(s);
    if(this->getCustomPlot()->saveBmp(QString("bmpfile.bmp"))){
        QMessageBox mes(QMessageBox::Information,QString("Plik został zapisany"),QString("Plik został zapisany"));
        mes.exec();
    }
    else{
        QMessageBox mes(QMessageBox::Information,QString("Plik nie został zapisany"),QString("Plik nie został zapisany"));
        mes.exec();
    }

}

bool BMPFileViewer::Save(std::string name)
{

return true;
}
