#include "listheaders.h"

Collision_master::Collision_master(QGraphicsItem* parent) :
    QObject (), QGraphicsRectItem (parent)
{
    create_collision_range();
}

void Collision_master::create_collision_range()
{
    for(int i = 0; i < 3 ; i ++)
    {
        collision_ranges.push_back(new QGraphicsRectItem(this));
        collision_ranges[i]->setPen(QPen(Qt::NoPen));
    }
}
