#include "listheaders.h"

Block::Block(pair position, QGraphicsItem* parent) :
    QObject (), QGraphicsPixmapItem (parent)
{
    setPos(position.x,position.y);
}


/*void Block::is_hit()
{
    if (collision_up() == true || collision_down() == true || collision_left() == true || collision_right() == true)
    {
        view->scene->addItem(new Collectable_type(position));
    }
}*/


void Block::blink()
{
    if(texture == question_mark && image_count != 2)
    {
        setPixmap(sprite[image_count]);
        image_count++; image_count%=2;
    }

}
