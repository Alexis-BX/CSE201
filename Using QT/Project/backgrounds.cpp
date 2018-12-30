#include "listheaders.h"

Background_far::Background_far(pair position): Background(position)
{
    sprite = QPixmap(gtexture->get_path_to(background_far));
    width = sprite.width();
    hight = sprite.height();
    setPixmap(sprite);
    this->speed_ratio = 10;
}

Background_middle::Background_middle(pair position): Background(position)
{
    sprite = QPixmap(gtexture->get_path_to(background_middle));
    width = sprite.width();
    hight = sprite.height();
    setPixmap(sprite);
    this->speed_ratio = 8;
}

Background_close::Background_close(pair position): Background(position)
{
    sprite = QPixmap(gtexture->get_path_to(background_close));
    width = sprite.width();
    hight = sprite.height();
    setPixmap(sprite);
    this->speed_ratio = 4;
}
