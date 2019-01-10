#ifndef COLLISION_MASTER_H
#define COLLISION_MASTER_H
#include "global.h"


class Collision_master : public QObject, public QGraphicsRectItem
{

public:

    Collision_master(QGraphicsItem *parent);

    void create_collision_range();

    QList<QGraphicsRectItem*> collision_ranges;
};

#endif // COLLISION_MASTER_H
