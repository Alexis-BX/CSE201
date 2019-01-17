#include "gobject.h"



GObject::GObject(QPoint position, QGraphicsItem* parent)
    : QObject(), QGraphicsPixmapItem (parent)
{
    setPos(position);
}
