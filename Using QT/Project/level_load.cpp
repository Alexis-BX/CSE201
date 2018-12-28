#include "level_load.h"
#include "tools.h"
#include "global.h"
#include "types_states_textures.h"
#include "texture.h"
#include "view.h"
#include "blocks.h"
#include "projectiles.h"
#include <QPixmap>

//clas used to store colors under the form (R,G,B)
class triple{
public:
    int r,g,b;

    triple(int x, int y, int z){
        r = x; g = y; b = z;
    }

    bool operator ==(triple other){
        int diff = 4;
        int R{other.r}, B{other.b}, G{other.g};
        if (abs(R-r)<=diff && abs(G-g)<=diff && abs(B-b)<=diff){
            return true;
        }
        return false;
    }
};

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

    pair position = pair{greal(x*view->block_size),greal(-y*view->block_size)};
    triple color(R,G,B);

    if (color == triple(0, 0, 0))
    {
        view->scene->addItem(new Base_block(position));
    }
    else if (color == triple(255, 255, 255))
    {
        //CREATE nothing at position (i,j)
    }
    else if (color == triple(237, 28, 36))
    {
        //CREATE enemy stating point at position (i,j)
    }
    else if (color == triple(185, 122, 87))
    {
        view->scene->addItem(new Special_block_below(position));
    }
    else if (color == triple(34, 177, 76))
    {
        view->scene->addItem(new Special_block_above(position));
    }
    else if (color == triple(255, 242, 0))
    {
        view->scene->addItem(new Small_collectable(position,0));
    }
    else if (color == triple(63, 72, 204))
    {
        view->scene->addItem(new Active_block(position));
    }
    else if (color == triple(255, 127, 39))
    {
        view->scene->addItem(new Breakable_block(position));
    }
}
