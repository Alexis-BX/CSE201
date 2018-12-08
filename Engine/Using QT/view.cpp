#include "view.h"
#include "player.h"
#include "block.h"
#include <QDebug>
#include <cstdlib>

View::View(pair screen_size, int block_size, QWidget* parent)
{
    this->block_size = block_size;

    scene = new QGraphicsScene();

    //scene->setSceneRect(-100,-100,100,100);

    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(screen_size.x,screen_size.y);

    player = new Player();

    player->setPos(50,-30);//int(screen_size.x/2),-int(screen_size.y/2));

    player->setFlag(QGraphicsItem::ItemIsFocusable);

    player->setFocus();

    scene->addItem(player);

    create_basic_world(100);
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

    int i = -(rand()%15 +5);
    for(int x = 0 ; x < width ; x++)
    {
        for(int y = 0 ; y < 2 ; y++)
        {
            create_block(pair{x*block_size,y*block_size});
        }
        if(x%3 == 0)
        {
            i += (rand()%3 )-1;
        }
        if(x > 15)
        {
            create_block(pair{x*block_size,i*block_size});

        }
    }
}

void View::create_block(pair position)
{
    Block* new_block = new Block(position);

    new_block->setPos(position.x,position.y);

    this->scene->addItem(new_block);
}
