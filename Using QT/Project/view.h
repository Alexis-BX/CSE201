#ifndef VIEW_H
#define VIEW_H
#include "global.h"

#include "level_load.h"
#include "backgrounds.h"
#include "music.h"
#include "menu.h"

class Player;

class View : public QGraphicsView
{

public:

    View(pair screen_size, int block_size = 18, QWidget * parent=nullptr);

    //attributes
    int block_size, ms_between_updates{30};

    pair screen_size;

    double_pair world_size;

    Player* player;

    Level_load* level_load;
    QString current_level;

    Music * music;

    Music * collect_cheese;

    Menu * menu;

    QGraphicsScene *scene_menu  = new QGraphicsScene();
    QGraphicsScene *scene  = new QGraphicsScene();
    QGraphicsScene *scene_game_over  = new QGraphicsScene();
    QGraphicsScene *scene_you_win  = new QGraphicsScene();

    //backgrounds
    //std::vector<Background*> backgrounds;
    std::vector<Background_far*> backgrounds_far;
    std::vector<Background_middle*> backgrounds_middle;
    std::vector<Background_close*> backgrounds_close;

    // Create world
    void collect();

    void update_background();

    void game_over();

    void you_win();

    void open_menu();

    void play_level(QString level_name);

    template <class BG> void update_single_bg(std::vector<BG*> &list);
};

#endif // VIEW_H
