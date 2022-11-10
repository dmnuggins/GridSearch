#ifndef ROOM_H
#define ROOM_H

#include "Object.h"

class Room : public Object
{
private:
    /* data */
    bool playerHere; // check if player is in room
public:
    Room(/* args */);
    ~Room();
};

#endif