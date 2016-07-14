#include "messageboxbox.h"
#include "ui_messageboxbox.h"
#include <QtGui>
#include <QtCore>
#include <QMessageBox>

messageboxbox::messageboxbox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::messageboxbox)
{
    ui->setupUi(this);

    mThread = new MyThread(this);
    connect(mThread, SIGNAL(NumberChanged(int)),this,SLOT(onNumberChanged(int)));
}

messageboxbox::~messageboxbox()
{
    delete ui;
    delete mThread;
}

void messageboxbox::onNumberChanged(int number)
{
   ui->label->setText(QString::number(number));
}

void messageboxbox::on_pushButton_clicked()
{
    QMessageBox::information(this,"123","123");
}

void messageboxbox::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton reply;


    reply = QMessageBox::question(this,"123","123",QMessageBox::YesAll | QMessageBox::NoToAll);
    if(reply == QMessageBox::YesAll)
        QMessageBox::information(this, "sf", "sdf");
    else
        QMessageBox::information(this, "123","OH no");

}

void messageboxbox::on_pushButton_2_clicked()
{
    QMessageBox::warning(this,"123","nononononononono");

}

void messageboxbox::on_pushButton_4_clicked()
{
    QMessageBox::critical(this,"123","444");

}

void messageboxbox::on_pushButton_5_clicked()
{
    mThread->stop = false;
    mThread->start();
}

void messageboxbox::on_pushButton_6_clicked()
{
    mThread->stop = true;
}
