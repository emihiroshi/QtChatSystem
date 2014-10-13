#ifndef WIDGET_H
#define WIDGET_H

#include "chatereactrl.h"
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLayout>
#include <QScrollBar>
#include <QTextTable>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(chatEreaCtrl *buff, QWidget *parent = 0);
    ~Widget();

public slots:
    void pushedTrans(void);
    void strChanged(void);

protected:
    QHBoxLayout *m_layH;
    QVBoxLayout *m_layV;
    QTextEdit *m_edtChatErea;
    QPushButton *m_btnTrans;
    QTextEdit *m_edtText;
    chatEreaCtrl *m_buffer;
};

#endif // WIDGET_H
