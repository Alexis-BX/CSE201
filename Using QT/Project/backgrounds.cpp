#include "backgrounds.h"
#include "global.h"
#include "texture.h"

sky::sky(pair pos): background(pos)
{
    //sprite = QPixmap(gtexture->get_path_to(Tsky));
    sprite = QPixmap(":Images/background/bg.png");
    width = sprite.width();
    setPixmap(sprite);

    this->speed_ratio = 8;
}

monument::monument(pair pos): background(pos)
{
    //sprite = QPixmap(gtexture->get_path_to(Tmonument));
    sprite = QPixmap(":/Images/background/eiffel.png");
    width = sprite.width();
    setPixmap(sprite);

    this->speed_ratio = 4;
}

buildings::buildings(pair pos): background(pos)
{
    //sprite = QPixmap(gtexture->get_path_to(Tbuildings));
    sprite = QPixmap(":/Images/background/buildings.png");
    width = sprite.width();
    setPixmap(sprite);

    this->speed_ratio = 2;
}
