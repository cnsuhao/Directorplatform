#include "Model/QButton.h"
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
    wid=parent;

    if(wid==NULL)
        wid=this;
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
    wid=parent;
    if(wid==NULL)
        wid=this;
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
    wid=parent;
    if(wid==NULL)
        wid=this;
}


void QButton::mouseReleaseEvent(QMouseEvent *event)
{
    QPushButton::mouseReleaseEvent(event);
    if(event->button()==Qt::LeftButton)
    {
        if(click)
        {
            click(wid);
        }
        if(lbuttonup)
        {
            lbuttonup(wid);
        }
    }
}


bool QButton::event(QEvent *e)
{
    if(e->type()==QEvent::MouseButtonDblClick)
    {

        if(dbclick)
        {
            dbclick(wid);
        }
       return true;
    }
    else if(e->type()==QEvent::Enter)
    {
        if(mouseenter)
        {
            mouseenter(wid);
        }
        return true;
    }
    else if(e->type()==QEvent::Leave)
    {
        if(mouseleave)
        {
            mouseleave(wid);
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
            lbuttondown(wid);
        }
    }
    if(event->button()==Qt::RightButton)
    {
        if(rbuttondown)
        {
            rbuttondown(wid);
        }
    }
}
