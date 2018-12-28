#ifndef ENEMY_H
#define ENEMY_H


#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QKeyEvent>
#include "types_states_textures.h"
#include "tools.h"


class Enemy : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

public:

    Enemy(pair position, QGraphicsItem* parent = 0);

    // Attributes
    bool direction{false};

    pair speedMax, speed, size;

    int number_of_frames, life;

    double count{0};

    QTimer* projectile_timer;

    std::vector<QPixmap> animation[2];

    QGraphicsRectItem* collision_range;

    Enemy_type type;

    Enemy_state state;

    Enemy_texture texture;


    // Methods
    bool collision_left(), collision_right(), collision_up(), collision_down();
    bool collision_b_l(), collision_b_r(), collision_t_l(), collision_t_r();
    bool block_left(), block_right(), block_up(), block_down();

    bool player_pos_t_l(), player_pos_t_r(), player_pos_b_l(), player_pos_b_r();

    void create_collision_range();


public slots:

    // Slot for timer
    void move();

    void throw_projectile();
};
#endif // ENEMY_H
