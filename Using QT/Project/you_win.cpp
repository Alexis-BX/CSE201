#include "listheaders.h"

You_win::You_win(QGraphicsItem* parent):
     QObject(), QGraphicsPixmapItem (parent)
{
    view->player->setX(0);
    view->player->playing = false;
    setPos(0,-view->screen_size.y+18);
    QPixmap img(":/Images/Backgrounds/Main_background/you_win.png");
    img = img.scaled(view->screen_size.x, view->screen_size.y);
    setPixmap(img);
    view->music->stop();
}
