#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_lblChatErea = new QLabel("", this);
    m_btnTrans = new QPushButton("送信", this);
    m_edtText = new QTextEdit(this);
    m_layH = new QHBoxLayout();
    m_layV = new QVBoxLayout(this);
    m_lblChatErea->setPalette(QPalette(QColor(250,250,250)));
    m_lblChatErea->setAutoFillBackground(true);
    m_lblChatErea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_btnTrans->setFixedSize(100,50);
    m_edtText->setFixedHeight(50);
    m_edtText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_lblChatErea->show();
    m_btnTrans->show();
    m_edtText->show();

    m_layH->addWidget(m_btnTrans);
    m_layH->addWidget(m_edtText);
    m_layV->addWidget(m_lblChatErea);
    m_layV->addLayout(m_layH);

    connect(m_btnTrans, SIGNAL(clicked()), this, SLOT(pushedTrans()));
}

Widget::~Widget()
{

}

void Widget::pushedTrans()
{
    if(m_edtText->toPlainText().length() != 0)
    {
        m_strBuffer += "自分 : " + m_edtText->toPlainText() + QString("\n");
        m_edtText->clear();
    }
    m_lblChatErea->setText(m_strBuffer);
}
