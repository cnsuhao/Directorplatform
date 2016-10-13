#include "MutiSocket.h"
#include <QTcpSocket>
#include <QUdpSocket>



MutiSocket::MutiSocket(quint16 port, QHostAddress address, QObject *parent):QObject(parent),m_port(port),m_address(address)
{
    m_time = 30000;
}

MutiSocket::MutiSocket(quint32 timeout, quint16 port, QHostAddress address, QObject *parent):m_time(timeout),
    m_port(port),m_address(address),QObject(parent)
{

}

MutiSocket::~MutiSocket()
{

}

/*************************************************************************/



TCPSocket::TCPSocket(quint16 port, QHostAddress address, QObject *parent):MutiSocket(port,address,parent)
{
    initSocket();
}

TCPSocket::TCPSocket(quint32 timeout, quint16 port, QHostAddress address, QObject *parent):MutiSocket(timeout,port,address,parent)
{

}
TCPSocket::~TCPSocket()
{
   breakConnect();
    // when init parent,it can auto release !
}


void TCPSocket::sendMsg(QByteArray msg)
{
    m_socket->write(msg);
}
void TCPSocket::recv()
{
   emit waitforRead();
}
void TCPSocket::breakConnect()
{
    m_socket->disconnectFromHost();
    m_socket->close();
}
void TCPSocket::someerror()
{
    emit displayError(m_socket->errorString());
}

void TCPSocket::dis()
{
    emit disconnectedToSocket();
}
void TCPSocket::initSocket()
{
    m_socket = new QTcpSocket(this);
    connect(m_socket,SIGNAL(disconnected()),this,SLOT(dis()));
    connect(m_socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(someerror()));
    m_socket->connectToHost(m_address,m_port);
    connect(m_socket,SIGNAL(readyRead()),this,SLOT(recv));
}

qint64 TCPSocket::getMsgLength()
{
    return m_socket->readBufferSize();
}

qint64 TCPSocket::read(char *data, qint64 maxlen)
{
    return m_socket->read(data,maxlen);
}

QByteArray TCPSocket::read(qint64 maxlen)
{
    return m_socket->read(maxlen);
}

QByteArray TCPSocket::readAll()
{
    return m_socket->readAll();
}

qint64 TCPSocket::readData(char *data, qint64 maxlen)
{
    return m_socket->read(data,maxlen);
}

qint64 TCPSocket::readLine(char *data, qint64 maxlen)
{
    return m_socket->readLine(data,maxlen);
}

bool TCPSocket::peedToRead()
{
    return true;
}
/************************************************************************************************/


UDPSocket::UDPSocket(quint16 port, QHostAddress address, QObject *parent):MutiSocket(port,address,parent),m_recvport(port+1)
{
    initSocket();
}

UDPSocket::UDPSocket(quint16 port, quint16 recvPort, QHostAddress address, QObject *parent):MutiSocket(port,address,parent),m_recvport(recvPort)
{
    initSocket();
}

UDPSocket::~UDPSocket()
{
   breakConnect();
}


void UDPSocket::initSocket()
{
    // recv
    m_bindsocket = new QUdpSocket(this);
    m_bindsocket->bind(QHostAddress::Any,m_recvport,QUdpSocket::ShareAddress);
    connect(m_bindsocket,SIGNAL(readyRead()),this,SLOT(recv()));
    connect(m_bindsocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(someerror()));
    connect(m_bindsocket,SIGNAL(disconnected()),this,SLOT(dis()));

    //send
    m_socket = new QUdpSocket(this);
    m_socket->connectToHost(m_address,m_port);
    connect(m_socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(someerror1()));
    connect(m_socket,SIGNAL(disconnected()),this,SLOT(dis()));
}

void UDPSocket::sendMsg(QByteArray msg)
{
    m_socket->write(msg);
}

void UDPSocket::recv()
{
   emit waitforRead();
}

void UDPSocket::breakConnect()
{
    m_socket->disconnectFromHost();
    m_bindsocket->disconnectFromHost();

    m_socket->close();
    m_bindsocket->close();
}

void UDPSocket::someerror1()
{
    emit displayError(m_socket->errorString());
}

void UDPSocket::someerror()
{
    emit displayError(m_bindsocket->errorString());
}

void UDPSocket::dis()
{
    emit disconnectedToSocket();
}


qint64 UDPSocket::getMsgLength()
{
    return m_bindsocket->pendingDatagramSize();
}

qint64 UDPSocket::read(char *data, qint64 maxlen)
{
    return m_bindsocket->read(data,maxlen);
}

QByteArray UDPSocket::read(qint64 maxlen)
{
    return m_bindsocket->read(maxlen);
}

QByteArray UDPSocket::readAll()
{
    return m_bindsocket->readAll();
}

qint64 UDPSocket::readData(char *data, qint64 maxlen)
{
    return m_bindsocket->readDatagram(data,maxlen);
}

qint64 UDPSocket::readLine(char *data, qint64 maxlen)
{
    return m_bindsocket->readLine(data,maxlen);
}

bool UDPSocket::peedToRead()
{
    return m_bindsocket->hasPendingDatagrams();
}
