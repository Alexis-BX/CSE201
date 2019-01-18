#include "listheaders.h"

Counter::Counter(int power_of_10, QGraphicsItem* parent) :
    QObject (), QGraphicsPixmapItem (parent)
{
    setPos(-(power_of_10+1)*size.rx(),0);
    update_counter(power_of_10);
}

void Counter::update_counter(int counter)
{
    setPixmap(QPixmap(path).copy(size.rx()*(counter%10), 0, size.rx(), size.ry()));
}


