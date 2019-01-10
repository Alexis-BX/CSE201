#include "listheaders.h"

View::View(pair screen_size, int block_size, QWidget* parent) :
    QGraphicsView(parent), block_size(block_size), screen_size(screen_size)
{
    //fluidifies image adition in the background along with some animations
    setViewportUpdateMode(MinimalViewportUpdate);//if problems: FullViewportUpdate

    //scene set up
    setScene(new QGraphicsScene());

    // load and create level
    level_load = new Level_load(this);

}

void View::update_background()
{
    backgrounds_far = update_single_bg<Background_far>(backgrounds_far, view->screen_size.y);
    backgrounds_middle = update_single_bg<Background_middle>(backgrounds_middle, 500);
    backgrounds_close = update_single_bg<Background_close>(backgrounds_close, 256);
}

template <class BG> std::vector<BG*> View::update_single_bg(std::vector<BG*> list, double offset)
{
    for(unsigned long long i = 0 ; i < list.size(); i++)
    {
        list[i]->setX((list[i]->x())-(player->speed.x)/(list[i]->speed_ratio));
    }

    if (list[0]->x() > player->x()-screen_size.x)
    {
        list.insert(list.begin(), new BG(pair{list[0]->x()-(backgrounds_far[0]->width),-offset}));
        scene()->addItem(list[0]);
    }
    else if (list[0]->x() + list[0]->width < player->x() - screen_size.x)
    {
        //for some reason deleting slows down and doesn't accelerate
        //scene()->removeItem(list[0]);
        //list.erase(list.begin());
    }

    if (list.back()->x() + list.back()->width < player->x() + screen_size.x/2)
    {
        list.push_back(new BG(pair{list.back()->x()+list.back()->width,-offset}));
        scene()->addItem(list.back());
    }
    else if (list.back()->x() > player->x() + screen_size.x)
    {
        //for some reason deleting slows down and doesn't accelerate
        //scene()->removeItem(list[list.size()-1]);
        //list.erase(list.end());
    }

    return list;
}
