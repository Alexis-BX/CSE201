#include "listheaders.h"

Background::Background(pair position, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
    setPos(position.x,position.y);
}

QPainterPath Background::shape() const
{
    return QPainterPath();
}

Background::~Background()
{
    //delete pixmap
    //remove from scene
}
