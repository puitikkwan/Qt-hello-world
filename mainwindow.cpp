#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"
#include "helloqlist.h"
#include "messageboxbox.h"

#include <QtCore>
#include <QFile>
#include <QtGui>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QLabel>
#include <Qlist>
#include <QStringList>

#include <QProgressBar>
#include <QtDesigner/QDesignerFormWindowInterface>

void Write(QString Filename)
{
    qDebug() <<"enter write loop";
    QFile mFile(Filename);

    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "could not open file for write";
        return;
    }
    QTextStream out(&mFile);
    out << "Hello world";
    mFile.flush();
    mFile.close();
    qDebug() <<"leave write loop";
}

void Read(QString Filename)
{
    QFile mFile(Filename);
    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() <<"could not open file for read";
        return;
    }

    QTextStream in(&mFile);
    QString mText = in.readAll();

    qDebug() << mText;
    mFile.close();


}

QString Read2(QString Filename)
{
    QFile mFile(Filename);

    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() <<"could not open file for read";
        return 0;
    }

    QTextStream in(&mFile);
    QString mText = in.readAll();

    qDebug() << mText;
    mFile.close();

    return mText;


}

//before output to plaintextedit, set the text.
QString atest(int a)
{
    QString *mtext = new QString("ADDLOOP");
    if(a<100)
    {
        a++;
        *mtext += "OHNO";
        return *mtext;
    }
    else
        return *mtext;
}




QString addloop2(int a)
{
    QString *mtext = new QString("ADDLOOP: ");
    for(int i = 0; i<a; i++)
    {
        *mtext += "1";
    }
    return *mtext;
}

void MainWindow::testtest()
{

    QString *mtext = new QString("testtest: ");
    for(int i = 0; i<100; i++)
    {
        *mtext += "1";
    }
    ui->plainTextEdit->document()->setPlainText(*mtext);
    return;
}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->pushButton->setText("Hello World");
//    ui->pushButton_2->setText("Hello World 2");
    ui->line->close();

    setCentralWidget(ui->plainTextEdit);

    //write and read file
    QString mFilename = "C:/Users/Admin/Desktop/helloworld2.txt";
    Write(mFilename);
    Read(mFilename);

    QString mFilxename2 = ":/myfile/mydialog.h";
    Read(mFilxename2);
    Read(":/new/prefix1/hello.txt");
//    qDebug()<< "addloop" << atest(1);
//    qDebug()<< "addloop" << addloop2(100);


    //output to plaintextedit
    testtest();
    ui->plainTextEdit->document()->setPlainText(Read2(mFilxename2));
//    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->progressBar,SLOT(setValue(int)));
//    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->line,SLOT(show()));



    /////////////////QLIST/////////////////
    QList<int> mlist;


    for(int i = 0;i<10;i++)
    {
        mlist.append(i);
    }

    QListIterator<int> Iter(mlist);
    Iter.toBack();

    while(Iter.hasPrevious())
    {
        qDebug() << Iter.previous();
    }

//    mlist.removeAt(4);
//    foreach(int listnumber, mlist)
//    {
//        qDebug() << listnumber;
//    }
    /////////////////END of QList /////////////////



    ////////////String list//////////////////
    QStringList slist;
    QString llist = "a,b,c,d,e,f,g";

    slist = llist.split(",");
    slist.replaceInStrings("a", "o");

    foreach(QString haha, slist)
    {
        qDebug()<< haha;
    }


    //status BAR
    Statlabel = new QLabel(this);
    StatProgress = new QProgressBar(this);

    ui->statusBar->addPermanentWidget(Statlabel);
    ui->statusBar->addPermanentWidget(StatProgress);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionP1_triggered()
{
    //ui->pushButton->setText("123");
    //強制回應 modal
//      MyDialog mdialog;
//      mdialog.setModal(true);
//      mdialog.exec();

    // 非強制回應
     //mdialog.show(); //useless, since mdialog is saving in stack and clean in every loop/
     //the method is to add the mdialog.h file into the main.h and create a private pointer
       mdialog = new MyDialog(this);
       mdialog->show();


}

void MainWindow::on_actionP2_triggered()
{
    mhelloworld = new HelloWorld(this);
    mhelloworld->show();
}

void MainWindow::on_actionP3_triggered()
{
    mmydialog = new Dialog(this);
    mmydialog->show();
}

void MainWindow::on_actionQqlist_triggered()
{
    mhelloqlist = new helloqlist(this);
    mhelloqlist->show();
}

void MainWindow::on_actionSfsf_triggered()
{
    ui->statusBar->showMessage("SFSFS",4000);
    StatProgress->setValue(13);
}

void MainWindow::on_actionAc_triggered()
{
    messageboxbox mme;
    mme.setModal(true);
    mme.exec();

}
