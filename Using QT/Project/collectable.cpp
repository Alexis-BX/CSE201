#include "collectable.h"
#include "player.h"
#include "view.h"
#include "global.h"


Collectable::Collectable(pair position, int creator_object_size_y, pair size, QGraphicsItem* parent):  // constructor: gives default aspects of the collectable
      QObject (), QGraphicsPixmapItem (parent)
{
    setPos(position.x, position.y);

    this -> size = size;     // gives the size of the collectable

    qDebug() << position.y;

    qDebug() << creator_object_size_y;

    qDebug() << size.x;

    collision_range();

    QTimer * timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(20);


    if (type == coin){
            size = pair{18,18};
            speed = pair{0,0};
        setPixmap(QPixmap(gtexture->get_path_to(small_collectable)));
        }

        if (type == star){
            size = pair{18,18};
            speed = pair{0,0};
        setPixmap(QPixmap(gtexture->get_path_to((big_collectable))));
        }

        if (type == mushroom){
            size = pair{18,18};
            speed = pair{1, 0};
        setPixmap(QPixmap(gtexture->get_path_to(power_up_1)));
        }

        if (type == eclair){
            size = pair{18,18};
            speed = pair{0,0};
        setPixmap(QPixmap(gtexture->get_path_to(power_up_2)));
        }

}

void Collectable::collision_range()
{
        collision_range_collec = new QGraphicsRectItem(this);
        collision_range_collec -> setRect(0,0,size.x + size.x/2, size.y + size.y/2);
        collision_range_collec -> setPos(0 - size.x/4, 0 -size.y/4);
}


bool Collectable::collision_right()
{
    // return if the right of the collectable suffers a collision with the player
        QList<QGraphicsItem *> colliding_items = collision_range_collec->collidingItems();
        for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
        {
            if (speed.x > 0) //collectable moves right
            {
                for (int i = 0; i<size.y; i++) //iterate over the whole height of the collectable
                {
                    if ((*iter)-> contains(QPointF(x() +  (size.x-1)  + (speed.x - 1) - (*iter)->x() , y() + i -(*iter)->y() )))
                    {
                        return true;
                    }
                }
            } //END OF FIRST CASE
        }
        return false;
    }

bool Collectable::collision_left()
{
    QList<QGraphicsItem *> colliding_items = collision_range_collec->collidingItems();
    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
    if (speed.x < 0) //collectable goes backwards
    {
        for (int i =0; i< size.y; i++)
        { //collision of the left of the collectable
            if ((*iter)-> contains(QPointF(x()  + speed.x   - (*iter)->x() , y() + i  -(*iter)->y() )))
            {
                return true;
            }
        }
    } //end of case 2
    }
    return false;
}

bool Collectable::collision_up()
{ // return if the up of the collectable suffers a collision with the player
    QList<QGraphicsItem *> colliding_items = collision_range_collec->collidingItems();
    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
        if (speed.y < 0) //collectable goes up
        {
            for (int i =0; i< size.x; i++)
            { //collision of the top of the collectable
                if ((*iter)-> contains(QPointF(x()  + i  - (*iter)->x() , y() +speed.y -(*iter)->y() )))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Collectable::collision_down()
{ // return if the down of the collectable suffers a collision with the player
    QList<QGraphicsItem *> colliding_items = collision_range_collec->collidingItems();
    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
        if(speed.y > 0) //collectable goes down
        {
            for (int i =0; i< size.x; i++)
            { //collision of the bottom of the projectile
                if ((*iter)-> contains(QPointF(x()  + i  - (*iter)->x() , y() + (size.y-1) + (speed.y-1) -(*iter)->y() )))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void Collectable::move()
{
    if (state == used)
    {
        QObject::deleteLater();
    }
}

