#include "listheaders.h"

Collectable::Collectable(pair position, int creator_object_size_y, QGraphicsItem* parent):  // constructor: gives default aspects of the collectable
      QObject (), QGraphicsPixmapItem (parent)
{
    setPos(position.x, position.y-creator_object_size_y);

    size = pair{18,18};     // gives the size of the collectable



    setZValue(layer_collectable);



    collision_ranges = create_collision_range<Collectable>(this);
}

void Collectable::set_movement()
{
    if(type == eclair)
    {
        //Timer
        move_timer = new QTimer();
        QObject::connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
        move_timer->start(30);
    }
}

Collectable::~Collectable()
{
    move_timer->stop();
    move_timer->deleteLater();
    for(int i = 0; i < collision_ranges.size(); i++)
    {
        delete(collision_ranges[i]);
    }
}

void Collectable::move()
{
    //Accelerate
    speed.y += 1;

    //Motion smooth

    if (facing == Right)
    {
        speed.x = 5;
    }
    else
    {
        speed.x = -5;
    }

    if(std::rand() % 200 == 0)
    {
        speed.y += 10;
    }

    //in boundaries
    if(y() >= view->world_size.bottom)
    {
        speed.y = (0 > speed.y) ? speed.y : 0 ;
        setY(view->world_size.bottom);
    }
    else if(y() <= view->world_size.top)
    {
        speed.y = (0 < speed.y) ? speed.y : 0 ;
        setY(view->world_size.top);
    }

    if(x()<=view->world_size.left)
    {
        speed.x = (0 < speed.x) ? speed.x : 0 ;
        setX(view->world_size.left);
    }
    else if(x() >= view->world_size.right)
    {
        speed.x = (0 > speed.x) ? speed.x : 0 ;
        setX(view->world_size.right);
    }

    update_collision_range(collision_ranges, size, speed);

    {
    QString temp_collision_type;
    QList<QGraphicsItem*> colliding_items;
    collision = QList<bool>{false,false,false};

    for(int i = 0; i < 3 ; i ++)
    {
        colliding_items = collision_ranges[i]->collidingItems();
        for(int j = 0; j < colliding_items.size(); j++)
        {
            temp_collision_type = collision_master->collide("Collectable",QString(typeid(*colliding_items[j]).name()));

            if(temp_collision_type == "simple_collision")
            {
                collision[i] = true;
                continue;
            }
        }
    }
    }

    // movements of the player:
    if (collision[0])
    {
        speed.x = 0;
        facing = (facing == Right) ? Left : Right ;
    }
    if (collision[1])
    {
        speed.y = 0;
    }
    if (collision[2] && !collision[1] && !collision[0])
    {
        speed.y = 0;
    }

    setPos(x()+speed.x,y()+speed.y);
}

