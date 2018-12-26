#include "counter.h"
#include "tools.h"
#include <string>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QObject>

Counter::Counter(int power_of_10, QGraphicsItem* parent) :
    QObject (), QGraphicsPixmapItem (parent)
{
    setPos(-(power_of_10+1)*size.x,0);
    update_counter(power_of_10);
}

void Counter::update_counter(int counter)
{
    std::string path = ":/Images/Textures/Main_texture/numbers.png";
    setPixmap(QPixmap(path.c_str()).copy(size.x*(counter%10), 0, size.x, size.y));
}


