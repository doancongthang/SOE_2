#ifndef MODBUSTCP_H
#define MODBUSTCP_H
#include <QModbusTcpServer>
#include <QObject>
#include <QDebug>
#include <QDateTime>
#include <QNetworkInterface>
class modbusTCP : public QObject
{
    Q_OBJECT
public:
    explicit modbusTCP(QObject *parent = nullptr);
    void setIP(QString ip);
    void  setPort(int port);
    void setId(int id);
    bool connected();
    bool startConnection();
    void stopConnection();
    void setDeviceName(QString deviceName);
    void addHreg(int off_set, quint16 num_reg);
    void addCoil(int off_set, quint16 num_reg);
    void addISts(int off_set, quint16 num_reg);
    void addIReg(int off_set, quint16 num_reg);
    void writeHreg(int offset, quint16 value);
    void writeIReg(int offset, quint16 value);
    void writeISts(int offset,bool value);

  QString getLocalIp();
signals:
private slots:

   bool onModbusStateChanged(QModbusDevice::State state);
private:
   QModbusTcpServer *modbusDevice= nullptr;
   QString _ip;
   QString _deviceName="";
   bool _connection_state=false;
   int _port;
   int _id;
   QDateTime _utcTimeDisconnect;
   QModbusDataUnitMap _reg;
};

#endif // MODBUSTCP_H
