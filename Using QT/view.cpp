#include "view.h"
#include "player.h"
#include "block.h"
#include "structures.h"
#include <QDebug>
#include <cstdlib>

View::View(pair screen_size, int block_size, QWidget* parent)
{
    world_size = double_pair{-1500,0,0,10000};

    this->block_size = block_size;

    this->screen_size = screen_size;


    //Create world
    set_scene_view();

    create_example_world(world_size.right-world_size.left);

    create_player();

}

void View::create_basic_world(int width)
{   //test blocks

    create_block(pair{150,-18});
    create_block(pair{150,-36});
    create_block(pair{150,-54});

    create_block(pair{20,-18});
    create_block(pair{20,-36});
    create_block(pair{20,-54});

    create_block(pair{254,-18});
    create_block(pair{254,-36});
    create_block(pair{254,-54});


    create_block(pair{58,-162});
    create_block(pair{40,-162});
    create_block(pair{76,-162});
    create_block(pair{94,-162});

    create_block(pair{200,-108});
    create_block(pair{218,-108});
    create_block(pair{236,-108});
    create_block(pair{254,-108});
    create_block(pair{272,-108});

    create_block(pair{550,-18});
    create_block(pair{450,-36});
    create_block(pair{350,-54});
    create_block(pair{650,-72});
    create_block(pair{750,-90});
    create_block(pair{750,-108});
    create_block(pair{850,-1});


    for(int x = 0 ; x < width ; x++)
    {
        for(int y = 0 ; y < 2 ; y++)
        {
            create_block(pair{greal(x*block_size),greal(y*block_size)});
        }
        create_block(pair{greal(x*block_size),greal(world_size.top)});
    }
}

void View::create_block(pair position, Block_type type, Block_texture texture,Block_state state )
{
    Block* new_block = new Block(position, type, texture, state);

    new_block->setPos(position.x,position.y-36); // the -36 is temporary

    this->scene->addItem(new_block);
}

void View::create_player(pair position)
{
    player = new Player();

    player->setPos(position.x,position.y);

    player->setFlag(QGraphicsItem::ItemIsFocusable);

    player->setFocus();

    scene->addItem(player);

    centerOn(player);
}

void View::set_scene_view()
{
    scene = new QGraphicsScene();

    scene->setSceneRect(world_size.left,world_size.top,world_size.right-world_size.left,world_size.bottom-world_size.top);

    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(screen_size.x,screen_size.y);
}

void View::create_example_world(int width) // under construction
{

    const int number_blocks = 15;

    pair block_position[number_blocks];

    Block_type block_type[number_blocks];

    Block_texture block_texture[number_blocks];

    greal xi = 5, yi = 10;

    int number = 5,start = 0;

    for(int i = start; i < number ; i++)
    {
        block_position[i] = pair{xi+i,yi};

        block_type[i] = permanent;

        block_texture[i] = (i%2 == 0) ? crate : question_mark;
    }

    xi = 15, yi = 11;

    start = 5;

    for(int i = start; i < number+ start ; i++)
    {
        block_position[i] = pair{xi+i,yi};

        block_type[i] = permanent;

        block_texture[i] = (i%2 == 0) ? crate : question_mark;
    }

    xi = 25, yi = 9;

    start = 10;

    for(int i = start; i < number+ start ; i++)
    {
        block_position[i] = pair{xi+i,yi};

        block_type[i] = permanent;

        block_texture[i] = (i%2 == 0) ? crate : question_mark;
    }

    for(int i = 0; i < number_blocks; i++)
    {
        create_block(pair{block_position[i].x*block_size, - block_position[i].y*block_size}, block_type[i], block_texture[i]);
    }

    int h = 2;

    bool is_grass = false;

    int change = rand() % 10 + 5;

    int i = 0;

    for(int x = 0 ; x < width ; x++)
    {

        if(i == change)
        {
            change =  rand() % 10 + 5;
            i = 0;
            is_grass = !is_grass;
        }
        else
        {
            i ++;
        }

        if(rand()%100<10)
        {
            h++;
        }
        if(rand()%100<10)
        {
            h--;
        }
        for(int y = -h ; y < 2 ; y++)
        {
            create_block(pair{greal(x*block_size),greal(y*block_size)}, permanent , (is_grass)? grass : brick);
        }
    }
}

