#ifndef QLIVEWIDGET_H
#define QLIVEWIDGET_H

#include <QWidget>
#include "PlatformConfig.h"
#include "QVideoWidget.h"
#include "QButton.h"
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
     QVBoxLayout  *videoLayout;
     QGridLayout  *gridLayout;
     QButton  *full_btn;
     QButton  *snd_btn;
     QButton  *setting_btn;
     QLabel       *title;
protected:
      void paintEvent(QPaintEvent* event);
      friend void onFullScreen(QWidget* q);
};

#endif // QLIVEWIDGET_H
