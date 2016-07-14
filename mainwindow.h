#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QLabel>
#include <QProgressBar>
#include "mydialog.h"
#include "helloworld.h"
#include "dialog.h"
#include "helloqlist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionP1_triggered();

    void on_actionP2_triggered();

    void on_actionP3_triggered();

    void on_actionQqlist_triggered();
    void testtest();

    void on_actionSfsf_triggered();

    void on_actionAc_triggered();

private:
    Ui::MainWindow *ui;
    MyDialog *mdialog;
    HelloWorld *mhelloworld;
    Dialog *mmydialog;
    helloqlist *mhelloqlist;
    QLabel *Statlabel;
    QProgressBar *StatProgress;

};

#endif // MAINWINDOW_H
