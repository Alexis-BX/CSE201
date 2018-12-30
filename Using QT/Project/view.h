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
    int block_size;

    pair screen_size;

    double_pair world_size;

    Player* player;

    Level_load* level_load;

    //backgrounds
    std::vector<Background*> backgrounds;
    std::vector<Background_far*> backgrounds_far;

    /**
    class Background_far * Background_far;
    class Background_middle * monuments;
    class Background_close * buildings;
    **/

    void applyParallax(Background* item);

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
};

#endif // VIEW_H
