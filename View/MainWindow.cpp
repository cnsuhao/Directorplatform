#include "View/MainWindow.h"
#include "QSystemSettingWidget.h"
#include <QPropertyAnimation>

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

    m_insertHead = new QPushButton(tr("InsertHead"));
    m_insertHead->setFixedSize(70,25);

    m_insertTail = new QPushButton(tr("InsertTail"));
    m_insertTail->setFixedSize(70,25);



    m_oneDirector = new QPushButton(tr("Single"));
    m_oneDirector->setFixedSize(70,25);
    m_oneDirector->setCheckable(true);
    m_oneDirector->setChecked(true);

    m_twoDirector = new QPushButton(tr("Double"));
    m_twoDirector->setFixedSize(70,25);
    m_twoDirector->setCheckable(true);

    m_auto = new QPushButton("auto");
    m_auto->setCheckable(true);
    m_auto->setChecked(true);
    m_semiAuto = new QPushButton("semi-auto");
    m_semiAuto->setCheckable(true);
    m_man = new QPushButton("man");
    m_man->setCheckable(true);

    m_oneKey = new QPushButton("one-key");
    m_sysSetting = new QPushButton();
    m_sysSetting->setFixedSize(34,34);
    m_sysSetting->setObjectName("systemSetting");
    m_sysSetting->setToolTip(tr("System Setting"));
   // m_sysSetting->setStyleSheet("QPushButton{background-image:url(:/skin/sysSetting.png);border:none;}");
    m_luboSetting = new QPushButton();
    m_luboSetting->setObjectName("luboSetting");
    m_luboSetting->setToolTip(tr("Record Setting"));
    m_luboSetting->setFixedSize(34,34);

    m_modeGroup = new QButtonGroup();
    m_autoGroup = new QButtonGroup();

    toolLayout->setMargin(3);

    toolLayout->addWidget(m_insertHead);
    toolLayout->addStretch(1);
    toolLayout->addWidget(m_insertTail);
    toolLayout->addStretch(2);
    toolLayout->addWidget(m_oneDirector);
    toolLayout->addWidget(m_twoDirector);
    m_modeGroup->addButton(m_oneDirector);
    m_modeGroup->addButton(m_twoDirector);
    toolLayout->addStretch(2);

    toolLayout->addWidget(m_auto);
    toolLayout->addWidget(m_semiAuto);
    toolLayout->addWidget(m_man);
    m_autoGroup->addButton(m_auto);
    m_autoGroup->addButton(m_semiAuto);
    m_autoGroup->addButton(m_man);
    toolLayout->addStretch(2);

    toolLayout->addWidget(m_oneKey);
    toolLayout->addStretch(2);
    toolLayout->addWidget(m_luboSetting);
    toolLayout->addStretch(1);
    toolLayout->addWidget(m_sysSetting);
    toolLayout->setSpacing(0);

    m_setwin = new QSystemSettingWidget();
    m_setlubowin = new QLuboSettingWidget();
    // add event
    connect(m_sysSetting,SIGNAL(clicked()),this,SLOT(showSystemSetting()));
    connect(m_luboSetting,SIGNAL(clicked()),this,SLOT(showLuboSetting()));
    connect(m_insertHead,SIGNAL(clicked()),this,SLOT(insertHead()));
    connect(m_insertTail,SIGNAL(clicked()),this,SLOT(insertTail()));
    connect(m_oneDirector,SIGNAL(clicked()),this,SLOT(showSingle()));
    connect(m_twoDirector,SIGNAL(clicked()),this,SLOT(showDouble()));
    connect(m_auto,SIGNAL(clicked()),this,SLOT(showAuto()));
    connect(m_semiAuto,SIGNAL(clicked()),this,SLOT(showSemiAuto()));
    connect(m_man,SIGNAL(clicked()),this,SLOT(showHandle()));

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
//   QPropertyAnimation animotion(m_setwin,"pos");
//   animotion.setDuration(1000);
//   int x= (SCREEN_WIDTH-m_setwin->geometry().width())/2;
//   int y= (SCREEN_HEIGHT-m_setwin->geometry().height())/2;
//   animotion.setKeyValueAt(0,QPoint(SCREEN_WIDTH,SCREEN_HEIGHT));
//   animotion.setKeyValueAt(1,QPoint(0,0));
//   animotion.setEasingCurve(QEasingCurve::Linear);
//   animotion.start();
}

void MainWindow::showLuboSetting()
{
    m_setlubowin->show();
}


void MainWindow::insertHead()
{
    QMessageBox::warning(0,"","TODO",0,0);
}

void MainWindow::insertTail()
{
    QMessageBox::warning(0,"","TODO",0,0);
}
void MainWindow::showSingle()
{
    QMessageBox::warning(0,"","TODO",0,0);
}
void MainWindow::showDouble()
{
    QMessageBox::warning(0,"","TODO",0,0);
}
void MainWindow::showAuto()
{
    QMessageBox::warning(0,"","TODO",0,0);
}
void MainWindow::showSemiAuto()
{
    QMessageBox::warning(0,"","TODO",0,0);
}

void MainWindow::showHandle()
{
    QMessageBox::warning(0,"","TODO",0,0);
}
