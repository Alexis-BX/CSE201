#include "player.h"
#include "view.h"
#include <QtDebug>
#include <QTimer>
#include <cmath>
#include "projectile.h"

Player::Player(QGraphicsItem* parent, int size ) : QObject (), QGraphicsPixmapItem (parent)
{

    create_animation();

    setPixmap(animations[0][0]);


    // Attributes
    count = 0;

    speed = pair{0,0};

    speedMax = pair{10,15};

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
        speed.y -= 10;
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


    QList<QGraphicsItem *> colliding_items = collision_range->collidingItems();

    for(auto iter = colliding_items.begin(); iter != colliding_items.end();iter++) //ITERATE OVER THE COLLIDING ITEMS
    {
        /**
        qDebug() << "collision";

        qDebug() << speed.x;

        qDebug() << speed.y;
        **/

        //NO COLLISION CASE
        if((*iter)->x() == x() && (*iter)->y() == y()) //
        {
            continue;
        }



        //FIRST CASE:
        if (speed.x > 0)
        {
            if(speed.y == 0) //WORKS DONT MODIFY
                //HORITZONTAL MOVEMENT TO THE RIGHT, must check for the entire height of the player if there are collisions
            {// DO WE ADD speed.x?  YES BUT IT WILL BELONG TO THE NEXT BLOCK, must retrieve -1
                // since block_size = 18, enough to check top of character and feet when the character is tall, but if he gets smaller, better to check middle too
                qDebug() << "speed.x >0, speed.y == 0";
                if ((*iter)-> contains(QPointF(x() +  (size-1)  + speed.x - (*iter)->x() , y()  -(*iter)->y() ))) //HEIGHT 0 of the player (35,0)
                {
                    speed.x = 0;
                }

                else if ((*iter)-> contains(QPointF(x() +  (size-1) + speed.x  - (*iter)->x() , y()  + size - 1 -(*iter)->y() ))) // (35,35)
                {
                    speed.x = 0;
                }

                else if ((*iter)-> contains(QPointF(x() +  (size-1) + speed.x  - (*iter)->x() , y()  + block_size - 1 -(*iter)->y() ))) // (35,17)
                {
                    speed.x = 0;
                }

                else if ((*iter)-> contains(QPointF(x() +  (size-1) + speed.x  - (*iter)->x() , y()  + block_size -(*iter)->y() ))) // (35,18)
                {
                    speed.x = 0;
                }

            }

            if (speed.y >0) //PLAYER GOES RIGHT AND DOWN: coordinates are given with respect to the COF of the player
            {
                qDebug() << "speed.x >0, speed.y > 0";
                //(0,35) collide with below right
                if ((*iter)-> contains(QPointF(x() + speed.x -1  - (*iter)->x() , y() + (size-1)  +speed.y   -(*iter)->y() )))
                {
                    speed.y = 0;
                }

                //(17,35)
                else if ((*iter)-> contains(QPointF(x() + speed.x - 1 +block_size - 1- (*iter)->x() , y() + (size-1) +speed.y  -(*iter)->y() )))
                {
                    speed.y = 0;
                }

                //(18,35)

                else if ((*iter)-> contains(QPointF(x() + speed.x - 1 + block_size - (*iter)->x() , y() + (size-1) +speed.y  -(*iter)->y() )))
                {
                    speed.y = 0;
                }

                //(35,35)  -2 because of the speed.x - 1 & size.x - 1
                else if ((*iter)-> contains(QPointF(x() + speed.x + size - 2 - (*iter)->x() , y() + (size-1) +speed.y  -(*iter)->y() )))
                {
                    speed.y = 0;
                }

                //(35,35)
                if ((*iter)-> contains(QPointF(x() + speed.x  + size - 1 - (*iter)->x() , y() + size - 1 +speed.y  -(*iter)->y() )))
                {
                    speed.x = 0;
                }

                //(35,18)
                else if ((*iter)-> contains(QPointF(x() + speed.x  + size - 1 - (*iter)->x() , y() + block_size +speed.y  -(*iter)->y() )))
                {
                    speed.x = 0;
                }

                //(35,17)
                else if ((*iter)-> contains(QPointF(x() + speed.x  + size - 1 - (*iter)->x() , y() + block_size -1 +speed.y  -(*iter)->y() )))
                {
                    speed.x = 0;
                }

                //(35,0)
                else if ((*iter)-> contains(QPointF(x() + speed.x  + size - 1 - (*iter)->x() , y() +speed.y  -(*iter)->y() )))
                {
                    speed.x = 0;
                }


            }



            if (speed.y < 0) //PLAYER GOES RIGHT AND UP: coordinates are given with respect to the COF of the player
            {
                qDebug() << "speed.x >0, speed.y < 0";
                //LEFT top corner of player (0,0) will collide with block above
                if ((*iter)-> contains(QPointF(x() + speed.x - 1 - (*iter)->x() , y()  +speed.y  -(*iter)->y() )))
                {
                    speed.y = 0;
                }

                // (17,0) will collide with block above
                else if ((*iter)-> contains(QPointF(x() + speed.x  - 1 + block_size - 1- (*iter)->x() , y()  +speed.y  -(*iter)->y() )))
                {
                    speed.y = 0;
                }

                //(18,0) will collide with block above
                else if ((*iter)-> contains(QPointF(x() + speed.x - 1 + block_size - (*iter)->x() , y()  +speed.y  -(*iter)->y() )))
                {
                    speed.y = 0;
                }

                //(35,0) will collide with block above
                else if ((*iter)-> contains(QPointF(x() + speed.x - 1 + size - 1 - (*iter)->x() , y()  +speed.y  -(*iter)->y() )))
                {
                    speed.y = 0;
                }

                //(35,0) (TOP RIGHT of block will collide with block above)
                if ((*iter)-> contains(QPointF(x() + speed.x - 1 + size  - (*iter)->x() , y()  +speed.y  -(*iter)->y() ))) //-1 in the x?
                {
                    speed.x = 0;
                }
                //(35,17) collides
                else if ((*iter)-> contains(QPointF(x() + speed.x - 1 + size - (*iter)->x() , y()  +speed.y + block_size - 1 -(*iter)->y() ))) //-1 in the x?
                {
                    speed.x = 0;
                }

                //(35,18)
                else if ((*iter)-> contains(QPointF(x() + speed.x - 1 + size - (*iter)->x() , y()  +speed.y + block_size -(*iter)->y() ))) //-1 in the x?
                {
                    speed.x = 0;
                }
                //(35,35)
                else if ((*iter)-> contains(QPointF(x() + speed.x - 1  + size - (*iter)->x() , y()  +speed.y + size - 1 -(*iter)->y() )))
                {
                    speed.x = 0;
                }
            }

        } //end of first case


// SECOND CASE:
        if (speed.x < 0)  //PLAYER GOES LEFT
        {
            if (speed.y == 0)
            { /**
                same principle as before, but this time no need to adjust by 1 as the block is at the right point. The speed when the character goes back
                backwards is already negative so can keep +speed.x
                **/

                qDebug() << "speed.x <0, speed.y == 0";
                if ((*iter)-> contains(QPointF(x() + speed.x  - (*iter)->x() , y()  -(*iter)->y() ))) //HEIGHT 0 of the player (0,0)
                {
                    speed.x = 0;
                }

                else if ((*iter)-> contains(QPointF(x() +  speed.x  - (*iter)->x() , y()  + size - 1 -(*iter)->y() ))) //  (0,35)
                {
                    speed.x = 0;
                }

                else if ((*iter)-> contains(QPointF(x() +  speed.x  - (*iter)->x() , y()  + block_size -(*iter)->y() ))) // (0,18)
                {
                    speed.x = 0;
                }

                else if ((*iter)-> contains(QPointF(x() +  speed.x  - (*iter)->x() , y()  + block_size - 1 -(*iter)->y() ))) // (0,17)
                {
                    speed.x = 0;
                }


            }

            if (speed.y < 0) //PLAYER GOES LEFT AND UP
            {   qDebug() << "speed.x <0, speed.y < 0";
                //(0,35)
                if ((*iter)-> contains(QPointF(x() + speed.x- (*iter)->x() , y() + speed.y + size - 1  -(*iter)->y() )))
                {
                    speed.x = 0;
                }

                //(0,18)
                else if ((*iter)-> contains(QPointF(x() + speed.x- (*iter)->x() , y() + speed.y + block_size  -(*iter)->y() )))
                {
                    speed.x = 0;
                }

                //(0,17)

                else if ((*iter)-> contains(QPointF(x() + speed.x- (*iter)->x() , y() + speed.y + block_size - 1  -(*iter)->y() )))
                {
                    speed.x = 0;
                }

                //(0,0)
                else if ((*iter)-> contains(QPointF(x() + speed.x- (*iter)->x() , y() + speed.y   -(*iter)->y() )))
                {
                    speed.x = 0;
                }

                //(0,0)
                if ((*iter)-> contains(QPointF(x() + speed.x- (*iter)->x() , y() + speed.y   -(*iter)->y() )))
                {
                    speed.y = 0;
                }

                //(17,0)
                else if ((*iter)-> contains(QPointF(x() + speed.x + block_size - 1 - (*iter)->x() , y() + speed.y   -(*iter)->y() )))
                {
                   speed.y = 0;
                }

                //(18,0)
                else if ((*iter)-> contains(QPointF(x() + speed.x + block_size - (*iter)->x() , y() + speed.y   -(*iter)->y() )))
                {
                   speed.y = 0;
                }

                //(35,0)

                else if ((*iter)-> contains(QPointF(x() + speed.x + size - 1 - (*iter)->x() , y() + speed.y   -(*iter)->y() )))
                {
                   speed.y = 0;
                }


            }


            if (speed.y > 0) //player goes left and down
            {   qDebug() << "speed.x < 0, speed.y > 0";

                //(0,35) collides with a block bottom left
                if ((*iter)-> contains(QPointF(x() + speed.x - (*iter)->x() , y() + speed.y +size - 2 -(*iter)->y() )))
                {
                    speed.x = 0;
                }
                //(0,0) collides with a block bottom left
                else if ((*iter)-> contains(QPointF(x() + speed.x - (*iter)->x() , y() + speed.y -1 -(*iter)->y() )))
                {
                    speed.x = 0;
                }

                //(0,17)
                else if ((*iter)-> contains(QPointF(x() + speed.x - (*iter)->x() , y() + speed.y +block_size -2 -(*iter)->y() )))
                {
                    speed.x = 0;
                }

                //(0,18)
                else if ((*iter)-> contains(QPointF(x() + speed.x - (*iter)->x() , y() + speed.y + block_size - 1-(*iter)->y() )))
                {
                    speed.x = 0;
                }



                //(0,35)
                if ((*iter)-> contains(QPointF(x() + speed.x - (*iter)->x() , y() + speed.y + size - 1 -(*iter)->y() )))
                {
                    speed.y = 0;
                }

                //(17,35)
                else if ((*iter)-> contains(QPointF(x() + speed.x + block_size - 1 - (*iter)->x() , y() + speed.y + size - 1-(*iter)->y() )))
                {
                    speed.y = 0;
                }

                //(18,35)
                else if ((*iter)-> contains(QPointF(x() + speed.x + block_size - (*iter)->x() , y() + speed.y + size - 1-(*iter)->y() )))
                {
                    speed.y = 0;
                }

                //(35,35)
                else if ((*iter)-> contains(QPointF(x() + speed.x + size - 1 - (*iter)->x() , y() + speed.y + size - 1-(*iter)->y() )))
                {
                    speed.y = 0;
                }
            }

        } //end of case 2


//THIRD CASE:
        if (speed.x == 0)  //DONE DONE DONE IT WORKS
        {

            if (speed.y > 0) //character goes straight down
            {   qDebug() << "speed.x == 0, speed.y > 0";
                //(0,35)
                if ((*iter)-> contains(QPointF(x() - (*iter)->x() , y() + size + speed.y - 1 -(*iter)->y() ))) //width 0
                {
                    speed.y = 0;
                }
                //(17,35)
                else if ((*iter)-> contains(QPointF(x() + block_size -1  - (*iter)->x() , y() + size + speed.y - 1 -(*iter)->y() ))) //width 17 of the player
                {
                    speed.y = 0;
                }
                //(18,35)
                else if ((*iter)-> contains(QPointF(x() + block_size - (*iter)->x() , y() + size + speed.y - 1 -(*iter)->y() ))) //width 18 of the player
                {
                    speed.y = 0;
                }
                //(35,35)
                else if ((*iter)-> contains(QPointF(x() + size - 1 - (*iter)->x() , y() + size + speed.y - 1 -(*iter)->y() ))) //width size -1 of the player
                {
                    speed.y = 0;
                }
            }


            if (speed.y < 0) //character jummps straight up
            {   qDebug() << "speed.x == 0, speed.y < 0";
                //(0,0)
                if ((*iter)-> contains(QPointF(x() - (*iter)->x() , y() + speed.y -(*iter)->y() )))
                {
                    speed.y = 0 ;
                }
                //(17,0)
                else if ((*iter)-> contains(QPointF(x() + block_size - 1 - (*iter)->x() , y() + speed.y -(*iter)->y() )) )
                {
                    speed.y = 0;
                }
                //(18,0)
                else if ((*iter)-> contains(QPointF(x() + block_size - (*iter)->x() , y() + speed.y  -(*iter)->y() )) )
                {
                    speed.y = 0;
                }
                //(35,0)
                else if ((*iter)-> contains(QPointF(x() + size - 1 - (*iter)->x() , y()  + speed.y  -(*iter)->y() )) )
                {
                    speed.y = 0;
                }
            }



        } //end of third case

    } //end of for loop


    //Direction of the player:
    if (pressedR){direction = 1;}
    if (pressedL){direction = 0;}

    setPos(x()+speed.x,y()+speed.y);

    view->centerOn(this);
}

