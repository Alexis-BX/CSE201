#include "gprojectile.h"

GProjectile::GProjectile(Projectile_type type, QPoint speed, QPoint position, QGraphicsItem* parent):
    GMovingObject(speed, position, parent)
{
    max_speed = speed;

    state = alive;

    this->type = type;

    setZValue(layer_projectile);

    setPixmap(gtexture->get_qpixmap_of(projectiles, type)[count]);
}

GProjectile::~GProjectile()
{

}

QString GProjectile::get_name()
{
    return "Projectile";
}

void GProjectile::move()
{
    life -= 1;

    update_collision_range();

    collide();

    if(speed != max_speed || life <= 0)
    {
        explode();

        return;
    }

    setPos(x()+speed.rx(),y()+speed.ry());

    count  += (count >= 3.7) ? -count : 0.3;

    setPixmap(gtexture->get_qpixmap_of(projectiles, type, 4)[count]);
}

void GProjectile::explode()
{
    QPixmap explosion = QPixmap(gtexture->get_path_to(projectile_vanish_effect));

    setPixmap(explosion);

    setPos(x()-explosion.width()/2+sizex/2,y()-explosion.height()/2+sizey/2);

    delay(100);

    deleteLater();
}

