#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "global.h"

class Background : public QGraphicsPixmapItem
{

public:

    int speed_ratio, width, hight;

    QPixmap sprite;

    Background(pair position, QGraphicsItem *parent = 0);

    virtual QPainterPath shape() const;
};

#endif // BACKGROUND_H
