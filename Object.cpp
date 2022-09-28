#include "Object.h"
#include <iostream>

Object::Object(/* args */)
{
    this->x = 0;
    this->y = 0;
}

Object::~Object()
{
}

int Object::getX()
{
    return x;
}

int Object::getY()
{
    return y;
}

void Object::setX(int x)
{
    this->x = x;
}

void Object::setY(int y)
{
    this->y = y;
}
