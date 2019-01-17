#include "listheaders.h"
#include "global.h"


Music::Music(QObject* parent):
    QMediaPlayer (parent)
{
    music = new QSound("://Images/Backgrounds/Main_background/song3.wav");
    collect_cheese = new QSound("://Images/Background/Main_background/cheese.wav");
}

Music::~Music()
{
    delete (music);
}

void Music::start()
{
    music->play();
    music->setLoops(QSound::Infinite);
}

void Music::cheese()
{
    collect_cheese->play();
}

void Music::stop()
{
    music->stop();
}
