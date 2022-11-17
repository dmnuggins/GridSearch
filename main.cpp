#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Room.h"

using namespace std;

int main()
{

    Player p1;
    char playerInput;
    Map newMap(p1);
    int moveCounter = 1;
    // Room **rooms = new Room *[7];

    do
    {
        system("CLS");
        cout << "Initial Map:" << endl;
        newMap.displayMap();

        cout << "Move counter: " << moveCounter << endl;
        // cout << "Player position: " << p1.getX() << ", " << p1.getY() << endl;
        // cout << "Player room status: " << p1.getRoomStatus() << endl;
        cout << "Enter directional key (w,a,s,d): ";
        cin >> playerInput;
        playerInput = tolower(playerInput); // forces input to lowercase
        moveCounter++;

        if (playerInput == 'q')
        {
            cout << "Exited game..." << endl;
            break;
        }

        // p1.setNextMove(playerInput);
        // p1.updatePlayer(playerInput);
        // newMap.displayMap(p1);
    } while (true);

    // for (int i = 0; i < 7; i++)
    // {
    //     delete[] rooms[i];
    // }
    // delete[] rooms;
    // rooms = NULL;

    return 0;
}
