#include "listheaders.h"
#include <QList>

View::View(pair screen_size, int block_size, QWidget* parent) :
    QGraphicsView(parent), block_size(block_size), screen_size(screen_size)
{
    //fluidifies image adition in the background along with some animations
    setViewportUpdateMode(FullViewportUpdate);//if problems (to slow): MinimalViewportUpdate

    level_load = new Level_load(this);

    music = new Music();

    current_level = ":/Images/Levels/Level_clara_002.png";
}

void View::update_background()
{
    update_single_bg<Background_far>(backgrounds_far);
    update_single_bg<Background_middle>(backgrounds_middle);
    update_single_bg<Background_close>(backgrounds_close);
}

//clear scene crashes everything for some reason (probably du to deletion of items but not timers?)
void View::game_over()
{
    view->music->stop();

    scene_game_over = new QGraphicsScene();
    setScene(scene_game_over);
    scene_game_over->addItem(new Game_over());
}

void View::you_win()
{
    view->music->stop();

    scene_you_win = new QGraphicsScene();
    setScene(scene_you_win);
    scene_you_win->addItem(new You_win());
}

void View::play_level(QString level_name)
{
    scene = new QGraphicsScene();
    setScene(scene);
    level_load->load_level(level_name, scene);

    music->start();
}




template <class BG> void View::update_single_bg(std::vector<BG*> &list)
{
    for(unsigned long long i = 0 ; i < list.size(); i++)
    {
        list[i]->setX((list[i]->x())-(player->speed.x)/(list[i]->speed_ratio));
    }

    if (list[0]->x() > player->x()-screen_size.x)
    {
        list.insert(list.begin(), new BG(pair{list[0]->x()-(list[0]->width),0}));
        scene->addItem(list[0]);
    }
    else if (list[0]->x() + list[0]->width < player->x() - screen_size.x)
    {
        //for some reason deleting slows down and doesn't accelerate
        //scene->removeItem(list[0]);
        //list.erase(list.begin());
    }

    if (list.back()->x() + list.back()->width < player->x() + screen_size.x/2)
    {
        list.push_back(new BG(pair{list.back()->x()+list.back()->width,0}));
        scene->addItem(list.back());
    }
    else if (list.back()->x() > player->x() + screen_size.x)
    {
        //for some reason deleting slows down and doesn't accelerate
        //scene->removeItem(list[list.size()-1]);
        //list.erase(list.end());
    }
}
