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
}

void Help::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Enter:
    case Qt::Key_Space:
    case Qt::Key_Return:
    {
        deleteLater();

        view->play_level(view->current_level);

        break;
    }
    }
}

