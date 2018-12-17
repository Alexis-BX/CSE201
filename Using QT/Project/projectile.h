#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "tools.h"
#include "types_states_textures.h"

class Projectile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    constexpr static greal velocity = 5;

    Projectile_type type;

    Projectile_state state;

    Projectile(pair position, bool direction, int character_size_x, pair size, QGraphicsItem* parent = 0);


    // Attributes
    int life;

    pair speed, size;

    QGraphicsRectItem* collision_range_proj;



    // Methods

    bool collision_right(),collision_left(),collision_down(),collision_up();
    bool collision_b_l(), collision_b_r(), collision_t_l(), collision_t_r();

    void create_collision_range();


public slots:

    void move(); //next position of the projectile depending on their way of moving

};

#endif // PROJECTILE_H
