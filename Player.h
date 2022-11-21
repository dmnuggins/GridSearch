#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

class Player : public Object
{
private:
    char direction;   // player direction
    int nextX, nextY; // player's next move
    bool inChestRoom; // flag for if player is in room

public:
    Player(/* args */);
    ~Player();

    void setNextMove(char playerInput);
    void resetNextMove();

    void setRoomStatus(bool newState);
    bool getRoomStatus();
    char getPlayerDirection();
    int getNextX();
    int getNextY();

    void updatePlayer(char playerInput);
    void movePlayer();

    bool isColliding();
    bool isOutOfBounds();
};

#endif