#include "mainwindow.h"
#include "ui_mainwindow.h"
//******************************************************************************************//

GPIO LED(25, GPIO_OUTPUT);
//GPIO DI_1(10,GPIO_OUTPUT);
GPIO DI_2(24, GPIO_OUTPUT);
GPIO DI_3(23, GPIO_OUTPUT);
GPIO DI_4(22, GPIO_OUTPUT);
GPIO DI_5(21, GPIO_OUTPUT);

GPIO DI_6(3, GPIO_OUTPUT);
GPIO DI_7(2, GPIO_OUTPUT);
GPIO DI_8(0, GPIO_OUTPUT);
static void isrInput1();
static void isrInput2();

static GPIO input1(0, GPIO_INPUT, isrInput1);
static GPIO input2(1, GPIO_INPUT, isrInput2);
//******************************************************************************************//

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //******************************************************************************************//
    xulythread = NULL;
    spi_init();
    di = new DI;
    time = new QDateTime;
    timeEdit = new QDateTimeEdit(QDateTime::currentDateTime());
    //connect(timeEdit, &QTimeEdit::dateTimeChanged, this, &MainWindow::on_date_changed);
    //QTimer *timer = new QTimer;
    //timer->setInterval();
    //connect(timer, SIGNAL(timeout()), this, SLOT(spi_update()));
    //timer->start(1);
    qDebug() << "Day la Ham Main";
    //  while (1)
    //  {
    //    di->dataParse(0, 0);
    //  }


//    xulythread = new Xuly_MultiThread();
//    xulythread ->start();

    task2read = new Task2_Read();
    task2read ->start();
}
//******************************************************************************************//
#pragma region MultiThread

#pragma endregion MultiThread
//******************************************************************************************//
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::spi_init()
{
    if (wiringPiSPISetupMode(0, SPEED, 0) < 0) {
        qDebug() << stderr << "SPI SETUP FAILED! " << strerror(errno);
    } else qDebug() << "SPI init completed";
}
//******************************************************************************************//
uint16_t MainWindow::readSPI(GPIO *cs, unsigned char num)
{
    uint16_t data = 0;
    unsigned char buf[2] = { 0xff, num };
    //qDebug()<<pin <<"-------------";

    cs->pinLow();
    wiringPiSPIDataRW(0, buf, 2);

    //qDebug()<<buf[0]<<" "<<buf[1] ;
    data = buf[0];
    data = data << 8;
    data |= buf[1];
    cs->pinHigh();

    return data;
}
//******************************************************************************************//
void MainWindow::on_date_changed(QDateTime time)
{
    //    qDebug()<<"fffhsdkfhdf";
}
//******************************************************************************************//
void MainWindow::spi_update()
{
    LED.pinToggle();
    //   readSPI(&DI_1,0x01);
    //   readSPI(&DI_2,0x02);
    //

    di->setValue(0, readSPI(&DI_2, 0x02));
    //Doc tan so xung 1 chan IO tren Pi
}
//******************************************************************************************//
static void isrInput1() {
    input1.isrCallback();
    qDebug() << "Ngat_1_Input";
}
static void isrInput2() {
    input2.isrCallback();
}
