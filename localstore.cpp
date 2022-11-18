#include "localstore.h"
#include "qdebug.h"

localStore::localStore()
{
    file=new QFile;
    dir=new QDir;

}

void localStore::mkdir(QString path)
{
QDir dir (path);
if(dir.exists()){
    qDebug()<<"dir exists";
}
else {
    dir.mkpath(path);
    qDebug()<<"Create file: "<<path;
}
}
