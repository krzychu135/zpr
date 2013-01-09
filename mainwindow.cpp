#include "stdafx.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <boost/lexical_cast.hpp>
#include "ParserFactory.h"

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

void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{

}
void MainWindow::addSequence(Sequence &s){
    try{
        std::cout<<s.getSpectrum()->getSamples()->size()<<std::endl;
    std::string item = boost::lexical_cast<std::string>(this->seq.size());
    if(this->seq.size()>10)return;
    QListWidgetItem * qitem = new QListWidgetItem(item.c_str());
    qitem->setData(Qt::UserRole,this->seq.size());
    this->seq.push_back(s);
    ui->listWidget->addItem(qitem);
    }catch(std::exception e){
        //do nothing
    }
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

    try{
        if(ui->listWidget->selectedItems().isEmpty()) return; //do nothing when nothing is checked
        auto d = ui->listWidget->selectedItems().first()->data(Qt::UserRole).toInt();
        Sequence s = seq.at(d);





    //Sequence *selected = this->sequences[row];
    //rysuj wykres
    //ui->graphicsView->setScene(drawChart(NULL));
    //std::cout<<"szerokość: "<<ui->graphicsView->width()<<" wysokość"<<ui->graphicsView->height()<<std::endl;
    //ui->graphicsView->show();
    }catch(std::out_of_range out){

    }
}

void MainWindow::on_pushButton_clicked()
{
    exit(0);
}

void MainWindow::on_pushButton_3_clicked()
{

}

void MainWindow::on_pushButton_5_clicked()
{

}
