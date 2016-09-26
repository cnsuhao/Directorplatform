#include "View/MainWindow.h"
#include "QSystemSettingWidget.h"
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
    gridLayout->setSpacing(2);

    this->setLayout(gridLayout);


    //some about tool

    m_insertHead = new QPushButton("head");
    m_insertTail = new QPushButton("tail");

    m_oneDirector = new QPushButton("one");
    m_twoDirector = new QPushButton("two");

    m_auto = new QPushButton("auto");
    m_semiAuto = new QPushButton("semi-auto");
    m_man = new QPushButton("man");

    m_oneKey = new QPushButton("one-key");
    m_Setting = new QPushButton("settting");

    toolLayout->setMargin(20);

    toolLayout->addWidget(m_insertHead);
    toolLayout->addWidget(m_insertTail);
    toolLayout->addWidget(m_oneDirector);
    toolLayout->addWidget(m_twoDirector);

    toolLayout->addWidget(m_auto);
    toolLayout->addWidget(m_semiAuto);
    toolLayout->addWidget(m_man);

    toolLayout->addWidget(m_oneKey);
    toolLayout->addWidget(m_Setting);

    m_setwin = new QSystemSettingWidget();
    connect(m_Setting,SIGNAL(clicked()),this,SLOT(showSystemSetting()));

}

MainWindow::~MainWindow()
{
    delete leftVideo;
    delete rightVideo;
    delete ctrlwin;
    delete funwin;

    for(int i=0;i<liveVideo_vec.count();i++)
    {
        delete liveVideo_vec[i];
    }
    liveVideo_vec.clear();

    delete dirvideoLayout;
    delete livevideoLayout;
    delete functionLayout;
    delete toolLayout;
    delete operatorLayout;
    delete mainLayout;
    delete gridLayout;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
    p.setPen(QColor(123,141,162));
    QPoint p1(toolLayout->geometry().left(),toolLayout->geometry().top());
    QPoint p2(toolLayout->geometry().right(),toolLayout->geometry().top());
    p.drawLine(p1,p2);
}

void MainWindow::showSystemSetting()
{

   m_setwin->show();

}
