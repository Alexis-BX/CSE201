#include <QtDebug>
#include <QTimer>
#include <cmath>
#include "projectile.h"
#include "projectiles.h"
#include "collectable.h"
#include "collectables.h"
#include "tools.h"
#include "enemy.h"
#include "player.h"
#include "view.h"
#include "global.h"

Player::Player(QGraphicsItem* parent, int size ) : QObject (), QGraphicsPixmapItem (parent)
{

    create_animation();

    setPixmap(animations[super][direction][0][0]);

    // Attributes
    count = 0;

    speed = pair{0,0};

    speedMax = pair{10,15};

    direction = true; //false = left, true = right

    this->size = size;


    // Create collision Range
    create_collision_range();


    // Timer
    QTimer * timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(20);
}

/**NOTE:
 *  FOR THE moment i made it so the player chooses the items he throws just for testing collisions
 * the designs i made are shit and i know it but again its just to test
 *
 * - adrien
 *
 *
 *
 *
 * **/

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        pressedL=true;
    }
    else if (event->key() == Qt::Key_Right)
    {
        pressedR=true;
    }
    else if (event->key() == Qt::Key_Up)
    {
        speed.y -= speedMax.y;
        if (speed.x == 0.0){
            state = jumpV;
        }
        else{
            state = jumpV;
        }
    }
    else if(event->key() == Qt::Key_1)
    {
        throwprojectile(1);
    }

    else if(event->key() == Qt::Key_2)
    {
        throwprojectile(2);
    }

    else if(event->key() == Qt::Key_3)
    {
        throwprojectile(3);
    }
    else if(event->key() == Qt::Key_4)
    {
        throwprojectile(4);
    }
    else if(event->key() == Qt::Key_5)
    {
        create_enemy();
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        pressedL = false;
    }
    else if (event->key() == Qt::Key_Right)
    {
        pressedR = false;
    }
}

void Player::create_enemy()
{   //condition to create enemy... - decide and add and if condition
        view->scene->addItem(new Enemy(36, pair{x()+2* size,y() -50 }, abs(direction-1)));
}

