#ifndef GAME_OVER_H
#define GAME_OVER_H
#include "global.h"

class Game_over: public QObject, public QGraphicsPixmapItem

{
public:
    Game_over(QGraphicsItem* parent = nullptr);
//    void game_over();
};

#endif // GAME_OVER_H
