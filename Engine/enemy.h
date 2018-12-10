#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "player.h"
#include "gamestate.h"
enum Enemy_type
{
    small_monster,
    boommushroom,
    smoker,
    Boss
};

class Enemy: public Character
{
private:
    int lif[4]={1,1,1,5};//default life points
    pair spd[4]={{1,0},{0,0},{0,0},{1,0}};//defaul speed for each enemy

public:
    Enemy(pair position, pair size, Enemy_type type,State state);

    void goback();//the enemy move automaticly in a specific range of place

    void makesmoke();//make smoke in the sceen (still not sure how to doi\)

    void hit(Player player);

    void behit(Player player);

    void die();//maybe put it in the character class

};

#endif // ENEMY_H
