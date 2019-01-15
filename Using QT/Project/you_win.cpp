#include "listheaders.h"

You_win::You_win(QGraphicsItem* parent):
     QObject(), QGraphicsPixmapItem (parent)
{
    setPos(0,0);

    QPixmap img(":/Images/Backgrounds/Main_background/youwin.png");

    img = img.scaled(view->screen_size.x, view->screen_size.y);

    setPixmap(img);
}
