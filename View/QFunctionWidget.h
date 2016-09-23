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

};

/**
 * @brief The QEffect class
 *
 * 特效功能区
 */
class QEffectFun : public QBaseFun
{
    Q_OBJECT
public:
    explicit QEffectFun(QBaseFun *parent = 0);
    ~QEffectFun();
signals:

public slots:
protected:

};
/**
 * @brief The QVideoFun class
 *
 * 视频功能区
 */
class QVideoFun : public QBaseFun
{
    Q_OBJECT
public:
    explicit QVideoFun(QBaseFun *parent = 0);
    ~QVideoFun();
signals:

public slots:
protected:

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
class QStateFun : public QBaseFun
{
    Q_OBJECT
public:
    explicit QStateFun(QBaseFun *parent = 0);
    ~QStateFun();
signals:

public slots:
protected:

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

};

#endif // QFUNCTIONWIDGET_H
