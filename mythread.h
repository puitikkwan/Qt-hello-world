#ifndef MYTHREAD_H
#define MYTHREAD_H


#include <QtCore>

class MyThread : public QThread
{
    Q_OBJECT

 public:
     explicit MyThread(QObject *parent = 0);
     void run();
     bool stop;
     int i;

 signals:
     void NumberChanged(int);
 public slots:

};


#endif // MYTHREAD_H
