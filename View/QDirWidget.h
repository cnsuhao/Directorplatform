#ifndef QDIRWIDGET_H
#define QDIRWIDGET_H

#include <QWidget>
#include "View/PlatformConfig.h"
#include "Model//QVideoWidget.h"
#include "Model/QButton.h"
#include <QTimer>
#include <QTime>
#include <QComboBox>
/*
 * Director Widget */

class QDirWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QDirWidget(QWidget *parent = 0);
    ~QDirWidget();
signals:

public slots:

public:
    QVideoWidget *video;

    QButton  *dirOutput_btn;
    QButton  *full_btn;
    QButton  *Ts_btn;
    QButton  *R_btn;
    QButton  *record_btn;
    QButton  *pause_btn;
    QButton  *stop_btn;

    QComboBox    *PMG_switch;
    QLabel       *time_title;

    void setToolBarBackColor(QColor color);
private:
    QHBoxLayout  *toolLayout;
    QVBoxLayout  *videoLayout;
    QVBoxLayout  *Con;
    QColor        tool_color;
    QTime         calctime;
    QTimer        timercalc;

protected:
    void paintEvent(QPaintEvent* event);

    friend void onBtnRecord(QWidget* q);
    friend void onBtnPause(QWidget* q);
    friend void onBtnStop(QWidget* q);
    friend void onBtnFullScreen(QDirWidget* q);
};



#endif // QDIRWIDGET_H
