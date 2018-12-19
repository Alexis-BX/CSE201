#ifndef COLLECTABLES_H
#define COLLECTABLES_H
#include "collectable.h"


class Collectable_1 : public Collectable
{
public:
    Collectable_1(pair position, int creator_object_size_y);
};

class Collectable_2 : public Collectable
{
public:
    Collectable_2(pair position, int creator_object_size_y);
};

class Collectable_3 : public Collectable
{
public:
    Collectable_3(pair position, int creator_object_size_y);
};

class Collectable_4 : public Collectable
{
public:
    Collectable_4(pair position, int creator_object_size_y);
};

#endif // COLLECTABLES_H
