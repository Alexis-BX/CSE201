#include "player.h"
#include <iostream>

Player::Player(pair position, pair size, State state):
    Character(position, size, state),
    max_speed(1)
{

}

Player::Player(pair position):
    Character(position, pair{10,10}, State{normal_player}),
    max_speed(1)
{

    setRect(position.x,position.y,size.x,size.y);

    setPos(position.x,position.y);

    setFlag(QGraphicsItem::ItemIsFocusable);

    setFocus();
}

void Player::next_position()
{
    position.x += speed.x;
    position.y += speed.y;
    speed.y -= 1;
    std::cout << position.x << "   " << position.y << std::endl;
}

void Player::goforward()
{
    speed.x = max_speed;
}


void Player::goback()
{
    speed.x = max_speed;
}

void Player::jump()
{
    speed.y = max_speed*5;
}

void Player::stop()
{
    speed.x = 0;
}

void Player::growbigger()
{
    size.y*=2;
}

void Player::shrink()
{
    size.y /= 2;
}
