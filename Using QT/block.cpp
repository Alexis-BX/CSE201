#include "block.h"
#include "player.h"
#include "view.h"

Block::Block(pair position, Block_type type, Block_texture texture, Block_state state, QGraphicsItem* parent) : QObject (), QGraphicsPixmapItem (parent)
{
    setPos(position.x,position.y);

    this->type = type;

    this->state = state;

    this->texture = texture;


    if(texture == brick)
    {
        if(int(position.y+81)%36 < 18)
        {
            setPixmap(QPixmap(":/images/pixmaps/ground1.png"));
        }
        else
        {
            setPixmap(QPixmap(":/images/pixmaps/ground3.png"));
        }
    }
    else if(texture == crate)
    {
        setPixmap(QPixmap(":/images/pixmaps/break0.png"));
    }
    else if(texture == question_mark)
    {
        setPixmap(QPixmap(":/images/pixmaps/question0.png"));

        image_count = 0;

        // Timer
        QTimer * timer = new QTimer();

        QObject::connect(timer,SIGNAL(timeout()),this,SLOT(blink()));

        timer->start(500);
    }
    else if(texture == grass)
    {
        setPixmap(QPixmap(":/images/pixmaps/grass.png"));
    }
}

void Block::blink()
{
    if(texture == question_mark)
    {
        if(image_count == 0)
        {
            setPixmap(QPixmap(":/images/pixmaps/question1.png"));
            image_count = 1;
        }
        else if(image_count == 1)
        {
            setPixmap(QPixmap(":/images/pixmaps/question0.png"));
            image_count = 0;
        }


    }

}
