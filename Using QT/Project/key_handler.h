#ifndef KEY_HANDLER_H
#define KEY_HANDLER_H
#include "global.h"

class Key_handler : public QGraphicsPixmapItem
{
    //Q_OBJECT

public:
    Key_handler(QGraphicsItem* parent = nullptr);

    void keyPressEvent(QKeyEvent * event);

    void keyReleaseEvent(QKeyEvent * event);

    ~Key_handler() {};
};

#endif // KEY_HANDLER_H
