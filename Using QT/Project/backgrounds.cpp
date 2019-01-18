#include "listheaders.h"

Background_far::Background_far(pair position): Background(position)
{
    sprite = QPixmap(gtexture->get_path_to(background_far));
    width = sprite.width();
    height = sprite.height();
    setPos(position.x,position.y-height+72);
    this->setZValue(layer_background_far);
    setPixmap(sprite);
    this->speed_ratio = 10;
}

Background_middle::Background_middle(pair position): Background(position)
{
    sprite = QPixmap(gtexture->get_path_to(background_middle));
    width = sprite.width()*5;
    height = sprite.height();
    setPos(position.x,position.y-height-50);
    this->setZValue(layer_background_middle);
    setPixmap(sprite);
    this->speed_ratio = 8;
}

Background_close::Background_close(pair position): Background(position)
{
    sprite = QPixmap(gtexture->get_path_to(background_close));
    width = sprite.width()*2;
    height = sprite.height();
    setPos(position.x,position.y-height-30);
    this->setZValue(layer_background_close);
    setPixmap(sprite);
    this->speed_ratio = 4;
}
