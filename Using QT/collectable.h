#ifndef COLLECTABLE_H
#define COLLECTABLE_H 

#include <QGraphicsPixmapItem>
#include <QObject>
#include "tools.h"
#include "types_states_textures.h"

class View;

extern View* view;

class Collectable : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Collectable_type type;             // shows the kind of collectable the player meets

    Collectable_state state;           // shows if the collectable is used or unused

    Collectable_texture texture;       // the player meets the same or different collectable

    pair size;
    pair position;
    pair speed;

    Collectable(pair position, Collectable_type type = Collectable_type{coin}, Collectable_state state = Collectable_state{unused},
                Collectable_texture texture = Collectable_texture{same}, QGraphicsItem* parent = 0 );

     QGraphicsRectItem* collision_range_collec;

     void collision_range();

     bool collision_left();
     bool collision_down();
     bool collision_up();
     bool collision_right();

public slots:

    void move(); //next position of the collectable depending on their way of moving

};

#endif // COLLECTABLE_H
