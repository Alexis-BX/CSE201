#include "world.h"
#include "listheaders.h"

World::World( QGraphicsItem* parent):
     QObject(), QGraphicsPixmapItem (parent)
{

    bg = new Button(0, -505+18, QPixmap(":/Images/Menu/BackgroundWorld.png"), this);

    setZValue(layer_button);
}

void World::keyPressEvent(QKeyEvent *event)
{
       switch (event->key())
       {

       case Qt::Key_Enter:
       case Qt::Key_Space:
       case Qt::Key_Return:
       {
           check_position();
           break;
       }
       default:
       {
           view->player->keyPressEvent(event);
           break;
       }
       }

}

void World::check_position()
{
    int x = view->player->x();
    if (x > 170 && x < 225)
    {
        view->scene->clear();
        view->play_level(":/Images/Levels/Level_003.png");
    }

    else if (x > 370 && x < 422)
    {
        view->scene->clear();
        view->play_level(":/Images/Levels/Level_004.png");
    }

    else if (x > 568 && x < 620)
    {
        view->scene->clear();
        view->play_level(":/Images/Levels/Level_005.png");
    }
}
