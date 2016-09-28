#include "QYoohooMainWindow.h"

#include <QMouseEvent>
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QApplication>
#include <QPainter>
#include <QBitmap>
#define log(...)                      printf(__VA_ARGS__);

QYoohooMainWindow::QYoohooMainWindow(QWidget *parent) :
    QWidget(parent)
{
    onLeft=onRight=onBottom=onLeftBottom=onRightBottom=false;
    m_canDrag = false;
    m_canExp = false;
    m_isPressed = false;
    m_isFull = false;
    titieHeight = 30;
    borderWidth = 5;
    m_labTitle = new QLabel(this);
    m_titleLayout = new QHBoxLayout();
    m_labTitle->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    m_mainLayout = new QVBoxLayout();
    m_mainLayout->setSpacing(0);
    m_mainLayout->setMargin(0);
    m_con = new QVBoxLayout();
    m_con->setSpacing(0);
    m_con->setMargin(0);


    close_btn = new QPushButton(this);
    close_btn->setFixedSize(20,20);
    close_btn->setStyleSheet("QPushButton{border-radius:10px;background:rgb(227,89,42);}");
    close_btn->setToolTip(tr("close"));
    mini_btn = new QPushButton(this);
    mini_btn->setFixedSize(20,20);
    mini_btn->setToolTip(tr("minisize"));
    mini_btn->setStyleSheet("QPushButton{border-radius:10px;background:rgb(218,165,32);}");
    max_btn = new QPushButton(this);
    max_btn->setFixedSize(20,20);
    max_btn->setToolTip(tr("maxsize"));
    max_btn->setStyleSheet("QPushButton{border-radius:10px;background:rgb(50,205,50);}");

    connect(close_btn,SIGNAL(clicked()),this,SLOT(close()));
    connect(mini_btn,SIGNAL(clicked()),this,SLOT(showMinimized()));
    connect(max_btn,SIGNAL(clicked()),this,SLOT(onmaxsize()));
    m_titleLayout->setSpacing(1);
    m_titleLayout->setMargin(5);
    m_labTitle->setText("QYoohooMainWindow");
    m_labTitle->setFixedHeight(titieHeight-9);
    m_titleLayout->addWidget(m_labTitle,3,Qt::AlignLeft|Qt::AlignTop);
    m_titleLayout->addWidget(mini_btn,0,Qt::AlignLeft|Qt::AlignTop);
    m_titleLayout->addWidget(max_btn,0,Qt::AlignLeft|Qt::AlignTop);
    m_titleLayout->addWidget(close_btn,0,Qt::AlignLeft|Qt::AlignTop);
    m_con->addLayout(m_titleLayout,0);
    m_con->addLayout(m_mainLayout,20);
    this->setLayout(m_con);
    this->setWindowFlags(Qt::FramelessWindowHint );

    this->installEventFilter(this);
    this->setAttribute(Qt::WA_Hover,true);

}

QYoohooMainWindow::~QYoohooMainWindow()
{
    delete m_labTitle;
    m_labTitle = NULL;
    delete close_btn;
    close_btn = NULL;
    delete mini_btn;
    mini_btn = NULL;
    delete max_btn;
    max_btn = NULL;
    delete m_titleLayout;
    delete m_mainLayout;
    delete m_con;
}

void QYoohooMainWindow::onmaxsize()
{
        if(isFullScreen())
        {
            showNormal();
        }
        else
        {
            showFullScreen();
        }

}


void QYoohooMainWindow::mousePress(QMouseEvent *e)
{
    if(e->buttons()==Qt::LeftButton)
    {
        m_isPressed = true;
        if(e->pos().y()<=titieHeight)
        {
            m_canDrag = true;
        }

        if(onLeft||onRight||onLeftBottom||onRightBottom)
        {
            m_canExp = true;
        }
        m_mousePoint = e->pos();
    }

}

void QYoohooMainWindow::mouseRelease(QMouseEvent *e)
{
    m_isPressed = false;
    m_canDrag = false;
    m_canExp = false;
}

void QYoohooMainWindow::mouseMove(QMouseEvent *e)
{

    if(m_canDrag&&(e->globalPos()-m_mousePoint).manhattanLength()>QApplication::startDragDistance())
    {
        move(e->globalPos()-m_mousePoint);
        m_mousePoint = e->globalPos()-pos();
        return ;
    }
    else if(m_canExp)
    {
         QRect r=this->geometry();
        if(onLeft)
        {
            r.setLeft(e->globalPos().x());
            setGeometry(r);
        }
        else if(onRight)
        {
            r.setRight(e->globalPos().x());
            setGeometry(r);
        }
        else if(onBottom)
        {
            r.setBottom(e->globalPos().y());
            setGeometry(r);
        }
        else if(onLeftBottom)
        {
            r.setBottomLeft(e->globalPos());
            setGeometry(r);

        }
        else if(onRightBottom)
        {
           r.setBottomRight(e->globalPos());
           setGeometry(r);
        }


    }
}
/**
 * @brief mouseHoverEnter
 *
 * use to update mouse status
 *
 */
