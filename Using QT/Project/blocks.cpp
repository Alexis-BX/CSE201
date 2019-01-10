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


<<<<<<< HEAD
Breakable_block_1::Breakable_block_1(pair position, QGraphicsItem* parent) :
=======
Breakable_block::Breakable_block(pair position, QGraphicsItem* parent) :
>>>>>>> 85cdf7b5c2fa4321352667f886d01e7d69b95ab6
    Block(position, parent)
{
    type = breakable;
    texture = crate;
    state = initial;

    sprite = gtexture->get_qpixmap_of(blocks, texture, 6);
    setPixmap(sprite[image_count]);

}

<<<<<<< HEAD
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

=======
>>>>>>> 85cdf7b5c2fa4321352667f886d01e7d69b95ab6
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


End_block::End_block(pair position, QGraphicsItem* parent) :
    Block(position, parent)
{
    type = permanent;
    texture = grass;            //RANDOM TEXTURE FOR NOW
    state = initial;

    sprite = gtexture->get_qpixmap_of(blocks, texture);
    setPixmap(sprite[image_count]);
}
