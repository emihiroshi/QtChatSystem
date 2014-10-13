#include "chatereactrl.h"

chatEreaCtrl::chatEreaCtrl()
{
}

void chatEreaCtrl::clear()
{
    m_allInfo.list.clear();
}

void chatEreaCtrl::write(const QString &name, const QString &str)
{
    CHAT_ONECE onece;
    onece.time = QDateTime::currentDateTimeUtc();
    onece.name = name;
    onece.str = str;
    m_allInfo.list.push_back(onece);
    emit strChanged();
}

chatEreaCtrl::CHAT_ALL_INFO& chatEreaCtrl::read(void)
{
    return m_allInfo;
}
