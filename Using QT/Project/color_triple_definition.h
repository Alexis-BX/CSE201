#ifndef COLOR_TRIPLE_CONSTRUCTORS_H
#define COLOR_TRIPLE_CONSTRUCTORS_H
#include "color_triple.h"
#include "view.h"

template<class T> Color_triple<T>::Color_triple(int R, int G, int B, View* view)
{
    this->view = view;
    r = R;
    g = G;
    b = B;
}

template<class T> void Color_triple<T>::test(int R, int G, int B, pair &position)
{
    if (abs(R-r)<=diff && abs(G-g)<=diff && abs(B-b)<=diff)
    {
        view->scene->addItem(new T{position});
    }
}

#endif // COLOR_TRIPLE_CONSTRUCTORS_H
