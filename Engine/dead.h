#ifndef DEAD_H
#define DEAD_H
#include "object.h"

class Dead: public Object
{
public:
    Dead(std::pair<int,int> position, std::pair<int,int> size);

};

#endif // DEAD_H
