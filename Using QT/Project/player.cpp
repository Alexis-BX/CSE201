#include <QtDebug>
#include <QTimer>
#include <cmath>
#include "projectile.h"
#include "projectiles.h"
#include "collectable.h"
#include "tools.h"
#include "enemy.h"
#include "player.h"
#include "view.h"
#include "global.h"

Player::Player(QGraphicsItem* parent, int size ) : QObject (), QGraphicsPixmapItem (parent)
{

    create_animation();

    setPixmap(animations[0][0]);


    // Attributes
    count = 0;

    speed = pair{0,0};

    speedMax = pair{10,25};

    block_size = 18;

    direction = 1; //0 = left, 1 = right

    this->size = size;


    // Timer
    QTimer * timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(20);

    // Create collision Range
    create_collision_range();
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


void Player::create_enemy()
{   //condition to create enemy... - decide and add and if condition
        Enemy* enemy = new Enemy(36, pair{x()+2* size,y() -50 }, abs(direction-1));
        view->scene->addItem(enemy);
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
            setPixmap(animations[7][int(count)]);//flip
        }
        else{
            setPixmap(animations[8][int(count)]);//flip
        }
    }
    else if(speed.x>0){
        if (speed.y<0){
            setPixmap(animations[2][int(count)]);
        }
        else{
            setPixmap(animations[3][int(count)]);
        }
    }
    else{
        if (speed.y<0){
            setPixmap(animations[1][int(count)]);
        }
        else{
            setPixmap(animations[0][int(count)]);
        }
    }

    speed.y += 1;

    bool r = collision_right();
    bool l = collision_left();
    bool t = collision_up();
    bool b = collision_down();
    bool bl = collision_b_l();
    bool br = collision_b_r();
    bool tl = collision_t_l();
    bool tr = collision_t_r();


    // movements of the player:
    if (r == true){speed.x = 0;}
    if (l == true){speed.x = 0;}
    if (b == true){speed.y = 0;}
    if (t == true){speed.y = 0;}
    if (bl == true || br == true){speed.y = 0; speed.x = speed.x;} //if the bottom corners collide, we maintain the velocity on x, but not on y
    if (tl == true || tr == true){speed.y = 0; speed.x = speed.x;} //if the top corners collide, we maintain the velocity on x. but not on y

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
    if (pressedR){direction = 1;}
    if (pressedL){direction = 0;}

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

void Player::count_coins(Collectable collectable)
{
    int count = 0;
    if (collectable.type == coin)
    {
        if (collectable.state == used)
        {
            count += 1;
        }
    }
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
            setPixmap(animations[7][int(count)]);//flip
        }
        else{
            setPixmap(animations[8][int(count)]);//flip
        }
    }
    else if(speed.x>0){
        if (speed.y<0){
            setPixmap(animations[2][int(count)]);
        }
        else{
            setPixmap(animations[3][int(count)]);
        }
    }
    else{
        if (speed.y<0){
            setPixmap(animations[1][int(count)]);
        }
        else{
            setPixmap(animations[0][int(count)]);
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
    if (collectable.type == star)
    {
        speed.x *= 2;
        speed.y *= 2;
    }

    if (collectable.type == mushroom)
    {
        size *= 2;
    }

    if (collectable.type == eclair)
    {
        Projectile* projectile = new Projectile(pair{x() + size, y() + size/4}, direction, Projectile_type{pot});
    }
}

void Player::create_animation()
{
    QPixmap imgChar(gtexture->get_path_to(basic_player));

    for (int j = 0; j<M-toMirror; j++)
    {
        for (int i = 0; i<N; i++)
        {
            animations[j][i] = imgChar.copy(i*size, j*size, size, size);
        }
    }

    QImage img = imgChar.toImage();
    QImage imgM = img.mirrored(true, false);
    QPixmap mirrored = QPixmap::fromImage(imgM);


    int lines[toMirror];

    lines[0] = 1; lines[1] = 2; lines[2] = 3; lines[3] = 5;

    for (int j = 0; j<toMirror; j++)
    {
        for (int i = 0; i<N; i++)
        {
            animations[j+(M-toMirror)][i] = mirrored.copy(i*size, lines[j]*size, size, size);
        }
    }
}


