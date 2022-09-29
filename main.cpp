#include <iostream>
#include "Map.h"
#include "Room.h"

using namespace std;

bool checkInput(char playerInput);

int main()
{

    char playerInput;
    int moveCounter = 1;
    Map newMap(7, 7);

    while (newMap.updateMap(playerInput))
    {
        cout << "Enter directional key (w,a,s,d): ";
        cin >> playerInput;
        // force input to lowercase
        playerInput = tolower(playerInput);
        moveCounter++;
    }

    return 0;
}

bool checkInput(char playerInput)
{
    return false;
}