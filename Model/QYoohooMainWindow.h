#ifndef QYOOHOOMAINWINDOW_H
#define QYOOHOOMAINWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

/**
 * @brief: IWindowEvent is the Interface of windows event
 */

class IWindowEvent
{
public:
    virtual void onCreate()=0;
    virtual void setTitle(QString &title)=0;
    virtual void setTitleHeight(uint height=30)=0;
    virtual void setBorderWidth(uint width=2)=0;
    virtual void onClose()=0;
    virtual void onSizeChanged()=0;
    virtual void onMoved()=0;
    virtual void onMaxSize()=0;
    virtual void onMiniSize()=0;
    virtual void onRestore()=0;

};




class QYoohooMainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit QYoohooMainWindow(QWidget *parent = 0);
signals:

public:
    void addWidgetToYoohoo(QWidget* w);
    void setTitleToYoohoo(const QString &title);
private:

    bool onLeft;
    bool onRight;
    bool onBottom;
    bool onLeftBottom;
    bool onRightBottom;

    QPoint m_mousePoint;
    bool  m_canDrag;
    bool m_isPressed;
    bool m_isFull;
    bool m_canExp;
    int  titieHeight;
    int  borderWidth;
    QLabel *m_labTitle;
    QPushButton *close_btn;
    QPushButton *mini_btn;
    QPushButton *max_btn;
    QHBoxLayout *m_titleLayout;
    QVBoxLayout *m_mainLayout;
    QVBoxLayout *m_con;

protected:
    bool eventFilter(QObject *, QEvent *);
    void onclose(QObject *obj);
    void onminisize(QObject *obj);
    void onmaxsize(QObject *obj);
private:
    void mouseMove(QMouseEvent* e);
    void mousePress(QMouseEvent* e);
    void mousedbClicked(QMouseEvent* e);
    void mouseRelease(QMouseEvent* e);
    void mouseEnter(QMouseEvent* e);
    void mouseHoverEnter(QHoverEvent* e);
    void mouseHoverMove(QHoverEvent* e);
    void mouseLeave(QMouseEvent* e);
    void paintEvent(QPaintEvent* e);
    void PaintBtn(QObject* obj);

protected:
     QString m_title;

};

#endif // QYOOHOOMAINWINDOW_H
