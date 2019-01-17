#include "gmovingobject.h"
#include "listheaders.h"

GMovingObject::GMovingObject(QPoint speed, QPoint position, QGraphicsItem *parent):
    GObject(position, parent)
{
    for(int i = 0; i < 3 ; i ++)
    {
        collision_ranges.push_back(new QGraphicsRectItem(this));
        collision_ranges[i]->setPen(QPen(Qt::NoPen));
    }

    this->speed = speed;

    timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(view->ms_between_updates);


}

GMovingObject::~GMovingObject()
{
    if(timer != nullptr)
    {
        timer->stop();
        timer->deleteLater();
    }
}

void GMovingObject::check_in_boundaries()
{
    if(y() >= view->world_size.bottom)
    {
        speed.rx() = (0 > speed.ry()) ? speed.ry() : 0 ;
        setY(view->world_size.bottom);
        deleteLater();
        return;
    }
    if(x()<=view->world_size.left)
    {
        speed.rx() = (0 < speed.rx()) ? speed.rx() : 0 ;
        setX(view->world_size.left);
    }
    else if(x() >= view->world_size.right-sizex)
    {
        speed.rx() = (0 > speed.rx()) ? speed.rx() : 0 ;
        setX(view->world_size.right-sizex);
    }
}

void GMovingObject::update_collision_range()
{
    collision_ranges[0]->setRect(0,0,speed.rx(),sizey-2); //horizontal movement
    collision_ranges[0]->setPos((speed.rx() > 0) ? sizex : -1 ,0);

    collision_ranges[1]->setRect(0,0,sizex-2,speed.ry()); //vertical movement
    collision_ranges[1]->setPos(0,(speed.ry() > 0) ? sizey : -1);

    collision_ranges[2]->setRect(0,0,speed.rx(),speed.ry()); // corners
    collision_ranges[2]->setPos((speed.rx() > 0) ? sizex : -1, (speed.ry() > 0) ? sizey : -1);
}

void GMovingObject::simple_collision(int i, QGraphicsItem *colliding)
{
    switch(i)
    {
    case horizontal:
    {
        if(speed.rx() > 0)
        {
            speed.setX(colliding->x() - x() - sizex);
        }
        else if(speed.rx() < 0)
        {
            speed.setX(colliding->sizex + colliding->x() - x());
        }
        break;
    }
    case vertical:
    {
        if(speed.ry() > 0)
        {
            speed.setY(colliding->y() - y() - sizey);
        }
        else if(speed.ry() < 0)
        {
            speed.setY(colliding->sizey + colliding->y() - y());
        }
        break;
    }
    case diagonal:
    {
        break;
    }
    }
}

void GMovingObject::activate_block(QGraphicsItem *colliding)
{
    if(speed.ry() < -5)
    {
        view->scene->addItem(new Activated_block(pair{colliding->x(),colliding->y()}));

        create_random_powerup(pair{colliding->x(),colliding->y()},view->block_size);

        destroy_item(colliding);
    }
}

void GMovingObject::destroy_item(QGraphicsItem *colliding)
{
    view->scene->removeItem(colliding);

    delete(colliding);
}

void GMovingObject::damage_block(QGraphicsItem *colliding)
{
    int current_type = (QString(typeid(*colliding).name()))[19].digitValue();

    int power = speed.manhattanLength()/10;

    if(power == 0)
    {
        return;
    }

    destroy_item(colliding);

    switch(current_type+power)
    {
    case 2:
    {
        view->scene->addItem(new Breakable_block_2(pair{colliding->x(), colliding->y()}));
        break;
    }
    case 3:
    {
        view->scene->addItem(new Breakable_block_3(pair{colliding->x(), colliding->y()}));
        break;
    }
    }
}

void GMovingObject::move()
{
    return;
}
