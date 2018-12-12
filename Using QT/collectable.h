#ifndef COLLECTABLE_H
#define COLLECTABLE_H 

#include <QGraphicsPixmapItem>
#include <QObject>
#include "tools.h"
#include "types_states_textures.h"

class View;

extern View* view;

class Collectable : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:

    Collectable_type type;             // shows the kind of collectable the player meets

    Collectable_state state;           // shows if the collectable is used or unused

    Collectable_texture texture;       // the player meets the same or different collectable

public:

    pair size;

    Collectable(pair position, pair size, Collectable_type type, Collectable_state state,
                Collectable_texture texture, QGraphicsItem* parent = 0 );

};

#endif // COLLECTABLE_H
