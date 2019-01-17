#ifndef ENEMIES_H
#define ENEMIES_H
#include "enemy.h"

class Enemy_1: public Enemy
{
public:
    Enemy_1(pair position, QGraphicsItem* parent = nullptr);
};

class Enemy_2: public Enemy
{
public:
    Enemy_2(pair position, QGraphicsItem* parent = nullptr);
};

class Enemy_3: public Enemy
{
public:
    Enemy_3(pair position, QGraphicsItem* parent = nullptr);
};
#endif // ENEMIES_H
