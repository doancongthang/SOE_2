#include "DI.h"

DI::DI()
{

//    spi->spi_init();
   // spi->spi_init(7);
    mbTCP =new modbusTCP;
    qDebug()<<"IP address is: " <<mbTCP->getLocalIp();
    mbTCP->setIP(mbTCP->getLocalIp());
    mbTCP->setPort(1025);
    mbTCP->setId(1);
    mbTCP->startConnection();
    mbTCP->addISts(0,256);
    mbTCP->addHreg(0,9000);
    file = new localStore;
 //file->mkdir("SOE_LOG/"+timeString->getStringCurrentYear()+"/"+timeString->getStringCurrentMonth()+"/"+timeString->getStringCurrentDay());
    //    timeString=new timeTypes;
    //    datetime = new QDateTime;
    file->mkdir("SOE-TEST");


}
void DI::setValue(int offset ,uint16_t value)
{
    _value[offset]=value;
    emit  valueChanged(offset,value);
}

uint16_t DI::getValue(int offset)
{
    return _value[offset];
}

void DI::setValue(int offset, QString data)
{

    QByteArray values=QByteArray::fromHex(data.toLatin1());
    quint16 value_16= ((quint8)values[0])<<8|values[1];
    if(value_16!=getValue(offset)){
        _value[offset]=value_16;
      //  count ++;
        emit  valueChanged(offset,value_16);
    }
}

//void DI::dataParse(int offset ,uint16_t value)
//{
//    static int count=0;
//    bool pre_reg[16];
//    bool new_reg[16];
//    for(int i=0;i<16;i++){
//        pre_reg[i]=_m_value[offset] &(1<<i);
//        new_reg[i]=value &(1<<i);
//    }
//    for(int i=0;i<16;i++){
//        HregDi temp;
//        if(pre_reg[i]!=new_reg[i]){
//            if(new_reg[i]==false){
//                 temp.ID=(((offset*16)+i)*2)+1;
//            }
//            else{
//                 temp.ID=(((offset*16)+i)*2)+2;
//            }
//            //            temp.ID=(offset*16)+i;//lấy offset
//            //            new_reg[i]==true?temp.ID=(offset*16)+i
//            temp.time=QDateTime::currentDateTime();
//            FiFoPush(temp);
//            count ++;
//            qDebug()<<"event at ID: "<<temp.ID<<" time: "<<temp.time;
//            qDebug()<<count;

//        }
//    }
//    _m_value[offset]=value;
//}
void DI::dataParse(int offset ,uint16_t value)
{
    qDebug()<<"Time Now:"<<QDateTime::currentDateTime();
}
void DI::FiFoPush(HregDi &data)
{
//    HregDi test;
    fifo.enqueue(data);
    if(getFiFoCount()>1125){
        qDebug()<<"Over fifo Hreg and save data";
        fifo.clear();
    }
//    test=fifo.at(0);
    qDebug()<<" fifo store num: "<<fifo.count();
}
void DI::modbusInputStatusTask()
{
   // qDebug()<<"input status task";
    for(int i=0;i<NUM_DI;i++){
        for(int j=0;j<16;j++){
            mbTCP->writeISts((16*i)+j,getValue(i)&(1<<j));
        }
    }
}
int DI::getFiFoCount()
{
    return fifo.count();
}

void DI::modbusHregTask()
{
    //  HregDi temp=fifo.at(fifo.count()-1);
    //qDebug()<<"event at ID: "<<temp.ID<<" time: "<<temp.time;
    int j=0;
    for(int i=fifo.count()-1;i>=0;i--){
        HregDi temp=fifo.at(i);
       // qDebug()<<"ID "<<temp.ID;
        mbTCP->writeHreg((j*8)+0,temp.ID);
        mbTCP->writeHreg((j*8)+1,temp.time.date().year()%100);
        mbTCP->writeHreg((j*8)+2,temp.time.date().month());
        mbTCP->writeHreg((j*8)+3,temp.time.date().day());
        mbTCP->writeHreg((j*8)+4,temp.time.time().hour());
        mbTCP->writeHreg((j*8)+5,temp.time.time().minute());
        mbTCP->writeHreg((j*8)+6,temp.time.time().second());
        mbTCP->writeHreg((j*8)+7,temp.time.time().msec());
        j++;

    }
}
void DI::valueChanged(int &offset, uint16_t &value){

   // qDebug()<<"value at: "<<offset<<" changed is: "<< bin <<value;
    modbusInputStatusTask();
    dataParse(offset,value);
    // FiFoPush(hregDi[offset/16]);
    modbusHregTask();
//    file->mkdir("SOE_LOG/"+timeString->getStringCurrentYear()+"/"+timeString->getStringCurrentMonth()+"/"+timeString->getStringCurrentDay());
}

void DI::updateChanged(QDate time)
{
    qDebug()<<"time changed";
}

