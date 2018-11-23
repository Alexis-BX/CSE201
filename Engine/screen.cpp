#include "screen.h"


Screen::Screen(QWidget *parent, pair screen_size) : QGraphicsView(parent)
{
    scene = new QGraphicsScene();

    //scene->setSceneRect(0,0,screen_size.x,screen_size.y);

    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //setFixedSize(screen_size.x,screen_size.y);

    game_state = new GameState(scene,screen_size);

    QTimer * timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(next_frame()));

    timer->start(20);

    show();
}

void Screen::next_frame()
{
    game_state->next_frame();
}
