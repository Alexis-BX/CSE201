#ifndef GOBJECT_H
#define GOBJECT_H
#include "global.h"
#define sizex boundingRect().width()
#define sizey boundingRect().height()


class GObject : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    GObject(QPoint position, QGraphicsItem* parent = nullptr);

public slots:

    virtual void move();

};

#endif // GOBJECT_H
