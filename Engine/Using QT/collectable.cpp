#include "collectable.h"
#include "player.h"
#include "view.h"


Collectable::Collectable(pair position, pair size, Collectable_type type, Collectable_state state, Collectable_texture texture, QGraphicsItem* parent):  // constructor: gives default aspects of the collectable
      QObject (), QGraphicsPixmapItem (parent)
{
    setPos(position.x, position.y);
    this -> type = type;
    this -> state = state;                      // gives the state of the collectable                        // gives the type of the collectable
    this -> texture = texture;                  // gives the texture of the collectable
    this -> size = size;

    setPixmap(QPixmap(":/images/Collectables.png"));
}

void Collectable::Set_State(Collectable_state state)
{
    this -> state = state;
}

Collectable_state Collectable::Get_State() const
{
	return state;
}

void Collectable::Set_Type(Collectable_type type)
{
	this->type = type;
}

Collectable_type Collectable::Get_Type() const
{
	return type;
}

void Collectable::Set_Texture(Collectable_texture texture)
{
	this->texture = texture;
}

Collectable_texture Collectable::Get_Texture() const
{
	return texture;
}

