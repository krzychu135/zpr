#ifndef MAINWINDOW_H

#define MAINWINDOW_H

#include "includes.h"
#include <QMainWindow>
#include "Sequence.h"
#include "ChartViewer.h"
#include <QListWidgetItem>


typedef boost::shared_ptr<Spectrum> shs;
typedef std::vector<shs > Sequences;


class QListWidgetItemBetter: public QListWidgetItem
{
    QListWidgetItemBetter():QListWidgetItem(){}
    ~QListWidgetItemBetter(){}


};

namespace Ui {
class MainWindow;
}
/**
 * @brief The MainWindow class
 * Creates program main window
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

    boost::shared_ptr<Spectrum> extractSelectedSpectrum();
    
public:
    /**
     * @brief MainWindow
     * @param parent parent widget
     * creates main window
     */
	explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    /**
     * @brief addSequence
     * @param s Sequence to add
     * add new sequence to list widget in main window
     */
    void addSequence(const Sequence &s);
    /**
     * @brief addSequences
     * Add all sequences from ParserFactory.
     */
    void addSequences();
    
private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();
    /**
     * @brief paint chart
     *
     *  Visualize selected spectrum on chart.
     *  if checkBox is checked painting on one chart
     */
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Sequences seq;
    ChartViewer * multiChart;
};

#endif // MAINWINDOW_H
