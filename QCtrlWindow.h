#ifndef QCTRLWINDOW_H
#define QCTRLWINDOW_H

#include <QWidget>
#include <QGridLayout>
/*
 *  this widget control windows operator */



class QCtrlWindow : public QWidget
{
    Q_OBJECT
public:
    explicit QCtrlWindow(QWidget *parent = 0);

signals:

public slots:
private:
    QGridLayout *m_gridLayout;


};

#endif // QCTRLWINDOW_H
