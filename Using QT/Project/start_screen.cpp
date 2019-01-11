#include "start_screen.h"
#include "listheaders.h"


start_screen::start_screen()
{
    //create bg
    //create buttons
}

void start_screen::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Down:
    {
        selected++;
        if (selected == amount_buttons)
        {
            selected = 0;
        }
        break;
    }
    case Qt::Key_Up:
    {
        selected--;
        if (selected == -1)
        {
            selected = amount_buttons-1;
        }
        break;
    }
    case Qt::Key_Enter:
    {
        switch(selected){
        case start_button:
            start();
            break;
        case settings_button:
            settings();
            break;
        case help_button:
            help();
            break;
        }
        break;
    }
    }
}

void start_screen::start()
{

}

void start_screen::settings()
{

}

void start_screen::help()
{

}
