#ifndef COLLECTABLE_H
#define COLLECTABLE_H 
#include "global.h"

class Collectable : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:


    QList<QGraphicsRectItem*> collision_ranges;

    QList<bool> collision;

    Collectable_type type;             // shows the kind of collectable the player meets

    Collectable_state state;           // shows if the collectable is used or unused

    Collectable_texture texture;       // the player meets the same or different collectable

    std::vector<QPixmap> sprite;

    Collectable(pair position, int creator_object_size_y, QGraphicsItem* parent = nullptr );

    // Attributes
    pair size, position, speed;
    int life; //some collectables have life even though they are not eaten (ex mushroom)

    Direction facing{Right};

    void set_movement();

    QTimer* move_timer = nullptr;

    virtual int get_power_number();

    ~Collectable();

    int get_power_number();

public slots:

    void move(); //next position of the collectable depending on their way of moving
};

#endif // COLLECTABLE_H
