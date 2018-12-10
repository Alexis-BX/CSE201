#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QtWidgets>
#include "structures.h"

class Player;

class View : public QGraphicsView
{

public:

    View(pair screen_size, int block_size = 18, QWidget * parent=0);


    //attributes
    int block_size;

    pair screen_size;

    double_pair world_size;

    QGraphicsScene * scene;

    Player* player;


    // Create world
    void create_basic_world(int width);

    void create_block(pair position);

    void create_player(pair position = pair{50,-60});

    void set_scene_view();
};

#endif // VIEW_H
