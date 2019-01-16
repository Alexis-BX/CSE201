#include "listheaders.h"

Menu::Menu(QGraphicsItem* parent) :
    QObject(), QGraphicsPixmapItem (parent)
{
    load_animation();

    selected = op_start;

    setFlag(QGraphicsItem::ItemIsFocusable);

    setFocus();

    //QTimer * timer = new QTimer();

    //QObject::connect(timer,SIGNAL(timeout()),this,SLOT(update()));

    //timer->start(100);
}

void Menu::update()
{
    set_animation_state();
}

void Menu::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Left:
    {
        selected--;
        if (selected<0)
        {
            selected = op_amount-1;
        }
        set_animation_state();
        break;
    }
    case Qt::Key_Right:
    {
        selected++;
        if (selected >= op_amount)
        {
            selected = 0;
        }
        set_animation_state();
        break;
    }
    case Qt::Key_Enter:
    case Qt::Key_Space:
    {
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
        view->play_level(view->current_level);
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
        button_list[i]->setPixmap(buttons[i][selected==i]);
    }
}

void Menu::load_animation()
{
   //new Button(0, -505, QPixmap(":/Images/Menu/accueilsgj.png"), this);

    QPixmap images(":/Images/Levels/buttons.png");

    for (int i=0; i<op_amount; i++)
    {
        buttons[i][0] = images.copy(0,  i*36, 72, 36);
        buttons[i][1] = images.copy(72, i*36, 72, 36);
    }

    for (int i=0; i<op_amount; i++)
    {
        button_list[i] = new Button(170 + 200*i, -70, buttons[i][selected==i], this);
    }
}



















