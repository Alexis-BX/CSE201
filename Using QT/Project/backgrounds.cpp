#include "listheaders.h"

Background_far::Background_far(pair position): Background(position)
{
    setPixmap(QPixmap(gtexture->get_path_to(background_far)));
    this->speed_ratio = 8;
}

Background_middle::Background_middle(pair position): Background(position)
{
    setPixmap(QPixmap(gtexture->get_path_to(background_middle)));
    this->speed_ratio = 4;
}

Background_close::Background_close(pair position): Background(position)
{
    setPixmap(QPixmap(gtexture->get_path_to(background_close)));
    this->speed_ratio = 2;
}
