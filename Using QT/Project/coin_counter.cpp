#include "coin_counter.h"
#include "collectable.h"
#include "collectables.h"
#include "player.h"
#include "view.h"
<<<<<<< HEAD
#include "global.h"
#include "tools.h"
#include "types_states_textures.h"



class View;

extern View* view;

=======
>>>>>>> e60f3f225943bfff56b37fd66cfa9c9e875cec33

Coin_counter::Coin_counter()
{
<<<<<<< HEAD
    coins = 0;

    Counter* counter = new Counter(pair{0 ,-100},this);

    counters.push_back(counter);

    qDebug() << "first counter created";

    qDebug() << counter->x();

    qDebug() << counter->y();

    //qDebug() << view->player->x();

    qDebug() << "accessed view";

    //view->scene->addItem(counter);

    qDebug() << "counter added to scene";

    qDebug() << "here";
}

void Coin_counter::add_coin()
{
    coins ++;

    update_counter();
}

void Coin_counter::update_counter()
{
    if(coins/(10^int(counters.size()))>=1)
    {
        Counter* counter = new Counter(pair{150-36*double(counters.size()),-150},this);

        counters.push_back(counter);
    }

    for(int i = 0 ; i < int(counters.size()) ; i ++)
    {
        counters[i]->update_counter(int(coins/(10^counters.size())));
    }
=======
    setPos (0,0);
>>>>>>> e60f3f225943bfff56b37fd66cfa9c9e875cec33

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
