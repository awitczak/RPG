#ifndef MONSTER_CREATION_HPP
#define MONSTER_CREATION_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

#include "fileManagement.hpp"

class MonsterCreation : public FileManagement
{
protected:
    std::vector<std::string> monster_adj = {"Ferocious", "Wild", "Abominable", "Diabolical", "Vicious", "Remorseless", "Barbaric", "Brutish", "Annoying"};
    std::vector<std::string> monster_type= {"Sorrowbrute", "Skeleton", "Dragon", "Monkey", "Boar", "Brute", "Hunter", "Goblin", "Gnome"};
    std::string monster_name;
public:
    MonsterCreation();
    ~MonsterCreation(){};
    void monsterNameGeneration();
    void dispAttributes();
    void xpCalc();
};

#endif