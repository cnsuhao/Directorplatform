#ifndef QVIDEOWIDGET_H
#define QVIDEOWIDGET_H

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QMouseEvent>

/*************************************************************
 *       Video Widget
 *************************************************************
 *
 *  Author         :Yoohoo   wand_niu@live.com   2016-9-9
 *
 *
 *  This class only use to play or display video,if your want
 *  get HWND which it is from winId().
 *
 *
 *
 ***************************************************************/



class QVideoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QVideoWidget(QWidget *parent = 0);
    virtual void setBackgroundColor(QColor color);
signals:
     void cocoSelected(QVideoWidget*);
public slots:


public:
    /*record the mouse left button is pressed ?*/
    bool   isPressed;
protected:
    QColor bkcolor;
protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);
public:
    void fullVideoScreen();
};

#endif // QVIDEOWIDGET_H

















