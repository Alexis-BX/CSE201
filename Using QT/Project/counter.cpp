#include "counter.h"
#include "tools.h"
#include <string>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QtGui>
#include <QLCDNumber>

Counter::Counter(pair position,QGraphicsItem* parent) : QObject (), QGraphicsPixmapItem (parent)
{
    setPos(position.x,position.y);

    update_counter(1);
}

void Counter::update_counter(int counter)
{
    qDebug() << "here";

    std::string path = ":/Images/Levels/number_";

    path.append(std::to_string(counter));

    path.append(".png");

    qDebug() << path.c_str();

    setPixmap(QPixmap(path.c_str()));
}


