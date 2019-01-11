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
    QTimer * timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(view->ms_between_updates);

}

void Projectile::move()
{
    if (state == vanish)
    {
        setPixmap(QPixmap(gtexture->get_path_to(projectile_vanish_effect)));

        delay(200);

        QObject::deleteLater();

        return;
    }

    //in boundaries
    if(y() >= view->world_size.bottom || y() <= view->world_size.top
            || x()<=view->world_size.left || x() >= view->world_size.right)
    {
        state = vanish;
        return;
    }

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

    // movements of the player:
    if (collision[0])
    {
        state = vanish;

        return;
    }
    if (collision[1])
    {
        state = vanish;

        return;
    }
    if (collision[2] && !collision[1] && !collision[0])
    {
        state = vanish;

        return;
    }


    setPos(x()+speed.x,y()+speed.y);

    img_count += 0.3;

    if(img_count>=4)
    {
        img_count = 0;
    }

    setPixmap(gtexture->get_qpixmap_of(projectiles, type, 4)[img_count]);

    life -= 1;

    if(life == 0)
    {
        state = vanish;

        return;
    }
}
