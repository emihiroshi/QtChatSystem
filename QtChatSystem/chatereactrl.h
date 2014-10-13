#ifndef CHATEREACTRL_H
#define CHATEREACTRL_H

#include <QObject>
#include <QString>

class chatEreaCtrl : public QObject
{
    Q_OBJECT

public:
    chatEreaCtrl();
    void clear(void);
    void write(const QString& str);
    QString read(void);

signals:
    void strChanged(void);

protected:
    QString m_buffer;
};

#endif // CHATEREACTRL_H
