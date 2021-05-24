#include <iostream>
#include <fstream>
#include <time.h>

#include "battle.hpp"
#include "battleLog.hpp"

using namespace std;

int battleMechanics::readUserInput()
{
     int userChoice;
     cin >> userChoice;
     while (cin.fail())
     {
          cout << "Error! Please enter an integer: " << endl;
          cin.clear();
          cin.ignore(256, '\n');
          cin >> userChoice;
          system("CLS");
     }
     return userChoice;
}
string battleMechanics::correctTableSize(int attribute)
{
     string amountOfSpaces;
     string attribute_str;
     attribute_str = to_string(attribute);

     for (int i = 0; i < (7 - attribute_str.length()); i++)
     {
          amountOfSpaces += " ";
     }
     amountOfSpaces += "|";

     return amountOfSpaces;
}
void battleMechanics::disp_battle(HeroCreation &hero, MonsterCreation &monster)
{
     system("cls");

     // creating gap between the names
     int temp_gap_number = 56 - hero.name.length();
     string temp_gap;

     for (int i = 0; i < temp_gap_number; i++)
     {
          temp_gap += " ";
     }

     cout << "Prepare for the ultimate duel!" << endl;
     cout << endl;
     cout << " " << hero.name << temp_gap << monster.name << endl;
     cout << "+------------------+-------------+"
          << "\t\t\t+------------------+-------------+" << endl;
     cout << "|   Strength:      |      " << hero.strength << correctTableSize(hero.strength)
          << "\t\t\t|   Strength:      |      " << monster.strength << correctTableSize(monster.strength) << endl;
     cout << "|   Dexterity:     |      " << hero.dexterity << correctTableSize(hero.dexterity)
          << "\t\t\t|   Dexterity:     |      " << monster.dexterity << correctTableSize(monster.dexterity) << endl;
     cout << "|   Endurance:     |      " << hero.endurance << correctTableSize(hero.endurance)
          << "\t    VS   \t|   Endurance:     |      " << monster.endurance << correctTableSize(monster.endurance) << endl;
     cout << "|   Intelligence:  |      " << hero.intelligence << correctTableSize(hero.intelligence)
          << "\t\t\t|   Intelligence:  |      " << monster.intelligence << correctTableSize(monster.intelligence) << endl;
     cout << "|   Charisma:      |      " << hero.charisma << correctTableSize(hero.charisma)
          << "\t\t\t|   Charisma:      |      " << monster.charisma << correctTableSize(monster.charisma) << endl;
     cout << "|   HP:            |      " << hero.HP << correctTableSize(hero.HP)
          << "\t\t\t|   HP:            |      " << monster.HP << correctTableSize(monster.HP) << endl;
     cout << "+------------------+-------------+"
          << "\t\t\t+------------------+-------------+" << endl;
     cout << endl;
}

void battleMechanics::attackMelee(bool heroTurn, HeroCreation &hero, MonsterCreation &monster)
{
     // hero
     if (heroTurn)
     {
          int damage = 2 * hero.strength;
          monster.HP -= damage;
          cout << "Hero attacks!" << endl;
     }
     // monster
     else
     {
          int damage = 2 * monster.strength;
          hero.HP -= damage;
          cout << "Monster attacks!" << endl;
     }
}

spells battleMechanics::spellCast(int spellChoice, HeroCreation &hero, MonsterCreation &monster)
{
     switch (spellChoice)
     {
     case 1: // fireball
          int fireball_dmg;
          fireball_dmg = 10 * (hero.intelligence - monster.intelligence);
          monster.HP -= fireball_dmg;
          cout << "The monster has been struck with a fireball for " << fireball_dmg << " HP!" << endl;
          return fireball;
          break;
     case 2: // thunderstorm
          int thunderstorm_dmg;
          if (hero.intelligence > 5)
               thunderstorm_dmg = hero.intelligence - 2;
          else
               thunderstorm_dmg = hero.intelligence;
          cout << "You have summoned a thunderstorm above the monster! It takes additional damage each round equal to " << thunderstorm_dmg << " HP!" << endl;
          return thunderstorm;
          break;
     case 3: // divine intervention
          cout << "You have called upon the divine power, you are granted invincibility in the next turn!" << endl;
          return divine_intervention;
          break;
     default:
          cout << "Error 101" << endl;
          return err_spells;
          break;
     }
}

