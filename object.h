#ifndef OBJECT_H
#define OBJECT_H

struct pr{
    int x,y;
};

class Object
{
public:
    Object(pr position, pr size);
    double* get_collision_box();
    pr position,size;
};


#endif // OBJECT_H
