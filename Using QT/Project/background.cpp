#include "listheaders.h"

Background::Background(pair position, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
    setPos(position.x,position.y);
}

Background::~Background()
{

}
