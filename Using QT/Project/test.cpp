#include "test.h"
#include "listheaders.h"
#include <unistd.h>
#include <stdlib.h>
#include <chrono>
#include <iostream>
#include <QGraphicsItem>
#include <QColor>
#include <QVector>
#include <typeinfo>

Test::Test(){}


//block and blocks classes tests


bool Test::Test_Blink() {
    pair position = {double(rand() % 739), double(rand() % 505)};
    Active_block testquestion_mark(position);
    unsigned long long x = testquestion_mark.image_count;
    testquestion_mark.blink();
    if(testquestion_mark.image_count != x){
        std::cout << "Blink() is working" << std::endl;
        return true;
    }
    std::cout << "Blink() is not working" << std::endl;
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
        std::cout << "Blink() inside question_mark is working" << std::endl;
        return true;
    }
    std::cout << "Blink() inside question_mark is not working" << std::endl;
    return false;
}

bool Test::Test_Blocks() {
    Test testobj;
    if(testobj.Test_Blink() == true && testobj.Test_Blink2() == true){
        return true;
    }
    return false;
}


//coin counter tests

bool Test::Test_AddCoin(){
    pair position = {double(rand() % 739), double(rand() % 505)};
    Coin_counter counter(QPoint(position.x,position.y));
    counter.coins = rand() % 20;
    int x = counter.coins;      //check the initial amount of coins
    int amount = rand() % 10;       //how many coins we add
    counter.add_coin(amount);
    if(counter.coins - x == amount){
        std::cout << "Add_coin() is working" << std::endl;
        return true;
    }
    std::cout << "Add_coin is not working" << std::endl;
    return false;
}

bool Test::Test_UpdateCounter(){                //tests update counter but from the add_coin point of view
    pair position = {double(rand() % 739), double(rand() % 505)};
    Coin_counter counter(QPoint(position.x,position.y));
    counter.coins = 9;      //i only need counters of length 1 for 9 coins
    counter.counters.push_back(new Counter(1));     //initialize counters of length 1
    counter.add_coin(3);     //for 12 coins, we will need another counter
    if(counter.counters.size() == 2){
        std::cout << "Update_counter() is working" << std::endl;
        return true;
    }
    std::cout << "Update_counter() is not working" << std::endl;
    return false;
}

bool Test::Test_CoinCount() {
    Test testobj;
    if(testobj.Test_AddCoin() == true && testobj.Test_UpdateCounter() == true){
        std::cout << "Coin_count() is working" << std::endl;
        return true;
    }
    std::cout << "Coin_Count() is not working" << std::endl;
    return false;
}

//tool tests

bool Test::Test_CreateColRange(){
    Player* player = new Player();                              //testing on player makes sense
    if(player->collision_ranges.size() == 3){            // collision range list should have size 3
        for(int i = 0; i < 3; i++){
            QColor c(0,0,0);
            c.setAlpha(255); // Maximum transparency
            if(player->collision_ranges[i]->pen().color() != c){           // every element should be invisible
                  std::cout << "Create Collision Range does not work" << std::endl;
                  return false;
            }
        }
        std::cout << "Create Collision Range works" << std::endl;
        return true;
    }
    std::cout << "Create Collision Range does not work" << std::endl;
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

bool Test::Test_Tools(){
    Test testobj;
    if(testobj.Test_Delay() == true && testobj.Test_UpdateColRange() == true && testobj.Test_CreateColRange() == true){
        std::cout << "Test_Tools() is working" << std::endl;
        return true;
    }
    std::cout << "Test_Tools() is not working" << std::endl;
    return false;
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
        std::cout << "Jump() is working" << std::endl;
        return true;
    }
    std::cout << "Jump() is not working" << std::endl;
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
    bool x = (player->x() >= enemy2->x());
    bool y = (enemy->speed.y > enemy->speedMax.y);
    enemy2->move();
    if(y){
        if(int(enemy2->speed.y) == int(enemy2->speedMax.y)){
            if(dist2 > 60000){
                if(enemy2->state != passiv){
                    return false;
                }
            }
            else{
                if(x){
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
        if(int(enemy2->speed.y) < -int(enemy2->speedMax.y)){   //y not true could also mean speed.y = 0 which we don't want
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
                    return false;
                }
            }
            else{return false;}
        }
    }

    //second case
    if(b){
        if(!b1){
            if(int(enemy->speed.y) == 0){
                if(int(enemy->y()) != view->world_size.top){
                    return false;
                }
            }
            else{return false;}
        }
    }

    //third case
    if(c){
        if(!c1){
            if(int(enemy->speed.x) == 0){
                if(int(enemy->x()) != view->world_size.right){
                    return false;
                }
            }
            else{return false;}
        }
    }

    //last case
    if(d){
        if(!d1){
            if(int(enemy->speed.x) == 0){
                if(int(enemy->x()) != view->world_size.left){
                    return false;
                }
            }
            else{return false;}
        }
    }
    return true;
}

//test for the movements, jump, direction

bool Test::Test_Move_Third(){
    pair position = {double(rand() % 739), double(rand() % 505)};
    Enemy_1* enemy = new Enemy_1(position);
    char x = enemy->facing;
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
        std::cout << "Move() is working" << std::endl;
        return true;
    }
    std::cout << "Move() is not working" << std::endl;
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
        std::cout << "timer_connect works" << std::endl;
        return true;
    }
    if(x == 99 && enemy->projectile_count == 0){
        std::cout << "timer_connect works" << std::endl;
        return true;
    }
    std::cout << "timer connect not working" << std::endl;
    return false;
}

