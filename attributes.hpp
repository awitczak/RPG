#ifndef ATTRIBUTES_HPP
#define ATTRIBUTES_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

class Attributes
{
public:
    std::string name;
    int XP;
    int HP;
    int strength, dexterity, endurance, intelligence, charisma, level;
    virtual void dispAttributes() = 0;
    virtual ~Attributes(){};
};

#endif