#include "QCtrlWindow.h"
#include <QPainter>
QCtrlWindow::QCtrlWindow(QWidget *parent) :
    QWidget(parent)
{

}
void QCtrlWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.fillRect(rect(),QColor("green"));
}
