#include "Player.h"
#include "Room.h"
#include "Map.h"
#include <iostream>

Player::Player(/* args */)
{
    this->setX(0);
    this->setY(0);
    this->setRoomStatus(false);
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
        nextX = this->getX() - 1;
        nextY = this->getY();
        break;
    case 'a':
        direction = playerInput;
        nextX = this->getX();
        nextY = this->getY() - 1;
        break;
    case 's':
        direction = playerInput;
        nextX = this->getX() + 1;
        nextY = this->getY();
        break;
    case 'd':
        direction = playerInput;
        nextX = this->getX();
        nextY = this->getY() + 1;
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
    inChestRoom = newState;
}

bool Player::getRoomStatus()
{
    return inChestRoom;
}

char Player::getPlayerDirection()
{
    return direction;
}

int Player::getNextX()
{
    return nextX;
}

int Player::getNextY()
{
    return nextY;
}

void Player::movePlayer()
{
    int curX = getX();
    int curY = getY();
    setX(nextX);
    setY(nextY);

    resetNextMove();
}

bool Player::isOutOfBounds()
{
    int curX = getX();
    int curY = getY();
    // check if player is outside of map bounds
    if ((nextX) > 6 || (nextY) > 6 || (nextX) < 0 || (nextY) < 0)
    {
        // std::cout << "Out of bounds..." << std::endl;
        return true;
    }
    return false;
}