spells battleMechanics::spellMenu()
{
     int choice;

     cout << "Choose the spell you want to cast: " << endl;
     cout << "1. Fireball" << endl;
     cout << "2. Thunderstorm" << endl;
     cout << "3. Divine intervention" << endl;
     cout << "Enter: ";
     choice = readUserInput();

     while (choice <= 0 || choice > 3)
     {
          cout << "No such option available, try again." << endl
               << endl;
          cout << "Choose the spell you want to cast: " << endl;
          cout << "1. Fireball" << endl;
          cout << "2. Thunderstorm" << endl;
          cout << "3. Divine intervention" << endl;
          cout << "Enter: ";
          choice = readUserInput();
     }

     switch (choice)
     {
     case fireball:
          return fireball;
          break;
     case thunderstorm:
          return thunderstorm;
          break;
     case divine_intervention:
          return divine_intervention;
          break;
     default:
          cout << "Error 101" << endl;
          return err_spells;
     }
}

actionChoice battleMechanics::disp_attack_options(bool if_spellCasted)
{
     int choice;
     cout << "Choose action:" << endl;
     cout << "1. Attack with a weapon" << endl;
     cout << "2. Cast a spell (can be cast once)" << endl;
     cout << "Enter: ";
     choice = readUserInput();

     while (choice <= 0 || choice > 2)
     {
          cout << "No such option available, try again." << endl
               << endl;
          cout << "Choose action:" << endl;
          cout << "1. Attack with a weapon" << endl;
          cout << "2. Cast a spell (can be cast once)" << endl;
          cout << "Enter: ";
          choice = readUserInput();
     }

     if (choice == 2 && if_spellCasted)
     {
          choice = spellCasted;
     }

     switch (choice)
     {
     case melee_attack:
          return melee_attack;
          break;
     case spellcast:
          return spellcast;
          break;
     case spellCasted:
          cout << "A spell has already been casted in this battle!" << endl;
          Sleep(2000);
          return spellCasted;
          break;
     default:
          return err_actionChoice;
          break;
     }
}

bool battleMechanics::dodge_hero(HeroCreation &hero)
{
     int dodgeWhen = 1;
     int dodge_stat_hero;

     // hero dodge
     if (hero.dexterity > 0)
     {
          dodge_stat_hero = 11 - hero.dexterity;
          // checking if a dodge should occur
          if (dodgeWhen == rand() % dodge_stat_hero)
               return true;
          else
               return false;
     }
     else
          return false;
}

bool battleMechanics::dodge_monster(MonsterCreation &monster)
{
     int dodgeWhen = 1;
     int dodge_stat_monster;

     // monster dodge
     if (monster.dexterity > 0)
     {
          dodge_stat_monster = 11 - monster.dexterity;
          // checking if a dodge should occur
          if (dodgeWhen == rand() % dodge_stat_monster)
               return true;
          else
               return false;
     }
     else
          return false;
}

