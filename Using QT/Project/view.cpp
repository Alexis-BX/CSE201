#include "listheaders.h"

View::View(pair screen_size, int block_size, QWidget* parent) :
    QGraphicsView(parent), block_size(block_size), screen_size(screen_size)
{
    //fluidifies image adition in the background along with some animations
    setViewportUpdateMode(FullViewportUpdate);//if problems (to slow): MinimalViewportUpdate

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(int(screen_size.x),int(screen_size.y));

    level_load = new Level_load(this);

    music = new Music();

    current_level = ":/Images/Levels/Level_adrien.png";

    for(int i = 0; i < scene_name_counter; i++)
    {
        scenes.push_back(new QGraphicsScene());
    }
}

void View::update_background()
{
    update_single_bg<Background_far>(backgrounds_far);
    update_single_bg<Background_middle>(backgrounds_middle);
    update_single_bg<Background_close>(backgrounds_close);
}


void View::game_over()
{
    music->stop_song(); //stops the background music

    music->play_sound_effect(music_end); //calls the game over music

    int score = player->coin_counter->coins;

    clear_scenes();

    setScene(scenes[scene_game_over]);

    scenes[scene_game_over]->addItem(new Key_handler);

    pressed_key_handler = control_game_over;

    gameover = new Game_over(score);

    scenes[scene_game_over]->addItem(gameover);
}

void View::you_win()
{
    music->stop_song(); //stops the background music

    music->play_sound_effect(music_win); //plays the winning music

    int score = player->coin_counter->coins;

    clear_scenes();

    setScene(scenes[scene_you_win]);

    scenes[scene_you_win]->addItem(new Key_handler);

    pressed_key_handler = control_win;

    youwin = new You_win(score);

    scenes[scene_you_win]->addItem(youwin);
}

void View::open_menu()
{
    setScene(scenes[scene_menu]);

    scenes[scene_menu]->addItem(new Key_handler);

    pressed_key_handler = control_menu;

    menu = new Menu();

    scenes[scene_menu]->addItem(menu);
}

void View::open_help()
{
    setScene(scenes[scene_help]);

    scenes[scene_help]->addItem(new Key_handler);

    pressed_key_handler = control_help;

    help = new Help();

    scenes[scene_help]->addItem(help);
}

void View::open_world()
{
    clear_scenes();

    pressed_key_handler = control_world;

    play_level(":/Images/Levels/level_world.png", true);

    scenes[scene_level]->addItem(new Key_handler);

    pressed_key_handler = control_world;

    world = new World();

    scenes[scene_level]->addItem(world);
}

void View::clear_scenes(int scene)
{
    if(scene == all)
    {
        for(int i = 0; i < scene_name_counter; i++)
        {
            scenes[i]->clear();
        }
    }
    else
    {
        scenes[scene]->clear();
    }
}


void View::play_level(QString level_name, bool is_world)
{
    clear_scenes();

    setScene(scenes[scene_level]);

    scenes[scene_level]->addItem(new Key_handler);

    if (!is_world)
    {
        pressed_key_handler = control_player;
    }

    level_load->load_level(level_name);

    music->start_song();
}




template <class BG> void View::update_single_bg(std::vector<BG*> &list)
{
    for(unsigned long long i = 0 ; i < list.size(); i++)
    {
        list[i]->setX((list[i]->x())-(player->speed.rx())/(list[i]->speed_ratio));
    }

    if (list[0]->x() > player->x()-screen_size.x)
    {
        list.insert(list.begin(), new BG(pair{list[0]->x()-(list[0]->width),0}));
        scenes[scene_level]->addItem(list[0]);
    }
    else if (list[0]->x() + list[0]->width < player->x() - screen_size.x)
    {
        scenes[scene_level]->removeItem(list[0]);
        delete(list[0]);
        list.erase(list.begin());
    }

    if (list.back()->x() + list.back()->width < player->x() + screen_size.x/2)
    {
        list.push_back(new BG(pair{list.back()->x()+list.back()->width,0}));
        scenes[scene_level]->addItem(list.back());
    }
    else if (list.back()->x() > player->x() + screen_size.x)
    {
        scenes[scene_level]->removeItem(list[list.size()-1]);
        delete(list[list.size()-1]);
        list.pop_back();
    }
}
