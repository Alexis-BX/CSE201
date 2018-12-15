#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QKeyEvent>
#include "tools.h"
#include "types_states_textures.h"
#include "collectable.h"

class Player : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

public:

    Player(QGraphicsItem* parent = 0, int size = 36);


    // Attributes
    pair speedMax,speed;

    double_pair world_boundaries;

    bool pressedL{false}, pressedR{false};

    int size{36}, M{10}, toMirror{4}, N{8}, direction{1}, block_size{18};

    double count;

    QPixmap animations[10][8];

    QGraphicsRectItem* collision_range;


    // Methods
    void keyPressEvent(QKeyEvent * event);

    void keyReleaseEvent(QKeyEvent * event);

    void throwprojectile(int i);

    void create_animation();

    void create_collision_range();

    void count_coins(Collectable collectable);

    void superpower(Collectable collectable);

    bool collision_left(), collision_right(), collision_up(), collision_down();
    bool collision_b_l(), collision_b_r(), collision_t_l(), collision_t_r();

    void create_enemy(); //for the moment the player chooses when the enemy appears while we work on it

public slots:

    // Slot for timer
    void move();

};

#endif // PLAYER_H
