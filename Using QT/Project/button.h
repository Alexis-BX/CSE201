#ifndef BUTTON_H
#define BUTTON_H
#include "global.h"

class Button : public QObject, public QGraphicsPixmapItem
{
public:
    Button(int x, int y, QPixmap sprite, QGraphicsItem* parent = nullptr);
};

#endif // BUTTON_H
