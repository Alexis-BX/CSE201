#include "object.h"


//lien openclassroom pour inclusion classe (heritage):
// https://openclassrooms.com/fr/courses/1894236-programmez-avec-le-langage-c/1898475-lheritage


Object::Object(pair position, pair size, State state, QGraphicsItem* parent): QObject(), QGraphicsRectItem(parent)
{

    this->position = position;

    this->size = size;

    this->state = state;

}

void Object::next_frame(pair &screen_top_left)
{
    setPos(position.x - screen_top_left.x,screen_top_left.y - position.y);
}

