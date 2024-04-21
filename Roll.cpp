#include "Roll.h"
#include <iostream>
#include <random>
using namespace std;

void Roll::rollDice()
{
    char input;
    int index, numDie, rollSum;
    
    index = numDie = rollSum = 0;

    int dieType = 4;

    bool done = false;

    random_device rd;
    auto random = default_random_engine{rd()};
 
    while (!done)
    {
        uniform_int_distribution<> dist(1, dieType);    


        cout << "Would you like to roll d" << dieType << "(s)? (Y/N): ";
        cin >> input;
        input = toupper(input);
        cout << endl << endl;

        while ((input != 'Y') && (input != 'N'))
        {
            cout << "Error. Please enter Y or N: ";
            cin >> input;
            input = toupper(input);
            cout << endl << endl;
        }

        if (input == 'Y')
        {
            cout << "How many d" << dieType << "? ";
            cin >> numDie;

            while (numDie < 0)
            {
                cout << "Error. Please enter non-negative integer: ";
                cin >> numDie;
                cout << endl << endl;
            }
            rollList[index].first = numDie;


            for (int i = 1; i <= numDie; i++)
            {
                rollSum += dist(random);
            }
            rollList[index].second = rollSum;
        }
    

        cout << "Have you finished rolling? (Y/N): ";
        cin >> input;
        input = toupper(input);
        cout << endl << endl;

        while ((input != 'Y') && (input != 'N'))
        {
            cout << "Error. Please enter Y or N: ";
            cin >> input;
            input = toupper(input);
            cout << endl << endl;
        }

        if (input == 'Y')
        {
            done = true;
        }
        else
        {
            rollSum = numDie = 0;
            index += 1;
            dieType += 2;
        }
    }
      

}

void Roll::display() const
{
    cout << "Name: " << name << endl;

    int dieType = 4;
    cout << "Rolls: " << endl;
    for (int i = 0; i < LENGTH; i++)
    {
        cout << "- d" << dieType << ": " << rollList[i].first << ", " 
             << rollList[i].second << endl;

        dieType += 2;
    }
    cout << endl;
}