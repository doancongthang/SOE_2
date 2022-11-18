#include "mainwindow.h"
//#include "DI.h"
#include <QApplication>
#include <QDebug>
#include <QThread>
#include <xuly_multithread.h>
#include <task2_read.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
//    QThread cThread;
//    Xuly_MultiThread cXuly;
//    cXuly.Caidat(cThread);
//    cXuly.moveToThread(&cThread);
//    cXuly.start();
}
