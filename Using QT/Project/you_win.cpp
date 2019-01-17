#include "listheaders.h"

You_win::You_win(QGraphicsItem* parent):
     QObject(), QGraphicsPixmapItem (parent)
{
    setPos(0,-view->screen_size.y-18);

    view->centerOn(this);

    QPixmap img(":/Images/Backgrounds/Main_background/you_win.png");
    img = img.scaled(view->screen_size.x, view->screen_size.y);

    QPainter painter;
    if(painter.begin(&img))
    {
        painter.setPen(QPen(Qt::yellow));
        painter.setFont(QFont("Times",12,QFont::Bold));
        painter.drawText(QPoint(5,25),"Final Score: " + QString() );
        painter.end();
    }
    setPixmap(img);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void You_win::keyPressEvent(QKeyEvent *event)
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
