#include "View/QLiveWidget.h"

void onFullScreen(QWidget* q)
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

QLiveWidget::QLiveWidget(QWidget *parent) :
    QWidget(parent)
{
    m_titleBar=new QHBoxLayout();
    m_statuBar=new QHBoxLayout();
    video = new QVideoWidget();
    videoLayout= new QVBoxLayout();
    gridLayout=new QGridLayout();
    full_btn=new QButton(this);
    full_btn->setToolTip(tr("full screen"));
    full_btn->click=onFullScreen;
    full_btn->setFixedWidth(25);
    full_btn->setObjectName("live_full");
    full_btn->setGeometry(0,0,30,30);
    snd_btn=new QButton("snd",this);
    snd_btn->setFixedWidth(25);
    setting_btn=new QButton("set",this);
    setting_btn->setFixedWidth(30);
    setting_btn->setToolTip(tr("setting"));
    title=new QLabel("title");
    title->setAlignment(Qt::AlignCenter);
// m_titleBar
    m_titleBar->setSpacing(0);
    m_titleBar->addStretch();
    m_titleBar->addWidget(full_btn);
    m_titleBar->addStretch();
    m_titleBar->addWidget(snd_btn);
    m_titleBar->addStretch();
    m_titleBar->addWidget(title);
    m_titleBar->addStretch();
    m_titleBar->setStretchFactor(title,7);
    m_titleBar->addWidget(setting_btn);
    m_titleBar->addStretch();

//gridLayout
    gridLayout->setSpacing(0);

//m_statuBar
    m_statuBar->setSpacing(0);


    QLabel *lab=new QLabel("A");
    lab->setFixedHeight(20);
    m_statuBar->addWidget(lab,0,Qt::AlignRight);

    videoLayout->addWidget(video);
    gridLayout->addLayout(m_titleBar,0,0);
    gridLayout->addLayout(videoLayout,1,0);
    gridLayout->addLayout(m_statuBar,2,0);

    gridLayout->setRowStretch(0,1);
    gridLayout->setRowStretch(1,30);
    gridLayout->setRowStretch(2,1);
    gridLayout->setMargin(0);
    this->setLayout(gridLayout);
}

QLiveWidget::~QLiveWidget()
{
    delete          m_titleBar;
    delete          m_statuBar;
    delete          video;
    delete          videoLayout;
    delete          gridLayout;
    delete          full_btn;
    delete          snd_btn;
    delete          setting_btn;
    delete          title;
}

void QLiveWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(m_titleBar->geometry(),QColor(47,79,79));
     painter.fillRect(m_statuBar->geometry(),QColor(0,128,128));
}
