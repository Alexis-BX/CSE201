#include "listheaders.h"

You_win::You_win(QGraphicsItem* parent):
     QObject(), QGraphicsPixmapItem (parent)
{
    setPos(view->player->x() - int(view->screen_size.x/2),-view->screen_size.y+18);
    QPixmap img(":/Images/Backgrounds/Main_background/youwin.png");
    img = img.scaled(view->screen_size.x, view->screen_size.y);
    setPixmap(img);
    view->music->stop();
}
