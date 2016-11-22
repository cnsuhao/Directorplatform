#include "QSystemSettingWidget.h"
#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>
#include <QTextDocument>
#include <QHeaderView>
#include <QDir>
#include "PlatformConfig.h"
#include <QTextStream>
#include <Model/TipDialog.h>

#include "Model/ConfigFile.h"

QSettingWidget::QSettingWidget(QWidget *parent) :
    QWidget(parent),canMove(false)
{
    m_labTitle = new QLabel("SettingWidget");
    m_labTitle->setFixedHeight(30);
    m_mainTab = new QTabWidget();
    m_mainTab->setStyleSheet("QTabWidget{border: 5px solid rgb(255,0,0);}");
    m_titleLay = new QHBoxLayout();
    m_dlgLay = new QHBoxLayout();
    m_con = new QVBoxLayout();
    m_con->setMargin(0);


    emptyLab = new QLabel();

    m_okBtn = new QPushButton(tr("Ok"));
    m_okBtn->setFixedSize(32,20);
    m_okBtn->setStyleSheet(SYS_SETTING_OK);
    m_applyBtn = new QPushButton(tr("Apply"));
    m_applyBtn->setFixedSize(32,20);
    m_applyBtn->setStyleSheet(SYS_SETTING_APPLY);
    m_cannelBtn = new QPushButton(tr("Cannel"));
    m_cannelBtn->setFixedSize(32,20);
    m_cannelBtn->setStyleSheet(SYS_SETTING_CANNEL);

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

   // painter.fillRect(rect(),QColor(48,48,48));
    painter.fillRect(rectTitle,QColor(75,73,67));
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
    QObjectList objlist=this->children();

    foreach (QObject *obj, objlist)
    {
        if(obj)
        {
            delete obj;
            obj=NULL;
        }
    }
}

// 串口设置

QSerialPort::QSerialPort(QWidget* parent):QWidget(parent)
{

}

