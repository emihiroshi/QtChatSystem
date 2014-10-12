#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void pushedTrans(void);

protected:
    QHBoxLayout *m_layH;
    QVBoxLayout *m_layV;
    QString m_strBuffer;
    QLabel *m_lblChatErea;
    QPushButton *m_btnTrans;
    QTextEdit *m_edtText;
};

#endif // WIDGET_H
