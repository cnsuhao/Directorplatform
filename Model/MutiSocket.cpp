//#include "MutiSocket.h"

//MutiSocket::MutiSocket(QObject *parent) :
//    QObject(parent)
//{
//}

//MutiSocket::MutiSocket(quint16 port, QHostAddress address, QObject *parent):QObject(parent),m_port(port),m_address(address)
//{

//}

//void MutiSocket::setPort(quint16 port)
//{
//    m_port = port;
//}

//void MutiSocket::setAddress(QHostAddress &address)
//{
//    m_address = address;
//}

//MutiSocket::~MutiSocket()
//{

//}

///*************************************************************************/


//UDPSocket::UDPSocket(QObject *parent):MutiSocket(parent)
//{
//    m_port = 1;
//    m_address = QHostAddress::LocalHost;
//    init();
//}


//UDPSocket::UDPSocket(quint16 port, QHostAddress address, QObject *parent):MutiSocket(port,address,parent)
//{
//    init();
//}

//UDPSocket::init()
//{
//    socket = new QUdpSocket(this);

//    connect(socket,SIGNAL(readyRead()),this,SLOT(recvData()));

//    if(!socket->bind(m_address,m_port,QUdpSocket::ShareAddress))
//    {
//        emit createError(CREATEERROR);
//        m_code = CREATEERROR;
//        return;
//    }
//    emit createError(NOERROR);
//    m_code=NOERROR;

//}

//UDPSocket::~UDPSocket()
//{
//    socket->close();
//    delete socket;
//}


//bool UDPSocket::sendMsg(const QVariant &var)
//{
//    if(m_code==NOERROR)
//    {
//        QVariant tmp=var;
//        socket->writeDatagram(tmp.toByteArray(),m_addres,m_port);
//    }
//}

//bool UDPSocket::recvMsg(QByteArray msg)
//{
//    QByteArray tmpdata;
//    tmpdata.resize(socket->pendingDatagramSize());
//    socket->readDatagram(tmpdata.data(),tmpdata.size(),m_address,m_port);
//    for(int i=0;i<tmpdata.size();i++)
//    {
//        msg.append(tmpdata.at(i));
//    }
//}

//void UDPSocket::setTimeout(const qint32 time)
//{

//}

//void UDPSocket::recvData()
//{
//    while (socket->hasPendingDatagrams())
//    {
//        recvMsg()
//    }
//}
























