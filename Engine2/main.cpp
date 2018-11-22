#include "objet.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Objet w;
    w.show();

    return a.exec();
}
