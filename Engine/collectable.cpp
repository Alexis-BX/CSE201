#include "collectable.h"


Collectable::Collectable(pair position, pair size, Collectable_state state, Collectable_type type, Collectable_texture texture):  // constructor: gives default aspects of the collectable 
      Dead(position, size)                    // inherits the position and the size from the Dead class
{
	this->state = state;                      // gives the state of the collectable

	this->type = type;                        // gives the type of the collectable

	this->texture = texture;                  // gives the texture of the collectable

}

void Collectable::Set_State(Collectable_state state)
{
	this->state = state;
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

/**
void Collectibles::Coll_state(enum st)
{
	state = st;
	if (state == "Unused")
	{
		state = "Used";
	}
}

bool Collectibles::Pass_by(enum st)
{
	if (Coll_state(st) == "Used")
	{
		return true;
	}
	else
	{
		return false;
	}
>>>>>>> a9ac4fb338b8d1131064a9c93d7b190498c2e9d3
}
**/
