#include "listheaders.h"

Coin_counter::Coin_counter(QPoint position, QGraphicsItem* parent) :
    QObject (), QGraphicsPixmapItem (parent)
{
    position.ry() -= 18;

    setPos(position);

    counters.push_back(new Counter(0, this));
}

void Coin_counter::add_coin(int amount)
{
    coins += amount;
    update_counter();
    view->music->play_sound_effect(collect_cheese); //plays the music coin sound effect
}

void Coin_counter::update_counter()
{
    if(coins/(std::pow(10,int(counters.size())))>=1) //if there is a counter missing
    {
        counters.push_back(new Counter(int(counters.size()), this));
    }

    for(unsigned long long i = 0 ; i < counters.size() ; i ++)
    {
        counters[i]->update_counter(coins/(std::pow(10, i)));
    }
}
