#ifndef COLLECTABLES_H
#define COLLECTABLES_H
#include "collectable.h"


class Small_collectable : public Collectable // cheese collectable
{
public:
    Small_collectable(pair position, int creator_object_size_y = 0);
};

/*class Big_collectable : public Collectable // star collectable
{
public:
    Big_collectable(pair position, int creator_object_size_y = 0);
};
*/

class Power_up_1 : public Collectable // eclair collectable
{
public:
    Power_up_1(pair position, int creator_object_size_y = 0);
};

class Power_up_2 : public Collectable // croissant collectable
{
public:
    Power_up_2(pair position, int creator_object_size_y = 0);
};

class Power_up_3 : public Collectable // chocolatine collectable
{
public:
    Power_up_3(pair position, int creator_object_size_y = 0);
};

class Power_up_4 : public Collectable // mini_eiffel collectable
{
public:
    Power_up_4(pair position, int creator_object_size_y = 0);
};

class Power_up_5 : public Collectable // glass_wine collectable
{
public:
    Power_up_5(pair position, int creator_object_size_y = 0);
};

class Power_up_6 : public Collectable // mushroom collectable
{
public:
    Power_up_6(pair position, int creator_object_size_y = 0);
};

class Power_up_7 : public Collectable // coin collectable
{
public:
    Power_up_7(pair position, int creator_object_size_y = 0);
};


class Power_up_8 : public Collectable // star collectable
{
public:
    Power_up_8(pair position, int creator_object_size_y = 0);
};

#endif // COLLECTABLES_H
