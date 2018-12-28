#include "listheaders.h"

Start_button::Start_button(pair screen_size)
{
    setPixmap(QPixmap(":/Images/Menu/start_button.png"));

    setPos(screen_size.x/2 - 3*18,-screen_size.y/2 + 1.5*18);
}
