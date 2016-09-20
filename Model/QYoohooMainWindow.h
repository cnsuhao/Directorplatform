#ifndef QYOOHOOMAINWINDOW_H
#define QYOOHOOMAINWINDOW_H

#include <QWidget>


/**
 * @brief: IWindowEvent is the Interface of windows event
 */

class IWindowEvent
{
    /**
     * @brief: onLoad
     *
     * when init windows to execute
     */
    virtual void onLoad()=0;
    /**
     * @brief: setTitle
     * @param title
     *
     * Set the title of the title bar
     */
    virtual void setTitle(QString &title)=0;
    /**
     * @brief setTitleHeight
     * @param width
     *
     * Set the height of the title bar
     */
    virtual void setTitleHeight(uint width=30)=0;
    /**
     * @brief setBorderWidth
     * @param height
     *
     * Set the width of the border
     */
    virtual void setBorderWidth(uint height=2)=0;
    /**
     * @brief onClose
     *
     * when windows close to execute
     */
    virtual void onClose()=0;
    /**
     * @brief onShow
     *
     * show the window
     */
    virtual void onShow()=0;
    /**
     * @brief onHide
     *
     * hide the window
     */
    virtual void onHide()=0;
    /**
     * @brief onSizeChanged
     */
    virtual void onSizeChanged()=0;
    /**
     * @brief onMoved
     */
    virtual void onMoved()=0;
    /**
     * @brief onMaxSize
     */
    virtual void onMaxSize()=0;
    /**
     * @brief onMiniSize
     */
    virtual void onMiniSize()=0;
    /**
     * @brief onRestore
     */
    virtual void onRestore()=0;

};














class QYoohooMainWindow : public QWidget ,public IWindowEvent
{
    Q_OBJECT
public:
    explicit QYoohooMainWindow(QWidget *parent = 0);
    virtual void onLoad();
    virtual void setTitle(QString &title);
    virtual void setTitleHeight(uint width=30);
    virtual void setBorderWidth(uint height=2);
    virtual void onClose();
    virtual void onShow();
    virtual void onHide();
    virtual void onSizeChanged();
    virtual void onMoved();
    virtual void onMaxSize();
    virtual void onMiniSize();
    virtual void onRestore();
signals:

public slots:
private:
    QPoint m_mousePoint;
    bool  m_needMove;
 protected:
    void mouseMoveEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);


protected:
     QString m_title;






};

#endif // QYOOHOOMAINWINDOW_H
