#ifndef HERO_CREATION_HPP
#define HERO_CREATION_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

#include "battle.hpp"
#include "fileManagement.hpp"

class FileManagement;
class battleMechanics;

class HeroCreation : public FileManagement
{
public:
    HeroCreation(std::string n, int s, int d, int e, int i, int c);
    ~HeroCreation(){};
    void dispAttributes();
    void levelUp();
};

#endif