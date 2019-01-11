#ifndef ENEMY_H
#define ENEMY_H
#include "global.h"

class Enemy : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

public:

    QList<QGraphicsRectItem*> collision_ranges;

    QList<bool> collision;

    Enemy(pair position, QGraphicsItem* parent = 0);

    // Attributes
    Direction facing{Right};

    pair speedMax, speed, size;

    int number_of_frames, life;

    double count{0};

    QTimer* projectile_timer;

    std::vector<QPixmap> animation[2];

    Enemy_type type;

    Enemy_state state;

    Enemy_texture texture;


public slots:

    // Slot for timer
    void move();

    void throw_projectile();
};
#endif // ENEMY_H
