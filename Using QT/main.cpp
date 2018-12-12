#include <QApplication>
#include "view.h"
#include "tools.h"

View* view;

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    view = new View(pair{800,500});

    view->show();

    return application.exec();
}
