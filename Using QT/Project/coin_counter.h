#ifndef COIN_COUNTER_H
#define COIN_COUNTER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "collectable.h"
#include "counter.h"
#include <vector>

class Coin_counter : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Coin_counter(pair position, QGraphicsItem* parent = 0);

    int coins;

    std::vector<Counter*> counters;

    pair position;

    void add_coin(int amount = 1);

    void update_counter();

public slots:

    void take_this();
};

#endif // COIN_COUNTER_H
