#ifndef SUPER_POWERS_H
#define SUPER_POWERS_H
#include "global.h"


class Super_powers
{

public:

    Super_powers();

    bool super{false},
    super_fast{false},
    super_throw{false},
    super_big{false},
    super_invincible{false},
    super_invincible2{false};

    int count_super{0},
    count_super_fast{0},
    count_super_throw{0},
    count_super_big{0},
    count_super_invincible{0},
    count_super_invincible2{0},

    max_count{300};

    void update_counters();

    void power_up(QString power_type);

    double get_speed();
};

#endif // SUPER_POWERS_H
