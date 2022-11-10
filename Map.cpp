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

// Primary update loop for player in map
// bool Map::updateMap(char playerInput)
// {
//     if (playerInput == 'q')
//     {
//         cout << "Exited game..." << endl;
//         return false;
//     }
//     // p1.movePlayer(playerInput);
//     p1.setNextMove(playerInput);
//     p1.updatePlayer(playerInput);
//     displayMap();
//     return true;
// }

// Displays map
void Map::displayMap(Player p1)
{
    cout << "Map is displayed" << endl;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << "[" << getSymbol(p1, i, j) << "]";
        }
        cout << endl;
    }
}

// Returns symbol of object given the paramter coords
char Map::getSymbol(Player p1, int x, int y)
{
    if (checkRoom(x, y))
        return 'X';
    else if (checkPlayer(p1, x, y))
        return 'O';
    return ' ';
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

// Checks if Player is present at given position
bool Map::checkPlayer(Player p1, int x, int y)
{
    if (x == p1.getX() && y == p1.getY())
        return true;
    return false;
}

Map::Point *Map::getRooms()
{
    return rooms;
}