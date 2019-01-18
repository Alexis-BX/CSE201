#ifndef WORLD_H
#define WORLD_H
#include "global.h"
#include "button.h"


class World: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    Button * bg;

    World( QGraphicsItem* parent = nullptr);

    void keyPressEvent(QKeyEvent * event);

    void check_position();
};

#endif // WORLD_H
