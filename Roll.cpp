#include "Roll.h"
#include <iostream>

void Roll::display() const
{
    std::cout << "Name: " << name << std::endl;

    std::cout << "Rolls: " << std::endl;
    for (int i = 0; i < LENGTH; i++)
    {
        std::cout << "- d" << rollList[i].first << ": " 
                  << rollList[i].second << std::endl;
    }
}