#ifndef ROLL_H
#define ROLL_H

#include <string>
#include <utility>
#include <vector>

class Roll
{
    public:
        void setName(const std::string &);
        std::string getName() const;

    private:
        std::string name;
        std::vector<std::pair<int,int>> rollList;
};

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
