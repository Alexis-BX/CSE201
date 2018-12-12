#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QtWidgets>
#include "structures.h"
#include "types_states_textures.h"

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

    void create_block(pair position, Block_type type = Block_type{permanent},
                      Block_texture texture = Block_texture{brick},Block_state state = Block_state{initial} );

    void create_player(pair position = pair{300,-300});

    void set_scene_view();

    void create_example_world(int width);
    
    void readBMP(const char* filename);
    
    void convert (int v0,int v1,int v2, int i, int j);
};

#endif // VIEW_H