void Player::throwprojectile(int i)
{

    // for the directino of the projectile: define a "last velocity speed"
    // then the direction is the direction of this last velocity
    if(i == 1)
    {
        if (direction == 1)
        {   // the player faces right, the projectile is thrown to the right
            Projectile* projectile = new Projectile(pair{int(x() + size ),int(y() +  size/4)}, direction, Projectile_type{baguette});
            view->scene->addItem(projectile);
        }
        else
        {   //the player faces left, the projectile is thrown to the left, and initial position just left of the player
            // -19... we would like -projectile.size.x - 1
            Projectile* projectile = new Projectile(pair{int(x() -19 ),int(y() +  size/4)}, direction, Projectile_type{baguette});
            view->scene->addItem(projectile);
        }
    }

    if(i == 2)
    {
        if (direction == 1)
        {   // the player faces right, the projectile is thrown to the right
            Projectile* projectile = new Projectile(pair{int(x() + size ),int(y() +  size/4)}, direction, Projectile_type{wine});
            view->scene->addItem(projectile);
        }
        else
        {   //the player faces left, the projectile is thrown to the left, and initial position just left of the player
            // -19... we would like -projectile.size.x - 1
            Projectile* projectile = new Projectile(pair{int(x() -19 ),int(y() +  size/4)}, direction, Projectile_type{wine});
            view->scene->addItem(projectile);
        }
    }

    if(i == 3)
    {
        if (direction == 1)
        {   // the player faces right, the projectile is thrown to the right
            Projectile* projectile = new Projectile(pair{int(x() + size ),int(y() +  size/4)}, direction, Projectile_type{smoke});
            view->scene->addItem(projectile);
        }
        else
        {   //the player faces left, the projectile is thrown to the left, and initial position just left of the player
            // -19... we would like -projectile.size.x - 1
            Projectile* projectile = new Projectile(pair{int(x() -19 ),int(y() +  size/4)}, direction, Projectile_type{smoke});
            view->scene->addItem(projectile);
        }
    }
}

void Player::create_animation()
{
    QPixmap imgChar(":/images/characterT.png");

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

void Player::create_collision_range()
{
    collision_range = new QGraphicsRectItem(this);

    collision_range->setRect(0,0,size + size/2, size + size/2);

    collision_range->setPos(x() - size /4 ,y() - size / 4); //we readjust the position of the collision box so that is centers the player

    collision_range->setPen(QPen(Qt::NoPen));
}
