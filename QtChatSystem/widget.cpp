#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_label = new QLabel("QtChatSystem", this);
    m_label->setGeometry(0,0,200,200);
    m_label->show();
}

Widget::~Widget()
{

}
