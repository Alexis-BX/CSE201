#ifndef PLAYER_H
#define PLAYER_H
#include "global.h"
#include "collectable.h"
#include "coin_counter.h"

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

    Player(QGraphicsItem* parent = 0);


    // Attributes

    pair max_speed{10,15},speed{0,0};

    double_pair world_boundaries;

    //direction false = left, true = right
    bool pressed_left{false}, pressed_right{false},
    super{false}, super_fast{false}, super_throw{false};

    int size{36}, number_of_character_states{11}, max_images_per_state{8},
    block_size{18}, count_super{0}, times_jumped{0}, max_consecutive_jumps{2},
    maxFrame[12] = {2, 8, 3, 2, 3, 2, 2, 2, 4, 2, 2, 8};

    int current_projectile{1};

    double count{0};

    Direction facing{Right};

    States state{stand}, old_state{stand};

                    //[super][direction][state][frame]
                    //[2][2][number_of_character_states][max_images_per_state]
    QPixmap animations[2][2][11][8];

    std::vector<QGraphicsRectItem*> collision_ranges;

    QGraphicsRectItem* vertical_collision_range;
    QGraphicsRectItem* horizontal_collision_range;
    QGraphicsRectItem* diagonal_collision_range;

    Coin_counter* coin_counter;


    // Methods
    void keyPressEvent(QKeyEvent * event);

    void keyReleaseEvent(QKeyEvent * event);

    void throw_projectile();

    void create_animation();

    void create_collision_range();

    void superpower(Collectable collectable);

    bool collision_left(), collision_right(), collision_up(), collision_down();
    bool collision_b_l(), collision_b_r(), collision_t_l(), collision_t_r();

    void set_animation_state(bool block_below);

    void jump();

public slots:

    // Slot for timer
    void move();

};

#endif // PLAYER_H
