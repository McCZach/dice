#include "Roll.h"
#include <iostream>
#include <random>
using namespace std;

void Roll::rollDice()
{
    char input;
    bool done = false;

    int index, numDie, rollSum;
    index = numDie = rollSum = 0;

    random_device rd;
    auto random = default_random_engine{rd()};
 
    int dieType = 4;
    while ((!done) && (dieType <= 12))
    {
        uniform_int_distribution<> dist(1, dieType);    


        cout << "Would you like to roll d" << dieType << "(s)? (Y/N): ";
        cin >> input;
        input = toupper(input);

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
                int dieRoll = dist(random);

                if (i != numDie)
                {
                    cout << dieRoll << ", ";
                }
                else
                {
                    cout << dieRoll << endl;
                }

                rollSum += dieRoll;
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

double Roll::scoreRoll(const int & i) const
{
    int dieType = ((i + 1) * 2) + 2;

    double maximum = rollList[i].first * dieType;

    return (rollList[i].second / maximum);
}

double Roll::getScore() const
{
    double sum;
    int count = 0;

    for (int i = 0; i < LENGTH; i++)
    {
        if (rollList[i].first != 0)
        {
            sum += scoreRoll(i);
            count += 1;
        }
    }

    count = LENGTH - count;

    return (sum / count);
}