#ifndef QLIVEWIDGET_H
#define QLIVEWIDGET_H

#include <QWidget>
#include "PlatformConfig.h"
#include "QVideoWidget.h"

/*
 * 直播(live video widget)*/

class QLiveWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QLiveWidget(QWidget *parent = 0);
    ~QLiveWidget();

signals:

public slots:
public:
     QHBoxLayout *m_titleBar;
     QHBoxLayout *m_statuBar;
private:
     QVideoWidget *video;
     QGridLayout  *gridLayout;
     QPushButton  *full_btn;
     QPushButton  *snd_btn;
     QPushButton  *setting_btn;
     QLabel       *title;
};

#endif // QLIVEWIDGET_H
