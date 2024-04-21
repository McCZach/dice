#ifndef ROLL_H
#define ROLL_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>

const int LENGTH = 5;

class Roll
{
    public:
        Roll();
        ~Roll();
        void setName(const std::string &);
        std::string getName() const;
        void rollDice();
        void display() const;

    private:
        std::string name;
        std::vector<std::pair<int,int>> rollList;
};

inline
Roll::Roll()
{
    name = "";

    rollList.resize(LENGTH);

    for (int i = 0; i < LENGTH; i++)
    {
        rollList[i].first = 0;
        rollList[i].second = 0;
    }
}

inline
Roll::~Roll()
{
    name = "";
    rollList.erase(rollList.begin(), rollList.end());
}

inline
void Roll::setName(const std::string& n)
{
    name = n;
}

inline
std::string Roll::getName() const
{
    return name;
}

#endif
