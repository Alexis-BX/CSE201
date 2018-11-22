#include "mushroom.h"

Mushroom::Mushroom(pr position, pr size, enum state)
{

}

void Mushroom::superpower(pr size)
{
    if (Collectibles::Pass_by == true) {
        if (Player::size != 2) { //if he is not already big
            Player::growbigger }
    }
}


