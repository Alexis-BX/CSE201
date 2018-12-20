#include "view.h"
#include "player.h"
#include "block.h"
#include "blocks.h"
#include "tools.h"
#include "start_button.h"
#include <QDebug>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <cstddef>
#include <fstream>
#include <QRgb>
#include "coin_counter.h"

View::View(pair screen_size, int block_size, QWidget* parent)
{
    this->block_size = block_size;

    this->screen_size = screen_size;

    //scene set up
    scene = new QGraphicsScene();

    setScene(scene);

    // load and create level
    const char* level = ":/Images/Levels/Level_agathe_001.png";
    readBMP(level);

    //start_screen();

    // Create Player
    create_player();

    //Set the background
    set_background(parent);

}

void View::create_block(pair position, Block_type type, Block_texture texture,Block_state state )
{
    Block* new_block = new Block(position, type, texture, state);

    new_block->setPos(position.x,position.y-36); // the -36 is temporary

    this->scene->addItem(new_block);
}

void View::create_basic_world(int width)
{   //test blocks

    create_block(pair{150,-18});
    create_block(pair{150,-36});
    create_block(pair{150,-54});

    create_block(pair{20,-18});
    create_block(pair{20,-36});
    create_block(pair{20,-54});

    create_block(pair{254,-18});
    create_block(pair{254,-36});
    create_block(pair{254,-54});


    create_block(pair{58,-162});
    create_block(pair{40,-162});
    create_block(pair{76,-162});
    create_block(pair{94,-162});

    create_block(pair{200,-108});
    create_block(pair{218,-108});
    create_block(pair{236,-108});
    create_block(pair{254,-108});
    create_block(pair{272,-108});

    create_block(pair{550,-18});
    create_block(pair{450,-36});
    create_block(pair{350,-54});
    create_block(pair{650,-72});
    create_block(pair{750,-90});
    create_block(pair{750,-108});
    create_block(pair{850,-1});


    for(int x = 0 ; x < width ; x++)
    {
        for(int y = 0 ; y < 2 ; y++)
        {
            create_block(pair{greal(x*block_size),greal(y*block_size)});
        }
        create_block(pair{greal(x*block_size),greal(world_size.top)});
    }
}

void View::create_player(pair position)
{
    player = new Player();

    player->setPos(position.x,position.y);

    player->setFlag(QGraphicsItem::ItemIsFocusable);

    player->setFocus();

    scene->addItem(player);

    centerOn(player);
}

void View::create_example_world(int width) // under construction
{

    const int number_blocks = 15;

    pair block_position[number_blocks];

    Block_type block_type[number_blocks];

    Block_texture block_texture[number_blocks];

    greal xi = 5, yi = 10;

    int number = 5,start = 0;

    for(int i = start; i < number ; i++)
    {
        block_position[i] = pair{xi+i,yi};

        block_type[i] = permanent;

        block_texture[i] = (i%2 == 0) ? crate : question_mark;
    }

    xi = 15; yi = 11;

    start = 5;

    for(int i = start; i < number+ start ; i++)
    {
        block_position[i] = pair{xi+i,yi};

        block_type[i] = permanent;

        block_texture[i] = (i%2 == 0) ? crate : question_mark;
    }

    xi = 25; yi = 9;

    start = 10;

    for(int i = start; i < number+ start ; i++)
    {
        block_position[i] = pair{xi+i,yi};

        block_type[i] = permanent;

        block_texture[i] = (i%2 == 0) ? crate : question_mark;
    }

    for(int i = 0; i < number_blocks; i++)
    {
        create_block(pair{block_position[i].x*block_size, - block_position[i].y*block_size}, block_type[i], block_texture[i]);
    }

    int h = 2;

    bool is_grass = false;

    int change = rand() % 10 + 5;

    int i = 0;

    for(int x = 0 ; x < width ; x++)
    {

        if(i == change)
        {
            change =  rand() % 10 + 5;
            i = 0;
            is_grass = !is_grass;
        }
        else
        {
            i ++;
        }

        if(rand()%100<10)
        {
            h++;
        }
        if(rand()%100<10)
        {
            h--;
        }
        for(int y = -h ; y < 2 ; y++)
        {
            create_block(pair{greal(x*block_size),greal(y*block_size)}, permanent , (is_grass)? grass : brick);
        }
    }
}

