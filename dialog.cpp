#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QStringList>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->label->setText("<h2><b>Hello</b> w</h2>");
    ui->checkBox->setChecked(true);

    ///////////////////////////////////////////////////////////////
    QStringList fonts;
          fonts << "Arial" << "Helvetica" << "Times" << "Courier";
    ui->comboBox->addItems(fonts);
    ui->comboBox->addItem("YOYO");

    for(int i=0;i<9;i++)
    {
        ui->comboBox->addItem(QString::number(i) + "Items");
    }

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    //ui->lineEdit->setText("GG");
    QMessageBox::information(this,ui->lineEdit->text(), "Hello World");
}

void Dialog::on_pushButton_2_clicked()
{
   if(ui->checkBox->isChecked())
   {
       QMessageBox::information(this,"HAHA","tata");
   }
   else
       QMessageBox::information(this,"CRY","no check");


}

void Dialog::on_pushButton_3_clicked()
{
    if(ui->radioButton->isChecked())
    {
        ui->radioButton_2->setChecked(true);
    }

}

void Dialog::on_radioButton_clicked()
{
    QMessageBox::information(this,">.< >.<", "Don't click me, click button");
}

void Dialog::on_pushButton_4_clicked()
{
    QMessageBox::information(this,"combo",ui->comboBox->currentText());
    qDebug()<<ui->comboBox->currentIndex();
}
