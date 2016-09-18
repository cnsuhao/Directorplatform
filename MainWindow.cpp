#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), NumberOfLive(7)
{
    leftVideo = new QDirWidget();
    rightVideo = new QDirWidget();
    ctrlwin = new QCtrlWindow();
    funwin = new QFunctionWidget();
    gridLayout = new QGridLayout();
    mainLayout = new QVBoxLayout();
    operatorLayout = new QVBoxLayout();
    toolLayout = new QHBoxLayout();

    dirvideoLayout = new QHBoxLayout();
    livevideoLayout = new QHBoxLayout();
    functionLayout = new QHBoxLayout();


    for(int i=0;i<NumberOfLive;i++)
    {
        QLiveWidget *qlive = new QLiveWidget();
        liveVideo_vec.append(qlive);
    }

    /*添加布局 & 控件 */
    gridLayout->addLayout(mainLayout,0,0);
    gridLayout->addLayout(operatorLayout,0,1);
    gridLayout->addLayout(toolLayout,1,0,1,2);
    mainLayout->addLayout(dirvideoLayout,10);
    mainLayout->addLayout(livevideoLayout,4);
    mainLayout->addLayout(functionLayout,6);

    dirvideoLayout->addWidget(leftVideo);
    dirvideoLayout->addWidget(rightVideo);

    operatorLayout->addWidget(ctrlwin);
    operatorLayout->setSpacing(0);

    functionLayout->addWidget(funwin);
    for(int i=0;i<NumberOfLive;i++)
    {
        livevideoLayout->addWidget(liveVideo_vec.at(i));
    }

    /*调整布局*/
    gridLayout->setRowStretch(0,20);
    gridLayout->setRowStretch(1,1);
    gridLayout->setColumnStretch(0,7);
    gridLayout->setColumnStretch(1,1);

    gridLayout->setMargin(0);
    gridLayout->setSpacing(1);

    this->setLayout(gridLayout);

}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(toolLayout->geometry(),QColor(37,44,52));
}
