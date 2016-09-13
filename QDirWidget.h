#ifndef QDIRWIDGET_H
#define QDIRWIDGET_H

#include <QWidget>
#include "PlatformConfig.h"
#include "QVideoWidget.h"
#include "QButton.h"

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
protected:
    void paintEvent(QPaintEvent* event);
    friend void onBtnFullScreen(QWidget* q);
    friend void onBtnRecord(QWidget* q);
    friend void onBtnPause(QWidget* q);
    friend void onBtnStop(QWidget* q);

};



#endif // QDIRWIDGET_H
