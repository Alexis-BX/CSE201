#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <structures.h>
#include "types_states_textures.h"

class View;

extern View* view;

class Projectile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:

    Projectile_type type;

    Projectile_state state;

public:

    Projectile(pair position, bool direction, Projectile_type type = Projectile_type{baguette},
               Projectile_state state = Projectile_state{alive}, QGraphicsItem* parent = 0);


    // Attributes
    int life;

    pair speed,size;

    QGraphicsRectItem* collision_range_proj;



    // Methods

    bool collision_right(),collision_left(),collision_down(),collision_up();

    void setup_projectile(bool direction);

    void create_collision_range();


public slots:

    void move(); //next position of the projectile depending on their way of moving

};

#endif // PROJECTILE_H
