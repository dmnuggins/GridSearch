#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

class Player : public Object
{
private:
    char direction;
    int xMove, yMove;

public:
    Player(/* args */);
    ~Player();

    void setNextMove(char playerInput);
    void resetNextMove();

    void updatePlayer(char playerInput);
    void movePlayer();
    bool isColliding();
    bool isOutOfBounds();
    bool isHittingWall();
};

#endif