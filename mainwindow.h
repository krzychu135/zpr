#ifndef MAINWINDOW_H

#define MAINWINDOW_H

#include "includes.h"
#include <QMainWindow>
#include <QModelIndex>
#include <QGraphicsScene>
#include "Sequence.h"
#include <QListWidgetItem>


typedef std::vector<Spectrum *> Sequences;

class QListWidgetItemBetter: public QListWidgetItem
{
    QListWidgetItemBetter():QListWidgetItem(){}
    ~QListWidgetItemBetter(){}


};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
	explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addSequence(Sequence &s);
    void addSequences();
    
private slots:
    void on_listWidget_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();
    bool close() { exit(0); }

private:
    Ui::MainWindow *ui;
    Sequences seq;
};

#endif // MAINWINDOW_H
