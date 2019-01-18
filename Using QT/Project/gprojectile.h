#ifndef GPROJECTILE_H
#define GPROJECTILE_H
#include "gmovingobject.h"
#include "global.h"
#include "texture.h"


class GProjectile : public GMovingObject
{

public:

    GProjectile(Projectile_type type, QPoint speed, QPoint position, QGraphicsItem* parent = nullptr);

    ~GProjectile();

    void explode();

    QString get_name();

    // Attributes
    double count = 0;

    int life;

    constexpr static greal velocity = 15;

    Projectile_type type;

    Projectile_state state;

public slots:

    void move();
};

#endif // GPROJECTILE_H
