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
<<<<<<< HEAD
    sprite = gtexture->get_qpixmap_of(blocks, texture);
    setPixmap(sprite[image_count]);
=======

    setPixmap(gtexture->get_qpixmap_of(blocks, texture)[image_count]);
>>>>>>> be8dc67cd71c413ceaa2161fffdae1a0e6cada01
}


Breakable_block::Breakable_block(pair position) :
    Block(position)
{
    type = breakable;
    texture = crate;
    state = initial;

<<<<<<< HEAD
    sprite = gtexture->get_qpixmap_of(blocks, texture, 6);
    setPixmap(sprite[image_count]);
=======
    setPixmap(gtexture->get_qpixmap_of(blocks, texture, 6)[image_count]);
>>>>>>> be8dc67cd71c413ceaa2161fffdae1a0e6cada01
}

Active_block::Active_block(pair position) :
    Block(position)
{
    type = active;
    texture = question_mark;
    state = initial;

<<<<<<< HEAD
    sprite = gtexture->get_qpixmap_of(blocks, texture, 3);
    setPixmap(sprite[image_count]);
=======
    setPixmap(gtexture->get_qpixmap_of(blocks, texture, 3)[image_count]);
    image_count = 0;
>>>>>>> be8dc67cd71c413ceaa2161fffdae1a0e6cada01

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

<<<<<<< HEAD
    sprite = gtexture->get_qpixmap_of(blocks, texture);
    setPixmap(sprite[image_count]);
=======
    setPixmap(gtexture->get_qpixmap_of(blocks, texture)[image_count]);
>>>>>>> be8dc67cd71c413ceaa2161fffdae1a0e6cada01
}

Special_block_below::Special_block_below(pair position) :
    Block(position)
{
    type = permanent;
    texture = dirt;
    state = initial;

<<<<<<< HEAD
    sprite = gtexture->get_qpixmap_of(blocks, texture);
    setPixmap(sprite[image_count]);
=======
    setPixmap(gtexture->get_qpixmap_of(blocks, texture)[image_count]);
>>>>>>> be8dc67cd71c413ceaa2161fffdae1a0e6cada01
}
