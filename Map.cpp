#include "Map.h"
#include "Room.h"
#include <iostream>

using namespace std;

Map::Map(int width,int length)
{
    cout << "Map generated..." << endl;
    this->length = length;
    this->width = width;
}

Map::~Map()
{
}

void Map::displayMap() 
{
    cout << "Map is displayed" << endl;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << "[" << checkRoom(i, j) << "]";
        }
        cout << endl;
    }
    
}

// Checks if parameter coords match with coordinates from rooms, if match, return X
char Map::checkRoom(int x, int y)
{
    for (int i = 0; i <= sizeof(*rooms); i++)
    {
        if(rooms[i].x == x && rooms[i].y == y)
            return 'X';
    }

    return ' ';
}

