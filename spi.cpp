//#include "spi.h"
//#include <QDebug>
//#include <wiringPi.h>
//#include "DI.h"
//GPIO LED (25,GPIO_OUTPUT);
//GPIO DI_1(10,GPIO_OUTPUT);
//GPIO DI_2 (24,GPIO_OUTPUT);
//GPIO DI_3 (23,GPIO_OUTPUT);
//GPIO DI_4 (22,GPIO_OUTPUT);
//GPIO DI_5 (21,GPIO_OUTPUT);


//GPIO DI_6 (3,GPIO_OUTPUT);
//GPIO DI_7 (2,GPIO_OUTPUT);
//GPIO DI_8 (0,GPIO_OUTPUT);
////GPIO MOSI(12,GPIO_OUTPUT);
////GPIO MISO(13,GPIO_INPUT);
////GPIO CLK(14,GPIO_OUTPUT);


//DI dicard;


//SPI::SPI(QObject *parent)
//    : QObject{parent}
//{
//    spi_init();
//QTimer *timer =new QTimer;
//timer->setInterval(1000);
//connect(timer,SIGNAL(timeout()),this,SLOT(spi_update()));
//timer->start();

//}



//void SPI::spi_init()
//{


//DI_1.pinHigh();
//DI_2.pinHigh();
//DI_3.pinHigh();
//DI_4.pinHigh();
//DI_5.pinHigh();
//DI_6.pinHigh();
//DI_7.pinHigh();
//DI_8.pinHigh();



////MOSI.pinLow();
////MISO.pinLow();
////CLK.pinLow();
//    if( wiringPiSPISetup(0, SPEED)<0){
//        qDebug()<<stderr<<"SPI SETUP FAILED! "<<strerror(errno);

//    }
//    else qDebug()<<"SPI init completed";



//}
//uint16_t SPI::readSPI(GPIO *cs,unsigned char num)
//{
//uint16_t data=0;
//      unsigned char buf[2] = { 0xff,num};
// //qDebug()<<pin <<"-------------";

//cs->pinLow();
//wiringPiSPIDataRW(0,buf,2);

//qDebug()<<buf[0]<<" "<<buf[1] ;
//data=buf[0];
//data=data<<8;
//data|=buf[1];
//cs->pinHigh();

//return data;
//}

//void SPI::spi_update()
//{
//    LED.pinToggle();

////    readSPI(&DI_1,0x01);
//    readSPI(&DI_2,0x02);

////    readSPI(&DI_3,0x03);
////    readSPI(&DI_4,0x04);
////    readSPI(&DI_5,0x05);
////    readSPI(&DI_6,0x06);
////    readSPI(&DI_7,0x07);
////    readSPI(&DI_8,0x08);
//    //dicard.setValue(1,readSPI(&DI_1,0x011));
//}