void QYoohooMainWindow::mouseHoverEnter(QHoverEvent *e)
{
    if((e->pos().x()<=borderWidth||e->pos().x()>=rect().width()-borderWidth)&&e->pos().y()>titieHeight&&e->pos().y()<rect().height()-10)
    {
        setCursor(Qt::SizeHorCursor);
        onLeft =true;onRight=false;onLeftBottom=false;onRightBottom=false;
    }
    else if(e->pos().y()>=rect().height()-10&& e->pos().x()>borderWidth&&e->pos().x()<rect().width()-10)
    {
         setCursor(Qt::SizeVerCursor);
         onLeft =false;onRight=true;onLeftBottom=false;onRightBottom=false;
    }
    else if(e->pos().x()<borderWidth &&e->pos().y()>rect().height()-10)
    {
        setCursor(Qt::SizeBDiagCursor);
        onLeft =false;onRight=false;onLeftBottom=true;onRightBottom=false;
    }
    else if(e->pos().x()>rect().width()-10 && e->pos().y()>rect().height()-10)
    {
        setCursor(Qt::SizeFDiagCursor);
        onLeft =false;onRight=false;onLeftBottom=false;onRightBottom=true;
    }
    else
    {
       setCursor(Qt::ArrowCursor);
       onLeft =false;onRight=false;onLeftBottom=false;onRightBottom=false;
    }

    update();
}
void QYoohooMainWindow::mouseHoverMove(QHoverEvent *e)
{
   if(e->pos().x()>10 && e->pos().y()<rect().height()-10 && e->pos().x()<rect().width()-10)
   {
      setCursor(Qt::ArrowCursor);
   }

}
void QYoohooMainWindow::mouseEnter(QMouseEvent *e)
{

}

void QYoohooMainWindow::mousedbClicked(QMouseEvent *e)
{
  if(e->pos().y()<titieHeight)
  {
    if(!m_isFull)
    {
        this->showFullScreen();
    }
    else
    {
        this->showNormal();
    }
    m_isFull =!m_isFull;
  }
}

/**
 * @brief QYoohooMainWindow::eventFilter
 * @param obj
 * @param e
 * @return
 *
 *  event filter to deal event
 */
bool QYoohooMainWindow::eventFilter(QObject *obj, QEvent *e)
{
    switch (e->type()) {
    case QEvent::MouseButtonPress:
        mousePress(static_cast<QMouseEvent*>(e));
        break;
    case QEvent::MouseMove:
        mouseMove(static_cast<QMouseEvent*>(e));
        break;
    case QEvent::MouseButtonRelease:
        mouseRelease(static_cast<QMouseEvent*>(e));
        break;
    case QEvent::Enter:
        mouseEnter(static_cast<QMouseEvent*>(e));
        break;
    case QEvent::MouseButtonDblClick:
        mousedbClicked(static_cast<QMouseEvent*>(e));
        break;
    case QEvent::HoverEnter:
        mouseHoverEnter(static_cast<QHoverEvent*>(e));
        break;
    case QEvent::HoverMove:
        mouseHoverMove(static_cast<QHoverEvent*>(e));
        break;
    default:
        return QWidget::eventFilter(obj,e);
        break;
    }
    return true;
}


void QYoohooMainWindow::paintEvent(QPaintEvent *e)
{
      QPainter p(this);
      QRect r=rect();
      r.setBottom(r.top()+titieHeight);
      p.setPen(QColor("red"));
      QRectF lrf(0.0,0.0,18.0,18.0);
      p.fillRect(r,QColor(75,73,67,255));

      if(!isMaximized())
      {
          QPainterPath path;
          path.addRoundRect(rect(),2,2);
          QPolygon polygon= path.toFillPolygon().toPolygon();
          QRegion region(polygon);
          setMask(region);
          p.setPen(QColor(75,73,67,255));
          p.drawRoundedRect(0,0,width()-1,height()-1,8,8);

      }
      update();
}

void QYoohooMainWindow::addWidgetToYoohoo(QWidget *w)
{
    m_mainLayout->addWidget(w);
}

void QYoohooMainWindow::setTitleToYoohoo(const QString &title)
{
    m_labTitle->setText(title);
}
void QYoohooMainWindow::PaintBtn(QObject *obj)
{
    if(obj==close_btn)
    {
        QRect r= close_btn->rect();
        QPainter p(close_btn);
        p.drawLine(QPoint(0,0),QPoint(20,20));
    }
}
