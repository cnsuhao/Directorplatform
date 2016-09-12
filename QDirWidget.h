#ifndef QDIRWIDGET_H
#define QDIRWIDGET_H

#include <QWidget>
#include "PlatformConfig.h"
#include "QVideoWidget.h"

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

    QPushButton  *dirOutput_btn;
    QPushButton  *full_btn;
    QPushButton  *Ts_btn;
    QPushButton  *R_btn;
    QPushButton  *record_btn;
    QPushButton  *pause_btn;
    QPushButton  *stop_btn;

    QComboBox    *PMG_switch;

private:
    QHBoxLayout  *toolLayout;
    QVBoxLayout  *videoLayout;
    QVBoxLayout  *Con;



};

#endif // QDIRWIDGET_H
