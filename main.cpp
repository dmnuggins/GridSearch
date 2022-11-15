#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Room.h"

using namespace std;

Player p1;

int main()
{

    char playerInput;
    int moveCounter = 1;
    Map newMap(7, 7);

    do
    {
        system("CLS");
        cout << "Initial Map:" << endl;
        newMap.displayMap(p1);
        cout << "Move counter: " << moveCounter << endl;
        cout << "Player position: " << p1.getX() << ", " << p1.getY() << endl;
        cout << "Player room status: " << p1.getRoomStatus() << endl;
        cout << "Enter directional key (w,a,s,d): ";
        cin >> playerInput;
        // force input to lowercase
        playerInput = tolower(playerInput);
        moveCounter++;

        if (playerInput == 'q')
        {
            cout << "Exited game..." << endl;
            break;
        }

        p1.setNextMove(playerInput);
        p1.updatePlayer(playerInput);
        newMap.displayMap(p1);
    } while (true);

    return 0;
}

bool checkInput(char playerInput)
{
    return false;
}