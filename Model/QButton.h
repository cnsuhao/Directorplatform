#ifndef QBUTTON_H
#define QBUTTON_H

#include <QPushButton>
#include <QString>
#include <QIcon>
#include <QWidget>
#include "View/PlatformConfig.h"

class QButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QButton(QWidget *parent = 0);
    explicit QButton(const QString &text, QWidget *parent=0);
    QButton(const QIcon& icon, const QString &text, QWidget *parent=0);
    EventCall click;
    EventCall dbclick;
    EventCall mouseenter;
    EventCall mouseleave;
    EventCall lbuttondown;
    EventCall lbuttonup;
    EventCall rbuttondown;
    QWidget  *wid;
signals:

public slots:
protected:
     void mouseReleaseEvent(QMouseEvent *event);
     void mousePressEvent(QMouseEvent *event);

     bool event(QEvent *e);

};

#endif // QBUTTON_H


//None = 0,                               // invalid event
//Timer = 1,                              // timer event
//MouseButtonPress = 2,                   // mouse button pressed
//MouseButtonRelease = 3,                 // mouse button released
//MouseButtonDblClick = 4,                // mouse button double click
//MouseMove = 5,                          // mouse move
//KeyPress = 6,                           // key pressed
//KeyRelease = 7,                         // key released
//FocusIn = 8,                            // keyboard focus received
//FocusOut = 9,                           // keyboard focus lost
//Enter = 10,                             // mouse enters widget
//Leave = 11,                             // mouse leaves widget
//Paint = 12,                             // paint widget
//Move = 13,                              // move widget
//Resize = 14,                            // resize widget
//Create = 15,                            // after widget creation
//Destroy = 16,                           // during widget destruction
//Show = 17,                              // widget is shown
//Hide = 18,                              // widget is hidden
//Close = 19,                             // request to close widget
//Quit = 20,                              // request to quit application
//ParentChange = 21,                      // widget has been reparented
//ParentAboutToChange = 131,              // sent just before the parent change is done