bool Test::Test_Enemy(){
    Test test;
    if(test.Test_Jump() && test.Test_Move()){
        std::cout << "Enemy is working" << std::endl;
        return true;
    }
    std::cout << "Enemy is not working" << std::endl;
    return false;
}

//tests for super_powers

bool Test::Test_UpdateCounter_SP(){
    Super_powers sp;
    int i_list[supers_count];               //i_list = sp.supers_i initially
    for(int j = 0; j < supers_count; j++){
       i_list[j] = sp.supers_i[j];
    }
    sp.supers_b[1] = true;  //make sure we at least have one that is true
    sp.update_counters();
    for(int i = 0; i < supers_count; i++){
        if(sp.supers_b[i]){
            if(sp.supers_i[i] != i_list[i] + 1 || sp.supers_i[i] != sp.supers_i[i] % sp.max_count){
                std::cout << "Update_counter for SP is not working" << std::endl;
                return false;
            }
        }
    }
    std::cout << "Update_counter for SP is working" << std::endl;
    return true;
}

bool Test::Test_PowerUp(){
    Super_powers sp;
    int i = rand() % 2;
    sp.power_up(i);
    if(!sp.supers_b[i] || sp.supers_i[i] != 0){
        std::cout << "Power Up is not working" << std::endl;
        return false;
    }
    std::cout << "Power Up is working" << std::endl;
    return true;
}

bool Test::Test_Speed_ThrowSpeed(){
    Super_powers sp;
    sp.supers_b[1] = true; //super_fast is true
    if(int(sp.get_speed()) != 2 || int(sp.get_throw_speed()) != 1){
        std::cout << "Speed and throw speed are not working" << std::endl;
        return false;
    }
    sp.supers_b[2] = true;
    sp.supers_b[1] = false;
    if(int(sp.get_speed()) != 1 || int(sp.get_throw_speed()) != 2){
        std::cout << "Speed and throw speed are not working" << std::endl;
        return false;
    }
    std::cout << "Speed and throw speed are working" << std::endl;
    return true;
}

bool Test::Test_SuperPow(){
    Test test;
    if(test.Test_UpdateCounter_SP() && test.Test_PowerUp() && test.Test_Speed_ThrowSpeed()){
        std::cout << "Super powers are working" << std::endl;
        return true;
    }
    std::cout << "Super powers are not working" << std::endl;
    return false;
}

//tests for projectile

bool Test::Test_Move_Projectile(){
    pair position = {double(rand() % 739), double(rand() % 505)};
    Player_projectile_2 proj(position, true, 20, 2);   //wine projectile
    int x = proj.life;
    proj.move();

    //1st test: life goes down by 1
    if(int(proj.life) != x - 1){
        std::cout << "Move projectile is not working" << std::endl;
        return false;
    }

    //2nd test: updating colliding items
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < proj.collision_ranges[i]->collidingItems().size(); j++){
            QString collision_type = collision_master->collide("Projectile",QString(typeid(*proj.collision_ranges[i]->collidingItems()[j]).name()));
            if(collision_type == "simple_collision" || collision_type == "damage_block" || collision_type == "enemy_collision"){
                if(!proj.collision[i]){
                    std::cout << "Move projectile is not working" << std::endl;
                    return false;
                }
            }
        }
    }
    std::cout << "Move projectile is working" << std::endl;
    return true;
}

