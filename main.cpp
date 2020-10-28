#include "Interface/widget.h"
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Widget w;
    w.setFixedSize(750, 450);
    w.show();
    return a.exec();
}
