#include "listheaders.h"

Game_over::Game_over(QGraphicsItem* parent):
    QObject(), QGraphicsPixmapItem (parent)
{
    setPos(view->player->x(),-500);
    QPixmap img(":/Images/Backgrounds/Main_background/game_over.png");
    setPixmap(img);
    //view->scene_game_over->addItem(this);
}
