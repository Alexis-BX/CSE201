#ifndef COLOR_TRIPLE_PLAYER_H
#define COLOR_TRIPLE_PLAYER_H
#include "global.h"
#include "base_color_triple.h"

class Color_triple_player : public Base_color_triple
{
public:

    Color_triple_player(int R, int G, int B, View* view);

    void test(int R, int G, int B, pair& position, QGraphicsScene*scene);
};

#endif // COLOR_TRIPLE_PLAYER_H
