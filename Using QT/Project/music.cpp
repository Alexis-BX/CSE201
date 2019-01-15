#include "listheaders.h"
#include "global.h"


Music::Music(QObject* parent):
    QMediaPlayer (parent)
{
    music = new QSound("://Images/Backgrounds/Main_background/song2.wav");
}

Music::~Music()
{
    delete (music);
}

void Music::start()
{
    music->play();
}

void Music::stop()
{
    music->stop();
}
