#include "QSystemSettingWidget.h"
#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>
#include <QTextDocument>


QSettingWidget::QSettingWidget(QWidget *parent) :
    QWidget(parent),canMove(false)
{
    m_labTitle = new QLabel("SettingWidget");
    m_labTitle->setFixedHeight(30);
    m_mainTab = new QTabWidget();
    m_titleLay = new QHBoxLayout();
    m_dlgLay = new QHBoxLayout();
    m_con = new QVBoxLayout();
    m_con->setMargin(0);


    emptyLab = new QLabel();

    m_okBtn = new QPushButton(tr("Ok"));
    m_applyBtn = new QPushButton(tr("Apply"));
    m_cannelBtn = new QPushButton(tr("Cannel"));

    m_titleLay->addWidget(m_labTitle,2,Qt::AlignTop|Qt::AlignHCenter);
    m_dlgLay->addWidget(emptyLab,10);
    m_dlgLay->addWidget(m_okBtn,0,Qt::AlignTop);
    m_dlgLay->addWidget(m_applyBtn,0,Qt::AlignTop);
    m_dlgLay->addWidget(m_cannelBtn,0,Qt::AlignTop);
    m_dlgLay->addStretch(1);
    m_okBtn->setFixedWidth(45);
    m_applyBtn->setFixedWidth(45);
    m_cannelBtn->setFixedWidth(45);
    m_dlgLay->setSpacing(20);
    m_dlgLay->setMargin(0);
    m_con->addLayout(m_titleLay);
    m_con->addWidget(m_mainTab,20);
    m_con->addLayout(m_dlgLay);


    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setLayout(m_con);
    this->resize(680,480);


    connect(m_okBtn,SIGNAL(clicked()),this,SLOT(clicked_OK()));
    connect(m_applyBtn,SIGNAL(clicked()),this,SLOT(clicked_Apply()));
    connect(m_cannelBtn,SIGNAL(clicked()),this,SLOT(clicked_Cannel()));

}

QSettingWidget::~QSettingWidget()
{

}

void QSettingWidget::SetTitle(const QString &title)
{
    m_labTitle->setText(title);
}

void QSettingWidget::AddPage(QWidget *widget, const QString &tabTitle)
{
    m_mainTab->addTab(widget,tabTitle);
}

void QSettingWidget::AddPage(QWidget *widget, const QString &tabTitle, const QIcon &icon)
{
    m_mainTab->addTab(widget,icon,tabTitle);
}

int QSettingWidget::PageCount()const
{
    return m_mainTab->count();
}

int QSettingWidget::CurrentIndex()const
{
    return m_mainTab->currentIndex();
}

QWidget* QSettingWidget::CurrentWidget()const
{
    return m_mainTab->currentWidget();
}

void QSettingWidget::SetPageIcon(int index,const QIcon &icon)
{
    m_mainTab->setTabIcon(index,icon);
}

void QSettingWidget::SetPageTitle(int index, const QString &title)
{
    m_mainTab->setTabText(index,title);
}

void QSettingWidget::SetPageToolTip(int index, const QString &tip)
{
    m_mainTab->setTabToolTip(index,tip);
}



void QSettingWidget::clicked_OK()
{

    QMessageBox::warning(0,"tip","you select ok",0,0);
    close();
}

void QSettingWidget::clicked_Apply()
{
    QMessageBox::warning(0,"tip","you select Apply",0,0);

}

void QSettingWidget::clicked_Cannel()
{
    QMessageBox::warning(0,"tip","you select Cannel",0,0);
    close();

}

void QSettingWidget::paintEvent(QPaintEvent *event)
{
    //draw title bar
    QPainter painter(this);
    QRect rectTitle=rect();
    rectTitle.setHeight(30);
    painter.fillRect(rectTitle,QColor(75,73,67));
   // painter.fillRect(rectTitle,QColor(228,92,45));
    QPainterPath path;
    path.addRoundRect(rect(),2,2);
    QPolygon polygon= path.toFillPolygon().toPolygon();
    QRegion region(polygon);
    setMask(region);
}

void QSettingWidget::mousePressEvent(QMouseEvent *event)
{
   if(event->buttons()==Qt::LeftButton && event->pos().y()<30)
   {
       canMove = true;
       oldPoint = event->globalPos()-pos();
   }
}

