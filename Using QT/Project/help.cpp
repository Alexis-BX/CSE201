#include "listheaders.h"

Help::Help(QGraphicsItem* parent):
    QObject(), QGraphicsPixmapItem (parent)
{
    setPos(0,-view->screen_size.y-18);
    view->centerOn(this);

    QPixmap img(":/Images/Menu/help.png");
    img = img.scaled(view->screen_size.x, view->screen_size.y);
    setPixmap(img);
}

void Help::keyPressEvent(QKeyEvent *event)
{
    view->open_menu();
}

