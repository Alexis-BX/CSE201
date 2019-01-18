#include "listheaders.h"

You_win::You_win(int score, QGraphicsItem* parent):
     QObject(), QGraphicsPixmapItem (parent)
{
    setPos(0,-view->screen_size.y-18);

    view->centerOn(this);

    QPixmap img(":/Images/Menu/you_win.png");
    img = img.scaled(view->screen_size.x, view->screen_size.y);

    QPainter painter;
    if(painter.begin(&img))
    {
        painter.setPen(QPen(Qt::red));
        painter.setFont(QFont("Times",30,QFont::Bold));
        painter.drawText(QPoint(320,40),"Final Score: " + QString(QString::number(score)));
        painter.end();
    }
    setPixmap(img);
}

void You_win::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Return:
    {
        view->open_world();
    }
    }
}
