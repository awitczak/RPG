#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

#include "HeroCreation.hpp"
#include "MonsterCreation.hpp"
#include "battleLog.hpp"

class HeroCreation;
class MonsterCreation;
class battleLog;
struct battleList;

enum spells
{
     err_spells = 0,
     fireball = 1,
     thunderstorm = 2,
     divine_intervention = 3
};

enum actionChoice
{
     err_actionChoice = 0,
     melee_attack = 1,
     spellcast = 2,
     spellCasted = 3
};

class battleMechanics
{
public:
     int readUserInput();
     void disp_battle(HeroCreation &hero, MonsterCreation &monster);
     std::string correctTableSize(int attribute);
     void attackMelee(bool heroTurn, HeroCreation &hero, MonsterCreation &monster);
     spells spellCast(int spellChoice, HeroCreation &hero, MonsterCreation &monster);
     spells spellMenu();
     actionChoice disp_attack_options(bool if_spellCasted);
     bool dodge_hero(HeroCreation &hero);
     bool dodge_monster(MonsterCreation &monster);
     bool battleSimulation(HeroCreation &hero, MonsterCreation &monster);
     bool battleResult(bool result, HeroCreation &hero, MonsterCreation &monster, int temp_endurance);
};

#endif