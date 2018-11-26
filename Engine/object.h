#ifndef OBJECT_H
#define OBJECT_H
#include <QObject>
#include <QGraphicsRectItem>

struct pair
{
    int x,y;
};


enum State
{
    normal_player,
    block_permanent,
    block_active,
    block_alive,
    baguette,
    star,
    mushroom,
    coin
};


/**
pair global_to_screen(pair &object_position, pair &screen_top_left);

#ifndef GLOBAL_TO_SCREEN_F
#define GLOBAL_TO_SCREEN_F


// from the global coordinates returns the screen coordinates
// the y axis of the global coordinates is upwards


EXPLANATION:
int x = object_position.x;
int y = object_position.y;
int a = screen_position.x;
int b = screen_position.y;

int c; // coordinates of the object in the frame of reference of the Screen (c along the x axis, d along the y axis)
int d;

c = x - a;
d = b - y; //the y axis in the frame of reference of the Screen goes downwards

#endif // GLOBAL_TO_SCREEN_F
**/


class Object: public QObject, public QGraphicsRectItem
{

public:

    pair position,size;


    Object(pair position, pair size, QGraphicsItem* parent=0);

    void next_frame(pair &screen_top_left);

};

#endif // OBJECT_H
