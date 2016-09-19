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
     * @brief: onMove
     *
     * when load windows to execute
     */
    virtual void onMove()=0;
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
     * @brief setVisible
     * @param visible
     *
     * set window visible
     */
    virtual void setVisible(bool visible=false)=0;
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
     * @brief onSizeChange
     */
    virtual void onSizeChange()=0;
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














class QYoohooMainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit QYoohooMainWindow(QWidget *parent = 0);

signals:

public slots:
public:




};

#endif // QYOOHOOMAINWINDOW_H
