#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QKeyEvent>

struct double_pair
{
    int left,right,bottom,top;

};

struct pair
{
    int x,y;
};

class View;

extern View* view;

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    pair speedMax;
    pair speed;
    bool pressedL = false;
    bool pressedR = false;
    int size = 36;
    int N = 8;
    double count;
    QPixmap crouch[8];

    Player(QGraphicsItem* parent = 0);

    void keyPressEvent(QKeyEvent * event);

    void keyReleaseEvent(QKeyEvent * event);

    double_pair world_boundaries;

public slots:

    void move();

};

#endif // PLAYER_H
