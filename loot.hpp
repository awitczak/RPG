#ifndef LOOT_HPP
#define LOOT_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

#include "fileManagement.hpp"
#include "HeroCreation.hpp"

class FileManagement;
class HeroCreation;

class Items : public FileManagement
{
    FileManagement loadingItems;
    int itemCount;
public:
    Items()
    {
        itemCount = loadingItems.itemLoad();
    };
    void disp_all_items();
    void lvl_check(HeroCreation &hero);
    int monsterLootDetermination();
    bool gettingLoot(HeroCreation &hero);
};

#endif