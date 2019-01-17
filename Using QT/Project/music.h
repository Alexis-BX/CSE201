#ifndef MUSIC_H
#define MUSIC_H
#include "global.h"
#include <QtMultimedia>

class Music:  public QMediaPlayer
{
public:
    Music(QObject *parent = nullptr);
    ~Music();
    void stop();
    void start();
    void cheese();

private:
    QSound *music;
    QSound *collect_cheese;
};

#endif // MUSIC_H
