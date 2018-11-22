#include "object.h"


//lien openclassroom pour inclusion classe (heritage):
// https://openclassrooms.com/fr/courses/1894236-programmez-avec-le-langage-c/1898475-lheritage


Object::Object(pair position, pair size, State state)
{
    this-> position = position;
    this->size = size;
    this->state = state;

}
