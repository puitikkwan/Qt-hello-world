 #include "mythread.h"
#include <QtCore>
#include <QtDebug>

MyThread::MyThread(QObject *parent) : QThread(parent)
{
        this->stop = false;
        this->i = 0;
}

void MyThread::run()
{
    qDebug()<< this->currentThread()<< "Running";

    for(int j = this->i ; j<10000; j++)
    {
        QMutex mutex;
        mutex.lock();
          if(this->stop)
          {
              this->i = j;
              qDebug()<< "123"<<this->currentThread()<< i;
              break;

          }
        mutex.unlock();
        qDebug()<< this->currentThread()<< i;

        emit NumberChanged(j);
        this->msleep(100);

    }



}
