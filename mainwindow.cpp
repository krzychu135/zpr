#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <boost/lexical_cast.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{

}
void MainWindow::addSequence(Sequence *s){

    std::string item = boost::lexical_cast<std::string>(this->seq.size());
   // Sequences[item] = s;
    ui->listWidget->addItem(item.c_str());

}

void MainWindow::on_pushButton_2_clicked()
{
    std::string type = ui->listWidget->selectedItems().first()->text().toStdString();
    //Sequence * s = this->seq[type];
    //s->getSpectrum()->samples;
    ui->customPlot->addGraph();
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i];  // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(-1, 1);
    ui->customPlot->yAxis->setRange(0, 1);
    ui->customPlot->replot();

    //Sequence *selected = this->sequences[row];
    //rysuj wykres
    //ui->graphicsView->setScene(drawChart(NULL));
    //std::cout<<"szerokość: "<<ui->graphicsView->width()<<" wysokość"<<ui->graphicsView->height()<<std::endl;
    //ui->graphicsView->show();
}

void MainWindow::on_pushButton_clicked()
{
    exit(0);
}
