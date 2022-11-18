#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QThread>
#include "DI.h"
#include <QDebug>
#include <QDateTime>
#include "QDateTime"
#include "QDateTimeEdit"
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include "gpio.h"
#include "xuly_multithread.h"
#include <task2_read.h>

#define CHANNEL 0
#define SPEED 5000000
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void  spi_init();
    uint16_t readSPI(GPIO *cs,unsigned char num);

private slots:
    void on_date_changed(QDateTime time );
public slots:
    void spi_update();
private:
    Ui::MainWindow *ui;
    DI *di;
    QDateTime *time;
    QDateTimeEdit *timeEdit;
    quint16 inputReg[8];


    Xuly_MultiThread *xulythread;
    Task2_Read *task2read;
signals:
    void valueIsChanged();
    void hee();
};
#endif // MAINWINDOW_H
