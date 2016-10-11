#include "View/QCtrlWindow.h"
#include <QPainter>
#include <QDate>
#include <QDateTime>
#include <Model/TipDialog.h>

// friend function to do event

void onBtn_up_up(QWidget *q)
{
    TipDialog t(TipDialog::OK|TipDialog::Cannel);
    t.setTipTitle("hahha");
    //t.setTipInfoText(QLabel::tr("12345678912345678123456789123456789123456789123456789123456789"));
    t.loadMovie(":/skin/load.gif");
    t.showDialog();
}
void onBtn_up_down(QWidget *q)
{

}

void onBtn_down_up(QWidget *q)
{

}
void onBtn_down_down(QWidget *q)
{
  QMessageBox::warning(0,"tip","down-dwon",0,0);
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

void onBtn_center_up(QWidget *q)
{
    QMessageBox::warning(0,"tip","you click center",0,0);

}
void onZoom_up_clicked(QWidget *q)
{
    QMessageBox::warning(0,"tip","zoom-up",0,0);

}
void onZoom_down_clicked(QWidget *q)
{
    QMessageBox::warning(0,"tip","zoom-down",0,0);

}
void onFocus_on_clicked(QWidget *q)
{
    QMessageBox::warning(0,"tip","focus-on",0,0);

}
void onFocus_off_clicked(QWidget *q)
{
    QMessageBox::warning(0,"tip","focus-off",0,0);

}
void onRing_big_clicked(QWidget *q)
{
    QMessageBox::warning(0,"tip","ring_big",0,0);

}
void onRing_small_clicked(QWidget *q)
{
    QMessageBox::warning(0,"tip","ring-small",0,0);

}


QCtrlWindow::QCtrlWindow(QWidget *parent) :
    QWidget(parent)
{

    logo = new QGraphicsView(this);
    logo->setFixedSize(257,94);
    logo->setObjectName("logo");
    logo->setStyleSheet("QGraphicsView{border:none;}");

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
    btn_center->lbuttonup = onBtn_center_up;


    btn_left = new QButton(this);
    btn_left->setFixedSize(34,34);
    btn_left->setObjectName("btn_left");
    btn_left->setToolTip(tr("move left"));
    btn_left->lbuttonup = onBtn_left_up;
    btn_left->lbuttondown = onBtn_left_down;

    btn_right = new QButton();
    btn_right->setFixedSize(34,34);
    btn_right->setObjectName("btn_right");
    btn_right->setToolTip(tr("move right"));
    btn_right->lbuttonup = onBtn_right_up;
    btn_right->lbuttondown = onBtn_right_down;

    mcGroup = new QButtonGroup();
    meeting_ctrl = new QPushButton(tr("meeting"));
    meeting_ctrl->setIcon(QIcon(":/skin/icon1"));
    meeting_ctrl->setCheckable(true);
    meeting_ctrl->setChecked(true);
    meeting_ctrl->setObjectName("meeting_ctrl");

    cloud_ctrl = new QPushButton(tr("cloud"));
    cloud_ctrl->setCheckable(true);
    cloud_ctrl->setObjectName("cloud_ctrl");

    mcGroup->addButton(meeting_ctrl);
    mcGroup->addButton(cloud_ctrl);
    one_person = new QCheckBox();
    one_person->setObjectName("one");

    two_person = new QCheckBox();
    two_person->setObjectName("two");

    three_person = new QCheckBox();
    three_person->setObjectName("three");

    group_person = new QCheckBox();
    group_person->setObjectName("group");

    zoom_label = new QLabel(tr("zoom"));
    zoom_up = new QButton();
    zoom_up->setFixedSize(25,25);
    zoom_up->setObjectName("plus");
    zoom_up->lbuttonup = onZoom_up_clicked;

    zoom_down = new QButton();
    zoom_down->setFixedSize(25,25);
    zoom_down->setObjectName("minus");
    zoom_down->lbuttonup = onZoom_down_clicked;

    focus_label = new QLabel(tr("focus"));

    focus_on = new QButton();
    focus_on->setFixedSize(25,25);
    focus_on->setObjectName("plus");
    focus_on->lbuttonup = onFocus_on_clicked;

    focus_off = new QButton();
    focus_off->setFixedSize(25,25);
    focus_off->setObjectName("minus");
    focus_off->lbuttonup = onFocus_off_clicked;

    focus_auto = new QCheckBox();
    focus_auto->setFixedSize(25,25);
    focus_auto->setObjectName("focus_auto");

    ring_label = new QLabel(tr("ring"));

    ring_big = new QButton();
    ring_big->setObjectName("plus");
    ring_big->setFixedSize(25,25);
    ring_big->lbuttonup = onRing_big_clicked;

    ring_small = new QButton();
    ring_small->setFixedSize(25,25);
    ring_small->setObjectName("minus");
    ring_small->lbuttonup = onRing_small_clicked;

    ring_auto = new QCheckBox();
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

    speed_adjust = new QSlider(Qt::Horizontal);
    speed_adjust->setObjectName("speed");

    btn_1 = new QPushButton();
    btn_1->setObjectName("btn_1");
    btn_1->setFixedSize(26,26);
    btn_1->setCheckable(true);
    btn_1->setChecked(true);

    btn_2 = new QPushButton();
    btn_2->setObjectName("btn_2");
    btn_2->setFixedSize(26,26);
    btn_2->setCheckable(true);

    btn_3 = new QPushButton();
    btn_3->setObjectName("btn_3");
    btn_3->setFixedSize(26,26);
    btn_3->setCheckable(true);

    btn_4 = new QPushButton();
    btn_4->setObjectName("btn_4");
    btn_4->setFixedSize(26,26);
    btn_4->setCheckable(true);

    btn_5 = new QPushButton();
    btn_5->setObjectName("btn_5");
    btn_5->setFixedSize(26,26);
    btn_5->setCheckable(true);

    btn_6 = new QPushButton();
    btn_6->setFixedSize(26,26);
    btn_6->setObjectName("btn_6");
    btn_6->setCheckable(true);

    btn_7 = new QPushButton();
    btn_7->setObjectName("btn_7");
    btn_7->setFixedSize(26,26);
    btn_7->setCheckable(true);

    btn_8 = new QPushButton();
    btn_8->setObjectName("btn_8");
    btn_8->setFixedSize(26,26);
    btn_8->setCheckable(true);

    group = new QButtonGroup();
    group->addButton(btn_1);
    group->addButton(btn_2);
    group->addButton(btn_3);
    group->addButton(btn_4);
    group->addButton(btn_5);
    group->addButton(btn_6);
    group->addButton(btn_7);
    group->addButton(btn_8);

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

    lcd_date = new QLCDNumber();
    lcd_date->setPalette(Qt::green);
    lcd_date->setStyleSheet("QLCDNumber{border:1px solid rgb(136, 179, 213);}");
    lcd_date->setDigitCount(22);
    QDateTime dt = QDateTime::currentDateTime();
    lcd_date->display(dt.toString("yyyy-MM-dd  hh:mm:ss"));

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
    gLayout->addWidget(speed_adjust,Qt::AlignCenter);
    gLayout->addStretch(2);
    gLayout->addLayout(numlay1);
    gLayout->addLayout(numlay2);

    gLayout->addWidget(lcd_date,3);


    gLayout->setSpacing(10);
    this->setLayout(gLayout);
    timer = new QTimer(this);// not need to release
    timer->start(1000);

    // event

    connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
    connect(meeting_ctrl,SIGNAL(clicked()),this,SLOT(switch_meet_cloud()));
    connect(cloud_ctrl,SIGNAL(clicked()),this,SLOT(switch_meet_cloud()));

    connect(btn_1,SIGNAL(clicked()),this,SLOT(switch_num()));
    connect(btn_2,SIGNAL(clicked()),this,SLOT(switch_num()));
    connect(btn_3,SIGNAL(clicked()),this,SLOT(switch_num()));
    connect(btn_4,SIGNAL(clicked()),this,SLOT(switch_num()));
    connect(btn_5,SIGNAL(clicked()),this,SLOT(switch_num()));
    connect(btn_6,SIGNAL(clicked()),this,SLOT(switch_num()));
    connect(btn_7,SIGNAL(clicked()),this,SLOT(switch_num()));
    connect(btn_8,SIGNAL(clicked()),this,SLOT(switch_num()));

}

QCtrlWindow::~QCtrlWindow()
{
    delete btn_up;
    delete btn_down;
    delete btn_left;
    delete btn_center;
    delete btn_right;

    delete meeting_ctrl;
    delete cloud_ctrl;
    delete mcGroup;
    delete one_person;
    delete two_person;
    delete three_person;
    delete group_person;

    delete zoom_label;
    delete zoom_up;
    delete zoom_down;

    delete focus_label;
    delete focus_on;
    delete focus_off;
    delete focus_auto;

    delete ring_label;
    delete ring_big;
    delete ring_small;
    delete ring_auto;

    delete speed_adjust;
    delete logo;
    delete btn_1;
    delete btn_2;
    delete btn_3;
    delete btn_4;
    delete btn_5;
    delete btn_6;
    delete btn_7;
    delete btn_8;

    delete lcd_date;

    delete dir_lay;
    delete personlay;
    delete zoomlay;
    delete focuslay;
    delete ringlay;
    delete gLayout;


}
void QCtrlWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));

    p.setPen(QColor(136,179,213));
    QRect r(gLayout->geometry().left()+8,meeting_ctrl->geometry().top()-10,gLayout->geometry().width()-16,lcd_date->geometry().top()-meeting_ctrl->geometry().top()+5);
    p.drawRoundedRect(r,5,5);


}

