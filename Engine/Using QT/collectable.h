#ifndef COLLECTABLE_H
#define COLLECTABLE_H 

#include <QGraphicsPixmapItem>
#include <QObject>
#include "structures.h"

class View;

extern View* view;

enum Collectable_state  // the collectable can either be used by the player or not
{
    used, //if the player took the collectable
    unused //if the player didn't took the collectbale
};

enum Collectable_type // shows all kinds of collectables that can appear
{
    coin, //gives points
    star, //gives the superpower to go faster
    mushroom, //gives the superpower to be bigger
    eclair
};

enum Collectable_texture  // shows if the player meets the same or different collectable
{
    same,
    different
};

class Collectable : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:

    Collectable_type type;             // shows the kind of collectable the player meets
    Collectable_state state;           // shows if the collectable is used or unused
    Collectable_texture texture;       // the player meets the same or different collectable

public:

    pair size;
    pair position;
    pair speed;

    int velocity;
    int count;

    Collectable(pair position, Collectable_type type = Collectable_type{coin}, Collectable_state state = Collectable_state{unused}, Collectable_texture texture = Collectable_texture{same}, QGraphicsItem* parent = 0 );

    QGraphicsRectItem* collision_range_collec;

    bool collision_left();
    bool collision_down();
    bool collision_up();
    bool collision_right();

    int collision = 0;

public slots:

    void move(); //next position of the projectile depending on their way of moving

};

#endif // COLLECTABLE_H


/*void Set_State(Collectable_state state);

Collectable_state Get_State() const;

void Set_Type(Collectable_type type);

Collectable_type Get_Type() const;

void Set_Texture(Collectable_texture texture);

Collectable_texture Get_Texture() const;*/
