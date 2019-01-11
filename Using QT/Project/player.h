#ifndef PLAYER_H
#define PLAYER_H
#include "global.h"
#include "collectable.h"
#include "coin_counter.h"
#include "collision_master.h"

//list of player states
enum States
{
    stand, run, jumpH, fallH, landH,
    crouchD, crouch, crouchU,
    jumpV, fallV, landV, throwA
};

class Player : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

public:

    Player(QGraphicsItem* parent = nullptr);


    // Attributes

    QList<QGraphicsRectItem*> collision_ranges;

    QList<bool> collision;

    pair max_speed{10,15}, absolute_max_speed{10,15}, size{36,36}, speed{0,0}, block_size{18,18};

    double_pair world_boundaries;

    bool pressed_left{false}, pressed_right{false},

    super{false}, super_fast{false}, super_throw{false}, super_big{false}, super_invincible{false};

    int count_super_fast{0}, count_super_throw{0},count_super{0}, count_super_big{0}, count_super_invincible{0},

    times_jumped{0}, max_consecutive_jumps{2},

    maxFrame[12] = {2, 8, 3, 2, 3, 2, 2, 2, 4, 2, 2, 8},
    number_of_character_states{11}, max_images_per_state{8};

    int current_projectile{1};

    double count{0};

    Direction facing{Right};

    States state{stand}, old_state{stand};

                    //[super][direction][state][frame]
                    //[2][2][number_of_character_states][max_images_per_state]
    QPixmap animations[2][2][11][8];

    Coin_counter* coin_counter;

    // Methods
    void keyPressEvent(QKeyEvent * event);

    void keyReleaseEvent(QKeyEvent * event);

    void throw_projectile();

    void create_animation();

    void superpower(QString collision_type);

    void set_animation_state();

    void jump();

public slots:

    // Slot for timer
    void move();
};

#endif // PLAYER_H
