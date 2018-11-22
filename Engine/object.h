#ifndef OBJECT_H
#define OBJECT_H


struct pair{
    int x,y;
};

enum State { };

class Object
{
public:
    Object(pair position, pair size, State state);
    pair position,size;
    State state ;

};


#endif // OBJECT_H
