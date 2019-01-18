#include "world.h"
#include "listheaders.h"

World::World( QGraphicsItem* parent):
     QObject(), QGraphicsPixmapItem (parent)
{
    bg = new Button(0, -505+18, QPixmap(":/Images/Backgrounds/BackgroundWorld.png"));

    view->level_load->load_level(":/Images/Backgrounds/world_block.png");

    view->scene->addItem(bg);

    setFlag(QGraphicsItem::ItemIsFocusable);

    setFocus();
}

void World::keyPressEvent(QKeyEvent *event)
{
       switch (event->key())
       {

       case Qt::Key_Enter:
       case Qt::Key_Space:
       case Qt::Key_Return:
       {
           qDebug()<<"a";
           check_position();
           break;
       }
       default:
       {
           qDebug()<<"a";
           view->player->keyPressEvent(event);
           break;
       }
       }

}

void World::check_position()
{
    if (x() > 170 && x() < 225)
    {
        view->scene->clear();
        view->play_level(":/Images/Levels/Level_003.png");
    }

    else if (x() > 370 && x() < 422)
    {
        view->scene->clear();
        view->play_level(":/Images/Levels/Level_004.png");
    }

    else if (x() > 568 && x() < 620)
    {
        view->scene->clear();
        view->play_level(":/Images/Levels/Level_005.png");
    }
}