void QSettingWidget::mouseReleaseEvent(QMouseEvent *event)
{
   canMove = false;
}

void QSettingWidget::mouseMoveEvent(QMouseEvent *event)
{
   if(canMove)
   {
       move(event->globalPos()-oldPoint);
       oldPoint = event->globalPos()-pos();
   }
}





/*********************************SUB_PAGE***********************************/

// 用户管理
QUserMgr::QUserMgr(QWidget* parent):QWidget(parent)
{

}

QUserMgr::~QUserMgr()
{

}

// 串口设置

QSerialPort::QSerialPort(QWidget* parent):QWidget(parent)
{

}

QSerialPort::~QSerialPort()
{

}
// 磁盘管理
QDiskMgr::QDiskMgr(QWidget* parent):QWidget(parent)
{

}

QDiskMgr::~QDiskMgr()
{

}

// 网络配置

QNetConfig::QNetConfig(QWidget* parent):QWidget(parent)
{
   m_layout = new QHBoxLayout();
   m_netMain = new QGroupBox(tr("Main NetWork"));
   m_netSub = new QGroupBox(tr("Sub NetWork"));

   m_mainLayout = new QFormLayout();
   m_mainLayout->setSpacing(35);
   m_sublayout = new QFormLayout();
   m_sublayout->setSpacing(35);

   m_mainDHCP = new QCheckBox((tr("DHCP")));
   m_mainIP = new QLineEdit();
   //m_mainIP->setInputMask("000.000.000.000;");
   QRegExp regexp("^(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])$");
   QRegExpValidator *vareg= new QRegExpValidator(regexp,this);
  // m_mainIP->setValidator(vareg);
   m_mainMask = new QLineEdit();
   m_mainMask->setValidator(vareg);
   m_mainGateway = new QLineEdit();
   m_mainGateway->setValidator(vareg);
   m_mainDNS = new QLineEdit();
   m_mainDNS->setValidator(vareg);
   m_mainDNS->setPlaceholderText("8.8.8.8");
   m_mainMAC = new QLineEdit();
   m_mainMAC->setInputMask(">HH:HH:HH:HH:HH:HH;");

   m_subDHCP = new QCheckBox(tr("DHCP"));
   m_subIP = new QLineEdit();
   m_sub_Mask = new QLineEdit();
   m_subGateway = new QLineEdit();
   m_subDNS = new QLineEdit();
   m_subMAC = new QLineEdit();

   m_mainLayout->addRow(m_mainDHCP,new QLabel());
   m_mainLayout->addRow(tr("IP"),m_mainIP);
   m_mainLayout->addRow(tr("Mask"),m_mainMask);
   m_mainLayout->addRow(tr("Gateway"),m_mainGateway);
   m_mainLayout->addRow(tr("DNS"),m_mainDNS);
   m_mainLayout->addRow(tr("MAC"),m_mainMAC);

   m_sublayout->addRow(m_subDHCP,new QLabel());
   m_sublayout->addRow(tr("IP"),m_subIP);
   m_sublayout->addRow(tr("Mask"),m_sub_Mask);
   m_sublayout->addRow(tr("Gateway"),m_subGateway);
   m_sublayout->addRow(tr("DNS"),m_subDNS);
   m_sublayout->addRow(tr("MAC"),m_subMAC);


   m_netMain->setLayout(m_mainLayout);
   m_netSub->setLayout(m_sublayout);


   m_layout->addWidget(m_netMain);
   m_layout->addWidget(m_netSub);

   this->setLayout(m_layout);

   //event
   connect(m_mainDHCP,SIGNAL(stateChanged(int)),this,SLOT(mainCheckChange(int)));
   connect(m_subDHCP,SIGNAL(stateChanged(int)),this,SLOT(subCheckChange(int)));

   connect(m_mainIP,SIGNAL(returnPressed()),this,SLOT(ReturnKey()));


}
QNetConfig::~QNetConfig()
{

}

void QNetConfig::mainCheckChange(int c)
{
    switch (c)
    {
    case Qt::Checked:
        setMainEnabled(false);
        break;
    case Qt::Unchecked:
        setMainEnabled(true);
        break;
    case Qt::PartiallyChecked:
        break;
    default:
        break;
    }
}

