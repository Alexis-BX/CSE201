#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <string>

class Projectile: public Dead
{
public:
    int speed;
    std::pair<int, int> direction;
    int life;

    Projectile(std::pair<int,int> position, std::pair<int,int> size, int speed, std::pair<int, int> direction, int time);

    void next_pos(std::pair<int,int> position, int speed, std::pair<int, int> direction);

    bool die_progressively(int life, std::pair<int,int> position, std::pair<int,int> size);

    bool explode(std::pair<int,int> size);

};

#endif // PROJECTILE_H
