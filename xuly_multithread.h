#ifndef XULY_MULTITHREAD_H
#define XULY_MULTITHREAD_H

#include <QThread>
#include <QDebug>
#include <QObject>
class Xuly_MultiThread : public QThread
{
    Q_OBJECT
public:
    explicit Xuly_MultiThread(QObject *parent = nullptr);
    //void Caidat(QThread &cThread);
protected:
    //void job1();
    void run();
    void stop();

signals:

public slots:
};

#endif // XULY_MULTITHREAD_H
