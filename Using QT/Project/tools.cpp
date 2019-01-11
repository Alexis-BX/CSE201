#include "listheaders.h"


// This function is a delay function which does not stop the game
//from running at yet can delay the continuation of a function
void delay(int i) //milliseconds
{
    QTime dieTime= QTime::currentTime().addMSecs(i);

    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

//This returns the distance of 2 pairs of points using standard distance
greal distance(pair a, pair b)
{
    greal dx = a.x-b.x;

    greal dy = a.y-b.y;

    return (dx*dx)+(dy*dy);
}

// this will update the position of the collision_ranges of the moving object
// using the speed and size and collisionn rang
void update_collision_range(QList<QGraphicsRectItem *> &collision_ranges, pair &size, pair &speed)
{    
    collision_ranges[0]->setRect(0,0,speed.x,size.y-2); //horizontal movement
    collision_ranges[0]->setPos((speed.x > 0) ? size.x : -1 ,0);

    collision_ranges[1]->setRect(0,0,size.x-2,speed.y); //vertical movement
    collision_ranges[1]->setPos(0,(speed.y > 0) ? size.y : -1);

    collision_ranges[2]->setRect(0,0,speed.x,speed.y); // corners
    collision_ranges[2]->setPos((speed.x > 0) ? size.x : -1, (speed.y > 0) ? size.y : -1);
}

void create_random_powerup(pair position, double x_offset)
{
    int x = int(x_offset);
    switch(rand()%9)
    {
    {
    case 0:
            view->scene->addItem(new Power_up_1(position,x));
            break;
    }
    {
    case 1:
            view->scene->addItem(new Power_up_2(position,x));
            break;
    }
    {
    case 2:
            view->scene->addItem(new Power_up_3(position,x));
            break;
    }
    {
    case 3:
            view->scene->addItem(new Power_up_4(position,x));
            break;
    }
    {
    case 4:
            view->scene->addItem(new Power_up_5(position,x));
            break;
    }
    {
    case 5:
            view->scene->addItem(new Power_up_6(position,x));
            break;
    }
    {
    case 6:
            view->scene->addItem(new Power_up_7(position,x));
            break;
    }
    {
    case 7:
            view->scene->addItem(new Power_up_8(position,x));
            break;
    }
    }
}
