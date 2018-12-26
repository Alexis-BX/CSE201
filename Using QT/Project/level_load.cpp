#include "level_load.h"
#include "tools.h"
#include "global.h"
#include "types_states_textures.h"
#include "texture.h"
#include "view.h"
#include "blocks.h"
#include "projectiles.h"
#include <QPixmap>

Level_load::Level_load(View* view)
{
    this->view = view;
}

void Level_load::read_level_image(const char *filename)
{
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setFixedSize(int(view->screen_size.x),int(view->screen_size.y));

    QPixmap imgChar(filename);

    QImage level = imgChar.toImage().mirrored(false, true);

    int height = level.height(), width = level.width();

    view->world_size = double_pair{18-height*view->block_size,
                                    0,
                                    18,
                                    width*view->block_size};

    view->setSceneRect(view->world_size.left,
                       view->world_size.top,
                       view->world_size.right-view->world_size.left,
                       view->world_size.bottom-view->world_size.top);

    int R,G,B;
    QRgb pixColor;

    for(int x = 0 ; x < width; x ++)
    {
        for(int y = 0 ; y < height; y ++)
        {
            pixColor = level.pixel(x,y);

            B = qBlue(pixColor);
            G = qGreen(pixColor);
            R = qRed(pixColor);

            color_to_object(B,G,R,x,y);
        }
    }
}

void Level_load::color_to_object(int B, int G, int R, int x, int y)
{

    /*** we have the following legend take these values +/- a difference chosen so that we can dram with not exactly the same red or blue and it not be a promblem
     * black --> brick --> 0,0,0
     * red --> starting place enemy --> 36, 28 ,237
     * orange --> breakable blocks --> 39, 127, 255
     * dark blue --> ?/active blocks --> 204, 72, 63
     * yellow --> coins --> 0,242,255
     * white  --> nothing  --> 255, 255, 255
     * green --> grass --> 76,177,34
     * brown --> ground --> 87 122 185
    ***/

    int diff=4;
    pair position = pair{greal(x*view->block_size),greal(-y*view->block_size)};


    if (B<=diff && G<=diff && R<=diff)
    {
        view->scene->addItem(new Base_block(position));
    }
    else if (B>=255-diff && G>=255-diff && R>=255-diff)
    {
        //CREATE nothing at position (i,j)
    }
    else if (36-diff<=B && B<=36+diff  && 28-diff<=G && G<=28+diff && 237-diff<=R && R<=237+diff)
    {
        //CREATE enemy stating point at position (i,j)
    }
    else if (87-diff<=B && B<=87+diff  && 122-diff<=G && G<=122+diff && 185-diff<=R && R<=185+diff)
    {
        view->scene->addItem(new Special_block_below(position));
    }
    else if (76-diff<=B && B<=76+diff  && 177-diff<=G && G<=177+diff && 34-diff<=R && R<=34+diff)
    {
        view->scene->addItem(new Special_block_above(position));
    }
    else if ( B<=0+diff  && 242-diff<=G && G<=242+diff && 255-diff<=R)
    {
        //CREATE coin at position (i,j)
        view->scene->addItem(new Small_collectable(position,0));
    }
    else if (204-diff<=B && B<=204+diff  && 72-diff<=G && G<=72+diff && 63-diff<=R && R<=63+diff)
    {
        view->scene->addItem(new Active_block(position));
    }
    else if (39-diff<=B && B<=39+diff  && 127-diff<=G && G<=127+diff && 255-diff<=R)
    {
        view->scene->addItem(new Breakable_block(position));
    }
}
