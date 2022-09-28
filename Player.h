#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

class Player: public Object
{
private:

public:
    Player(/* args */);
    ~Player();
    void movePlayer(char playerInput);
};




#endif