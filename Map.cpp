#include "Map.h"

using namespace std;

Map::Map(Player p1)
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
    if (room.getChestSpawn())
    {
        return 'X';
    }
    else if (room.getPlayer())
    {
        return 'P';
    }
    else
    {
        return ' ';
    }
}

// Returns symbol of object given the paramter coords
// char Map::getSymbol(Player &p1, int x, int y)
// {
//     char symbol;

//     if (checkPlayer(p1, x, y) && checkRoom(x, y))
//     {
//         symbol = 'O';
//     }
//     else if (checkPlayer(p1, x, y) && !checkRoom(x, y))
//     {
//         symbol = 'P';
//         p1.setRoomStatus(false);
//     }
//     else if (checkRoom(x, y) && !checkPlayer(p1, x, y))
//     {
//         symbol = 'X';
//     }
//     else
//     {
//         symbol = ' ';
//     }
//     return symbol;
// }

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
