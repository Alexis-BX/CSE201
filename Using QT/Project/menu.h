#ifndef MENU_H
#define MENU_H
#include "global.h"

enum Options
{
    op_start, op_keys, op_help, op_amount
};

class Menu : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Menu(QGraphicsItem* parent = nullptr);

    int selected;

    QPixmap buttons[op_amount][2];

    QTimer* timer;

    // Methods
    void keyPressEvent(QKeyEvent * event);

    void load_animation();

    void set_animation_state();

    void launch();

public slots:

    // Slot for timer
    void update();
};

#endif // MENU_H
