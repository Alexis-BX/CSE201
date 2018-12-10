#include "block.h"
#include "player.h"
#include "view.h"

Block::Block(pair position, Block_type type, Block_state state, Block_texture texture, QGraphicsItem* parent) : QObject (), QGraphicsPixmapItem (parent)
{
    setPos(position.x,position.y);

    this->type = type;

    this->state = state;

    this->texture = texture;


    if(texture == brick)
    {
        if((position.y+81)%36 < 18)
        {
            setPixmap(QPixmap(":/images/pixmaps/ground1.png"));
        }
        else
        {
            setPixmap(QPixmap(":/images/pixmaps/ground3.png"));
        }
    }
}
