#include "Player.h"
#include <iostream>

Player::Player(/* args */)
{

}

Player::~Player()
{

}

// Updates player position
void Player::movePlayer(char playerInput)
{
    int tempX = getX();
    int tempY = getY();

    if(playerInput == 'w')
    {
        tempX -= 1;
        setX(tempX);
    }
    else if(playerInput == 'a')
    {
        tempY -= 1;
        setY(tempY);
    }
    else if(playerInput == 's')
    {
        tempX += 1;
        setX(tempX);

    }
    else if(playerInput == 'd')
    {
        tempY += 1;
        setY(tempY);
    }
    else
        std::cout << "Invalid input..." << std::endl;

}

