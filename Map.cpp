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
    // stores player input direction
    char direction = p1.getPlayerDirection();

    // clear visibility flags
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            rooms[i][j].setVisibility(false);
        }
    }

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
    }

    setPlayerVision(p1);
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

void Map::setPlayerVision(Player &p1) // sets player vision
{
    int x = p1.getX();
    int y = p1.getY();
    bool playerInsideRoom = p1.getRoomStatus();

    // update visibilty flag of adjacent rooms based on player position
    if (x - 1 >= 0 && !rooms[x - 1][y].getChestSpawn()) // w
    {
        rooms[x - 1][y].setVisibility(true);
    }
    if (y - 1 >= 0 && !playerInsideRoom && !rooms[x][y - 1].getChestSpawn()) // a
    {
        rooms[x][y - 1].setVisibility(true);
    }
    if (x + 1 < ROW && !playerInsideRoom) // s
    {
        rooms[x + 1][y].setVisibility(true);
    }
    if (y + 1 < COL && !playerInsideRoom && !rooms[x][y + 1].getChestSpawn()) // d
    {
        rooms[x][y + 1].setVisibility(true);
    }
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
    else if (!room.getVisibility() && room.getChestSpawn())
    {
        symbol = 'X';
    }
    else if (room.getVisibility())
    {
        symbol = '*';
        if (room.getChestSpawn())
        {
            symbol = 'E';
            if (room.getTreasureState())
            {
                symbol = 'T';
            }
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
