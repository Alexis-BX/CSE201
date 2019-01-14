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

//enemy class tests

bool Test::Test_Jump(){
    pair position = {double(rand() % 739), double(rand() % 505)};
    Enemy_1* enemy = new Enemy_1(position);

    int res[2]; //two cases, as before res[i] = 1 means succes 0 otherwise

    //case I, the enemy jumped the maximum amount already
    enemy->max_consecutive_jumps = 2;
    enemy->times_jumped = 2;
    int x = enemy->times_jumped;
    enemy->jump();
    if(x == enemy->times_jumped){
        res[0] = 1;
    }
    else{
        res[0] = 0;
    }

    //case II, the enemy can still jump
    enemy->times_jumped = 1;
    enemy->jump();
    if(int(enemy->times_jumped) == 2 && int(enemy->speed.y) == -int(enemy->speedMax.y)){
        res[1] = 1;
    }
    else{
        res[1] = 0;
    }

    int sum = 0;
    for(int i = 0; i < 2; i++){
        sum += res[i];
    }
    if(sum == 2){
        std::cout << "Jump works :)" << std::endl;
        return true;
    }
    std::cout << "Jump does not work :(" << std::endl;
    return false;
}

//tests the first part of the move() function

bool Test::Test_Move_First(){
    Player* player = new Player();
    player->pos() = {double(rand() % 739), double(rand() % 505)};   //player at a random place
    pair position = {double(rand() % 739), double(rand() % 505)};
    Enemy_1* enemy = new Enemy_1(position);                             //enemy at a random place
    double dist = distance(pair{player->x(),player->y()},pair{enemy->x(),enemy->y()});    //the distance between the random places

    //Case I: State is passive
    enemy->move();
    if(dist < 30000){
         if(enemy->state != aggressiv){
              return false;
         }
    }
    else{               //enemy is still passiv
        if(enemy->facing == Right){
            if(int(enemy->speed.x) != int(enemy->speedMax.x)){
                return false;
            }
        }
        else{
            if(int(enemy->speed.x) != -int(enemy->speedMax.x)){
                return false;
            }
        }
    }


    //Case II: state is aggressiv and motion smooth
    pair position2 = {double(rand() % 739), double(rand() % 505)};
    Enemy_1* enemy2 = new Enemy_1(position2);                             //new enemy that did not move
    double dist2 = distance(pair{player->x(),player->y()},pair{enemy2->x(),enemy2->y()});  //the distance between new enemy and player
    enemy2->state = aggressiv;
    int x = (player->x() >= enemy2->x()) ? 0 : -1; //if player.x >= enemy2.x, x = 0; else, x = -1
    int y = (enemy->speed.y > enemy->speedMax.y) ? 0 : -1; //y=0 if (...) true and -1 otherwise
    enemy2->move();
    if(y == 0){
        if(int(enemy2->speed.y) == int(enemy2->speedMax.y)){
            if(dist2 > 60000){
                if(enemy2->state != passiv){
                    return false;
                }
            }
            else{
                if(x == 0){
                    if(int(enemy2->speed.x) != int(enemy2->speedMax.x)){
                        return false;
                    }
                }
                else{
                    if(int(enemy2->speed.x) != -int(enemy2->speedMax.x)){
                        return false;
                    }
                }
            }
        }
        else{return false;}
    }
    else{
        if(int(enemy2->speed.y) < -int(enemy2->speedMax.y)){   //y not 0 could also mean speed.y = 0 which we don't want
            if(int(enemy2->speed.y) != -int(enemy2->speedMax.y)){
                return false;
            }
        }
    }
    return true;
}

//tests the bounderies part of the move function

