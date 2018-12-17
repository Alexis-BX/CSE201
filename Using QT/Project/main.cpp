#include <QApplication>
#include "view.h"
#include "tools.h"
#include "texture.h"

View* view;

Texture* gtexture;

int main(int argc, char *argv[])
{
    gtexture = new Texture();

    QApplication application(argc, argv);

    view = new View(pair{793,505});

    view->show();

    return application.exec();
}
