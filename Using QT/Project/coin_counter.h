#ifndef COIN_COUNTER_H
#define COIN_COUNTER_H
#include "global.h"

#include "counter.h"

class Coin_counter : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Coin_counter(QPoint position, QGraphicsItem* parent = 0);

    int coins{0};

    std::vector<Counter*> counters;

    pair position;

    void add_coin(int amount = 1);

    void update_counter();
};

#endif // COIN_COUNTER_H
