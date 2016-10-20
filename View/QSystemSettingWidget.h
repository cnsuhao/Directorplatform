#ifndef QSYSTEMSETTINGWIDGET_H
#define QSYSTEMSETTINGWIDGET_H

#include <QWidget>
#include <QTabWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QFormLayout>
#include <QValidator>
#include <QRegExpValidator>
#include <QPlainTextEdit>
#include <QProcess>
#include <QTextDocument>
#include <QTableView>
#include <QComboBox>
#include <QTranslator>
#include <QApplication>
#include <QDateEdit>
#include <QTimeEdit>
#include <QTableWidget>
#include <QShortcut>
#include <QPainter>
#include <QMessageBox>

/********************************************
 * QSystemSettingWidget class
 ********************************************
 *
 *  use to make system setting page
 *
 *******************************************/

// designed for ok cannel apply

#define     SYS_SETTING_OK         "QPushButton{border-radius:3px;background:rgb(55,55,55);} QPushButton:hover{border-radius:3px;background:rgb(55,55,55,150);}"
#define     SYS_SETTING_APPLY      SYS_SETTING_OK
#define     SYS_SETTING_CANNEL     SYS_SETTING_OK









class QSettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QSettingWidget(QWidget *parent = 0);
    ~QSettingWidget();
signals:

protected:
    QLabel*                         m_labTitle;
    QTabWidget*                     m_mainTab;
    QHBoxLayout*                    m_titleLay;
    QHBoxLayout*                    m_dlgLay;
    QVBoxLayout*                    m_con;

    QPushButton*                    m_okBtn;
    QPushButton*                    m_applyBtn;
    QPushButton*                    m_cannelBtn;
private:
    QLabel*             emptyLab;
    bool canMove;
    QPoint oldPoint;
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
public:
    virtual void SetTitle(const QString &title);
    virtual void AddPage(QWidget* widget,const QString &tabTitle);
    virtual void AddPage(QWidget *widget, const QString &tabTitle,const QIcon &icon);
    virtual int PageCount()const;
    virtual int CurrentIndex()const;
    virtual QWidget* CurrentWidget()const;
    virtual void SetPageIcon(int index,const QIcon &icon);
    virtual void SetPageTitle(int index,const QString &title);
    virtual void SetPageToolTip(int index,const QString &tip);


public slots:
    virtual void clicked_OK();
    virtual void clicked_Apply();
    virtual void clicked_Cannel();

protected:
    virtual void paintEvent(QPaintEvent* event);
};


class IDrawBackground : protected QWidget
{
public:
     virtual void paintEvent(QPaintEvent *event)
     {
         QPainter p(this);
         p.fillRect(rect(),QColor(48,48,48));
     }
};


/**********************************SUB_PAGE******************************/

/**
 * @brief The QUserMgr class
 *
 * 用户管理
 */

class QUserMgr : public QWidget
{
    Q_OBJECT
public:
    explicit QUserMgr(QWidget *parent = 0);
    ~QUserMgr();
signals:

public slots:

};

/**
 * @brief The QSerialPort class
 *
 * 串口设置
 */

class QSerialPort : public QWidget
{
    Q_OBJECT
public:
    explicit QSerialPort(QWidget *parent = 0);
    ~QSerialPort();
signals:

public slots:
};


/**
 * @brief The QDiskMgr class
 *
 * 磁盘管理
 */
class QDiskMgr : public QWidget
{
    Q_OBJECT
public:
    explicit QDiskMgr(QWidget *parent = 0);
    ~QDiskMgr();
signals:

public slots:
protected:
    QTableWidget*                m_tableview;
    QStringList                  m_headList;
    QComboBox                    *m_fullAction,*m_fileSystem,*m_diskProtocol;
    QCheckBox                    *m_forceMoveDiskRecord,*m_newDiskRecord,*m_newMoveDiskRecord,*m_newNetDiskRecord;
    QPushButton                  *m_uponNetDriver,*m_Share;

private:
    QVBoxLayout*                 m_con;
    QHBoxLayout                 *m_lay_1,*m_lay_2,*m_lay_3;