void View::readBMP(const char* filename)
{

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(int(screen_size.x),int(screen_size.y));

    QPixmap imgChar(filename);

    QImage level = imgChar.toImage();

    level = level.mirrored(false, true);

    int height = level.height();

    int width = level.width();

    world_size = double_pair{18-height*block_size,0,18,width*block_size};

    setSceneRect(world_size.left,world_size.top,world_size.right-world_size.left,world_size.bottom-world_size.top);

    int R,G,B;

    for(int j = 0 ; j < height; j ++)
    {
        for(int i = 0 ; i < width; i++)
        {
            QRgb pixColor = level.pixel(i,j);

            R = qRed(pixColor);
            G = qGreen(pixColor);
            B = qBlue(pixColor);

            //std::cout << i << "   " << j << "   " << R << "   " << G << "   " << B << "   " << std::endl;
            convert (B,G,R,i,j); // careful colors are not stored in correct order so do swap
        }
    }

    /** OLD VERSION THAT ONLY WORKED ON WINDOWS USE QT TOOLS TO MAKE IT WORK FOR EVERYTHING
        std::ifstream image;

        image.open(filename);

        if(!image.is_open())
        {
            printf("not open");
        }

        int height = 0,width = 0;

        for(int i = 0 ; i < 54 ; i++)
        {
            if(i == 18)
            {
                width = image.get();
            }
            else if(i == 22)
            {
                height = image.get();
            }
            else
            {
                image.get();
            }
        }

        world_size.bottom = 0;
        world_size.left = 0;
        world_size.top = - block_size * height;
        world_size.right = block_size * width;
        //std::cout << width << "  " << height << std::endl;



        Now data should contain the (R, G, B) values of the pixels. The color of pixel (i, j) is stored at
        data[3 * (i * width + j)], data[3 * (i * width + j) + 1] and data[3 * (i * width + j) + 2].




    while(image.good())
    {
        R = image.get();
        G = image.get();
        B = image.get();
        std::cout << R << "   " << G << "   " << B << "   " << std::endl;

    }


    image >> buffer;

    while(image.good())
    {
        std::cout << buffer << std::endl;
        image >> buffer;
    }

    int info[200];
    FILE* f = fopen(filename, "rb");


    for(int i = 0; i < 100; i ++)
    {
        for(int j = 0; j < 100; j++)
        {
            info = std::f

            std::cout << *info << std::endl;
        }
    }


    fread(info, sizeof(unsigned char), 3, f);

    std::ifstream image;
    image.open(filename);

    char* buffer = new char [50];

    if(!image.is_open())
    {
        printf("not open");
    }



    image.seekg (0, image.end);
    int length = image.tellg();
    image.seekg (0, image.beg);
    printf("3");

    printf("4");
    std::cout << "Reading " << length << " characters... ";
    read data as a block:
    image.read (buffer,length);
    printf("5");
    FILE* f = fopen(filename, "rb");
    printf("2");
    unsigned char info[54];
    printf("3");
    fread(info, sizeof(unsigned char), 54, image); // read the 54-byte header
    printf("4");

    extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
    std::cout << width << std::endl;
    std::cout << height << std::endl;

    const std::size_t size = 3 * width * height;
    std::cout << "width" << std::endl;
    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
    std::cout << "width" << std::endl;
    fread(data, sizeof(int), size, f); // read the rest of the data at once
    fclose(f);

    printf("5");


    if (ord==1){
     if ord==1 means you are using a windows
    the swap between every first and third pixel is done because windows stores the
    color values as (B, G, R) triples, not (R, G, B).

    for(i = 0; i < size; i += 3){
            unsigned char tmp = data[i];
            data[i] = data[i+2];
            data[i+2] = tmp;
    }}




    for(int i = 0; i < height; i ++)
    {
        for(int j = 0; j < width; j++)
        {
             int value [3];
             value[0] = data[3 * (i * width + j)];
             value [1]=data[3 * (i * width + j)+1];
             value [2]= data[3 * (i * width + j)+2];
             convert (value[0],value[1], value [2],i,j);  //this function creates ther object at position (i,j)
        }
    }
    printf("3");
        **/

    qDebug() << "before coin_counter creation";

    this->scene->addItem(new Coin_counter());

    qDebug() << "after coin_counter creation";
}

