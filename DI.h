#ifndef DI_H
#define DI_H
#define NUM_DI 8
#include <QObject>
#include <qstring.h>
#include <QDebug>
#include "modbustcp.h"
#include <QTime>
#include <QDateTime>
#include <QQueue>
#include "localstore.h"
#include "timetypes.h"
#include <QDateTimeEdit>

class DI: public QObject
{
public:

    DI();
    void setValue(int offset,uint16_t value);
    void dataParse(int offset, uint16_t value);
    uint16_t getValue(int offset);
    void setValue(int offset, QString data);
private:
    uint16_t _value[NUM_DI];
    uint16_t _m_value[NUM_DI];
    modbusTCP *mbTCP;
    localStore *file;
    timeTypes *timeString;
    QDateTime *datetime;

    struct HregDi
    {
        bool value;
        int ID;
        QDateTime time;

        HregDi() {}
    };
    HregDi hregDi[NUM_DI*16];
    QQueue <HregDi> fifo;
    void FiFoPush(HregDi &data);
    void modbusInputStatusTask();
    int getFiFoCount();
    void modbusHregTask();
signals:
    void valueChanged(int &offset, uint16_t &value);
public slots:
    void updateChanged(QDate time);

};

#endif // DI_H
