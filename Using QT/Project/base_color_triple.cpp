#include "base_color_triple.h"

Base_color_triple::~Base_color_triple()
{

}

void Base_color_triple::test(int R, int G, int B, pair &position)
{
    qDebug() << "This functino was called by mistake with "
                "R = " << R << "G = " << G << "B = " << B <<
                "position = (" << position.x << "," << position.y << ")";
}
