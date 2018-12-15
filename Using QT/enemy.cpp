#include "enemy.h"
#include "player.h"
#include "view.h"
#include <QtDebug>
#include <QTimer>
#include <cmath>
#include "projectile.h"
#include "types_states_textures.h"
#include "tools.h"

class View;

extern View* view;

Enemy::Enemy(int size, pair position, bool direction, QGraphicsItem* parent ) : QObject (), QGraphicsPixmapItem (parent)
{

    setPos(position.x, position.y);
    setPixmap(QPixmap(":/images/main_texture_pack/enemy.png"));

    // Attributes
    int life = 100;

    if (direction == 0){ speed = pair{-5,2};}
    else { speed = pair{5,2};}

    speedMax = pair{10,15};

    direction = 0; //0 = left, 1 = right

    this->size = size;

    // Create collision Range
    collision_range_enemy = new QGraphicsRectItem(this);
    collision_range_enemy->setRect(0,0, 1.5* size, 1.5 * size);

    collision_range_enemy->setPos(0 - size/4,0 - size/4); //we readjust the position of the collision box so that is centers the player

    collision_range_enemy->setOpacity(0.5);

    // Timer
    QTimer * timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(20);


}

//coordinates of the player:
//view.player.x() and view.player.y()

bool Enemy::collision_right()
{
    if (speed.x > 0)
    {
        QList<QGraphicsItem *> colliding_items = collision_range_enemy->collidingItems();
        for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
        {
            for (int i = 0; i < size; i += 1)
            {
                if ((*iter)-> contains(QPointF(x() + (size) + (speed.x-1)  - (*iter)->x() , y() + i    -(*iter)->y() )))
                {
                    return true;
                }
            }

        }
    }

    return false;
}

