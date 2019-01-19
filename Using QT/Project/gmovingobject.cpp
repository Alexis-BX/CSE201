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
    timer->stop();
    timer->deleteLater();
    for(int i = 0; i < collision_ranges.size(); i++)
    {
        delete(collision_ranges[i]);
    }
}

void GMovingObject::check_in_boundaries()
{
    if(y() >= view->world_size.bottom)
    {
        gstate = Dead;
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
            speed.setX(max<qreal>(colliding->x() - x() - sizex,0));
        }
        else if(speed.rx() < 0)
        {
            speed.setX(min<qreal>(colliding->sizex + colliding->x() - x(),0));
        }
        break;
    }
    case vertical:
    {
        if(speed.ry() > 0)
        {
            speed.setY(max<qreal>(colliding->y() - y() - sizey,0));
            touching_ground = true;
        }
        else if(speed.ry() < 0)
        {
            speed.setY(min<qreal>(colliding->sizey + colliding->y() - y(),0));
        }
        break;
    }
    case diagonal:
    {
        break;
    }
    }
}

void GMovingObject::activate_block(int direction, QGraphicsItem *colliding)
{
    if(speed.ry() < -5 && direction == vertical)
    {
        view->scenes[scene_level]->addItem(new Activated_block(pair{colliding->x(),colliding->y()}));

        create_random_powerup(pair{colliding->x(),colliding->y()},view->block_size);

        simple_collision(direction, colliding);

        destroy_item(colliding);
    }
    else
    {
        simple_collision(direction, colliding);
    }
}

void GMovingObject::destroy_item(QGraphicsItem *colliding)
{
    view->scenes[scene_level]->removeItem(colliding);

    delete(colliding);
}

void GMovingObject::damage_block(int direction, QGraphicsItem *colliding)
{
    int current_type = (QString(typeid(*colliding).name()))[18].digitValue();

    int power;

    if(get_name() == "Player")
    {
        switch(direction)
        {
        case horizontal:
        {
            power = abs(speed.rx())/6;
            break;
        }
        case vertical:
        {
            power = abs(speed.ry())/6;
            break;
        }
        default:
        {
            simple_collision(direction, colliding);
            return;
        }
        }

        if(power == 0)
        {
            simple_collision(direction, colliding);
            return;
        }
    }
    else
    {
        if(direction != horizontal)
        {
            simple_collision(direction, colliding);
            return;
        }
        if(QString(typeid(*this).name()) == "19Player_projectile_2")
        {
            power = 5;
        }
        else
        {
            power = 1;
        }
    }


    switch(current_type+power)
    {
    case 2:
    {
        view->scenes[scene_level]->addItem(new Breakable_block_2(pair{colliding->x(), colliding->y()}));
        break;
    }
    case 3:
    {
        view->scenes[scene_level]->addItem(new Breakable_block_3(pair{colliding->x(), colliding->y()}));
        break;
    }
    }

    simple_collision(direction, colliding);

    destroy_item(colliding);
}

void GMovingObject::collide()
{
    QString temp_collision_type;
    QList<QGraphicsItem*> colliding_items;
    for(int direction = 0; direction < 3; direction ++)
    {
        colliding_items  = collision_ranges[direction]->collidingItems();

        for(int j = 0; j < colliding_items.size(); j++)
        {
            temp_collision_type = collision_master->collide(get_name(),QString(typeid(*colliding_items[j]).name()));

            if(temp_collision_type == "simple_collision")
            {
                simple_collision(direction, colliding_items[j]);
            }
            else if(temp_collision_type == "active_collision") //deactivates an active block
            {
                activate_block(direction, colliding_items[j]);
            }
            else if(temp_collision_type == "add_coin") //collision with cheese
            {
                view->player->coin_counter->add_coin();

                destroy_item(colliding_items[j]);
            }
            else if(temp_collision_type == "power") //collision with power up
            {
                int last_char = (QString(typeid(*colliding_items[j]).name()))[11].digitValue();

                view->player->power_up(last_char-1);

                destroy_item(colliding_items[j]);
            }
            else if(temp_collision_type == "damage_block") //collision with breakable block
            {
                damage_block(direction, colliding_items[j]);
            }
            else if(temp_collision_type == "end_collision") //collision with end_block
            {
                gstate = Win;
                return;
            }
            else if(temp_collision_type == "die") //collision with enemy
            {
                if(view->player->supers_b[super])
                {
                    destroy_item(colliding_items[j]);
                }
                else
                {
                    gstate = Dead;
                    return;
                }
            }
            else if(temp_collision_type == "enemy_collision")
            {
                simple_collision(direction, colliding_items[j]);

                destroy_item(colliding_items[j]);
            }

            else if(temp_collision_type == "power_player")
            {
                gstate = Dead;
                int last_char = (QString(typeid(this).name()))[11].digitValue();

                view->player->power_up(last_char-1);
            }
        }
    }
}

QString GMovingObject::get_name()
{
    return "GMovingObject";
}

void GMovingObject::move()
{
    return;
}
