#ifndef MAP_H
#define MAP_H

class Map
{
private:
    /* data */
    int width, length;
public:
    Map(int width, int length);
    ~Map();
    void displayMap();
};

#endif