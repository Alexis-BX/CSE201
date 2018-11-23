#ifndef SCREEN_H
#define SCREEN_H

#include "gamestate.h"
#include <QGraphicsView>
#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>

class Screen: public QGraphicsView
{

    Q_OBJECT

public:

    Screen(QWidget* parent = 0, pair screen_size = pair{800,600});

    QGraphicsScene* scene;

    GameState* game_state;

public slots:

    void next_frame();

};

#endif // SCREEN_H
