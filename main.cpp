#include "CSVManaging/Reader.h"
#include "Interface/widget.h"
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Widget w;
    w.show();
    return a.exec();
}
