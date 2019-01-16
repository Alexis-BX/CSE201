#include "listheaders.h"

Enemy::Enemy(pair position, QGraphicsItem* parent ) : QObject (), QGraphicsPixmapItem (parent)
{

    setPos(position.x, position.y);

    setZValue(layer_enemy);


    collision_ranges = create_collision_range<Enemy>(this);


    // Timers
    timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(timer_connect()));

    timer->start(30);

    collision_range_br = new QGraphicsRectItem(this);
    collision_range_bl = new QGraphicsRectItem(this);

    collision_range_br->setRect(0,0, 8 ,8); // bottom right corner
    collision_range_br->setPos(36, 36);
    collision_range_br->setPen(QPen(Qt::NoPen));

    collision_range_bl->setRect(0,0,8,8); // bottom left corner
    collision_range_bl->setPos(-9, 36);
    collision_range_bl->setPen(QPen(Qt::NoPen));

}

void Enemy::jump()
{
    if(times_jumped >= max_consecutive_jumps)
    {
        return;
    }
    times_jumped ++;
    speed.y = -speedMax.y;
}

Enemy::~Enemy()
{
    timer->stop();
    timer->deleteLater();

    for(int i = 0; i < collision_ranges.size(); i++)
    {
        delete(collision_ranges[i]);
    }
}

void Enemy::timer_connect()
{
    move();

    if(state == aggressiv)
    {
        projectile_count += 1;
        if(projectile_count == 100)
        {
            projectile_count = 0;
            throw_projectile();
        }
    }
}

void Enemy::move()
{
    //Accelerate
    speed.y += 1;

    //Player in range
    greal distance_to_player = distance(pair{view->player->x(),view->player->y()},pair{x(),y()});

    if(distance_to_player < 30000 && state == passiv)
    {
        state = aggressiv;
    }
    else if(distance_to_player > 60000 and state == aggressiv)
    {
        state = passiv;
    }

    if(state == aggressiv)
    {
        if(view->player->x() >= x())
        {
            speed.x = speedMax.x;
        }
        else
        {
            speed.x = -speedMax.x;
        }
    }
    else if(state == passiv)
    {
        if(facing == Right)
        {
            speed.x = speedMax.x;
        }
        else
        {
            speed.x = -speedMax.x;
        }

    }

    //Motion smooth
    if (speed.y > speedMax.y)
    {
        speed.y = speedMax.y;
    }
    if (speed.y < -speedMax.y)
    {
        speed.y = -speedMax.y;
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

    //make sure he doesn't fall off:
    QList<QGraphicsItem*> corner_colliding_br;
    QList<QGraphicsItem*> corner_colliding_bl;

    corner_colliding_br = collision_range_br->collidingItems();
    corner_colliding_bl = collision_range_bl->collidingItems();

    int br = corner_colliding_br.size();
    int bl = corner_colliding_bl.size();

    if(br == 1) //if there is no collision on the bottom right or left (THE COLLISION BOX COUNTS AS A COLLISION; HENCE 1 AND NOT 0)
    {
        if( speed.x > 0)
        {
            speed.x = -speed.x;
        }
    }

    if(bl == 1)
    {
        if( speed.x < 0)
        {
            speed.x = -speed.x;
        }
    }


    {
    QString temp_collision_type;
    QList<QGraphicsItem*> colliding_items;
    collision = QList<bool>{false,false,false};

    for(int i = 0; i < 3 ; i ++)
    {
        colliding_items = collision_ranges[i]->collidingItems();
        for(int j = 0; j < colliding_items.size(); j++)
        {
            temp_collision_type = collision_master->collide("Enemy",QString(typeid(*colliding_items[j]).name()));

            if(temp_collision_type == "simple_collision")
            {
                collision[i] = true;
                continue;
            }
        }
    }
    }

    // movements of the enemy:

    switch(state)
    {
    {
    case aggressiv:
            if (collision[0])
            {
                speed.x = 0;
                jump();
            }
            if (collision[1])
            {
                speed.y = 0;
            }
            if (collision[2] && !collision[1] && !collision[0])
            {
                speed.y = 0;
            }
            break;
    }
    {
    case passiv:
            if (collision[0])
            {
                speed.x = 0;
                facing = (facing == Right) ? Left : Right;
            }
            if (collision[1])
            {
                speed.y = 0;
            }
            if (collision[2] && !collision[1] && !collision[0])
            {
                speed.y = 0;
            }
            break;
    }
    }

    //Jump reset
    if(collision[1] && speed.y >= 0)
    {
        times_jumped = 0;
    }

    //Direction of the player:
    if (speed.x>0)
    {
        facing = Right;
    }
    else if (speed.x<0)
    {
        facing = Left;
    }

    setPos(x()+speed.x,y()+speed.y);

    count+=0.2;
    if (count >= number_of_frames){
        count = 0;
    }
    setPixmap(animation[facing][int(count)]);

}

void Enemy::throw_projectile()
{    
    view->scene->addItem(new Enemy_projectile_1(pair{x(),y()},facing,size.x));
}
