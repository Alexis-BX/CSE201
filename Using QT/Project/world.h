#ifndef WORLD_H
#define WORLD_H
#include "global.h"
#include "button.h"


class World: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    World(QGraphicsItem* parent = nullptr);

    int selected;

    void keyPressEvent(QKeyEvent * event);

    void check_position();

    QTimer* timer;

    QTimer* timerGO;

};

#endif // WORLD_H
