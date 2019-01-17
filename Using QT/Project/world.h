#ifndef WORLD_H
#define WORLD_H
#include "global.h"
#include "button.h"


class World: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    World(QString level, QGraphicsItem* parent = nullptr);

    int selected;

    void keyPressEvent(QKeyEvent * event);

    void check_position();

    QTimer* timer;

    QTimer* timerGO;

    QString current_level;


};

#endif // WORLD_H
