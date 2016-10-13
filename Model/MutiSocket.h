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
    enum Code{NOERROR=0x0,CREATEERROR=0x1};
    MutiSocket(quint16 port,QHostAddress address=QHostAddress::LocalHost,QObject *parent=0);
    MutiSocket(quint32 timeout,quint16 port,QHostAddress address=QHostAddress::LocalHost,QObject *parent=0);
    virtual ~MutiSocket();
protected:
    QHostAddress       m_address;
    quint16            m_port;
    quint32            m_time;
    int                m_code;
    QByteArray         m_data;
signals:
    void displayError(QString);
    void disconnectedToSocket();
public:
    virtual void sendMsg(QByteArray msg)=0;
    virtual QByteArray recvMsg()=0;
    virtual void breakConnect()=0;

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
    QByteArray recvMsg();
    void breakConnect();
protected slots:
    void someerror();
    void dis();
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
    QByteArray recvMsg();
    void breakConnect();
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
