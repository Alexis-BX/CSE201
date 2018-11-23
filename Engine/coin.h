#ifndef COIN_H
#define COIN_H

#include "collectable.h"

class Coin : public Collectable
{

public:

    Coin(pair position, pair size, State state);

    //void Value(pair size);
};

#endif // COIN_H
