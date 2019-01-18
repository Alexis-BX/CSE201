#include "gclock.h"
#include "listheaders.h"

GClock::GClock(int seconds, QGraphicsItem* parent) :
    QGraphicsTextItem (parent)
{
    setPos(view->screen_size.x/2-72,36-view->screen_size.y);

    setZValue(layer_clock);

    setDefaultTextColor(Qt::white);

    setFont(QFont("Times", 25, QFont::Bold));


    timer = new QTimer();

    timer->setSingleShot(true);

    timer->setInterval(seconds*1000);

    timer->connect(timer,SIGNAL(timeout()),this,SLOT(time_out()));

    timer->start();
}

GClock::~GClock()
{
    timer->stop();

    timer->deleteLater();
}

void GClock::update()
{
    setPlainText("time left: " + QString(QString::number(timer->remainingTime()/1000)));

    if(view->player->x() < view->world_size.left + view->screen_size.x/2 || view->player->x() > view->world_size.right + view->screen_size.x/2)
    {
        return;
    }

    setX(view->player->x()-72);
}

void GClock::time_out()
{
    view->game_over();
}
