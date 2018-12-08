#include "projectile.h"
#include "player.h"
#include "view.h"

Projectile::Projectile(pair position, bool direction, Projectile_type type, Projectile_state state, QGraphicsItem* parent) :
    QObject (), QGraphicsPixmapItem (parent)

{   //initialisation
    setPos (position.x, position.y);
    this -> type = type;
    this -> state = state;

    setPixmap(QPixmap(":/images/Mario.png"));

    //initializing life and size of projectile depending on it's type
    if (type == baguette){
        life = 1000;
        size = pair{40,10};
        if (direction)
        {
            speed = pair{5,0};
        }
        else
        {
            speed = pair{-5,0};
        }
    }
    if (type == smoke){
        life = 200;
        size = pair {18,18};
        speed = pair{5,10};
    }
    if (type == wine){
        life = 50;
        size = pair{20,10};
        speed = pair{5,10};
    }

    setPos(position.x, position.y);

    QTimer * timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(20);
}

void Projectile::move()
{
    //Goal of this method is to update the position of the projectile
    //linear direction for smoke and baguette prjectile
    if (type == smoke || type == baguette){
        setX(x() + speed.x);
        setY(y() + speed.y);
    }

    // if type == wine: mario throw bottle of wine down in diagonal
    else {
        setX(2);
        setY(1);
    }

    life -= 1; //at each next frame, life of projectile diminishes by 1
    if (life == 0){
        state = Projectile_state{dead}; //if projectile have no more life, projectile change state from alive to dead
    }
}

void Projectile::hit(Projectile_state state) //if porjectile is hit by something it changes state to dead
{
    state = dead;
}

void Projectile::explode() //if we want, the projectile can explode before changing state to vanish or dead
{
    size.x *= 2;
    size.y *= 2;
    if (state == alive){
        state = vanish;
    }
    else {
        state = dead;
    }
}











