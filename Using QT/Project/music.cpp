#include "listheaders.h"
#include "global.h"


Music::Music(QObject* parent):
    QMediaPlayer (parent)
{
    music = new QSound("://Images/Backgrounds/Main_background/song3.wav");
    collect_cheese = new QSound("://Images/Backgrounds/Main_background/cheese.wav");
    music_end = new QSound("://Images/Backgrounds/Main_background/end.wav");
    music_win = new QSound("://Images/Backgrounds/Main_background/win.wav");
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

void Music::end()
{
    music_end->play();
}

void Music::win()
{
    music_win->play();
}

void Music::stop()
{
    music->stop();
}
