#include "listheaders.h"

Help::Help(QGraphicsItem* parent):
    QObject(), QGraphicsPixmapItem (parent)
{
    setPos(0,-view->screen_size.y-18);
    view->centerOn(this);

    QPixmap img(":/Images/Menu/help.png");
    img = img.scaled(view->screen_size.x, view->screen_size.y);
    setPixmap(img);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    view->scene_help->addItem(this);
}

void Help::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    default:
    {
        view->scene_help->clear();
        view->open_menu();
        break;
    }
    }
}