//tests for player

bool Test::Test_KeyEvents(QKeyEvent *event){
    Player* player = new Player;
    player->times_jumped= 0;
    player->keyPressEvent(event);
    if(event->key() == Qt::Key_Left){
        if(!player->pressed_left){
            return false;
        }
        player->keyReleaseEvent(event);
        if(player->pressed_left){
            return false;
        }
    }
    if(event->key() == Qt::Key_Right){
        if(!player->pressed_right){
            return false;
        }
        player->keyReleaseEvent(event);
        if(player->pressed_right){
            return false;
        }
    }
    if(event->key() == Qt::Key_Up){
        if(player->times_jumped != 1){
            return false;
        }
    }
    std::cout << "Key events player works" << std::endl;
    return true;
}

bool Test::Test_Move_Player(){
    Player* player = new Player;
    int x = int(player->speed.x);
    int y = int(player->speed.y);

    //motion smooth tests

    if(player->pressed_left){
        if(x > (-player->max_speed.x)*(player->super_powers->get_speed())){
            if(int(player->speed.x) != x - 1){
                return false;
            }
        }
    }
    else{
        if(x < 0){
            if(int(player->speed.x) != (x < -1) ? x/2 : 0){
                return false;
            }
        }
    }
    if(player->pressed_right){
        if(x < (player->max_speed.x)*(player->super_powers->get_speed())){
            if(int(player->speed.x) != x + 1){
                return false;
            }
        }
    }
    else{
        if(x > 0){
            if(int(player->speed.x) != (x > 1) ? x/2 : 0){
                return false;
            }
        }
    }
    if(y > player->max_speed.y){
        if(int(player->speed.y) != int(player->max_speed.y)){
            return false;
        }
    }
    else if(y < -player->max_speed.y){
        if(int(player->speed.y) != -int(player->max_speed.y)){
            return false;
        }
    }

    //in boundaries tests
    bool y1 = (0 > player->speed.y);
    bool x1 = (0 < player->speed.x);
    bool x2 = (0 > player->speed.x);

    if(player->y() >= view->world_size.bottom){
        if(!y1){
            if(int(player->y()) != int(view->world_size.bottom)){
                return false;
            }
        }
    }
    if(player->x() <= view->world_size.left){
        if(!x1){
            if(int(player->x()) != int(view->world_size.left)){
                return false;
            }
        }
    }
    if(player->x() >= (view->world_size.right - player->size.x)){
        if(!x2){
            if(int(player->x()) != int(view->world_size.right - player->size.x)){
                return false;
            }
        }
    }

    //movements
    if(player->collision[0]){
        if(int(player->speed.x) != 0){
            return false;
        }
    }
    if(player->collision[1]){
        if(int(player->speed.y) != 0){
            return false;
        }
    }
    if(!player->collision[0] && !player->collision[1] && player->collision[2]){
        if(int(player->speed.y) != 0){
            return false;
        }
    }

    //jump reset
    if(player->collision[1] && int(player->speed.y) >= 0){
        if(player->times_jumped != 0){
            return false;
        }
    }
    std::cout << "Move for player is working" << std::endl;
    return true;
}

bool Test::Test_Jump_Player(){
    Player* player = new Player;
    player->times_jumped = 1;
    player->max_consecutive_jumps = 2;
    player->super_powers->supers_b[super_jump] = true;
    player->jump();
    if(player->times_jumped != 1){  //shouldn't have changed
        std::cout << "Jump for player is not working" << std::endl;
        return false;
    }
    player->super_powers->supers_b[super_jump] = false;
    player->jump();
    if(player->times_jumped == 2){
        if(int(player->speed.y) == -int(player->max_speed.y)){
            std::cout << "yayy" <<std::endl;
            std::cout << "Jump for player is working" << std::endl;
            return true;
        }
    }
    std::cout << "Jump for player is not working" << std::endl;
    return false;
}

