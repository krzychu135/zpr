#ifndef MAINWINDOW_H

#define MAINWINDOW_H

#include "stdafx.h"
#include <QMainWindow>
#include <QModelIndex>
#include <QGraphicsScene>
#include "Sequence.h"
#include <QListWidgetItem>


typedef std::vector<Sequence *> Sequences;

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

    void addSequence(Sequence *s);
    
private slots:
    void on_listWidget_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Sequences seq;
};

#endif // MAINWINDOW_H
