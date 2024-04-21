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

    int count = 4;
    for (int i = 0; i < LENGTH; i++)
    {
        rollList[i].first = count;
        rollList[i].second = 0;
        count += 2;
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
