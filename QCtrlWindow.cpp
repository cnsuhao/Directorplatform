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
    zoom_up->setFixedSize(25,25);
    zoom_up->setObjectName("zoom_up");

    zoom_down = new QButton(this);
    zoom_down->setFixedSize(25,25);
    zoom_down->setObjectName("zoom_down");

    focus_label = new QLabel(tr("focus"),this);

    focus_on = new QButton(this);
    focus_on->setFixedSize(25,25);
    focus_on->setObjectName("focus_on");

    focus_off = new QButton(this);
    focus_off->setFixedSize(25,25);
    focus_off->setObjectName("focus_off");

    focus_auto = new QCheckBox(this);
    focus_auto->setFixedSize(25,25);
    focus_auto->setObjectName("focus_auto");

    ring_label = new QLabel(tr("ring"),this);

    ring_big = new QButton(this);
    ring_big->setObjectName("ring_big");
    ring_big->setFixedSize(25,25);

    ring_small = new QButton(this);
    ring_small->setFixedSize(25,25);
    ring_small->setObjectName("ring_small");

    ring_auto = new QCheckBox(this);
    ring_auto->setFixedSize(25,25);
    ring_auto->setObjectName("ring_auto");

    personlay = new QHBoxLayout();
    personlay->addWidget(one_person);
    personlay->addWidget(two_person);
    personlay->addWidget(three_person);
    personlay->addWidget(group_person);

    zoomlay = new QHBoxLayout();
    zoomlay->setSpacing(1);
    zoomlay->addWidget(zoom_label,1,Qt::AlignLeft);
    zoomlay->addWidget(zoom_up,1,Qt::AlignLeft);
    zoomlay->addWidget(zoom_down,1,Qt::AlignLeft);
    QLabel *tmp = new QLabel;
    tmp->setFixedSize(25,25);
    zoomlay->addWidget(tmp,1,Qt::AlignLeft);

    focuslay = new QHBoxLayout();
    focuslay->setSpacing(1);
    focuslay->addWidget(focus_label,1,Qt::AlignLeft);
    focuslay->addWidget(focus_on,1,Qt::AlignLeft);
    focuslay->addWidget(focus_off,1,Qt::AlignLeft);
    focuslay->addWidget(focus_auto,1,Qt::AlignLeft);

    ringlay = new QHBoxLayout();
    ringlay->setSpacing(1);
    ringlay->addWidget(ring_label,1,Qt::AlignLeft);
    ringlay->addWidget(ring_big,1,Qt::AlignLeft);
    ringlay->addWidget(ring_small,1,Qt::AlignLeft);
    ringlay->addWidget(ring_auto,1,Qt::AlignLeft);

    speed_adjust = new QSlider(Qt::Horizontal,this);
    speed_adjust->setObjectName("speed");

    btn_1 = new QPushButton(this);
    btn_1->setObjectName("btn_1");
    btn_1->setFixedSize(26,26);

    btn_2 = new QPushButton(this);
    btn_2->setObjectName("btn_2");
    btn_2->setFixedSize(26,26);

    btn_3 = new QPushButton(this);
    btn_3->setObjectName("btn_3");
    btn_3->setFixedSize(26,26);

    btn_4 = new QPushButton(this);
    btn_4->setObjectName("btn_4");
    btn_4->setFixedSize(26,26);

    btn_5 = new QPushButton(this);
    btn_5->setObjectName("btn_5");
    btn_5->setFixedSize(26,26);

    btn_6 = new QPushButton(this);
    btn_6->setFixedSize(26,26);
    btn_6->setObjectName("btn_6");

    btn_7 = new QPushButton(this);
    btn_7->setObjectName("btn_7");
    btn_7->setFixedSize(26,26);

    btn_8 = new QPushButton(this);
    btn_8->setObjectName("btn_8");
    btn_8->setFixedSize(26,26);


    numlay1 = new QHBoxLayout;
    numlay2 = new QHBoxLayout;

    numlay1->addWidget(btn_1);
    numlay1->addWidget(btn_2);
    numlay1->addWidget(btn_3);
    numlay1->addWidget(btn_4);

    numlay2->addWidget(btn_5);
    numlay2->addWidget(btn_6);
    numlay2->addWidget(btn_7);
    numlay2->addWidget(btn_8);

    lcd_date = new QLCDNumber(this);
    lcd_date->setDigitCount(30);
    lcd_date->display("2016-9-18   14:20:56");

    gLayout = new QVBoxLayout();


    dir_lay->addWidget(btn_up,0,1,1,1,Qt::AlignBottom);
    dir_lay->addWidget(btn_left,1,0,1,1,Qt::AlignRight);
    dir_lay->addWidget(btn_center,1,1);
    dir_lay->addWidget(btn_right,1,2,1,1,Qt::AlignLeft);
    dir_lay->addWidget(btn_down,2,1,1,1,Qt::AlignTop);
    dir_lay->setSpacing(3);


    // ----------------LAYOUT-------------------

    gLayout->addWidget(logo,2);
    gLayout->addStretch(1);
    gLayout->addWidget(meeting_ctrl,1,Qt::AlignCenter);
    gLayout->addWidget(cloud_ctrl,1,Qt::AlignCenter);

    gLayout->addLayout(personlay);
    gLayout->addStretch(1);
    gLayout->addLayout(zoomlay);
    gLayout->addLayout(focuslay);
    gLayout->addLayout(ringlay);
    gLayout->addStretch(1);

    gLayout->addLayout(dir_lay,3);
    gLayout->addWidget(speed_adjust);
    gLayout->addStretch(2);
    gLayout->addLayout(numlay1);
    gLayout->addLayout(numlay2);

    gLayout->addWidget(lcd_date,3);


    gLayout->setSpacing(10);
    this->setLayout(gLayout);


}

QCtrlWindow::~QCtrlWindow()
{

}
void QCtrlWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
}
