#include "listheaders.h"

Projectile::Projectile(pair position, bool direction, int character_size_x, pair size, QGraphicsItem* parent) :
    QObject (), QGraphicsPixmapItem (parent)
{
    state = alive;

    this->size = size;

    setZValue(layer_projectile);

    setPos(position.x + ((direction) ? character_size_x : -size.x), position.y);


    collision_ranges = create_collision_range<Projectile>(this);



    //Timer
    timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(view->ms_between_updates);

}

Projectile::~Projectile()
{
    qDebug() << "Pojectile_deletion";

    timer->stop();
    timer->deleteLater();

    for(int i = 0; i < collision_ranges.size(); i++)
    {
        delete(collision_ranges[i]);
    }
}

void Projectile::explode()
{
    setPixmap(QPixmap(gtexture->get_path_to(projectile_vanish_effect)));

    setPos(x()-10,y()-10);

    delay(200);

    QObject::deleteLater();
}

void Projectile::move()
{
    life -= 1;

    update_collision_range(collision_ranges, size, speed);

    {
    QString temp_collision_type;
    QList<QGraphicsItem*> colliding_items;
    collision = QList<bool>{false,false,false};

    for(int i = 0; i < 3 ; i ++)
    {
        colliding_items = collision_ranges[i]->collidingItems();
        for(int j = 0; j < colliding_items.size(); j++)
        {
            temp_collision_type = collision_master->collide("Projectile",QString(typeid(*colliding_items[j]).name()));

            if(temp_collision_type == "simple_collision")
            {
                collision[i] = true;
                continue;
            }
        }
    }
    }

    // If it has collided or gone outside the world or is out of life it explodes
    if (collision[0] || collision[1] || collision[2]
            || y() >= view->world_size.bottom || y() <= view->world_size.top
            || x() <= view->world_size.left || x() >= view->world_size.right
            || life == 0)
    {
        explode();

        return;
    }

    setPos(x()+speed.x,y()+speed.y);

    img_count  += (img_count >= 3.7) ? -img_count : 0.3;

    setPixmap(gtexture->get_qpixmap_of(projectiles, type, 4)[img_count]);
}
