#include "listheaders.h"

Coin_counter::Coin_counter(pair position, QGraphicsItem* parent) :
    QObject (), QGraphicsPixmapItem (parent)
{
    coins = 0;
    setPos(position.x,position.y-20);

    Counter* counter = new Counter(0, this);
    counters.push_back(counter);
}

void Coin_counter::add_coin(int amount)
{
    coins += amount;
    update_counter();
}

void Coin_counter::update_counter()
{
    if(coins/(std::pow(10,int(counters.size())))>=1)
    {
        Counter* counter = new Counter(int(counters.size()), this);
        counters.push_back(counter);
    }

    for(unsigned long long i = 0 ; i < counters.size() ; i ++)
    {
        counters[i]->update_counter(coins/(std::pow(10, i)));
    }
}
