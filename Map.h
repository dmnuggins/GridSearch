#ifndef MAP_H
#define MAP_H

#include "Player.h"
#include "Room.h"
#include "Chest.h"
#include <iostream>

class Map
{
private:
    /* data */
    const int ROW = 7, COL = 7;
    char playerInput;
    Room **rooms;
    Chest treasure;
    // Point rooms[9] = {{1, 1}, {1, 3}, {1, 5}, {3, 1}, {3, 3}, {3, 5}, {5, 1}, {5, 3}, {5, 5}};

public:
    Map();
    ~Map();

    void initializeMap();
    void updateMap(Player &p1);
    void updatePlayer(Player &p1);

    void displayMap();
    char symbol(Room room);
    char getSymbol(Player &p, int x, int y);

    void checkPlayerCollision();
    bool isTreasureFound(Player p1);

    void clearMap();
};

#endif