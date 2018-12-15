#ifndef ENEMY_H
#define ENEMY_H


#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QKeyEvent>
#include "types_states_textures.h"
#include "tools.h"

class View;

extern View* view;

class Enemy : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

public:

    Enemy(int size = 36, pair position = pair{0,0}, bool direction = 0, QGraphicsItem* parent = 0);

    bool direction = 0;

    // Attributes
    pair speedMax,speed;

    int size{36}, life;

    QGraphicsRectItem* collision_range_enemy;


    // Methods
    bool collision_left(), collision_right(), collision_up(), collision_down();
    bool collision_b_l(), collision_b_r(), collision_t_l(), collision_t_r();
    bool block_left(), block_right(), block_up(), block_down();

    bool player_pos_t_l(), player_pos_t_r(), player_pos_b_l(), player_pos_b_r();

    bool throwprojectile();


public slots:

    // Slot for timer
    void move();

};
#endif // ENEMY_H
