#ifndef MAP_H
#define MAP_H

#include "Player.h"
#include "Room.h"

class Map
{
private:
    /* data */
    int width, length;
    char playerInput;

    struct Point
    {
        int x, y;
    };

    // Player p1;
    // Coordinates of the rooms
    Point rooms[9] = {{1, 1}, {1, 3}, {1, 5}, {3, 1}, {3, 3}, {3, 5}, {5, 1}, {5, 3}, {5, 5}};

public:
    Map(int width, int length);
    ~Map();

    void displayMap(Player &p);
    char getSymbol(Player &p, int x, int y);

    bool checkRoom(int x, int y);
    bool checkPlayer(Player &p, int x, int y);
    bool isPlayerColliding(Player &p);

    Point *getRooms();
};

#endif