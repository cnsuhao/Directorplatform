#include "QCtrlWindow.h"
#include <QPainter>



// friend function to do event

void onBtn_up_up(QWidget *q)
{
    // TODO
}
void onBtn_up_down(QWidget *q)
{

}

void onBtn_down_up(QWidget *q)
{

}
void onBtn_down_down(QWidget *q)
{

}
void onBtn_left_up(QWidget *q)
{

}
void onBtn_left_down(QWidget *q)
{

}

void onBtn_right_up(QWidget *q)
{

}
void onBtn_right_down(QWidget *q)
{

}















QCtrlWindow::QCtrlWindow(QWidget *parent) :
    QWidget(parent)
{

    logo = new QGraphicsView(this);
    logo->setFixedSize(257,94);
    logo->setObjectName("logo");

    dir_wid = new QWidget();
    dir_lay = new QGridLayout();

    btn_up = new QButton(this);
    btn_up->setFixedSize(34,34);
    btn_up->setObjectName("btn_up");
    btn_up->setToolTip(tr("move up"));
    btn_up->lbuttonup = onBtn_up_up;
    btn_up->lbuttondown = onBtn_up_down;

    btn_down = new QButton(this);
    btn_down->setFixedSize(34,34);
    btn_down->setObjectName("btn_down");
    btn_down->setToolTip(tr("move down"));
    btn_down->lbuttonup = onBtn_down_up;
    btn_down->lbuttondown = onBtn_down_down;

    btn_center = new QButton(this);
    btn_center->setFixedSize(34,34);
    btn_center->setObjectName("btn_center");
    btn_center->setToolTip(tr("reset"));


    btn_left = new QButton(this);
    btn_left->setFixedSize(34,34);
    btn_left->setObjectName("btn_left");
    btn_left->setToolTip(tr("move left"));
    btn_left->lbuttonup = onBtn_left_up;
    btn_left->lbuttondown = onBtn_left_down;

    btn_right = new QButton(this);
    btn_right->setFixedSize(34,34);
    btn_right->setObjectName("btn_right");
    btn_right->setToolTip(tr("move right"));
    btn_right->lbuttonup = onBtn_right_up;
    btn_right->lbuttondown = onBtn_right_down;

    meeting_ctrl = new QCheckBox(tr("meeting"),this);
    meeting_ctrl->setObjectName("meeting_ctrl");

    cloud_ctrl = new QCheckBox(tr("cloud"),this);
    cloud_ctrl->setObjectName("cloud_ctrl");

    one_person = new QCheckBox(this);
    one_person->setObjectName("one");

    two_person = new QCheckBox(this);
    two_person->setObjectName("two");

    three_person = new QCheckBox(this);
    three_person->setObjectName("three");

    group_person = new QCheckBox(this);
    group_person->setObjectName("group");

    zoom_label = new QLabel(tr("zoom"),this);

    zoom_up = new QButton(this);
    zoom_up->setObjectName("zoom_up");

    zoom_down = new QButton(this);
    zoom_down->setObjectName("zoom_down");

    focus_label = new QLabel(tr("focus"),this);

    focus_on = new QButton(this);
    focus_on->setObjectName("focus_on");

    focus_off = new QButton(this);
    focus_off->setObjectName("focus_off");

    focus_auto = new QCheckBox(this);
    focus_auto->setObjectName("focus_auto");

    ring_label = new QLabel(tr("ring"),this);

    ring_big = new QButton(this);
    ring_big->setObjectName("ring_big");

    ring_small = new QButton(this);
    ring_small->setObjectName("ring_small");

    ring_auto = new QCheckBox(this);
    ring_auto->setObjectName("ring_auto");


    speed_adjust = new QSlider(Qt::Horizontal,this);
    speed_adjust->setObjectName("speed");

    btn_1 = new QPushButton("1",this);
    btn_1->setFixedSize(25,25);
    btn_2 = new QPushButton("2",this);
    btn_2->setFixedSize(25,25);
    btn_3 = new QPushButton("3",this);
    btn_3->setFixedSize(25,25);
    btn_4 = new QPushButton("4",this);
    btn_4->setFixedSize(25,25);
    btn_5 = new QPushButton("5",this);
    btn_5->setFixedSize(25,25);
    btn_6 = new QPushButton("6",this);
    btn_6->setFixedSize(25,25);
    btn_7 = new QPushButton("7",this);
    btn_7->setFixedSize(25,25);
    btn_8 = new QPushButton("8",this);
    btn_8->setFixedSize(25,25);


    lcd_date = new QLCDNumber(this);
    lcd_date->setDigitCount(30);
    lcd_date->display("2016-9-18");

    lcd_time = new QLCDNumber(this);
    lcd_time->setDigitCount(30);
    lcd_time->display("14:20:52");
    gridLayout = new QGridLayout();


    //layout
//    QVBoxLayout *b1 = new QVBoxLayout;
//    QVBoxLayout *b2 = new QVBoxLayout;
//    QVBoxLayout *b3 = new QVBoxLayout;

//    b1->addWidget(meeting_ctrl);
//    b2->addWidget(cloud_ctrl);
//    gridLayout->addLayout(b1,0,0);
//    gridLayout->addLayout(b1,1,0);
//    gridLayout->addLayout(b1,2,0);


    dir_lay->addWidget(btn_up,0,1,1,1,Qt::AlignBottom);
    dir_lay->addWidget(btn_left,1,0,1,1,Qt::AlignRight);
    dir_lay->addWidget(btn_center,1,1);
    dir_lay->addWidget(btn_right,1,2,1,1,Qt::AlignLeft);
    dir_lay->addWidget(btn_down,2,1,1,1,Qt::AlignTop);

    dir_wid->setLayout(dir_lay);




    gridLayout->addWidget(logo,0,0,1,4);
    gridLayout->addWidget(meeting_ctrl,1,0,1,3);

    gridLayout->addWidget(cloud_ctrl,2,0,1,3);

    gridLayout->addWidget(one_person,3,0);
    gridLayout->addWidget(two_person,3,1);
    gridLayout->addWidget(three_person,3,2);
    gridLayout->addWidget(group_person,3,3);

    gridLayout->addWidget(zoom_label,4,0);
    gridLayout->addWidget(zoom_up,4,1);
    gridLayout->addWidget(zoom_down,4,2);

    gridLayout->addWidget(focus_label,5,0);
    gridLayout->addWidget(focus_on,5,1);
    gridLayout->addWidget(focus_off,5,2);
    gridLayout->addWidget(focus_auto,5,3);

    gridLayout->addWidget(ring_label,6,0);
    gridLayout->addWidget(ring_small,6,1);
    gridLayout->addWidget(ring_big,6,2);
    gridLayout->addWidget(ring_auto,6,3);


//    gridLayout->addWidget(btn_up,7,1,1,1,Qt::AlignBottom);
//    gridLayout->addWidget(btn_left,8,0,1,1,Qt::AlignRight);
//    gridLayout->addWidget(btn_center,8,1,1,1,Qt::AlignLeft);
//    gridLayout->addWidget(btn_right,8,2,1,1,Qt::AlignLeft);
//    gridLayout->addWidget(btn_down,9,1,1,1,Qt::AlignTop);

    gridLayout->addWidget(dir_wid,7,1);

    gridLayout->addWidget(speed_adjust,10,0,1,4);

    gridLayout->addWidget(btn_1,11,0);
    gridLayout->addWidget(btn_2,11,1);
    gridLayout->addWidget(btn_3,11,2);
    gridLayout->addWidget(btn_4,11,3);

    gridLayout->addWidget(btn_5,12,0);
    gridLayout->addWidget(btn_6,12,1);
    gridLayout->addWidget(btn_7,12,2);
    gridLayout->addWidget(btn_8,12,3);


    gridLayout->addWidget(lcd_date,13,0,1,3);
    gridLayout->addWidget(lcd_time,14,0,1,3);

    gridLayout->setColumnStretch(1,1);
    gridLayout->setColumnStretch(2,1);
    gridLayout->setColumnStretch(3,1);
    gridLayout->setColumnStretch(4,1);

    //gridLayout->setRowStretch(0,2);
    gridLayout->setRowStretch(7,1);
    gridLayout->setRowStretch(8,1);
    gridLayout->setRowStretch(9,1);
    gridLayout->setRowStretch(10,4);
    gridLayout->setRowStretch(11,1);
    gridLayout->setRowStretch(12,1);

    this->setLayout(gridLayout);


}

QCtrlWindow::~QCtrlWindow()
{

}
void QCtrlWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
}
