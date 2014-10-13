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
    typedef struct{
        QDateTime time;
        QString name;
        QString str;
    } CHAT_ONECE;

    typedef struct{
        QVector<CHAT_ONECE> list;
    } CHAT_ALL_INFO;

public:
    chatEreaCtrl();
    void clear(void);
    void write(const QString& name, const QString& str);
    CHAT_ALL_INFO& read(void);

signals:
    void strChanged(void);

protected:
    CHAT_ALL_INFO m_allInfo;
};

#endif // CHATEREACTRL_H
