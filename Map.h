#ifndef MAP_H
#define MAP_H

#include "Player.h"

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

    Player p1;
    // Coordinates of the rooms
    Point rooms[9] = {{1, 1}, {1, 3}, {1, 5}, {3, 1}, {3, 3}, {3, 5}, {5, 1}, {5, 3}, {5, 5}};

public:
    Map(int width, int length);
    ~Map();
    bool updateMap(char playerInput);
    void displayMap();
    // Check room location relative to map
    bool checkRoom(int x, int y);
    bool checkPlayer(int x, int y);
    char getSymbol(int x, int y);
};

#endif