void QNetConfig::subCheckChange(int state)
{
    switch (state)
    {
    case Qt::Checked:
        setSubEnabled(false);
        break;
    case Qt::Unchecked:
        setSubEnabled(true);
        break;
    case Qt::PartiallyChecked:
        break;
    default:
        break;
    }
}
void QNetConfig::setMainEnabled(bool ienabled)
{
    m_mainIP->setEnabled(ienabled);
    m_mainMask->setEnabled(ienabled);
    m_mainGateway->setEnabled(ienabled);
    m_mainDNS->setEnabled(ienabled);
    m_mainMAC->setEnabled(ienabled);

}
void QNetConfig::setSubEnabled(bool ienabled)
{
    m_subIP->setEnabled(ienabled);
    m_sub_Mask->setEnabled(ienabled);
    m_subGateway->setEnabled(ienabled);
    m_subDNS->setEnabled(ienabled);
    m_subMAC->setEnabled(ienabled);
}


void QNetConfig::ReturnKey()
{
    //QMessageBox::warning(0,"","21",0,0);
    QString s= m_mainIP->text();
    QStringList l=s.split(".");
    if(l.size()!=4)
    {
        QMessageBox::warning(0,"","too short",0,0);
    }

}


//网络测试

QNetTest::QNetTest(QWidget* parent):QWidget(parent)
{
    m_con = new QVBoxLayout();
    m_proc = new QProcess(this);
    m_commandLine = new QLineEdit();
    m_commandInfo = new QPlainTextEdit();
    m_commandLine->setPlaceholderText(tr("input command"));

    m_con->addWidget(m_commandLine);
    m_con->addWidget(m_commandInfo);
    this->setLayout(m_con);

    //event band

    connect(m_commandLine,SIGNAL(returnPressed()),this,SLOT(returnKey()));
    connect(m_proc,SIGNAL(readyReadStandardOutput()),this,SLOT(showStdOutInfo()));


}

QNetTest::~QNetTest()
{

}
void QNetTest::returnKey()
{
    //QMessageBox::warning(0,"","sa",0,0);

    m_commandInfo->clear();
    m_proc->start(m_commandLine->text());
    m_proc->waitForReadyRead();

}
void QNetTest::showStdOutInfo()
{
    QByteArray bt=m_proc->readAllStandardOutput();

    m_commandInfo->appendPlainText(QString::fromLocal8Bit(bt));
}

//显卡设置
QGrapCard::QGrapCard(QWidget* parent):QWidget(parent)
{

}

QGrapCard::~QGrapCard()
{

}

//中控设置

QCtrlSetting::QCtrlSetting(QWidget* parent):QWidget(parent)
{

}

QCtrlSetting::~QCtrlSetting()
{

}

// 系统信息

QSystemInfo::QSystemInfo(QWidget* parent):QWidget(parent)
{

}
QSystemInfo::~QSystemInfo()
{

}




/**********************************END********************************/

QSystemSettingWidget::QSystemSettingWidget(QWidget *parent) :
    QSettingWidget(parent)
{
    userMgrWidget = new QUserMgr();
    serialPortWidget = new QSerialPort();
    diskMgrWidget = new QDiskMgr();
    netConfigWidget = new QNetConfig();
    netTestWidget = new QNetTest();
    grapCardWidget = new QGrapCard();
    ctrlSetting = new QCtrlSetting();
    systemInfoWidget = new QSystemInfo();


    AddPage(userMgrWidget,tr("User"));
    AddPage(serialPortWidget,tr("Serial"));
    AddPage(diskMgrWidget,tr("Disk"));
    AddPage(netConfigWidget,tr("NetWork-C"));
    AddPage(netTestWidget,tr("Network-T"));
    AddPage(grapCardWidget,tr("GraphicsCard"));
    AddPage(ctrlSetting,tr("CenterCtrl"));
    AddPage(systemInfoWidget,tr("Information"));
    SetTitle(tr("system setting"));

}

QSystemSettingWidget::~QSystemSettingWidget()
{

}

void QSystemSettingWidget::clicked_OK()
{
   close();
}
void QSystemSettingWidget::clicked_Apply()
{
}
void QSystemSettingWidget::clicked_Cannel()
{
  close();
}
