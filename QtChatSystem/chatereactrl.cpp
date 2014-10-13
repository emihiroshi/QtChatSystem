#include "chatereactrl.h"

chatEreaCtrl::chatEreaCtrl()
{
}

void chatEreaCtrl::clear()
{
    m_chatList.clear();
}

void chatEreaCtrl::write(const QString &str)
{
    CHATINFO info;
    info.time = QDateTime::currentDateTimeUtc();
    info.str = str;
    m_chatList.push_back(info);
    emit strChanged();
}

QString chatEreaCtrl::read()
{
    int i;
    QString tmp;
    for(i=0; i<m_chatList.count(); i++)
    {
        tmp += m_chatList.value(i).time.date().toString("yyyy/MM/dd ");
        tmp += m_chatList.value(i).time.time().toString("hh:mm:ss ");
        tmp += "\t";
        tmp += m_chatList.value(i).str;
    }
    return tmp;
}
