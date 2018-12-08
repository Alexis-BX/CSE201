#include "block.h"
#include "player.h"
#include "view.h"

Block::Block(pair position, Block_type type, Block_state state, Block_texture texture, QGraphicsItem* parent) : QObject (), QGraphicsPixmapItem (parent)
{
    setPos(position.x,position.y);

    this->type = type;

    this->state = state;

    this->texture = texture;

    setPixmap(QPixmap(":/images/brick18.png")); //JUST A WORKING BRICK WITH THE RIGHT DIMENSIONS
}
