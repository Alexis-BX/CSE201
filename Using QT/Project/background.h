#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "global.h"

class Background : public QGraphicsPixmapItem
{

public:

    int speed_ratio, width, height;

    QPixmap sprite;

    Background(pair position, QGraphicsItem *parent = nullptr);

    ~Background();
};

#endif // BACKGROUND_H
