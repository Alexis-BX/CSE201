#include "coin_counter.h"
#include "collectable.h"
#include "collectables.h"
#include "player.h"
#include "view.h"
#include "global.h"

Coin_counter::Coin_counter(QGraphicsItem* parent) : QObject (), QGraphicsPixmapItem (parent)
{
    coins = 0;

    Counter* counter = new Counter(pair{150,-150},this);

    qDebug() << "first counter created";

    qDebug() << counter->x();

    qDebug() << counter->y();

    //qDebug() << view->player->x();


    qDebug() << "accessed view";

    //view->scene->addItem(counter);

    qDebug() << "counter added to scene";

    counters.push_back(counter);


    qDebug() << "heere";
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

}



/*int Coin_counter::add_coin(Collectable collectable)
{
    int count = 0;
    if (collectable.type == coin)
    {
<<<<<<< HEAD
        count += 1;
=======
        if (collision_up() == true || collision_down() == true || collision_left() == true || collision_right() == true)
        {
            count += 1;
        }
>>>>>>> 4ee68fda1702c7bcb826a1e273a8a77166b6823a
    }
    return count;
}*/
/**
void Coin_counter::update_counter()
{
    int unit = coins % 10;
    switch (unit)
    {
        case 1:
        setPixmap(QPixmap(":/Images/Levels/sticker-numero-un.jpg"));
        //setPos(size of image)
        break;

    case 2:
        break;

    }

    int tens = (coins - coins % 10)/10;
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
**/
