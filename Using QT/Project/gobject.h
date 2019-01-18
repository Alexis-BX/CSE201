#ifndef GOBJECT_H
#define GOBJECT_H
#include "global.h"
#define sizex boundingRect().width()
#define sizey boundingRect().height()

enum General_state
{
    Alive,
    Dead,
    Win
};

class GObject : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    GObject(QPoint position, QGraphicsItem* parent = nullptr);

    General_state gstate{Alive};

public slots:

    virtual void move();

};

#endif // GOBJECT_H
