#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <structures.h>

class View;

extern View* view;

enum Projectile_state
{
    alive,
    vanish,
    dead //if his life is over or it hit something
};

enum Projectile_type
{
    baguette, //player's projectile : horizantal attack
    smoke, //enemy's projectile : horizantal attack
    wine, //player's projectile : downward attack to kill the thief roding right to left for example, projectile you get after taking a msuhroom maybe
    pot,
};


class Projectile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:

    Projectile_type type;
    Projectile_state state;

public:
    int life;
    pair speed;
    pair size;
    pair position;

    int count;
    int velocity;


    Projectile(pair position, bool direction, Projectile_type type = Projectile_type{baguette}, Projectile_state state = Projectile_state{alive}, QGraphicsItem* parent = 0);

    void hit(Projectile_state state);

    void explode();

    QGraphicsRectItem* collision_range_proj;

    bool collision_right();

    bool collision_left();
    bool collision_down();
    bool collision_up();

    int collision = 0;

public slots:

    void move(); //next position of the projectile depending on their way of moving

};

#endif // PROJECTILE_H
