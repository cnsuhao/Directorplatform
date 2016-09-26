#include "View/QFunctionWidget.h"
#include <QPainter>



/**************************SUBPAGE****************************/

QBaseFun::QBaseFun(QWidget* parent):QWidget(parent)
{
   m_con = new QVBoxLayout();
   m_con->setSpacing(0);
   m_tab = new QTabWidget();
   m_con->addWidget(m_tab);
   this->setLayout(m_con);
//
  // AddPage(new QWidget(),"1");
}

QBaseFun::~QBaseFun()
{

}

void QBaseFun::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
}
void QBaseFun::AddPage(QWidget *widget,const QString& title)
{
    m_tab->addTab(widget,title);
}

//######################################################


QEffectFun::QEffectFun(QBaseFun* parent):QBaseFun(parent)
{
   AddPage(new QWidget(),"1");
   AddPage(new QWidget(),"2");
}

QEffectFun::~QEffectFun()
{

}

//######################################################

QVideoFun::QVideoFun(QBaseFun* parent):QBaseFun(parent)
{

}

QVideoFun::~QVideoFun()
{

}

//#####################################################
QLuboFun::QLuboFun(QBaseFun* parent):QBaseFun(parent)
{

}
QLuboFun::~QLuboFun()
{

}


//#####################################################

QStateFun::QStateFun(QBaseFun* parent):QBaseFun(parent)
{

}

QStateFun::~QStateFun()
{

}

/**********************************************************/





QFunctionWidget::QFunctionWidget(QWidget *parent) :
    QWidget(parent)
{
    m_con = new QHBoxLayout();
    m_effectFunWidget = new QEffectFun();
    m_videoFunWidget = new QVideoFun();
    m_luboFunWidget = new QLuboFun();
    m_stateFunWidget = new QStateFun();

    m_con->addWidget(m_effectFunWidget);
    m_con->addWidget(m_videoFunWidget);
    m_con->addWidget(m_luboFunWidget);
    m_con->addWidget(m_stateFunWidget);
    m_con->setSpacing(0);
    m_con->setMargin(0);
    this->setLayout(m_con);
}

void QFunctionWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor(37,44,52));
}
