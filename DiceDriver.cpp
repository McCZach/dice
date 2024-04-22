#include "Roll.h"
#include <iostream>

using namespace std;

int main()
{
    Roll myObj;
    myObj.setName("Lebron James");

    myObj.display();

    myObj.rollDice();

    myObj.display();

    cout << "The roll's score is: " << myObj.getScore() << endl;
    
    return 0;
}