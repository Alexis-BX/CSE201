#include "listheaders.h"
#include "test.h"
#include "music.h"
#include <QSound>

View* view;

Texture* gtexture;

Collision_master* collision_master;

void main_start_game(){
    view->start_game();
    view->level_load->load_level(":/Images/Levels/Level_clara_002.png");
}

int main(int argc, char *argv[])
{

    QApplication application(argc, argv);

    collision_master = new Collision_master();

    gtexture = new Texture();

    view = new View(pair{793,505});

    //main_start_game();
    new Menu();

    view->show();

    QSound::play("://Images/Backgrounds/Main_background/song.wav");

    return application.exec();

}