QSerialPort::~QSerialPort()
{
    QObjectList objlist=this->children();

    foreach (QObject *obj, objlist)
    {
        if(obj)
        {
            delete obj;
            obj=NULL;
        }
    }
}
// 磁盘管理
QDiskMgr::QDiskMgr(QWidget* parent):QWidget(parent)
{
    m_lay_1 = new QHBoxLayout();
    m_lay_2 = new QHBoxLayout();
    m_lay_3 = new QHBoxLayout();

    m_fullAction = new QComboBox();
    m_fileSystem = new QComboBox();
    m_diskProtocol = new QComboBox();
    QStringList p;
    p<<"EXT4"<<"EXT3"<<"EXT2"<<"FAT32"<<"NTFS";
    m_diskProtocol->addItems(p);

    m_fullAction = new QComboBox();
    m_fileSystem = new QComboBox();
    m_diskProtocol = new QComboBox();

    m_forceMoveDiskRecord = new QCheckBox(tr("Forced moving disk video"));
    m_newDiskRecord = new QCheckBox(tr("New hard disk default video"));
    m_newMoveDiskRecord = new QCheckBox(tr("New mobile hard disk default video"));
    m_newNetDiskRecord = new QCheckBox(tr("New SkyDrive default video"));

    m_uponNetDriver = new QPushButton(tr("Map network drive"));
    m_Share = new QPushButton(tr("Shared settings"));

    L1.setText(tr("After full"));
    m_lay_1->addWidget(&L1);
    m_lay_1->addWidget(m_fullAction);
    m_lay_1->addStretch();
    L2.setText(tr("File system"));
    m_lay_1->addWidget(&L2);
    m_lay_1->addWidget(m_fileSystem);
     m_lay_1->addStretch();
    L3.setText(tr("protocol"));
    m_lay_1->addWidget(&L3);
    m_lay_1->addWidget(m_diskProtocol);

    m_lay_2->addWidget(m_forceMoveDiskRecord);
    m_lay_2->addWidget(m_newDiskRecord);
    m_lay_2->addWidget(m_newMoveDiskRecord);

    m_lay_3->addWidget(m_newNetDiskRecord);
    m_lay_3->addWidget(m_uponNetDriver);
    m_lay_3->addWidget(m_Share);

    m_tableview = new QTableWidget(7,8);
    m_tableview->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");
    m_headList<<tr("NO")<<tr("State")<<tr("Enabled")<<tr("Capacity")<<tr("Type")<<tr("Format")<<tr("Dump")<<tr("Record");

    int width= m_tableview->geometry().width()/8;
    for(int i=0;i<8;i++)
    {
        m_tableview->setColumnWidth(i,width);
    }
    m_tableview->setHorizontalHeaderLabels(m_headList);
    m_tableview->horizontalHeader()->setClickable(false);
    m_tableview->verticalHeader()->setVisible(false);
    m_con = new QVBoxLayout();
    m_con->addWidget(m_tableview);
    m_con->addLayout(m_lay_1);
    m_con->addLayout(m_lay_2);
    m_con->addLayout(m_lay_3);
    this->setLayout(m_con);

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
   m_mainIP->setStyleSheet("QLineEdit::text{align:center;}");
   connect(m_mainIP,SIGNAL(textChanged(QString)),this,SLOT(mainIPChange(QString)));
   m_mainIP->setInputMask("000.000.000.000;");
   QRegExp regexp("^(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])\.(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9]?[0-9])$");
   QRegExpValidator *vareg= new QRegExpValidator(regexp,this);
  // m_mainIP->setValidator(vareg);
   m_mainMask = new QLineEdit();
   m_mainMask->setInputMask("000.000.000.000;");
  // m_mainMask->setValidator(vareg);
   m_mainGateway = new QLineEdit();
   m_mainGateway->setInputMask("000.000.000.000;");
  // m_mainGateway->setValidator(vareg);
   m_mainDNS = new QLineEdit();
   m_mainDNS->setInputMask("000.000.000.000;");
   m_mainDNS->setPlaceholderText("8.8.8.8");
   m_mainMAC = new QLineEdit();
   m_mainMAC->setInputMask(">HH:HH:HH:HH:HH:HH;");

   m_subDHCP = new QCheckBox(tr("DHCP"));
   m_subIP = new QLineEdit();
   m_subIP->setInputMask("000.000.000.000;");
   m_sub_Mask = new QLineEdit();
   m_sub_Mask->setInputMask("000.000.000.000;");
   m_subGateway = new QLineEdit();
   m_subGateway->setInputMask("000.000.000.000;");
   m_subDNS = new QLineEdit();
   m_subDNS->setInputMask("000.000.000.000;");
   m_subMAC = new QLineEdit();
   m_subMAC->setInputMask(">HH:HH:HH:HH:HH:HH");

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
QNetConfig::~QNetConfig()
{
   QObjectList list = children();
   foreach (QObject *var, list)
   {
     if(var)
     {
         delete var;
         var =NULL;
     }
   }
   qDebug("QNetConfig children has been release\n");
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
    QString s= m_mainIP->text();
    QStringList l=s.split(".");
    if(l.size()!=4)
    {
        QMessageBox::warning(0,"","too short",0,0);
    }

}

void QNetConfig::mainIPChange(QString ipTxt)
{
    //QMessageBox::information(0,"",ipTxt,0,0);
}

QString QNetConfig::getMainIP()const
{
    return m_mainIP->text();
}

void QNetConfig::setMainIP(const QString &str)
{
    m_mainIP->setText(str);
}

QString QNetConfig::getSubIP() const
{
    return m_subIP->text();
}
void QNetConfig::setSubIP(const QString &str)
{
    m_subIP->setText(str);
}

QString QNetConfig::getMainMask() const
{
    return m_mainMask->text();
}
void QNetConfig::setMainMask(const QString &str)
{
    m_mainMask->setText(str);
}

QString QNetConfig::getSubMask()const
{
    return m_sub_Mask->text();
}
void QNetConfig::setSubMask(const QString &str)
{
    m_sub_Mask->setText(str);
}
QString QNetConfig::getMainGate()const
{
    return m_mainGateway->text();
}
void QNetConfig::setMainGate(const QString &str)
{
    m_mainGateway->setText(str);
}
QString QNetConfig::getSubGate()const
{
    return m_subGateway->text();
}
void QNetConfig::setSubGate(const QString &str)
{
    m_subGateway->setText(str);
}

QString QNetConfig::getMainDNS()const
{
    return m_mainDNS->text();
}
void QNetConfig::setMainDNS(const QString &str)
{
    m_mainDNS->setText(str);
}

QString QNetConfig::getSubDNS()const
{
    return m_subDNS->text();
}
void QNetConfig::setSubDNS(const QString &str)
{
    m_subDNS->setText(str);
}

QString QNetConfig::getMainMAC() const
{
    return m_mainMAC->text();
}
void QNetConfig::setMainMAC(const QString &str)
{
    m_mainMask->setText(str);
}

QString QNetConfig::getSubMAC() const
{
    return m_subMAC->text();
}

void QNetConfig::setSubMAC(const QString &str)
{
    m_subMAC->setText(str);
}
/********************************************************/
//网络测试

QNetTest::QNetTest(QWidget* parent):QWidget(parent)
{
    m_con = new QVBoxLayout();
    m_proc = new QProcess(this);
    m_commandLine = new QLineEdit();
    m_commandLine->setFixedWidth(300);
    m_commandInfo = new PlainTextYoo();
    m_commandLine->setPlaceholderText(tr("input command"));
    m_lay= new QHBoxLayout();
    m_executeBtn = new QPushButton(tr("Execute"));
    m_executeBtn->setFixedWidth(50);
    m_lay->addStretch(1);
    m_lay->addWidget(m_commandLine,0,Qt::AlignCenter);
    m_lay->addWidget(m_executeBtn,0,Qt::AlignLeft);
    m_lay->addStretch(1);
    m_con->addLayout(m_lay);
    //m_con->addWidget(m_commandLine,0,Qt::AlignCenter);
    //m_con->addWidget(m_executeBtn);
    m_con->addWidget(m_commandInfo);
    this->setLayout(m_con);

    //event band

    connect(m_commandLine,SIGNAL(returnPressed()),this,SLOT(returnKey()));
    connect(m_proc,SIGNAL(readyReadStandardOutput()),this,SLOT(showStdOutInfo()));

    connect(m_commandInfo,SIGNAL(Ctrl_C()),this,SLOT(exit_proc()));
    connect(m_executeBtn,SIGNAL(clicked()),this,SLOT(returnKey()));


}

void QNetTest::exit_proc()
{
    if(m_proc->isOpen())
     {
       m_proc->close();
       m_commandInfo->appendHtml("<font color=red>you press CTRL-C,the command broken</font>");
       m_commandInfo->appendHtml("<font color=black> </font>");
     }

}

QNetTest::~QNetTest()
{
    if(m_proc->isOpen())
    m_proc->close();

}
void QNetTest::returnKey()
{
    m_commandInfo->clear();
    if(m_proc->isOpen())
    m_proc->close();
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
    m_grapCard_1 = new QGroupBox(tr("Graphics Card 1"));
    m_grapCard_2 = new QGroupBox(tr("Graphics Card 2"));

    m_light_1 = new QSlider(Qt::Horizontal);
    m_light_1->setMaximum(100);
    m_light_1->setValue(50);
    m_light_2 = new QSlider(Qt::Horizontal);
    m_light_2->setMaximum(100);
    m_light_2->setValue(50);

    m_balance_1 = new QSlider(Qt::Horizontal);
    m_balance_1->setMaximum(100);
    m_balance_1->setValue(50);
    m_balance_2 = new QSlider(Qt::Horizontal);
    m_balance_2->setMaximum(100);
    m_balance_2->setValue(50);

    m_shade_1 = new QSlider(Qt::Horizontal);
    m_shade_1->setMaximum(100);
    m_shade_1->setValue(50);
    m_shade_2 = new QSlider(Qt::Horizontal);
    m_shade_2->setMaximum(100);
    m_shade_2->setValue(50);

    m_fill_1 = new QSlider(Qt::Horizontal);
    m_fill_1->setMaximum(100);
    m_fill_1->setValue(50);
    m_fill_2 = new QSlider(Qt::Horizontal);
    m_fill_2->setMaximum(100);
    m_fill_2->setValue(50);


    m_resolution_1 = new QComboBox();
    m_resolution_2 = new QComboBox();

    m_freq_1 = new QComboBox();
    m_freq_2 = new QComboBox();

    m_outputDevice = new QComboBox();

    m_audio = new QCheckBox();

    m_form_1 = new QFormLayout();
    m_form_1->setSpacing(20);
    m_form_1->addRow(tr("Output Device"),m_outputDevice);
    m_form_1->addRow(tr("resolution"),m_resolution_1);
    m_form_1->addRow(tr("Frequency"),m_freq_1);
    m_form_1->addRow(tr("Lighting"),m_light_1);
    m_form_1->addRow(tr("Contrast"),m_balance_1);
    m_form_1->addRow(tr("Shade"),m_shade_1);
    m_form_1->addRow(tr("Saturation"),m_fill_1);

    m_form_2 = new QFormLayout();
    m_form_2->setSpacing(20);
    m_form_2->addRow(tr("Audio"),m_audio);
    m_form_2->addRow(tr("resolution"),m_resolution_2);
    m_form_2->addRow(tr("Frequency"),m_freq_2);
    m_form_2->addRow(tr("Lighting"),m_light_2);
    m_form_2->addRow(tr("Contrast"),m_balance_2);
    m_form_2->addRow(tr("Shade"),m_shade_2);
    m_form_2->addRow(tr("Saturation"),m_fill_2);

    m_grapCard_1->setLayout(m_form_1);
    m_grapCard_2->setLayout(m_form_2);
    m_con = new QHBoxLayout();
    m_con->addWidget(m_grapCard_1);
    m_con->addWidget(m_grapCard_2);


    this->setLayout(m_con);

}



void QGrapCard::setMianLight(int value)
{
    m_light_1->setValue(value);
}
int QGrapCard::getMainLight()const
{
    return m_light_1->value();
}

void QGrapCard::setMainBalance(int value)
{
    m_balance_1->setValue(value);
}
int QGrapCard::getMainBalance()const
{
    return m_balance_1->value();
}

void QGrapCard::setMainShade(int value)
{
    m_shade_1->setValue(value);
}
int QGrapCard::getMainShade()const
{
    return m_shade_1->value();
}

void QGrapCard::setMainFill(int value)
{
    m_fill_1->setValue(value);
}
int QGrapCard::getMainFill()const
{
    return m_fill_1->value();
}

void QGrapCard::setSubLight(int value)
{
    m_light_2->setValue(value);
}
int QGrapCard::getSubLight()const
{
    return m_light_2->value();
}

void QGrapCard::setSubBalance(int value)
{
    m_balance_2->setValue(value);
}
int QGrapCard::getSubBalance()const
{
    return m_balance_2->value();
}

void QGrapCard::setSubShade(int value)
{
    m_shade_2->setValue(value);
}
int QGrapCard::getSubShade()const
{
    return m_shade_2->value();
}

void QGrapCard::setSubFill(int value)
{
    m_fill_2->setValue(value);
}

int QGrapCard::getSubFill()const
{
    return m_fill_2->value();
}



QGrapCard::~QGrapCard()
{
    QObjectList obj = this->children();

    foreach(QObject *var,obj)
    {
        if(var)
        {
            delete var;
            var = NULL;
        }
    }
}

//中控设置  18393366997---776917623

QCtrlSetting::QCtrlSetting(QWidget* parent):QWidget(parent)
{
    m_con = new QHBoxLayout();
    m_form1 = new QFormLayout();
    m_form2 = new QFormLayout();
    m_oneKeyPause = new QLineEdit();
    m_oneKeyPauseReturn = new QLineEdit();
    m_oneKeyStart = new QLineEdit();
    m_oneKeyStartReturn = new QLineEdit();
    m_oneKeyStop = new QLineEdit();
    m_oneKeyStopReturn = new QLineEdit();
    m_shutdown = new QLineEdit();
    m_shutdownReturn = new QLineEdit();
    m_lockVGA = new QLineEdit();
    m_lockVGAReturn = new QLineEdit();
    m_serialPort = new QComboBox();

    m_con->setMargin(30);
    m_form1->setSpacing(30);
    m_form1->addRow(tr("Serial Port"),m_serialPort);
    m_form1->addRow(tr("One Key Start"),m_oneKeyStart);
    m_form1->addRow(tr("One Key Pause"),m_oneKeyPause);
    m_form1->addRow(tr("One Key Stop"),m_oneKeyStop);
    m_form1->addRow(tr("Power off"),m_shutdown);
    m_form1->addRow(tr("Lock VGA"),m_lockVGA);
    m_form2->setSpacing(30);
    m_form2->addRow(tr(""),&tmp);
    m_form2->addRow(tr("Return Key"),m_oneKeyStartReturn);
    m_form2->addRow(tr("Retrun Key"),m_oneKeyPauseReturn);
    m_form2->addRow(tr("Return Key"),m_oneKeyStopReturn);
    m_form2->addRow(tr("Return Key"),m_shutdownReturn);
    m_form2->addRow(tr("Return Key"),m_lockVGAReturn);




    m_con->addLayout(m_form1);
    m_con->addLayout(m_form2);
    this->setLayout(m_con);

}

QString QCtrlSetting::getOneKeyStartCode()const
{
    return m_oneKeyStart->text();
}
void QCtrlSetting::setOneKeyStartCode(const QString& code)
{
    m_oneKeyStart->setText(code.toUpper());
}

QString QCtrlSetting::getOneKeyStartReturnCode()const
{
    return m_oneKeyStartReturn->text();
}
void QCtrlSetting::setOneKeyStartReturnCode(const QString& code)
{
    m_oneKeyStartReturn->setText(code.toUpper());
}

QString QCtrlSetting::getOneKeyPauseCode()const
{
    return m_oneKeyPause->text();
}
void QCtrlSetting::setOneKeyPauseCode(const QString& code)
{
    m_oneKeyPause->setText(code.toUpper());
}

QString QCtrlSetting::getOneKeyPauseReturnCode()const
{
    return m_oneKeyPauseReturn->text();
}
void QCtrlSetting::setOneKeyPauseReturnCode(const QString& code)
{
    m_oneKeyPauseReturn->setText(code.toUpper());
}

QString QCtrlSetting::getOneKeyStopCode()const
{
    return m_oneKeyStop->text();
}
void QCtrlSetting::setOneKeyStopCode(const QString& code)
{
    m_oneKeyStop->setText(code.toUpper());
}

QString QCtrlSetting::getOneKeyStopReturnCode()const
{
    return m_oneKeyStopReturn->text();
}
void QCtrlSetting::setOneKeyStopReturnCode(const QString& code)
{
    m_oneKeyStopReturn->setText(code.toUpper());
}

QString QCtrlSetting::getPowerOffCode()const
{
    return m_shutdown->text();
}
void QCtrlSetting::setPowerOffCode(const QString& code)
{
    m_shutdown->setText(code.toUpper());
}

QString QCtrlSetting::getPowerOffReturnCode()const
{
    return m_shutdownReturn->text();
}
void QCtrlSetting::setPowerOffReturnCode(const QString& code)
{
    m_shutdownReturn->setText(code.toUpper());
}

QString QCtrlSetting::getLockVGACode()const
{
    return m_lockVGA->text();
}
void QCtrlSetting::setLockVGACode(const QString& code)
{
    m_lockVGA->setText(code.toUpper());
}

QString QCtrlSetting::getLockVGAReturnCode()const
{
    return m_lockVGAReturn->text();
}
void QCtrlSetting::setLockVGAReturnCode(const QString& code)
{
    m_lockVGAReturn->setText(code.toUpper());
}



QCtrlSetting::~QCtrlSetting()
{
    delete m_oneKeyPause;
    delete m_oneKeyPauseReturn;
    delete m_oneKeyStart;
    delete m_oneKeyStartReturn;
    delete m_oneKeyStop;
    delete m_oneKeyPause;
    delete m_shutdown;
    delete m_shutdownReturn;
    delete m_lockVGA;
    delete m_lockVGAReturn;

    delete m_form1;
    delete m_form2;
    delete m_con;

}

// 系统信息

QSystemInfo::QSystemInfo(QWidget* parent):QWidget(parent)
{
    m_verInfo = new QGroupBox(tr("Version Info"));
    m_dateSettingB = new QGroupBox(tr("Time Setting"));

    m_hardwardId = new QLabel("0");
    m_softVersion = new QLabel("1.0.0");
    m_romVersion = new QLabel("Ubuntu 14.04");
    m_releaseVersion = new QLabel("1.0.0");


    m_language = new QComboBox();
    m_language->addItem(tr("Chinese"));
    m_language->addItem(tr("English"));
    m_dateFormat = new QComboBox();
    m_dateFormat->addItem(tr("yyyy-MM-dd"));
    m_dateFormat->addItem(tr("yyyy/MM/dd"));
    m_dateFormat->addItem(tr("yyyy MM dd"));
    m_dateFormat->addItem(tr("MM-dd-yyyy"));
    connect(m_dateFormat,SIGNAL(currentIndexChanged(int)),this,SLOT(switchDateFormat(int)));

    QDate dt =QDate::currentDate();
    QTime tm =QTime::currentTime();
    m_dateSetting = new QDateEdit(dt);
    m_dateSetting->setDisplayFormat(m_dateFormat->currentText());
    m_timeSetting = new QTimeEdit(tm);
    m_hostName = new QLineEdit();
    m_aysn = new QLineEdit();

    m_networkTimeAysn = new QCheckBox(tr("Network Aysn"));

    m_recoveryBtn = new QPushButton(tr("Recovery"));
    m_upgradeBtn = new QPushButton(tr("Upgrade"));
    m_shutdownBtn = new QPushButton(tr("Shutdown"));
    m_restartBtn = new QPushButton(tr("Restart"));
    m_testScreenBtn = new QPushButton(tr("Test Screen"));
    m_ProSettingBtn = new QPushButton(tr("Project"));
    m_importConfigBtn = new QPushButton(tr("Import"));
    m_exportConfigBtn = new QPushButton(tr("export"));

    m_supVersion = new QFormLayout();
    m_supDate = new QFormLayout();

    m_verLay = new QVBoxLayout();
    m_funLay = new QVBoxLayout();
    m_supDown = new QFormLayout();
    m_con = new QHBoxLayout();
    m_con->setSpacing(20);
    m_con->setMargin(10);


    // layout
    m_supVersion->setSpacing(25);
    m_supDown->setSpacing(25);
    m_supDown->addRow(tr("Language"),m_language);
    m_supDown->addRow(tr("Host Name"),m_hostName);
    m_supVersion->addRow(tr("Hardware ID"),m_hardwardId);
    m_supVersion->addRow(tr("Software Version"),m_softVersion);
    m_supVersion->addRow(tr("ROM Version"),m_romVersion);
    m_supVersion->addRow(tr("Release Version"),m_releaseVersion);
    m_verInfo->setLayout(m_supVersion);

    m_supDate->setSpacing(30);
    m_supDate->addWidget(m_networkTimeAysn);
    m_supDate->addRow(tr("Date Format"),m_dateFormat);
    m_supDate->addRow(tr("Date"),m_dateSetting);
    m_supDate->addRow(tr("Time"),m_timeSetting);
    m_supDate->addRow(tr("Net-Server"),m_aysn);
    m_dateSettingB->setLayout(m_supDate);

    m_funLay->addWidget(m_recoveryBtn);
    m_funLay->addWidget(m_upgradeBtn);
    m_funLay->addWidget(m_shutdownBtn);
    m_funLay->addWidget(m_restartBtn);
    m_funLay->addWidget(m_testScreenBtn);
    m_funLay->addWidget(m_ProSettingBtn);
    m_funLay->addWidget(m_importConfigBtn);
    m_funLay->addWidget(m_exportConfigBtn);

    m_verLay->addWidget(m_verInfo);
    m_verLay->addLayout(m_supDown);
    m_con->addLayout(m_verLay,4);
    m_con->addWidget(m_dateSettingB,4);
    m_con->addLayout(m_funLay,3);

    this->setLayout(m_con);


    //event

    connect(m_language,SIGNAL(currentIndexChanged(int)),this,SLOT(switchLanguage(int)));
    connect(m_recoveryBtn,SIGNAL(clicked()),this,SLOT(recovery()));
    connect(m_upgradeBtn,SIGNAL(clicked()),this,SLOT(upgrade()));
    connect(m_shutdownBtn,SIGNAL(clicked()),this,SLOT(shutdown()));
    connect(m_restartBtn,SIGNAL(clicked()),this,SLOT(restart()));
    connect(m_testScreenBtn,SIGNAL(clicked()),this,SLOT(testScreen()));
    connect(m_ProSettingBtn,SIGNAL(clicked()),this,SLOT(proSetting()));
    connect(m_importConfigBtn,SIGNAL(clicked()),this,SLOT(importCFG()));
    connect(m_exportConfigBtn,SIGNAL(clicked()),this,SLOT(exportCFG()));


}
void QSystemInfo::switchLanguage(int index)
{
     Singleton<QTranslator> *rt =Singleton<QTranslator>::getInstance();
  if(index==0)
  {
      qApp->removeTranslator(&rt->m_data);
      rt->m_data.load(QString(":/cfg/director_zh"));
      qApp->installTranslator(&rt->m_data);

  }
  else
  {

//    qApp->removeTranslator(&rt->m_data);
//    rt->m_data.load(QString(":/cfg/director_en"));
//    qApp->installTranslator(&rt->m_data);

//    QString program = QApplication::applicationFilePath();
//    QStringList arguments = QApplication::arguments();
//    QString workingDirectory = QDir::currentPath();
//    QApplication::exit();
//    QProcess::startDetached(program, arguments, workingDirectory);
  }

}

void QSystemInfo::switchDateFormat(int index)
{
     m_dateSetting->setDisplayFormat(m_dateFormat->currentText());
}


QSystemInfo::~QSystemInfo()
{

}

void QSystemInfo::recovery()
{
    TipDialog tip(TipDialog::OK|TipDialog::Cannel);
    tip.setTipTitle(tr("waring"));
    tip.setTipInfoText(tr("Are you sure restore the factory settings, restore the factory settings your personal configuration will be deleted"));
    if(TipDialog::OK==tip.showDialog())
    {

    }
   // QMessageBox::warning(0,"","TODO",0,0);
}

void QSystemInfo::upgrade()
{
    QMessageBox::warning(0,"","TODO",0,0);
}

void QSystemInfo::shutdown()
{
    QMessageBox::warning(0,"","TODO",0,0);
}

void QSystemInfo::restart()
{
    QMessageBox::warning(0,"","TODO",0,0);
}
void QSystemInfo::testScreen()
{
    QMessageBox::warning(0,"","TODO",0,0);
}
void QSystemInfo::proSetting()
{
    QMessageBox::warning(0,"","TODO",0,0);
}

void QSystemInfo::importCFG()
{
    QMessageBox::warning(0,"","TODO",0,0);
}
void QSystemInfo::exportCFG()
{
    QMessageBox::warning(0,"","TODO",0,0);
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

    //this->setWindowFlags(Qt::WindowStaysOnTopHint);
    AddPage(userMgrWidget,tr("User"));
    AddPage(serialPortWidget,tr("Serial"));
    AddPage(diskMgrWidget,tr("Disk"));
    AddPage(netConfigWidget,tr("NetWork-C"));
    AddPage(netTestWidget,tr("Network-T"));
    AddPage(grapCardWidget,tr("GraphicsCard"));
    AddPage(ctrlSetting,tr("CenterCtrl"));
    AddPage(systemInfoWidget,tr("Information"));
    SetTitle(tr("system setting"));

    InitConfig();

}

QSystemSettingWidget::~QSystemSettingWidget()
{

}

void QSystemSettingWidget::clicked_OK()
{
    if(CurrentWidget() == netTestWidget)
    {
      ;
    }

    close();

}
void QSystemSettingWidget::clicked_Apply()
{

}
void QSystemSettingWidget::clicked_Cannel()
{
  close();
}


void QSystemSettingWidget::InitConfig()
{
    // 初始化配置文件
    // TODO
    configFileName ="F:\\C++\\Dev\\Qt\\Directorplatform\\config.conf";

    ConfigFile cfg(configFileName);

    // net-config
    netConfigWidget->setMainIP(cfg.getValue("MainIP","NetworkConfig"));
    netConfigWidget->setMainGate(cfg.getValue("MainGate","NetworkConfig"));
    netConfigWidget->setMainDNS(cfg.getValue("MainDNS","networkConfig"));
    netConfigWidget->setMainMask(cfg.getValue("MainMask","NetworkConfig"));

    netConfigWidget->setSubIP(cfg.getValue("SubIP","NetworkConfig"));
    netConfigWidget->setSubGate(cfg.getValue("subGate","NetworkConfig"));
    netConfigWidget->setSubDNS(cfg.getValue("subDNS","networkConfig"));
    netConfigWidget->setSubMask(cfg.getValue("subMask","NetworkConfig"));


    // c-setting

    ctrlSetting->setOneKeyStartCode(cfg.getValue("OneKeyStartCode","CenterSetting"));
    ctrlSetting->setOneKeyStartReturnCode(cfg.getValue("OneKeyStartReturnCode","CenterSetting"));
    ctrlSetting->setOneKeyPauseCode(cfg.getValue("OneKeyPauseCode","CenterSetting"));
    ctrlSetting->setOneKeyPauseReturnCode(cfg.getValue("OneKeyPauseReturnCode","CenterSetting"));
    ctrlSetting->setOneKeyStopCode(cfg.getValue("OneKeyStopCode","CenterSetting"));
    ctrlSetting->setOneKeyStopReturnCode(cfg.getValue("OneKeyStopReturnCode","CenterSetting"));
    ctrlSetting->setPowerOffCode(cfg.getValue("PowerOffCode","CenterSetting"));
    ctrlSetting->setPowerOffReturnCode(cfg.getValue("PowerOffReturnCode","CenterSetting"));
    ctrlSetting->setLockVGACode(cfg.getValue("LockVGACode","CenterSetting"));
    ctrlSetting->setLockVGAReturnCode(cfg.getValue("LockVGAReturnCode","CenterSetting"));



}
