#include "object.h"

using namespace std;

//lien openclassroom pour inclusion classe (heritage):
// https://openclassrooms.com/fr/courses/1894236-programmez-avec-le-langage-c/1898475-lheritage


<<<<<<< HEAD:object.cpp
Object::Object(pr position, pr size)
{
    this-> position=position;
    this->size=size;
}

double *Object::get_collision_box()
{

}
=======
Object::Object(std::pair<int,int> position, std::pair<int,int> size)
{
    this->position = position;
    this->size = size;
}




>>>>>>> 208f95c90dfead9bb959e9ca20e887526da05685:Engine/object.cpp