bool Test::Test_Move_Second(){
    pair position = {double(rand() % 739), double(rand() % 505)};
    Enemy_1* enemy = new Enemy_1(position);     //enemy 1 is a good test for enemy

    //I apologise for how confusing this is about to get

    bool a = (enemy->y() >= view->world_size.bottom);
    bool b = (enemy->y() <= view->world_size.top);
    bool c = (enemy->x() >= view->world_size.right);
    bool d = (enemy->x() <= view->world_size.left);

    enemy->move();

    bool a1 = (enemy->speed.y < 0);
    bool b1 = (enemy->speed.y > 0);
    bool c1 = (enemy->speed.x < 0);
    bool d1 = (enemy->speed.x > 0);


    //first case
    if(a){
        if(!a1){
            if(int(enemy->speed.y) == 0){
                if(int(enemy->y()) != view->world_size.bottom){
                    std::cout << "1" << std::endl;
                    return false;
                }
            }
            else{std::cout << "2" << std::endl;return false;}
        }
    }

    //second case
    if(b){
        if(!b1){
            if(int(enemy->speed.y) == 0){
                if(int(enemy->y()) != view->world_size.top){
                    std::cout << "3" << std::endl;
                    return false;
                }
            }
            else{std::cout << "4" << std::endl;return false;}
        }
    }

    //third case
    if(c){
        if(!c1){
            if(int(enemy->speed.x) == 0){
                if(int(enemy->x()) != view->world_size.right){
                    std::cout << "5" << std::endl;
                    return false;
                }
            }
            else{std::cout << "6" << std::endl;return false;}
        }
    }

    //last case
    if(d){
        if(!d1){
            if(int(enemy->speed.x) == 0){
                if(int(enemy->x()) != view->world_size.left){
                    std::cout << "7" << std::endl;
                    return false;
                }
            }
            else{std::cout << "8" << std::endl;return false;}
        }
    }
    return true;
}

//test for the movements, jump, direction

bool Test::Test_Move_Third(){
    pair position = {double(rand() % 739), double(rand() % 505)};
    Enemy_1* enemy = new Enemy_1(position);
    double x = enemy->facing;
    enemy->move();

    //case passiv
    if(enemy->collision[0]){
        if(int(enemy->speed.x) != 0 || enemy->facing == x){
            return false;
        }
    }
    if(enemy->collision[1]){
        if(int(enemy->speed.y) != 0){
            return false;
        }
    }
    if(!enemy->collision[0] && !enemy->collision[1] && enemy->collision[2]){
        if(int(enemy->speed.y) != 0){
            return false;
        }
    }

    //jump reset
    if(enemy->collision[1] && enemy->speed.y >= 0){
        if(int(enemy->times_jumped) != 0){
            return false;
        }
    }

    //direction of player
    if(enemy->speed.x > 0){
        if(enemy->facing != Right){
            return false;
        }
    }
    else if (enemy->speed.x < 0){
        if(enemy->facing != Left){
            return false;
        }
    }

    //case aggressiv
    pair position2 = {double(rand() % 739), double(rand() % 505)};
    Enemy_1* enemy2 = new Enemy_1(position2);

    int y = enemy2->times_jumped;
    enemy2->move();

    if(enemy2->collision[0]){
        if(int(enemy2->speed.x) != 0 || enemy2->times_jumped == y){
            return false;
        }
    }
    if(enemy2->collision[1]){
        if(int(enemy2->speed.y) != 0){
            return false;
        }
    }
    if(!enemy2->collision[0] && !enemy2->collision[1] && enemy2->collision[2]){
        if(int(enemy2->speed.y) != 0){
            return false;
        }
    }
    return true;
}

bool Test::Test_Move(){
    Test test;
    if(test.Test_Move_First() && test.Test_Move_Second() && test.Test_Move_Third()){
        std::cout << "All move work :)" << std::endl;
        return true;
    }
    return false;
}

bool Test::Test_TimerConnect(){
    pair position = {double(rand() % 739), double(rand() % 505)};
    Enemy_1* enemy = new Enemy_1(position);
    Player* player = new Player;
    player->setPos({enemy->x() + 50, enemy->y() + 50}); // player really close to enemy
    int x  = enemy->projectile_count;  //equal to projectile count
    enemy->timer_connect();
    std::cout << x << std::endl;
    std::cout << enemy->projectile_count << std::endl;
    if(x != 99 && enemy->projectile_count - x == 1){
        std::cout << "now it works" << std::endl;
        return true;
    }
    if(x == 99 && enemy->projectile_count == 0){
        std::cout << "now it works" << std::endl;
        return true;
    }
    std::cout << "timer connect not working" << std::endl;
    return false;
}
