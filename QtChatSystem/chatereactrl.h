#ifndef CHATEREACTRL_H
#define CHATEREACTRL_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QDateTime>

class chatEreaCtrl : public QObject
{
    Q_OBJECT

public:
    typedef enum{
        USERTYPE_OWNSELF,
        USERTYPE_OTHER,
        USERTYPE_ERROR
    } USERTYPE;

    typedef struct{
        USERTYPE type;
        QDateTime time;
        QString str;
    } CHATINFO;

public:
    chatEreaCtrl();
    void clear(void);
    void write(const QString& str);
    QString read(void);

signals:
    void strChanged(void);

protected:
    QVector<CHATINFO> m_chatList;
};

#endif // CHATEREACTRL_H