void QCtrlWindow::updateTime()
{
   // 2016-9-18   14:20:56
    QDateTime dt = QDateTime::currentDateTime();
    lcd_date->display(dt.toString("yyyy-MM-dd  hh:mm:ss"));
}

void QCtrlWindow::switch_meet_cloud()
{
   if(meeting_ctrl->isChecked())
   {
       QMessageBox::warning(0,"","Meet is checked",0,0);
   }
   else
   {
       QMessageBox::warning(0,"","cloud is checked",0,0);
   }
}

void QCtrlWindow::switch_num()
{
    if(btn_1->isChecked())
    {
        QMessageBox::warning(0,"","1",0,0);
    }
    else if(btn_2->isChecked())
    {
        QMessageBox::warning(0,"","2",0,0);
    }
    else if(btn_3->isChecked())
    {
        QMessageBox::warning(0,"","3",0,0);
    }
    else if(btn_4->isChecked())
    {
        QMessageBox::warning(0,"","4",0,0);
    }
    else if(btn_5->isChecked())
    {
        QMessageBox::warning(0,"","5",0,0);
    }
    else if(btn_6->isChecked())
    {
        QMessageBox::warning(0,"","6",0,0);
    }
    else if(btn_7->isChecked())
    {
        QMessageBox::warning(0,"","7",0,0);
    }
    else if(btn_8->isChecked())
    {
        QMessageBox::warning(0,"","8",0,0);
    }

}
