#ifndef OBJECT_H
#define OBJECT_H
#include <utility>



class Object
{
public:
    Object( std::pair<int,int> position, std::pair<int,int> size);
    std::pair<int , int > position, size;
    // std::pair<int,int> get_position, get_size; no use for now



};


#endif // OBJECT_H
