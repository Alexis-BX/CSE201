#include "block.h"
#include "player.h"
#include "view.h"
#include "tools.h"
#include "global.h"

Block::Block(pair position, Block_type type, Block_texture texture, Block_state state, QGraphicsItem* parent) :
    QObject (), QGraphicsPixmapItem (parent)
{
    setPos(position.x,position.y);

    this->type = type;

    this->state = state;

    this->texture = texture;

    switch (texture)
    {

    case brick:
    {
        if(int(-position.y)%36 < 9)
        {
            setPixmap(QPixmap(gtexture->get_path_to(base_block_1)));
        }
        else
        {
            setPixmap(QPixmap(gtexture->get_path_to(base_block_2)));
        }
        break;
    }

    case crate:
    {
        setPixmap(QPixmap(gtexture->get_path_to(breakable_block)));
        break;
    }

    case question_mark:
    {
        setPixmap(QPixmap(gtexture->get_path_to(active_block_1)));
        image_count = 0;

        // Timer
        QTimer * timer = new QTimer();
        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(blink()));
        timer->start(500);
        break;
    }

    case grass:
    {
        setPixmap(QPixmap(gtexture->get_path_to(special_block_above)));
        break;
    }

    case dirt:
    {
        setPixmap(QPixmap(gtexture->get_path_to(special_block_below)));
        break;
    }
    }

}

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
