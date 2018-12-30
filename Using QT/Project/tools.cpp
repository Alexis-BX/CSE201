#include "listheaders.h"

void delay(int i) //milliseconds
{
    QTime dieTime= QTime::currentTime().addMSecs(i);

    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

greal distance(pair a, pair b)
{
    greal dx = a.x-b.x;

    greal dy = a.y-b.y;

    return (dx*dx)+(dy*dy);
}
