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

    btn_up = new QButton(this);
    btn_up->setObjectName("btn_up");
    btn_up->setToolTip(tr("move up"));
    btn_up->lbuttonup = onBtn_up_up;
    btn_up->lbuttondown = onBtn_up_down;

    btn_down = new QButton(this);
    btn_down->setObjectName("btn_down");
    btn_down->setToolTip(tr("move down"));
    btn_down->lbuttonup = onBtn_down_up;
    btn_down->lbuttondown = onBtn_down_down;

    btn_left = new QButton(this);
    btn_left->setObjectName("btn_left");
    btn_left->setToolTip(tr("move left"));
    btn_left->lbuttonup = onBtn_left_up;
    btn_left->lbuttondown = onBtn_left_down;

    btn_right = new QButton(this);
    btn_right->setObjectName("btn_right");
    btn_right->setToolTip(tr("move right"));
    btn_right->lbuttonup = onBtn_right_up;
    btn_right->lbuttondown = onBtn_right_down;

    meeting_ctrl = new QCheckBox(this);
    meeting_ctrl->setObjectName("meeting_ctrl");

    cloud_ctrl = new QCheckBox(this);
    cloud_ctrl->setObjectName("cloud_ctrl");

    one_person = new QCheckBox(this);
    one_person->setObjectName("one");

    two_person = new QCheckBox(this);
    two_person->setObjectName("two");

    three_person = new QCheckBox(this);
    three_person->setObjectName("three");

    group_person = new QCheckBox(this);
    group_person->setObjectName("group");

    zoom_up = new QButton(this);
    zoom_up->setObjectName("zoom_up");

    zoom_down = new QButton(this);
    zoom_down->setObjectName("zoom_down");

    focus_on = new QButton(this);
    focus_on->setObjectName("focus_on");

    focus_off = new QButton(this);
    focus_off->setObjectName("focus_off");

    focus_auto = new QCheckBox(this);
    focus_auto->setObjectName("focus_auto");

    ring_big = new QButton(this);
    ring_big->setObjectName("ring_big");

    ring_small = new QButton(this);
    ring_small->setObjectName("ring_small");

    ring_auto = new QCheckBox(this);
    ring_auto->setObjectName("ring_auto");


    speed_adjust = new QSlider(Qt::Horizontal,this);
    speed_adjust->setObjectName("speed");

    gridLayout = new QGridLayout();


    //layout
    QVBoxLayout *b1 = new QVBoxLayout;
    QVBoxLayout *b2 = new QVBoxLayout;
    QVBoxLayout *b3 = new QVBoxLayout;

    b1->addWidget(meeting_ctrl);
    b2->addWidget(cloud_ctrl);
    gridLayout->addLayout(b1,0,0);
    gridLayout->addLayout(b1,1,0);
    gridLayout->addLayout(b1,2,0);

    this->setLayout(gridLayout);


}

QCtrlWindow::~QCtrlWindow()
{

}
void QCtrlWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor("green"));
}
