#include "coin_counter.h"
#include "collectable.h"
#include "player.h"
#include "view.h"

coin_counter::coin_counter()
{

}

void coin_counter::add_coin(Collectable collectable)
{
    int count = 0;
    if (collectable.type == coin)
    {
        if (collectable.state == used)
        {
            count += 1;
        }
    }
}
