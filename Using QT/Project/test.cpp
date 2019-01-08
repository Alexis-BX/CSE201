#include "test.h"
#include "blocks.h"
#include "tools.h"
#include "coin_counter.h"
#include "collectable.h"
#include "player.h"
#include "view.h"
#include "global.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <QGraphicsItem>

Test::Test(){}


//block and blocks classes tests


bool Test::Test_Blink() {
    pair position = {double(rand() % 739), double(rand() % 505)};
    Active_block testquestion_mark(position);
    int x = testquestion_mark.image_count;
    testquestion_mark.blink();
    if(testquestion_mark.image_count != x){
        return true;
    }
    std::cout << "Blink() is not working :(" << std::endl;
    return false;
}

//test if for a block that has texture question mark blink changes its image_count
bool Test::Test_Blink2() {
    pair position = {double(rand() % 739), double(rand() % 505)};
    Active_block anotherquestion_mark(position);
    int x = anotherquestion_mark.image_count;
    usleep(700000);
    if(anotherquestion_mark.image_count != x){
        return true;
    }
    std::cout << "Blink() inside question_mark is not working :(" << std::endl;
    return false;
}

void Test::Test_Blocks() {
    Test testobj;
    if(testobj.Test_Blink() == true && testobj.Test_Blink2() == true){
        std::cout << "Blocks class is succesful!" << std::endl;
    }
}


//coin_counter tests


/*

bool Test::Test_AddCoin(){
>>>>>>> 75d0c7dfd18410ff74e5422f1ba946f0f9c03c3e
    Coin_counter current_count;
    for(int i = 0; i < 20; i++){
        current_count.add_coin();
    }
    if(current_count.coin_count == 20){
        return true;
    }
    std::cout << "Coin_counter does not work :(" << std::endl;
    return false;
}


//collectable tests


bool Test::Test_ColRight(){
    pair position = {double(rand() % 739), double(rand() % 505)};
    Collectable_type types[4];
    types[0] = coin;
    types[1] = mushroom;
    types[2] = eclair;
    types[3] = star;
    int index = rand() % 3;
    Collectable collectable(position, types[index], Collectable_state{unused}, Collectable_texture{same});
    collectable.setPos(position.x, position.y);
    std::cout << collectable.speed.x << " " << collectable.speed.y << std::endl;
    std::cout << collectable.collision_right() << std::endl;
    if(collectable.speed.x <= 0 || collectable.speed.y != 0){
        if(collectable.collision_right() == false){
            std::cout << "working" << std::endl;
            return true;
        }
        std::cout << "collision_right not working" << std::endl;
        return false;
    }*/
    /*QList<QGraphicsItem *> colliding_items = (collectable.collision_range_collec)->collidingItems();
    for(auto other_object = colliding_items.begin(); other_object != colliding_items.end(); other_object++){
        for(int i = 0; i < collectable.size.y; i++){
            if ((*other_object) -> contains( QPointF(collectable.x() +  (collectable.size.x - 1)  + (collectable.speed.x - 1) - (*other_object)->x(), collectable.y() + i -(*other_object)->y() ))){
                if(collectable.collision_right() == true){
                    std::cout << "working" << std::endl;
                    return true;
                }
                std::cout << "collision_right not working" << std::endl;
                return false;
            }
        }*/

    /*if(!collectable.collision_right()){
        std::cout << "working" << std::endl;
        return true;
    }
    std::cout << "working" << std::endl;
    return false;*/


