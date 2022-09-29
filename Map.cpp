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

bool Map::updateMap(char playerInput)
{
    if (playerInput == 'q')
    {
        cout << "Exited game..." << endl;
        return false;
    }
    // p1.movePlayer(playerInput);
    p1.setNextMove(playerInput);
    p1.updatePlayer(playerInput);
    displayMap();
    return true;
}

// Displays map
void Map::displayMap()
{
    cout << "Map is displayed" << endl;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << "[" << getSymbol(i, j) << "]";
        }
        cout << endl;
    }
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
bool Map::checkPlayer(int x, int y)
{
    if (x == p1.getX() && y == p1.getY())
        return true;
    return false;
}

// Returns symbol of object given the paramter coords
char Map::getSymbol(int x, int y)
{
    if (checkRoom(x, y))
        return 'X';
    else if (checkPlayer(x, y))
        return 'O';
    return ' ';
}
