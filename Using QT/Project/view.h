#ifndef VIEW_H
#define VIEW_H
#include "global.h"

#include "level_load.h"
#include "backgrounds.h"

class Player;

class View : public QGraphicsView
{

public:

    View(pair screen_size, int block_size = 18, QWidget * parent=0);

    //attributes
    int block_size, ms_between_updates{30};

    pair screen_size;

    double_pair world_size;

    Player* player;

    Level_load* level_load;

    QGraphicsScene *scene  = new QGraphicsScene();

    //backgrounds
    //std::vector<Background*> backgrounds;
    std::vector<Background_far*> backgrounds_far;
    std::vector<Background_middle*> backgrounds_middle;
    std::vector<Background_close*> backgrounds_close;

    // Create world
    void create_basic_world(int width);

    void create_player(pair position = pair{300,-300});

    void create_block(pair position, Block_type type = Block_type{permanent},
                      Block_texture texture = Block_texture{brick},Block_state state = Block_state{initial} );

    void create_example_world(int width);

    void readBMP(const char* filename);

    void convert (int v0,int v1,int v2, int i, int j);

    void start_screen();

    void update_background();

    template <class BG> std::vector<BG*> update_single_bg(std::vector<BG*> list, double offset);
};

#endif // VIEW_H
