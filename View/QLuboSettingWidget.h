#ifndef QLUBOSETTINGWIDGET_H
#define QLUBOSETTINGWIDGET_H

#include "QSystemSettingWidget.h"
#include <QSpinBox>


/**********************SUBPAGE******************************/
/**
 * @brief The OneKeySetting class
 *
 * 一键开始设置
 */
class OneKeySetting :public QWidget
{
    Q_OBJECT
public:
    explicit OneKeySetting(QWidget *parent = 0);
    ~OneKeySetting();

signals:
public slots:
    void selectdMode1(int state);
    void selectedMode2(int state);
    void selectedStream1(int state);
    void selectedStream2(int state);
    void selecteddirector(int state);
    void selectedResRecord(int state);
protected:
    QCheckBox              *m_movieMode,*m_movieMode2,*m_stream,*m_stream2,*m_director,*m_resRecord;
private:
    QGroupBox              *m_group;
    QGridLayout            *m_lay;
    QHBoxLayout            *m_con;

};

/**
 * @brief The CodingSetting class
 *
 *
 * 编码设置
 */
class CodingSetting :public QWidget
{
    Q_OBJECT
public:
    explicit CodingSetting(QWidget *parent = 0);
    ~CodingSetting();

signals:

private:

public slots:
protected:
    QComboBox             *m_mainResolution1,*m_mainResolution2,*m_subResolution1,*m_subResolution2,
                          *m_mainCoding1,*m_mainCoding2,*m_subCoding1,*m_subCoding2;
    QSpinBox              *m_mainFrameRate1,*m_mainFrameRate2,*m_subFrameRate1,*m_subFrameRate2,
                          *m_mainCodeRate1,*m_mainCodeRate2,*m_subCodeRate1,*m_subCodeRate2,
                          *m_mainFrameSpacing1,*m_mainFrameSpacing2;
private:
    QHBoxLayout           *m_con;
    QGroupBox             *m_movieMode1,*m_movieMode2,*m_maincode1,*m_maincode2,*m_subcode1,*m_subcode2;
    QFormLayout           *m_form1,*m_form2,*m_form3,*m_form4;
    QVBoxLayout           *m_lay1,*m_lay2;

};
/**
 * @brief The AudioSetting class
 *
 *
 * 音频设置
 */
class AudioSetting :public QWidget
{
    Q_OBJECT
public:
    explicit AudioSetting(QWidget *parent = 0);
    ~AudioSetting();

signals:

private:

public slots:
protected:
    QComboBox             *m_channel;
    QComboBox             *m_frequency;
    QComboBox             *m_bit;
    QSpinBox              *m_rate;
private:
    QFormLayout           *m_con;
};

/**
 * @brief The RecordSetting class
 *
 * 录制设置
 */
class RecordSetting :public QWidget
{
    Q_OBJECT
public:
    explicit RecordSetting(QWidget *parent = 0);
    ~RecordSetting();

signals:

private:

public slots:


};

/**
 * @brief The TimerRecordSetting class
 *
 * 定时录制设置
 */
class TimerRecordSetting :public QWidget
{
    Q_OBJECT
public:
    explicit TimerRecordSetting(QWidget *parent = 0);
    ~TimerRecordSetting();

signals:

private:

public slots:
protected:
};

/**
 * @brief The RTMPSetting class
 *
 * RTMP 推流
 */
class RTMPSetting :public QWidget
{
    Q_OBJECT
public:
    explicit RTMPSetting(QWidget *parent = 0);
    ~RTMPSetting();

signals:

private:

public slots:
protected:
};

/**
 * @brief The TSSetting class
 *
 * TS 推流
 */
class TSSetting :public QWidget
{
    Q_OBJECT
public:
    explicit TSSetting(QWidget *parent = 0);
    ~TSSetting();

signals:

private:

public slots:
protected:
};

/**
 * @brief The AutoTrackSetting class
 *
 * 自动跟踪设置
 */
class AutoTrackSetting :public QWidget
{
    Q_OBJECT
public:
    explicit AutoTrackSetting(QWidget *parent = 0);
    ~AutoTrackSetting();

signals:

private:

public slots:
protected:
};

/**
 * @brief The SwitchPolicy class
 *
 * 切换策略
 */
class SwitchPolicy :public QWidget
{
    Q_OBJECT
public:
    explicit SwitchPolicy(QWidget *parent = 0);
    ~SwitchPolicy();

signals:

private:

public slots:
protected:
};
/**
 * @brief The FollowMachineSetting class
 *
 * 跟随主机设置
 */
class FollowMachineSetting :public QWidget
{
    Q_OBJECT
public:
    explicit FollowMachineSetting(QWidget *parent = 0);
    ~FollowMachineSetting();

signals:

private:

public slots:
protected:
    QLineEdit           *m_IP,*m_port;
private:
    QFormLayout          *m_con;
};

/*********************************************************/



class QLuboSettingWidget :public QSettingWidget
{
    Q_OBJECT
public:
    explicit QLuboSettingWidget(QSettingWidget *parent = 0);
    ~QLuboSettingWidget();

signals:

private:

public slots:
protected:
    //void clicked_OK();
    //void clicked_Apply();
   //void clicked_Cannel();
protected:
    OneKeySetting          *m_onekeyWidget;
    CodingSetting          *m_codingWidget;
    AudioSetting           *m_audioWidget;
    RecordSetting          *m_recordWidget;
    TimerRecordSetting     *m_timerRecordWidget;
    RTMPSetting            *m_rtmpWidget;
    TSSetting              *m_tsWidget;
    AutoTrackSetting       *m_autoWidget;
    SwitchPolicy           *m_switchWidget;
    FollowMachineSetting   *m_followWidget;


private:


};

#endif // QLUBOSETTINGWIDGET_H
