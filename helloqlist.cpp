#include "helloqlist.h"
#include "ui_helloqlist.h"
#include <QStringList>
#include <Qt>

helloqlist::helloqlist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helloqlist)
{
    ui->setupUi(this);

    ///////////list widget/////////////
    ui->listWidget->addItem("hwhw");
    QStringList fonts;
          fonts << "Arial" << "Helvetica" << "Times" << "Courier";
    ui->listWidget->addItems(fonts);

    ///////////tree widget/////////////
    ui->treeWidget->setColumnCount(2);
    AddRoot("1 Hello", "World");
    AddRoot("2 Hello", "World");
    AddRoot("3 Hello", "World");

}

void helloqlist::AddRoot(QString name, QString Description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0,name);
    itm->setText(1,Description);
    ui->treeWidget->addTopLevelItem(itm);
    AddChild(itm, "1","2");
    AddChild(itm, "1","2");
    AddChild(itm, "1","2");

}

void helloqlist::AddChild(QTreeWidgetItem *parent, QString name, QString Description)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0,name);
    itm->setText(1,Description);
    parent->addChild(itm);

}

helloqlist::~helloqlist()
{
    delete ui;
}

void helloqlist::on_pushButton_clicked()
{
    ui->listWidget->currentItem()->setText("Fuzzy");
    QListWidgetItem *itm = ui->listWidget->currentItem();
    itm->setBackgroundColor(Qt::red);
    itm->setTextColor(Qt::cyan);


}

void helloqlist::on_pushButton_2_clicked()
{

    ui->treeWidget->currentItem()->setBackgroundColor(0,Qt::red);
    ui->treeWidget->currentItem()->setBackgroundColor(1,Qt::blue);
}
