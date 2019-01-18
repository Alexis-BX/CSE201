#ifndef GMOVINGOBJECT_H
#define GMOVINGOBJECT_H
#include "global.h"
#include "gobject.h"


enum Collision_ranges
{
    horizontal,
    vertical,
    diagonal
};

class GMovingObject : public GObject
{

public:

    GMovingObject(QPoint speed, QPoint position, QGraphicsItem* parent = nullptr);

    ~GMovingObject();

    void check_in_boundaries();

    void update_collision_range();

    void simple_collision(int i, QGraphicsItem* colliding);

    void activate_block(QGraphicsItem* colliding);

    void destroy_item(QGraphicsItem* colliding);

    void damage_block(int direction, QGraphicsItem* colliding);

    void collide();

    QList<QGraphicsRectItem*> collision_ranges;

    QPoint speed{0,0}, max_speed{10,15};

    Direction facing{Right};

    QTimer* timer;

    bool touching_ground{false};

    virtual QString get_name();


public slots:

    // Slot for timer
    virtual void move();

};

#endif // GMOVINGOBJECT_H
