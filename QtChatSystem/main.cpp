#include "widget.h"
#include "chatereactrl.h"
#include <QApplication>
#include <QSettings>

typedef struct{
    QString ipaddr;
    int port;
} CHAT_CONF;

void getConfig(CHAT_CONF& config)
{
    QSettings setting("chatconf.ini", QSettings::IniFormat);
    config.ipaddr = setting.value("TCP/ipaddr", "localhost").toString();
    config.port = setting.value("TCP/port", 3923).toInt();
    setting.setValue("TCP/ipaddr", config.ipaddr);
    setting.setValue("TCP/port", config.port);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chatEreaCtrl *buf = new chatEreaCtrl;
    CHAT_CONF config;
    Widget w(buf);

    getConfig(config);

    w.setGeometry(100,100,500,500);
    w.show();

    return a.exec();
}
