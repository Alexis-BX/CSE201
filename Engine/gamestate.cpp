#include "gamestate.h"
#include "player.h"
#include <QGraphicsItem>

GameState::GameState(QGraphicsScene* scene, pair screen_size):
    chunk_size(10), block_size(10), screen_size(screen_size),
    scene(scene)
{
    chunks_on_screen = pair{int(screen_size.x/chunk_size),int(screen_size.y/chunk_size)};

    create_basic_world(3,10);

    create_player(pair{50,100});
}

void GameState::create_block(pair position, pair size)
{
    pair chunk = pair{int(position.x/chunk_size),int(position.y/chunk_size)};

    Block* new_block = new Block(position,size);

    new_block->setPos(position.x,position.y);

    new_block->setRect(position.x,position.y,size.x,size.y);

    this->scene->addItem(new_block);

    if(chunk_to_blocks.count(chunk))
    {

        chunk_to_blocks[chunk].push_back(new_block);

    }
    else
    {

        std::list<Block*> new_block_list{new_block};

        chunk_to_blocks.insert(std::make_pair(chunk,new_block_list));

    }
}

void GameState::create_block(pair position)
{
    create_block(position,pair{block_size,block_size});
}

void GameState::create_player(pair position)
{
    printf("yes");

    player = new Player(pair{position.x,position.y});

    this->scene->addItem(player);
}

void GameState::create_basic_world(int height, int length)
{
    for(int x = 0 ; x < length ; x++)
    {
        for(int y = 0 ; y < height ; y++)
        {
            create_block(pair{x*block_size,y*block_size});
        }
    }
};

void GameState::check_collision(Block * block, Player * player)
{

    if(player->position.x<block->position.x+block->size.x
            && player->position.x+player->size.x>block->position.x)
    {

        if(player->position.y-player->size.y>=block->position.y-block->size.y
                && player->position.y-player->size.y<=block->position.y)
        {

            player->position.y = block->position.y+player->size.y;

            player->speed.y = std::max<int>(player->speed.y,0);

        }
        else if(player->position.y>=block->position.y+block->size.y
                && player->position.y<=block->position.y)
        {
            player->position.y = block->position.y-block->size.y;

            player->speed.y = std::min<int>(player->speed.y,0);
        }
    }
}

void GameState::next_frame()
{
    player->next_position();

    pair player_position = player->position;

    pair player_chunk{int(player_position.x/chunk_size),int(player_position.y/chunk_size)};

    for(int i = -1; i <= 1 ; i++)
    {

        for(int j = -1; j <= 1 ; j++)
        {

            pair collision_chunk{player_chunk.x + i, player_chunk.y + j};

            if(chunk_to_blocks.count(collision_chunk))
            {

                for(auto block_iterator = chunk_to_blocks[collision_chunk].begin() ;
                    block_iterator != chunk_to_blocks[collision_chunk].end() ; ++ block_iterator)
                {

                    check_collision((*block_iterator),player);
                }
            }
        }
    }

    screen_top_left = pair{player_position.x-int(screen_size.x/2),player_position.y-int(screen_size.y/2)};

    screen_top_left_chunk = pair{screen_top_left.x/chunk_size,screen_top_left.y/chunk_size};

    for(int i = 0; i <= chunks_on_screen.x ; i++)
    {

        for(int j = -1; j <= chunks_on_screen.y ; j++)
        {

            pair chunk_to_update{screen_top_left_chunk.x + i, screen_top_left_chunk.y + j};

            if(chunk_to_blocks.count(chunk_to_update))
            {
                for(auto block_iterator = chunk_to_blocks[chunk_to_update].begin() ;
                    block_iterator != chunk_to_blocks[chunk_to_update].end() ; block_iterator++)
                {
                    (*block_iterator)->next_frame(screen_top_left,screen_size);
                }
            }
        }
    }

    player->next_frame(screen_top_left,screen_size);
}


