#include "widget.h"

Widget::Widget(chatEreaCtrl *buff, QWidget *parent)
    : QWidget(parent)
{
    m_buffer = buff;
    m_lblChatErea = new QLabel("");
    m_btnTrans = new QPushButton("送信", this);
    m_edtText = new QTextEdit(this);
    m_layH = new QHBoxLayout();
    m_layV = new QVBoxLayout(this);
    m_scrlErea = new QScrollArea(this);
    m_lblChatErea->setPalette(QPalette(QColor(250,250,250)));
    m_lblChatErea->setAutoFillBackground(true);
    m_lblChatErea->setFixedHeight(1080);
    m_lblChatErea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    m_lblChatErea->setAlignment(Qt::AlignBottom);
    m_btnTrans->setFixedSize(100,50);
    m_edtText->setFixedHeight(50);
    m_edtText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_scrlErea->setWidget(m_lblChatErea);
    m_scrlErea->setWidgetResizable(true);
    m_lblChatErea->show();
    m_btnTrans->show();
    m_edtText->show();
    m_scrlErea->show();

    m_layH->addWidget(m_btnTrans);
    m_layH->addWidget(m_edtText);
    m_layV->addWidget(m_scrlErea);
    m_layV->addLayout(m_layH);

    connect(m_btnTrans, SIGNAL(clicked()), this, SLOT(pushedTrans()));
    connect(m_buffer, SIGNAL(strChanged()), this, SLOT(strChanged()));
}

Widget::~Widget()
{

}

void Widget::pushedTrans()
{
    if(m_edtText->toPlainText().length() != 0)
    {
        m_buffer->write(QString("自分 : ") + m_edtText->toPlainText() + QString("\n"));
        m_edtText->clear();
    }
}

void Widget::strChanged()
{
    m_lblChatErea->setText(m_buffer->read());
    m_scrlErea->verticalScrollBar()->setSliderPosition(m_scrlErea->verticalScrollBar()->maximum());
}
