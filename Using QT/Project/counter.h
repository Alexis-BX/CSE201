#ifndef COUNTER_H
#define COUNTER_H
#include "global.h"

class Counter : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    QPoint size{18,18};

    const QString path{":/Images/Textures/Main_texture/numbers.png"};

    Counter(int power_of_10, QGraphicsItem* parent = nullptr);

    void update_counter(int counter);

};

#endif // COUNTER_H
