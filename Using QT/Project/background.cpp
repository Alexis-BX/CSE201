#include "listheaders.h"

background::background(const char * img, pair position, int speed_ratio, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
    sprite = QPixmap(img);
    setX(position.x);
    setY(position.y);
    width = sprite.width();
    this->speed_ratio = speed_ratio;
}

background::background(pair position, QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
    setX(position.x);
    setY(position.y);
}

QPainterPath background::shape() const
{
    return QPainterPath();
}
