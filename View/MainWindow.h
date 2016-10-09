#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "View/PlatformConfig.h"
#include "View/QDirWidget.h"
#include "View/QLiveWidget.h"
#include "View/QCtrlWindow.h"
#include "View/QFunctionWidget.h"
#include "QSystemSettingWidget.h"
#include "QLuboSettingWidget.h"
#include  <QVector>
#include <QList>


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    /*两侧导播视频控件*/
    QDirWidget *leftVideo;
    QDirWidget *rightVideo;

    QCtrlWindow *ctrlwin;
    QFunctionWidget *funwin;
    QVector<QLiveWidget*> liveVideo_vec;


private:

    QList<QVideoWidget*> m_selDir;
    QList<QVideoWidget*> m_selLive;
    const int NumberOfLive;
    /*全局栅格布局*/
    QGridLayout *gridLayout;
    /*主展示区布局*/
    QVBoxLayout *mainLayout;
    /*右侧操作栏布局*/
    QVBoxLayout *operatorLayout;
    /*下方工具栏布局*/
    QHBoxLayout *toolLayout;

    /**/
    QHBoxLayout *dirvideoLayout;
    QHBoxLayout *livevideoLayout;
    QHBoxLayout *functionLayout;

private:
    QPushButton *m_insertHead;
    QPushButton *m_insertTail;
    QPushButton *m_oneDirector;
    QPushButton *m_twoDirector;

    QPushButton *m_auto;
    QPushButton *m_semiAuto;
    QPushButton *m_man;

    QPushButton *m_oneKey;

    QPushButton *m_sysSetting,*m_luboSetting;
    QSystemSettingWidget *m_setwin;
    QLuboSettingWidget   *m_setlubowin;

    QButtonGroup *m_modeGroup,*m_autoGroup;


protected:
    void paintEvent(QPaintEvent* event);

public slots:
    void showSystemSetting();
    void showLuboSetting();
    //插入片头
    void insertHead();
    //插入片尾
    void insertTail();
    //单导模式
    void showSingle();
    //双导模式
    void showDouble();
    //自动
    void showAuto();
    //半自动
    void showSemiAuto();
    //手动
    void showHandle();

    void TobeMutex(QVideoWidget*);
    void TobeMutexLive(QVideoWidget*);

};

#endif // MAINWINDOW_H
