#include "enemy.h"

Enemy::Enemy(pair position, pair size, Enemy_type type,State state):
    Character(position, size, state,spd[type], lif[type])
{

}

void Enemy::goback(){
    speed.x=-speed.x;
}

void Enemy::makesmoke(){

}

void Enemy::hit(Player player){
    player.behit(type);//there should be a attribute as different enemy can cause different type of damage
}

void Enemy::behit(Character object){
    hp-=1;
    if (hp==0){
        die();
    }else{
        hit(object);
    }
}

void die(){
    state=die;
}
