#include "Player.h"
#include "Room.h"
#include "Map.h"
#include <iostream>

Player::Player(/* args */)
{
    this->setX(0);
    this->setY(0);
}

Player::~Player()
{
}

void Player::setNextMove(char playerInput)
{
    switch (playerInput)
    {
    case 'w':
        direction = playerInput;
        nextX = -1;
        break;
    case 'a':
        direction = playerInput;
        nextY = -1;
        break;
    case 's':
        direction = playerInput;
        nextX = 1;
        break;
    case 'd':
        direction = playerInput;
        nextY = 1;
        break;
    default:
        std::cout << "Invalid input..." << std::endl;
        break;
    }
}

// Reset player movement values
void Player::resetNextMove()
{
    direction = ' ';
    nextX = 0;
    nextY = 0;
}

void Player::setRoomStatus(bool newState)
{
    inRoom = newState;
}

bool Player::getRoomStatus()
{
    return inRoom;
}
void Player::updatePlayer(char playerInput)
{
    if (!isColliding())
    {
        movePlayer();
    }
    resetNextMove();
}

void Player::movePlayer()
{
    int curX = getX();
    int curY = getY();
    setX(curX + nextX);
    setY(curY + nextY);

    resetNextMove();
}

bool Player::isColliding()
{
    // checks if player is out of bounds
    if (isOutOfBounds()) //  || isHittingWall()
        return true;
    // Check if player is colliding with rooms
    return false;
}

bool Player::isOutOfBounds()
{
    int curX = getX();
    int curY = getY();
    // check if player is outside of map bounds
    if ((curX + nextX) > 6 || (curY + nextY) > 6 || (curX + nextX) < 0 || (curY + nextY) < 0)
    {
        std::cout << "Out of bounds..." << std::endl;
        return true;
    }
    return false;
}
