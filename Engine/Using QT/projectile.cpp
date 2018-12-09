#include "projectile.h"
#include "player.h"
#include "view.h"
#include <QtDebug>
#include <QTimer>
#include <QTime>

Projectile::Projectile(pair position, bool direction, Projectile_type type, Projectile_state state, QGraphicsItem* parent) :
    QObject (), QGraphicsPixmapItem (parent)

{   //initialisation
    this -> type = type;
    this -> state = state;
    this->position = position;

    int velocity = 5;


    if (state == vanish){setPixmap(QPixmap(":/images/explosion.png"));}

    //initializing life and size of projectile depending on it's type
    if (type == baguette){
        life = 10;
        size = pair{18,5};
        if (direction == 1)
        {
            speed = pair{velocity, 0};
        }
        else
        {
            speed = pair{-velocity, 0};
        }

        setPixmap(QPixmap(":/images/baguette.png"));
    }
    if (type == smoke){
        life = 200;
        size = pair {18,18};
        if (direction == 1)
        {
            speed = pair{velocity,0};
        }
        else
        {
            speed = pair{-velocity, 0};
        }
        setPixmap(QPixmap(":/images/smoke.png"));
    }
    if (type == wine){
        life = 50;
        size = pair{18,18};
        if (direction == 1)
        {
            speed = pair{velocity,velocity};
        }
        else
        {
            speed = pair{-velocity,velocity};
        }
        setPixmap(QPixmap(":/images/wine.png"));
    }

    setPos(position.x, position.y);

    QTimer * timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(20);

    collision_range_proj = new QGraphicsRectItem(this);
    collision_range_proj->setRect(0,0,size.x + size.x /2, size.y + size.y/2);
    collision_range_proj->setPen(QPen(Qt::NoPen));
    collision_range_proj->setPos(0 -size.x/4,0 - size.y/4); //we readjust the position of the collision
                                                                //box so that is centers the projectile
}

