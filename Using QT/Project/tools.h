#ifndef STRUCTURES_H
#define STRUCTURES_H
#define greal double
#include <QList>
#include <QGraphicsRectItem>
#include <QPen>

struct double_pair
{
    int top,left,bottom,right;
};

struct pair
{
    greal x,y;
};

enum Direction
{
    Left,
    Right
};

template <typename T> T min(T a, T b)
{
    return (a > b) ? b : a;
};

template <typename T> T min(T a, T b, T c)
{
    T mab = min<T>(a,b);
    return (mab > c) ? c : mab;
};


template <typename T> T max(T a,T b)
{
    return (a < b) ? b : a;
};

template <typename T> T max_of(pair p)
{
    return (p.x < p.y) ? p.y : p.x;
};

template <typename T> bool same_sign(T a, T b)
{
    return ((a > 0 && b > 0) || (a < 0 && b < 0));
};

template <typename T> T abs(T a)
{
    return (a<0) ? -a : a;
};

template <typename T> QList<QGraphicsRectItem*> create_collision_range(T* parent)
{
    QList<QGraphicsRectItem*> temp_list;
    for(int i = 0; i < 3 ; i ++)
    {
        temp_list.push_back(new QGraphicsRectItem(parent));
        //temp_list[i]->setPen(QPen(Qt::NoPen));
    }
    return temp_list;
}

void create_random_powerup(pair position, double y_offset);

void update_collision_range(QList<QGraphicsRectItem*> &collision_ranges,pair &size, pair &speed);

greal distance(pair a, pair b);

void delay(int i);


#endif // STRUCTURES_H
