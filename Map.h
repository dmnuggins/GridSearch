#ifndef MAP_H
#define MAP_H

class Map
{
private:
    /* data */
    int width, length;

    struct Point
    {
        int x, y;
    };

    // Coordinates of the rooms
    Point rooms[9] = {  {1,1}, {1,3}, {1,5},
                        {3,1}, {3,3}, {3,5},
                        {5,1}, {5,3}, {5,5} };

public:
    Map(int width, int length);
    ~Map();
    void displayMap();
    // Check room location relative to map
    char checkRoom(int x, int y);
};

#endif