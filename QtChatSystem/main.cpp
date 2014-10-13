#include "widget.h"
#include "chatereactrl.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chatEreaCtrl *buf = new chatEreaCtrl;
    Widget w(buf);
    w.setGeometry(100,100,500,500);
    w.show();

    return a.exec();
}