bool Player::collision_right()
{
    if (speed.x > 0)
    {
        QList<QGraphicsItem *> colliding_items = collision_range->collidingItems();
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

bool Player::collision_left()
{
    if (speed.x < 0)
    {
        QList<QGraphicsItem *> colliding_items = collision_range->collidingItems();
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

bool Player::collision_up()
{
    if (speed.y < 0)
    {
        QList<QGraphicsItem *> colliding_items = collision_range->collidingItems();
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

bool Player::collision_down()
{
    if (speed.y > 0)
    {
        QList<QGraphicsItem *> colliding_items = collision_range->collidingItems();
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

bool Player::collision_b_l() //spots if the bottom left corner endures a collision both from the left and the bottom
{
    bool l = collision_left();
    bool b = collision_down();
    if(speed.y > 0 && speed.x < 0 && l == false && b == false)
    {
        QList<QGraphicsItem *> colliding_items = collision_range->collidingItems();
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

bool Player::collision_b_r() // spots if the bottom right corner endures a collision both from the right and the bottom
{
    bool r = collision_right();
    bool b = collision_down();
    if(speed.y > 0 && speed.x > 0 && r == false && b == false)
    {
        QList<QGraphicsItem *> colliding_items = collision_range->collidingItems();
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

bool Player::collision_t_l()
{
    bool l = collision_left();
    bool t = collision_up();
    if(speed.y < 0 && speed.x < 0 && l == false && t == false)
    {
        QList<QGraphicsItem *> colliding_items = collision_range->collidingItems();
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

bool Player::collision_t_r()
{
    bool r = collision_right();
    bool t = collision_up();
    if(speed.y < 0 && speed.x > 0 && r == false && t == false)
    {
        QList<QGraphicsItem *> colliding_items = collision_range->collidingItems();
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

void Player::move()
{
    //Accelerate
    speed.y += 1;


    //Motion smooth
    if (pressedL)
    {
        if (speed.x>-speedMax.x)
        {
            speed.x -= 1;
        }
    }
    else
    {
        if (speed.x<-1)
        {
            speed.x -= speed.x/2;
        }
        else if (speed.x<0)
        {
            speed.x=0;
        }
    }

    if (pressedR)
    {
        if (speed.x<speedMax.x)
        {
            speed.x += 1;
        }
    }
    else
    {
        if (speed.x>1)
        {
            speed.x -= speed.x/2;
        }
        else if (speed.x>0)
        {
            speed.x=0;
        }
    }

    if (speed.y > speedMax.y)
    {
        speed.y = speedMax.y;
    }
    else if (speed.y < -speedMax.y)
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



    bool r = collision_right();
    bool l = collision_left();
    bool t = collision_up();
    bool b = collision_down();
    bool bl = collision_b_l();
    bool br = collision_b_r();
    bool tl = collision_t_l();
    bool tr = collision_t_r();



    // movements of the player:
    if (r == true)
    {
        speed.x = 0;
    }
    if (l == true)
    {
        speed.x = 0;
    }
    if (b == true)
    {
        speed.y = 0;
    }
    if (t == true)
    {
        speed.y = 0;
    }
    if (bl == true || br == true)
    {
        //if the bottom corners collide, we maintain the velocity on x, but not on y
        speed.y = 0; speed.x = speed.x;
    }
    if (tl == true || tr == true)
    {
        //if the top corners collide, we maintain the velocity on x. but not on y
        speed.y = 0; speed.x = speed.x;
    }

    //Direction of the player:
    if (speed.x>0)
    {
        direction = 1;
    }
    else if (speed.x<0)
    {
        direction = 0;
    }


    //superpowers timer
    if (super)
    {
        count_super += 1;
    }
    if (count_super > 50)
    {
        super = false;
    }

    if (super_fast)
    {
        count_super +=1;
    }
    if (count_super > 50)
    {
        super_fast = false;
    }

    if (super_throw)
    {
        count_super +=1;
    }
    if (count_super > 50)
    {
        super_fast = false;
    }

    //animation
    count += 0.2;

    set_animation_state(b);

    if (count >= maxFrame[state])
    {
        count = 0;
    }
    if (count < 0)
    {
        count = maxFrame[state]-0.00001;
    }

    setPixmap(animations[super][direction][state][int(count)]);

    setPos(x()+speed.x,y()+speed.y);

    view->centerOn(this);
}

void Player::create_collision_range()
{
    collision_range = new QGraphicsRectItem(this);

    collision_range->setRect(0,0,size + size/2, size + size/2);

    collision_range->setPos(x() - size /4 ,y() - size / 4); //we readjust the position of the collision box so that is centers the player

    collision_range->setOpacity(0);
}

/***
 * Trying another move method
 ***/

/**
void Player::create_collision_range()
{
    collision_range = new QGraphicsRectItem(this);

    collision_range->setRect(0, 0, size, size);

    collision_range->setPos(0, 0); //we readjust the position of the collision box so that is centers the player

    //collision_range->setPen(QPen(Qt::NoPen));
}

void Player::move()
{

    speed.y += 1;

    //Motion smooth
    if (pressedL){
        if (speed.x>-speedMax.x){speed.x -= 1;}
    }
    else{
        if (speed.x<-1){speed.x -= speed.x/2;}
        else if (speed.x<0){speed.x=0;}
    }
    if (pressedR){
        if (speed.x<speedMax.x){speed.x += 1;}
    }
    else{
        if (speed.x>1){speed.x -= speed.x/2;}
        else if (speed.x>0){speed.x=0;}
    }
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

    //animation
    if (speed.x<0){count -= 0.1;}
    else{count += 0.1;}

    if (count>=N){count = 0;}
    if (count< 0){count = N-0.00001;}

    if (speed.x<0){
        if (speed.y<0){
            setPixmap(animations[super][direction][7][int(count)]);//flip
        }
        else{
            setPixmap(animations[super][direction][8][int(count)]);//flip
        }
    }
    else if(speed.x>0){
        if (speed.y<0){
            setPixmap(animations[super][direction][2][int(count)]);
        }
        else{
            setPixmap(animations[super][direction][3][int(count)]);
        }
    }
    else{
        if (speed.y<0){
            setPixmap(animations[super][direction][1][int(count)]);
        }
        else{
            setPixmap(animations[super][direction][0][int(count)]);
        }
    }


    collision_range->setPos(speed.x,speed.y);

    QList<QGraphicsItem *> colliding_items = collision_range->collidingItems();


    pair temp_ratio{1,1},final_ratio{1,1},collision_vector;

    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
        if((*iter)->x() == x() && (*iter)->y() == y())
        {
            continue;
        }

        //set the collision vector x
        if(speed.x > 0)
        {
            collision_vector.x = (*iter)->x()-x()-size;
        }
        else if(speed.x < 0)
        {
            collision_vector.x = (*iter)->x()+block_size-x();
        }

        //set the collision vector y
        if(speed.y > 0)
        {
            collision_vector.y =(*iter)->y()-y()-size;
        }
        else if(speed.y < 0)
        {
            collision_vector.y = (*iter)->y()+block_size-y();
        }

        // computer temp ratios
        temp_ratio.x = (speed.x != 0) ? (collision_vector.x)/speed.x : 0;
        temp_ratio.y = (speed.y != 0) ? (collision_vector.y)/speed.y : 0;

        //temp_ratio.x = max_of<greal>(temp_ratio);
        //temp_ratio.y = temp_ratio.x;



        //update fianl ration we want to it be between 1 and -1 (it starts at 1 only decreases and is bounded by -1)
        final_ratio.x = max<greal>(min<greal>(temp_ratio.x,final_ratio.x),-1);
        final_ratio.y = max<greal>(min<greal>(temp_ratio.y,final_ratio.y),-1);
    }

    //update speed
    speed.x = int(speed.x * final_ratio.x);
    speed.y = int(speed.y * final_ratio.y);


    //Direction of the player:
    if (pressedR){direction = 1;}
    if (pressedL){direction = 0;}

    setPos(x()+speed.x,y()+speed.y);

    view->centerOn(this);
}
**/


void Player::throwprojectile(int i)
{

    // for the directino of the projectile: define a "last velocity speed"
    // then the direction is the direction of this last velocity
    pair position{x(),y()};

    switch (i)
    {
    case 1:
    {
        view->scene->addItem(new Player_projectile_1(position, direction, size));
        break;
    }

    case 2:
    {
        view->scene->addItem(new Player_projectile_2(position, direction, size));
        break;
    }

    case 3:
    {
        view->scene->addItem(new Player_projectile_3(position, direction, size));
        break;
    }

    case 4:
    {
        view->scene->addItem(new Enemy_projectile_1(position, direction, size));
        break;
    }
    }
}

void Player::superpower(Collectable collectable)
{
    if (collectable.type == star) //mario clignotte
    {
        count_super = 0;
        super = true;
    }

    if (collectable.type == mushroom)
    {
        count_super = 0;
        speed.x *= 2;
        super_fast = true;
    }

    if (collectable.type == eclair)
    {
        count_super = 0;
        view->scene->addItem(new Player_projectile_3(pair{x(),y()}, direction, size));
        super_throw = true;
    }
}

void Player::set_animation_state(bool b)
{
    switch(state)
    {
        case jumpH:
            if (count>=maxFrame[jumpH])
            {
                state = fallH;
            }
            break;

        case landH:
            if (count>=maxFrame[landH])
            {
                state = run;
            }
            break;

        case jumpV:
            if (count>=maxFrame[jumpV])
            {
                state = fallV;
            }
            break;

        case landV:
            if (count>=maxFrame[landV])
            {
                state = stand;
            }
            break;

        default:
            if (b)
            {
                if (state==fallH)
                {
                    state = landH;
                }
                else if (state == fallV)
                {
                    state = landV;
                }
                else if (speed.x == 0.0)
                {
                    state = stand;
                }
                else
                {
                    state = run;
                }
            }
            else
            {
                if (speed.x == 0.0)
                {
                    state = fallV;
                }
                else
                {
                    state = fallH;
                }
            }
    }

    if (state != oldState)
    {
        oldState = state;
        count = 0;
    }
}

void Player::create_animation()
{
    QPixmap imgChar(gtexture->get_path_to(basic_player));

    for (int j = 0; j<M; j++)
    {
        for (int i = 0; i<maxFrame[j]; i++)
        {
            //generate images looking left
            animations[0][1][j][i] = imgChar.copy(i*size, j*size, size, size);

            //generate images looking right
            QImage img = imgChar.copy(i*size, j*size, size, size).toImage();
            img = img.mirrored(true, false);
            animations[0][0][j][i] = QPixmap::fromImage(img);


            //Generate super images looking left
            animations[1][1][j][i] = imgChar.copy(i*size, (M+j)*size, size, size);

            //Generate super images looking right
            QImage imgs = imgChar.copy(i*size, (M+j)*size, size, size).toImage();
            imgs = imgs.mirrored(true, false);
            animations[1][0][j][i] = QPixmap::fromImage(imgs);

        }
    }
}


