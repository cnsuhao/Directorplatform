#include "QSystemSettingWidget.h"
#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>


QSettingWidget::QSettingWidget(QWidget *parent) :
    QWidget(parent),canMove(false)
{
    m_labTitle = new QLabel("SettingWidget");
    m_labTitle->setFixedHeight(30);
    m_mainTab = new QTabWidget();
    m_titleLay = new QHBoxLayout();
    m_dlgLay = new QHBoxLayout();
    m_con = new QVBoxLayout();
    m_con->setMargin(0);


    emptyLab = new QLabel();

    m_okBtn = new QPushButton(tr("Ok"));
    m_applyBtn = new QPushButton(tr("Apply"));
    m_cannelBtn = new QPushButton(tr("Cannel"));

    m_titleLay->addWidget(m_labTitle,2,Qt::AlignTop|Qt::AlignHCenter);
    m_dlgLay->addWidget(emptyLab,10);
    m_dlgLay->addWidget(m_okBtn,0,Qt::AlignTop);
    m_dlgLay->addWidget(m_applyBtn,0,Qt::AlignTop);
    m_dlgLay->addWidget(m_cannelBtn,0,Qt::AlignTop);
    m_dlgLay->addStretch(1);
    m_okBtn->setFixedWidth(45);
    m_applyBtn->setFixedWidth(45);
    m_cannelBtn->setFixedWidth(45);
    m_dlgLay->setSpacing(20);
    m_dlgLay->setMargin(0);
    m_con->addLayout(m_titleLay);
    m_con->addWidget(m_mainTab,20);
    m_con->addLayout(m_dlgLay);


    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setLayout(m_con);
    this->resize(680,480);


    connect(m_okBtn,SIGNAL(clicked()),this,SLOT(clicked_OK()));
    connect(m_applyBtn,SIGNAL(clicked()),this,SLOT(clicked_Apply()));
    connect(m_cannelBtn,SIGNAL(clicked()),this,SLOT(clicked_Cannel()));

}

QSettingWidget::~QSettingWidget()
{

}

void QSettingWidget::SetTitle(const QString &title)
{
    m_labTitle->setText(title);
}

void QSettingWidget::clicked_OK()
{

    QMessageBox::warning(0,"tip","you select ok",0,0);
    close();
}

void QSettingWidget::clicked_Apply()
{
    QMessageBox::warning(0,"tip","you select Apply",0,0);

}

void QSettingWidget::clicked_Cannel()
{
    QMessageBox::warning(0,"tip","you select Cannel",0,0);
    close();

}

void QSettingWidget::paintEvent(QPaintEvent *event)
{
    //draw title bar
    QPainter painter(this);
    QRect rectTitle=rect();
    rectTitle.setHeight(30);
    painter.fillRect(rectTitle,QColor(75,73,67));

    QPainterPath path;
    path.addRoundRect(rect(),2,2);
    QPolygon polygon= path.toFillPolygon().toPolygon();
    QRegion region(polygon);
    setMask(region);
}

void QSettingWidget::mousePressEvent(QMouseEvent *event)
{
   if(event->buttons()==Qt::LeftButton && event->pos().y()<30)
   {
       canMove = true;
       oldPoint = event->globalPos()-pos();
   }
}

void QSettingWidget::mouseReleaseEvent(QMouseEvent *event)
{
   canMove = false;
}

void QSettingWidget::mouseMoveEvent(QMouseEvent *event)
{
   if(canMove)
   {
       move(event->globalPos()-oldPoint);
       oldPoint = event->globalPos()-pos();
   }
}





/********************************************************************/



QSystemSettingWidget::QSystemSettingWidget(QWidget *parent) :
    QWidget(parent)
{
}
