#include "blocks.h"
#include "global.h"
#include "texture.h"
#include <QTimer>

Base_block::Base_block(pair position) :
    Block(position)
{
    type = permanent;
    texture = brick;
    state = initial;

    if(int(-position.y)%36 < 9)
    {
        setPixmap(QPixmap(gtexture->get_path_to(base_block_1)));
    }
    else
    {
        setPixmap(QPixmap(gtexture->get_path_to(base_block_2)));
    }

}


Breakable_block::Breakable_block(pair position) :
    Block(position)
{
    type = breakable;
    texture = crate;
    state = initial;

    setPixmap(QPixmap(gtexture->get_path_to(breakable_block)));


}

Active_block::Active_block(pair position) :
    Block(position)
{
    type = active;
    texture = question_mark;
    state = initial;

    setPixmap(QPixmap(gtexture->get_path_to(active_block_1)));
    image_count = 0;

    // Timer
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(blink()));
    timer->start(500);

}

Special_block_above::Special_block_above(pair position) :
    Block(position)
{
    type = permanent;
    texture = grass;
    state = initial;

    setPixmap(QPixmap(gtexture->get_path_to(special_block_above)));


}

Special_block_below::Special_block_below(pair position) :
    Block(position)
{
    type = permanent;
    texture = dirt;
    state = initial;

    setPixmap(QPixmap(gtexture->get_path_to(special_block_below)));


}
