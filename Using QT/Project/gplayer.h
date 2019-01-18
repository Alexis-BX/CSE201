#ifndef GPLAYER_H
#define GPLAYER_H
#include "global.h"
#include "super_powers.h"
#include "coin_counter.h"
#include "gmovingobject.h"

enum Player_states
{
    stand, run, jumpH, fallH, landH,
    crouchD, crouch, crouchU,
    jumpV, fallV, landV, throwA, number_of_character_states
};

class GPlayer : public GMovingObject, public Super_powers
{

public:

    GPlayer(QPoint position, QPoint speed = QPoint{0,0}, QPoint size = QPoint{36,36}, QGraphicsItem *parent = nullptr);

    ~GPlayer();

    void keyPressEvent(QKeyEvent * event);

    void keyReleaseEvent(QKeyEvent * event);

    void create_animation(QPoint size);

    void effect_forces();

    void set_animation_state();

    void throw_projectile();

    void jump();

    QString get_name();

    bool pressed_left{false}, pressed_right{false};

    int times_jumped{0}, max_consecutive_jumps{2},

    maxFrame[12] = {2, 8, 3, 2, 3, 2, 2, 2, 4, 2, 2, 8},
    max_images_per_state{8};

    Player_states state{stand}, old_state{stand};

    double count{0};

    QPixmap animations[2][2][12][8];

    Coin_counter* coin_counter;

public slots:

    void move();

};

#endif // GPLAYER_H
