#include "Map.h"

using namespace std;

Map::Map()
{
    int roomIndex = 0;
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
                rooms[i][j].setRoomNum(roomIndex);

                // initialize treasure spawn
                if (treasure.getChestIndex() == rooms[i][j].getRoomNum())
                {
                    rooms[i][j].setTreasure(true);
                }
                roomIndex++;
            }
        }
    }

    // set initial player position
    rooms[0][0].setPlayer(true);

    std::cout << "Map initialized..." << std::endl;
}

Map::~Map()
{
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

                // update visibility state of adjacent rooms
                // insert code here

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
    }
}

// update player based on user input and next move set
void Map::updatePlayer(Player &p1)
{
    char input = p1.getPlayerDirection();
    if (p1.getRoomStatus())
    {
        if (input != 'w')
        {
            std::cout << "ERROR::colliding inside chest room" << std::endl;
            // reset the next move
            p1.resetNextMove();
        }
        else
        {
            p1.movePlayer();
        }
    }
    else // if player chestroomstatus is false
    {
        if (input != 's' && rooms[p1.getNextX()][p1.getNextY()].getChestSpawn())
        {
            std::cout << "ERROR::colliding with chest room" << std::endl;
            p1.resetNextMove();
        }
        else if (p1.isOutOfBounds()) // with outer bounds of the map
        {
            std::cout << "ERROR::colliding with outer bounds" << std::endl;
            p1.resetNextMove();
        }
        else
        {
            p1.movePlayer();
        }
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
    cout << "Treaure index: " << treasure.getChestIndex() << endl;
}

// returns symbol based on room status
char Map::symbol(Room room)
{
    char symbol;
    if (room.getPlayer() && room.getChestSpawn())
    {
        symbol = 'O';
    }
    else if (room.getPlayer())
    {
        symbol = 'P';
    }
    else if (room.getChestSpawn())
    {
        symbol = 'X';
        if (room.getTreasureState())
        {
            symbol = 'T';
        }
    }
    else
    {
        symbol = ' ';
    }

    return symbol;
}

void Map::checkPlayerCollision()
{
}

bool Map::isTreasureFound(Player p1)
{
    // if player position is in room that has treasure state as true
    if (rooms[p1.getX()][p1.getY()].getTreasureState())
    {
        return true;
    }

    return false;
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
