#include "widget.h"

Widget::Widget(chatEreaCtrl *buff, QWidget *parent)
    : QWidget(parent)
{
    m_buffer = buff;
    m_edtChatErea = new QTextEdit(this);
    m_btnTrans = new QPushButton("送信", this);
    m_edtText = new QTextEdit(this);
    m_layH = new QHBoxLayout();
    m_layV = new QVBoxLayout(this);
    m_edtChatErea->setPalette(QPalette(QColor(250,250,250)));
    m_edtChatErea->setAutoFillBackground(true);
    m_edtChatErea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_edtChatErea->setAlignment(Qt::AlignBottom);
    m_edtChatErea->setReadOnly(true);
    m_btnTrans->setFixedSize(100,50);
    m_edtText->setFixedHeight(50);
    m_edtText->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_edtChatErea->show();
    m_btnTrans->show();
    m_edtText->show();

    m_layH->addWidget(m_btnTrans);
    m_layH->addWidget(m_edtText);
    m_layV->addWidget(m_edtChatErea);
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
        m_buffer->write("自分", m_edtText->toPlainText());
        m_edtText->clear();
    }
}

void Widget::strChanged()
{
    chatEreaCtrl::CHAT_ALL_INFO info;
    QTextCursor cursor(m_edtChatErea->textCursor());
    QTextTableFormat tableFormat;
    tableFormat.setBorder(0);

    //Clear ChatErea
    m_edtChatErea->clear();
    //Get all ChatLog
    info = m_buffer->read();
    //Redraw all ChatLog
    for(int i=0; i<info.list.count(); i++)
    {
        cursor.movePosition(QTextCursor::End);
        QTextTable *table = cursor.insertTable(1,3,tableFormat);
        QString time = info.list[i].time.date().toString("yyyy/MM/dd ");
        time += info.list[i].time.time().toString("hh:mm:ss");
        table->cellAt(0, 0).firstCursorPosition().insertText("[" + time + "]");
        table->cellAt(0, 1).firstCursorPosition().insertText("<" + info.list[i].name + ">");
        table->cellAt(0, 2).firstCursorPosition().insertText(info.list[i].str);
    }
    //scroll bottom
    m_edtChatErea->verticalScrollBar()->setSliderPosition(m_edtChatErea->verticalScrollBar()->maximum());
}