bool battleMechanics::battleSimulation(HeroCreation &hero, MonsterCreation &monster)
{
     bool heroTurn = false; // true for hero, false for monster

     // spell effects
     bool if_thunderstorm = false;
     bool if_divine_intervention = false;
     bool if_spellCasted = false;

     // monster xp
     monster.xpCalc();

     // HP
     hero.HP = 50;
     monster.HP = 50;

     // displaying the battle layout
     disp_battle(hero, monster);
     Sleep(1000);
     cout << "The fight has begun!" << endl;
     cout << endl;

     while (hero.endurance >= 0 && monster.endurance >= 0) // battle continues till endurance = 0;
     {
          if (hero.HP <= 0) // battle ends when one of the members has HP = 0 or less
          {
               cout << "The monster has succeeded... You will feel the remnants of this defeat till the end of your days." << endl;
               return false;
          }
          else if (monster.HP <= 0)
          {
               cout << "You have won! Congratulations, you have earned a lot of experience during the battle." << endl;
               return true;
          }
          else
          {
               heroTurn = !heroTurn;

               if (hero.endurance == 0) // if hero ran out of endurance
               {
                    cout << hero.name << " is too exhausted to continue fighting! Sadly he lost his will and left the battlefield losing XP." << endl;
                    return false;
               }
               else if (monster.endurance == 0) // if monster ran out of endurance
               {
                    int monsterDestiny;

                    cout << monster.name << " has had enough! You bested him and now you have the choice to spare the beast..." << endl;
                    cout << endl;
                    cout << "1. Kill the monster!" << endl;
                    cout << "2. Spare the poor thing..." << endl;
                    monsterDestiny = readUserInput();
                    while (monsterDestiny <= 0 || monsterDestiny > 2)
                    {
                         cout << "No such option available, try again." << endl
                              << endl;
                         cout << "Choose action:" << endl;
                         cout << "1. Kill the monster!" << endl;
                         cout << "2. Spare the poor thing..." << endl;
                         cout << "Enter: ";
                         monsterDestiny = readUserInput();
                    }

                    cout << endl;
                    if (monsterDestiny == 1)
                    {
                         cout << "The blood covered your weapon and you stand above the corpse in glory." << endl;
                    }
                    else if (monsterDestiny == 2)
                    {
                         cout << "The monster went on to reform it's world view and be a meaningful addition to the local society." << endl;
                         cout << "It lives in the nearby forest to the end of it's days surrounded with the love and praise of the local people." << endl;
                    }
                    return true;
               }
               else // continue battle
               {
                    if (heroTurn)
                    { // hero turn
                         if (if_thunderstorm)
                         {
                              int thunderstorm_dmg;
                              if (hero.intelligence > 5)
                                   thunderstorm_dmg = hero.intelligence - 2;
                              else
                                   thunderstorm_dmg = hero.intelligence;
                              monster.HP -= thunderstorm_dmg;
                              cout << "The monster suffers from the thunderstorm above it's head, it takes " << thunderstorm_dmg << " damage." << endl;
                              if_spellCasted = true;
                         }
                         if (dodge_monster(monster))
                         {
                              cout << "The hero attacked, but the monster managed to dodge the attack!" << endl;
                         }
                         else
                         {
                              switch (disp_attack_options(if_spellCasted))
                              {
                              case melee_attack:
                                   attackMelee(heroTurn, hero, monster);
                                   break;
                              case spellcast:
                                   switch (spellMenu())
                                   {
                                   case fireball:
                                        spellCast(fireball, hero, monster);
                                        if_spellCasted = true;
                                        break;
                                   case thunderstorm:
                                        spellCast(thunderstorm, hero, monster);
                                        if_thunderstorm = true;
                                        break;
                                   case divine_intervention:
                                        spellCast(divine_intervention, hero, monster);
                                        if_divine_intervention = true;
                                        break;
                                   }
                                   break;
                              case spellCasted:
                                   cout << "As no other option was viable, you had to resort to more traditional means of combat." << endl;
                                   attackMelee(heroTurn, hero, monster);
                                   break;
                              case err_actionChoice:
                                   break;
                              default:
                                   break;
                              }
                         }
                         // reducing endurance;
                         hero.endurance--;
                    }
                    else
                    { // monster turn
                         if (dodge_hero(hero) && !if_divine_intervention)
                         {
                              cout << "The monster attacked, but the hero managed to dodge the attack!" << endl;
                         }
                         else
                         {
                              if (if_divine_intervention)
                              {
                                   if_divine_intervention = false;
                                   if_spellCasted = true;
                                   cout << "The monster is helpless. It can not touch the hero, as the divine power burns it's skin." << endl;
                              }
                              else
                                   attackMelee(heroTurn, hero, monster);
                         }
                         // reducing endurance;
                         monster.endurance--;
                    }
               }
          }
          system("pause");
          // displaying the battle layout
          disp_battle(hero, monster);
     }
     return false;
}
bool battleMechanics::battleResult(bool result, HeroCreation &hero, MonsterCreation &monster, int temp_endurance)
{
     if (result)
     {
          cout << "You have gained " << monster.XP << " experience points!" << endl;
          hero.XP += monster.XP;
          hero.levelUp();
          cout << "Current XP pool: " << hero.XP << endl;
          return true;
     }
     else
     {
          cout << "You have lost " << monster.XP << " experience points!" << endl;
          hero.XP -= monster.XP;
          hero.levelUp();
          cout << "Current XP pool: " << hero.XP << endl;
          return false;
     }

     // replenish endurance
     hero.endurance = temp_endurance;
     // saving progress
     hero.save(false);
}