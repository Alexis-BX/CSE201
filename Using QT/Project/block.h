#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "tools.h"
#include "types_states_textures.h"
#include "collectable.h"
#include "collectables.h"

class Block : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Block_texture texture;

    Block_state state;

    Block_type type;

    Block(pair position, QGraphicsItem* parent = 0);

    int image_count{0};

    void is_hit();

public slots:

    void blink();

};

#endif // BLOCK_H
