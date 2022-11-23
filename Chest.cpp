#include "Chest.h"

Chest::Chest(/* args */)
{
    srand(time(0));
    chestIndex = (rand() % 9);
}

Chest::~Chest()
{
}

void Chest::setTreasureState(bool state)
{
    hasTreasure = state;
}

bool Chest::getTreasureState()
{
    return hasTreasure;
}

int Chest::getChestIndex()
{
    return chestIndex;
}