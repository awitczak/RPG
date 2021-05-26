#ifndef FILE_MANAGEMENT_HPP
#define FILE_MANAGEMENT_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

#include "attributes.hpp"

class Attributes;

class FileManagement : public Attributes
{
protected:
    std::string filename;

public:
    void dispAttributes(){};
    void save(bool ifMonster);
    void load(bool ifMonster, int whichMonster);
    void list_update();
    std::vector<std::string> dispList();
    int itemLoad();
};

#endif