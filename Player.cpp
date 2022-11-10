#include "Player.h"
#include <iostream>

Player::Player(/* args */)
{
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
        xMove = -1;
        break;
    case 'a':
        direction = playerInput;
        yMove = -1;
        break;
    case 's':
        direction = playerInput;
        xMove = 1;
        break;
    case 'd':
        direction = playerInput;
        yMove = 1;
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
    xMove = 0;
    yMove = 0;
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
    setX(curX + xMove);
    setY(curY + yMove);

    resetNextMove();
}

bool Player::isColliding()
{
    if (isOutOfBounds()) //  || isHittingWall()
        return true;
    // Check if player is out of bounds
    // Check if player is colliding with rooms
    return false;
}

bool Player::isOutOfBounds()
{
    int curX = getX();
    int curY = getY();
    // check if player is outside of map bounds
    if ((curX + xMove) > 6 || (curY + yMove) > 6 || (curX + xMove) < 0 || (curY + yMove) < 0)
    {
        std::cout << "Out of bounds..." << std::endl;
        return true;
    }
    return false;
}

bool Player::isHittingWall()
{
    int curX = getX();
    int curY = getY();

    for (int i = 0; i < 9; i++)
    {
        /* code */
    }

    // check if player is entering room from above (like bucket)

    return false;
}
