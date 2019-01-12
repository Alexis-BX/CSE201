#ifndef SUPER_POWERS_H
#define SUPER_POWERS_H
#include "global.h"

enum Supers
{
    super,
    super_fast,
    super_throw,
    super_big,
    super_invincible,
    super_invincible2,
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
