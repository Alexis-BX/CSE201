#include "character.h"
#include<iostream>
using namespace std;

Character:: Character(pr position, pr size, char st): Object (position,size){
    state=st;
}

void Character::set_speed(pr new_speed)
{
    speed.x= new_speed.x;
    speed.y=new_speed.y;
}


pr Character::get_speed()
{
    return speed;
}