    QLabel  L1,L2,L3;


};


/**
 * @brief The QNetConfig class
 *
 *  网络配置
 */
class QNetConfig : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QString mainIP READ getMainIP WRITE setMainIP)
    Q_PROPERTY(QString subIP READ getSubIP WRITE setSubIP )
    Q_PROPERTY(QString mainMask READ getMainMask WRITE setMainMask )
    Q_PROPERTY(QString subMask READ getSubMask WRITE setSubMask )
    Q_PROPERTY(QString mainGate READ getMainGate WRITE setMainGate )
    Q_PROPERTY(QString subGate READ getSubGate WRITE setSubGate )
    Q_PROPERTY(QString mainDNS READ getMainDNS WRITE setMainDNS )
    Q_PROPERTY(QString subDNS READ getSubDNS WRITE setSubDNS)
    Q_PROPERTY(QString mainMAC READ getMainMAC WRITE setMainMAC )
    Q_PROPERTY(QString subMAC READ getSubMAC WRITE setSubMAC )

public:
    explicit QNetConfig(QWidget *parent = 0);
    ~QNetConfig();
signals:

public slots:
     void mainCheckChange(int );
     void subCheckChange(int);
     void ReturnKey();

     void mainIPChange(QString ipTxt);

public:
    QCheckBox         *m_mainDHCP,*m_subDHCP;
    QLineEdit         *m_mainIP,*m_subIP,*m_mainMask,*m_sub_Mask,*m_mainGateway,*m_subGateway,*m_mainDNS,*m_subDNS,
                      *m_mainMAC,*m_subMAC;
    QFormLayout       *m_mainLayout,*m_sublayout;

private:
    QHBoxLayout*      m_layout;
    QGroupBox*        m_netMain;
    QGroupBox*        m_netSub;

private:

     void setMainEnabled(bool);
     void setSubEnabled(bool);


public:

     // property:
     QString getMainIP()const;
     void setMainIP(const QString &str);

     QString getSubIP() const;
     void setSubIP(const QString &str);

     QString getMainMask() const;
     void setMainMask(const QString &str);

     QString getSubMask() const;
     void setSubMask(const QString &str);

     QString getMainGate() const;
     void setMainGate(const QString &str);

     QString getSubGate() const;
     void setSubGate(const QString &str);

     QString getMainDNS() const;
     void setMainDNS(const QString &str);

     QString getSubDNS() const;
     void setSubDNS(const QString &str);

     QString getMainMAC() const;
     void setMainMAC(const QString &str);

     QString getSubMAC() const;
     void setSubMAC(const QString &str);

};

/**
 * @brief The QNetTest class
 *
 * 网络测试
 */


class PlainTextYoo :public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit PlainTextYoo()
    {

    }
    void keyPressEvent(QKeyEvent *e)
    {
        if((e->modifiers()==Qt::ControlModifier)&&(e->key()==Qt::Key_C))
        {
           // QMessageBox::information(0,"","Ctrl-C",0,0);
            emit Ctrl_C();
        }
        else return QPlainTextEdit::keyPressEvent(e);
    }
 signals:
    void Ctrl_C();
};


class QNetTest : public QWidget
{
    Q_OBJECT
public:
    explicit QNetTest(QWidget *parent = 0);
    ~QNetTest();
signals:

public slots:
    void returnKey();
    void showStdOutInfo();

    void exit_proc();

public:
    QLineEdit*          m_commandLine;
    PlainTextYoo*       m_commandInfo;
private:
    QVBoxLayout*        m_con;
    QHBoxLayout*        m_lay;
    QProcess*           m_proc;
    QPushButton*        m_executeBtn;

};

/**
 * @brief The QGrapCard class
 *
 * 显卡设置
 */
