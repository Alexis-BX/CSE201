#include "color_triple_player.h"
#include "view.h"
#include "player.h"

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
        view->player = new Player();

        view->player->setPos(position.x,position.y);

        view->player->setFlag(QGraphicsItem::ItemIsFocusable);

        view->player->setFocus();

        scene->addItem(view->player);

        view->centerOn(view->player);

        view->player->coin_counter = new Coin_counter(pair{view->player->size.x,0},view->player);
    }
}
