#include "listheaders.h"

Level_load::Level_load(View* view) : view(view)
{
    color_triples.push_back(new Color_triple<Base_block>(0,0,0,view));
    color_triples.push_back(new Color_triple<Enemy_1>(237, 28, 36,view));
    color_triples.push_back(new Color_triple<Special_block_below>(185, 122, 87,view));
    color_triples.push_back(new Color_triple<Special_block_above>(34, 177, 76,view));
    color_triples.push_back(new Color_triple<Small_collectable>(255, 242, 00,view));
    color_triples.push_back(new Color_triple<Active_block>(63, 72, 204,view));
    color_triples.push_back(new Color_triple<Breakable_block>(255, 127, 39,view));
    color_triples.push_back(new Color_triple_player(181, 230, 29,view));
}

void Level_load::load_level(const char *filename)
{
    setup_view();

    setup_background();

    read_level_image(filename);
}

void Level_load::setup_view()
{
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setFixedSize(int(view->screen_size.x),int(view->screen_size.y));
}

void Level_load::setup_background()
{
    //Set the background layers (paralax background)
    view->backgrounds.push_back(new Background_far(pair{0,-view->screen_size.y}));
    view->backgrounds.push_back(new Background_middle(pair{0,qreal(-450)}));
    view->backgrounds.push_back(new Background_close(pair{0,qreal(-300)}));

    for(unsigned long long i = 0 ; i < view->backgrounds.size(); i++)
    {
        view->scene()->addItem(view->backgrounds[i]);
    }
}

void Level_load::read_level_image(const char* filename)
{
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

            color_to_object(B,G,R,pair{greal(x*view->block_size),-greal(y*view->block_size)});
        }
    }
}

void Level_load::color_to_object(int B, int G, int R, pair position)
{
    for(unsigned long long i = 0; i < color_triples.size(); i++)
    {
        (*color_triples[i]).test(R,G,B,position);
    }

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
    /**
    triple color(R,G,B);

    if (color == triple(0, 0, 0))
    {
        view->scene()->addItem(new Base_block(position));
    }
    else if (color == triple(255, 255, 255))
    {
        //CREATE nothing at position (i,j)
    }
    else if (color == triple(237, 28, 36))
    {
        //CREATE enemy stating point at position (i,j)
        view->scene()->addItem(new Enemy_1(position));
    }
    else if (color == triple(185, 122, 87))
    {
        view->scene()->addItem(new Special_block_below(position));
    }
    else if (color == triple(34, 177, 76))
    {
        view->scene()->addItem(new Special_block_above(position));
    }
    else if (color == triple(255, 242, 0))
    {
        view->scene()->addItem(new Small_collectable(position));
    }
    else if (color == triple(63, 72, 204))
    {
        view->scene()->addItem(new Active_block(position));
    }
    else if (color == triple(255, 127, 39))
    {
        view->scene()->addItem(new Breakable_block(position));
    }
    **/
}
