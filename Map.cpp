#include "Map.h"

using namespace std;

Map::Map()
{
    std::cout << "Map initialized..." << std::endl;

    // initialize room coordinates
    rooms = new Room *[ROW];
    for (int i = 0; i < ROW; i++)
    {
        rooms[i] = new Room[COL];
        for (int j = 0; j < COL; j++)
        {
            rooms[i][j].setX(i);
            rooms[i][j].setY(j);
        }
    }

    // initialize chest rooms
    for (int i = 1; i < ROW; i += 2)
    {
        for (int j = 0; j < COL; j++)
        {
            if (j == 1 || j == 3 || j == 5)
            {
                rooms[i][j].setChestSpawn(true);
            }
        }
    }

    rooms[0][0].setPlayer(true);
}

Map::~Map()
{
}

void Map::initializeMap()
{
    // code
}

void Map::updateMap(Player &p1)
{
    // update map with coordinate changes from player
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            // update player flag on rooms
            if ((rooms[i][j].getX() != p1.getX()) || (rooms[i][j].getY() != p1.getY()))
            {
                rooms[i][j].setPlayer(false);
            }
            else if ((rooms[i][j].getX() == p1.getX()) && (rooms[i][j].getY() == p1.getY()))
            {
                rooms[i][j].setPlayer(true);

                // checks if room is also a chest location
                if (rooms[i][j].getChestSpawn())
                {
                    p1.setRoomStatus(true); // set player chest spawn flag true
                }
                else
                {
                    p1.setRoomStatus(false);
                }
            }
        }
        cout << endl;
    }
}

// Displays map
void Map::displayMap()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            // cout << "[" << rooms[i][j].getX() << "," << rooms[i][j].getY() << "]"; // getSymbol(p1, i, j)
            cout << "[" << symbol(rooms[i][j]) << "]"; // getSymbol(p1, i, j)
        }
        cout << endl;
    }
    cout << "Map is displayed" << endl;
}

// returns symbol based on room status
char Map::symbol(Room room)
{
    if (room.getPlayer() && room.getChestSpawn())
    {
        return 'O';
    }
    else if (room.getPlayer())
    {
        return 'P';
    }
    else if (room.getChestSpawn())
    {
        return 'X';
    }
    else
    {
        return ' ';
    }
}

void Map::checkPlayerBounds()
{
}

void Map::clearMap()
{
    for (int i = 0; i < 7; i++)
    {
        delete[] rooms[i];
    }
    delete[] rooms;
    rooms = NULL;
}
