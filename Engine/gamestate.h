#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "player.h"
#include "block.h"
#include <QGraphicsScene>
#include <unordered_map>

struct pair_hasher
{
    std::size_t operator()(const pair& p) const
    {
        return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
    }
};

struct pair_equal_to
{
    bool operator() (const pair &p1, const pair &p2) const
    {
        return p1.x==p2.x && p1.y==p2.y;
    }
};

class GameState
{

public:

    const int chunk_size,block_size;

    pair screen_size, screen_top_left, screen_top_left_chunk, chunks_on_screen;

    QGraphicsScene* scene;

    Player* player;

    std::unordered_map<pair,std::list<Block*>,pair_hasher,pair_equal_to> chunk_to_blocks;

    GameState(QGraphicsScene* scene, pair screen_size);

    void create_block(pair position, pair size);

    void create_block(pair position);

    void create_player(pair position);

    void create_basic_world(int height, int length);

    void check_collision(Block*,Player*);

public slots:

    void next_frame();


};


#endif // GAMESTATE_H
