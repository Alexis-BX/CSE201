#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "global.h"

class background : public QGraphicsPixmapItem
{
public:
    QPixmap sprite;

    int speed_ratio, width;

    background(const char * img, pair position, int speed_ratio, QGraphicsItem *parent = 0);

    background(pair position, QGraphicsItem *parent = 0);

    virtual QPainterPath shape() const;
};

#endif // BACKGROUND_H
