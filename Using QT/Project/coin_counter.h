#ifndef COIN_COUNTER_H
#define COIN_COUNTER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "collectable.h"
#include "player.h"

class Coin_counter : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Coin_counter();
    int add_coin(Collectable collectable);
    void display_counter(int coin);

};

#endif // COIN_COUNTER_H
