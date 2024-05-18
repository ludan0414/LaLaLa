#include "widget.h"
#include "makedic.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    work();
    readcustomdic();
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
