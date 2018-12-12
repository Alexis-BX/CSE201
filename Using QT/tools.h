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

template <typename T> T min(T a, T b);

template <typename T> T min(T a, T b, T c);

template <typename T> T max(T a,T b);

template <typename T> T max_of(pair p);

template <typename T> bool same_sign(T a, T b);

template <typename T> T abs(T a);

const char* add_dir(const char* image);

#endif // STRUCTURES_H
