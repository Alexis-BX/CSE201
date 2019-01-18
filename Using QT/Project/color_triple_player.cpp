#include "color_triple_player.h"
#include "view.h"
#include "player.h"
#include "gplayer.h"

Color_triple_player::Color_triple_player(int R, int G, int B, View *view)
{
    this->view = view;
    r = R;
    g = G;
    b = B;
}

void Color_triple_player::test(int R, int G, int B, pair &position, QGraphicsScene*scene)
{
    if (abs(R-r)<=diff && abs(G-g)<=diff && abs(B-b)<=diff)
    {
        view->player = new GPlayer(QPoint{int(position.x),int(position.y)});

        scene->addItem(view->player);
    }

}
