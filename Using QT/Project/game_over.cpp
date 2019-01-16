#include "listheaders.h"

Game_over::Game_over(QGraphicsItem* parent):
    QObject(), QGraphicsPixmapItem (parent)
{
    setPos(0,-view->screen_size.y-18);
    view->centerOn(this);

    QPixmap img(":/Images/Backgrounds/Main_background/game_over.png");
    img = img.scaled(view->screen_size.x, view->screen_size.y);
    setPixmap(img);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    QString score="Final Score:";
    QPainter painter(&img) ;
    painter.drawText(QPoint(5,25),score);


}

void Game_over::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Return:
    {
        deleteLater();

        view->play_level(view->current_level);
    }
    }
}

