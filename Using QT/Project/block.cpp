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
    if(texture == question_mark)
    {
        switch (image_count)
        {

        case 0:
        {
            setPixmap(QPixmap(gtexture->get_path_to(active_block_2)));
            image_count = 1;
            break;
        }

        case 1:
        {
            setPixmap(QPixmap(gtexture->get_path_to(active_block_1)));
            image_count = 0;
            break;
        }
        }
    }

}
