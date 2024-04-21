#include "Roll.h"
#include <iostream>
#include <random>
using namespace std;

void Roll::rollDice()
{
    random_device rd;
    auto random = default_random_engine{rd()}; 
      

}

void Roll::display() const
{
    cout << "Name: " << name << endl;

    int count = 4;
    cout << "Rolls: " << endl;
    for (int i = 0; i < LENGTH; i++)
    {
        cout << "- d" << count << ": " << rollList[i].first << ", " 
             << rollList[i].second << endl;

        count += 2;
    }
}