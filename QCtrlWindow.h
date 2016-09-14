#ifndef QCTRLWINDOW_H
#define QCTRLWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include "QButton.h"
#include <QCheckBox>
#include <QSlider>
#include <QLCDNumber>


/*
 *  this widget control windows operator */



class QCtrlWindow : public QWidget
{
    Q_OBJECT
public:
    explicit QCtrlWindow(QWidget *parent = 0);

signals:

public slots:
private:
    QGridLayout *m_gridLayout;

    /*direction Button*/
    QButton   *btn_up;
    QButton   *btn_down;
    QButton   *btn_left;
    QButton   *btn_right;

    /*switch Control use checkbox*/
    QCheckBox *meeting_ctrl;//会议控制
    QCheckBox *cloud_ctrl;//云台控制

    /*number of person*/
    QCheckBox *one_person;
    QCheckBox *two_person;
    QCheckBox *three_person;
    QCheckBox *group_person;


    QButton  *zoom_up; //向大变焦
    QButton  *zoom_down;//向小变焦

    QButton  *focus_on;//放 聚焦
    QButton  *focus_off;//收 聚焦
    QCheckBox *focus_auto;

    QButton  *ring_big;//光圈 大
    QButton  *ring_small;//光圈 小
    QCheckBox *ring_auto;

    QSlider *speed_adjust;//速度调节


    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_4;
    QPushButton *btn_5;
    QPushButton *btn_6;
    QPushButton *btn_7;
    QPushButton *btn_8;

    QLCDNumber *lcd_time;
    QLCDNumber *lcd_date;




protected:
    void paintEvent(QPaintEvent* event);


};

#endif // QCTRLWINDOW_H
