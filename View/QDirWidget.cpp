#include "View/QDirWidget.h"
#include <QTime>

void onBtnFullScreen(QWidget* q)
{
    QDirWidget *d=static_cast<QDirWidget*>(q);
    Q_ASSERT(d);
    d->video->fullVideoScreen();
}


void onBtnRecord(QWidget* q)
{
    QMessageBox::warning(q,"tip","record",0,0);

}
void onBtnPause(QWidget* q)
{
     QMessageBox::warning(q,"tip","pause",0,0);
}
void onBtnStop(QWidget* q)
{
     QMessageBox::warning(q,"tip","stop",0,0);
}


QDirWidget::QDirWidget(QWidget *parent) :
    QWidget(parent)
{

// Init
    tool_color=QColor(37,44,52);// default is black
    video =  new  QVideoWidget();

    dirOutput_btn = new QButton(tr("D"),this);
    dirOutput_btn->setToolTip(tr("Director Output"));
    dirOutput_btn->setFixedWidth(30);
    dirOutput_btn->setObjectName("dir_ouput");
   // auto fun =[](QWidget* w){QMessageBox::warning(0,"tip","导播输出",0,0);};
    dirOutput_btn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    full_btn = new QButton(this);
    full_btn->setObjectName("dir_fullscreen");
   // full_btn->setStyleSheet("border-image:url(:skin/full.png)");
    full_btn->setFixedSize(25,25);
    full_btn->setToolTip(tr("Full Screen"));
    full_btn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    Ts_btn = new QButton(tr("Ts"),this);
    Ts_btn->setFixedWidth(30);
    Ts_btn->setToolTip(tr("Ts"));//---
    Ts_btn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    R_btn = new QButton(tr("R"),this);
    R_btn->setToolTip(tr("R"));//---
    R_btn->setFixedWidth(30);
    R_btn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    record_btn = new QButton(this);
    record_btn->setToolTip(tr("record"));
    record_btn->setFixedSize(24,24);
    record_btn->setObjectName("dir_record");
    record_btn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    pause_btn = new QButton(this);
    pause_btn->setToolTip(tr("pause"));
    pause_btn->setFixedSize(24,24);
    pause_btn->setObjectName("dir_pause");
    pause_btn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    stop_btn = new QButton(this);
    stop_btn->setToolTip(tr("stop"));
    stop_btn->setObjectName("dir_stop");
    stop_btn->setFixedSize(24,24);
    stop_btn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    PMG_switch = new QLabel("PMG");
    PMG_switch->setToolTip(tr("PMG"));
    PMG_switch->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    calctime.setHMS(0,0,0);

    time_title = new QLabel(calctime.toString("hh:mm:ss"),this);
    time_title->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);



//tool
    toolLayout = new QHBoxLayout();
    toolLayout->setSpacing(2);
    toolLayout->addWidget(dirOutput_btn);
    toolLayout->addWidget(full_btn);
    toolLayout->addWidget(PMG_switch,4,Qt::AlignCenter);
    toolLayout->addWidget(Ts_btn);
    toolLayout->addWidget(R_btn);
    toolLayout->addWidget(record_btn);
    toolLayout->addWidget(pause_btn);
    toolLayout->addWidget(stop_btn);
    toolLayout->addWidget(time_title);

    videoLayout = new QVBoxLayout();
    videoLayout->setSpacing(0);
    Con  =  new QVBoxLayout();
    Con->setSpacing(0);
    Con->setMargin(0);

    videoLayout->addWidget(video);

    Con->addLayout(videoLayout,10);
    Con->addLayout(toolLayout,1);
    this->setLayout(Con);
//event
    full_btn->click=onBtnFullScreen;
    record_btn->click=onBtnRecord;
    stop_btn->click=onBtnStop;
    pause_btn->click=onBtnPause;

    //connect(full_btn,SIGNAL(clicked()),this,SLOT(onBtnFullScreen()));

}


QDirWidget::~QDirWidget()
{
//DeInit
    delete  video;
    delete  dirOutput_btn;
    delete  full_btn;
    delete  Ts_btn;
    delete  R_btn;
    delete  record_btn;
    delete  pause_btn;
    delete  stop_btn;
    delete  PMG_switch;


    delete  toolLayout;
    delete  videoLayout;
    delete  Con;
}

void QDirWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(toolLayout->geometry(),tool_color);
}

void QDirWidget::setToolBarBackColor(QColor color)
{
    tool_color=color;
}


