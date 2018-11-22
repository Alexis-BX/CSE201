#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <string>
#include "dead.h"

class Projectile: public Dead
{
public:
    int speed;
    std::pair<int, int> direction;
    int life;

    Projectile(std::pair<int,int> position, std::pair<int,int> size, int speed, std::pair<int, int> direction, int life);

    void next_pos(std::pair<int,int> position, int speed, std::pair<int, int> direction);

    bool die_progressively(int life, std::pair<int,int> position, std::pair<int,int> size, std::pair<int,int> direction);

    bool explode(std::pair<int,int> size);

};

#endif // PROJECTILE_H
