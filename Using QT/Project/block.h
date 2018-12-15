#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "tools.h"
#include "types_states_textures.h"

class Block : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Block_texture texture;

    Block_state state;

    Block_type type;

    Block(pair position, Block_type type = Block_type{permanent},
          Block_texture texture = Block_texture{brick}, Block_state state = Block_state{initial},
          QGraphicsItem* parent = 0);

    int image_count;

public slots:

    void blink();

};

#endif // BLOCK_H
