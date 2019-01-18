#ifndef GCLOCK_H
#define GCLOCK_H
#include "global.h"
#include "view.h"
#include "QGraphicsTextItem"

class GClock : public QGraphicsTextItem
{
    Q_OBJECT

public:

    GClock(int seconds, QGraphicsItem* parent = nullptr);

    ~GClock();

    void update();

    QTimer * timer;

public slots:

    void time_out();

};

#endif // GCLOCK_H
