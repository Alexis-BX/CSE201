#ifndef BACKGROUNDS_H
#define BACKGROUNDS_H
#include "background.h"

class sky: public background
{
public:
    sky(pair pos);
};

class monument: public background
{
public:
    monument(pair pos);
};

class buildings: public background
{
public:
    buildings(pair pos);
};

#endif // BACKGROUNDS_H
