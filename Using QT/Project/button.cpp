#include "listheaders.h"

Button::Button(int x, int y, QPixmap sprite, QGraphicsItem* parent):
    QGraphicsPixmapItem(parent)
{
    setPos(x, y);
    setPixmap(sprite);
    this->setZValue(layer_button);
}
