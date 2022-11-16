#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

class Player : public Object
{
private:
    char direction;
    int xMove, yMove;
    bool inRoom; // flag for if player is in room

public:
    Player(/* args */);
    ~Player();

    void setNextMove(char playerInput);
    void resetNextMove();

    void setRoomStatus(bool newState);
    bool getRoomStatus();

    void updatePlayer(char playerInput);
    void movePlayer();

    bool isColliding();
    bool isOutOfBounds();
    bool isHittingWall(Map map);
};

#endif