void delay(int i) //milliseconds
{
    QTime dieTime= QTime::currentTime().addMSecs(i);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Projectile::move()
{
    if (state == dead)
    {
        delay(200); //make sure the explosion image stays for a bit THIS SOLUTION FOR A TIMER IS SHIT, IT STOPS ALL CALCULATIONS
        QObject::deleteLater();
    }
    if (state == vanish){setPixmap(QPixmap(":/images/explosion.png")); state = dead;}

    //COLLISIONS OF THE PROJECTILE
    // WE assume the projectile is necessarily smaller than a block (maximum size = 18*18)
    // I did the cases where projectiles could also go up, although for the moment we have none of these
    QList<QGraphicsItem *> colliding_items = collision_range_proj->collidingItems();
    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
        if (speed.x > 0) //projectile moves right
        {
            if (speed.y == 0) //horizontal movement
            {
                //(size.x - 1, 0)
                if ((*iter)-> contains(QPointF(x() +  size.x  + speed.x - 1 - (*iter)->x() , y()  -(*iter)->y() ))) //
                {
                    speed.x = 0;
                    speed.y +=5;
                }
                //(size.x - 1, size.y - 1)
                if ((*iter)-> contains(QPointF(x() +  size.x  + speed.x - 1 - (*iter)->x() , y() +size.y - 1 -(*iter)->y() )))
                {
                    speed.x = 0;
                    speed.y += 5;
                }


            }

            if (speed.y > 0) //projectile moves right and down
            {
                //(size.x - 1, 0)
                if ((*iter)-> contains(QPointF(x() +  size.x  + speed.x - 1 - (*iter)->x() , y() +speed.y -(*iter)->y() )))
                {
                    speed.x = 0;
                }

                //(size.x - 1, size.y - 1)
                else if ((*iter)-> contains(QPointF(x() +  size.x  + speed.x - 1 - (*iter)->x() , y() +speed.y + size.y -1 -(*iter)->y() )))
                {
                    speed.x = 0;
                }

                //(size.x - 1, size.y - 1)
                if ((*iter)-> contains(QPointF(x() +  size.x  + speed.x - 1 - (*iter)->x() , y() +speed.y + size.y -1 -(*iter)->y() )))
                {
                    speed.y = 0;
                    speed.x = 0; //when it reaches the ground it automatically stops
                    state = vanish;

                }

                //(0, size.y - 1)
                else if ((*iter)-> contains(QPointF(x() + speed.x - (*iter)->x() , y() +speed.y + size.y -1 -(*iter)->y() )))
                {
                    speed.y = 0;
                    speed.x = 0;
                    state = vanish;
                }

                //
            }


            if (speed.y < 0) //projectile moves right and up
            {
                //(0, 0)
                if ((*iter)-> contains(QPointF(x()  + speed.x  - (*iter)->x() , y() +speed.y -(*iter)->y() )))
                {
                    speed.y = 0;
                }

                //(size.x - 1,0)
                else if ((*iter)-> contains(QPointF(x()  + speed.x + size.x - 1 - (*iter)->x() , y() +speed.y -(*iter)->y() )))
                {
                    speed.y = 0;
                }

                //(size.x-1, 0)
                if ((*iter)-> contains(QPointF(x()  + speed.x +size.x - 1 - (*iter)->x() , y() +speed.y -(*iter)->y() )))
                {
                    speed.x = 0;
                }

                //(size.x -1, size.y - 1)
                else if ((*iter)-> contains(QPointF(x()  + speed.x + size.x - 1 - (*iter)->x() , y() +speed.y + size.y - 1-(*iter)->y() )))
                {
                    speed.x = 0;
                }
            }
        } //END OF FIRST CASE


        //SECOND CASE:
        if (speed.x < 0) //projectile goes backwards
        {
            if (speed.y ==0) // horizontal left movement
            {
                //(0,0)
                if ((*iter)-> contains(QPointF(x()  + speed.x  - (*iter)->x() , y() +speed.y -(*iter)->y() )))
                {
                    speed.x = 0;
                    speed.y += 5;
                }

                //(0,size.y - 1)
                if ((*iter)-> contains(QPointF(x()  + speed.x  - (*iter)->x() , y() +speed.y +size.y - 1 -(*iter)->y() )))
                {
                    speed.x = 0;
                    speed.y += 5;
                }
            }

            if (speed.y > 0) //left and down
            {
                //(0,0)
                if ((*iter)-> contains(QPointF(x()  + speed.x  - (*iter)->x() , y() +speed.y -(*iter)->y() )))
                {
                    speed.x = 0;
                }
                //(0,size.y - 1)
                else if ((*iter)-> contains(QPointF(x()  + speed.x  - (*iter)->x() , y() +speed.y + size.y - 1-(*iter)->y() )))
                {
                    speed.x = 0;
                }

                //(0, size.y - 1)
                if ((*iter)-> contains(QPointF(x()  + speed.x  - (*iter)->x() , y() +speed.y +size.y - 1 -(*iter)->y() )))
                {
                    speed.y = 0;
                    speed.x = 0;
                    state = vanish;
                }

                //(size.x -1, size.y - 1)
                else if ((*iter)-> contains(QPointF(x()  + speed.x + size.x - 1 - (*iter)->x() , y() +speed.y + size.y - 1 -(*iter)->y() )))
                {
                    speed.y = 0;
                    speed.x = 0;
                    state = vanish;
                }
            }

            if (speed.y < 0) //left and up
            {
                // (0, size.y - 1)
                if ((*iter)-> contains(QPointF(x()  + speed.x  - (*iter)->x() , y() +speed.y + size.y - 1 -(*iter)->y() )))
                {
                    speed.x = 0;
                }

                //(0,0)
                else if ((*iter)-> contains(QPointF(x()  + speed.x  - (*iter)->x() , y() +speed.y -(*iter)->y() )))
                {
                    speed.x = 0;
                }

                //(0,0)
                if ((*iter)-> contains(QPointF(x()  + speed.x  - (*iter)->x() , y() +speed.y -(*iter)->y() )))
                {
                    speed.y = 0;

                }

                //(size.x - 1, 0)

                if ((*iter)-> contains(QPointF(x()  + speed.x +size. x- 1  - (*iter)->x() , y() +speed.y -(*iter)->y() )))
                {
                    speed.y = 0;
                }


            }
        } //end of case 2


        //Last case  if we create a projectile that drops straight down
        if (speed.x == 0)
        {
            if (speed. y > 0)
            { //(0, size.y - 1)
                if ((*iter)-> contains(QPointF(x()  + speed.x  - (*iter)->x() , y() +speed.y + size.y - 1 -(*iter)->y() )))
                {
                    speed.y = 0;
                    state = vanish;
                }
                //(size.x - 1, size.y - 1)
                if ((*iter)-> contains(QPointF(x()  + speed.x +size.x - 1 - (*iter)->x() , y() +speed.y + size.y - 1 -(*iter)->y() )))
                {
                    speed.y = 0;
                    state = vanish;
                }
            }


        }

        /**
        // WE create a last case, where if there is a player that jumps above him, the object falls to the ground
        // i.e. if the type/state of the block above our projectile is alive (player, not a brick), we have speed.y += 5 for the proj
        // we must have the state for the characters.
        // for the moment, we use: if not (type == block), then:


        //(0,0)
        if ((*iter)-> contains(QPointF(x()  - (*iter)->x() , y()  -(*iter)->y() )))
        {
            if ((*iter)->type != block) //must change the condition
            {
                speed.y += 5;
            }

        }
        //(size.x - 1,0)
        if ((*iter)-> contains(QPointF(x() + size.x - 1  - (*iter)->x() , y()  -(*iter)->y() )))
        {
            if ((*iter)->type != block) //must change the condition
            {
                speed.y += 5;
            }

        }

        **/

    }

    setPos(x() + speed.x, y() + speed.y);



}

void Projectile::hit(Projectile_state state) //if porjectile is hit by something it changes state to dead
{
    state = dead;
}

void Projectile::explode() //if we want, the projectile can explode before changing state to vanish or dead
{
    size.x *= 2;
    size.y *= 2;
    state = vanish;
}












