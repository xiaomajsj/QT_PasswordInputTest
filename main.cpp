#include "mainwindow.h"

#include <QApplication>
#include <QQmlEngine>

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
