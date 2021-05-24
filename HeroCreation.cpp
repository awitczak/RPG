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