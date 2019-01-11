#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "global.h"

class Projectile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    QList<QGraphicsRectItem*> collision_ranges;

    QList<bool> collision;

    constexpr static greal velocity = 15;

    Projectile_type type;

    Projectile_state state;

    Projectile(pair position, bool direction, int character_size_x, pair size, QGraphicsItem* parent = 0);


    // Attributes
    int life;

    pair speed, size;

    double img_count=0;

public slots:

    void move(); //next position of the projectile depending on their way of moving

};

#endif // PROJECTILE_H
