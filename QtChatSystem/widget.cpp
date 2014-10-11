#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_seguchi = new QLabel("seguchi", this);
    m_seguchi->setGeometry(0,0,200,200);
    m_seguchi->show();
}

Widget::~Widget()
{

}
