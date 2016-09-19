#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "View/PlatformConfig.h"
#include "View/QDirWidget.h"
#include "View/QLiveWidget.h"
#include "View/QCtrlWindow.h"
#include "View/QFunctionWidget.h"

#include  <QVector>

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
protected:
    void paintEvent(QPaintEvent* event);


};

#endif // MAINWINDOW_H
