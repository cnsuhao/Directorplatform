#include "QDirWidget.h"

QDirWidget::QDirWidget(QWidget *parent) :
    QWidget(parent)
{

// Init
    video =  new  QVideoWidget();
    dirOutput_btn = new QPushButton(tr("D-Output"));
    dirOutput_btn->setToolTip(tr("Director Output"));
    full_btn = new QPushButton(tr("FullScreen"));
    full_btn->setToolTip(tr("Full Screen"));
    Ts_btn = new QPushButton(tr("Ts"));
    Ts_btn->setToolTip(tr("Ts"));//---
    R_btn = new QPushButton(tr("R"));
    R_btn->setToolTip(tr("R"));//---
    record_btn = new QPushButton(tr("record"));
    record_btn->setToolTip(tr("record"));
    pause_btn = new QPushButton("pause");
    pause_btn->setToolTip(tr("pause"));
    stop_btn = new QPushButton(tr("stop"));
    stop_btn->setToolTip(tr("stop"));
    PMG_switch = new QComboBox(tr("PMG"));
    PMG_switch->setToolTip(tr("PMG"));


    toolLayout = new QHBoxLayout();
    toolLayout->setSpacing(2);
    videoLayout = new QVBoxLayout();
    videoLayout->setSpacing(0);
    Con  =  new QVBoxLayout();
    Con->setSpacing(0);

    videoLayout->addWidget(video);

    Con->addLayout(videoLayout,10);
    Con->addLayout(toolLayout,1);
    this->setLayout(Con);

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
