#include "player.h"
#include "view.h"
#include <QtDebug>
#include <QTimer>
#include <cmath>

Player::Player(QGraphicsItem* parent) : QObject (), QGraphicsPixmapItem (parent){

    QPixmap imgChar(":/images/character.png");
    for (int j = (int)0; j<M; j++){
        for (int i = (int)0; i<N; i++){
            animations[j][i] = imgChar.copy(i*size, j*size, size, size);
        }
    }

    setPixmap(animations[0][0]);
    count = 0;

    speed = pair{0,0};
    speedMax = pair{5,10};

    QTimer * timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(20);

    world_boundaries = double_pair{0,1000,-36,-100}; //PIXELS ATTENTION

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        pressedL=true;
    }
    else if (event->key() == Qt::Key_Right){
        pressedR=true;
    }
    else if (event->key() == Qt::Key_Space){
        speed.y -= 10;
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
    if(y()>=world_boundaries.bottom){
        speed.y = (0 > speed.y) ? speed.y : 0 ;
        setY(world_boundaries.bottom);
    }
    if(x()<=world_boundaries.left){
        speed.x = (0 < speed.x) ? speed.x : 0 ;
        setX(world_boundaries.left);
    }
    else if(x() >= world_boundaries.right){
        speed.x = (0 > speed.x) ? speed.x : 0 ;
        setX(world_boundaries.right);
    }

    //animation
    count += 0.1;
    if (count>=N){count = 0;}
    if (speed.x<0){
        if (speed.y<0){
            setPixmap(animations[2][(int) count]);//flip
        }
        else{
            setPixmap(animations[3][(int) count]);//flip
        }
    }
    else if(speed.x>0){
        if (speed.y<0){
            setPixmap(animations[2][(int) count]);
        }
        else{
            setPixmap(animations[3][(int) count]);
        }
    }
    else{
        if (speed.y<0){
            setPixmap(animations[1][(int) count]);
        }
        else{
            setPixmap(animations[0][(int) count]);
        }
    }

    setPos(x()+speed.x,y()+speed.y);

    view->centerOn(this);
}


void Player::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        pressedL = false;
    }
    else if (event->key() == Qt::Key_Right){
        pressedR = false;
    }
}
