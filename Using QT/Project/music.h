#ifndef MUSIC_H
#define MUSIC_H
#include "global.h"
#include <QtMultimedia>

enum Sound_effects
{
    collect_cheese, //when collecting a cheese
    music_end, //game over music
    music_win, //winning music
    sound_effects_counter
};

class Music
{
public:
    Music();
    ~Music();
    void stop_song();
    void start_song();
    void play_sound_effect(Sound_effects sound_effect);

private:
    QSound * song;
    QList <QSound*> music;

};

#endif // MUSIC_H
