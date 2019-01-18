#ifndef PLAYER_H
#define PLAYER_H
#include "global.h"
#include "collectable.h"
#include "coin_counter.h"
#include "collision_master.h"
#include "super_powers.h"
#include "gplayer.h"

//list of player states
/*enum States
{
    stand, run, jumpH, fallH, landH,
    crouchD, crouch, crouchU,
    jumpV, fallV, landV, throwA, number_of_character_states
};
*/

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

    bool pressed_left{false}, pressed_right{false}, playing{true};

    int times_jumped{0}, max_consecutive_jumps{2},

    maxFrame[12] = {2, 8, 3, 2, 3, 2, 2, 2, 4, 2, 2, 8},
    max_images_per_state{8};

    Super_powers* super_powers;

    int current_projectile{1};

    double count{0};

    Direction facing{Right};

    Player_states state{stand}, old_state{stand};

                    //[super][direction][state][frame]
                    //[2][2][number_of_character_states][max_images_per_state]
    QPixmap animations[2][2][12][8];

    Coin_counter* coin_counter;

    QTimer* timer;

    QTimer* timerGO;

    void setup_timer();

    // Methods
    void keyPressEvent(QKeyEvent * event);

    void keyReleaseEvent(QKeyEvent * event);

    void move();

    void throw_projectile();

    void create_animation();

    void set_animation_state();

    void jump();

    void world_launch_level();

    ~Player();

public slots:

    // Slot for timer
    void update();

    void test();
};

#endif // PLAYER_H
