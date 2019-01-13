#ifndef MUSIC_H
#define MUSIC_H
#include "global.h"
#include <QtMultimedia>

class Music:  public QMediaPlayer
{
public:
    Music(QObject *parent = nullptr);
};

#endif // MUSIC_H
