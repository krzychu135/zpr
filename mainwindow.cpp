#include "stdafx.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <boost/lexical_cast.hpp>
#include "ParserFactory.h"
#include "ChartViewer.h"
#include "BMPFileViewer.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
	ui = new Ui::MainWindow();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addSequence(Sequence &s){
    try{
    std::string seqsize = boost::lexical_cast<std::string>(s.getSpectrum()->getSamples()->size());
    std::string item = boost::lexical_cast<std::string>(this->seq.size());
    std::string label = item + " " + seqsize;
    //if(this->seq.size()>10)return;
    QListWidgetItem * qitem = new QListWidgetItem(label.c_str());
    qitem->setData(Qt::UserRole,this->seq.size());
    this->seq.push_back(s.getSpectrum());
    ui->listWidget->addItem(qitem);
    }catch(std::exception e){
        //do nothing
    }
}
void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{

}

void MainWindow::addSequences()
{
    BOOST_FOREACH (boost::shared_ptr<std::vector <Sequence>> vec, ParserFactory::get().allSequences)
    {
        BOOST_FOREACH (auto seq, *vec) //reference
        {
            addSequence(seq);

        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    for(int i=0;i<ui->listWidget->count();i++){

    }
}

void MainWindow::on_pushButton_clicked()
{
    exit(0);
}

void MainWindow::on_pushButton_3_clicked()
{
//    std::cout<<"clicked3"<<std::endl;
    if(ui->listWidget->selectedItems().isEmpty()) return; //do nothing when nothing is checked
    auto d = ui->listWidget->selectedItems().first()->data(Qt::UserRole).toInt();
    Spectrum * s = seq.at(d);
    if(s!=NULL){
        BMPFileViewer nowy;
        nowy.Show(s);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    std::cout<<"clicked4"<<std::endl;
}

void MainWindow::on_pushButton_4_clicked()
{
    std::cout<<"clicked"<<std::endl;
    try{
        if(ui->listWidget->selectedItems().isEmpty()) return; //do nothing when nothing is checked
        auto d = ui->listWidget->selectedItems().first()->data(Qt::UserRole).toInt();
        Spectrum * s = seq.at(d);
        if(s!=NULL){
    ChartViewer nowy;
    nowy.Show(s);
//    std::cout<<"Podstawiam"<<std::endl;
    ui->customPlot = nowy.getCustomPlot();
    ui->customPlot->repaint();
    /*ui->horizontalLayout_3->removeWidget(ui->customPlot);
    ui->horizontalLayout_3->addWidget(nowy.getCustomPlot());
    //this->repaint();
    ui->customPlot->hide();*/
//    std::cout<<"Podstawiłem"<<std::endl;



    //Sequence *selected = this->sequences[row];
    //rysuj wykres
    //ui->graphicsView->setScene(drawChart(NULL));
    //std::cout<<"szerokość: "<<ui->graphicsView->width()<<" wysokość"<<ui->graphicsView->height()<<std::endl;
    //ui->graphicsView->show();
        }
    }catch(std::out_of_range out){

    }
}
