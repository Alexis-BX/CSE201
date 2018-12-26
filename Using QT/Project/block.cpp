#include "block.h"
#include "player.h"
#include "view.h"
#include "tools.h"
#include "global.h"

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
<<<<<<< HEAD
        setPixmap(sprite[image_count]);
        image_count++; image_count%=2;
=======
        switch (image_count)
        {

        case 0:
        {
            setPixmap(gtexture->get_qpixmap_of(blocks, texture, 3)[image_count]);
            image_count = 1;
            break;
        }

        case 1:
        {
            setPixmap(gtexture->get_qpixmap_of(blocks, texture, 3)[image_count]);
            image_count = 0;
            break;
        }
        }
>>>>>>> be8dc67cd71c413ceaa2161fffdae1a0e6cada01
    }

}
