#include "task2_read.h"
#include "DI.h"
#include "wiringPi.h"

#include "gpio.h"
GPIO PULSE(0, GPIO_INPUT);

Task2_Read::Task2_Read(QObject *parent)
    : QThread{parent}
{
}
void Task2_Read::run()
{
    while (1)
    {
        //qDebug()<<"Day la task_2"<<QDateTime::currentDateTime()<<digitalRead(25);
        //qDebug()<<"Day la task_2"<<QDateTime::currentDateTime()<<digitalRead(25);
        int j=digitalRead(0);
        switch (j)
        {
        case 1:
            qDebug()<<"Day la task_2"<<QDateTime::currentDateTime();
            break;
        case 0:
            qDebug()<<"Logic_thap"<<QDateTime::currentDateTime();
            break;
        default:
            break;
        }
    }
}
void Task2_Read::stop()
{

}
