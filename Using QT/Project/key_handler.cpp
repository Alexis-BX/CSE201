#include "listheaders.h"

Key_handler::Key_handler(QGraphicsItem* parent) : QGraphicsPixmapItem (parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);

    setFocus();
}

void Key_handler::keyPressEvent(QKeyEvent * event)
{
    switch(view->pressed_key_handler)
    {
    case control_player:
    {
        view->player->keyPressEvent(event);
        break;
    }
    case control_help:
    {
        view->help->keyPressEvent(event);
        break;
    }
    case control_menu:
    {
        view->menu->keyPressEvent(event);
        break;
    }
    case control_world:
    {
        view->world->keyPressEvent(event);
        break;
    }
    case control_game_over:
    {
        view->gameover->keyPressEvent(event);
        break;
    }
    case control_win:
    {
        view->youwin->keyPressEvent(event);
        break;
    }
    }
}

void Key_handler::keyReleaseEvent(QKeyEvent * event)
{
    switch(view->pressed_key_handler)
    {
    case control_world:
    case control_player:
    {
        view->player->keyReleaseEvent(event);
        break;
    }
    default:
    {
        break;
    }
    }
}
