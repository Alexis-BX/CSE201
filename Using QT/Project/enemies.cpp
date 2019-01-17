#include "listheaders.h"

Enemy_1::Enemy_1(pair position, QGraphicsItem* parent) :
    Enemy(position, parent)
{
    speed = pair{-5,2};
    speedMax = pair{5,15};

    type = basic;
    state = passiv;
    texture = normal;

    size = pair{36,36};
    number_of_frames = 4;
    life = 100;

    QPixmap temp;

    //setting animations
    animation[1] = gtexture->get_qpixmap_of(enemy_1, 0, number_of_frames, size);

    for(int i = 0; i < number_of_frames; i++)
    {
        temp.convertFromImage(animation[1][i].toImage().mirrored(true,false));
        animation[0].push_back(temp);
    }
    setPixmap(animation[0][0]);
}

Enemy_2::Enemy_2(pair position, QGraphicsItem* parent) :
    Enemy(position, parent){
    speed = pair{-5,2};
    speedMax = pair{5,15};

    type = cloud;
    state = passiv;
    texture = normal;

    size = pair{54,36};
    number_of_frames = 2;
    life = 100;

    QPixmap temp;

    //setting animations
    animation[1] = gtexture->get_qpixmap_of(enemy_2, 0, number_of_frames, size);

    for(int i = 0; i < number_of_frames; i++)
    {
        temp.convertFromImage(animation[1][i].toImage().mirrored(true,false));
        animation[0].push_back(temp);
    }
    setPixmap(animation[0][0]);
}

Enemy_3::Enemy_3(pair position, QGraphicsItem* parent) :
    Enemy(position, parent){
    speed = pair{-5,3};
    speedMax = pair{5,20};

    type = smoker;
    state = passiv;
    texture = normal;

    size = pair{36,36};
    number_of_frames = 3;
    life = 100;

    QPixmap temp;

    //setting animations
    animation[1] = gtexture->get_qpixmap_of(enemy_3, 0, number_of_frames, size);

    for(int i = 0; i < number_of_frames; i++)
    {
        temp.convertFromImage(animation[1][i].toImage().mirrored(true,false));
        animation[0].push_back(temp);
    }
    setPixmap(animation[0][0]);
}
