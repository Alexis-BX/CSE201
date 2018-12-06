#include "player.h"
#include "view.h"
#include <QtDebug>
#include <QTimer>
#include <cmath>

Player::Player(QGraphicsItem* parent) : QObject (), QGraphicsPixmapItem (parent){
    QPixmap img(":/images/character_crouching.png");
    for (int i = 0; i<N; i++){
        crouch[i] = img.copy(i*size, 0, size, size);
    }
    setPixmap(crouch[0]);
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
    }
    if(x()<=world_boundaries.left){
        speed.x = (0 < speed.x) ? speed.x : 0 ;
    }
    else if(x() >= world_boundaries.right){
        speed.x = (0 > speed.x) ? speed.x : 0 ;
    }

    //animation
    count += 0.1;
    if (count>=N){count = 0;}
    setPixmap(crouch[(int) count]);

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
