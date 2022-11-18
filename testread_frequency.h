#ifndef TESTREAD_FREQUENCY_H
#define TESTREAD_FREQUENCY_H

#include <QThread>

class TestRead_Frequency : public QThread
{
public:
    explicit TestRead_Frequency(QObject *parent = nullptr);
};

#endif // TESTREAD_FREQUENCY_H
