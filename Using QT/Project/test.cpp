#include "test.h"
#include "listheaders.h"
#include <unistd.h>
#include <stdlib.h>
#include <chrono>
#include <iostream>
#include <QGraphicsItem>
#include <QColor>
#include <QVector>

Test::Test(){}


//block and blocks classes tests


bool Test::Test_Blink() {
    pair position = {double(rand() % 739), double(rand() % 505)};
    Active_block testquestion_mark(position);
    unsigned long long x = testquestion_mark.image_count;
    testquestion_mark.blink();
    if(testquestion_mark.image_count != x){
        return true;
    }
    std::cout << "Blink() is not working :( " << std::endl;
    return false;
}

//test if for a block that has texture question mark blink changes its image_count
/* the idea is that every 0.5 seconds the image count should change;
 * checking this once does not work (due to delays, order of execution, who knows),
 * so I tried checking it 10 times and see if works more than half the times
 * spoiler, still not working - but we can clearly see in the game that the function works
 * will come back to this later */


bool Test::Test_Blink2() {
    pair position = {double(rand() % 739), double(rand() % 505)};
    Active_block anotherquestion_mark(position);
    int res[10];
    int i = 9;
    unsigned long long x = anotherquestion_mark.image_count;
    while(i>=0){
        usleep(520000);
        if(anotherquestion_mark.image_count != x){
            res[i] = 1;
        }
        else{
            res[i] = 0;
        }
        i -= 1;
        x = anotherquestion_mark.image_count;
    }
    int sum = 0;
    for(int j=0; j<10; j++){
        sum += res[j];
    }
    if(sum>5){
        std::cout << "Blink() inside question_mark is working :)" << std::endl;
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


//coin counter tests

bool Test::Test_AddCoin(){
    pair position = {double(rand() % 739), double(rand() % 505)};
    Coin_counter counter(position);
    counter.coins = rand() % 20;
    int x = counter.coins;      //check the initial amount of coins
    int amount = rand() % 10;       //how many coins we add
    counter.add_coin(amount);
    if(counter.coins - x == amount){
        return true;
    }
    std::cout << "Add_coin is not working :(" << std::endl;
    return false;
}

bool Test::Test_UpdateCounter(){                //tests update counter but from the add_coin point of view
    pair position = {double(rand() % 739), double(rand() % 505)};
    Coin_counter counter(position);
    counter.coins = 9;      //i only need counters of length 1 for 9 coins
    counter.counters.push_back(new Counter(1));     //initialize counters of length 1
    counter.add_coin(3);     //for 12 coins, we will need another counter
    if(counter.counters.size() == 2){
        return true;
    }
    std::cout << "Update_counter does not work :(" << std::endl;
    return false;
}

void Test::Test_CoinCount() {
    Test testobj;
    if(testobj.Test_AddCoin() == true && testobj.Test_UpdateCounter() == true){
        std::cout << "Coin_counter class is succesful!" << std::endl;
    }
}

//tool tests

bool Test::Test_CreateColRange(){
    Player* player = new Player();                              //testing on player makes sense
    if(player->collision_ranges.size() == 3){            // collision range list should have size 3
        for(int i = 0; i < 3; i++){
            QColor c(0,0,0);
            c.setAlpha(255); // Maximum transparency
            if(player->collision_ranges[i]->pen().color() != c){           // every element should be invisible
                  std::cout << "Create Collision Range does not work :(" << std::endl;
                  return false;
            }
        }
        std::cout << "Create Collision Range works :)" << std::endl;
        return true;
    }
    std::cout << "Create Collision Range does not work :(" << std::endl;
    return false;
}

/*For updating the collision range, I am just taking different cases into account and checking the position
 * given by the function one by one*/

bool Test::Test_UpdateColRange(){
    int res[4]; //4 tests, res[i] = 1 if test worked, 0 otherwise

    //first case, everything is bigger than 0

    Player* player = new Player();          //testing on player again makes sense
    player->speed.x = 1;
    player->speed.y = 2;
    player->size.x = 3;
    player->size.y = 4;

    update_collision_range(player->collision_ranges, player->size, player->speed);
    if(player->collision_ranges[0]->pos() == QPointF{3, 0} && player->collision_ranges[0]->rect() == QRectF{0, 0, 1, 2}
       && player->collision_ranges[1]->pos() == QPointF{0, 4} && player->collision_ranges[1]->rect() == QRectF{0, 0, 1, 2}
       && player->collision_ranges[2]->pos() == QPointF{3, 4} && player->collision_ranges[2]->rect() == QRectF{0, 0, 1, 2}){
        res[0] = 1;
    }
    else{
        res[0] = 0;
    }

    //second case, speed.x bigger than 0, speed.y is 0
    player->speed.y = 0;
    update_collision_range(player->collision_ranges, player->size, player->speed);
    if(player->collision_ranges[0]->pos() == QPointF{3, 0} && player->collision_ranges[0]->rect() == QRectF{0, 0, 1, 2}
       && player->collision_ranges[1]->pos() == QPointF{0, -1} && player->collision_ranges[1]->rect() == QRectF{0, 0, 1, 0}
       && player->collision_ranges[2]->pos() == QPointF{3, -1} && player->collision_ranges[2]->rect() == QRectF{0, 0, 1, 0}){
        res[1] = 1;
    }
    else{
        res[1] = 0;
    }

    //third case, speed.y bigger than 0, speed.x is 0
    player->speed.x = 0;
    player->speed.y = 2;
    update_collision_range(player->collision_ranges, player->size, player->speed);
    if(player->collision_ranges[0]->pos() == QPointF{-1, 0} && player->collision_ranges[0]->rect() == QRectF{0, 0, 0, 2}
       && player->collision_ranges[1]->pos() == QPointF{0, 4} && player->collision_ranges[1]->rect() == QRectF{0, 0, 1, 2}
       && player->collision_ranges[2]->pos() == QPointF{-1, 4} && player->collision_ranges[2]->rect() == QRectF{0, 0, 0, 2}){
        res[2] = 1;
    }
    else{
        res[2] = 0;
    }

    //last case, speed.x = speed.y = 0
    player->speed.x = 0;
    player->speed.y = 0;
    update_collision_range(player->collision_ranges, player->size, player->speed);
    if(player->collision_ranges[0]->pos() == QPointF{-1, 0} && player->collision_ranges[0]->rect() == QRectF{0, 0, 0, 2}
       && player->collision_ranges[1]->pos() == QPointF{0, -1} && player->collision_ranges[1]->rect() == QRectF{0, 0, 1, 0}
       && player->collision_ranges[2]->pos() == QPointF{-1, -1} && player->collision_ranges[2]->rect() == QRectF{0, 0, 0, 0}){
        res[3] = 1;
    }
    else{
        res[3] = 0;
    }

    //did all the tests work?

    int sum = 0;
    for(int i = 0; i < 4; i++){
        sum += res[i];
    }
    if(sum == 4){
        std::cout << "Update Collision Range works :)" << std::endl;
        return true;
    }
    std::cout << "Update Collision Range does not work :(" << std::endl;
    return false;
}

bool Test::Test_Delay(){   // sometimes it works sometimes it doesnt (due to time delays)
    std::chrono::steady_clock::time_point over = std::chrono::steady_clock::now() + std::chrono::seconds(1); //over =  1 second from now
    delay(1000);           //should delay 1 second
    if(std::chrono::steady_clock::now() < over){
          std::cout << "Delay works :)" << std::endl;
          return true;
    }
    std::cout << "Delay doesn' t work" << std::endl;
    return false;
}

void Test::Test_Tools(){
    Test testobj;
    if(testobj.Test_Delay() == true && testobj.Test_UpdateColRange() == true && testobj.Test_CreateColRange() == true){
        std::cout << "Tools are succesful!" << std::endl;
    }
}
