#ifndef COLLECTABLES_H
#define COLLECTABLES_H
#include "collectable.h"


class Small_collectable : public Collectable // coin collectable
{
public:
    Small_collectable(pair position, int creator_object_size_y = 0);
};

class Big_collectable : public Collectable // star collectable
{
public:
    Big_collectable(pair position, int creator_object_size_y = 0);
};

class Power_up_1 : public Collectable // mushroom collectable
{
public:
    Power_up_1(pair position, int creator_object_size_y = 0);
};

class Power_up_2 : public Collectable // eclair collectable
{
public:
    Power_up_2(pair position, int creator_object_size_y = 0);
};

#endif // COLLECTABLES_H
