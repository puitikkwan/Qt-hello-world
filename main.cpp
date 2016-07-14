#include "mainwindow.h"
#include <QApplication>

#include "mydialog.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();


    //強制回應 modal
      MyDialog mdialog;
      mdialog.setModal(true);
      mdialog.exec();

    return a.exec();
}
