#include "coin_counter.h"
#include "collectable.h"
#include "collectables.h"
#include "player.h"
#include "view.h"
#include "global.h"
#include "tools.h"
#include "types_states_textures.h"
#include <QTimer>
#include <cmath>

Coin_counter::Coin_counter(pair position, QGraphicsItem* parent) :
    QObject (), QGraphicsPixmapItem (parent)
{
    coins = 0;
    setPos(position.x,position.y-20);

    Counter* counter = new Counter(0, this);
    counters.push_back(counter);

    // Timer
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(take_this()));
    timer->start(200);
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

void Coin_counter::take_this()
{
    add_coin();
}
