#include "Model/QVideoWidget.h"

QVideoWidget::QVideoWidget(QWidget *parent) :
    QWidget(parent)
{
    /*default the background color is purge black*/
    bkcolor=QColor(0,0,0);
    /*the left button is not pressed */
    isPressed=false;
}

void QVideoWidget::setBackgroundColor(QColor color)
{
    bkcolor=color;
}

void QVideoWidget::paintEvent(QPaintEvent *event)
{
   QPainter p(this);
   p.fillRect(rect(),bkcolor);

   if(isPressed &&!isFullScreen())
   {
       p.setPen(QPen(QColor(0, 255, 0), 3));
       p.drawRect(rect());
   }
}

void QVideoWidget::mousePressEvent(QMouseEvent *event)
{
  if(event->button()==Qt::LeftButton)
  {

      if(event->type()==QEvent::MouseButtonPress)
      {
          isPressed=!isPressed;
          if(isPressed)
          {
              emit cocoSelected(this);
          }
      }
      else if(event->type()==QEvent::MouseButtonDblClick)
      {
          fullVideoScreen();
      }
      this->update();

  }
  else if(event->button()==Qt::RightButton)
  {

  }
  else if(event->button()==Qt::MidButton)
  {

  }
  else
      QWidget::mousePressEvent(event);
}

void QVideoWidget::fullVideoScreen()
{
    if(this->isFullScreen())
    {
        this->setWindowFlags(Qt::SubWindow);
        this->showNormal();
    }
    else
    {
       this->setWindowFlags(Qt::Dialog);
       this->showFullScreen();
    }
}
