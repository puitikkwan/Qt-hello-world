#include "helloworld.h"
#include "ui_helloworld.h"
#include <QtGui>
#include <QtCore>
#include <QApplication>
#include <QLineEdit>

HelloWorld::HelloWorld(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelloWorld)
{
    QWidget *window = new QWidget;
    window->setWindowTitle("123");
    QLabel *label = new QLabel("Hello World");
    //label->show();
    QGridLayout *q = new QGridLayout;
    QLabel *l1 = new QLabel("Name: ");
    QLineEdit *L1 = new QLineEdit;
    QLabel *l2 = new QLabel("Name: ");
    QLineEdit *L2 = new QLineEdit;
    QLabel *l3 = new QLabel("Name: ");
    QLineEdit *L3 = new QLineEdit;

    q->addWidget(l1, 0, 0);
    q->addWidget(L1, 0, 1);
    q->addWidget(l2, 1, 0);
    q->addWidget(L2, 1, 1);
    q->addWidget(l3, 2, 0);
    q->addWidget(L3, 2, 1);
    q->addWidget(label, 3,0,1,2);
    ui->setupUi(this);
    window->setLayout(q);
    window->show();

}

HelloWorld::~HelloWorld()
{
    delete ui;
}
