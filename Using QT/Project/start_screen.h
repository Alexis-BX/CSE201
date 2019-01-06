#ifndef START_SCREEN_H
#define START_SCREEN_H
#include "global.h"

enum button
{
    start_button,
    settings_button,
    help_button,
    amount_buttons
};

class start_screen
{
public:
    start_screen();

    int selected{start_button};

    void keyPressEvent(QKeyEvent * event);

    void start();
    void settings();
    void help();
};

#endif // START_SCREEN_H
