#include "listheaders.h"

Base_block::Base_block(pair position, QGraphicsItem* parent) :
    Block(position, parent)
{
    type = permanent;
    texture = brick;
    state = initial;
    sprite = gtexture->get_qpixmap_of(blocks, texture);
    setPixmap(sprite[image_count]);
}


Breakable_block::Breakable_block(pair position, QGraphicsItem* parent) :
    Block(position, parent)
{
    type = breakable;
    texture = crate;
    state = initial;

    sprite = gtexture->get_qpixmap_of(blocks, texture, 6);
    setPixmap(sprite[image_count]);

}

Active_block::Active_block(pair position, QGraphicsItem* parent) :
    Block(position, parent)
{
    type = active;
    texture = question_mark;
    state = initial;

    sprite = gtexture->get_qpixmap_of(blocks, texture, 3);
    setPixmap(sprite[image_count]);

    // Timer
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(blink()));
    timer->start(500);
}

Special_block_above::Special_block_above(pair position, QGraphicsItem* parent) :
    Block(position, parent)
{
    type = permanent;
    texture = grass;
    state = initial;

    sprite = gtexture->get_qpixmap_of(blocks, texture);
    setPixmap(sprite[image_count]);
}

Special_block_below::Special_block_below(pair position, QGraphicsItem* parent) :
    Block(position, parent)
{
    type = permanent;
    texture = dirt;
    state = initial;

    sprite = gtexture->get_qpixmap_of(blocks, texture);
    setPixmap(sprite[image_count]);
}

Activated_block::Activated_block(pair position, QGraphicsItem* parent) :
    Block(position, parent)
{
    type = permanent;
    texture = activated;
    state = initial;

    sprite = gtexture->get_qpixmap_of(blocks, texture);
    setPixmap(sprite[image_count]);
}
