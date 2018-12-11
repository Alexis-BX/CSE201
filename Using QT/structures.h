#ifndef STRUCTURES_H
#define STRUCTURES_H
#define greal double
#define pixmap_dir ":/images/pixmaps/"


struct double_pair
{
    int top,left,bottom,right;

};

struct pair
{
    greal x,y;
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

enum Object_type
{
    player,
    block,
    projectile,
    collectable
};

/**
template char* add_dir(char* image)
{
    const int length = strlen(pixmap_dir) + strlen(image) + 1;

    char pixmap[length];

    strcpy(pixmap,pixmap_dir);

    strcat(pixmap,image);

    return pixmap;
}
**/

#endif // STRUCTURES_H
