#include "MonsterCreation.hpp"

using namespace std;

MonsterCreation::MonsterCreation()
{
    monsterNameGeneration();
    name = monster_name;
    strength = rand() % 7 + 3;
    dexterity = rand() % 7 + 3;
    endurance = rand() % 7 + 3;
    intelligence = rand() % 7 + 3;
    charisma = rand() % 7 + 3;
}

void MonsterCreation::monsterNameGeneration()
{
    int i = rand() % monster_adj.size();
    int j = rand() % monster_type.size();
    monster_name = monster_adj[i] + "_" + monster_type[j];
}
void MonsterCreation::dispAttributes()
{
    cout << name << " has the following statistics: " << endl;
    cout << "Strength:\t " << strength << endl;
    cout << "Dexterity:\t " << dexterity << endl;
    cout << "Endurance:\t " << endurance << endl;
    cout << "Intelligence:\t " << intelligence << endl;
    cout << "Charisma:\t " << charisma << endl;
}

void MonsterCreation::xpCalc()
{
    XP = strength + dexterity + endurance + intelligence + charisma;
}