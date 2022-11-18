#include "xuly_multithread.h"
#include "qdebug.h"
#include "DI.h"

Xuly_MultiThread::Xuly_MultiThread(QObject *parent)
    : QThread{parent}
{
}
//******************************************************************************************//
void Xuly_MultiThread::run()
{
    for (int i = 0;i <100;i++)
    {
        qDebug()<<i<<"helloword";
        qDebug()<<"Time Now:"<<QDateTime::currentDateTime();
    }
    qDebug()<<"Finish!!!";
}
void Xuly_MultiThread::stop()
{

}

//void Xuly_MultiThread::Caidat(QThread &cThread)
//{
//    connect(&cThread,SIGNAL(started()),this,SLOT(job1()));
//}

//void Xuly_MultiThread::job1()
//{
//        for (int i = 0;i <1000;i++)
//        {
//            qDebug()<<i<<"helloword";
//            //qDebug()<<"Time Now:"<<QDateTime::currentDateTime();
//        }
//        qDebug()<<"Finish!!!";
//}
