#ifndef BLOCK_H
#define BLOCK_H
#include "global.h"

class Block : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Block_texture texture;

    Block_state state;

    Block_type type;

    Block(pair position, QGraphicsItem* parent = nullptr);

    unsigned long long image_count{0};

    std::vector<QPixmap> sprite;

    void is_hit();

public slots:

    void blink();

};

#endif // BLOCK_H
