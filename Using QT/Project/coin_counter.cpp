#include "coin_counter.h"
#include "collectable.h"
#include "collectables.h"
#include "player.h"
#include "view.h"

Coin_counter::Coin_counter()
{
    setPos (0,0);

    setPixmap(QPixmap(":/Images/Levels/sticker-numero-un.jpg"));
}

/*int Coin_counter::add_coin(Collectable collectable)
{
    int count = 0;
    if (collectable.type == coin)
    {
        if (collision_up() == true || collision_down() == true || collision_left() == true || collision_right() == true)
        {
            count += 1;
        }
    }
    return count;
}*/

void Coin_counter::display_counter(int count)
{
    int unit = count % 10;
    switch (unit)
    {
        case 1:
        setPixmap(QPixmap(":/Images/Levels/sticker-numero-un.jpg"));
        //setPos(size of image)
        break;

    case 2:
        break;

    }

    int tens = (count - count % 10)/10;
    switch (tens)
    {
        case 1:
        setPixmap(QPixmap(":/Images/Levels/sticker-numero-un.jpg"));
        // setPos(size of image)
        break;

        case 2:
        break;
    }
}
