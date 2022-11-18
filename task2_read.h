#ifndef TASK2_READ_H
#define TASK2_READ_H

#include <QThread>
#include <QObject>
#include <gpio.h>
#include "softPwm.h"

class Task2_Read : public QThread
{
public:
    explicit Task2_Read(QObject *parent = nullptr);
protected:
    void run();
    void stop();
signals:

public slots:
};
#endif // TASK2_READ_H
