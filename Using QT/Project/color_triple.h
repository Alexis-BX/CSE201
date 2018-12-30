#ifndef COLOR_TRIPLE_H
#define COLOR_TRIPLE_H
#include "global.h"
#include "base_color_triple.h"

template<class T> class Color_triple : public Base_color_triple
{

public:

    Color_triple(int R, int G, int B,View* view);

    void test(int R, int G, int B, pair& position);
};

#endif // COLOR_TRIPLE_H
