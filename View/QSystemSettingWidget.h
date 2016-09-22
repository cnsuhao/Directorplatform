#ifndef QSYSTEMSETTINGWIDGET_H
#define QSYSTEMSETTINGWIDGET_H

#include <QWidget>
#include <QTabWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

/********************************************
 * QSystemSettingWidget class
 ********************************************
 *
 *  use to make system setting page
 *
 */



class QSettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QSettingWidget(QWidget *parent = 0);
    ~QSettingWidget();
signals:

protected:
    QLabel*                         m_labTitle;
    QTabWidget*                     m_mainTab;
    QHBoxLayout*                    m_titleLay;
    QHBoxLayout*                    m_dlgLay;
    QVBoxLayout*                    m_con;

    QPushButton*                    m_okBtn;
    QPushButton*                    m_applyBtn;
    QPushButton*                    m_cannelBtn;
private:
    QLabel*             emptyLab;
    bool canMove;
    QPoint oldPoint;
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
public:
    virtual void SetTitle(const QString &title);
public slots:
    virtual void clicked_OK();
    virtual void clicked_Apply();
    virtual void clicked_Cannel();
protected:
    virtual void paintEvent(QPaintEvent* event);
};








class QSystemSettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QSystemSettingWidget(QWidget *parent = 0);

signals:

private:


public slots:

};

#endif // QSYSTEMSETINGWIDGET_H
