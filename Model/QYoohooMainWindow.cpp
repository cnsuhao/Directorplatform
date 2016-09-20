#include "QYoohooMainWindow.h"

#include <QMouseEvent>
#include <QApplication>

QYoohooMainWindow::QYoohooMainWindow(QWidget *parent) :
    QWidget(parent)
{
    m_needMove = false;

}


void QYoohooMainWindow::onLoad()
{

}

void QYoohooMainWindow::onMoved()
{

}

void QYoohooMainWindow::setTitle(QString &title)
{
    m_title = title;
}
void QYoohooMainWindow::setTitleHeight(uint height)
{

}
void QYoohooMainWindow::setBorderWidth(uint width)
{

}

void QYoohooMainWindow::onClose()
{
    this->close();
}

void QYoohooMainWindow::onShow()
{
    this->show();
}

void QYoohooMainWindow::onHide()
{
    this->hide();
}

void QYoohooMainWindow::onSizeChanged()
{

}

void QYoohooMainWindow::onMaxSize()
{

}

void QYoohooMainWindow::onMiniSize()
{

}
void QYoohooMainWindow::onRestore()
{

}


void QYoohooMainWindow::mouseMoveEvent(QMouseEvent* e)
{

    if(m_needMove &&(e->buttons()==Qt::LeftButton) &&(e->globalPos()-m_mousePoint).manhattanLength()>QApplication::startDragDistance())
    {
        move(e->globalPos()-m_mousePoint);
        m_mousePoint=e->globalPos()-pos();
    }


    return QWidget::mouseMoveEvent(e);

}
void QYoohooMainWindow::mouseReleaseEvent(QMouseEvent *e)
{
m_needMove=false;
}
void QYoohooMainWindow::mousePressEvent(QMouseEvent *e)
{
    m_needMove=true;

    m_mousePoint=e->globalPos()-pos();
        return QWidget::mousePressEvent(e);
}
