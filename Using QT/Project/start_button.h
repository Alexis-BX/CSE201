#ifndef START_BUTTON_H
#define START_BUTTON_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include "tools.h"

class Start_button: public QObject, public QGraphicsPixmapItem
{
   Q_OBJECT

public:

    Start_button(pair screen_size);

};

#endif // START_BUTTON_H
