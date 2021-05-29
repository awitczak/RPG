#ifndef ATTRIBUTES_HPP
#define ATTRIBUTES_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

class Attributes
{
public:
    struct items {
        std::string name;
        int strength;
        int dexterity;
        int endurance;
        int intelligence;
        int charisma;
        int HP;
        int dropRate;
        int ID;
        int reqLvl;
    };

    std::vector<items> Item;
    std::string name;
    int XP;
    int HP;
    int strength, dexterity, endurance, intelligence, charisma, level;
    virtual void dispAttributes() = 0;
    virtual ~Attributes(){};
};

#endif