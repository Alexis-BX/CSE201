#ifndef OBJECT_H
#define OBJECT_H


class Object
{
public:
    Object();
    double* get_collision_box();
    double pos_x, pos_y, size_x, size_y;

};


#endif // OBJECT_H
