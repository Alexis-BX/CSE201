#include <QApplication>
#include "object.h"
#include "screen.h"

Screen* screen;

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    screen = new Screen();

    screen->show();

    return application.exec();
}


