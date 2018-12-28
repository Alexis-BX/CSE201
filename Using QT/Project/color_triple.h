#ifndef COLOR_TRIPLE_H
#define COLOR_TRIPLE_H
#include "global.h"
#include "tools.h"

class Base_color_triple
{
public:
    virtual ~Base_color_triple(){}

    virtual void test(int R, int G, int B, pair& position){}
};

template<class T> class Color_triple : public Base_color_triple
{

public:

    static constexpr int diff = 4;

    int r,g,b;

    View* view;

    Color_triple(int R, int G, int B,View* view);

    void test(int R, int G, int B, pair& position);
};



#endif // COLOR_TRIPLE_H
