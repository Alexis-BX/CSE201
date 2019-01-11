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

    int number_of_frames, life,

    times_jumped{0}, max_consecutive_jumps{2},

    projectile_count{0};

    double count{0};

    QTimer* timer;

    std::vector<QPixmap> animation[2];

    Enemy_type type;

    Enemy_state state;

    Enemy_texture texture;

    void jump();

    void move();

    void throw_projectile();

    ~Enemy();

public slots:

    // Slot for timer
    void timer_connect();

};
#endif // ENEMY_H
