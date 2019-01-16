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


Breakable_block_1::Breakable_block_1(pair position, QGraphicsItem* parent) :
    Block(position, parent)
{
    type = breakable;
    texture = crate;
    state = initial;

    sprite = gtexture->get_qpixmap_of(blocks, texture, 6);
    setPixmap(sprite[image_count]);

}

Breakable_block_2::Breakable_block_2(pair position, QGraphicsItem* parent) :
    Block(position, parent)
{
    type = breakable;
    texture = crate_2; //should be crate_2
    state = initial;

    sprite = gtexture->get_qpixmap_of(blocks, texture, 6);
    setPixmap(sprite[image_count]);

}

Breakable_block_3::Breakable_block_3(pair position, QGraphicsItem* parent) :
    Block(position, parent)
{
    type = breakable;
    texture = crate_3; // should be crate_3
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
    blink_timer = new QTimer();
    QObject::connect(blink_timer,SIGNAL(timeout()),this,SLOT(blink()));
    blink_timer->start(500);
}

Active_block::~Active_block()
{
    blink_timer->stop();
    blink_timer->deleteLater();
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


End_block::End_block(pair position, QGraphicsItem* parent) :
    Block(position, parent)
{
    type = permanent;
    texture = grass;            //RANDOM TEXTURE FOR NOW
    state = initial;

    sprite = gtexture->get_qpixmap_of(blocks, texture);
    setPixmap(sprite[image_count]);
}

Tube_block::Tube_block(pair position, QGraphicsItem* parent) :
    Block(position, parent)
{
    type = permanent;
    texture = tube;
    state = initial;

    sprite = gtexture->get_qpixmap_of(blocks, texture, 1, pair{36,18});      //size bigger than others, equal to 36
    setPixmap(sprite[image_count]);
}

Tube_block_up::Tube_block_up(pair position, QGraphicsItem* parent) :
    Block(position, parent)
{
    type = permanent;
    texture = tube_up;
    state = initial;

    sprite = gtexture->get_qpixmap_of(blocks, texture, 1, pair{36,18});      //size bigger than others, equal to 36
    setPixmap(sprite[image_count]);
}

Tube_block_down::Tube_block_down(pair position, QGraphicsItem* parent) :
    Block(position, parent)
{
    type = permanent;
    texture = tube_down;
    state = initial;

    sprite = gtexture->get_qpixmap_of(blocks, texture, 1, pair{36,18});      //size bigger than others, equal to 36
    setPixmap(sprite[image_count]);
}
