#include "listheaders.h"
#include <QList>

View::View(pair screen_size, int block_size, QWidget* parent) :
    QGraphicsView(parent), block_size(block_size), screen_size(screen_size)
{
    //fluidifies image adition in the background along with some animations
    setViewportUpdateMode(FullViewportUpdate);//if problems (to slow): MinimalViewportUpdate

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(int(screen_size.x),int(screen_size.y));

    level_load = new Level_load(this);

    music = new Music();

    current_level = ":/Images/Levels/Level_003.png";
}

void View::update_background()
{
    update_single_bg<Background_far>(backgrounds_far);
    update_single_bg<Background_middle>(backgrounds_middle);
    update_single_bg<Background_close>(backgrounds_close);
}


void View::game_over()
{
    music->stop_song(); //stops the background music

    music->play_sound_effect(music_end); //calls the game over music

    setScene(scene_game_over);
    scene_game_over->addItem(new Game_over(player->coin_counter->coins));

    scene->clear();
}

void View::you_win()
{
    music->stop_song(); //stops the background music

    music->play_sound_effect(music_win); //plays the winning music

    setScene(scene_you_win);
    scene_you_win->addItem(new You_win());

    scene->clear();
}

void View::open_menu()
{
    setScene(scene_menu);

    menu = new Menu();

    scene_menu->addItem(menu);
}

void View::world()
{
    scene_game_over->clear();
    scene_you_win->clear();


    setScene(scene);

    scene->addItem(new World());

}


void View::play_level(QString level_name)
{
    scene_game_over->clear();
    scene_you_win->clear();

    setScene(scene);
    level_load->load_level(level_name);

    music->start_song();
}




template <class BG> void View::update_single_bg(std::vector<BG*> &list)
{
    for(unsigned long long i = 0 ; i < list.size(); i++)
    {
        list[i]->setX((list[i]->x())-(player->speed.rx())/(list[i]->speed_ratio));
    }

    if (list[0]->x() > player->x()-screen_size.x)
    {
        list.insert(list.begin(), new BG(pair{list[0]->x()-(list[0]->width),0}));
        scene->addItem(list[0]);
    }
    else if (list[0]->x() + list[0]->width < player->x() - screen_size.x)
    {
        scene->removeItem(list[0]);
        delete(list[0]);
        list.erase(list.begin());
    }

    if (list.back()->x() + list.back()->width < player->x() + screen_size.x/2)
    {
        list.push_back(new BG(pair{list.back()->x()+list.back()->width,0}));
        scene->addItem(list.back());
    }
    else if (list.back()->x() > player->x() + screen_size.x)
    {
        scene->removeItem(list[list.size()-1]);
        delete(list[list.size()-1]);
        list.pop_back();
    }
}
