#ifndef QFUNCTIONWIDGET_H
#define QFUNCTIONWIDGET_H

/*下方功能区*/

#include <QWidget>

class QFunctionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QFunctionWidget(QWidget *parent = 0);

signals:

public slots:
protected:
    void paintEvent(QPaintEvent* event);

};

#endif // QFUNCTIONWIDGET_H
