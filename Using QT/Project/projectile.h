#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "global.h"

class Projectile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Projectile(pair position, bool direction, int character_size_x, Projectile_type type, pair size = pair{18,18}, QGraphicsItem* parent = 0);

    ~Projectile();

    void explode();

    // Attributes
    int life;

    pair speed, size;

    double img_count = 0;

    QList<QGraphicsRectItem*> collision_ranges;

    QList<bool> collision;

    constexpr static greal velocity = 15;

    Projectile_type type;

    Projectile_state state;

    QTimer* timer;

public slots:

    void move();

};

#endif // PROJECTILE_H
