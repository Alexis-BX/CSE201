#ifndef ENEMIES_H
#define ENEMIES_H
#include "enemy.h"

class Enemy_1: public Enemy
{
public:
    Enemy_1(pair position, QGraphicsItem* parent = 0);
};

class Enemy_2: public Enemy
{
public:
    Enemy_2(pair position, QGraphicsItem* parent = 0);
};

#endif // ENEMIES_H
