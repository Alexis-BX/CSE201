#include "super_powers.h"

Super_powers::Super_powers()
{

}

void Super_powers::update_counters()
{
    //superpowers timer
    if (super)
    {
        count_super += 1;
    }
    if (count_super > max_count)
    {
        super = false;
    }

    if (super_fast)
    {
        count_super_fast +=1;
    }
    if (count_super > max_count)
    {
        super_fast = false;
    }

    if (super_throw)
    {
        count_super_throw +=1;
    }
    if (count_super > max_count)
    {
        super_throw = false;
    }

    if (super_big)
    {
        count_super_big +=1;
    }
    if (count_super_big > max_count)
    {
        super_big = false;
    }

    if (super_invincible)
    {
        count_super_invincible +=1;
    }
    if (count_super_invincible > max_count)
    {
        super_invincible = false;
    }

    if(super_invincible2)
    {
        count_super_invincible2 +=1;
    }
    if (count_super_invincible2 > max_count)
    {
        super_invincible2 = false;
    }
}

void Super_powers::power_up(QString power_type)
{
    if(power_type == "10Power_up_1") //eclair
    {
        count_super_throw = 0;
        super_throw = true;
    }
    else if(power_type == "10Power_up_2") //croissant
    {
        count_super_fast = 0;
        super_fast = true;
    }
    else if(power_type == "10Power_up_3") //chocolatine
    {
        count_super_invincible2 = 0;
        super_invincible2 = true;
    }
    else if(power_type == "10Power_up_4") //mini_eiffel
    {
        count_super_invincible = 0;
        super_invincible = true;
    }
    else if(power_type == "10Power_up_5") //glass_wine
    {
        count_super = 0;
        super = true;
        count_super_fast = 0;
        super_fast = true;

    }
    else if(power_type == "10Power_up_6") //mushroom
    {
        count_super_fast = 0;
        super_fast = true;
    }

    else if (power_type == "10Power_up_7") //coin
    {
        count_super_throw = 0;
        super_throw = true;
    }

    else if(power_type == "10Power_up_8") //star
    {
        count_super = 0;
        super = true;
    }
}

double Super_powers::get_speed()
{
    return ((super_fast) ? 2 : 1);
}
