#include "Room.h"
#include <iostream>

using namespace std;

Room::Room(/* args */)
{
    playerHere = false;
    chestSpawn = false;
    treasureState = false;
    roomNum = -1;
}

Room::~Room()
{
}

void Room::setPlayer(bool state)
{
    playerHere = state;
}

void Room::setChestSpawn(bool state)
{
    chestSpawn = state;
}

void Room::setTreasure(bool state)
{
    treasureState = state;
}

void Room::setRoomNum(int index)
{
    roomNum = index;
}

void Room::setVisibility(bool state)
{
    visible = state;
}

bool Room::getPlayer()
{
    return playerHere;
}

bool Room::getChestSpawn()
{
    return chestSpawn;
}

bool Room::getTreasureState()
{
    return treasureState;
}

bool Room::getVisibility()
{
    return visible;
}

int Room::getRoomNum()
{
    return roomNum;
}