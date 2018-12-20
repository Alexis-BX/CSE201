#ifndef COUNTER_H
#define COUNTER_H
#include <QGraphicsPixmapItem>
#include "tools.h"
#include <QObject>

class Counter : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Counter(pair position,QGraphicsItem* parent = 0);

    void update_counter(int counter);

};

#endif // COUNTER_H
