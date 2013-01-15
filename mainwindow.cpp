#include "includes.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ParserFactory.h"
#include "ChartViewer.h"
#include "BMPFileViewer.h"
#include "Exceptions.h"
#include <QMessageBox>
/**
 * @brief creates program main window
 * @param parent parent widget for this window
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    multiChart ==NULL;
	ui = new Ui::MainWindow();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    exit(0);
}
/**
 * @brief add sequence to list in main window
 * @param s sequence to add
 */
void MainWindow::addSequence(const Sequence &s){
    try{
        std::string seqsize = boost::lexical_cast<std::string>(s.getSpectrum()->getSamples()->size());
        std::string item = boost::lexical_cast<std::string>(this->seq.size());
        std::string label = item + " " + seqsize;

        QListWidgetItem  * qitem = new QListWidgetItem(label.c_str());
        qitem->setData(Qt::UserRole,this->seq.size());  //identifier of sequence
        this->seq.push_back(boost::shared_ptr<Spectrum>(s.getSpectrum()));
        ui->listWidget->addItem(qitem);

    }catch(std::exception e){
        std::cout<<"Internal error when adding sequence in: "<<e.what()<<std::endl;
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
/**
 * @brief saves all created spectrums to bmpfile
 */
void MainWindow::on_pushButton_2_clicked() //save all charts
{
   try{
        for(int i=0;i<ui->listWidget->count();i++){
            int d = ui->listWidget->item(i)->data(Qt::UserRole).toInt();
            boost::shared_ptr<Spectrum> s = this->seq.at(d);
            BMPFileViewer bmp;
            bmp.addSpectrum(s);
            bmp.save("spectrum"+boost::lexical_cast<std::string>(i)+".bmp");
        }
        QMessageBox mes(QMessageBox::Information,QString("information"),QString("All charts saved"));
        mes.exec();
    }catch(fileException & e){
        std::cout<<"File exception: "<<e.message<<std::endl;
    }catch(std::exception & e){
        std::cout<<"Exception: "<<e.what()<<std::endl;
    }
}
/**
 * @brief closing window and finishing program
 */
void MainWindow::on_pushButton_clicked()
{
    this->close();
}
/**
 * @brief saves spectrum chart as bmp image
 */
void MainWindow::on_pushButton_3_clicked()  //saveChart
{
    try{

        if(ui->checkBox->checkState() == Qt::Checked){
            if(this->multiChart != NULL){
                BMPFileViewer ala(*this->multiChart);
                ala.save("spectrum.bmp");
            }
        }else{
            shs s = extractSelectedSpectrum();
            BMPFileViewer nowy;
            nowy.addSpectrum(s);
            nowy.save("spectrum.bmp");
        }
        QMessageBox mes(QMessageBox::Information,QString("information"),QString("Chart saved"));
        mes.exec();
    }catch(guiException & e){
        QMessageBox mes(QMessageBox::Warning,QString("information"),QString(e.message.c_str()));
        mes.exec();
    }catch(fileException & e){
        QMessageBox mes(QMessageBox::Warning,QString("information"),QString(e.message.c_str()));
        mes.exec();
    }catch(std::exception & e){
        std::cout<<"Exception: "<<e.what()<<std::endl;
    }
}
/**
 * @brief
 * @return spectrum associated with selected item in list
 */
shs MainWindow::extractSelectedSpectrum()
{
    if(ui->listWidget->selectedItems().isEmpty())
        throw guiException("You must select item from list first");

    auto d = ui->listWidget->selectedItems().first()->data(Qt::UserRole).toInt();
return seq.at(d);
}
/**
 * @brief Showing selected sequence as chart in separated window
 */
void MainWindow::on_pushButton_4_clicked()  //show chart
{
    try{
        shs s = extractSelectedSpectrum();
        //if many charts at one wanted
        if((ui->checkBox->checkState()) == Qt::Checked){
            if(this->multiChart==NULL){
                this->multiChart = new ChartViewer();
            }
            this->multiChart->addSpectrum(s);
            multiChart->show();
        }
        else{
            ChartViewer nowy = ChartViewer();
            nowy.addSpectrum(s);
            nowy.show();
        }


    }catch(guiException & e){
        QMessageBox mes(QMessageBox::Warning,QString("information"),QString(e.message.c_str()));
        mes.exec();
    }catch(nullPointerException e){
        std::cout<<"Exception "<<e.what()<<": "<<e.message<<std::endl;

    }catch(std::out_of_range out){
        std::cout<<"Exception "<<out.what()<<std::endl;
    }
}
