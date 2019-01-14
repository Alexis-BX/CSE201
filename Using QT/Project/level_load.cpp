#include "listheaders.h"

Level_load::Level_load(View* view) : view(view)
{
    color_triples.push_back(new Color_triple<Base_block>(0,0,0,view));
    color_triples.push_back(new Color_triple<Enemy_1>(237, 28, 36,view));
    color_triples.push_back(new Color_triple<Special_block_below>(185, 122, 87,view));
    color_triples.push_back(new Color_triple<Special_block_above>(34, 177, 76,view));
    color_triples.push_back(new Color_triple<Small_collectable>(255, 242, 00,view));
    color_triples.push_back(new Color_triple<Active_block>(63, 72, 204,view));
    color_triples.push_back(new Color_triple<Breakable_block_1>(255, 127, 39,view));
    color_triples.push_back(new Color_triple_player(181, 230, 29,view));
    color_triples.push_back(new Color_triple<End_block>(255, 0, 255,view));
    color_triples.push_back(new Color_triple<Tube_block>(163, 73, 164, view));        //random color here
}

void Level_load::load_level(QString filename, QGraphicsScene*scene)
{
    this->scene = scene;

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
    view->backgrounds_far.push_back(new Background_far(pair{0,0}));
    scene->addItem(view->backgrounds_far[0]);

    view->backgrounds_middle.push_back(new Background_middle(pair{0,0}));
    scene->addItem(view->backgrounds_middle[0]);

    view->backgrounds_close.push_back(new Background_close(pair{0,0}));
    scene->addItem(view->backgrounds_close[0]);
}

void Level_load::read_level_image(QString filename)
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

            color_to_object(R,G,B,pair{greal(x*view->block_size),-greal(y*view->block_size)});
        }
    }
}

void Level_load::color_to_object(int R, int G, int B, pair position)
{
    for(unsigned long long i = 0; i < color_triples.size(); i++)
    {
        (*color_triples[i]).test(R,G,B,position, scene);
    }
}
