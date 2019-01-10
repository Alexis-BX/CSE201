#include "listheaders.h"
#include "test.h"

View* view;

Texture* gtexture;

Collision_master* collision_master;

int main(int argc, char *argv[])
{

    QApplication application(argc, argv);

    collision_master = new Collision_master();

    gtexture = new Texture();

    view = new View(pair{793,505});

    view->level_load->load_level(":/Images/Levels/Level_clara_002.png");

    view->show();

    Test test;

    test.Test_Blink();

    test.Test_Blink2();

    //test.Test_AddCoin();

    //test.Test_UpdateCounter();

    return application.exec();

}

int main2(int argc, char *argv[])
{
    gtexture = new Texture();

    QApplication application(argc, argv);

    view = new View(pair{505,505});

    view->show();

    return application.exec();
}
