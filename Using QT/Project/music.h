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
    void end();
    void win();

private:
    QSound *music;
    QSound *collect_cheese;
    QSound *music_end;
    QSound *music_win;
};

#endif // MUSIC_H
