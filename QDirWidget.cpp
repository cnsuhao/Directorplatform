#include "QDirWidget.h"


void onBtnFullScreen(QWidget* q)
{
    if(q->isFullScreen())
    {
        q->setWindowFlags(Qt::SubWindow);
        q->showNormal();
    }
    else
    {
        q->setWindowFlags(Qt::Dialog);
        q->showFullScreen();
    }
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
    tool_color=QColor(35,35,70);// default is black
    video =  new  QVideoWidget();

    dirOutput_btn = new QButton(tr("D"),this);
    dirOutput_btn->setToolTip(tr("Director Output"));
    dirOutput_btn->setFixedWidth(30);
   // auto fun =[](QWidget* w){QMessageBox::warning(0,"tip","导播输出",0,0);};
    dirOutput_btn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    full_btn = new QButton(this);
    full_btn->setStyleSheet("border-image:url(:skin/full.png)");
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
    record_btn = new QButton(tr("record"),this);
    record_btn->setToolTip(tr("record"));
    record_btn->setFixedWidth(30);
    record_btn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    pause_btn = new QButton("pause",this);
    pause_btn->setToolTip(tr("pause"));
    pause_btn->setFixedWidth(30);
    pause_btn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    stop_btn = new QButton(tr("stop"),this);
    stop_btn->setToolTip(tr("stop"));
    stop_btn->setFixedWidth(30);
    stop_btn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    PMG_switch = new QComboBox();
    PMG_switch->setToolTip(tr("PMG"));
    PMG_switch->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);
    time_title = new QLabel("00:00:00",this);
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


