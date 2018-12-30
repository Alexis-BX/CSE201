#ifndef BACKGROUNDS_H
#define BACKGROUNDS_H
#include "background.h"

class Background_far: public Background
{
public:
    Background_far(pair position);
};

class Background_middle: public Background
{
public:
    Background_middle(pair position);
};

class Background_close: public Background
{
public:
    Background_close(pair position);
};

#endif // BACKGROUNDS_H
