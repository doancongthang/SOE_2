#include "modbustcp.h"
#include <qloggingcategory.h>
modbusTCP::modbusTCP(QObject *parent)
    : QObject{parent}
{
modbusDevice = new QModbusTcpServer;
}
void modbusTCP::setIP(QString ip){
    _ip=ip;
}
void modbusTCP::setPort(int port){
    _port=port;
}
void modbusTCP::setId(int id){
    _id=id;
}

bool modbusTCP::connected()
{
return _connection_state;
}
void modbusTCP::setDeviceName(QString deviceName){
    _deviceName=deviceName;
}
bool modbusTCP::startConnection(){
connect(modbusDevice, &QModbusTcpServer::stateChanged, this, &modbusTCP::onModbusStateChanged);
    modbusDevice->setConnectionParameter(QModbusDevice::NetworkPortParameter,_port);
    modbusDevice->setConnectionParameter(QModbusDevice::NetworkAddressParameter,_ip);
    modbusDevice->setServerAddress(_id);
// QLoggingCategory::setFilterRules(QStringLiteral("qt.modbus* = true"));
    if(!modbusDevice){
        qDebug()<<"Modbus create fail"+ _deviceName;
        return false;
    }
    if(!modbusDevice->connectDevice()){
        qDebug()<<"modbus cannot connect"+_deviceName;
        _connection_state=false;
//        emit varChanged();
    }
    else {
        qDebug()<<"Modbus connected "+_deviceName+": "<<modbusDevice->state();
        _connection_state=true;
    }
return true;


}
void modbusTCP::stopConnection(){
    qDebug()<<"Modbus disconnection "+_deviceName;
    modbusDevice->disconnectDevice();
    _connection_state=false;

}
bool modbusTCP::onModbusStateChanged(QModbusDevice::State state){
qDebug()<<_deviceName+" State changed: "<< state;
_connection_state=(state==QModbusDevice::ConnectedState);
if(state!=QModbusDevice::ConnectedState){
    _utcTimeDisconnect=QDateTime::currentDateTimeUtc();
}
return true;
}

QString modbusTCP::getLocalIp()
{
    QString ip="";

//    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
//    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
//        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
//             qDebug() << address.toString();
//       return address.toString();
//    }

    QNetworkInterface eth1Ip = QNetworkInterface::interfaceFromName("eth0");
    QList<QNetworkAddressEntry> entries = eth1Ip.addressEntries();
    if (!entries.isEmpty()) {
        QNetworkAddressEntry entry = entries.first();
     //   qDebug() << entry.ip().toString();
        ip=entry.ip().toString();


    }
    return ip;

}
void modbusTCP::addCoil(int offset, quint16 num_regs){
    _reg.insert(QModbusDataUnit::Coils, { QModbusDataUnit::Coils, offset, num_regs });
    modbusDevice->setMap(_reg);
}
void modbusTCP::addHreg(int offset, quint16 num_regs){
    _reg.insert(QModbusDataUnit::HoldingRegisters,{QModbusDataUnit::HoldingRegisters,offset,num_regs});
    modbusDevice->setMap(_reg);
}
void modbusTCP::addISts(int offset, quint16 num_regs){
    _reg.insert(QModbusDataUnit::DiscreteInputs,{QModbusDataUnit::DiscreteInputs,offset,num_regs});
    modbusDevice->setMap(_reg);
}
void modbusTCP::addIReg(int offset, quint16 num_regs){
    _reg.insert(QModbusDataUnit::InputRegisters,{QModbusDataUnit::InputRegisters,offset,num_regs});
    modbusDevice->setMap(_reg);

}
void modbusTCP::writeHreg(int offset, quint16 value){
    modbusDevice->setData(QModbusDataUnit::HoldingRegisters,offset,value);
}
void modbusTCP::writeIReg(int offset,quint16 value){
    modbusDevice->setData(QModbusDataUnit::InputRegisters,offset,value);
}

void modbusTCP::writeISts(int offset, bool value)
{
    modbusDevice->setData(QModbusDataUnit::DiscreteInputs,offset,value);
}

