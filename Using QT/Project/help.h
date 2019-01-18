#ifndef HELP_H
#define HELP_H
#include "global.h"

class Help:public QObject, public QGraphicsPixmapItem
{
public:
    Help(QGraphicsItem* parent = nullptr);

    void keyPressEvent(QKeyEvent * event);
};

#endif // HELP_H
