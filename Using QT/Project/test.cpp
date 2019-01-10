#include "test.h"
#include "listheaders.h"
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <QGraphicsItem>

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
    std::cout << "Blink() is not working :( 1" << std::endl;
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
