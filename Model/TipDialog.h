#ifndef TIPDIALOG_H
#define TIPDIALOG_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDialog>
#include <QPainter>
#include <QPaintEvent>
#include <QMovie>


/**
 * @brief The TipDialog class
 *
 * @info 消息提示对话框,可以加入按钮 OK CANNEL EXIT 用做对话狂提示，并且得到相应的返回选择按钮
 *
 *
 * @author Yoohoo         @date 2016-10-10
 */


class TipDialog : public QDialog
{
    Q_OBJECT
public:
    enum Type
    {
        None=0x0,
        OK=0x1,
        Cannel=0x2,
        Exit=0x4
    };
    explicit TipDialog(QDialog *parent = 0);
    TipDialog(int btnStyle=OK|Cannel,QDialog*parent=0);
    virtual ~TipDialog();
    virtual void setTipTitle(const QString &title);
    virtual void setTipInfoText(const QString &txt);
    virtual int  showDialog();
    virtual int  getCode();
    virtual void loadMovie(const QString &fileName);

signals:

public slots:
    void clickedOK();
    void clickedCannel();
    void clickedExit();
private:
    void setBtnEnabled(int btnStyle);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    QPushButton     *m_btnOK,*m_btnCannel,*m_btnExit;
    QLabel          *m_title,*m_txt;
    QVBoxLayout     *m_con;
    QHBoxLayout     *m_btnLay;
    int             code;
    QPoint          oldPoint;
    bool            canMove;


};

#endif // TIPDIALOG_H
