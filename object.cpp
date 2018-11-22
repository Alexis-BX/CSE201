#include "object.h"

using namespace std;

//lien openclassroom pour inclusion classe (heritage):
// https://openclassrooms.com/fr/courses/1894236-programmez-avec-le-langage-c/1898475-lheritage


Object::Object(pr position, pr size)
{
    this-> position=position;
    this->size=size;
}

double *Object::get_collision_box()
{

}
