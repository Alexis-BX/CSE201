#include "listheaders.h"

Background::Background(pair position, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
    setPos(position.x,position.y);
    //setOpacity(10);
}

QPainterPath Background::shape() const
{
    return QPainterPath();
}

Background::~Background()
{

}