class QGrapCard : public QWidget
{
    Q_OBJECT
public:
    explicit QGrapCard(QWidget *parent = 0);
    ~QGrapCard();
signals:

public slots:
protected:
    QGroupBox             *m_grapCard_1,*m_grapCard_2;
    QSlider               *m_light_1,*m_light_2,*m_balance_1,*m_balance_2,
                          *m_shade_1,*m_shade_2,*m_fill_1,*m_fill_2;
    QComboBox             *m_resolution_1,*m_resolution_2,*m_freq_1,*m_freq_2,
                          *m_outputDevice;
    QCheckBox             *m_audio;

private:
    QHBoxLayout           *m_con;
    QFormLayout           *m_form_1,*m_form_2;

public:
    void setMianLight(int value);
    int getMainLight()const;

    void setMainBalance(int value);
    int getMainBalance()const;

    void setMainShade(int value);
    int getMainShade()const;

    void setMainFill(int value);
    int getMainFill()const;

    void setSubLight(int value);
    int getSubLight()const;

    void setSubBalance(int value);
    int getSubBalance()const;

    void setSubShade(int value);
    int getSubShade()const;

    void setSubFill(int value);
    int getSubFill()const;

};

/**
 * @brief The QCtrlSetting class
 *
 * 中控设置
 */
class QCtrlSetting : public QWidget
{
    Q_OBJECT
public:
    explicit QCtrlSetting(QWidget *parent = 0);
    ~QCtrlSetting();
signals:

public slots:
private:
    QHBoxLayout         *m_con;
    QFormLayout         *m_form1,*m_form2;
protected:
    QLineEdit           *m_oneKeyStart,*m_oneKeyStartReturn,*m_oneKeyPause,*m_oneKeyPauseReturn,
                        *m_oneKeyStop,*m_oneKeyStopReturn,*m_shutdown,*m_shutdownReturn,*m_lockVGA,*m_lockVGAReturn;
    QComboBox           *m_serialPort;
    QLabel tmp;

};

/**
 * @brief The QSysInfo class
 *
 * 系统信息
 */
class QSystemInfo : public QWidget
{
    Q_OBJECT
public:
    explicit QSystemInfo(QWidget *parent = 0);
    ~QSystemInfo();
signals:

public slots:
    void switchLanguage(int);
    void switchDateFormat(int);
    //恢复
    void recovery();
    //升级
    void upgrade();
    //关机
    void shutdown();
    //重启
    void restart();
    //显示屏测试
    void testScreen();
    //工程设置
    void proSetting();
    //导入配置
    void importCFG();
    //导出配置
    void exportCFG();
public:

protected:
    QGroupBox               *m_verInfo,*m_dateSettingB;
    QLabel                  *m_hardwardId,*m_softVersion,*m_romVersion,*m_releaseVersion;
    QComboBox               *m_language,*m_dateFormat;
    QLineEdit               *m_hostName,*m_aysn;
    QDateEdit               *m_dateSetting;
    QTimeEdit               *m_timeSetting;
    QCheckBox               *m_networkTimeAysn;
    QPushButton             *m_recoveryBtn,*m_upgradeBtn,*m_shutdownBtn,*m_restartBtn,
                            *m_testScreenBtn,*m_ProSettingBtn,*m_importConfigBtn,*m_exportConfigBtn;
private:
    QHBoxLayout             *m_con;
    QVBoxLayout             *m_verLay,*m_funLay;
    QFormLayout             *m_supVersion,*m_supDown,*m_supDate;

};




/**********************************END********************************************/


class QSystemSettingWidget : public QSettingWidget
{
    Q_OBJECT
public:
    explicit QSystemSettingWidget(QWidget *parent = 0);
    ~QSystemSettingWidget();

signals:

private:

    QUserMgr*       userMgrWidget;
    QSerialPort*    serialPortWidget;
    QDiskMgr*       diskMgrWidget;
    QNetConfig*     netConfigWidget;
    QNetTest*       netTestWidget;
    QGrapCard*      grapCardWidget;
    QCtrlSetting*   ctrlSetting;
    QSystemInfo*    systemInfoWidget;

public slots:
protected:
    void clicked_OK();
    void clicked_Apply();
    void clicked_Cannel();

private:
    QString configFileName;
    void InitConfig();

};

#endif // QSYSTEMSETINGWIDGET_H
