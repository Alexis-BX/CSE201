#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QKeyEvent>
#include "tools.h"
#include "types_states_textures.h"
#include "collectable.h"
#include "coin_counter.h"

//list of player states
enum States{
    stand, run, jumpH, fallH, landH, crouchD, crouch, crouchU, jumpV, fallV, landV, throwA
};

class Player : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

public:

    Player(QGraphicsItem* parent = 0, int size = 36);

    Coin_counter* coin_counter;

    // Attributes
    pair speedMax,speed;

    double_pair world_boundaries;

    //direction false = left, true = right
    bool pressedL{false}, pressedR{false}, direction{true}, super{false}, super_fast{false}, super_throw{false};

    //M: amount of character states (linesin sheet)
    //N: max amount of images per state (longest line)
    int size{36}, M{11}, N{8}, block_size{18}, count_super;

    int times_jumped{0}, max_consecutive_jumps{2};

    States state{stand}, oldState{stand};

    double count;

    int maxFrame[12] = {2, 8, 3, 2, 3, 2, 2, 2, 4, 2, 2, 8};

                    //[super][direction][state][frame]
                    //[2][2][M][N]
    QPixmap animations[2][2][11][8];

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

    void set_animation_state(bool b);

public slots:

    // Slot for timer
    void move();

};

#endif // PLAYER_H
