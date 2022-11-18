#ifndef LOCALSTORE_H
#define LOCALSTORE_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QDebug>
class localStore
{
public:
    localStore();
    void mkdir(QString path);
private:
    QDir *dir;
    QFile *file;
};

#endif // LOCALSTORE_H
