#include "object.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Object w;
    w.show();

    return a.exec();
}
