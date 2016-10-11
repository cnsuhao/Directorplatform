//#ifndef MUTISOCKET_H
//#define MUTISOCKET_H

//#include <QObject>
//#include <QUdpSocket>
//#include <QTcpServer>
//#include <QHostAddress>

///**********************************************************
// *                      MutiSocket
// *
// *  1,TCP/UDP可选
// *  2,相同发送和接受消息接口
// *  3,相同的配置接口
// *
// *
// *
// *
// *
// *
// *
// **********************************************************/




//class MutiSocket : public QObject
//{
//    Q_OBJECT
//public:
//    enum Code{NOERROR=0x0,CREATEERROR=0x1};
//    MutiSocket(QObject *parent = 0);
//    MutiSocket(quint16 port,QHostAddress address=QHostAddress::LocalHost,QObject *parent=0);
//    virtual ~MutiSocket();
//    virtual bool sendMsg(const QVariant& var)=0;
//    virtual void setTimeout(const qint32 time)=0;
//    virtual bool recvMsg(QByteArray msg)=0;
//    virtual void setPort(quint16 port);
//    virtual void setAddress(QHostAddress &address);
//protected:
//    QHostAddress       m_address;
//    quint16            m_port;
//    int                m_code;
//signals:
//    void createError(int);
//public slots:
//    virtual void recvData()=0;

//};



////class TCPSocket : public MutiSocket
////{
////public:
////    TCPSocket(QObject *parent=0);
////    ~TCPSocket();
////signals:
////public:
////    bool sendMsg(const QVariant &var);
////    void setTimeout(const qint32 time);
////    bool recvMsg(char *msg, qint32 length);
////public slots:
////    void readyRead();
////private:
////    QTcpSocket   *socket;
////};


//class UDPSocket :public MutiSocket
//{
//public:
//    UDPSocket(QObject *parent=0);
//    UDPSocket(quint16 port,QHostAddress address=QHostAddress::LocalHost,QObject *parent=0);
//    ~UDPSocket();
//signals:
//public:
//    bool sendMsg(const QVariant &var);
//    void setTimeout(const qint32 time);
//    bool recvMsg(QByteArray  msg);
//public slots:
//    void recvData();
//private:
//    QUdpSocket    *socket;
//    void init();

//};




//#endif // MUTISOCKET_H
