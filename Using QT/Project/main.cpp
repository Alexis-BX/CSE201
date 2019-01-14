#include "listheaders.h"
#include "test.h"
#include "music.h"
#include <QSound>

View* view;

Texture* gtexture;

Collision_master* collision_master;

int main(int argc, char *argv[])
{

    QApplication application(argc, argv);

    collision_master = new Collision_master();

    gtexture = new Texture();

    view = new View(pair{793,505});

    view->play_level(":/Images/Levels/Level_clara_002.png");

    //new Menu();

    view->show();

    return application.exec();

}


