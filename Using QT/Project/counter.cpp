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

    if(power_of_10 == 0)
    {
        update_counter(0);
    }
    else
    {
        update_counter(1);
    }
}

void Counter::update_counter(int counter)
{
    std::string path = ":/Images/Textures/Main_texture/number_";

    path.append(std::to_string(counter%2));

    path.append(".png");

    setPixmap(QPixmap(path.c_str()));
}


