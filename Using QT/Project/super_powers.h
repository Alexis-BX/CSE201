#ifndef SUPER_POWERS_H
#define SUPER_POWERS_H
#include "global.h"

enum Supers
{
    super_fast = eclair,
    super_throw = croissant,
    super_invincible = chocolatine,
    super_jump = mini_eiffel,
    super_wine = glass_wine,
    super = mushroom,
    supers_count
};

class Super_powers
{

public:

    Super_powers();

    QList<bool> supers_b;

    QList<int> supers_i;

    int max_count{300};

    void update_counters();

    void power_up(int i);

    double get_speed();

    double get_throw_speed();
};

#endif // SUPER_POWERS_H
