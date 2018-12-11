#include "collectable.h"
#include "player.h"
#include "view.h"


Collectable::Collectable(pair position, pair size, Collectable_type type, Collectable_state state, Collectable_texture texture, QGraphicsItem* parent):  // constructor: gives default aspects of the collectable
      QObject (), QGraphicsPixmapItem (parent)
{
    setPos(position.x, position.y);

    this -> type = type;                        // gives the type of the collectable

    this -> state = state;                      // gives the state of the collectable

    this -> texture = texture;                  // gives the texture of the collectable

    this -> size = size;

    setPixmap(QPixmap(":/images/pixmaps/Collectables.png"));
}
