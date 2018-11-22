#include "object.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Object w;
    w.show();

    return a.exec();
}

pair global_to_screen(pair object_position, pair screen_position);
// from the global coordinates returns the screen coordinates
// the y axis of the global coordinates is upwards
{
    /**
    EXPLANATION:
    int x = object_position.x;
    int y = object_position.y;
    int a = screen_position.x;
    int b = screen_position.y;

    int c; // coordinates of the object in the frame of reference of the Screen (c along the x axis, d along the y axis)
    int d;

    c = x - a;
    d = b - y; //the y axis in the frame of reference of the Screen goes downwards
    **/

    pair position_in_screen; //what we want i.e. the vector (c,d)
    position_in_screen.x = object_position.x - screen_position.x;
    position_in_screen.y = screen_position.y - object.position.y;
    return position_in_screen;

}
