#ifndef HERO_CLASSES_HPP
#define HERO_CLASSES_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

#include "HeroCreation.hpp"

class HeroCreation;

class Warrior
{
public:
    ~Warrior(){};
    void increaseAttribute(HeroCreation &hero);
};
class Thief
{
public:
    ~Thief(){};
    void increaseAttribute(HeroCreation &hero);
};
class Berserk
{
public:
    ~Berserk(){};
    void increaseAttribute(HeroCreation &hero);
};
class Mage
{
public:
    ~Mage(){};
    void increaseAttribute(HeroCreation &hero);
};

#endif