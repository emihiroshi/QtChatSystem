#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>]

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

protected:
    QLabel *m_seguchi;
};

#endif // WIDGET_H
