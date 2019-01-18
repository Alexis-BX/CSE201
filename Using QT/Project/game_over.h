#ifndef GAME_OVER_H
#define GAME_OVER_H
#include "global.h"

class Game_over: public QObject, public QGraphicsPixmapItem

{
public:
    Game_over(int score, QGraphicsItem* parent = nullptr);

    void keyPressEvent(QKeyEvent * event);
};

#endif // GAME_OVER_H
