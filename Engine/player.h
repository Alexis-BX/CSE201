#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "character.h"
using namespace std;

class Player: public Character
{
public:
    char state;
    Player(pr position, pr size, char state);
    void goforward();
    void goback();
    void jump();
    void growbigger();//these moving parts should have a default speed so we dont put parametres
    void shrink();
    void stop();
};

#endif // PLAYER_H
