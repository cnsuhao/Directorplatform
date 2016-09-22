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
public:
    QCheckBox         *m_mainDHCP,*m_subDHCP;
    QLabel            *m_mainlabIP,*m_sublabIP,*m_mainlabMask,*m_sublabMask,*m_mainlabDNS,*m_sublanDNS,
                      *m_mainlabMAC,*m_sublabMac;
    QLineEdit         *m_mainIP,*m_subIP,*m_mainMask,*m_sub_Mask,*m_mainDNS,*m_subDNS,
                      *m_mainMAC,*m_subMAC;
    QFormLayout       *m_mainLayout,*m_sublayout;

private:
    QHBoxLayout*      m_layout;
    QGroupBox*        m_netMain;
    QGroupBox*        m_netSub;



};

/**
 * @brief The QNetTest class
 *
 * 网络测试 ping
 */
class QNetTest : public QWidget
{
    Q_OBJECT
public:
    explicit QNetTest(QWidget *parent = 0);
    ~QNetTest();
signals:

public slots:

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

};

#endif // QSYSTEMSETINGWIDGET_H
