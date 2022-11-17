#ifndef ROOM_H
#define ROOM_H

#include "Object.h"

class Room : public Object
{
private:
    bool playerHere;   // check if player is in room
    bool chestSpawn;   // flag for if room is chest spawn
    bool treasureHere; // flag for when treasure is inside chest
public:
    Room(/* args */);
    ~Room();

    void setPlayer(bool state);
    void setChestSpawn(bool state);
    bool getPlayer();
    bool getChestSpawn();
};

#endif