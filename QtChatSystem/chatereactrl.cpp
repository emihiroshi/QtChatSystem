#include "chatereactrl.h"

chatEreaCtrl::chatEreaCtrl()
{
}

void chatEreaCtrl::clear()
{
    m_buffer.clear();
}

void chatEreaCtrl::write(const QString &str)
{
    m_buffer += str;
    emit strChanged();
}

QString chatEreaCtrl::read()
{
    return m_buffer;
}
