#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QtWidgets>

class Player;

struct pair
{
    int x,y;
};

class View : public QGraphicsView
{

public:

    View(pair screen_size, int block_size = 10, QWidget * parent=0);

    int block_size;

    int screen_sizex,screen_sizey;

    QGraphicsScene * scene;

    Player* player;

    void create_basic_world(int width);

    void create_block(pair position);
};

#endif // VIEW_H
