#include "Map.h"
#include "Room.h"
#include "Player.h"
#include <iostream>

using namespace std;

Map::Map(int width, int length)
{
    cout << "Map generated..." << endl;
    this->length = length;
    this->width = width;
}

Map::~Map()
{
}

// Displays map
void Map::displayMap(Player &p1)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << "[" << getSymbol(p1, i, j) << "]";
        }
        cout << endl;
    }
    cout << "Map is displayed" << endl;
}

// Returns symbol of object given the paramter coords
char Map::getSymbol(Player &p1, int x, int y)
{
    char symbol;

    if (checkPlayer(p1, x, y) && checkRoom(x, y))
    {
        symbol = 'O';
        p1.setRoomStatus(true);
    }
    else if (checkPlayer(p1, x, y) && !checkRoom(x, y))
    {
        symbol = 'P';
        p1.setRoomStatus(false);
    }
    else if (checkRoom(x, y) && !checkPlayer(p1, x, y))
    {
        symbol = 'X';
    }
    else
    {
        symbol = ' ';
    }
    return symbol;
}

// Checks if rooms is present at given position
bool Map::checkRoom(int x, int y)
{
    for (int i = 0; i <= sizeof(*rooms); i++)
    {
        if (rooms[i].x == x && rooms[i].y == y)
            return true;
    }
    return false;
}

// Checks if Player is present at given position (x, y)
bool Map::checkPlayer(Player &p1, int x, int y)
{
    bool isPlayer = false;

    // checks if player is present in location
    if (x == p1.getX() && y == p1.getY())

    {
        isPlayer = true;
    }

    return isPlayer;
}

bool Map::isPlayerColliding(Player &p)
{
    if (p.getRoomStatus() == false) // if player is not in room
    {
    }
    else // if player is in room
    {
    }

    return false;
}

Map::Point *Map::getRooms()
{
    return rooms;
}