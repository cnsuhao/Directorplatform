#ifndef MUTISOCKET_H
#define MUTISOCKET_H

#include <QObject>
#include <QUdpSocket>
#include <QTcpServer>
#include <QHostAddress>






class MutiSocket : public QObject
{
    Q_OBJECT
public:
    MutiSocket(quint16 port,QHostAddress address=QHostAddress::LocalHost,QObject *parent=0);
    MutiSocket(quint32 timeout,quint16 port,QHostAddress address=QHostAddress::LocalHost,QObject *parent=0);
    virtual ~MutiSocket();
protected:
    QHostAddress       m_address;
    quint16            m_port;
    quint32            m_time;
    QByteArray         m_data;
signals:
    void displayError(QString);
    void disconnectedToSocket();
    void waitforRead();
public:
    virtual void sendMsg(QByteArray msg)=0;
   // virtual QByteArray recvMsg()=0;
    virtual void breakConnect()=0;

    virtual qint64 getMsgLength()=0;
    virtual qint64 read(char* data,qint64 maxlen)=0;
    virtual QByteArray read(qint64 maxlen)=0;
    virtual QByteArray readAll()=0;
    virtual qint64 readData(char* data,qint64 maxlen)=0;// BEST For UDP
    virtual qint64 readLine(char*data,qint64 maxlen)=0;
    virtual bool  peedToRead()=0;


};



class TCPSocket : public MutiSocket
{
     Q_OBJECT
public:
    TCPSocket(quint16 port,QHostAddress address=QHostAddress::LocalHost,QObject *parent=0);
    TCPSocket(quint32 timeout,quint16 port,QHostAddress address=QHostAddress::LocalHost,QObject *parent=0);
    ~TCPSocket();
signals:
public:
    void sendMsg(QByteArray msg);
    //QByteArray recvMsg();
    void breakConnect();

    qint64 getMsgLength();
    qint64 read(char* data,qint64 maxlen);
    QByteArray read(qint64 maxlen);
    QByteArray readAll();
    qint64 readData(char* data,qint64 maxlen);
    qint64 readLine(char*data,qint64 maxlen);
    bool   peedToRead();
protected slots:
    void someerror();
    void dis();
    void recv();
private:
    QTcpSocket   *m_socket;
    void initSocket();
};


class UDPSocket :public MutiSocket
{
    Q_OBJECT
public:
    UDPSocket(quint16 port,QHostAddress address=QHostAddress::LocalHost,QObject *parent=0);
    UDPSocket(quint16 port,quint16 recvPort,QHostAddress address=QHostAddress::LocalHost,QObject *parent=0);
    ~UDPSocket();
signals:
public:
    void sendMsg(QByteArray msg);
   // QByteArray recvMsg();
    void breakConnect();

    qint64 getMsgLength();
    qint64 read(char* data,qint64 maxlen);
    QByteArray read(qint64 maxlen);
    QByteArray readAll();
    qint64 readData(char* data,qint64 maxlen);
    qint64 readLine(char*data,qint64 maxlen);
    bool peedToRead();
public slots:
    void someerror();
    void someerror1();
    void dis();
    void recv();
private:
    QUdpSocket    *m_socket;//send
    QUdpSocket    *m_bindsocket;//recv
    quint16       m_recvport;
    void initSocket();

};




#endif // MUTISOCKET_H
