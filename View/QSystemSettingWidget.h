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

/********************************************
 * QSystemSettingWidget class
 ********************************************
 *
 *  use to make system setting page
 *
 *******************************************/



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
    QTableView*                m_tableview;
private:
    QVBoxLayout*               m_con;
    QHeaderView*               m_head;



};


/**
 * @brief The QNetConfig class
 *
 *  网络配置
 */
class QNetConfig : public QWidget
{
    Q_OBJECT
public:
    explicit QNetConfig(QWidget *parent = 0);
    ~QNetConfig();
signals:

public slots:
     void mainCheckChange(int );
     void subCheckChange(int);
     void ReturnKey();

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

};

/**
 * @brief The QNetTest class
 *
 * 网络测试
 */
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

public:
    QLineEdit*          m_commandLine;
    QPlainTextEdit*     m_commandInfo;
private:
    QVBoxLayout*        m_con;
    QProcess*           m_proc;

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
public:

protected:
    QGroupBox               *m_verInfo,*m_dateSettingB;
    QLabel                  *m_hardwardId,*m_softVersion,*m_romVersion,*m_releaseVersion;
    QComboBox               *m_language,*m_dateFormat;
    QLineEdit               *m_dateSetting,*m_timeSetting,*m_hostName,*m_aysn;
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

};

#endif // QSYSTEMSETINGWIDGET_H
