#include "View/QFunctionWidget.h"
#include <QPainter>



/**************************SUBPAGE****************************/

QBaseFun::QBaseFun(QWidget* parent):QWidget(parent)
{

}

QBaseFun::~QBaseFun()
{

}

void QBaseFun::paintEvent(QPaintEvent *event)
{

}

//######################################################


QEffectFun::QEffectFun(QBaseFun* parent):QBaseFun(parent)
{

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
}

void QFunctionWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor("yellow"));
}
