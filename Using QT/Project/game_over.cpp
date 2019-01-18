#include "listheaders.h"

Game_over::Game_over(int final_score, QGraphicsItem* parent):
    QObject(), QGraphicsPixmapItem (parent)
{
    setPos(0,-view->screen_size.y-18);
    view->centerOn(this);

    QPixmap img(":/Images/Backgrounds/Main_background/game_over.png");
    img = img.scaled(view->screen_size.x, view->screen_size.y);
    QPainter painter;
    if(painter.begin(&img))
    {
        painter.setPen(QPen(Qt::yellow));
        painter.setFont(QFont("Times",12,QFont::Bold));
        painter.drawText(QPoint(5,25),"Final Score: " + QString(final_score) );
        painter.end();
    }
    setPixmap(img);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Game_over::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Enter:
    case Qt::Key_Space:
    case Qt::Key_Return:
    {
        deleteLater();

        view->world();

        break;
    }
    }
}

