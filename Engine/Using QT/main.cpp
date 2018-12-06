#include <QApplication>
#include "view.h"
#include "structures.h"

View* view;

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    view = new View(pair{500,500});

    view->show();

    return application.exec();
}
