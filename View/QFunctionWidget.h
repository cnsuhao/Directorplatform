#ifndef QFUNCTIONWIDGET_H
#define QFUNCTIONWIDGET_H

/****************************************************************
 *             下方视频功能区
 ****************************************************************
 *
 *    QEffectFun           :  特效功能
 *                            1,画面分割
 *                            2,切换特效
 *
 *    QVideoFun            :  视频功能
 *                            1,字幕制作
 *                            2,声音控制
 *
 *    QLuboFun             :  录播功能
 *                            1,角标切换
 *                            2,OSD信息
 *                            3,时间
 *                            4,附加OSD
 *
 *
 *   QStateFun             :  状态功能
 *
 *****************************************************************/

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QVector>
#include <QButtonGroup>

/************************SUBPAGE*********************************/

/**
 * @brief The QBaseFun class
 *
 * base class of per function class
 */
class QBaseFun : public QWidget
{
    Q_OBJECT
public:
    explicit QBaseFun(QWidget *parent = 0);
    ~QBaseFun();

signals:

public slots:
protected:
    void paintEvent(QPaintEvent* event);
    virtual void AddPage(QWidget* widget,const QString &title);
protected:
    QVBoxLayout*       m_con;
    QTabWidget*      m_tab;

};

/**
 * @brief The QEffect class
 *
 * 特效功能区
 */


class ShowSplitWidget : public QWidget //画面分割UI
{
    Q_OBJECT
public:
    explicit ShowSplitWidget(QWidget *parent = 0);
    ~ShowSplitWidget();

signals:

public slots:
protected:
    void paintEvent(QPaintEvent* event);
protected:

};

class EffectSwitch : public QWidget //特效切换UI
{
    Q_OBJECT
public:
    explicit EffectSwitch(QWidget *parent = 0);
    ~EffectSwitch();

signals:

public slots:
protected:
    void paintEvent(QPaintEvent* event);
protected:
    QGridLayout     *m_con;
    QVector<QPushButton*> m_effect;
    QButtonGroup    *m_group;


};




class QEffectFun : public QBaseFun
{
    Q_OBJECT
public:
    explicit QEffectFun(QBaseFun *parent = 0);
    ~QEffectFun();
signals:

public slots:
protected:
    EffectSwitch    *effectWidget;
    ShowSplitWidget *splitWidget;

private:


};
/**
 * @brief The QVideoFun class
 *
 * 视频功能区
 */


class SubTitleWidget : public QWidget //字幕控制UI
{
    Q_OBJECT
public:
    explicit SubTitleWidget(QWidget *parent = 0);
    ~SubTitleWidget();

signals:

public slots:
protected:
    void paintEvent(QPaintEvent* event);
protected:

};

class VoiceWidget : public QWidget //声音控制UI
{
    Q_OBJECT
public:
    explicit VoiceWidget(QWidget *parent = 0);
    ~VoiceWidget();

signals:

public slots:
protected:
    void paintEvent(QPaintEvent* event);
protected:

};



class QVideoFun : public QBaseFun
{
    Q_OBJECT
public:
    explicit QVideoFun(QBaseFun *parent = 0);
    ~QVideoFun();
signals:

public slots:
protected:
    SubTitleWidget*      m_subtitle;
    VoiceWidget*         m_voice;

};
/**
 * @brief The QLuboFun class
 *
 * 录播功能区
 */
class QLuboFun : public QBaseFun
{
    Q_OBJECT
public:
    explicit QLuboFun(QBaseFun *parent = 0);
    ~QLuboFun();
signals:

public slots:
protected:

};
/**
 * @brief The QStateFun class
 *
 * 状态功能区
 */

class StateWidget : public QWidget //特效切换UI
{
    Q_OBJECT
public:
    explicit StateWidget(QWidget *parent = 0);
    ~StateWidget();

signals:

public slots:
protected:
    void paintEvent(QPaintEvent* event);
protected:
    QGridLayout     *m_con;
    QVector<QPushButton*> m_state;
};


class QStateFun : public QBaseFun
{
    Q_OBJECT
public:
    explicit QStateFun(QBaseFun *parent = 0);
    ~QStateFun();
signals:

public slots:
protected:
    StateWidget*     m_state;

};

/*************************************************************/

class QFunctionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QFunctionWidget(QWidget *parent = 0);

signals:

public slots:
protected:
    void paintEvent(QPaintEvent* event);
private:
    QHBoxLayout *m_con;
protected:
    QEffectFun  *m_effectFunWidget;
    QVideoFun   *m_videoFunWidget;
    QLuboFun    *m_luboFunWidget;
    QStateFun   *m_stateFunWidget;

};

#endif // QFUNCTIONWIDGET_H