void View::convert(int v0, int v1, int v2, int i, int j)
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

    pair position = pair{greal(i*block_size),greal(-j*block_size)};

    if (v0<=diff && v1<=diff && v2<=diff)
    {
        //CREATE PERMANEMT BLOCK at position (i,j)
        this->scene->addItem(new Base_block(position));
    }
    else if (v0>=255-diff && v1>=255-diff && v2>=255-diff)
    {
        //CREATE nothing at position (i,j)
    }
    else if (36-diff<=v0 && v0<=36+diff  && 28-diff<=v1 && v1<=28+diff && 237-diff<=v2 && v2<=237+diff)
    {
        //CREATE enemy stating point at position (i,j)
    }
    else if (87-diff<=v0 && v0<=87+diff  && 122-diff<=v1 && v1<=122+diff && 185-diff<=v2 && v2<=185+diff)
    {
        //CREATE ground  at position (i,j)
        this->scene->addItem(new Special_block_below(position));
    }
    else if (76-diff<=v0 && v0<=76+diff  && 177-diff<=v1 && v1<=177+diff && 34-diff<=v2 && v2<=34+diff)
    {
        //CREATE grass  at position (i,j)
        this->scene->addItem(new Special_block_above(position));
    }
    else if ( v0<=0+diff  && 242-diff<=v1 && v1<=242+diff && 255-diff<=v2)
    {
        //CREATE coin at position (i,j)
    }
    else if (204-diff<=v0 && v0<=204+diff  && 72-diff<=v1 && v1<=72+diff && 63-diff<=v2 && v2<=63+diff)
    {
        //CREATE ?/active block  at position (i,j)
        this->scene->addItem(new Active_block(position));
    }
    else if (39-diff<=v0 && v0<=39+diff  && 127-diff<=v1 && v1<=127+diff && 255-diff<=v2)
    {
        //CREATE breakable block  at position (i,j)
        this->scene->addItem(new Breakable_block(position));
    }

    /**
    int diff=4;


    if (v0<=diff && v1<=diff && v2<=diff)
    {
        //CREATE PERMANEMT BLOCK at position (i,j)
        Block_type btype = permanent;
        Block_texture btexture = brick;
        Block_state bstate = initial;
        create_block(pair{greal(i*block_size),greal(-18-j*block_size)}, btype, btexture, bstate);
    }
    else if (v0>=255-diff && v1>=255-diff && v2>=255-diff)
    {
        //CREATE nothing at position (i,j)
    }
    else if (36-diff<=v0 && v0<=36+diff  && 28-diff<=v1 && v1<=28+diff && 237-diff<=v2 && v2<=237+diff)
    {
        //CREATE enemy stating point at position (i,j)
    }
    else if (87-diff<=v0 && v0<=87+diff  && 122-diff<=v1 && v1<=122+diff && 185-diff<=v2 && v2<=185+diff)
    {
        //CREATE ground  at position (i,j)
        Block_type btype = permanent;
        Block_texture btexture = dirt;
        Block_state bstate = initial;
        create_block(pair{greal(i*block_size),greal(-18-j*block_size)}, btype, btexture, bstate);
    }
    else if (76-diff<=v0 && v0<=76+diff  && 177-diff<=v1 && v1<=177+diff && 34-diff<=v2 && v2<=34+diff)
    {
        //CREATE grass  at position (i,j)
        this->scene->addItem(new Special_block_above(pair{greal(i*block_size),greal(-18-j*block_size)}));


        Block_type btype = permanent;
        Block_texture btexture = grass;
        Block_state bstate = initial;
        create_block(pair{greal(i*block_size),greal(-18-j*block_size)}, btype, btexture, bstate);
    }
    else if ( v0<=0+diff  && 242-diff<=v1 && v1<=242+diff && 255-diff<=v2)
    {
        //CREATE coin at position (i,j)
        Block_type btype = permanent;
        Block_texture btexture = grass;
        Block_state bstate = initial;
        create_block(pair{greal(i*block_size),greal(-18-j*block_size)}, btype, btexture, bstate);
    }
    else if (204-diff<=v0 && v0<=204+diff  && 72-diff<=v1 && v1<=72+diff && 63-diff<=v2 && v2<=63+diff)
    {
        //CREATE ?/active block  at position (i,j)
        Block_type btype = active;
        Block_texture btexture = question_mark;
        Block_state bstate = operative;
        create_block(pair{greal(i*block_size),greal(-18-j*block_size)}, btype, btexture, bstate);
    }
    else if (39-diff<=v0 && v0<=39+diff  && 127-diff<=v1 && v1<=127+diff && 255-diff<=v2)
    {
        //CREATE breakable block  at position (i,j)
        Block_type btype = breakable;
        Block_texture btexture = crate;
        Block_state bstate = initial;
        create_block(pair{greal(i*block_size),greal(-18-j*block_size)}, btype, btexture, bstate);
    }
    **/
}

void View::start_screen()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(int(screen_size.x),int(screen_size.y));

    readBMP(":/Images/Levels/screen_start.png");

    scene->addItem(new Start_button(screen_size));

}

void View::set_background(QWidget* parent)
{
    QPixmap bkgnd(":/Images/background/Background.png");

    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);


    QPalette palette;

    palette.setBrush(QPalette::Background, bkgnd);

    this->setPalette(palette);



    setBackgroundBrush(bkgnd);
}


