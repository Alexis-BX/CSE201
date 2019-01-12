#include "super_powers.h"

Super_powers::Super_powers()
{
    for(int i = 0; i < supers_count; i ++)
    {
        supers_b.push_back(false);
        supers_i.push_back(0);
    }
}

void Super_powers::update_counters()
{
    for(int i = 0; i < supers_count; i ++)
    {
        if(supers_b[i])
        {
            supers_i[i] ++;
            supers_i[i] %= max_count;
        }
    }
}

void Super_powers::power_up(int i)
{
    supers_b[i] = true;
    supers_i[i] = 0;
}

double Super_powers::get_speed()
{
    return ((supers_b[super_fast]) ? 2 : 1);
}

double Super_powers::get_throw_speed()
{
    return (supers_b[super_throw]) ? 2 : 1;
}


