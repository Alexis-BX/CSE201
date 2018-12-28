#include "listheaders.h"

Enemy_1::Enemy_1(pair position, QGraphicsItem* parent) :
    Enemy(position, parent)
{
    speed = pair{-5,2};
    speedMax = pair{10,15};

    type = basic;
    state = passiv;
    texture = normal;

    size = pair{36,36};
    number_of_frames = 4;
    life = 100;

    QPixmap temp;

    //setting animations
    animation[1] = gtexture->get_qpixmap_of(enemy_1, 0, number_of_frames, int(size.x));

    for(int i = 0; i < number_of_frames; i++)
    {
        temp.convertFromImage(animation[1][i].toImage().mirrored(true,false));
        animation[0].push_back(temp);
    }
    setPixmap(animation[0][0]);


    create_collision_range();
}

Enemy_2::Enemy_2(pair position, QGraphicsItem* parent) :
    Enemy(position, parent)
{


}
