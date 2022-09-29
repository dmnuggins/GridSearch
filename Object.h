#ifndef OBJECT_H
#define OBJECT_H

class Object
{
private:
    // Position
    int x, y;

public:
    Object(/* args */);
    ~Object();
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
};

#endif