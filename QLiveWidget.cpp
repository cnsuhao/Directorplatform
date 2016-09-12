#include "QLiveWidget.h"

QLiveWidget::QLiveWidget(QWidget *parent) :
    QWidget(parent)
{
    m_titleBar=new QHBoxLayout();
    m_statuBar=new QHBoxLayout();
    video=new QVideoWidget();
    gridLayout=new QGridLayout();
    full_btn=new QPushButton("full");
    full_btn->setToolTip(tr("full screen"));
    full_btn->setGeometry(0,0,30,30);
    snd_btn=new QPushButton("snd");
    setting_btn=new QPushButton("set");
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

    QVBoxLayout *vb=new QVBoxLayout();

    QLabel *lab=new QLabel("---------");
    m_statuBar->addWidget(lab);

    vb->addWidget(video);
    gridLayout->addLayout(m_titleBar,0,0,1,16,Qt::AlignLeft);
    gridLayout->addLayout(vb,1,0,9,16,Qt::AlignCenter);
    gridLayout->addLayout(m_statuBar,10,0,1,16,Qt::AlignLeft);
    this->setLayout(gridLayout);
}

QLiveWidget::~QLiveWidget()
{
    delete          m_titleBar;
    delete          m_statuBar;
    delete          video;
    delete          gridLayout;
    delete          full_btn;
    delete          snd_btn;
    delete          setting_btn;
    delete          title;
}
