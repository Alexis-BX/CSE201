#include <iostream>

/**
bool collide (Object object1,Object object2 ){

    //each object is treated as a rectangle

    pair position1 = object1.position;
    int x1= position1.x;
    int y1 = position1.y;

    pair position2 = object2.position;
    int x2= position2.x;
    int y2 = position2.y;

    pair size1 = object1.size;
    int w1= size1.x;
    int h1 = size1.y;

    pair size2 = object2.size;
    int w2= size2.x;
    int h2 = size2.y;

    // now look for the collisions!
    // first since the window will have a longer width then height check the x coordinates before the y
    // do not use and user multiple if loops for optimization

    if (x2 < w1+ x1){
        if (x1 < w2+ x2){
            if (y2 < h1 + y1){
                if (y1 < h2+ y2){
                    return true ;       // there is collision
                }
            }
        }
    }
    return false; // there is no collision
}


int main(){
    // NEED TO GET THE OBJECTS FORM SOMEWHERE!
    // at least one active object

    bool answer= collide (object1, object2);
    return 0;
}
**/
    

