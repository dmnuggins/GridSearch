#ifndef CHEST_H
#define CHEST_H

#include "Object.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

class Chest : public Object
{
private:
    bool hasTreasure;
    int chestIndex;

public:
    Chest(/* args */);
    ~Chest();
    void setTreasureState(bool state);
    bool getTreasureState();
    int getChestIndex();
};

#endif