#include "block.h"
#include "player.h"
#include "view.h"
#include "tools.h"

Block::Block(pair position, Block_type type, Block_texture texture, Block_state state, QGraphicsItem* parent) : QObject (), QGraphicsPixmapItem (parent)
{
    setPos(position.x,position.y);

    this->type = type;

    this->state = state;

    this->texture = texture;

    const char * image;

    if(texture == brick)
    {
        if(int(position.y+81)%36 < 18)
        {
             image = "ground1.png";
        }
        else
        {
             image = "ground3.png";
        }
    }
    else if(texture == crate)
    {
         image = "break0.png";
    }
    else if(texture == question_mark)
    {
         image = "question0.png";

        image_count = 0;

        // Timer
        QTimer * timer = new QTimer();

        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(blink()));

        timer->start(500);
    }
    else if(texture == grass)
    {
         image = "grass.png";
    }
    else if(texture == dirt)
    {
         image = "dirt.png";
    }
    else if(texture == face)
    {
        image = "face.png";
    }
    setPixmap(QPixmap(add_dir(image)));

}

void Block::blink()
{
    if(texture == question_mark)
    {
        const char * image;
        if(image_count == 0)
        {
             image = "question1.png";
            image_count = 1;
        }
        else if(image_count == 1)
        {
             image = "question0.png";
            image_count = 0;
        }
        setPixmap(QPixmap(add_dir(image)));

    }

}
