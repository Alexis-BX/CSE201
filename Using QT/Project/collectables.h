#ifndef COLLECTABLES_H
#define COLLECTABLES_H
#include "collectable.h"


class Collectable_1 : public Collectable // coin collectable
{
public:
    Collectable_1(pair position, int creator_object_size_y);
};

class Collectable_2 : public Collectable // star collectable
{
public:
    Collectable_2(pair position, int creator_object_size_y);
};

class Collectable_3 : public Collectable // mushroom collectable
{
public:
    Collectable_3(pair position, int creator_object_size_y);
};

class Collectable_4 : public Collectable // eclair collectable
{
public:
    Collectable_4(pair position, int creator_object_size_y);
};

#endif // COLLECTABLES_H
