#include "listheaders.h"

Menu::Menu(QGraphicsItem* parent) :
    QObject(), QGraphicsPixmapItem (parent)
{
    view->setScene(view->scene_menu);

    load_animation();

    selected = op_start;

    QTimer * timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(update()));

    timer->start(500);
}

void Menu::update()
{
    set_animation_state();
    std::cout<<"updated"<<std::endl;
}

void Menu::keyPressEvent(QKeyEvent *event)
{
    std::cout<<"u"<<std::endl;
    switch (event->key())
    {
    case Qt::Key_Up:
    {
        selected--;
        if (selected<0)
        {
            selected = op_amount-1;
        }
        std::cout<<"u"<<std::endl;
        break;
    }
    case Qt::Key_Down:
    {
        selected++;
        if (selected >= op_amount)
        {
            selected = 0;
        }
        std::cout<<"d"<<std::endl;
        break;
    }
    case Qt::Key_Enter:
    case Qt::Key_Space:
    {
        std::cout<<"e"<<std::endl;
        launch();
        break;
    }
    }
}

void Menu::launch()
{
    switch (selected) {
    case op_start:
    {
        view->start_game();
        view->level_load->load_level(":/Images/Levels/Level_clara_002.png", view->scene);
        break;
    }
    case op_keys:
    {
        //key options
        break;
    }
    case op_help:
    {
        //display help, game info...
        break;
    }
    }
}

void Menu::set_animation_state()
{
    for (int i=0; i<op_amount; i++)
    {
        view->scene_menu->addItem(new Button(view->screen_size.x/2-36, -300+40*i, buttons[i][selected==i]));
    }
}

void Menu::load_animation()
{
    Level_load *level_load = new Level_load(view);
    level_load->load_level(":/Images/Levels/start_screen.png", view->scene_menu);

    QPixmap images(":/Images/Levels/buttons.png");

    for (int i=0; i<op_amount; i++)
    {
        buttons[i][0] = images.copy(0,  i*36, 72, 36);
        buttons[i][1] = images.copy(72, i*36, 72, 36);
    }
}



















