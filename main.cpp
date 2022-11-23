#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Room.h"
#include "Chest.h"

using namespace std;

int main()
{

    Player p1;
    char playerInput;
    Map newMap;
    int moveCounter = 1;
    // Room **rooms = new Room *[7];

    do
    {
        system("CLS");
        newMap.displayMap();

        cout << "Move counter: " << moveCounter << endl;
        cout << "Player position: " << p1.getX() << ", " << p1.getY() << endl;
        cout << "Player room status: " << p1.getRoomStatus() << endl;
        cout << "Enter directional key (w,a,s,d): ";
        cin >> playerInput;
        playerInput = tolower(playerInput); // forces input to lowercase
        moveCounter++;

        if (playerInput == 'q')
        {
            cout << "Exited game..." << endl;
            break;
        }

        p1.setNextMove(playerInput);
        newMap.updatePlayer(p1);
        newMap.updateMap(p1);
        bool winCon = newMap.isTreasureFound(p1);

        if (winCon)
        {
            system("CLS");
            newMap.displayMap();
            cout << "TREASURE FOUND!!!" << endl;
            break;
        }
    } while (true);

    // frees up memory
    newMap.clearMap();

    return 0;
}
