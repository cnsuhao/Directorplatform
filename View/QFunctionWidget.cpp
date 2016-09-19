#include "View/QFunctionWidget.h"
#include <QPainter>

QFunctionWidget::QFunctionWidget(QWidget *parent) :
    QWidget(parent)
{
}

void QFunctionWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor("yellow"));
}
