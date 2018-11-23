#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

class Player: public Character
{

public:

    int max_speed;

    Player(pair position, pair size, State state);

    Player(pair position);

    void next_position();

    void goforward();

    void goback();

    void jump();

    void growbigger();

    void shrink();

    void stop();

};

#endif // PLAYER_H
