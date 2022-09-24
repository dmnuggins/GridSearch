#include "Map.h"
#include "Room.h"
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

void Map::displayMap() 
{
    cout << "Map is displayed" << endl;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << "[" << " " << "]";
        }
        cout << endl;
    }
    
}
