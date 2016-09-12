#include "QButton.h"
#include <QMessageBox>
#include <QMouseEvent>
QButton::QButton(QWidget *parent) :
    QPushButton(parent)
{
    click=NULL;
    dbclick=NULL;
    mouseenter=NULL;
    mouseleave=NULL;
    lbuttondown=NULL;
    lbuttonup=NULL;
    rbuttondown=NULL;
}
QButton::QButton(const QString &text, QWidget *parent):QPushButton(text,parent)
{
    click=NULL;
    dbclick=NULL;
    mouseenter=NULL;
    mouseleave=NULL;
    lbuttondown=NULL;
    lbuttonup=NULL;
    rbuttondown=NULL;
}
QButton::QButton(const QIcon& icon, const QString &text, QWidget *parent):
    QPushButton(icon,text,parent)
{
    click=NULL;
    dbclick=NULL;
    mouseenter=NULL;
    mouseleave=NULL;
    lbuttondown=NULL;
    lbuttonup=NULL;
    rbuttondown=NULL;
}


void QButton::mouseReleaseEvent(QMouseEvent *event)
{
    QPushButton::mouseReleaseEvent(event);
    if(event->button()==Qt::LeftButton)
    {
        if(click)
        {
            click();
        }
        if(lbuttonup)
        {
            lbuttonup();
        }
    }
}


bool QButton::event(QEvent *e)
{
    if(e->type()==QEvent::MouseButtonDblClick)
    {

        if(dbclick)
        {
            dbclick();
        }
       return true;
    }
    else if(e->type()==QEvent::Enter)
    {
        if(mouseenter)
        {
            mouseenter();
        }
        return true;
    }
    else if(e->type()==QEvent::Leave)
    {
        if(mouseleave)
        {
            mouseleave();
        }
    }
    else
    {
          return QPushButton::event(e);
    }

}

void QButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        if(lbuttondown)
        {
            lbuttondown();
        }
    }
    if(event->button()==Qt::RightButton)
    {
        if(rbuttondown)
        {
            rbuttondown();
        }
    }
}
