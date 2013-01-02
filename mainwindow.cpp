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
    QListWidgetItem * qitem = new QListWidgetItem(item.c_str());
    qitem->setData(Qt::UserRole,this->seq.size());
    this->seq.push_back(s);
    ui->listWidget->addItem(qitem);
}

void MainWindow::on_pushButton_2_clicked()
{
    auto d = ui->listWidget->selectedItems().first()->data(Qt::UserRole).toInt();
        Sequence * s = seq.at(d);


    std::vector<double> * samples = s->getSpectrum()->getSamples();

    QVector<double> x(samples->size()), y(samples->size()); // initialize with entries 0..100
    for (int i=0; i<samples->size(); ++i)
    {
      x[i] = i; // x goes from -1 to 1
      y[i] = samples->at(i);  // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, 20);
    ui->customPlot->yAxis->setRange(-20,30);
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
