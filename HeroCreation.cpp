#include "HeroCreation.hpp"

using namespace std;

HeroCreation::HeroCreation(string n, int s, int d, int e, int i, int c)
{
    name = n;
    strength = s;
    dexterity = d;
    endurance = e;
    intelligence = i;
    charisma = c;
    XP = 0;
    level = 0;
}
void HeroCreation::createHero(string n, int s, int d, int e, int i, int c)
{
    name = n;
    strength = s;
    dexterity = d;
    endurance = e;
    intelligence = i;
    charisma = c;
    XP = 0;
    level = 0;
}
void HeroCreation::dispAttributes()
{

    battleMechanics disp;

    cout << "\t " << name << " Lvl: " << level << " XP: " << XP << endl;
    cout << "\t+------------------+-------------+" << endl;
    cout << "\t|   Strength:      |      " << strength << disp.correctTableSize(strength) << endl;
    cout << "\t|   Dexterity:     |      " << dexterity << disp.correctTableSize(dexterity) << endl;
    cout << "\t|   Endurance:     |      " << endurance << disp.correctTableSize(endurance) << endl;
    cout << "\t|   Intelligence:  |      " << intelligence << disp.correctTableSize(intelligence) << endl;
    cout << "\t|   Charisma:      |      " << charisma << disp.correctTableSize(charisma) << endl;
    cout << "\t+------------------+-------------+" << endl;
    cout << endl;
}
void HeroCreation::dispInventory()
{
    system("cls");
    cout << "\tInventory: " << endl;
    for (int i = 0; i < inventory.size(); i++)
    {
        cout << "Item name: \t" << inventory[i].name << endl;
        cout << "Strength: \t" << inventory[i].strength << endl;
        cout << "Dexterity: \t" << inventory[i].dexterity << endl;
        cout << "Endurance: \t" << inventory[i].endurance << endl;
        cout << "Intelligence: \t" << inventory[i].intelligence << endl;
        cout << "Charisma: \t" << inventory[i].charisma << endl;
        cout << "HP: \t\t" << inventory[i].HP << endl;
        cout << endl;
    }
    system("pause");
}
void HeroCreation::levelUp()
{
    int level_threshold = 100;
    if (XP >= (level_threshold + 10 * level))
    {
        XP -= level_threshold + 10 * level;
        level++;
        cout << "You reached a new level!" << endl;
        cout << "Current level: " << level << endl;
    }
}