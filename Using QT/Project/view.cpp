#include "listheaders.h"

View::View(pair screen_size, int block_size, QWidget* parent) :
    QGraphicsView(parent), block_size(block_size), screen_size(screen_size)
{
    //scene set up
    setScene(new QGraphicsScene());

    // load and create level
    level_load = new Level_load(this);
    level_load->load_level(":/Images/Levels/Level_agathe_002.png");
}

void View::update_background()
{
    for(unsigned long long i = 0 ; i < backgrounds_far.size(); i++)
    {
        backgrounds_far[i]->setX((backgrounds_far[i]->x())-(player->speed.x)/(backgrounds_far[i]->speed_ratio));
    }
    if (backgrounds_far[0]->x() > player->x()-screen_size.x/2){
        backgrounds_far.insert(backgrounds_far.begin(), new Background_far(pair{backgrounds_far[0]->x()-(backgrounds_far[0]->width),-view->screen_size.y}));
        backgrounds_far[0]->setZValue(-1);
        scene()->addItem(view->backgrounds_far[0]);
    }

    double temp = backgrounds_far.back()->x()+backgrounds_far.back()->width;
    if (temp < player->x()+screen_size.x/2){
        backgrounds_far.push_back(new Background_far(pair{temp,-view->screen_size.y}));
        backgrounds_far.back()->setZValue(-1);
        scene()->addItem(view->backgrounds_far.back());
    }
    //remove backgrounds not in view
    //setup all the z values


    for(unsigned long long i = 0 ; i < backgrounds.size(); i++)
    {
        backgrounds[i]->setX((backgrounds[i]->x())-(player->speed.x)/(backgrounds[i]->speed_ratio));
    }
}
