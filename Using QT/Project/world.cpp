#include "world.h"
#include "listheaders.h"

World::World(QGraphicsItem* parent):
     QObject(), QGraphicsPixmapItem (parent)
{

    view->level_load->load_level(":/Images/Backgrounds/world_block.png");

    view->scene->addItem(new Button(0, -505+18, QPixmap(":/Images/Backgrounds/BackgroundWorld.png")));

    selected = op_start;


}

void World::keyPressEvent(QKeyEvent *event)
{
       switch (event->key())
       {

       case Qt::Key_A:
       {
           check_position();
           break;
       }
       }

}

void World::check_position()
{
    switch (selected) {
    case op_start:
    {
        view->game_over();
        break;
    }
    }
}
