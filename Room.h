#ifndef ROOM_H
#define ROOM_H

#include "Object.h"

class Room : public Object
{
private:
    bool playerHere;    // check if player is in room
    bool enemyHere;     // check if enemy is in room
    bool chestSpawn;    // flag for if room is chest spawn
    bool treasureState; // flag for when treasure is inside chest
    int roomNum;        // room index number for spawn reference
    bool visible;       // flag if visible to player

public:
    Room(/* args */);
    ~Room();

    void setPlayer(bool state);
    void setEnemy(bool state);
    void setChestSpawn(bool state);
    void setTreasure(bool state);
    void setRoomNum(int index);
    void setVisibility(bool state);

    bool getPlayer();
    bool getEnemy();
    bool getChestSpawn();
    bool getTreasureState();
    bool getVisibility();
    int getRoomNum();
};

#endif