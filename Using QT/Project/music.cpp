#include "music.h"
#include "listheaders.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSound>
#include <QUrl>


Music::Music(QObject* parent):
    QObject(), QMediaPlayer (parent)
{
    QUrl url = QUrl(":/Images/Backgrounds/Main_background/song.wav");
    QMediaPlayer* music = new QMediaPlayer;
       music->setMedia(url);
       music->setVolume(100);
       music->play();
}
