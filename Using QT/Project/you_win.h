#ifndef YOU_WIN_H
#define YOU_WIN_H
#include "global.h"

class You_win: public QObject,public QGraphicsPixmapItem
{
public:
    You_win(QGraphicsItem* parent = nullptr);

    void keyPressEvent(QKeyEvent * event);

};

#endif // YOU_WIN_H