bool Enemy::collision_left()
{
    if (speed.x < 0)
    {
        QList<QGraphicsItem *> colliding_items = collision_range_enemy->collidingItems();
        for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
        {
            for (int i = 0; i< size; i += 1)
            {
                if ((*iter)-> contains(QPointF(x() + (speed.x)  - (*iter)->x() , y() + i   -(*iter)->y() )))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Enemy::collision_up()
{
    if (speed.y < 0)
    {
        QList<QGraphicsItem *> colliding_items = collision_range_enemy->collidingItems();
        for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
        {
            for (int i = 0; i< size; i += 1)
            {
                if ((*iter)-> contains(QPointF(x() + i  - (*iter)->x() , y() + (speed.y)  -(*iter)->y() )))
                {
                    return true;
                }
            }

        }
    }
    return false;
}

bool Enemy::collision_down()
{
    if (speed.y > 0)
    {
        QList<QGraphicsItem *> colliding_items = collision_range_enemy->collidingItems();
        for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
        {
            for (int i = 0; i<size; i += 1)
            {
                if ((*iter)-> contains(QPointF(x() + i - (*iter)->x() , y() + (size) + (speed.y-1 )  - (*iter)->y() )))
                {
                    return true;
                }
            }
        }
    }
    return false;

}

bool Enemy::collision_b_l() //spots if the bottom left corner endures a collision both from the left and the bottom
{
    bool l = collision_left();
    bool b = collision_down();
    if(speed.y > 0 && speed.x < 0 && l == false && b == false)
    {
        QList<QGraphicsItem *> colliding_items = collision_range_enemy->collidingItems();
        for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
        {
            //(bottom left, (0,36)
            if ((*iter)-> contains(QPointF(x() + (speed.x)  - (*iter)->x() , y() + (size) + (speed.y - 1)   -(*iter)->y() )))
            {
                return true;
            }
        }
    }
    return false;
}

bool Enemy::collision_b_r() // spots if the bottom right corner endures a collision both from the right and the bottom
{
    bool r = collision_right();
    bool b = collision_down();
    if(speed.y > 0 && speed.x > 0 && r == false && b == false)
    {
        QList<QGraphicsItem *> colliding_items = collision_range_enemy->collidingItems();
        for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
        {
            //(bottom right, (36,36)
            if ((*iter)-> contains(QPointF(x() + size + (speed.x - 1)  - (*iter)->x() , y() + (size) + (speed.y - 1)   -(*iter)->y() )))
            {
                return true;
            }
        }
    }
    return false;
}

bool Enemy::collision_t_l()
{
    bool l = collision_left();
    bool t = collision_up();
    if(speed.y < 0 && speed.x < 0 && l == false && t == false)
    {
        QList<QGraphicsItem *> colliding_items = collision_range_enemy->collidingItems();
        for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
        {
            //(top left (0,0))
            if ((*iter)-> contains(QPointF(x() + speed.x - (*iter)->x() , y() + speed.y   -(*iter)->y() )))
            {
                return true;
            }
        }
    }
    return false;
}

bool Enemy::collision_t_r()
{
    bool r = collision_right();
    bool t = collision_up();
    if(speed.y < 0 && speed.x > 0 && r == false && t == false)
    {
        QList<QGraphicsItem *> colliding_items = collision_range_enemy->collidingItems();
        for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
        {
            //(top right (36,0))
            if ((*iter)-> contains(QPointF(x() + size + speed.x-1 - (*iter)->x() , y() + speed.y   -(*iter)->y() )))
            {
                return true;
            }
        }
    }
    return false;
}

void Enemy::move()
{

    int velocity = 5;

    //Motion smooth
    if (speed.y > speedMax.y)
    {
        speed.y = speedMax.y;
    }
    if (speed.y < -speedMax.y)
    {
        speed.y = -speedMax.y;
    }

    speed.y += 1;

    bool play_tl = player_pos_t_l();
    bool play_tr = player_pos_t_r();
    bool play_bl = player_pos_b_l();
    bool play_br = player_pos_b_r();

    bool block_r = block_right();
    bool block_l = block_left();
    bool block_d = block_down();
    bool block_t = block_up();

    bool r1 = collision_right();
    bool l1 = collision_left();

    /**
    qDebug() <<  "=================";
    qDebug() <<  block_right();
    qDebug() <<  block_left();
    qDebug() <<  block_up();
    qDebug() <<  block_down();

    **/

    if (play_tr == true || play_br == true) //if the player is on the right
    {
        speed.x = velocity;
        if (block_d == true && (r1 == true || block_r == true) && block_t == false) //there is a block on the bottom
        {
            speed.y = - 2* velocity ; //enemy jumps to escape the block
            setPos(x() + speed.x, y() + speed.y);
            return;
        }
    }

    if (play_tl == true || play_bl == true) //if the player is on the left
    {
        speed.x = -velocity;
        if (block_d == true && (l1 == true || block_l == true) && block_t == false)
        {
            speed.y = -2* velocity;
            setPos(x() + speed.x, y() + speed.y);
            return;
        }
    }

    bool r = collision_right();
    bool l = collision_left();
    bool t = collision_up();
    bool b = collision_down();

    bool bl = collision_b_l();
    bool br = collision_b_r();
    bool tl = collision_t_l();
    bool tr = collision_t_r();

    /**
      MUST DO A CASE WHEN THERE IS A COLLISION BETWEEN THE ENEMY AND THE PLAYER TO GIVE INTERACTION (LATER)
      MUST ALSO DO A THROW PROJECTILE Function to try and kill our player
      * how do we want the enemy to move?
      * if the player is on the right, put the velocity on +x;
      * if the player is on the left, put the velocity on -x;
      *
      * if the player is on the right:
      * if there is a block on the right and one below,the enemy attempts to jump and go the right
      * if there is a blokc on the rihgt but none below, the enemy just suffers regular collisions
      *
      * same on left
      *
      *
**/



    // movements of the enemy: regular collisions
    if (r == true){speed.x = 0; life -= 10;}
    if (l == true){speed.x = 0; life -= 10;}
    if (b == true){speed.y = 0; life -= 10;}
    if (t == true){speed.y = 0; life -= 10;}
    if (bl == true || br == true){speed.y = 0; speed.x = speed.x; life -= 10;} //if the bottom corners collide, we maintain the velocity on x, but not on y
    if (tl == true || tr == true){speed.y = 0; speed.x = speed.x; life -= 10;} //if the top corners collide, we maintain the velocity on x. but not on y

    // check y-velocity is not too big
    if (speed.y > speedMax.y)
    {
        speed.y = speedMax.y;
    }
    if (speed.y < -speedMax.y)
    {
        speed.y = -speedMax.y;
    }

    //Direction of the player:
    if (speed.x < 0){direction = 0;}
    else{direction = 1;}

    setPos(x()+speed.x,y()+speed.y);

}

bool Enemy::block_right()
{
    QList<QGraphicsItem *> colliding_items = collision_range_enemy->collidingItems();
    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
        for (int i = 0; i < size; i += 1)
        {
            if ((*iter)-> contains(QPointF(x() + (size) - (*iter)->x() , y() + i    -(*iter)->y() )))
            {
                return true;
            }
        }

    }
    return false;
}

bool Enemy::block_left()
{
    QList<QGraphicsItem *> colliding_items = collision_range_enemy->collidingItems();
    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
        for (int i = 0; i < size; i += 1)
        {
            if ((*iter)-> contains(QPointF(x() -1 - (*iter)->x() , y() + i    -(*iter)->y() )))
            {
                return true;
            }
        }

    }

    return false;
}

bool Enemy::block_down()
{
    QList<QGraphicsItem *> colliding_items = collision_range_enemy->collidingItems();
    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
        for (int i = 0; i < size; i += 1)
        {
            if ((*iter)-> contains(QPointF(x() + i - (*iter)->x() , y() + size    -(*iter)->y() )))
            {
                return true;
            }
        }

    }
    return false;
}

bool Enemy::block_up()
{
    QList<QGraphicsItem *> colliding_items = collision_range_enemy->collidingItems();
    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
        for (int i = 0; i < size; i += 1)
        {
            if ((*iter)-> contains(QPointF(x() + i - (*iter)->x() , y() -1   -(*iter)->y() )))
            {
                return true;
            }
        }

    }
    return false;
}

bool Enemy::player_pos_b_l() //is the player at the bottom left of the enemy? (not colliding though)
{
    if (view->player->x() + size < x() && view->player->y() > y() + size ) //here size should be player.size in the x part
    {
        return true;
    }
    return false;
}

bool Enemy::player_pos_b_r() //is the player at the bottom right of the enemy? (not colliding though)
{
    if (view->player->x() > x() + size  && view->player->y() > y() + size )
    {
        return true;
    }
    return false;
}

bool Enemy::player_pos_t_l() //is the player at the top left of the enemy? (horizontal included) (not colliding though)
{
    if (view->player->x() + size < x() && view->player->y()+ size <= y() + size) //here size should be player.size in the x part
    {
        return true;
    }
    return false;
}

bool Enemy::player_pos_t_r() //is the player at the top right of the enemy? (horizontal included) (not colliding though)
{
    if (view->player->x() > x() + size && view->player->y() <= y() + size )
    {
        return true;
    }
    return false;
}

bool Enemy::throwprojectile()
{
    qreal player_x = view->player->x();
    qreal player_y = view->player->y();


}

