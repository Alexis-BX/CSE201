#include "listheaders.h"
#include "global.h"


Music::Music(QObject* parent):
    QMediaPlayer (parent)
{
    music = new QSound("://Images/Backgrounds/Main_background/song.wav");
    music->play();
}

Music::~Music()
{
    delete (music);
}


void Music::stop()
{
    music->stop();
}
