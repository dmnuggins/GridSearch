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

    struct Point
    {
        int x, y;
    };

public:
    Map();
    ~Map();

    void initializeMap();
    void updateMap(Player &p1);
    void updatePlayer(Player &p1);

    void displayMap();
    void setPlayerVision(Player &p1);
    char symbol(Room room);
    char getSymbol(Player &p, int x, int y);

    void checkPlayerCollision();
    bool isTreasureFound(Player p1);

    void clearMap();
};

#endif