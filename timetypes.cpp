#include "timetypes.h"
#include "qvariant.h"

timeTypes::timeTypes()
{

}

QString timeTypes::getStringCurrentYear()
{
QVariant getYear=QDateTime::currentDateTime().date().year();
return getYear.toString();
}

QString timeTypes::getStringCurrentMonth()
{
    QVariant getMonth=QDateTime::currentDateTime().date().month();
    return getMonth.toString();
}

QString timeTypes::getStringCurrentDay()
{
    QVariant getDay=QDateTime::currentDateTime().date().day();
    return getDay.toString();
}
