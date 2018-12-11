#include "projectile.h"
#include "player.h"
#include "view.h"
#include <QtDebug>
#include <QTimer>
#include <QTime>

Projectile::Projectile(pair position, bool direction, Projectile_type type, Projectile_state state, QGraphicsItem* parent) :
    QObject (), QGraphicsPixmapItem (parent)
{
    //Attributes
    this -> type = type;

    this -> state = state;



    setup_projectile(direction);

    setPos(position.x, position.y);

    create_collision_range();



    QTimer * timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(20);
}

void Projectile::setup_projectile(bool direction)
{
    greal velocity = 5;

    //initializing life and size of projectile depending on it's type
    if (type == baguette)
    {
        life = 1000;

        size = pair{18,5};

        if (direction == 1)
        {
            speed = pair{velocity, 0};
        }
        else
        {
            speed = pair{-velocity, 0};
        }

        setPixmap(QPixmap(":/images/pixmaps/baguette.png"));
    }
    else if (type == smoke)
    {
        life = 400;

        size = pair {18,18};

        if (direction == 1)
        {
            speed = pair{velocity, 0};
        }
        else
        {
            speed = pair{-velocity, 0};
        }

        setPixmap(QPixmap(":/images/pixmaps/smoke.png"));
    }
    else if (type == wine)
    {
        life = 50000;

        size = pair{18,18};

        if (direction == 1)
        {
            speed = pair{velocity,velocity};
        }
        else
        {
            speed = pair{-velocity,velocity};
        }

        setPixmap(QPixmap(":/images/pixmaps/wine.png"));
    }
    else if (type == pot)
    {
        life = 200000;

        size = pair{18,18};

        if(direction == 1)
        {
            speed = pair{velocity, -velocity + 3};
        }
        else
        {
            speed = pair{-velocity, -velocity + 3};
        }

        setPixmap(QPixmap(":/images/pixmaps/pot.png"));
    }
}

void Projectile::create_collision_range()
{
    collision_range_proj = new QGraphicsRectItem(this);

    collision_range_proj->setRect(0,0,size.x + size.x /2, size.y + size.y/2);

    collision_range_proj->setPen(QPen(Qt::NoPen));

    collision_range_proj->setPos(-size.x/4,-size.y/4);

    //we readjust the position of the collision
    //box so that is centers the projectile
}

bool Projectile::collision_right()
{
    // return if the right of the projectile suffers a collision
    QList<QGraphicsItem *> colliding_items = collision_range_proj->collidingItems();
    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
        if (speed.x > 0) //projectile moves right
        {
            if (speed.y == 0) //horizontal movement
            {
                for (int i = 0; i<size.y; i++) //iterate over the whole height of the projectile
                {
                    if ((*iter)-> contains(QPointF(x() +  (size.x-1)  + (speed.x) - (*iter)->x() , y() + i -(*iter)->y() )))
                    {
                        return true;
                    }
                }


            }

            else if (speed.y > 0) //projectile moves right and down
            {

                for (int i =0; i< size.y; i++)
                { //collision of the right side of the projectile
                    if ((*iter)-> contains(QPointF(x()  + (speed.x-1) + (size.x)  - (*iter)->x() , y() + (speed.y-1) + i -(*iter)->y() )))
                    {
                        return true;
                    }
                }
            }


            else if (speed.y < 0) //projectile moves right and up
            {
                for (int i =0; i< size.y; i++)
                { //collision of the right side of the projectile
                    if ((*iter)-> contains(QPointF(x()  + (speed.x) + (size.x-1)  - (*iter)->x() , y() +(speed.y+1) + i -(*iter)->y() )))
                    {
                        return true;;
                    }
                }
            }
        } //END OF FIRST CASE

    }
    return false;
}

