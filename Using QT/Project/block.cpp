#include "listheaders.h"

Block::Block(pair position, QGraphicsItem* parent) :
    QObject (), QGraphicsPixmapItem (parent)
{
    setPos(position.x,position.y);
    this->setZValue(layer_block);
}

void Block::blink()
{
    if(texture == question_mark && image_count != 2)
    {
        setPixmap(sprite[image_count]);
        image_count++; image_count%=2;
    }

}
