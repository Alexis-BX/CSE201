#include "listheaders.h"

void delay(int i) //milliseconds
{
    QTime dieTime= QTime::currentTime().addMSecs(i);

    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

greal distance(pair a, pair b)
{
    greal dx = a.x-b.x;

    greal dy = a.y-b.y;

    return (dx*dx)+(dy*dy);
}

void update_collision_range(QList<QGraphicsRectItem *> &collision_ranges, pair &size, pair &speed)
{    
    collision_ranges[0]->setRect(0,0,speed.x,size.y-2); //horizontal movement
    collision_ranges[0]->setPos((speed.x > 0) ? size.x : -1 ,0);

    collision_ranges[1]->setRect(0,0,size.x-2,speed.y); //vertical movement
    collision_ranges[1]->setPos(0,(speed.y > 0) ? size.y : -1);

    collision_ranges[2]->setRect(0,0,speed.x,speed.y); // corners
    collision_ranges[2]->setPos((speed.x > 0) ? size.x : -1, (speed.y > 0) ? size.y : -1);
}
