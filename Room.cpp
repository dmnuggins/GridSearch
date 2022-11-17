#include "Room.h"
#include <iostream>

using namespace std;

Room::Room(/* args */)
{
    playerHere = false;
    chestSpawn = false;
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

bool Room::getPlayer()
{
    return playerHere;
}

bool Room::getChestSpawn()
{
    return chestSpawn;
}