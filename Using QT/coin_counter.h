#ifndef COIN_COUNTER_H
#define COIN_COUNTER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "collectable.h"
#include "player.h"

class View;

extern View* view;


class coin_counter : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    coin_counter();
    void add_coin(Collectable collectable);

};

#endif // COIN_COUNTER_H