bool Projectile::collision_left()
{
    QList<QGraphicsItem *> colliding_items = collision_range_proj->collidingItems();
    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
    if (speed.x < 0) //projectile goes backwards
    {
        if (speed.y ==0) // horizontal left movement
        {
            for (int i =0; i< size.y; i++)
            { //collision of the left of the projectile
                if ((*iter)-> contains(QPointF(x()  + speed.x   - (*iter)->x() , y() + i  -(*iter)->y() )))
                {
                    return true;
                }
            }

        }

        else if (speed.y > 0) //left and down
        {
            for (int i =0; i< size.y; i++)
            { //collision of the left side of the projectile
                if ((*iter)-> contains(QPointF(x()  + speed.x  - (*iter)->x() , y() +(speed.y-1) + i -(*iter)->y() )))
                {
                    return true;
                }
            }
        }

        else if (speed.y < 0) //left and up
        {

            for (int i =0; i< size.y; i++)
            { //collision of the left side of the projectile
                if ((*iter)-> contains(QPointF(x()  + speed.x  - (*iter)->x() , y() +(speed.y+1) + i -(*iter)->y() )))
                {
                    return true;
                }
            }

        }
    } //end of case 2
    }
    return false;

}

bool Projectile::collision_up()
{
    QList<QGraphicsItem *> colliding_items = collision_range_proj->collidingItems();
    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
        if (speed.y < 0)
        {
            if (speed.x == 0)
            {
                for (int i =0; i< size.x; i++)
                { //collision of the top of the projectile
                    if ((*iter)-> contains(QPointF(x()  + i  - (*iter)->x() , y() +speed.y -(*iter)->y() )))
                    {
                        return true;
                    }
                }
            }
            else if (speed.x > 0)
            {
                for (int i =0; i< size.x; i++)
                { //collision of the top of the projectile
                    if ((*iter)-> contains(QPointF(x()  + (speed.x-1) + i  - (*iter)->x() , y() +speed.y -(*iter)->y() )))
                    {
                        return true;
                    }
                }
            }

            else if (speed.x < 0)
            {
                for (int i =0; i< size.x; i++)
                { //collision of the top of the projectile
                    if ((*iter)-> contains(QPointF(x()  + (speed.x+1) + i  - (*iter)->x() , y() +speed.y -(*iter)->y() )))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;


}

bool Projectile::collision_down()
{
    QList<QGraphicsItem *> colliding_items = collision_range_proj->collidingItems();
    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
        if(speed.y > 0)
        {
            if (speed.x == 0)
            {
                for (int i =0; i< size.x; i++)
                { //collision of the bottom of the projectile
                    if ((*iter)-> contains(QPointF(x()  + i  - (*iter)->x() , y() + (size.y-1) + (speed.y) -(*iter)->y() )))
                    {
                        return true;
                    }
                }
            }

            if (speed.x > 0)
            {
                for (int i =0; i< size.x; i++)
                { //collision of the bottom of the projectile
                    if ((*iter)-> contains(QPointF(x()  + i + (speed.x - 1)  - (*iter)->x() , y() + (size.y-1) + (speed.y) -(*iter)->y() )))
                    {
                        return true;
                    }
                }
            }

            if (speed.x < 0)
            {
                for (int i =0; i< size.x; i++)
                { //collision of the bottom of the projectile
                    if ((*iter)-> contains(QPointF(x()  + i + (speed.x+1)  - (*iter)->x() , y() + (size.y - 1) +  (speed.y) -(*iter)->y() )))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void delay(int i) //milliseconds
{
    QTime dieTime= QTime::currentTime().addMSecs(i);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Projectile::move()
{
    if (state == vanish){setPixmap(QPixmap(":/images/explosion.png")); state = dead ; delay(200); QObject::deleteLater();}

    life -= 10;
    //if(life == 0){
    //speed.y = 5; setPos(x()+speed.x, y()+speed.y); return;}
    //if(life == -10){delay(100); QObject::deleteLater();}

    int ac_vel_x = 2; //after collision velocity (when the projectile bounces)
    int ac_vel_y = 5;

    bool r = collision_right();
    bool l = collision_left();
    bool t = collision_up();
    bool b = collision_down();

    if (r == true)
    {
        if (b == true)
        {
            speed.x = 0;
            speed.y = 0;
            state = vanish;
        }
        else
        {
            speed.x = - ac_vel_x;
            speed.y = ac_vel_x;
        }
    }

    else if (l == true)
    {
        if (b == true)
        {
            speed.x = 0;
            speed.y = 0;
            state = vanish;
        }
        else
        {
            speed.x = ac_vel_x;
            speed.y = ac_vel_x;
        }
    }
    if (t == true){ speed.y = ac_vel_y;}

    setPos(x() + speed.x, y() + speed.y);

}
