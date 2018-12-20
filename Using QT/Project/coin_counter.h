#ifndef COIN_COUNTER_H
#define COIN_COUNTER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "collectable.h"
#include "player.h"
#include <vector>
#include "counter.h"

class Coin_counter : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Coin_counter(QGraphicsItem* parent = 0);

    int coins;

    void add_coin();

    void update_counter();

    std::vector<Counter*> counters;

};

#endif // COIN_COUNTER_H
