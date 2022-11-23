#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Map.h"
#include "Player.h"
#include "Room.h"
#include "Chest.h"

using namespace std;

void slow_print(const std::string &str, int delay_time)
{
    for (size_t i = 0; i != str.size(); ++i)
    {
        std::cout << str[i];
        Sleep(delay_time);
    }
}

int main()
{

    Player p1;
    char playerInput;
    Map newMap;
    int moveCounter = 1;
    int intro = 0;

    slow_print("WELCOME TO GRIDSEARCH\n", 10);
    cout << endl;

    system("pause");
    // slow_print("Press any key to continue...", 2);
    do
    {
        system("CLS");

        newMap.displayMap();

        if (intro < 1)
        {
            cout << "================================================" << endl;
            cout << "Use the \'wasd\' keys to navigate" << endl;
            cout << "Your movement options are indicated by the \'*\'" << endl;
            cout << "================================================" << endl;
        }

        intro++;

        cout << "Move counter: " << moveCounter << endl;
        cout << "Player position: " << p1.getX() << ", " << p1.getY() << endl;
        cout << "Player room status: " << p1.getRoomStatus() << endl;
        cout << "Enter directional key (w,a,s,d): ";
        cin >> playerInput;
        playerInput = tolower(playerInput); // forces input to lowercase
        moveCounter++;

        if (playerInput == 'q')
        {
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
            cout << "SUCCESS!! You've found the treasure in " << moveCounter << " moves!" << endl;
            break;
        }
    } while (true);

    cout << "GAME OVER" << endl;
    // frees up memory
    newMap.clearMap();
    system("pause");

    return 0;
}
