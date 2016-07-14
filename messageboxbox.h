#ifndef MESSAGEBOXBOX_H
#define MESSAGEBOXBOX_H

#include <QDialog>
#include "mythread.h"

namespace Ui {
class messageboxbox;
}

class messageboxbox : public QDialog
{
    Q_OBJECT

public:
    explicit messageboxbox(QWidget *parent = 0);
    ~messageboxbox();
    MyThread *mThread;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::messageboxbox *ui;

public slots:
    void onNumberChanged(int);
};

#endif // MESSAGEBOXBOX_H
